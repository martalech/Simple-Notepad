#pragma once

class Zooming : public QObject
{
	Q_OBJECT
public:
	Zooming(QWidget *parent, Qt::KeyboardModifiers modifiers);
	~Zooming();
protected:
	virtual bool eventFilter(QObject *watched, QEvent *event) override;
signals:
	void wheelRolled(int count);
private:
	Qt::KeyboardModifiers modifiers;
};
