#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
//    , ui(new Ui::Widget)
{
//    ui->setupUi(this);
    MyUI();
    QObject::connect(m_btn,SIGNAL(clicked()),this,SLOT(calculate()));
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
    m_grdLyt->addWidget(m_lbl_totalAmountPayable_v,5,0);
    m_grdLyt->addWidget(m_lbl_totalAmountPayable,5,1);
    m_grdLyt->addWidget(m_lbl_amountPaiedTillNow_v,6,0);
    m_grdLyt->addWidget(m_lbl_amountPaiedTillNow,6,1);

}

void Widget::calculate()
{
    int chitAmount = m_lnEdt_chitAmount->text().toInt();
    int totalMonths = m_lnEdt_totalMonths->text().toInt();
    int chitTakenMonth = m_lnEdt_chitTakenMonth->text().toInt();
    int currentMonth = m_lnEdt_currentMonth->text().toInt();
    int monthlyPayment = chitAmount/totalMonths;
    int nextMonthAmount = monthlyPayment + monthlyPayment/5;
    int remainingEMI = totalMonths-currentMonth;
    int monthsAfterTakenChitti = currentMonth - chitTakenMonth;
    int monthsBeforeTakenChitti = currentMonth - monthsAfterTakenChitti;
    int amountPaiedTillNow = monthsBeforeTakenChitti * monthlyPayment + monthsAfterTakenChitti * nextMonthAmount;
    int totalAmountPayable = amountPaiedTillNow + remainingEMI * nextMonthAmount;
    int yetToPayAmount = totalAmountPayable - amountPaiedTillNow;
    QString re = QString::number(yetToPayAmount);
    QString re1 = QString::number(amountPaiedTillNow);
    QString re2 = QString::number(totalAmountPayable);


    m_lbl_result->setText(re);
    m_lbl_totalAmountPayable->setText(re1);
    m_lbl_amountPaiedTillNow->setText(re2);
}



Widget::~Widget()
{
//    delete ui;
}

