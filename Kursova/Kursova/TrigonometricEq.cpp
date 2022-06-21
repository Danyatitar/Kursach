#include "MyForm.h";
#include <vector>
#include<algorithm>
#include "TrigonometricEq.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
TrigonometricEq::TrigonometricEq(double x, double y, double e, std::vector <double> items) {
	this->x = x;
	this->y = y;
	this->e = e;
	this->items = items;
	this->n = 0;
}

std::vector <double> TrigonometricEq::Newton() {
	/*ja - матриц€ якоб≥
	dx,dy-прирости зм≥нних дл€ х та у в≥дпов≥дно
	matrix-масив функц≥й
	det - визначник
	norm-число, €ке проходить перев≥рку на точн≥сть(норма)	
	results - вектор з пром≥жними результатами
	i - л≥чильник
	*/
	double  ja[2][2], dx, dy, matrix[2], matrix1[2], norm, det;
	int i = 1;
	std::vector <double> results;
		do
		{
			matrix1[0] = (this->items[0] * Math::Cos(this->items[1] * this->x + this->items[2] * this->y) + this->items[3] * this->y - this->items[4]);
			matrix1[1] = (this->items[5] * Math::Sin(this->items[6] * this->y - 2) + this->items[7] * this->x - this->items[8]);
			ja[0][0] = this->items[0] * this->items[1] * (-Math::Sin(this->items[1] * this->x + this->items[2] * this->y));
			ja[0][1] = this->items[0] * this->items[2] * (-Math::Sin(this->items[1] * this->x + this->items[2] * this->y)) + this->items[3];
			ja[1][0] =  this->items[7];
			ja[1][1] = this->items[5] * this->items[6] * Math::Cos(this->items[6] * this->y - 2);
			det = ja[0][0] * ja[1][1] - ja[0][1] * ja[1][0];
			if (det == 0) {
				results.push_back(-2);
				break;
			}
			oberMatrixN(ja, det);
			dx = -ja[0][0] * matrix1[0] + -ja[0][1] * matrix1[1];
			dy = -ja[1][0] * matrix1[0] + -ja[1][1] * matrix1[1];
			this->x = this->x + dx;
			this->y = this->y + dy;
			if (dx / this->x > this->e && dy / this->y > this->e) {
				results.push_back(-1);
				break;
			}
			matrix[0] = (this->items[0] * Math::Cos(this->items[1] * this->x + this->items[2] * this->y) + this->items[3] * this->y - this->items[4]);
			matrix[1] = (this->items[5] * Math::Sin(this->items[6] * this->y - 2) + this->items[7] * this->x - this->items[8]);
			norm = Math::Sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1]);
			results.push_back(x);
			results.push_back(y);
			i++;
			this->n++;
		} while (norm >= this->e);

	return results;
}
std::vector <double> TrigonometricEq::Broyden() {
	/*ja - матриц€ якоб≥
dx,dy-прирости зм≥нних дл€ х та у в≥дпов≥дно
matrix-масив функц≥й
det - визначник
norm-число, €ке проходить перев≥рку на точн≥сть(норма)
newJa - обернена матриц€ якоб≥
s0 - модуль вектора наближенн€ в квадрат≥
	results - вектор з пром≥жними результатами
	i - л≥чильник
	da-масив поправок дл€ матриц≥ якоб≥
	y0 - допом≥жна величина
*/
	double newJa[2][2], ja[2][2], dx, dy, matrix[2], matrix1[2], norm, det, s0, y0[2], da[2][2];
	int i = 1;
	std::vector <double> results;
	const double e = 0.01;
	ja[0][0] = this->items[0] * this->items[1] * (-Math::Sin(this->items[1] * this->x + this->items[2] * this->y));
	ja[0][1] = this->items[0] * this->items[2] * (-Math::Sin(this->items[1] * this->x + this->items[2] * this->y)) + this->items[3];
	ja[1][0] = this->items[7];
	ja[1][1] = this->items[5] * this->items[6] * Math::Cos(this->items[6] * this->y - 2);
		do
		{
			matrix1[0] = (this->items[0] * Math::Cos(this->items[1] * this->x + this->items[2] * this->y) + this->items[3] * this->y - this->items[4]);
			matrix1[1] = (this->items[5] * Math::Sin(this->items[6] * this->y - 2) + this->items[7] * this->x - this->items[8]);
			det = ja[0][0] *ja[1][1] - ja[0][1] * ja[1][0];
			if (det == 0) {
				results.push_back(-2);
				break;
			}
			else {
				oberMatrixB(ja, newJa, det);
				dx = -newJa[0][0] * matrix1[0] + -newJa[0][1] * matrix1[1];
				dy = -newJa[1][0] * matrix1[0] + -newJa[1][1] * matrix1[1];

				this->x = this->x + dx;
				this->y = this->y + dy;
				if ((dx / this->x) > e && (dy / this->y) > e) {
					results.push_back(-1);
					break;
				}
				matrix[0] = (this->items[0] * Math::Cos(this->items[1] * this->x + this->items[2] * this->y) + this->items[3] * this->y - this->items[4]);
				matrix[1] = (this->items[5] * Math::Sin(this->items[6] * this->y - 2) + this->items[7] * this->x  - this->items[8]);
				y0[0] = matrix[0] - matrix1[0];
				y0[1] = matrix[1] - matrix1[1];
				s0 = dx * dx + dy * dy;
				y0[0] = y0[0] - ja[0][0] * dx - ja[1][0] * dy;
				y0[1] = y0[1] - ja[1][0] * dx - ja[1][1] * dy;
				da[0][0] = y0[0] * dx;
				da[0][1] = y0[1] * dy;
				da[1][0] = y0[0] * dx;
				da[1][1] = y0[1] * dy;
				ja[0][0] = ja[0][0] + da[0][0] / s0;
				ja[0][1] = ja[0][1] + da[0][1] / s0;
				ja[1][0] = ja[1][0] + da[1][0] / s0;
				ja[1][1] = ja[1][1] + da[1][1] / s0;
				norm = Math::Sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1]);
				results.push_back(x);
				results.push_back(y);
				i++;
				this->n++;
			}

		} while (norm >= this->e);


	return results;
}