#include "calculator.h"
#include "widget.h"

calculator::calculator(QWidget *parent) : QWidget(parent)
{


}

void calculator::calculate()
{
    int chitAmount = w.m_lnEdt_chitAmount->text().toInt();
    int totalMonths = w.m_lnEdt_totalMonths->text().toInt();
    int chitTakenMonth = w.m_lnEdt_chitTakenMonth->text().toInt();
    int currentMonth = w.m_lnEdt_currentMonth->text().toInt();
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


    w.m_lbl_result->setText(re);
    w.m_lbl_amountPaiedTillNow->setText(re1);
    w.m_lbl_totalAmountPayable->setText(re2);
}
