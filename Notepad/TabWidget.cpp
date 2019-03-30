#include "stdafx.h"
#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent)
	: QTabWidget(parent)
{
}

TabWidget::~TabWidget()
{
}

void TabWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		QRect tabBarRectangle = tabBar()->geometry();
		if(event->x() >= tabBarRectangle.bottomRight().x() 
			&& (event->y() <= tabBarRectangle.bottomLeft().y() && event->y() >= tabBarRectangle.topRight().y()))
		emit tabBarDoubleClicked(-1);
	}
	QTabWidget::mouseDoubleClickEvent(event);
}
