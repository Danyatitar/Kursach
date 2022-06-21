#pragma once
#include "MyForm.h";
#include <vector>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
class Equations {
protected:
	double x;
	double y;
	double e;
	int n;
	std::vector <double> items;
public:
	double getX();//‘ункц≥€ повертаЇ значенн€ X
	double getY();// ‘ункц≥€ повертаЇ значенн€ Y
	double getIterations();// ѕовертаЇ к-ть ≥терац≥й
	void oberMatrixN(double a[2][2], double det);// ќбернена матриц€ дл€ методу Ќьютона
	void oberMatrixB(double a0[2][2],double a[2][2], double det);// ќбернена матриц€ дл€ методу с≥чних
};