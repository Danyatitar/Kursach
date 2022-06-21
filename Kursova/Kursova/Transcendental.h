#pragma once
// Клас для вирішення систем трансцендентного виду
#include "MyForm.h";
#include <vector>
#include "Equations.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
class TranscendentalEq : public Equations {
public:
	TranscendentalEq(double x, double y, double e, std::vector <double> items); //конструктор класу
	std::vector <double> Newton();//Рішення системи методом Ньютона
	std::vector <double> Broyden();//Рішення системи методом Ньютона
};