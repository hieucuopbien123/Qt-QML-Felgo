#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtConcurrent>
#include "myjob.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void onStop();

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();

public slots:
    void newNumber(QString name, int number);

private:
    Ui::Widget *ui;
    MyJob *job;
};
#endif // WIDGET_H
