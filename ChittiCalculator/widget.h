#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDebug>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void MyUI();
    ~Widget();
public:
    QGridLayout *m_grdLyt;

    QLabel *m_lbl_chitAmount;
    QLabel *m_lbl_totalMonths;
    QLabel *m_lbl_chitTakenMonth;
    QLabel *m_lbl_currentMonth;
    QLabel *m_lbl_result;
    QLabel *m_lbl_amountPaiedTillNow;
    QLabel *m_lbl_totalAmountPayable;
    QLabel *m_lbl_amountPaiedTillNow_v;
    QLabel *m_lbl_totalAmountPayable_v;

    QLineEdit *m_lnEdt_chitAmount;
    QLineEdit *m_lnEdt_totalMonths;
    QLineEdit *m_lnEdt_chitTakenMonth;
    QLineEdit *m_lnEdt_currentMonth;

    QPushButton *m_btn;

private:
    //Ui::Widget *ui;

public slots:
    void calculate();
};
#endif // WIDGET_H
