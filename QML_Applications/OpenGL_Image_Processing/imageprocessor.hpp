#ifndef IMAGEPROCESSOR_HPP
#define IMAGEPROCESSOR_HPP

#include <QObject>
#include <QImage>
#include <QDebug>
#include <QUrl>
#include <QCamera>
#include <QByteArray>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlImageProviderBase>
#include <QQuickImageProvider>
#include <QBuffer>
#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>

class ImageProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QImage img READ img WRITE setImg NOTIFY imgChanged)
    QImage m_img;

public:
    explicit ImageProcessor(QObject *parent = nullptr);

    Q_INVOKABLE void processImage(const QImage& image,
                        const QString& textureVar,
                        const QString& vertexPosVar,
                        const QString& textureCoordVar);

signals:

    void imgChanged();

public:
//    QString vertexShader =
//            "attribute vec4 aPosition;\n"
//            "attribute vec2 aTexCoord;\n"
//            "varying vec2 vTexCoord;\n"
//            "void main()\n"
//            "{\n"
//            "   gl_Position = aPosition;\n"
//            "   vTexCoord = aTexCoord;\n"
//            "}";
    QString vertexShader =
            "attribute vec4 aPosition;\n"
            "attribute vec2 aTexCoord;\n"
            "varying vec2 vTexCoord;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = aPosition;\n"
            "   vTexCoord.x = -aTexCoord.x;\n"
            "   vTexCoord.y = aTexCoord.y;\n"
            "}";

//    QString fragmentShader =
//            "uniform sampler2D texture;\n"
//            "varying vec2 vTexCoord;\n"
//            "void main()\n"
//            "{\n"
//            "   gl_FragColor = texture2D(texture, vTexCoord);\n"
//            "}";

    QString fragmentShader =
            "uniform sampler2D texture;\n"
            "varying vec2 vTexCoord;\n"
            "void main()\n"
            "{\n"
            "   vec2 uv = vTexCoord;\n"
            "   vec4 orig = texture2D(texture, uv);\n"
            "   vec3 col = orig.rgb;\n"
            "   float y = 0.3 * col.r + 0.59 * col.g + 0.11 * col.b;\n"
            "   gl_FragColor = vec4(y + 0.15, y + 0.07, y - 0.12, 1.0);\n"
            "}";

    const QImage &img() const;
    void setImg(const QImage &newImg);

    Q_INVOKABLE QUrl imageToUrl(const QImage& image);

//    void decodeImageQML(const QUrl &imgUrl)
//    {
//        QQmlEngine *engine = QQmlEngine::contextForObject(this)->engine();
//        QQmlImageProviderBase* imageProviderBase = engine->imageProvider(imgUrl);
//        QQuickImageProvider* imageProvider = static_cast<QQuickImageProvider*>(imageProviderBase);
//        QImage image = imageProvider->requestImage(("preview_1", &size, QSize()));


//    }
};

#endif // IMAGEPROCESSOR_HPP
