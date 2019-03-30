#include "stdafx.h"
#include "KeywordFinder.h"
#include "Notepad.h"

KeywordFinder::KeywordFinder(QWidget *parent)
	: QDialog(parent), firstTime(true)
{
	ui.setupUi(this);
	setWindowModality(Qt::WindowModal);
	connect(ui.pushButton, &QPushButton::clicked, this, &KeywordFinder::findRequest);
}

KeywordFinder::~KeywordFinder()
{
}

void KeywordFinder::findKeyword(QTextEdit *textEdit)
{
	QString keyword = ui.lineEdit->text();
	QTextDocument *document = textEdit->document();
	QTextCursor findCursor = document->find(keyword);
	if (findCursor.isNull())
	{
		close();
		QMessageBox message(this);
		message.setText("No keyword found");
		message.setIcon(QMessageBox::Warning);
		message.exec();
		return;
	}
	if (textEdit != nullptr)
	{
		if (firstTime)
		{
			currentKeyword = keyword;
			textEdit->moveCursor(QTextCursor::Start);
			firstTime = false;
		}
		if (currentKeyword != keyword)
		{
			currentKeyword = keyword;
			textEdit->moveCursor(QTextCursor::Start);
		}
		QTextCursor currentCursor = textEdit->textCursor();
		textEdit->find(keyword);
		if (currentCursor.position() == textEdit->textCursor().position())
		{
			textEdit->moveCursor(QTextCursor::Start);
			textEdit->find(keyword);
		}

		QPalette p = textEdit->palette();
		p.setColor(QPalette::Highlight, QColor(Qt::yellow));
		textEdit->setPalette(p);
	}
}