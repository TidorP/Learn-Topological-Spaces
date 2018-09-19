#pragma once
#include <QTWidgets>
#include <QObject>
#include "Linked.h"
#include "VectorDin.h"
#include "Spatiu.h"
#include <QDebug>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <GenerateSubSets.h>
class GUI :public QObject
{
	Q_OBJECT

private:
	Multime<int> mul{ 100 };
	VectorDinamic familie;

	QWidget * w = new QWidget();
	QWidget* e = new QWidget();
	QWidget* main = new QWidget();
	QWidget* BIG = new QWidget();

	QVBoxLayout* box = new QVBoxLayout();
	QVBoxLayout* empty = new QVBoxLayout();
	QFormLayout* big = new QFormLayout();
	QHBoxLayout* principal = new QHBoxLayout();
	QVBoxLayout* mainLayout = new QVBoxLayout();

	QListWidget* list_set = new QListWidget;
	QListWidget* list_Subset = new QListWidget;
	QLabel* msg1 = new QLabel("Base set:");
	QLabel* msg2 = new QLabel("Family of subsets:");

	QLabel* add_set = new QLabel("Add an element in the set");
	QLineEdit* Eadd_set = new QLineEdit;
	QPushButton* buttonAddSet = new QPushButton("Add in set");

	QLabel* add_subSet = new QLabel("Give a subset (each element separated by comma)");
	QLineEdit* Eadd_subSet = new QLineEdit;
	QPushButton* buttonAddSubSet = new QPushButton("Add a subset");


	QPushButton* C = new QPushButton("Time to check");
	QLabel* buttonDel1 = new QLabel("Select an element from the list and press delete to remove it");
	QLabel* buttonDel2 = new QLabel("Select a subset from the list and press enter to remove it from the family");

	QLabel* cm1 = new QLabel("Shortcut command");
	QLabel* cm2 = new QLabel("Construct a random set with a given size to add to our main set of elements:");
	QLabel* cm3 = new QLabel("Input size:");
	QLineEdit* Ecm3 = new QLineEdit;
	QPushButton* construct= new QPushButton("Construct");
	QLabel* cm4 = new QLabel("Try not to add more than 30 a time after the second call !");

	QPushButton* instructional= new QPushButton("Jump to the instructional part, learn how it works and what it means, see some examples !");
	QLabel * myLabel = new QLabel;


	//part 2
	QWidget* intr = new QWidget;
	QFormLayout* intr_layout = new QFormLayout;
	QLabel* wel = new QLabel("Welcome to our learning demo app, fellow seeker of truth !");
	QLabel* im = new QLabel;
	QLabel* txt1 = new QLabel("Let the program find some topological spaces for you !");
	QLabel* txt2 = new QLabel("Be sure you already inserted some elements to our mainset, we will construct some topological spaces for you with respect to that base set !");
	QLabel* t1 = new QLabel("Give a number N to construct a family of N-subsets for our main set");
	QLineEdit* Et1 = new QLineEdit;
	QLabel* t2 = new QLabel("Don't forget this is just for instructional purposes, type an integer less than 10 !");
	QLabel* t3 = new QLabel("For example, this family will give a topological space !");
	QPushButton* gen = new QPushButton("Show example");
	QListWidget* li = new QListWidget;
	QLabel* t4 = new QLabel("Not familiar with the term \"SubSet\"? Click here to show you all the subsets of our mainSet!");
	QPushButton* buttont4 = new QPushButton("Click");
	QListWidget* allOfThem = new QListWidget;



public:
	GUI(Multime<int>& mul, VectorDinamic& familie);
	private slots:
	void color();
	void updateListSet();
	void updateFamilie();
	void clickExeAdd1();
	void clickExeAdd2();
	void clickExeDel1();
	void clickExeDel2();
	void populate();
	void ver();
	void showI();
	void gen_fam();
	void SubSets();
};

