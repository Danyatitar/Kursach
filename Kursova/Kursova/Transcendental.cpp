#include "MyForm.h";
#include <vector>
#include "Transcendental.h"
#include<math.h>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
TranscendentalEq::TranscendentalEq(double x, double y, double e, std::vector <double> items) {
	this->x = x;
	this->y = y;
	this->e = e;
	this->items = items;
	this->n = 0;
}
std::vector <double> TranscendentalEq::Newton() {
	double  ja[2][2], dx, dy, matrix[2], matrix1[2], norm, det;
	int i = 1;
	const double e = 0.001;
	std::vector <double> results;
		do
		{
			matrix1[0] = this->items[0] * Math::Log(this->items[1] * this->x + 5) + this->items[2] * this->y - this->items[3];
			matrix1[1] = this->items[4] * Math::Log(this->items[5] * this->y - 2) + this->items[6] * Math::Log10(this->items[7] * this->x) - this->items[8];
			ja[0][0] = (this->items[0] * this->items[1]) / (this->items[1] * this->x + 5);
			ja[0][1] = this->items[2];
			ja[1][0] = (this->items[6] * this->items[7]) / (this->items[7] * this->x * Math::Log(10));
			ja[1][1] = (this->items[4] * this->items[5]) / (this->items[5] * this->y - 2);
			det = ja[0][0] * ja[1][1] - ja[0][1] * ja[1][0];
			if (det == 0) {
				results.push_back(-2);
				break;
			}
			oberMatrixN(ja, det);
			dx = -ja[0][0] * matrix1[0] + -ja[0][1] * matrix1[1];
			dy = -ja[1][0] * matrix1[0] + -ja[1][1] * matrix1[1];
			if (dx / this->x > e && dy / this->y > e) {
				results.push_back(-1);
				break;
			}
			this->x = this->x + dx;
			this->y = this->y + dy;
			matrix[0] = this->items[0] * Math::Log(this->items[1] * this->x + 5) + this->items[2] * this->y - this->items[3];
			matrix[1] = this->items[4] * Math::Log(this->items[5] * this->y - 2) + this->items[6] * Math::Log10(this->items[7] * this->x) - this->items[8];
			norm = Math::Sqrt(matrix[0] * matrix[0] + matrix[1] * matrix[1]);
			results.push_back(x);
			results.push_back(y);
			i++;
			this->n++;
			if (x <= 0 || (y * items[5] - 2) <= 0 || (x * items[1] + 5) <= 0) {
				results.push_back(-3);
				break;
			}
		} while (norm >= this->e);

	return results;
}
std::vector <double> TranscendentalEq::Broyden() {
	/*ja - ������� ����
dx,dy-�������� ������ ��� � �� � ��������
matrix-����� �������
det - ���������
norm-�����, ��� ��������� �������� �� �������(�����)
newJa - �������� ������� ����
s0 - ������ ������� ���������� � �������
	results - ������ � ��������� ������������
	i - ��������
	da-����� �������� ��� ������� ����
	y0 - �������� ��������
*/
	double newJa[2][2], ja[2][2], dx, dy, matrix[2], matrix1[2], norm, det, aa, s0, y0[2], da[2][2];
	int i = 1;
	std::vector <double> results;
		ja[0][0] = (this->items[0] * this->items[1]) / (this->items[1] * this->x + 5);
		ja[0][1] = this->items[2];
		ja[1][0] = (this->items[6] * this->items[7]) / (this->items[7] * this->x * Math::Log(10));
		ja[1][1] = (this->items[4] * this->items[5]) / (this->items[5] * this->y - 2);
		do
		{
			matrix1[0] = this->items[0] * Math::Log(this->items[1] * this->x + 5) + this->items[2] * this->y - this->items[3];
			matrix1[1] = this->items[4] * Math::Log(this->items[5] * this->y - 2) + this->items[6] * Math::Log10(this->items[7] * this->x) - this->items[8];

			det = ja[0][0] * ja[1][1] - ja[0][1] * ja[1][0];
			if (det == 0) {
				results.push_back(-2);
				break;
			}
			else {
				oberMatrixB(ja, newJa, det);
				dx = -newJa[0][0] * matrix1[0] - newJa[0][1] * matrix1[1];
				dy = -newJa[1][0] * matrix1[0] - newJa[1][1] * matrix1[1];
				if ((dx / this->x) > this->e && (dy / this->y) > this->e) {
					results.push_back(-1);
					break;
				}
				this->x = this->x + dx;
				this->y = this->y + dy;
				matrix[0] = this->items[0] * Math::Log(this->items[1] * this->x + 5) + this->items[2] * this->y - this->items[3];
				matrix[1] = this->items[4] * Math::Log(this->items[5] * this->y - 2) + this->items[6] * Math::Log10(this->items[7] * this->x) - this->items[8];
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
				if (x <= 0 || (y * items[5] - 2) <= 0 || (x * items[1] + 5) <= 0) {
					results.push_back(-3);
					break;
				}
			}

		} while (norm >= this->e);


	return results;
}