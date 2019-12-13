#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include "widget.h"

class calculator : public QWidget
{
    Q_OBJECT
    Widget w;
public:
    explicit calculator(QWidget *parent = nullptr);

signals:

public slots:
    void calculate();
};

#endif // CALCULATOR_H
