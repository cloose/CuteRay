#include "mainwindow.h"

// Qt
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

// Own
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupActions()
{
    ui->openAction->setShortcut(QKeySequence::Open);
    ui->openAction->setStatusTip(tr("Open an existing scene script file..."));
    connect(ui->openAction, SIGNAL(triggered()),
            this, SLOT(onFileOpen()));

    ui->exitAction->setShortcut(QKeySequence::Quit);
    ui->exitAction->setStatusTip(tr("Exit the program"));
}

void MainWindow::onFileOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Scene Script"), "",
                                                    tr("Scene files (*.scn)"));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString script = in.readAll();
}
