#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 自定义信号 需要写到signals下
    // 返回类型必须void 信号只需声明 不需要实现
    //信号可以有参数 可以重载
    void Hungry();
    void Hungry(QString foodName);
};

#endif // TEACHER_H
