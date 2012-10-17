#include "scriptevaluator.h"

// Qt
#include <QMessageBox>
#include <QScriptEngine>
#include <QString>

// Own
#include "directionallight.h"

Q_SCRIPT_DECLARE_QMETAOBJECT(DirectionalLight, QObject*)

ScriptEvaluator::ScriptEvaluator()
{
}

World *ScriptEvaluator::evaluate(const QString &script)
{
    QScriptEngine engine;

    World* world = new World();
    QScriptValue worldValue = engine.newQObject(world);
    engine.globalObject().setProperty("world", worldValue);

    QScriptValue directionalLightClass = engine.scriptValueFromQMetaObject<DirectionalLight>();
    engine.globalObject().setProperty("DirectionalLight", directionalLightClass);

    engine.evaluate(script);
    if (engine.hasUncaughtException())
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Warning);
        messageBox.setWindowTitle("Script error");
        messageBox.setText("An error occurred while executing the script.");
        messageBox.setInformativeText(engine.uncaughtException().toString());
        messageBox.setDetailedText(engine.uncaughtExceptionBacktrace().join("\n"));
        messageBox.exec();
        return 0;
    }

    return world;
}
