#ifndef VMARBLEWIDGET_H
#define VMARBLEWIDGET_H


#include <marble/MarbleWidget.h>

namespace Marble {

class VMarbleWidget : public MarbleWidget
{
public:
    VMarbleWidget();

protected:
    void mousePressEvent(QMouseEvent *event) { Q_UNUSED(event); }
    void mouseReleaseEvent(QMouseEvent *event) { Q_UNUSED(event); }
    void mouseMoveEvent(QMouseEvent *event) { Q_UNUSED(event); }
};

}

#endif // VMARBLEWIDGET_H
