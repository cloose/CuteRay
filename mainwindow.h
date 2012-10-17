#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onFileOpen();
    void onRenderStart();
    void onRenderStop();

private:
    void setupActions();

private:
    Ui::MainWindow *ui;
    bool isRenderingRunning;
};

#endif // MAINWINDOW_H
