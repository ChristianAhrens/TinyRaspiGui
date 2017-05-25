#include "procReader.h"

#include <QFile>
#include <QDir>
#include <QTextStream>

CProcReader::CProcReader(const QString& name, InterpretScheme scheme)
{
	SetProcFileName(name);
	SetProcScheme(scheme);
}

bool CProcReader::SetProcFileName(const QString& name)
{
	m_procFileName = name;

	return true;
}

bool CProcReader::SetProcScheme(InterpretScheme scheme)
{
	m_interpretScheme = scheme;

	return true;
}

void CProcReader::update()
{
	QFile file(m_procFileName);
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug("Unable to open file %s, aborting", qPrintable(file.fileName()));
		return;
	}
	if (!file.isReadable()) {
		qDebug("Unable to read file %s, aborting", qPrintable(file.fileName()));
		return;
	}
	QByteArray contents = file.readAll();
	file.close();

	switch (m_interpretScheme)
	{
	case LoadAvg:
		{
		QTextStream in(&contents);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			QStringList values = line.split(QChar(' '));
			if (values.size() < 3)
				continue;
			double avg1 = values.at(0).toDouble();
			double avg5 = values.at(1).toDouble();
			double avg15 = values.at(2).toDouble();
			QList<double> avgs = QList<double>() << avg1 << avg5 << avg15;
			emit valuesRead(avgs);
		}
		}
		break;
	default:
		{
		emit valuesRead(QList<double>() << 0);
		}
		break;
	}
}
