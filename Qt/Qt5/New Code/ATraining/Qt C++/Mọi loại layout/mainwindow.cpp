#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QTimer>
#include <QElapsedTimer>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSplitter>
#include <QLineEdit>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QElapsedTimer elapsedTimer;
    elapsedTimer.start();
    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::showText);
    timer->start(5000);
    qDebug() << "set up need " << elapsedTimer.elapsed() << " ms";

    QTabWidget* tabwidget = new QTabWidget(this);
    this->setCentralWidget(tabwidget);

    QWidget* tab1 = new QWidget(tabwidget);
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    QPushButton* button1Tab1 = new QPushButton(this);
    button1Tab1->setText("Button 1");
    QPushButton* button2Tab1 = new QPushButton(this);
    button2Tab1->setText("Button 2");
    QPushButton* button3Tab1 = new QPushButton(this);
    button3Tab1->setText("Button 3");
    QSplitter* splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Horizontal);
    splitter->addWidget(button1Tab1);
    splitter->addWidget(button2Tab1);
    hLayout->addWidget(splitter);
    hLayout->addWidget(button3Tab1);
    tab1->setLayout(hLayout);
    tabwidget->addTab(tab1,"Tab 1");

    QWidget* tab2 = new QWidget(tabwidget);
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QHBoxLayout *h1 = new QHBoxLayout(this);
    QHBoxLayout *h2 = new QHBoxLayout(this);
    QPushButton* button1Tab2 = new QPushButton(this);
    button1Tab2->setText("Button 1");
    QPushButton* button2Tab2 = new QPushButton(this);
    button2Tab2->setText("Button 2");
    QSpacerItem* spacerleft1 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    QSpacerItem* spacerleft2 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    QSpacerItem* spacerright1 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    QSpacerItem* spacerright2 = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum);
    h1->addItem(spacerleft1);
    h1->addWidget(button1Tab2);
    h1->addItem(spacerright1);
    h2->addItem(spacerleft2);
    h2->addWidget(button2Tab2);
    h2->addItem(spacerright2);
    QSpacerItem* spacerCenter = new QSpacerItem(1,10,QSizePolicy::Expanding,QSizePolicy::Ignored);//ch???nh size 1 t??
    QSpacerItem* spacerCenter2 = new QSpacerItem(20,40,QSizePolicy::Expanding,QSizePolicy::Expanding);
    vLayout->addLayout(h1);
    vLayout->addItem(spacerCenter);
    vLayout->addLayout(h2);
    vLayout->addItem(spacerCenter2);
    vLayout->addWidget(button1Tab2);
    vLayout->addWidget(button2Tab2);
    tab2->setLayout(vLayout);
    tabwidget->addTab(tab2,"Tab 2");
    //nch l?? size v??? tr?? ta k n??n ch???nh b???ng code m?? d??ng ui.form n???u k th?? compile c?? th??? l???i khi resize ??o fix dc

    QWidget* tab3 = new QWidget(this);
    QBoxLayout* boxLayout = new QBoxLayout(QBoxLayout::RightToLeft, this);
    QLabel* label = new QLabel("Label: ", this);
    QLineEdit* lineEdit = new QLineEdit(this);
    boxLayout->addWidget(label);
    boxLayout->addWidget(lineEdit);
    boxLayout->setAlignment(label,Qt::AlignCenter);
    boxLayout->setAlignment(lineEdit,Qt::AlignLeft);
    tab3->setLayout(boxLayout);
    tabwidget->addTab(tab3,"Tab 3");

    QWidget* tab6= new QWidget(this);
    QBoxLayout* Layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    QLabel* label1 = new QLabel("Label: ", this);
    QLineEdit* lineEdit1 = new QLineEdit(this);
    Layout->addWidget(label1);
    Layout->addWidget(lineEdit1);
    Layout->setSpacing(10);//c??ch ch???nh kho???ng c??ch 2 c??c widget b??n trong
//    Layout->setStretch(Layout->indexOf(label1),1);//d??ng alignment th?? th??nh k??ch th?????c default k d??ng ??c stretch
//    Layout->setStretch(Layout->indexOf(lineEdit1),2);
    //d??ng setStretch v???i label l?? ngu d???t, d??ng v???i button m???i th???y hi???u ???ng k??o d??n ch??? label ph???n th???a d???n v??o b??n ph???i
    //th??nh kho???ng tr???ng s??? k nh?? ??
    tab6->setLayout(Layout);
    tabwidget->addTab(tab6,"Tab 6");

    tabwidget->setCurrentIndex(2);

    QWidget* tab4 = new QWidget(this);
    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->addRow(new QLabel("Name: ",this),new QLineEdit(this));//C1
    formLayout->addRow(tr("&Age:"), new QLineEdit(this));
    formLayout->setWidget(2,QFormLayout::LabelRole,new QLabel("Job",this));//C2
    formLayout->setWidget(2,QFormLayout::FieldRole,new QLabel("Description",this));
    //1 row c???a form ch??? ??c ch???a 2 widget v?? ph???i ????ng l?? 1 LabelRole v?? 1 FieldRole
    tab4->setLayout(formLayout);
    tabwidget->addTab(tab4,"Tab 4");

    QWidget* tab5 = new QWidget(this);
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->addWidget(new QLabel("Test: ",this),0,0);
    gridLayout->addWidget(new QLineEdit(this),0,1);
    gridLayout->addWidget(new QPushButton("Button 1", this),1,0,1,2);
    gridLayout->addWidget(new QPushButton("Button 2", this),1,1,1,1);
    //d??ng grid ?????c bi???t l?? n???u d??ng v???i c??c c??i t??? k??o d??n nh?? lineedit th?? n?? s??? t??? chi???m h???t. Ta set span s??? g??y l???i
    //N???u vs c??c widget bth th?? span ??c ch??? c??i n??y k ??c. ?????c bi???t l?? grid th?? c??c h??ng c??c c???t t??? c??n theo nhau
    //n???u d??ng tr??n c?? 2 c???t th?? d??ng d?????i theo k??ch th?????c d??ng tr??n v?? cx ch??? c?? 2 c???t
    tab5->setLayout(gridLayout);
    tabwidget->addTab(tab5,"Tab 5");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showText()
{
    qDebug() << "Timeout";
}

