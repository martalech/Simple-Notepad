#pragma once

#include "ui_Notepad.h"
#include "Zooming.h"
#include "KeywordFinder.h"
#include "NotepadTab.h"

class Notepad : public QMainWindow
{
	Q_OBJECT
public:
	Notepad(QWidget *parent = nullptr);
protected:
	virtual void closeEvent(QCloseEvent *event) override;
private:
	void newFile();
	void openFile();
	void saveFile();
	void saveFileAs();
	void saveAll();
	void closeFile();
	void closeAll();
	void newTab(int index);

	void undo();
	void redo();
	void copy();
	void cut();
	void paste();
	void clear();
	void selectAll();

	void zoomIn();
	void zoomOut();
	void showFinder();
	void find();
	void closeFinder();
	void font();
	void color();

	void applySettings();
	void restoreDefaultSettings();
	void statusBarUpdate();

	void open(QString filepath);

	Ui::NotepadClass ui;
	KeywordFinder *finder;
	QAction *fontUpAction;
	QAction *fontDownAction;
	QLabel *charactersCount;
	QLabel *wordsCount;
	QLabel *linesCount;
	QLabel *currentLine;
	Zooming *zoomAction;
	QFont notepadFont;
	QColor notepadColor;
	QPalette originalPalette;
	QSettings *settings;
private slots:
	void restoreOriginalPalette();
	bool closeTab(int index);
	void textChange();
	void changeFontSize(int factor);
};
