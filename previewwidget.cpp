#include "previewwidget.h"

PreviewWidget::PreviewWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void PreviewWidget::initializeGL()
{
    // set opengl states
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);
}
