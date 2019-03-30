#pragma once

class TabWidget : public QTabWidget
{
	Q_OBJECT
public:
	TabWidget(QWidget *parent);
	~TabWidget();
protected:
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
};
