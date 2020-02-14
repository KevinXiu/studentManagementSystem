#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    m_menuWidget = new MenuWidget;
    m_traStudentWidget = new TraverseStudentWidget;
    m_addStudentWidget = new AddStudentWidget;
    m_selectWidget = new SelectWiget;
    m_modifyWidget = new ModifyWidget;
   // m_clSrudentWidget = new ClearStudentWidget;
    m_sortWidget = new SortWidget;
    m_qstackedlayout = new QStackedLayout;
    m_delStudentWidget = new DeleteStudentWidget;

    //将窗口添加到stackedlayout布局中去
    m_qstackedlayout->addWidget(m_menuWidget);
    m_qstackedlayout->addWidget(m_traStudentWidget);
    m_qstackedlayout->addWidget(m_addStudentWidget);
    m_qstackedlayout->addWidget(m_selectWidget);
    m_qstackedlayout->addWidget(m_modifyWidget);
    m_qstackedlayout->addWidget(m_delStudentWidget);
    //m_qstackedlayout->addWidget(m_clSrudentWidget);
    m_qstackedlayout->addWidget(m_sortWidget);


    setLayout(m_qstackedlayout);

    connect(m_menuWidget, &MenuWidget::display, m_qstackedlayout, &QStackedLayout::setCurrentIndex);

    connect(m_addStudentWidget, &AddStudentWidget::display, m_qstackedlayout, &QStackedLayout::setCurrentIndex);
    connect(m_selectWidget, &SelectWiget::display, m_qstackedlayout, &QStackedLayout::setCurrentIndex);
    connect(m_modifyWidget, &ModifyWidget::display, m_qstackedlayout, &QStackedLayout::setCurrentIndex);
    connect(m_sortWidget, &SortWidget::display, m_qstackedlayout, &QStackedLayout::setCurrentIndex);
    connect(m_traStudentWidget,&TraverseStudentWidget::display,m_qstackedlayout,&QStackedLayout::setCurrentIndex);
    connect(m_delStudentWidget,&DeleteStudentWidget::display,m_qstackedlayout,&QStackedLayout::setCurrentIndex);
}

MainWidget::~MainWidget()
{
    delete ui;
}
