#ifndef PREVIEWWIDGET_H
#define PREVIEWWIDGET_H

#include <QGLWidget>

class PreviewWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit PreviewWidget(QWidget *parent = 0);

protected:
    virtual void initializeGL();
};

#endif // PREVIEWWIDGET_H
