#include "MyForm.h";
#include <vector>
#include "ArithmeticEq.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
ArithmeticEq::ArithmeticEq(double x, double y, double e, std::vector <double> items) {
	this->x = x;
	this->y = y;
	this->e = e;
	this->items = items;
	this->n = 0;
}

std::vector <double> ArithmeticEq::Newton() {
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
			matrix1[0] = (this->items[1] * this->y * this->y + this->items[0] * this->x * this->x - this->items[2]);
			matrix1[1] = (this->items[3] * this->x + this->items[4] * this->x * this->y * this->y * this->y - this->items[5]);
			ja[0][0] = 2 * this->items[0] * this->x;
			ja[0][1] = 2 * this->items[1] * this->y;
			ja[1][0] = this->items[3] + this->items[4] * this->y * this->y * this->y;
			ja[1][1] = 3 * this->items[4] * this->x * this->y * this->y;
			det = ja[0][0] * ja[1][1] - ja[0][1] * ja[1][0];
			if (det == 0) {
				results.push_back(-2);
				break;
			}
			oberMatrixN(ja, det);
			dx = -ja[0][0] * matrix1[0] + -ja[0][1] * matrix1[1];
			dy = -ja[1][0] * matrix1[0] + -ja[1][1] * matrix1[1];
			/**/if ((dx / this->x) > this->e && (dy / this->y) > this->e) {
				results.push_back(-1);
				break;
			}
			this->x = this->x + dx;
			this->y = this->y + dy;

			matrix[0] = (this->items[1] * this->y * this->y + this->items[0] * this->x * this->x - this->items[2]);
			matrix[1] = (this->items[3] * this->x + this->items[4] * this->x * this->y * this->y * this->y - this->items[5]);
			norm = Math::Sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1]);
			results.push_back(x);
			results.push_back(y);
			i++;
			this->n++;
		} while (norm >= this->e);
	
	return results;
}
std::vector <double> ArithmeticEq::Broyden() {
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
	double newJa[2][2], ja[2][2], dx, dy, matrix[2], matrix1[2], norm, det, aa, s0, y0[2], da[2][2];
	int i = 1;
	const double e = 0.01;
	std::vector <double> results;
		ja[0][0] = 2 * this->items[0] * this->x;
		ja[0][1] = 2 * this->items[1] * this->y;
		ja[1][0] = this->items[3] + this->items[4] * this->y * this->y * this->y;
		ja[1][1] = 3 * this->items[4] * this->x * this->y * this->y;
		do
		{
			matrix1[0] = (this->items[1] * this->y * this->y + this->items[0] * this->x * this->x - this->items[2]);
			matrix1[1] = (this->items[3] * this->x + this->items[4] * this->x * this->y * this->y * this->y - this->items[5]);

			det = ja[0][0] * ja[1][1] - ja[0][1] * ja[1][0];
			if (det == 0) {
				results.push_back(-2);
				break;
			}
			else {
				oberMatrixB(ja,newJa, det);
				dx = -newJa[0][0] * matrix1[0] - newJa[0][1] * matrix1[1];
				dy = -newJa[1][0] * matrix1[0] - newJa[1][1] * matrix1[1];
				if ((dx / this->x) > e && (dy / this->y) > e) {
					results.push_back(-1);
					break;
				}
				this->x = this->x + dx;
				this->y = this->y + dy;
				matrix[0] = (this->items[1] * this->y * this->y + this->items[0] * this->x * this->x - this->items[2]);
				matrix[1] = (this->items[3] * this->x + this->items[4] * this->x * this->y * this->y * this->y - this->items[5]);
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

		} while (norm >= this->e );
	
	
	return results;
}
/*bool ArithmeticEq::Convergence() {
	double a[2][2], b1[2],b[2],h[2][4];
	a[0][0] = 2 * this->items[1] * this->x;
	a[0][1] = 2 * this->items[0] * this->y;
	a[1][0] = this->items[3] + this->items[4] * this->y * this->y * this->y;
	a[1][1] = 3 * this->items[4] * this->x * this->y * this->y;
	double A = sqrt(a[0][0]*a[0][0]+ a[0][1] * a[0][1]+ a[1][0] * a[1][0]+ a[1][1] * a[1][1]);
	b1[0] = (this->items[0] * this->y * this->y + this->items[1] * this->x * this->x - this->items[2]);
	b1[1] = (this->items[3] * this->x + this->items[4] * this->x * this->y * this->y * this->y - this->items[5]);
	b[0] = -a[0][0] * b1[0] + -a[0][1] * b1[1];
	b[1] = -a[1][0] * b1[0] + -a[1][1] * b1[1];
	double B= sqrt(b[0] * b[0] + b[1] * b[1]);
	h[0][0] = 2 * this->items[1];
	h[0][1] = 0;
	h[0][2] = 2 * this->items[0];
	h[0][3] = 0;
	h[1][0] = 0;
	h[1][1] = 3*this->items[4] * this->y * this->y;
	h[1][2] = 3 * this->items[4] * this->y * this->y;
	h[1][3] = 6 * this->items[4] * this->x * this->y;
}*/
