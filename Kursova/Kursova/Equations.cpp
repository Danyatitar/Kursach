#include "Equations.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
double Equations::getX() {
	return x;
}
double Equations::getY() {
	return y;
}
double Equations::getIterations() {
	return n;
}
void Equations::oberMatrixN(double a[2][2], double det) {
	double aa = a[0][0];
	a[0][0] = a[1][1] / det;
	a[1][1] = aa / det;
	a[0][1] = -a[0][1] / det;
	a[1][0] = -a[1][0] / det;
}
void Equations::oberMatrixB(double a0[2][2], double a[2][2], double det) {
	a[0][0] = a0[1][1] / det;
	a[1][1] = a0[0][0] / det;
	a[0][1] = -a0[0][1] / det;
	a[1][0] = -a0[1][0] / det;
}