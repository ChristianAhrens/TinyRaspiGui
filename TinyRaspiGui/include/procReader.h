#pragma once

#ifndef PROCREADER_H
#define PROCREADER_H

#include <QObject>


enum InterpretScheme {
	Invalid = 0,
	CpuInfo,
	DiskStats,
	LoadAvg,
	MemInfo,
	Stat,
	NetStat
};

class CProcReader : public QObject
{
	Q_OBJECT
	
signals:
	void valuesRead(const QList<double>& values);

public slots:
	void update();

public:
	CProcReader(const QString& name = "/proc/loadavg", InterpretScheme scheme = LoadAvg);

	bool SetProcFileName(const QString& name);
	bool SetProcScheme(InterpretScheme scheme);

private:
	QString			m_procFileName;
	InterpretScheme m_interpretScheme;
	int				m_updateCount;
};
#endif //PROCREADER_H
