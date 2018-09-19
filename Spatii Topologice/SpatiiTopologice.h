#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SpatiiTopologice.h"

class SpatiiTopologice : public QMainWindow
{
	Q_OBJECT

public:
	SpatiiTopologice(QWidget *parent = Q_NULLPTR);

private:
	Ui::SpatiiTopologiceClass ui;
};
