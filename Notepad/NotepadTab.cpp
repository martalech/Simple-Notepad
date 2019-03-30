#include "stdafx.h"
#include "NotepadTab.h"

IndexPool NotepadTab::untitledPool = IndexPool();

NotepadTab::NotepadTab(QWidget *parent)
	: QWidget(parent), textTab(nullptr)
{
}

NotepadTab::NotepadTab(QWidget *parent, QString path): QWidget(parent), path(path), characters(0), words(0), lines(0)
					  , currentLine(1)
{
	QString text = QString();
	if (!path.isEmpty())
	{
		QFile file(path);
		if (!file.open(QIODevice::ReadWrite | QFile::Text))
		{
			QMessageBox::warning(this, "Error", "Cannot open file");
			throw std::exception();
		}
		filename = QFileInfo(file).fileName();
		QTextStream in(&file);
		text = in.readAll();
		file.close();
	}
	else
	{	
		int index = untitledPool.takeIndex();
		if (index == 0)
			filename = "untitled.txt";
		else
			filename = "untitled" + QString::number(index) + ".txt";
	}
	originalText = text;
	textTab = new QTextEdit(this);
	QString textTabStyle = "QTextEdit { background-color: white; }";
	textTab->setStyleSheet(textTabStyle);
	textTab->setText(text);
	characters = textTab->toPlainText().length();
	countWords();
	lines = textTab->document()->lineCount();
	connect(textTab, &QTextEdit::textChanged, this, &NotepadTab::filenameChange);
	connect(textTab, &QTextEdit::currentCharFormatChanged, this, [this] { textTab->setTextColor(color); });
	connect(textTab, &QTextEdit::cursorPositionChanged, this, [this] { currentLine = textTab->textCursor().blockNumber() + 1; });

	QLayout* newLayout = new QHBoxLayout();
	newLayout->addWidget(textTab);
	setLayout(newLayout);
}

void NotepadTab::save()
{
	if (path.isEmpty())
	{
		path = QFileDialog::getSaveFileName(this, "Choose a folder to save file", "", "Text files (*.txt);;All files (*.*)");
		if (path.isEmpty())
			return;
		removeUntitled();
	}
	QFile file(path);
	QString newFilename = QFileInfo(file).fileName();
	if (file.open(QIODevice::WriteOnly))
	{
		if (filename != newFilename)
			filename = newFilename;
		updateOriginalText();
		QTextStream out(&file);
		out << originalText;
		file.close();
		if (filename[0] == '*')
			filename = filename.right(filename.size() - 1);
		textTab->document()->clearUndoRedoStacks();
		setWindowTitle(filename);
	}
	else
		QMessageBox::warning(this, "Error", "Cannot save file");
}

void NotepadTab::filenameChange()
{
	if (filename[0] != "*")
		filename = "*" + filename;
	if (textTab->toPlainText() == originalText)
		filename = filename.right(filename.size() - 1);
	characters = textTab->toPlainText().length();
	countWords();
	lines = textTab->document()->lineCount();
}

void NotepadTab::removeUntitled()
{
	QRegExp rx("untitled(\\d+)");
	int pos = rx.indexIn(filename);
	if (pos == -1)
		untitledPool.releaseIndex(0);
	else
	{
		int untitledIndex = rx.cap(1).toInt();
		untitledPool.releaseIndex(untitledIndex);
	}
}

NotepadTab::~NotepadTab()
{
	if (path.isEmpty())
		removeUntitled();
}

void NotepadTab::setPath(const QString& path)
{
	this->path = path;
}

void NotepadTab::setFilename(const QString& filename)
{
	this->filename = filename;
}

void NotepadTab::updateOriginalText()
{
	originalText = textTab->toPlainText();
}

QTextEdit* NotepadTab::getTextTab()
{
	return textTab;
}

QString NotepadTab::getFilename()
{
	return filename;
}

void NotepadTab::setFont(QFont fon)
{
	font = fon;
	textTab->setFont(font);
}

void NotepadTab::setColor(QColor col)
{
	color = col;
	QPalette palette;
	palette.setColor(QPalette::Text, color);
	textTab->setPalette(palette);
}

void NotepadTab::countWords()
{
	int spaces = 0;
	QString text = textTab->toPlainText();
	int i = 0;
	if (text[i].isSpace())
	{
		while (text[i].isSpace() && text[i] != '\0')
			++i;
	}
	for (; i<text.length(); ++i)
	{
		++spaces;
		while (text[i].isSpace() && text[i] != '\0')
		{
			++i;
		}
		while (!text[i].isSpace() && text[i] != '\0')
		{
			++i;
		}
	}
	words = spaces;
}
