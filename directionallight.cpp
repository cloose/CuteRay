#include "directionallight.h"

#include <QDebug>

DirectionalLight::DirectionalLight(QObject *parent) :
    Light(parent)
{
}

void DirectionalLight::setDirection(double x, double y, double z)
{
    m_direction.setX(x);
    m_direction.setY(y);
    m_direction.setZ(z);
    qDebug() << "DirectionalLight" << m_direction;
}

void DirectionalLight::setIntensityColor(double r, double g, double b)
{
    qDebug() << "DirectionalLight" << r << g << b;
}
