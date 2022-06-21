#include "MyForm.h"
#include <vector>
#include<math.h>
#include "ArithmeticEq.h"
#include "Transcendental.h"
#include "TrigonometricEq.h"
#include <fstream>
using namespace System::Windows::Forms;
using namespace System;
[STAThreadAttribute]
void main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Calculator::MyForm form;
	Application::Run(% form);
}

System::Void Calculator::MyForm::choose_Click(System::Object^ sender, System::EventArgs^ e) {
	textboxes.Add(item1);// textboxes - список із введеними коефіцієнтами
	textboxes.Add(item2);
	textboxes.Add(item3);
	textboxes.Add(item4);
	textboxes.Add(item5);
	textboxes.Add(item6);
	textboxes.Add(item7);
	textboxes.Add(item8);
	textboxes.Add(item9);

	if (templates->SelectedIndex == 0) {
		label12->Text = "";
		label13->Text = "";
		label11->Text = "";
		this->Controls->Remove(this->item8);
		this->Controls->Remove(this->item7);
		this->Controls->Remove(this->item9);
		pictureBox1->Image = Image::FromFile(L"C:\\Users\\Danylo\\Desktop\\picture1.png");

	}
	else if (templates->SelectedIndex == 1) {
		this->Controls->Add(this->item8);
		this->Controls->Add(this->item7);
		this->Controls->Add(this->item9);
		label12->Text = "k6=";
		label11->Text = "k7=";
		label13->Text = "k8=";
		pictureBox1->Image = Image::FromFile(L"C:\\Users\\Danylo\\Desktop\\picture2.png");
	}
	else if (templates->SelectedIndex == 2) {
		this->Controls->Add(this->item8);
		this->Controls->Add(this->item7);
		this->Controls->Add(this->item9);
		label12->Text = "k6=";
		label11->Text = "k7=";
		label13->Text = "k8=";
		pictureBox1->Image = Image::FromFile(L"C:\\Users\\Danylo\\Desktop\\picture3.png");
	}
	else {
		MessageBox::Show("Оберіть вид рівняння", "Помилка");
	}
}
System::Void Calculator::MyForm::submit_Click(System::Object^ sender, System::EventArgs^ e) {
	List<String^> items;// Коефіцієнт рівняння, який буде конвертований у дійсне число
	double item;
	bool parsedAll = false;// умова введення всіх коефіцієнтів правильно
	if (templates->SelectedIndex == 0) {
		bool parsed = true;
		for (int i = 0; i < 6; i++) {
			if (!Double::TryParse(Convert::ToString(textboxes[i]->Text), item)) {
				MessageBox::Show("Введіть дійсне число", "Помилка");
				parsed = false;
				break;
			}
			else {
				if (items.Count >= i + 1) {
					items[i] = textboxes[i]->Text;
				}
				else {
					items.Add(textboxes[i]->Text);
				}
			}
		}
		if (parsed) {
			label15->Text = items[0] + "X^2+" + items[1] + "Y^2=" + items[2];
			label16->Text = items[3] + "X+" + items[4] + "Y^3*X=" + items[5];
			parsedAll = true;
		}

	}
	else if (templates->SelectedIndex == 1) {
		bool parsed = true;
		for (int i = 0; i < 9; i++) {
			if (!Double::TryParse(Convert::ToString(textboxes[i]->Text), item)) {
				MessageBox::Show("Введіть дійсне число", "Помилка");
				parsed = false;
				break;
			}
			else {

				if (items.Count >= i + 1) {
					items[i] = textboxes[i]->Text;
				}
				else {
					items.Add(textboxes[i]->Text);
				}
			}
		}
		if (parsed) {
			label15->Text = items[0] + "cos(" + items[1] + "X+" + items[2] + "Y)+" + items[3] + "Y=" + items[4];
			label16->Text = items[5] + "sin(" + items[6] + "Y-2)+" + items[7] + "X=" + items[8];
			parsedAll = true;
		}
	}
	else if(templates->SelectedIndex == 2){
		bool parsed = true;
		for (int i = 0; i < 9; i++) {
			if (!Double::TryParse(Convert::ToString(textboxes[i]->Text), item)) {
				MessageBox::Show("Введіть дійсне число", "Помилка");
				parsed = false;
				break;
			}
			else {
				if (items.Count >= i + 1) {
					items[i] = textboxes[i]->Text;
				}
				else {
					items.Add(textboxes[i]->Text);
				}
			}
		}
		if (parsed) {
			label15->Text = items[0] + "log(" + items[1] + "X+5)+" + items[2] + "Y=" + items[3];
			label16->Text = items[4] + "log(" + items[5] + "Y-2)+" + items[6] + "log10(" + items[7] + "X)=" + items[8];
			parsedAll = true;
		}
	}
	else {
		MessageBox::Show("Оберіть вид рівняння", "Помилка");
	}
	if (parsedAll) {
		addComponents(sender, e);
	}
}
System::Void  Calculator::MyForm::Calculate_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Controls->Add(this->results);
	this->results->Text = "";
	double x, y, E;// вектор початкового наближення та точність
	bool parsed = true;// умова коректності введення даних
	if (!Double::TryParse(Convert::ToString(firstX->Text), x)) {
		MessageBox::Show("Введіть дійсне число", "Помилка");
		parsed = false;

	}
	else {
		x = Convert::ToDouble(firstX->Text);
	}
	if (!Double::TryParse(Convert::ToString(firstY->Text), y)) {
		MessageBox::Show("Введіть дійсне число", "Помилка");
		parsed = false;
	}
	else {
		y = Convert::ToDouble(firstY->Text);
	}
	if (!Double::TryParse(Convert::ToString(accuracy->Text), E)) {
		MessageBox::Show("Введіть дійсне число", "Помилка");
		parsed = false;
	}
	else {
		E = Convert::ToDouble(accuracy->Text);
	}
	if (templates->SelectedIndex == 0) {
		std::vector <double> items;// коефіцієнти рівняння
		for (int i = 0; i <=5; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		if (parsed) {
			ArithmeticEq* equation = new ArithmeticEq(x, y, E, items);
			std::vector <double> results;// розв'язок системи
			if (Newton->Checked == true) {
				 results= equation->Newton();
			}
			else {
			 results = equation->Broyden();
			}
			
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					this->results->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					this->results->Text += "Ітераційний процес розбіжний\n";
					this->results->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					this->results->Text += "Матриця Якобі невироджена\n";
					this->results->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {
				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					this->results->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n\n";
					j++;
				}
				this->results->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}

		}
		this->Controls->Add(this->toFile);
	}
	else if (templates->SelectedIndex == 1) {
		std::vector <double> items;// коефіцієнти рівняння
		for (int i = 0; i < 9; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		if (parsed) {

			TrigonometricEq* equation = new TrigonometricEq(x, y, E, items);
			std::vector <double> results;// розв'язок системи
			if (Newton->Checked == true) {
				results = equation->Newton();
			}
			else {
				results = equation->Broyden();
			}
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					this->results->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					this->results->Text += "Ітераційний процес розбіжний\n";
					this->results->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					this->results->Text += "Матриця Якобі невироджена\n";
					this->results->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {
				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					this->results->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				this->results->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}


		}
		this->Controls->Add(this->toFile);
	}
	else {
	
		this->Controls->Add(this->toFile);
		std::vector <double> items;// коефіцієнти рівняння
		for (int i = 0; i < 9; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}	
		if ((items[7]*x) <= 0 || (y* items[5]-2) <= 0   || (x*items[1]+5) <= 0) {
			MessageBox::Show("Число не входить в ОДЗ логарифма", "Помилка");
		}
		else {
			if (parsed) {
				TranscendentalEq* equation = new TranscendentalEq(x, y, E, items);
				std::vector <double> results;// розв'язок системи
				if (Newton->Checked == true) {
					results = equation->Newton();
				}
				else {
					results = equation->Broyden();
				}
				if (results.size() % 2 == 1) {
					int j = 1;;
					for (int i = 0; i < results.size() - 1; i = i + 2) {
						this->results->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
						j++;
					}
					if (results[results.size() - 1] == -1) {
						this->results->Text += "Ітераційний процес розбіжний\n";
						this->results->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
					}
					else if (results[results.size() - 1] == -2) {
						this->results->Text += "Матриця Якобі невироджена\n";
						this->results->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
					}
					else if (results[results.size() - 1] == -3) {
						this->results->Text += "Наступне значення x або у не входить в ОДЗ\n";
						this->results->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
					}
				}
				else {

					int j = 1;;
					for (int i = 0; i < results.size(); i = i + 2) {
						this->results->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
						j++;

					}
					this->results->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
				}


			}
		}
		
		
	}
	
}
System::Void Calculator::MyForm::addComponents(System::Object^ sender, System::EventArgs^ e) {
	label17->Text = "Введіть точність та вектор початкового наближення";
	label19->Text = "X0=";
	label20->Text = "Y0=";
	label21->Text = "E=";
	this->Controls->Add(firstX);

	firstX->Location = System::Drawing::Point(55, 315);
	firstX->Size = System::Drawing::Size(38, 18);
	this->Controls->Add(firstY);
	firstY->Location = System::Drawing::Point(225, 315);
	firstY->Size = System::Drawing::Size(38, 18);
	this->Controls->Add(accuracy);
	accuracy->Location = System::Drawing::Point(420, 315);
	accuracy->Size = System::Drawing::Size(38, 40);
	this->Controls->Add(Calculate);
	this->Controls->Add(this->Methods);
	label24->Text = "Оберіть метод розв'язання";
}
System::Void Calculator::MyForm::toFile_Click(System::Object^ sender, System::EventArgs^ e) {
	System::IO::StreamWriter^ fp = gcnew System::IO::StreamWriter("Solve.txt");// файл з результатами виконання програми
	fp->Write("Система\n");
	fp->Write(label15->Text + "\n");
	fp->Write(label16->Text + "\n\n");
	fp->Write("Розв'язок: \n");
	fp->Write(results->Text + "\n\n");
	fp->Close();
}

/*System::Void Kursova::MyForm::Newton_Click(System::Object^ sender, System::EventArgs^ e) {
	label23->Text = "";
	if (comboBox1->SelectedIndex == 0) {
		std::vector <double> items;
		bool parsed = true;
		for (int i = 0; i < 6; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		double x, y, e;
		if (!Double::TryParse(Convert::ToString(textBox10->Text), x)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;

		}
		else {
			x = Convert::ToDouble(textBox10->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox11->Text), y)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			y = Convert::ToDouble(textBox11->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox12->Text), e)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			e = Convert::ToDouble(textBox12->Text);
		}
		if (parsed) {

			ArithmeticEq* equation = new ArithmeticEq(x, y, e, items);
			std::vector <double> results = equation->Newton();
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					label23->Text += "Ітераційний процес розбіжний\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					label23->Text += "Матриця Якобі невироджена\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {
				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				label23->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}

		}
	}
	else if (comboBox1->SelectedIndex == 1) {
		std::vector <double> items;
		bool parsed = true;
		for (int i = 0; i < 9; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		double x, y, e;
		if (!Double::TryParse(Convert::ToString(textBox10->Text), x)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;

		}
		else {
			x = Convert::ToDouble(textBox10->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox11->Text), y)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			y = Convert::ToDouble(textBox11->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox12->Text), e)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			e = Convert::ToDouble(textBox12->Text);
		}
		if (parsed) {

			TrigonometricEq* equation = new TrigonometricEq(x, y, e, items);
			std::vector <double> results = equation->Newton();
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					label23->Text += "Ітераційний процес розбіжний\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					label23->Text += "Матриця Якобі невироджена\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {
				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				label23->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}


		}
	}
	else {
		std::vector <double> items;
		bool parsed = true;
		for (int i = 0; i < 9; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		double x, y, e;
		if (!Double::TryParse(Convert::ToString(textBox10->Text), x)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;

		}
		else {
			x = Convert::ToDouble(textBox10->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox11->Text), y)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			y = Convert::ToDouble(textBox11->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox12->Text), e)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			e = Convert::ToDouble(textBox12->Text);
		}
		if (parsed) {
			bool odz = true;
			TranscendentalEq* equation = new TranscendentalEq(x, y, e, items);
			std::vector <double> results = equation->Newton();
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					label23->Text += "Ітераційний процес розбіжний\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					label23->Text += "Матриця Якобі невироджена\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -3) {
					label23->Text += "Наступне значення x або у не входить в ОДЗ\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {

				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;

				}
				label23->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}


		}
	}
}
System::Void Kursova::MyForm::Secant_Click(System::Object^ sender, System::EventArgs^ e) {
	label23->Text = "";
	if (comboBox1->SelectedIndex == 0) {
		std::vector <double> items;
		bool parsed = true;
		for (int i = 0; i < 6; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		double x, y, e;
		if (!Double::TryParse(Convert::ToString(textBox10->Text), x)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;

		}
		else {
			x = Convert::ToDouble(textBox10->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox11->Text), y)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			y = Convert::ToDouble(textBox11->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox12->Text), e)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			e = Convert::ToDouble(textBox12->Text);
		}
		if (parsed) {

			ArithmeticEq* equation = new ArithmeticEq(x, y, e, items);
			std::vector <double> results = equation->Broyden();
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					label23->Text += "Ітераційний процес розбіжний\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					label23->Text += "Матриця Якобі невироджена\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {
				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				label23->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}


		}
	}
	else if (comboBox1->SelectedIndex == 1) {
		std::vector <double> items;
		bool parsed = true;
		for (int i = 0; i < 9; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		double x, y, e;
		if (!Double::TryParse(Convert::ToString(textBox10->Text), x)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;

		}
		else {
			x = Convert::ToDouble(textBox10->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox11->Text), y)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			y = Convert::ToDouble(textBox11->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox12->Text), e)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			e = Convert::ToDouble(textBox12->Text);
		}
		if (parsed) {

			TrigonometricEq* equation = new TrigonometricEq(x, y, e, items);
			std::vector <double> results = equation->Broyden();
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					label23->Text += "Ітераційний процес розбіжний\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					label23->Text += "Матриця Якобі невироджена\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {
				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				label23->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}


		}
	}
	else {
		std::vector <double> items;
		bool parsed = true;
		for (int i = 0; i < 9; i++) {
			items.push_back(Convert::ToDouble(textboxes[i]->Text));
		}
		double x, y, e;
		if (!Double::TryParse(Convert::ToString(textBox10->Text), x)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;

		}
		else {
			x = Convert::ToDouble(textBox10->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox11->Text), y)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			y = Convert::ToDouble(textBox11->Text);
		}
		if (!Double::TryParse(Convert::ToString(textBox12->Text), e)) {
			MessageBox::Show("Введіть дійсне число", "Помилка");
			parsed = false;
		}
		else {
			e = Convert::ToDouble(textBox12->Text);
		}
		if (parsed) {
			bool odz = true;
			TranscendentalEq* equation = new TranscendentalEq(x, y, e, items);
			std::vector <double> results = equation->Broyden();
			if (results.size() % 2 == 1) {
				int j = 1;;
				for (int i = 0; i < results.size() - 1; i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;
				}
				if (results[results.size() - 1] == -1) {
					label23->Text += "Ітераційний процес розбіжний\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -2) {
					label23->Text += "Матриця Якобі невироджена\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
				else if (results[results.size() - 1] == -3) {
					label23->Text += "Наступне значення x або у не входить в ОДЗ\n";
					label23->Text += "\n\nВідповідь: розв'язків немає спробуйте обрати інший вектор початкового наближення";
				}
			}
			else {
				int j = 1;;
				for (int i = 0; i < results.size(); i = i + 2) {
					label23->Text += "ітерація " + j + ": x=" + results[i] + "    y=" + results[i + 1] + "\n";
					j++;

				}
				label23->Text += "\n\nВідповідь: x=" + equation->getX() + "    y=" + equation->getY() + "  за " + equation->getIterations() + "  ітерацій";
			}


		}
	}
}*/
