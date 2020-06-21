#pragma once
#include "Функции.h"
#include <cmath>
#include <string>
using namespace std;

bool work = false;

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Operations* calc;
		MyForm(void)
		{
			InitializeComponent();

			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label9;





	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(444, 197);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 57);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Посчитать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(238, 166);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(49, 26);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox2->Location = System::Drawing::Point(238, 212);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(49, 26);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->Location = System::Drawing::Point(12, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(566, 75);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Сложение ", L"Вычитание", L"Умножение ", L"Деление",
					L"Остаток от деления", L"Возведение в целую степень", L"Обмен местами числителя и знаменателя дроби", L"Смнена знака"
			});
			this->comboBox1->Location = System::Drawing::Point(312, 319);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(266, 28);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->Text = L"(Не выбрано)";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox3->Location = System::Drawing::Point(329, 212);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(49, 26);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox4->Location = System::Drawing::Point(329, 166);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(49, 26);
			this->textBox4->TabIndex = 9;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(20, 166);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 26);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Числитель";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(227, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 40);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Первое\r\n число";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2->Location = System::Drawing::Point(161, 296);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(132, 51);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Вид дроби";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button3->Location = System::Drawing::Point(12, 296);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 51);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Десятичный вид";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label3->Location = System::Drawing::Point(7, 211);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(155, 26);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Знаменатель ";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label5->Location = System::Drawing::Point(378, 276);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(114, 26);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Операции";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button4->Location = System::Drawing::Point(444, 110);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 57);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Очистить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(325, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 40);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Второе \r\nчисло";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Black;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1));
			this->label6->Location = System::Drawing::Point(9, 201);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(157, 2);
			this->label6->TabIndex = 18;
			this->label6->Text = L"_________________________________________________________________________________"
				L"__________________________________________________________________________";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Black;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1));
			this->label7->Location = System::Drawing::Point(324, 201);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 2);
			this->label7->TabIndex = 19;
			this->label7->Text = L"____________________________________________________________________";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Black;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1));
			this->label8->Location = System::Drawing::Point(230, 201);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(70, 2);
			this->label8->TabIndex = 20;
			this->label8->Text = L"____________________________________________________________________";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::LightBlue;
			this->pictureBox1->Location = System::Drawing::Point(-3, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(613, 543);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label9->Location = System::Drawing::Point(187, 197);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(25, 26);
			this->label9->TabIndex = 22;
			this->label9->Text = L"=";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(595, 369);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->Text = L"Калькулятор";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = pictureBox2->CreateGraphics();
		bool flag = false;

		if (comboBox1->SelectedIndex != 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7) {
			g->Clear(Color::White);
			Pen^ p = gcnew Pen(Color::Black, 1.0f);
			g->DrawString(textBox1->Text, this->Font, Brushes::Black, 20, 22);


			Point pt1 = Point(22, 35);
			Point pt2;
			if (6 * Convert::ToDouble(textBox1->Text->Length) > 6 * Convert::ToDouble(textBox2->Text->Length)) {
				pt2 = Point(6 * Convert::ToDouble(textBox1->Text->Length) + 22, 35);
				flag = true;
			}
			else {
				pt2 = Point(6 * Convert::ToDouble(textBox2->Text->Length) + 22, 35);
			}


			g->DrawLine(p, pt1, pt2);

			g->DrawString(textBox2->Text, this->Font, Brushes::Black, 20, 40);


			if (comboBox1->SelectedIndex == 0) {
				work = false;
				if (flag) g->DrawString("+", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString("+", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}
			else if (comboBox1->SelectedIndex == 1) {
				work = false;
				if (flag) g->DrawString("-", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString("-", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}
			else if (comboBox1->SelectedIndex == 2) {
				work = false;
				if (flag) g->DrawString("x", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString("x", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}
			else if (comboBox1->SelectedIndex == 3) {
				work = false;
				if (flag) g->DrawString(":", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString(":", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}
			else if (comboBox1->SelectedIndex == 4) {
				work = false;
				if (flag) g->DrawString("%", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString("%", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}
			else if (comboBox1->SelectedIndex == 5) {
				work = false;
				if (flag) g->DrawString("\n\nx^n", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString("\n\nx^n", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}
			else if (comboBox1->SelectedIndex == 6) {
				work = true;
				if (flag) g->DrawString("\n\n(x/y)=(y/x)", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString("\n\n(x/y)=(y/x)", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}
			else if (comboBox1->SelectedIndex == 7) {
				work = true;
				if (flag) g->DrawString("\n\n*(-1)", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox1->Text->Length) + 30, 28);
				else g->DrawString("\n\n*(-1)", this->Font, Brushes::Black, 6 * Convert::ToDouble(textBox2->Text->Length) + 30, 28);
			}

			
			

			Point pt3;
			Point pt4;
			if (Convert::ToDouble(textBox1->Text->Length) > Convert::ToDouble(textBox2->Text->Length)) {
				pt3 = Point((6 * (Convert::ToString(textBox1->Text))->Length) + 50, 35);
			}
			else {
				pt3 = Point((6 * (Convert::ToString(textBox2->Text))->Length) + 50, 35);
			}

			bool flag2 = false;
			if (((Convert::ToString(textBox4->Text))->Length) > ((Convert::ToString(textBox3->Text))->Length)) {
				pt4 = Point((6 * (Convert::ToString(textBox4->Text))->Length) + 50 + (6 * (Convert::ToString(textBox1->Text))->Length), 35);
				flag2 = true;
			}
			else {
				pt4 = Point((6 * (Convert::ToString(textBox3->Text))->Length) + 50 + (6 * (Convert::ToString(textBox1->Text))->Length), 35);
			}


			if (work == true)
			{
				if (flag)
				{
					if (flag2)
					{
						g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 40);
					}
					else
					{
						g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox2->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox2->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 40);
					}
					else
					{
						/*g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 40);*/
					}
				}
			}
			else
			{
				if (flag)
				{
					if (flag2)
					{
						g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 40);
					}
					else
					{
						g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox2->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox2->Text))->Length) + ((Convert::ToString(textBox4->Text))->Length) + 52, 40);
					}
					else
					{
						g->DrawString(textBox4->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 22);
						g->DrawLine(p, pt3, pt4);
						g->DrawString(textBox3->Text, this->Font, Brushes::Black, 2 * ((Convert::ToString(textBox1->Text))->Length) + ((Convert::ToString(textBox3->Text))->Length) + 52, 40);
					}
				}
			}



			if (flag) {
				if (flag2) {
					g->DrawString("= ", this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 10, 28);
				}
				else {
					g->DrawString("= ", this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 10, 28);
				}
			}
			else {
				if (flag2) {
					g->DrawString("= ", this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 10, 28);
				}
				else
				{
					g->DrawString("= ", this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 10, 28);
				}
			}


			int result_numerator,
				result_denominator,
				length_stroka_5,
				length_stroka_6;
			Point pt5, pt6;


			switch (comboBox1->SelectedIndex)
			{
			case 0:

				work = false;

				result_numerator = calc->Amount_numerator(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox3->Text));
				result_denominator = calc->Amount_denominator(Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox3->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));


				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}

				break;
			case 1:

				work = false;

				result_numerator = calc->Difference_numerator(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox3->Text));
				result_denominator = calc->Difference_denominator(Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox3->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));


				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 70, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 85 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}

				break;
			case 2:

				work = false;

				result_numerator = calc->Multiplication_numerator(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox4->Text));
				result_denominator = calc->Multiplication_denominator(Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox3->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));


				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}

				break;
			case 3:

				work = false;

				result_numerator = calc->Division_numerator(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox3->Text));
				result_denominator = calc->Division_denominator(Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox2->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));


				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}

				break;
			case 4:

				work = false;
				
				result_numerator = calc->Division_numerator(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox3->Text));
				result_denominator = calc->Division_denominator(Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox2->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));


				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}

				break;
			case 5:

				result_numerator = calc->Exponentiation_numerator(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox3->Text));
				result_denominator = calc->Exponentiation_denominator(Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text), Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox3->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));

				work = true;

				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}

				break;
			case 6:

				result_numerator = calc->Swap_numerator(Convert::ToInt32(textBox2->Text));
				result_denominator = calc->Swap_denominator(Convert::ToInt32(textBox1->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));

				work = true;

				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 70, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 85 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}

				break;
			case 7:

				result_numerator = calc->Change_sign_numerator(Convert::ToInt32(textBox1->Text));
				result_denominator = calc->Change_sign_denominator(Convert::ToInt32(textBox2->Text));

				length_stroka_5 = 6 * (calc->Lenght_string(result_numerator));
				length_stroka_6 = 6 * (calc->Lenght_string(result_denominator));

				work = true;

				if (flag) {
					if (flag2) {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else {
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 20 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				else
				{
					if (flag2)
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 68, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 75 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 48 + 24, 40);
					}
					else
					{
						g->DrawString(Convert::ToString(result_numerator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 22);
						pt5 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 70, 35);
						pt6 = Point(6 * ((Convert::ToString(textBox1->Text))->Length) + 6 * ((Convert::ToString(textBox4->Text))->Length) + 85 + length_stroka_5, 35);
						g->DrawLine(p, pt5, pt6);
						g->DrawString(Convert::ToString(result_denominator), this->Font, Brushes::Black, 6 * ((Convert::ToString(textBox2->Text))->Length) + 6 * ((Convert::ToString(textBox3->Text))->Length) + 48 + 24, 40);
					}
				}
				break;				
			default:
				break;
			}
		}
		else {


		}
	};
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = pictureBox2->CreateGraphics();
		g->Clear(Color::White);

		double oper1 = calc->Plain(Convert::ToDouble(textBox1->Text), Convert::ToDouble(textBox2->Text));
		double oper2 = calc->Plain(Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox3->Text));
		int oper3 = calc->Plain(Convert::ToDouble(textBox1->Text), Convert::ToDouble(textBox2->Text));
		int oper4 = calc->Plain(Convert::ToInt32(textBox4->Text), Convert::ToInt32(textBox3->Text));

		double oper5 = calc->Plain(Convert::ToDouble(textBox2->Text), Convert::ToDouble(textBox1->Text));


		g->DrawString(Convert::ToString(oper1), this->Font, Brushes::Black, 20, 30);
		int tmp = calc->Plain(Convert::ToDouble(textBox4->Text), Convert::ToDouble(textBox3->Text));

		switch (comboBox1->SelectedIndex)
		{
		case 0:
			g->DrawString(" +", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 20, 28);
			break;
		case 1:
			g->DrawString(" -", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 20, 28);
			break;
		case 2:
			g->DrawString(" x", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 20, 28);
			break;
		case 3:
			g->DrawString(" :", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 20, 28);
			break;
		case 4:
			g->DrawString(" %", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 17, 28);
			break;
		case 5:
			g->DrawString("\n\nx^n", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 20, 28);
			work = false;
			break;
		case 6:
			g->DrawString("\n\n(x/y) = (y/x)", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 20, 28);
			work = true;
			break;
		case 7:
			g->DrawString("\n\n*(-1)", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 20, 28);
			work = true;
			break;

		default:
			break;
		}

		if (work==true)
		{
			g->DrawString(" = ", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 30 + 6 * ((Convert::ToString(oper2))->Length) + 5, 28);
		}
		else
		{
			g->DrawString(Convert::ToString(oper2), this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 30, 30);
			g->DrawString(" = ", this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 30 + 6 * ((Convert::ToString(oper2))->Length) + 5, 28);
		}


		double result;

		switch (comboBox1->SelectedIndex)
		{
		case 0:
			result = oper1 + oper2;
			break;
		case 1:
			result = oper1 - oper2;
			break;
		case 2:
			result = oper1 * oper2;
			break;
		case 3:
			result = oper1 / oper2;
			break;
		case 4:
			result = oper3 % oper4;
			break;
		case 5:		
			result = oper1;
			for (int i = 1; i < tmp; i++)
			{
				result *= oper1;
			}
			break;
		case 6:
			result = oper5;
			break;
		case 7:
			result = oper1 * (-1);
			break;

		default:
			break;
		}


		if (work == true)
		{
			g->DrawString(Convert::ToString(result), this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 30 + 6 * ((Convert::ToString(oper2))->Length) + 15, 30);
		}
		else
		{ 
			g->DrawString(Convert::ToString(result), this->Font, Brushes::Black, 6 * ((Convert::ToString(oper1))->Length) + 30 + 6 * ((Convert::ToString(oper2))->Length) + 15, 30);
		}

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		comboBox1->Text = "";
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}