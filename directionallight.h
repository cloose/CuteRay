#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "light.h"
#include <QVector3D>

class DirectionalLight : public Light
{
    Q_OBJECT

public:
    explicit DirectionalLight(QObject *parent = 0);

public slots:
    void setDirection(double x, double y, double z);
    void setIntensityColor(double r, double g, double b);

private:
    QVector3D m_direction;
};

#endif // DIRECTIONALLIGHT_H
