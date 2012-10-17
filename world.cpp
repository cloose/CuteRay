#include "world.h"

#include <QDebug>

#include "light.h"

World::World(QObject *parent) :
    QObject(parent)
{
}

World::~World()
{
    qDebug() << "World::~World()";
    qDeleteAll(m_lights);
    m_lights.clear();
}

QList<Light *> World::lights() const
{
    return m_lights;
}

void World::addLight(Light *light)
{
    qDebug() << "World::addLight";
    m_lights.append(light);
}
