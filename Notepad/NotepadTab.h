#pragma once

#include "IndexPool.h"

class NotepadTab : public QWidget
{
	Q_OBJECT

public:
	NotepadTab(QWidget *parent);
	NotepadTab(QWidget *parent, QString path="");
	~NotepadTab();

	void updateOriginalText();
	void setPath(const QString&);
	void setFilename(const QString&);
	void save();
	void setFont(QFont fon);
	void setColor(QColor col);

	QTextEdit* getTextTab();
	QString getFilename();
	int getCharacters() { return characters; }
	int getWords() { return words; }
	int getLines() { return lines; }
	int getCurrentLine() { return currentLine; }
private slots:
	void filenameChange();
private:
	void removeUntitled();
	void countWords();

	static IndexPool untitledPool;
	QTextEdit *textTab;
	QString path;
	QString originalText;
	QString filename;
	QFont font;
	QColor color;
	int characters;
	int words;
	int lines;
	int currentLine;
};
