#pragma once
#include "TPlex.h"

class TCanvas {
protected:
	std::vector<TBase*> mas;

public:
	TCanvas();
	void Print();
	void AddObj(TBase* a);
};

TCanvas::TCanvas() {

}

void TCanvas::Print()
{
	for (int i = 0; i < mas.size(); i++)
	{
		mas[i]->Print();
		std::cout << "\n\n";
	}
}

void TCanvas::AddObj(TBase* a)
{
	mas.push_back(a);
}