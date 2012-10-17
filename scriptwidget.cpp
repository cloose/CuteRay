#include "scriptwidget.h"
#include "ui_scriptwidget.h"

ScriptWidget::ScriptWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScriptWidget)
{
    ui->setupUi(this);
}

ScriptWidget::~ScriptWidget()
{
    delete ui;
}

QString ScriptWidget::script() const
{
    return ui->scriptTextEdit->document()->toPlainText();
}

void ScriptWidget::setScript(const QString &scriptText)
{
    ui->scriptTextEdit->document()->setPlainText(scriptText);
}
