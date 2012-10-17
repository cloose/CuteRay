#ifndef SCRIPTWIDGET_H
#define SCRIPTWIDGET_H

#include <QWidget>

namespace Ui {
class ScriptWidget;
}

class ScriptWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ScriptWidget(QWidget *parent = 0);
    ~ScriptWidget();

    QString script() const;
    void setScript(const QString &scriptText);

private:
    Ui::ScriptWidget *ui;
};

#endif // SCRIPTWIDGET_H
