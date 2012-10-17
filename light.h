#ifndef LIGHT_H
#define LIGHT_H

#include <QObject>

class Light : public QObject
{
    Q_OBJECT

public:
    explicit Light(QObject *parent = 0);
};

#endif // LIGHT_H
