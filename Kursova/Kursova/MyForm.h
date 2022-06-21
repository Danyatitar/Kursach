#pragma once

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		List<TextBox^> textboxes;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ templates;
	private: System::Windows::Forms::Button^ choose;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ submit;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ item1;
	private: System::Windows::Forms::TextBox^ item2;
	private: System::Windows::Forms::TextBox^ item3;
	private: System::Windows::Forms::TextBox^ item7;
	private: System::Windows::Forms::TextBox^ item6;
	private: System::Windows::Forms::TextBox^ item5;
	private: System::Windows::Forms::TextBox^ item4;
	private: System::Windows::Forms::TextBox^ item8;
	private: System::Windows::Forms::TextBox^ accuracy;
	private: System::Windows::Forms::TextBox^ firstY;
	private: System::Windows::Forms::TextBox^ firstX;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ item9;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::GroupBox^ Methods;
	private: System::Windows::Forms::RadioButton^ Secant;
	private: System::Windows::Forms::RadioButton^ Newton;
	private: System::Windows::Forms::Button^ Calculate;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Button^ toFile;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::RichTextBox^ results;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->templates = (gcnew System::Windows::Forms::ComboBox());
			this->choose = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->item1 = (gcnew System::Windows::Forms::TextBox());
			this->item2 = (gcnew System::Windows::Forms::TextBox());
			this->item3 = (gcnew System::Windows::Forms::TextBox());
			this->item7 = (gcnew System::Windows::Forms::TextBox());
			this->item6 = (gcnew System::Windows::Forms::TextBox());
			this->item5 = (gcnew System::Windows::Forms::TextBox());
			this->item4 = (gcnew System::Windows::Forms::TextBox());
			this->item8 = (gcnew System::Windows::Forms::TextBox());
			this->accuracy = (gcnew System::Windows::Forms::TextBox());
			this->firstY = (gcnew System::Windows::Forms::TextBox());
			this->firstX = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->item9 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->Methods = (gcnew System::Windows::Forms::GroupBox());
			this->Secant = (gcnew System::Windows::Forms::RadioButton());
			this->Newton = (gcnew System::Windows::Forms::RadioButton());
			this->Calculate = (gcnew System::Windows::Forms::Button());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->toFile = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->results = (gcnew System::Windows::Forms::RichTextBox());
			this->Methods->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label1->Location = System::Drawing::Point(18, 35);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(420, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Виберіть вид системи нелінійних рівнянь розмірності 2х2\r\n\r\n";
			// 
			// templates
			// 
			this->templates->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->templates->FormattingEnabled = true;
			this->templates->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"алгебраїчний", L"тригонометричний ", L"трансцендентний" });
			this->templates->Location = System::Drawing::Point(453, 32);
			this->templates->Margin = System::Windows::Forms::Padding(2);
			this->templates->Name = L"templates";
			this->templates->Size = System::Drawing::Size(191, 26);
			this->templates->TabIndex = 1;
			this->templates->Text = L"Вид системи";
			// 
			// choose
			// 
			this->choose->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->choose->Location = System::Drawing::Point(663, 30);
			this->choose->Margin = System::Windows::Forms::Padding(2);
			this->choose->Name = L"choose";
			this->choose->Size = System::Drawing::Size(94, 29);
			this->choose->TabIndex = 2;
			this->choose->Text = L"Вибрати";
			this->choose->UseVisualStyleBackColor = true;
			this->choose->Click += gcnew System::EventHandler(this, &MyForm::choose_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label2->Location = System::Drawing::Point(17, 70);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(298, 36);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Введіть коефіцієнти системи рівнянь ki\r\n\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label3->Location = System::Drawing::Point(1306, 453);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 18);
			this->label3->TabIndex = 10;
			// 
			// submit
			// 
			this->submit->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->submit->Location = System::Drawing::Point(144, 174);
			this->submit->Margin = System::Windows::Forms::Padding(2);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(134, 34);
			this->submit->TabIndex = 11;
			this->submit->Text = L"Застосувати\r\n";
			this->submit->UseVisualStyleBackColor = true;
			this->submit->Click += gcnew System::EventHandler(this, &MyForm::submit_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label4->Location = System::Drawing::Point(1306, 478);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 18);
			this->label4->TabIndex = 12;
			// 
			// item1
			// 
			this->item1->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item1->Location = System::Drawing::Point(61, 97);
			this->item1->Margin = System::Windows::Forms::Padding(2);
			this->item1->Name = L"item1";
			this->item1->Size = System::Drawing::Size(27, 26);
			this->item1->TabIndex = 13;
			// 
			// item2
			// 
			this->item2->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item2->Location = System::Drawing::Point(143, 97);
			this->item2->Margin = System::Windows::Forms::Padding(2);
			this->item2->Name = L"item2";
			this->item2->Size = System::Drawing::Size(27, 26);
			this->item2->TabIndex = 14;
			// 
			// item3
			// 
			this->item3->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item3->Location = System::Drawing::Point(226, 97);
			this->item3->Margin = System::Windows::Forms::Padding(2);
			this->item3->Name = L"item3";
			this->item3->Size = System::Drawing::Size(27, 26);
			this->item3->TabIndex = 15;
			// 
			// item7
			// 
			this->item7->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item7->Location = System::Drawing::Point(226, 127);
			this->item7->Margin = System::Windows::Forms::Padding(2);
			this->item7->Name = L"item7";
			this->item7->Size = System::Drawing::Size(27, 26);
			this->item7->TabIndex = 18;
			// 
			// item6
			// 
			this->item6->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item6->Location = System::Drawing::Point(143, 128);
			this->item6->Margin = System::Windows::Forms::Padding(2);
			this->item6->Name = L"item6";
			this->item6->Size = System::Drawing::Size(27, 26);
			this->item6->TabIndex = 17;
			// 
			// item5
			// 
			this->item5->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item5->Location = System::Drawing::Point(61, 129);
			this->item5->Margin = System::Windows::Forms::Padding(2);
			this->item5->Name = L"item5";
			this->item5->Size = System::Drawing::Size(27, 26);
			this->item5->TabIndex = 16;
			// 
			// item4
			// 
			this->item4->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item4->Location = System::Drawing::Point(316, 97);
			this->item4->Margin = System::Windows::Forms::Padding(2);
			this->item4->Name = L"item4";
			this->item4->Size = System::Drawing::Size(27, 26);
			this->item4->TabIndex = 19;
			// 
			// item8
			// 
			this->item8->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item8->Location = System::Drawing::Point(316, 127);
			this->item8->Margin = System::Windows::Forms::Padding(2);
			this->item8->Name = L"item8";
			this->item8->Size = System::Drawing::Size(27, 26);
			this->item8->TabIndex = 20;
			// 
			// accuracy
			// 
			this->accuracy->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->accuracy->Location = System::Drawing::Point(873, 149);
			this->accuracy->Name = L"accuracy";
			this->accuracy->Size = System::Drawing::Size(100, 26);
			this->accuracy->TabIndex = 0;
			// 
			// firstY
			// 
			this->firstY->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->firstY->Location = System::Drawing::Point(1034, 149);
			this->firstY->Name = L"firstY";
			this->firstY->Size = System::Drawing::Size(100, 26);
			this->firstY->TabIndex = 0;
			// 
			// firstX
			// 
			this->firstX->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->firstX->Location = System::Drawing::Point(1218, 149);
			this->firstX->Name = L"firstX";
			this->firstX->Size = System::Drawing::Size(100, 26);
			this->firstX->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label5->Location = System::Drawing::Point(20, 100);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 18);
			this->label5->TabIndex = 21;
			this->label5->Text = L"k0=";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label6->Location = System::Drawing::Point(102, 100);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 18);
			this->label6->TabIndex = 22;
			this->label6->Text = L"k1=";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label7->Location = System::Drawing::Point(185, 101);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 18);
			this->label7->TabIndex = 23;
			this->label7->Text = L"k2=";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label8->Location = System::Drawing::Point(278, 101);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 18);
			this->label8->TabIndex = 24;
			this->label8->Text = L"k3=";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label9->Location = System::Drawing::Point(20, 135);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(37, 18);
			this->label9->TabIndex = 25;
			this->label9->Text = L"k4=";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label10->Location = System::Drawing::Point(102, 132);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 18);
			this->label10->TabIndex = 26;
			this->label10->Text = L"k5=";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label11->Location = System::Drawing::Point(278, 132);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 18);
			this->label11->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label12->Location = System::Drawing::Point(186, 132);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 18);
			this->label12->TabIndex = 28;
			// 
			// item9
			// 
			this->item9->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->item9->Location = System::Drawing::Point(411, 128);
			this->item9->Margin = System::Windows::Forms::Padding(2);
			this->item9->Name = L"item9";
			this->item9->Size = System::Drawing::Size(27, 26);
			this->item9->TabIndex = 29;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label13->Location = System::Drawing::Point(370, 130);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 18);
			this->label13->TabIndex = 30;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label14->Location = System::Drawing::Point(20, 210);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(136, 18);
			this->label14->TabIndex = 31;
			this->label14->Text = L"Введена система\r\n";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label15->Location = System::Drawing::Point(20, 239);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(8, 18);
			this->label15->TabIndex = 32;
			this->label15->Text = L"\r\n";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label16->Location = System::Drawing::Point(20, 261);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 18);
			this->label16->TabIndex = 33;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label17->Location = System::Drawing::Point(17, 287);
			this->label17->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(0, 18);
			this->label17->TabIndex = 34;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label18->Location = System::Drawing::Point(17, 365);
			this->label18->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 18);
			this->label18->TabIndex = 38;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label19->Location = System::Drawing::Point(18, 317);
			this->label19->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(0, 18);
			this->label19->TabIndex = 39;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label20->Location = System::Drawing::Point(186, 317);
			this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(0, 18);
			this->label20->TabIndex = 40;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label21->Location = System::Drawing::Point(387, 317);
			this->label21->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(0, 18);
			this->label21->TabIndex = 41;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label22->Location = System::Drawing::Point(1188, 40);
			this->label22->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(78, 18);
			this->label22->TabIndex = 42;
			this->label22->Text = L"Розв\'язок";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label23->Location = System::Drawing::Point(1642, 70);
			this->label23->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(0, 18);
			this->label23->TabIndex = 43;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label25->Location = System::Drawing::Point(720, 88);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(99, 18);
			this->label25->TabIndex = 45;
			this->label25->Text = L"Вид системи";
			// 
			// Methods
			// 
			this->Methods->Controls->Add(this->Secant);
			this->Methods->Controls->Add(this->Newton);
			this->Methods->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->Methods->Location = System::Drawing::Point(12, 452);
			this->Methods->Name = L"Methods";
			this->Methods->Size = System::Drawing::Size(290, 45);
			this->Methods->TabIndex = 46;
			this->Methods->TabStop = false;
			// 
			// Secant
			// 
			this->Secant->AutoSize = true;
			this->Secant->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->Secant->Location = System::Drawing::Point(158, 19);
			this->Secant->Name = L"Secant";
			this->Secant->Size = System::Drawing::Size(119, 22);
			this->Secant->TabIndex = 48;
			this->Secant->Text = L"Метод січних";
			this->Secant->UseVisualStyleBackColor = true;
			// 
			// Newton
			// 
			this->Newton->AutoSize = true;
			this->Newton->Checked = true;
			this->Newton->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->Newton->Location = System::Drawing::Point(11, 19);
			this->Newton->Name = L"Newton";
			this->Newton->Size = System::Drawing::Size(141, 22);
			this->Newton->TabIndex = 47;
			this->Newton->TabStop = true;
			this->Newton->Text = L"Метод Ньютона";
			this->Newton->UseVisualStyleBackColor = true;
			// 
			// Calculate
			// 
			this->Calculate->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->Calculate->Location = System::Drawing::Point(139, 348);
			this->Calculate->Name = L"Calculate";
			this->Calculate->Size = System::Drawing::Size(136, 35);
			this->Calculate->TabIndex = 47;
			this->Calculate->Text = L"Порахувати";
			this->Calculate->UseVisualStyleBackColor = true;
			this->Calculate->Click += gcnew System::EventHandler(this, &MyForm::Calculate_Click);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->label24->Location = System::Drawing::Point(23, 420);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(0, 18);
			this->label24->TabIndex = 47;
			// 
			// toFile
			// 
			this->toFile->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->toFile->Location = System::Drawing::Point(1355, 19);
			this->toFile->Name = L"toFile";
			this->toFile->Size = System::Drawing::Size(193, 50);
			this->toFile->TabIndex = 48;
			this->toFile->Text = L"Зберегти у файл";
			this->toFile->UseVisualStyleBackColor = true;
			this->toFile->Click += gcnew System::EventHandler(this, &MyForm::toFile_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(640, 117);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(248, 111);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 48;
			this->pictureBox1->TabStop = false;
			// 
			// results
			// 
			this->results->Font = (gcnew System::Drawing::Font(L"Arial", 12));
			this->results->Location = System::Drawing::Point(1191, 89);
			this->results->Name = L"results";
			this->results->Size = System::Drawing::Size(491, 361);
			this->results->TabIndex = 49;
			this->results->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1844, 845);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->item4);
			this->Controls->Add(this->item6);
			this->Controls->Add(this->item5);
			this->Controls->Add(this->item3);
			this->Controls->Add(this->item2);
			this->Controls->Add(this->item1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->choose);
			this->Controls->Add(this->templates);
			this->Controls->Add(this->label1);
			//this->Controls->Add(this->results);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Form1";
			this->Methods->ResumeLayout(false);
			this->Methods->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void choose_Click(System::Object^ sender, System::EventArgs^ e);// Висвічується загальний вид системи рівнянь
private: System::Void submit_Click(System::Object^ sender, System::EventArgs^ e);//Висвічується загальний вид системи рівнянь разом з коефіцієнтами
private: System::Void Calculate_Click(System::Object^ sender, System::EventArgs^ e);// Вирішує систему обраним методом
private: System::Void toFile_Click(System::Object^ sender, System::EventArgs^ e);// Записує результат у файл
private: System::Void Calculator::MyForm::addComponents(System::Object^ sender, System::EventArgs^ e);// додає деякі компоненти на форму


};
}
