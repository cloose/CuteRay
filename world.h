#ifndef WORLD_H
#define WORLD_H

#include <QObject>

class Light;

class World : public QObject
{
    Q_OBJECT

public:
    explicit World(QObject *parent = 0);
    virtual ~World();
    
    QList<Light*> lights() const;

public slots:
    void addLight(Light *light);

private:
    QList<Light*> m_lights;
};

#endif // WORLD_H
