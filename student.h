#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    // 自定义槽函数
    // 高版本可以写到 public下 或者全局函数
    // 槽函数返回值 void 需要声明也需要实现 可以有参 可以无参
    void treat();
    void treat(QString foodName);

};

#endif // STUDENT_H
