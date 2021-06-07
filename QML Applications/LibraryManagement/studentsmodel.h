#ifndef STUDENTSMODEL_H
#define STUDENTSMODEL_H

#include <QObject>
#include <QSqlQueryModel>


class StudentsModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit StudentsModel(QObject *parent = nullptr);

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        AgeRole,
        EmailRole,
        PasswordRole,
        GenderRole,
        RoleRole,
        DepartmentRole,
        SemesterRole
    };

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:

    QHash<int, QByteArray> roleNames() const;

public slots:

    void updateModel(QString studentname);
    int getId(int row);
};
#endif // STUDENTSMODEL_H
