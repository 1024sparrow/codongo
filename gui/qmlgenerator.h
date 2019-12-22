#ifndef QMLGENERATOR_H
#define QMLGENERATOR_H

#include <QString>

class QmlGenerator
{
public:
	QmlGenerator();
	bool generate();
private:
	QString getLayoutId(const QString &layoutTitle); // get instance id for class id
};

#endif // QMLGENERATOR_H
