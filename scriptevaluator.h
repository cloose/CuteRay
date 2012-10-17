#ifndef SCRIPTEVALUATOR_H
#define SCRIPTEVALUATOR_H

#include "world.h"

class ScriptEvaluator
{
public:
    ScriptEvaluator();

    World *evaluate(const QString &script);
};

#endif // SCRIPTEVALUATOR_H
