#include "widget.h"
#include "ui_widget.h"
#include "calculator.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    //    , ui(new Ui::Widget)
{
    //    ui->setupUi(this);
    MyUI();

    QObject::connect(m_btn,SIGNAL(clicked()),this,SLOT( calculator.calculate()));
//    c.calculator();
}

void Widget::MyUI()
{

    m_grdLyt = new QGridLayout(this);

    m_lbl_chitAmount = new QLabel();
    m_lbl_totalMonths = new QLabel();
    m_lbl_chitTakenMonth = new QLabel();
    m_lbl_currentMonth = new QLabel();
    m_lbl_result = new QLabel();
    m_lbl_amountPaiedTillNow = new QLabel();
    m_lbl_totalAmountPayable = new QLabel();
    m_lbl_amountPaiedTillNow_v = new QLabel();
    m_lbl_totalAmountPayable_v = new QLabel();

    m_lnEdt_chitAmount = new QLineEdit();
    m_lnEdt_totalMonths = new QLineEdit();
    m_lnEdt_chitTakenMonth = new QLineEdit();
    m_lnEdt_currentMonth = new QLineEdit();
    m_btn = new QPushButton();

    m_validator_chitAmount = new QIntValidator(0,1000000000,m_grdLyt);
    m_lnEdt_chitAmount->setValidator(m_validator_chitAmount);
    m_validator_totalMonths = new QIntValidator(0,1000000000,m_grdLyt);
    m_lnEdt_totalMonths->setValidator(m_validator_totalMonths);
    m_validator_chitTakenMonth = new QIntValidator(0,1000000000,m_grdLyt);
    m_lnEdt_chitTakenMonth->setValidator(m_validator_chitTakenMonth);
    m_validator_currentMonth = new QIntValidator(0,1000000000,m_grdLyt);
    m_lnEdt_currentMonth->setValidator(m_validator_currentMonth);



    m_btn->setText("Click");
    QPalette pal = m_btn->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    m_btn->setAutoFillBackground(true);
    m_btn->setPalette(pal);
    m_btn->update();

    m_lbl_chitAmount->setText("chit Amount");
    m_lbl_chitAmount->palette();
    m_lbl_totalMonths->setText("Total No of Months");
    m_lbl_chitTakenMonth->setText("chit Taken Month");
    m_lbl_currentMonth->setText("current Month Number");
    m_lbl_amountPaiedTillNow_v->setText("amountPaiedTillNow");
    m_lbl_totalAmountPayable_v->setText("totalAmountPayable");

    m_grdLyt->addWidget(m_lbl_chitAmount,0,0);
    m_grdLyt->addWidget(m_lnEdt_chitAmount,0,1);
    m_grdLyt->addWidget(m_lbl_totalMonths,1,0);
    m_grdLyt->addWidget(m_lnEdt_totalMonths,1,1);
    m_grdLyt->addWidget(m_lbl_chitTakenMonth,2,0);
    m_grdLyt->addWidget(m_lnEdt_chitTakenMonth,2,1);
    m_grdLyt->addWidget(m_lbl_currentMonth,3,0);
    m_grdLyt->addWidget(m_lnEdt_currentMonth,3,1);
    m_grdLyt->addWidget(m_btn,4,0);
    m_grdLyt->addWidget(m_lbl_result,4,1);
    m_grdLyt->addWidget(m_lbl_amountPaiedTillNow_v,5,0);
    m_grdLyt->addWidget(m_lbl_amountPaiedTillNow,5,1);
    m_grdLyt->addWidget(m_lbl_totalAmountPayable_v,6,0);
    m_grdLyt->addWidget(m_lbl_totalAmountPayable,6,1);


}




Widget::~Widget()
{
    //    delete ui;
}

