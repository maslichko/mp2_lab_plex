#pragma once
#include "TBase.h"
#include "TPoint.h"
#include "TLine.h"
#include "TSquare.h"
#include "TCanvas.h"

#include <string>

class TPlex : public TBase {
protected:
	TBase* left;
	TBase* right;
public:
	TPlex();
	TPlex(TPoint* a, TPoint* b);
	TPlex(char* s);
	TPlex(const TPlex& p);

	virtual void Print();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](char* name);
	virtual double& operator[](int i);

	virtual TBase* GetChild(int i);
	virtual void SetChild(TBase* c, int i);
	virtual TBase* PrintAll(TBase* p);
	TBase* GetLeft();
	TBase* GetRight();

	TPlex* GetLeftPlex();
	TPlex* GetRightPlex();

	void SetLeft(TBase* x);
	void SetRight(TBase* x);
	bool AddLine(TPoint* a, TPoint* b);

	virtual int GetChildCount()
	{
		return 2;
	}

	virtual TBase* Clone();
};

TPlex::TPlex() 
{
	left = new TPoint();
	right = new TPoint();
}

TPlex::TPlex(char* s) //Чар* вида - 1 2, 3 4, 5 6, 7 8
{
	int count = 1;
	int cc = 0;
	int i = 0;
	int j = 0;

	//Считаем количество цифр и элементов в чар*
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			count++;
		i++;
		cc++;
	}

	//Если цифр нечетное количество и меньше 4, то исключение
	if (count % 2 != 0 && count < 4)
	{
		throw "Error";
	}

	double* mass = new double[count]; //Создаем массив, куда запишем цифры из чар*

	std::string temp = "";

	//Проходим по чар* и заполняем массив
	i = 0;
	for (int q = 0; q < cc; q++)
	{
		if (s[q] != ' ' && s[q] != ',')
			temp += s[q];
		else if (temp != "")
		{
			mass[j] = atoi(temp.c_str());
			j++;
			temp = "";
		}
	}
	mass[j] = atoi(temp.c_str()); //Последняя цифра из чар*

	TPoint *a = new TPoint(mass[0], mass[1]);
	TPoint *b = new TPoint(mass[2], mass[3]);

	left = a;
	right = b;
	//TPlex("12 23, 34 45, 56 67");
	for (int q = 4; q < count; q++)
	{
		TPoint *temp_left = new TPoint(mass[q-2], mass[q-1]);
		TPoint *temp_right = new TPoint(mass[q], mass[q + 1]);

		this->AddLine(temp_left, temp_right);
		q++;
	}
}

TPlex::TPlex(TPoint* a, TPoint* b) 
{
	if (a != NULL)
		left = a;

	if (b != NULL)
		right = b;
}

TPlex::TPlex(const TPlex& p) 
{
	left = p.left->Clone();
	right = p.right->Clone();
}

void TPlex::Print()
{
	PrintAll(0);
};

TBase* TPlex::PrintAll(TBase* p)
{
	TBase* p1 = left->PrintAll(0);
	TBase* p2 = right->PrintAll(0);
	std::cout << "Plex: " << std::endl;
	p1->Print();
	p2->Print();
	std::cout << std::endl;
	return p2;
}

double TPlex::GetVal(int i) {
	throw - 1;
}

void TPlex::SetVal(double val, int i) {
	throw - 1;
}

double& TPlex::operator[](char* name) {
	throw - 1;
}

double& TPlex::operator[](int i) {
	throw - 1;
}

TBase* TPlex::GetChild(int i) {
	if (i == 0)
		return left;
	else if (i == 1)
		return right;
	else
		throw - 1;
}

void TPlex::SetChild(TBase* c, int i)
{
	if (i == 0)
		left = c;
	else if (i == 1)
		right = c;
	else
		throw - 1;
}

TBase* TPlex::GetLeft()
{
	return left;
}
TBase* TPlex::GetRight()
{
	return right;
}

TPlex* TPlex::GetLeftPlex()
{
	return dynamic_cast<TPlex*>(left);
}
TPlex* TPlex::GetRightPlex()
{
	return dynamic_cast<TPlex*>(right);
}

void TPlex::SetLeft(TBase* x)
{
	left = x;
}
void TPlex::SetRight(TBase* x)
{
	right = x;
}
bool TPlex::AddLine(TPoint* a, TPoint* b)
{
	TPlex* l = GetLeftPlex();
	bool isAdd = false;
	if (l != 0)
		isAdd = l->AddLine(a, b);
	else
	{
		if (left == a)
		{
			left = new TPlex(b, a);
			return true;
		}
	}
	if (isAdd)
		return isAdd;

	TPlex* r = GetLeftPlex();
	if (r != 0)
		isAdd = r->AddLine(a, b);
	else
	{
		if (right->GetVal(0) == a->GetX0() && right->GetVal(1) == a->GetX1())
		{
			right = new TPlex(b, a);
			return true;
		}
	}
	return isAdd;
}

TBase* TPlex::Clone()
{
	return new TPlex(*this);
}
