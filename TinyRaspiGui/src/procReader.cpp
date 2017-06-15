#include "procReader.h"

#include "math.h"

#include <QFile>
#include <QDir>
#include <QTextStream>

CProcReader::CProcReader(const QString& name, InterpretScheme scheme)
{
	SetProcFileName(name);
	SetProcScheme(scheme);

	m_updateCount = 0;
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
	InterpretScheme derivedInterpretation = InterpretScheme::Invalid;
	QByteArray contents;
	QFile file(m_procFileName);
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug("Unable to open file %s, aborting", qPrintable(file.fileName()));
	}
	else if (!file.isReadable()) {
		qDebug("Unable to read file %s, aborting", qPrintable(file.fileName()));
	}
	else
	{
		contents = file.readAll();
		derivedInterpretation = m_interpretScheme;
	}
	file.close();

	switch (derivedInterpretation)
	{
	case LoadAvg:
		{
		QStringList values;
		QTextStream in(&contents);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			values = line.split(QChar(' '));
			if (values.size() < 3)
				continue;
		}
		if (values.size() > 2)
		{
			double avg1 = values.at(0).toDouble();
			double avg5 = values.at(1).toDouble();
			double avg15 = values.at(2).toDouble();
			QList<double> avgs = QList<double>() << avg1 << avg5 << avg15;
			emit valuesRead(avgs);
		}
		}
		break;
	case NetStat:
		{
		QList<QStringList> parsedTextLines;
		QTextStream in(&contents);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			QStringList values = line.split(QChar(' '));

			if (parsedTextLines.size())
				Q_ASSERT(parsedTextLines.back().size() == values.size());

			parsedTextLines.push_back(values);
		}
		if (parsedTextLines.size() > 3 && parsedTextLines.at(3).size() > 13)
		{
			double InMcastPkts = parsedTextLines.at(3).at(3).toDouble();
			double OutMcastPkts = parsedTextLines.at(3).at(4).toDouble();
			double InBcastPkts = parsedTextLines.at(3).at(5).toDouble();
			double OutBcastPkts = parsedTextLines.at(3).at(6).toDouble();
			double InCsumErrors = parsedTextLines.at(3).at(13).toDouble();
			QList<double> avgs = QList<double>() << InMcastPkts << OutMcastPkts << InBcastPkts << OutBcastPkts << InCsumErrors;
			emit valuesRead(avgs);
		}
		}
		break;
	default:
		{
		QList<double> dummys = QList<double>() << sinf(m_updateCount*0.1) << cosf(m_updateCount*0.1);
		emit valuesRead(dummys);
		}
		break;
	}

	m_updateCount++;
}
