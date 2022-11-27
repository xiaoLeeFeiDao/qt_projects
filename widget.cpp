#include "widget.h"
#include <QDebug>
// 需求 创建两个类 Teacher类 Student类

// 下课后 老师发出信号 饿了
// 学生响应信号 处理信号的槽函数 请客吃饭
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    zt = new Teacher(); // 如果这里不传入this指针 需析构时delete
    st = new Student(this);

    // 连接老师和学生
//    connect(zt,&Teacher::Hungry, st, &Student::treat);


    // 有参数 信号和槽
    // 函数指针 执行函数地址
    void(Teacher:: *tearcherSignal)(QString) = &Teacher::Hungry;
    void(Student:: *stSlot)(QString) = &Student::treat;
    connect(zt,tearcherSignal, st, stSlot);
    classIsOver();
}

void Widget::classIsOver()
{
    // 触发老师说饿了的信号 老师饿了的信号属于自定义信号 出发自定义信号关键字 emmit
    emit zt->Hungry();
    emit zt->Hungry("宫保鸡丁");

}
Widget::~Widget()
{
    delete zt;
    qDebug() << "Student已析构";
}

