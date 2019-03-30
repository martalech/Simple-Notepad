#include "stdafx.h"
#include "Zooming.h"

Zooming::Zooming(QWidget *parent, Qt::KeyboardModifiers modifiers)
	: QObject(parent), modifiers(modifiers)
{
	parent->installEventFilter(this);
}

Zooming::~Zooming()
{
}

bool Zooming::eventFilter(QObject *watched, QEvent *event)
{
	if (event->type() == QEvent::Wheel)
	{
		QWheelEvent *wheelEvent = dynamic_cast<QWheelEvent*>(event);
		if (wheelEvent->modifiers() == modifiers)
		{
			int count = 0;
			if (!wheelEvent->angleDelta().isNull())
				count = wheelEvent->angleDelta().y() / 120;
			else if (!wheelEvent->pixelDelta().isNull())
				count = wheelEvent->pixelDelta().y() / 8;
			if (count != 0)
			{
				emit wheelRolled(count);
				return true;
			}
		}
	}
	return QObject::eventFilter(watched, event);
}
