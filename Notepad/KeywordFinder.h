#pragma once

#include "ui_KeywordFinder.h"

class KeywordFinder : public QDialog
{
	Q_OBJECT
public:
	KeywordFinder(QWidget *parent = nullptr);
	~KeywordFinder();
public slots:
	void findKeyword(QTextEdit *textEdit);
signals:
	void findRequest();
private:
	Ui::KeywordFinder ui;
	QString keyword;
	QString currentKeyword;
	bool firstTime;
};
