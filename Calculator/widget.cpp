#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)//,    ui(new Ui::Widget)
{
    //ui->setupUi(this);
    UI();
    connect(m_b,SIGNAL(clicked(bool)),this,SLOT(claculate()));
}

Widget::~Widget()
{
    //delete ui;
}

void Widget::UI()
{
    m_vb = new QVBoxLayout(this);
    m_b = new QPushButton();
    m_l = new QLineEdit();
    m_l1 = new QLineEdit();
    m_b->setText("Click");

    m_vb->addWidget(m_b);
    m_vb->addWidget(m_l);
    m_vb->addWidget(m_l1);

}

void Widget::claculate()
{
    m_l1->setText(m_l->text());
}
