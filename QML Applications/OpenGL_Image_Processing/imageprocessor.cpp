#include "imageprocessor.hpp"

ImageProcessor::ImageProcessor(QObject *parent) : QObject(parent)
{

}

void ImageProcessor::processImage(const QImage &image, const QString &textureVar, const QString &vertexPosVar, const QString &textureCoordVar)
{
    QOpenGLContext context;
    if(!context.create())
    {
        qDebug() << "Can't create GL context.";
        return;
    }
    QOffscreenSurface surface;
    surface.setFormat(context.format());
    surface.create();
    if(!surface.isValid())
    {
        qDebug() << "Surface not valid.";
        return;
    }
    if(!context.makeCurrent(&surface))
    {
        qDebug() << "Can't make context current.";
        return;
    }
    QOpenGLFramebufferObject fbo(image.size(),GL_TEXTURE_2D);
    context.functions()->glViewport(0, 0, image.width(), image.height());
    QOpenGLShaderProgram program(&context);
    if (!program.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShader))
    {
        qDebug() << "Can't add vertex shader.";
        return;
    }
    if (!program.addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShader))
    {
        qDebug() << "Can't add fragment shader.";
        return;
    }
    if (!program.link())
    {
        qDebug() << "Can't link program.";
        return;
    }
    if (!program.bind())
    {
        qDebug() << "Can't bind program.";
        return;
    }
    QOpenGLTexture texture(QOpenGLTexture::Target2D);
    texture.setData(image);

    texture.bind();
    if(!texture.isBound())
    {
        qDebug() << "Texture not bound.";
        return;
    }
    struct VertexData
    {
        QVector2D position;
        QVector2D texCoord;
    };

    VertexData vertices[] =
    {
        {{ -1.0f, +1.0f }, { 0.0f, 1.0f }}, // top-left
        {{ +1.0f, +1.0f }, { 1.0f, 1.0f }}, // top-right
        {{ -1.0f, -1.0f }, { 0.0f, 0.0f }}, // bottom-left
        {{ +1.0f, -1.0f }, { 1.0f, 0.0f }}  // bottom-right
    };

    GLuint indices[] =
    {
        0, 1, 2, 3
    };

    QOpenGLBuffer vertexBuf(QOpenGLBuffer::VertexBuffer);
    QOpenGLBuffer indexBuf(QOpenGLBuffer::IndexBuffer);

    if(!vertexBuf.create())
    {
        qDebug() << "Can't create vertex buffer.";
        return;
    }

    if(!indexBuf.create())
    {
        qDebug() << "Can't create index buffer.";
        return;
    }

    if(!vertexBuf.bind())
    {
        qDebug() << "Can't bind vertex buffer.";
        return;
    }
    vertexBuf.allocate(vertices, 4 * sizeof(VertexData));

    if(!indexBuf.bind())
    {
        qDebug() << "Can't bind index buffer.";
        return;
    }
    indexBuf.allocate(indices, 4 * sizeof(GLuint));

    int offset = 0;
    program.enableAttributeArray(vertexPosVar.toLatin1().data());
    program.setAttributeBuffer(vertexPosVar.toLatin1().data(), GL_FLOAT, offset, 2, sizeof(VertexData));
    offset += sizeof(QVector2D);
    program.enableAttributeArray(textureCoordVar.toLatin1().data());
    program.setAttributeBuffer(textureCoordVar.toLatin1().data(), GL_FLOAT, offset, 2, sizeof(VertexData));
    program.setUniformValue(textureVar.toLatin1().data(), 0);
    context.functions()->glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, Q_NULLPTR);
    setImg(fbo.toImage(false));
}

const QImage &ImageProcessor::img() const
{
    return m_img;
}

void ImageProcessor::setImg(const QImage &newImg)
{
    if (m_img == newImg)
        return;
    m_img = newImg;
    emit imgChanged();
}

QUrl ImageProcessor::imageToUrl(const QImage &image)
{
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "png");
    QString base64 = QString::fromUtf8(byteArray.toBase64());
    return QString("data:image/png;base64,") + base64;
}
