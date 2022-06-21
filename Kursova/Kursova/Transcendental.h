#pragma once
// ���� ��� �������� ������ ���������������� ����
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
	TranscendentalEq(double x, double y, double e, std::vector <double> items); //����������� �����
	std::vector <double> Newton();//г����� ������� ������� �������
	std::vector <double> Broyden();//г����� ������� ������� �������
};