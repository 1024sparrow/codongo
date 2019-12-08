#ifndef MW_H
#define MW_H

#include <QWidget>

class MW : public QWidget
{
	Q_OBJECT
public:
	MW();
protected:
	void paintEvent(QPaintEvent *e);
};

#endif // MW_H
