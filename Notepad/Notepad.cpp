#include "stdafx.h"
#include "Notepad.h"

Notepad::Notepad(QWidget *parent)
	: QMainWindow(parent), fontUpAction(new QAction(this)), fontDownAction(new QAction(this))
	, zoomAction(new Zooming(this, Qt::ControlModifier)), finder(nullptr), notepadFont(QFont()), notepadColor(QColor())
	, originalPalette(QPalette()), charactersCount(new QLabel(this)), wordsCount(new QLabel(this))
	, linesCount(new QLabel(this)), currentLine(new QLabel(this)), settings(new QSettings(qApp->applicationDirPath() + "/settings.ini",
	QSettings::IniFormat, this))
{
	ui.setupUi(this);
	applySettings();

	ui.statusBar->addPermanentWidget(charactersCount, 1);
	ui.statusBar->addPermanentWidget(wordsCount, 1);
	ui.statusBar->addPermanentWidget(linesCount, 1);
	ui.statusBar->addPermanentWidget(currentLine, 1);
	statusBarUpdate();
	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &Notepad::statusBarUpdate);

	connect(ui.actionOpen, &QAction::triggered, this, &Notepad::openFile);
	connect(ui.actionSave, &QAction::triggered, this, &Notepad::saveFile);
	connect(ui.tabWidget, &QTabWidget::tabCloseRequested, this, &Notepad::closeTab);
	connect(ui.actionopenFile, &QAction::triggered, this, &Notepad::openFile);
	connect(ui.actionsaveFile, &QAction::triggered, this, &Notepad::saveFile);
	connect(ui.actionNewFile, &QAction::triggered, this, &Notepad::newFile);
	connect(ui.actionsaveAll, &QAction::triggered, this, &Notepad::saveAll);
	connect(ui.actioncloseFile, &QAction::triggered, this, &Notepad::closeFile);
	connect(ui.actioncloseAll, &QAction::triggered, this, &Notepad::closeAll);
	connect(ui.actionSave_as, &QAction::triggered, this, &Notepad::saveFileAs);
	connect(ui.actionClose, &QAction::triggered, this, &Notepad::closeFile);
	connect(ui.actionClose_all, &QAction::triggered, this, &Notepad::closeAll);

	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &Notepad::restoreOriginalPalette);
	connect(ui.tabWidget, &QTabWidget::tabBarDoubleClicked, this, &Notepad::newTab);

	connect(ui.actionUndo, &QAction::triggered, this, &Notepad::undo);
	connect(ui.actionRedo, &QAction::triggered, this, &Notepad::redo);
	connect(ui.actionCopy, &QAction::triggered, this, &Notepad::copy);
	connect(ui.actionCut, &QAction::triggered, this, &Notepad::cut);
	connect(ui.actionPaste, &QAction::triggered, this, &Notepad::paste);
	connect(ui.actionundo, &QAction::triggered, this, &Notepad::undo);
	connect(ui.actionredo, &QAction::triggered, this, &Notepad::redo);
	connect(ui.actioncopy, &QAction::triggered, this, &Notepad::copy);
	connect(ui.actioncut, &QAction::triggered, this, &Notepad::cut);
	connect(ui.actionpaste, &QAction::triggered, this, &Notepad::paste);
	connect(ui.actionClear, &QAction::triggered, this, &Notepad::clear);
	connect(ui.actionSelect_all, &QAction::triggered, this, &Notepad::selectAll);
	connect(ui.actionRestore_default, &QAction::triggered, this, &Notepad::restoreDefaultSettings);

	connect(ui.actionzoomIn, &QAction::triggered, this, &Notepad::zoomIn);
	connect(ui.actionzoomOut, &QAction::triggered, this, &Notepad::zoomOut);
	connect(ui.actionZoom_in, &QAction::triggered, this, &Notepad::zoomIn);
	connect(ui.actionZoom_out, &QAction::triggered, this, &Notepad::zoomOut);

	fontUpAction->setShortcut(QKeySequence("Ctrl++"));
	fontDownAction->setShortcut(QKeySequence("Ctrl+-"));
	addAction(fontUpAction);
	addAction(fontDownAction);
	connect(fontUpAction, &QAction::triggered, this, [this] { changeFontSize(1); });
	connect(fontDownAction, &QAction::triggered, this, [this] { changeFontSize(-1); });
	connect(zoomAction, &Zooming::wheelRolled, this, &Notepad::changeFontSize);

	connect(ui.actionfind, &QAction::triggered, this, &Notepad::showFinder);
	connect(ui.actionfont, &QAction::triggered, this, &Notepad::font);
	connect(ui.actiontextColor, &QAction::triggered, this, &Notepad::color);
	connect(ui.actionFind_in_file, &QAction::triggered, this, &Notepad::showFinder);

	ui.tabWidget->setMovable(true);
	ui.tabWidget->setTabsClosable(true);
	QStringList arguments = QApplication::arguments();
	QStringList::iterator it = arguments.begin();
	++it;
	for (; it != arguments.end(); ++it)
	{
		open(*it);
	}
}

void Notepad::open(QString filepath)
{
	QFile file(filepath);
	if (file.exists())
	{
		NotepadTab* newTab = new NotepadTab(this, filepath);
		newTab->setFont(notepadFont);
		newTab->setColor(notepadColor);
		int index = ui.tabWidget->addTab(newTab, newTab->getFilename());
		ui.tabWidget->setCurrentIndex(index);
		connect(newTab->getTextTab(), &QTextEdit::textChanged, this, &Notepad::textChange);
		connect(newTab->getTextTab(), &QTextEdit::cursorPositionChanged, this, [this, newTab] { currentLine->setText("Current line: " + QString::number(newTab->getCurrentLine())); });
	}
	else
	{
		QMessageBox message(this);
		message.setText("\"" + filepath + "\" doesn't exist.");
		message.setInformativeText("Do you want to create it?");
		message.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		message.setIcon(QMessageBox::Question);
		int answer = message.exec();
		if (answer == QMessageBox::Yes)
		{
			try
			{
				NotepadTab* newTab = new NotepadTab(this, filepath);
				newTab->setFont(notepadFont);
				newTab->setColor(notepadColor);
				int index = ui.tabWidget->addTab(newTab, newTab->getFilename());
				ui.tabWidget->setCurrentIndex(index);
				connect(newTab->getTextTab(), &QTextEdit::textChanged, this, &Notepad::textChange);
				connect(newTab->getTextTab(), &QTextEdit::cursorPositionChanged, this, [this, newTab] { currentLine->setText("Current line: " + QString::number(newTab->getCurrentLine())); });
			}
			catch (std::exception)
			{
				return;
			}
		}
		else
			return;
	}
}

void Notepad::newTab(int index)
{
	if (index == -1)
		newFile();
}

void Notepad::openFile()
{
	QString filepath = QFileDialog::getOpenFileName(this, "Choose a text file", "", "All files (*.*);;Text files (*.txt)");
	if (filepath.isEmpty())
		return;
	open(filepath);
}

void Notepad::saveFile()
{
	NotepadTab *textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab == nullptr)
		return;
	int currentIndex = ui.tabWidget->currentIndex();
	textTab->save();
	ui.tabWidget->setTabText(currentIndex, textTab->getFilename());
}

void Notepad::saveFileAs()
{
	NotepadTab *textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab == nullptr)
		return;
	int currentIndex = ui.tabWidget->currentIndex();
	QString savePath = QFileDialog::getSaveFileName(this, "Choose a folder to save file", "", "Text files (*.txt);;All files (*.*)");
	if (savePath.isEmpty())
		return;
	textTab->setPath(savePath);
	textTab->save();
	ui.tabWidget->setTabText(currentIndex, textTab->getFilename());
}

void Notepad::textChange()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
	{
		int currentIndex = ui.tabWidget->currentIndex();
		ui.tabWidget->setTabText(currentIndex, textTab->getFilename());
	}
	statusBarUpdate();
}

void Notepad::saveAll()
{
	if (ui.tabWidget->count() == 0)
		return;
	int index = 0;
	while (index != ui.tabWidget->count())
	{
		ui.tabWidget->setCurrentIndex(index);
		saveFile();
		++index;
	}
}

bool Notepad::closeTab(int index)
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(index));
	if (textTab == nullptr)
		return false;
	QString filename = ui.tabWidget->tabText(index);
	if (filename[0] != '*')
	{
		delete(ui.tabWidget->widget(index));
		return true;
	}
	QMessageBox message(this);
	message.setText("The document \""
		+ textTab->getFilename().right(textTab->getFilename().length()-1) + "\" has been modified.");
	message.setInformativeText("Do you want to save changes?");
	message.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
	message.setIcon(QMessageBox::Question);
	int answer = message.exec();
	switch (answer)
	{
	case QMessageBox::Yes:
		saveFile();
		break;
	case QMessageBox::No:
		break;
	case QMessageBox::Cancel:
		return false;
	}
	delete(ui.tabWidget->widget(index));
	return true;
}

void Notepad::newFile()
{
	NotepadTab* newTab = new NotepadTab(this, "");
	newTab->setFont(notepadFont);
	newTab->setColor(notepadColor);
	int index = ui.tabWidget->addTab(newTab, newTab->getFilename());
	ui.tabWidget->setCurrentIndex(index);
	connect(newTab->getTextTab(), &QTextEdit::textChanged, this, &Notepad::textChange);
	connect(newTab->getTextTab(), &QTextEdit::cursorPositionChanged, this, [this, newTab] { currentLine->setText("Current line: " + QString::number(newTab->getCurrentLine())); });
}

void Notepad::closeFile()
{
	int index = ui.tabWidget->currentIndex();
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(index));
	if (textTab != nullptr)
		closeTab(index);
}

void Notepad::closeAll()
{
	if (ui.tabWidget->count() == 0)
		return;
	while (ui.tabWidget->count() != 0)
	{
		if (!closeTab(0))
			break;
	}
}

void Notepad::undo()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
		textTab->getTextTab()->undo();
}

void Notepad::redo()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
		textTab->getTextTab()->redo();
}

void Notepad::copy()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
		textTab->getTextTab()->copy();
}

void Notepad::cut()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
		textTab->getTextTab()->cut();
}

void Notepad::paste()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
		textTab->getTextTab()->paste();
}

void Notepad::zoomIn()
{
	changeFontSize(1);
}

void Notepad::zoomOut()
{
	changeFontSize(-1);
}

void Notepad::clear()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
	{
		QTextDocument *document = textTab->getTextTab()->document();
		QTextCursor cursor(document);
		cursor.select(QTextCursor::Document);
		cursor.removeSelectedText();
	}
}

void Notepad::selectAll()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
		textTab->getTextTab()->selectAll();
}

void Notepad::showFinder()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab != nullptr)
	{
		if (finder != nullptr)
		{
			finder->show();
			return;
		}
		finder = new KeywordFinder(this);
		finder->setAttribute(Qt::WA_DeleteOnClose);
		connect(finder, &QObject::destroyed, this, &Notepad::closeFinder);
		connect(finder, &KeywordFinder::findRequest, this, &Notepad::find);
		finder->show();
	}
}

void Notepad::find()
{
	if (finder != nullptr)
	{
		NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
		if(textTab != nullptr)
			finder->findKeyword(textTab->getTextTab());
		else
			finder->close();
	}
}

void Notepad::restoreOriginalPalette()
{
	if (ui.tabWidget->count() == 0 || finder == nullptr)
		return;
	int index = 0;
	while (index != ui.tabWidget->count())
	{
		NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(index));
		textTab->getTextTab()->setPalette(originalPalette);
		++index;
	}
}

void Notepad::closeFinder()
{
	restoreOriginalPalette();
	finder = nullptr;
}

void Notepad::changeFontSize(int factor)
{
	if (ui.tabWidget->count() == 0)
		return;
	int index = 0;
	while (index != ui.tabWidget->count())
	{
		NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(index));
		QFont editorFont = textTab->getTextTab()->font();
		editorFont.setPointSize(std::max(editorFont.pointSize() + factor * 2, 6));
		textTab->setFont(editorFont);
		++index;
	}
	notepadFont = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(0))->getTextTab()->font();
}

void Notepad::font()
{
	bool fontSelected;
	QFont pickedFont = QFontDialog::getFont(&fontSelected, notepadFont, this);
	if (fontSelected)
	{
		notepadFont = pickedFont;
		int index = 0;
		while (index != ui.tabWidget->count())
		{
			NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(index));
			textTab->setFont(notepadFont);
			++index;
		}
	}
}

void Notepad::color()
{
	QColor pickedColor = QColorDialog::getColor(notepadColor, this);
	if (pickedColor.isValid())
	{
		notepadColor = pickedColor;
		originalPalette.setColor(QPalette::Text, notepadColor);
		int index = 0;
		while (index != ui.tabWidget->count())
		{
			NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(index));
			textTab->setColor(notepadColor);
			++index;
		}
		QPixmap pixmap(":/Notepad/Resources/blackSquare.png");
		QBitmap mask = pixmap.createMaskFromColor(Qt::black, Qt::MaskOutColor);
		pixmap.fill(notepadColor);
		pixmap.setMask(mask);
		ui.actiontextColor->setIcon(QIcon(pixmap));
	}
}

void Notepad::closeEvent(QCloseEvent *event)
{
	settings->setValue("color", notepadColor);
	settings->setValue("font", notepadFont);

	closeAll();
	if (ui.tabWidget->count() != 0)
		event->ignore();
	else
		event->accept();
}

void Notepad::applySettings()
{
	notepadColor = settings->value("color").value<QColor>();
	notepadFont = settings->value("font").value<QFont>();
	originalPalette.setColor(QPalette::Text, notepadColor);

	QPixmap pixmap(":/Notepad/Resources/blackSquare.png");
	QBitmap mask = pixmap.createMaskFromColor(Qt::black, Qt::MaskOutColor);
	pixmap.fill(notepadColor);
	pixmap.setMask(mask);
	ui.actiontextColor->setIcon(QIcon(pixmap));
}

void Notepad::restoreDefaultSettings()
{
	notepadColor = QColor();
	notepadFont = QFont();
	originalPalette.setColor(QPalette::Text, notepadColor);
	int index = 0;
	while (index != ui.tabWidget->count())
	{
		NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->widget(index));
		textTab->setColor(notepadColor);
		textTab->setFont(notepadFont);
		++index;
	}
	QPixmap pixmap(":/Notepad/Resources/blackSquare.png");
	QBitmap mask = pixmap.createMaskFromColor(Qt::black, Qt::MaskOutColor);
	pixmap.fill(notepadColor);
	pixmap.setMask(mask);
	ui.actiontextColor->setIcon(QIcon(pixmap));
}

void Notepad::statusBarUpdate()
{
	NotepadTab* textTab = dynamic_cast<NotepadTab*>(ui.tabWidget->currentWidget());
	if (textTab == nullptr)
	{
		charactersCount->setText("Characters count: ");
		wordsCount->setText("Words count: ");
		linesCount->setText("Lines count: ");
		currentLine->setText("Current line: ");
	}
	else
	{
		charactersCount->setText("Characters count: " + QString::number(textTab->getCharacters()));
		wordsCount->setText("Words count: " + QString::number(textTab->getWords()));
		linesCount->setText("Lines count: " + QString::number(textTab->getLines()));
		currentLine->setText("Current line: " + QString::number(textTab->getCurrentLine()));
	}
}