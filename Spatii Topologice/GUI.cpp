
#include "GUI.h"

GUI::GUI(Multime<int>& mul, VectorDinamic& familie) : mul{ mul }, familie{ familie }
{
	w->setLayout(box);
	//w->setMinimumWidth(200);
	//w->setMaximumWidth(200);
	
	e->setLayout(empty);

	BIG->setLayout(big);

	big->addRow(add_set, Eadd_set);
	big->addWidget(buttonAddSet);

	big->addRow(add_subSet, Eadd_subSet);
	big->addWidget(buttonAddSubSet);
	big->addWidget(C);
	big->addWidget(cm1);
	big->addWidget(cm2);
	big->addRow(cm3,Ecm3);
	big->addWidget(construct);
	big->addWidget(cm4);
	
	//e->setMinimumWidth(500);

	principal->addWidget(w);
	principal->addWidget(e);

	main->setLayout(mainLayout);

	mainLayout->addWidget(instructional);
	mainLayout->addLayout(principal);
	mainLayout->addLayout(big);
	mainLayout->addWidget(BIG);
	
	
	//main->setMinimumWidth(700);

	box->addWidget(msg1);
	box->addWidget(list_set);
	box->addWidget(buttonDel1);

	empty->addWidget(msg2);
	empty->addWidget(list_Subset);
	empty->addWidget(buttonDel2);

	connect(buttonAddSet, &QPushButton::clicked, this, &GUI::clickExeAdd1);
	connect(buttonAddSubSet, &QPushButton::clicked, this, &GUI::clickExeAdd2);
	connect(C, &QPushButton::clicked, this, &GUI::ver);
	connect(construct, &QPushButton::clicked, this, &GUI::populate);
	connect(instructional, &QPushButton::clicked, this, &GUI::showI);
	connect(gen, &QPushButton::clicked, this, &GUI::gen_fam);
	connect(buttont4, &QPushButton::clicked, this, &GUI::SubSets);
	//connect(buttonDel1, &QPushButton::clicked, this, &GUI::clickExeDel1);
	QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Delete),main);
	connect(shortcut, SIGNAL(activated()), this, SLOT(clickExeDel1()));

	QShortcut *shortcut2 = new QShortcut(QKeySequence(Qt::Key_Return), main);
	connect(shortcut2, SIGNAL(activated()), this, SLOT(clickExeDel2()));
	//main->setStyleSheet("background-color:rgb(95,158,160)");
	color();
	Eadd_set->setValidator(new QIntValidator(0, INT_MAX, this));
	Ecm3->setValidator(new QIntValidator(0, INT_MAX, this));
	Et1->setValidator(new QIntValidator(0, INT_MAX, this));
	//Eadd_subSet->setValidator(new QIntValidator(0, INT_MAX, this));

	updateListSet();
	QPixmap pixmap;
	pixmap.load("0KKfV.png");
	myLabel->setPixmap(pixmap);
	mainLayout->addWidget(myLabel);
	main->show();

	intr->setLayout(intr_layout);
	QPixmap pixmap2;
	pixmap2.load("d507cf5f6d362feba7a8468df3795fbf.png");
	im->setPixmap(pixmap2);
	//im->setFixedWidth(2000);
	intr_layout->addWidget(wel);
	intr_layout->addWidget(im);
	intr_layout->addWidget(txt1);
	intr_layout->addWidget(txt2);
	intr_layout->addRow(t1,Et1);
	intr_layout->addWidget(t2);
	intr_layout->addWidget(gen);
	intr_layout->addWidget(t3);
	intr_layout->addWidget(li);
	intr_layout->addRow(t4, buttont4);
	intr_layout->addWidget(allOfThem);
	intr->hide();

}
void GUI::color()
{
	QPalette pal = C->palette();
	pal.setColor(QPalette::Button, QColor(Qt::red));
	C->setAutoFillBackground(true);
	C->setPalette(pal);

	QPalette pal2 = buttonAddSet->palette();
	pal2.setColor(QPalette::Button, QColor(Qt::blue));
	buttonAddSet->setAutoFillBackground(true);
	buttonAddSet->setPalette(pal2);

	QPalette pal3 = buttonAddSubSet->palette();
	pal3.setColor(QPalette::Button, QColor(Qt::blue));
	buttonAddSubSet->setAutoFillBackground(true);
	buttonAddSubSet->setPalette(pal3);

	QPalette pal4 = construct->palette();
	pal4.setColor(QPalette::Button, QColor(Qt::green));
	construct->setAutoFillBackground(true);
	construct->setPalette(pal4);

	cm1->setStyleSheet("QLabel { background-color : red; color : blue; }");
	cm4->setStyleSheet("QLabel { background-color : white; color: green; }");
	cm4->setStyleSheet("QLabel { font: bold italic large ; background-color : white; color: green; }");
	txt1->setStyleSheet("QLabel { font: bold italic large ; background-color : white; color: blue; }");
	t3->setStyleSheet("QLabel { font: bold italic large }");
	instructional->setStyleSheet("QPushButton { font: bold italic large ; background-color : yellow; color: blue; }");
	wel->setStyleSheet("QLabel { font: bold italic large ; background-color : brown; color: blue; }");
}
void GUI::updateListSet()
{
	list_set->clear();
	int i;
	for (i = 0; i < mul.dim(); i++)
	{
		QString str = QString::fromStdString(std::to_string(mul.element(i)));
		QListWidgetItem* lis = new QListWidgetItem(str, list_set);
		lis;
	}
}
void GUI::updateFamilie()
{
	list_Subset->clear();
	int i;
	int j;
	for (i = 0; i < familie.dim(); i++)
	{
		std::string str="";
		familie.element(i);
		for (j = 0; j < familie.element(i).dim(); j++)
		{
			str = str + std::to_string(familie.element(i).element(j));
			if (j != familie.element(i).dim() - 1)
			{
				str = str + ",";
			}
		}
		if (str != "")
		{
			QString s = QString::fromStdString(str);
			QListWidgetItem* lis = new QListWidgetItem(s, list_Subset);
			lis;
		}
		else
		{
			QString s = QString::fromStdString("empty_set");
			QListWidgetItem* lis = new QListWidgetItem(s, list_Subset);
			lis;
		}
		
	}
}
void GUI::clickExeAdd1()
{
	mul.add(Eadd_set->text().toInt());
	updateListSet();
	Eadd_set->clear();
}
void GUI::clickExeAdd2()
{
	std::string str = Eadd_subSet->text().toStdString();
	//qDebug() << Eadd_subSet->text();
	std::vector<int> vect;

	std::stringstream ss(str);

	int i;

	while (ss >> i)
	{
		vect.push_back(i);

		if (ss.peek() == ',')
			ss.ignore();
	}
	Multime<int> subm{ 100 };
	for (i = 0; i < vect.size(); i++)
		subm.add(vect.at(i));

	//for (i = 0; i < subm.dim(); i++)
	//{
	//	qDebug() << subm.element(i) << " ";
	//}
	//qDebug() << "gata prima ";
	//for (i = 0; i < mul.dim(); i++)
	//{
	//	qDebug() << mul.element(i) << " ";
	//}
	//qDebug() << "gata a doua ";
	if (mul.isSubSet(subm) == false)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Submultimea introdusa nu este o submultume a multimii curente !");
		messageBox.setFixedSize(500, 200);
	}
	else
	{
		familie.adaugaSfarsit(subm);
	}
	updateFamilie();
	Eadd_subSet->clear();

}
void GUI::clickExeDel1()
{
	QList<QListWidgetItem*> items = list_set->selectedItems();
	foreach(QListWidgetItem * item, items)
	{
		mul.del(item->text().toInt());
		//list_set->takeItem(list_set->row(item));
	}
	updateListSet();
	int i;
	for (i = 0; i < mul.dim(); i++)
	{
		qDebug() << mul.element(i) << " ";
	}
}
void GUI::clickExeDel2()
{
	qDebug() << "A intrat";
	QModelIndexList indexes = list_Subset->selectionModel()->selectedIndexes();

	foreach(QModelIndex index, indexes)
	{
		qDebug() << index.row();
		familie.sterge(index.row());
		
	}
	updateFamilie();
	
}
void GUI::populate()
{
	srand(0);
	int n = Ecm3->text().toInt();
	if (n > 200)
	{
		QMessageBox msgBox;
		msgBox.setText("We limit our set size to max 200 items for practical reasons...");
		msgBox.exec();
		return;
	}
	else
	{
		std::vector<int> vect;
		while (vect.size() < n)
		{
			int r = rand() % 1000;
			auto it = std::find_if(vect.begin(), vect.end(), [&r](auto x) {return x == r; });
			if (it == vect.end())
				vect.push_back(r);
		}
		for (auto i : vect)
		{
			mul.add(i);
		}
		updateListSet();
	}
}
void GUI::ver()
{
	Spatiu sp = Spatiu{ mul, familie };
	int i;
	if (sp.check() == 1)
	{
		QMessageBox msgBox;
		std::string str = "";
		str = str + "Axiom 1 does not stand !";
		Multime<int> fail = sp.getTrouble();
		str = str + " The next set is not part of the family: {";
		for (i = 0; i < fail.dim(); i++)
		{
			str = str + std::to_string(fail.element(i));
			if(i!=fail.dim()-1)
				str = str + ",";
		}
		str = str + "}";
		QString qstr = QString::fromStdString(str);
		msgBox.setText(qstr);
		msgBox.exec();
	}
	if (sp.check() == 2)
	{
		QMessageBox msgBox;
		std::string str = "";
		str = str + "Axiom 2 does not stand !";
		Multime<int> fail = sp.getTrouble();
		str = str + " The next set is not part of the family: {";
		for (i = 0; i < fail.dim(); i++)
		{
			str = str + std::to_string(fail.element(i));
			if (i != fail.dim() - 1)
				str = str + ",";
		}
		str = str + "}";
		QString qstr = QString::fromStdString(str);
		msgBox.setText(qstr);
		msgBox.exec();
	}
	if (sp.check() == 3)
	{
		QMessageBox msgBox;
		std::string str = "";
		str = str + "Axiom 3 does not stand !";
		Multime<int> fail = sp.getTrouble();
		str = str + " The next set is not part of the family: {";
		for (i = 0; i < fail.dim(); i++)
		{
			str = str + std::to_string(fail.element(i));
			if (i != fail.dim() - 1)
				str = str + ",";
		}
		str = str + "}";
		QString qstr = QString::fromStdString(str);
		msgBox.setText(qstr);
		msgBox.exec();
	}
	if (sp.check() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText("It is a topological space !!!");
		msgBox.exec();
	}
}
void GUI::showI()
{
	intr->show();
}
void GUI::gen_fam()
{
	int d = Et1->text().toInt();
	if (d >= 10)
	{
		QMessageBox msgBox;
		msgBox.setText("We said no more than 10...");
		msgBox.exec();
		return;
	}
	int m=mul.dim();
	if (d == 0)
	{
		QMessageBox msgBox;
		msgBox.setText("You are trolling with 0...");
		msgBox.exec();
		return;
	}
	if (d == 1)
	{
		QMessageBox msgBox;
		msgBox.setText("What does axiom 1 tell you?..of course we need more than 1 subset for a topological space...");
		msgBox.exec();
		return;
	}
	if (d == 2)
	{
		QMessageBox msgBox;
		msgBox.setText("Tere is only one topological space with this size, you guessed it..empty set and self set");
		msgBox.exec();
		return;
	}
	if (d == 3)
	{
		if (m >= 2)
		{
			li->clear();
			QString s = "empty set";
			QListWidgetItem* lis = new QListWidgetItem(s, li);
			lis;
			std::string s1;
			for (int i = 0; i < mul.dim(); i++)
			{
				s1 = s1 + std::to_string(mul.element(i));
				if(i!=mul.dim()-1)
					s1 = s1 + ",";
			}
			QString qs1 = QString::fromStdString(s1);
			QListWidgetItem* lis1 = new QListWidgetItem(qs1, li);
			lis1;
			QString qs2 = QString::fromStdString(std::to_string(mul.element(0)));
			QListWidgetItem* lis2 = new QListWidgetItem(qs2, li);
			lis2;

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("You are kidding right? the main subset is less than 2 elements long lol");
			msgBox.exec();
		}
		return;
	}
	if (d == 4)
	{
		if (m >= 3)
		{
			li->clear();
			QString s = "empty set";
			QListWidgetItem* lis = new QListWidgetItem(s, li);
			lis;
			std::string s1;
			for (int i = 0; i < mul.dim(); i++)
			{
				s1 = s1 + std::to_string(mul.element(i));
				if (i != mul.dim() - 1)
					s1 = s1 + ",";
			}
			QString qs1 = QString::fromStdString(s1);
			QListWidgetItem* lis1 = new QListWidgetItem(qs1, li);
			lis1;
			QString qs2 = QString::fromStdString(std::to_string(mul.element(0)));
			QListWidgetItem* lis2 = new QListWidgetItem(qs2, li);
			lis2;
			std::string strin = "";
			strin = strin + std::to_string(mul.element(0));
			strin = strin + ",";
			strin = strin + std::to_string(mul.element(1));
			QString qs3 = QString::fromStdString(strin);
			QListWidgetItem* lis3 = new QListWidgetItem(qs3, li);
			lis3;

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("You are kidding right? the main subset is less than 3 elements long lol");
			msgBox.exec();
		}
		return;
	}
	if (d == 5)
	{
		if (m >= 3)
		{
			li->clear();
			QString s = "empty set";
			QListWidgetItem* lis = new QListWidgetItem(s, li);
			lis;
			std::string s1;
			for (int i = 0; i < mul.dim(); i++)
			{
				s1 = s1 + std::to_string(mul.element(i));
				if (i != mul.dim() - 1)
					s1 = s1 + ",";
			}
			QString qs1 = QString::fromStdString(s1);
			QListWidgetItem* lis1 = new QListWidgetItem(qs1, li);
			lis1;
			QString qs2 = QString::fromStdString(std::to_string(mul.element(0)));
			QListWidgetItem* lis2 = new QListWidgetItem(qs2, li);
			lis2;
			std::string strin = "";
			strin = strin + std::to_string(mul.element(0));
			strin = strin + ",";
			strin = strin + std::to_string(mul.element(1));
			QString qs3 = QString::fromStdString(strin);
			QListWidgetItem* lis3 = new QListWidgetItem(qs3, li);
			lis3;

			std::string strin2 = "";
			strin2 = strin2 + std::to_string(mul.element(1));
			QString qs4 = QString::fromStdString(strin2);
			QListWidgetItem* lis4 = new QListWidgetItem(qs4, li);
			lis4;

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("You are kidding right? the main subset is less than 3 elements long lol");
			msgBox.exec();
		}
		return;
	}
	if (d == 6)
	{
		if (m >= 3)
		{
			QMessageBox msgBox;
			msgBox.setText("That example with work if the base set is only the first 3 elements from the list in the main window");
			msgBox.exec();

			li->clear();
			QString s = "empty set";
			QListWidgetItem* lis = new QListWidgetItem(s, li);
			lis;
			std::string s1;
			for (int i = 0; i < mul.dim(); i++)
			{
				s1 = s1 + std::to_string(mul.element(i));
				if (i != mul.dim() - 1)
					s1 = s1 + ",";
			}
			QString qs1 = QString::fromStdString(s1);
			QListWidgetItem* lis1 = new QListWidgetItem(qs1, li);
			lis1;
			QString qs2 = QString::fromStdString(std::to_string(mul.element(0)));
			QListWidgetItem* lis2 = new QListWidgetItem(qs2, li);
			lis2;
			std::string strin = "";
			strin = strin + std::to_string(mul.element(0));
			strin = strin + ",";
			strin = strin + std::to_string(mul.element(1));
			QString qs3 = QString::fromStdString(strin);
			QListWidgetItem* lis3 = new QListWidgetItem(qs3, li);
			lis3;

			std::string strin2 = "";
			strin2 = strin2 + std::to_string(mul.element(1));
			QString qs4 = QString::fromStdString(strin2);
			QListWidgetItem* lis4 = new QListWidgetItem(qs4, li);
			lis4;

			std::string S = "";
			S = S + std::to_string(mul.element(0));
			S = S + ",";
			S = S + std::to_string(mul.element(2));
			QString qs5 = QString::fromStdString(S);
			QListWidgetItem* lis5 = new QListWidgetItem(qs5, li);
			lis5;

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("You are kidding right? the main subset is less than 3 elements long lol");
			msgBox.exec();
		}
		return;
	}
	if (d == 7)
	{
		if (m >= 3)
		{
			li->clear();
			QMessageBox msgBox;
			msgBox.setText("That example with work if the base set is only the first 3 elements from the list in the main window");
			msgBox.exec();

			QString s = "empty set";
			QListWidgetItem* lis = new QListWidgetItem(s, li);
			lis;
			std::string s1;
			for (int i = 0; i < mul.dim(); i++)
			{
				s1 = s1 + std::to_string(mul.element(i));
				if (i != mul.dim() - 1)
					s1 = s1 + ",";
			}
			QString qs1 = QString::fromStdString(s1);
			QListWidgetItem* lis1 = new QListWidgetItem(qs1, li);
			lis1;
			QString qs2 = QString::fromStdString(std::to_string(mul.element(0)));
			QListWidgetItem* lis2 = new QListWidgetItem(qs2, li);
			lis2;
			std::string strin = "";
			strin = strin + std::to_string(mul.element(0));
			strin = strin + ",";
			strin = strin + std::to_string(mul.element(1));
			QString qs3 = QString::fromStdString(strin);
			QListWidgetItem* lis3 = new QListWidgetItem(qs3, li);
			lis3;

			std::string strin2 = "";
			strin2 = strin2 + std::to_string(mul.element(1));
			QString qs4 = QString::fromStdString(strin2);
			QListWidgetItem* lis4 = new QListWidgetItem(qs4, li);
			lis4;

			std::string S = "";
			S = S + std::to_string(mul.element(0));
			S = S + ",";
			S = S + std::to_string(mul.element(2));
			QString qs5 = QString::fromStdString(S);
			QListWidgetItem* lis5 = new QListWidgetItem(qs5, li);
			lis5;

			std::string strin22 = "";
			strin22 = strin22 + std::to_string(mul.element(2));
			QString qs6 = QString::fromStdString(strin22);
			QListWidgetItem* lis6 = new QListWidgetItem(qs6, li);
			lis6;

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("You are kidding right? the main subset is less than 3 elements long lol");
			msgBox.exec();
		}
		return;
	}
	if (d == 8)
	{
		if (m >= 3)
		{
			li->clear();
			QMessageBox msgBox;
			msgBox.setText("That example with work if the base set is only the first 3 elements from the list in the main window");
			msgBox.exec();

			QString s = "empty set";
			QListWidgetItem* lis = new QListWidgetItem(s, li);
			lis;
			std::string s1;
			for (int i = 0; i < mul.dim(); i++)
			{
				s1 = s1 + std::to_string(mul.element(i));
				if (i != mul.dim() - 1)
					s1 = s1 + ",";
			}
			QString qs1 = QString::fromStdString(s1);
			QListWidgetItem* lis1 = new QListWidgetItem(qs1, li);
			lis1;
			QString qs2 = QString::fromStdString(std::to_string(mul.element(0)));
			QListWidgetItem* lis2 = new QListWidgetItem(qs2, li);
			lis2;
			std::string strin = "";
			strin = strin + std::to_string(mul.element(0));
			strin = strin + ",";
			strin = strin + std::to_string(mul.element(1));
			QString qs3 = QString::fromStdString(strin);
			QListWidgetItem* lis3 = new QListWidgetItem(qs3, li);
			lis3;

			std::string strin2 = "";
			strin2 = strin2 + std::to_string(mul.element(1));
			QString qs4 = QString::fromStdString(strin2);
			QListWidgetItem* lis4 = new QListWidgetItem(qs4, li);
			lis4;

			std::string S = "";
			S = S + std::to_string(mul.element(0));
			S = S + ",";
			S = S + std::to_string(mul.element(2));
			QString qs5 = QString::fromStdString(S);
			QListWidgetItem* lis5 = new QListWidgetItem(qs5, li);
			lis5;

			std::string strin22 = "";
			strin22 = strin22 + std::to_string(mul.element(2));
			QString qs6 = QString::fromStdString(strin22);
			QListWidgetItem* lis6 = new QListWidgetItem(qs6, li);
			lis6;

			std::string SS = "";
			SS = SS + std::to_string(mul.element(1));
			SS = SS + ",";
			SS = SS + std::to_string(mul.element(2));
			QString qs7 = QString::fromStdString(SS);
			QListWidgetItem* lis7 = new QListWidgetItem(qs7, li);
			lis7;

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("You are kidding right? the main subset is less than 3 elements long lol");
			msgBox.exec();
		}
		return;
	}
	if (d == 9)
	{
		if (m >= 4)
		{
			li->clear();
			QMessageBox msgBox;
			msgBox.setText("We will take only the first 4 elements from the list and form a base set (from the other window) and illustrate an example in this case");
			msgBox.exec();

			QString s = "empty set";
			QListWidgetItem* lis = new QListWidgetItem(s, li);
			lis;
			std::string s1;
			for (int i = 0; i < mul.dim(); i++)
			{
				s1 = s1 + std::to_string(mul.element(i));
				if (i != mul.dim() - 1)
					s1 = s1 + ",";
			}
			QString qs1 = QString::fromStdString(s1);
			QListWidgetItem* lis1 = new QListWidgetItem(qs1, li);
			lis1;
			QString qs2 = QString::fromStdString(std::to_string(mul.element(0)));
			QListWidgetItem* lis2 = new QListWidgetItem(qs2, li);
			lis2;
			std::string strin = "";
			strin = strin + std::to_string(mul.element(0));
			strin = strin + ",";
			strin = strin + std::to_string(mul.element(1));
			QString qs3 = QString::fromStdString(strin);
			QListWidgetItem* lis3 = new QListWidgetItem(qs3, li);
			lis3;

			std::string strin2 = "";
			strin2 = strin2 + std::to_string(mul.element(1));
			QString qs4 = QString::fromStdString(strin2);
			QListWidgetItem* lis4 = new QListWidgetItem(qs4, li);
			lis4;

			std::string S = "";
			S = S + std::to_string(mul.element(0));
			S = S + ",";
			S = S + std::to_string(mul.element(2));
			QString qs5 = QString::fromStdString(S);
			QListWidgetItem* lis5 = new QListWidgetItem(qs5, li);
			lis5;

			std::string strin22 = "";
			strin22 = strin22 + std::to_string(mul.element(2));
			QString qs6 = QString::fromStdString(strin22);
			QListWidgetItem* lis6 = new QListWidgetItem(qs6, li);
			lis6;

			std::string SS = "";
			SS = SS + std::to_string(mul.element(1));
			SS = SS + ",";
			SS = SS + std::to_string(mul.element(2));
			QString qs7 = QString::fromStdString(SS);
			QListWidgetItem* lis7 = new QListWidgetItem(qs7, li);
			lis7;

			std::string SSS = "";
			SSS = SSS + std::to_string(mul.element(1));
			SSS = SSS + ",";
			SSS = SSS + std::to_string(mul.element(2));
			SSS = SSS + ",";
			SSS = SSS + std::to_string(mul.element(0));
			QString qs8 = QString::fromStdString(SSS);
			QListWidgetItem* lis8 = new QListWidgetItem(qs8, li);
			lis8;

		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText("We need at least 4 elements in the base set for this to work, mate");
			msgBox.exec();
		}
		return;
	}

}
void GUI::SubSets()
{
	std::vector<int> arr;
	li->clear();
	for (int i = 0; i < mul.dim(); i++)
	{
		arr.push_back(mul.element(i));
	}
	GenerateSubSets g{ arr };
	for (auto el : g.print())
	{
		std::string s1;
		for (int i = 0; i < el.size(); i++)
		{
			if (el.at(i) != null)
			{
				s1 = s1 + std::to_string(el.at(i));
				if (i != el.size() - 1)
					s1 = s1 + ",";
			}
			
		}
		QString qs1 = QString::fromStdString(s1);
		QListWidgetItem* lis1 = new QListWidgetItem(qs1, allOfThem);
		lis1;
	}
	
}
