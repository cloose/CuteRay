#include "mainwindow.h"

// Qt
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

// Own
#include "scriptevaluator.h"
#include "ui_mainwindow.h"
#include "world.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isRenderingRunning(false)
{
    ui->setupUi(this);

    setupActions();
}

MainWindow::~MainWindow()
{
    delete ui;
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

    ui->scriptDockContents->setScript(script);
}

void MainWindow::onRenderStart()
{
    isRenderingRunning = true;
    ui->startAction->setEnabled(!isRenderingRunning);
    ui->stopAction->setEnabled(isRenderingRunning);

    QString script = ui->scriptDockContents->script();
    ScriptEvaluator evaluator;
    World* world = evaluator.evaluate(script);
}

void MainWindow::onRenderStop()
{
    isRenderingRunning = false;
    ui->startAction->setEnabled(!isRenderingRunning);
    ui->stopAction->setEnabled(isRenderingRunning);
}

void MainWindow::setupActions()
{
    ui->openAction->setShortcut(QKeySequence::Open);
    ui->openAction->setStatusTip(tr("Open an existing scene script file..."));
    connect(ui->openAction, SIGNAL(triggered()),
            this, SLOT(onFileOpen()));

    ui->exitAction->setShortcut(QKeySequence::Quit);
    ui->exitAction->setStatusTip(tr("Exit the program"));

    ui->startAction->setEnabled(!isRenderingRunning);
    connect(ui->startAction, SIGNAL(triggered()),
            this, SLOT(onRenderStart()));

    ui->stopAction->setEnabled(isRenderingRunning);
    connect(ui->stopAction, SIGNAL(triggered()),
            this, SLOT(onRenderStop()));
}
