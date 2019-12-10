#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QVBoxLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void UI();

public:
    QPushButton *m_b;
    QLineEdit *m_l;
    QLineEdit *m_l1;
    QVBoxLayout *m_vb;

private:
    //Ui::Widget *ui;


public slots:
    void claculate();
};

#endif // WIDGET_H
