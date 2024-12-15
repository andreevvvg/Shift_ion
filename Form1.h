#pragma once
#include "Header.h"
#include <cstring>
//#include <winuser.h>
//#include <string>


ofstream fout;
ifstream fin;
ifstream f_in_abc;

bool convert(System::Windows::Forms::TextBox^ textBox) {
	bool flagged = true;
	for (int i; i < textBox->Text->Length; i++)
	{
		if ((textBox->Text[i] <= 47 || textBox->Text[i] >= 58) && textBox->Text[i] != 8 &&
			textBox->Text[i] != 44 && textBox->Text[i] != '-' && textBox->Text[i] != 'e') {
			flagged = false;
		}
	}
	if (!flagged) {textBox->Clear();
	}
	return flagged;
}

//auto v = validator(str_float,true);
//pure pa;
namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int counter = 0;
	int www = 0;

	//ofstream fout;
	//ofstream foo;
	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox_a;
	private: System::Windows::Forms::Label^ label_a;
	private: System::Windows::Forms::RadioButton^ radioButton_file;
	private: System::Windows::Forms::RadioButton^ radioButton_formula;
	private: System::Windows::Forms::Label^ label_file;


	protected:

	private:
		double a = 0;
		String^ a_str = "0";

		double b = 0;
		String^ b_str = "0";

		double c = 0;
		String^ c_str = "0";

		double N = 0;
		String^ N_str = "0";

		double I = 0;
		String^ I_str = "0";


		double T1 = 0;
		String^ T1_str = "0";
		double T2 = 0;
		String^ T2_str = "0";
		double Th = 0;
		String^ Th_str = "0";

		double vp1 = 0;
		String^ vp1_str = "0";
		double vp2 = 0;
		String^ vp2_str = "0";
		double vph = 0;
		String^ vph_str = "0";

		double T_scale = 1;
		String^ T_scale_str = "1";
		double sig_scale = 1;
		String^ sig_scale_str = "1";

		double m = 0;

		bool flag_file_open = false;
		bool correct = false;

		String^ jopa = "jopa";

		

	private: System::Windows::Forms::Label^ label_b;
	private: System::Windows::Forms::TextBox^ textBox_b;
	private: System::Windows::Forms::Label^ label_c;
	private: System::Windows::Forms::TextBox^ textBox_c;
	private: System::Windows::Forms::Label^ label_N;
	private: System::Windows::Forms::TextBox^ textBox_N;
	private: System::Windows::Forms::Label^ label_I;
	private: System::Windows::Forms::TextBox^ textBox_I;
	private: System::Windows::Forms::Label^ label_T1;
	private: System::Windows::Forms::TextBox^ textBox_T1;
	private: System::Windows::Forms::Label^ label_T2;
	private: System::Windows::Forms::TextBox^ textBox_T2;
	private: System::Windows::Forms::Label^ label_Th;
	private: System::Windows::Forms::TextBox^ textBox_Th;
	private: System::Windows::Forms::Label^ label_vp1;
	private: System::Windows::Forms::TextBox^ textBox_vp1;
	private: System::Windows::Forms::Label^ label_vp2;
	private: System::Windows::Forms::TextBox^ textBox_vp2;
	private: System::Windows::Forms::Label^ label_vph;
	private: System::Windows::Forms::TextBox^ textBox_vph;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::CheckBox^ checkBox_pure;
	private: System::Windows::Forms::CheckBox^ checkBox_logT;
	private: System::Windows::Forms::CheckBox^ checkBox_logvp;
	private: System::Windows::Forms::Button^ button_fin;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::Label^ label_T_scale;
	private: System::Windows::Forms::TextBox^ textBox_T_scale;
	private: System::Windows::Forms::Label^ label_sig_scale;
	private: System::Windows::Forms::TextBox^ textBox_sig_scale;
private: System::Windows::Forms::TextBox^ textBox_m;
private: System::Windows::Forms::Label^ label_m;
private: System::Windows::Forms::Label^ label_error;
private: System::Windows::Forms::CheckBox^ checkBox_shift;
private: System::Windows::Forms::OpenFileDialog^ openFileDialog3;


private: System::ComponentModel::IContainer^ components;


		   /// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox_a = (gcnew System::Windows::Forms::TextBox());
			this->label_a = (gcnew System::Windows::Forms::Label());
			this->radioButton_file = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_formula = (gcnew System::Windows::Forms::RadioButton());
			this->label_file = (gcnew System::Windows::Forms::Label());
			this->label_b = (gcnew System::Windows::Forms::Label());
			this->textBox_b = (gcnew System::Windows::Forms::TextBox());
			this->label_c = (gcnew System::Windows::Forms::Label());
			this->textBox_c = (gcnew System::Windows::Forms::TextBox());
			this->label_N = (gcnew System::Windows::Forms::Label());
			this->textBox_N = (gcnew System::Windows::Forms::TextBox());
			this->label_I = (gcnew System::Windows::Forms::Label());
			this->textBox_I = (gcnew System::Windows::Forms::TextBox());
			this->label_T1 = (gcnew System::Windows::Forms::Label());
			this->textBox_T1 = (gcnew System::Windows::Forms::TextBox());
			this->label_T2 = (gcnew System::Windows::Forms::Label());
			this->textBox_T2 = (gcnew System::Windows::Forms::TextBox());
			this->label_Th = (gcnew System::Windows::Forms::Label());
			this->textBox_Th = (gcnew System::Windows::Forms::TextBox());
			this->label_vp1 = (gcnew System::Windows::Forms::Label());
			this->textBox_vp1 = (gcnew System::Windows::Forms::TextBox());
			this->label_vp2 = (gcnew System::Windows::Forms::Label());
			this->textBox_vp2 = (gcnew System::Windows::Forms::TextBox());
			this->label_vph = (gcnew System::Windows::Forms::Label());
			this->textBox_vph = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->checkBox_pure = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_logT = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_logvp = (gcnew System::Windows::Forms::CheckBox());
			this->button_fin = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label_T_scale = (gcnew System::Windows::Forms::Label());
			this->textBox_T_scale = (gcnew System::Windows::Forms::TextBox());
			this->label_sig_scale = (gcnew System::Windows::Forms::Label());
			this->textBox_sig_scale = (gcnew System::Windows::Forms::TextBox());
			this->textBox_m = (gcnew System::Windows::Forms::TextBox());
			this->label_m = (gcnew System::Windows::Forms::Label());
			this->label_error = (gcnew System::Windows::Forms::Label());
			this->checkBox_shift = (gcnew System::Windows::Forms::CheckBox());
			this->openFileDialog3 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 209);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ввести параметры";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox_a
			// 
			this->textBox_a->Location = System::Drawing::Point(43, 52);
			this->textBox_a->Name = L"textBox_a";
			this->textBox_a->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox_a->Size = System::Drawing::Size(82, 20);
			this->textBox_a->TabIndex = 1;
			this->textBox_a->Text = L"14";
			this->textBox_a->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_a_TextChanged);
			// 
			// label_a
			// 
			this->label_a->AutoSize = true;
			this->label_a->Location = System::Drawing::Point(12, 55);
			this->label_a->Name = L"label_a";
			this->label_a->Size = System::Drawing::Size(25, 13);
			this->label_a->TabIndex = 2;
			this->label_a->Text = L"a = ";
			// 
			// radioButton_file
			// 
			this->radioButton_file->AutoSize = true;
			this->radioButton_file->Checked = true;
			this->radioButton_file->Location = System::Drawing::Point(18, 12);
			this->radioButton_file->Name = L"radioButton_file";
			this->radioButton_file->Size = System::Drawing::Size(117, 17);
			this->radioButton_file->TabIndex = 1;
			this->radioButton_file->TabStop = true;
			this->radioButton_file->Text = L"Сечения из файла";
			this->radioButton_file->UseVisualStyleBackColor = true;
			this->radioButton_file->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_file_CheckedChanged);
			// 
			// radioButton_formula
			// 
			this->radioButton_formula->AutoSize = true;
			this->radioButton_formula->Location = System::Drawing::Point(141, 12);
			this->radioButton_formula->Name = L"radioButton_formula";
			this->radioButton_formula->Size = System::Drawing::Size(130, 17);
			this->radioButton_formula->TabIndex = 2;
			this->radioButton_formula->Text = L"Сечения по формуле";
			this->radioButton_formula->UseVisualStyleBackColor = true;
			this->radioButton_formula->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_formula_CheckedChanged);
			// 
			// label_file
			// 
			this->label_file->AutoSize = true;
			this->label_file->Location = System::Drawing::Point(30, 52);
			this->label_file->Name = L"label_file";
			this->label_file->Size = System::Drawing::Size(33, 13);
			this->label_file->TabIndex = 3;
			this->label_file->Text = L"файл";
			// 
			// label_b
			// 
			this->label_b->AutoSize = true;
			this->label_b->Location = System::Drawing::Point(12, 78);
			this->label_b->Name = L"label_b";
			this->label_b->Size = System::Drawing::Size(25, 13);
			this->label_b->TabIndex = 3;
			this->label_b->Text = L"b = ";
			// 
			// textBox_b
			// 
			this->textBox_b->Location = System::Drawing::Point(43, 75);
			this->textBox_b->Name = L"textBox_b";
			this->textBox_b->Size = System::Drawing::Size(82, 20);
			this->textBox_b->TabIndex = 4;
			this->textBox_b->Text = L"1,08";
			this->textBox_b->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_b_TextChanged);
			// 
			// label_c
			// 
			this->label_c->AutoSize = true;
			this->label_c->Location = System::Drawing::Point(12, 104);
			this->label_c->Name = L"label_c";
			this->label_c->Size = System::Drawing::Size(25, 13);
			this->label_c->TabIndex = 5;
			this->label_c->Text = L"c = ";
			// 
			// textBox_c
			// 
			this->textBox_c->Location = System::Drawing::Point(43, 101);
			this->textBox_c->Name = L"textBox_c";
			this->textBox_c->Size = System::Drawing::Size(82, 20);
			this->textBox_c->TabIndex = 6;
			this->textBox_c->Text = L"0,75";
			this->textBox_c->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_c_TextChanged);
			// 
			// label_N
			// 
			this->label_N->AutoSize = true;
			this->label_N->Location = System::Drawing::Point(10, 131);
			this->label_N->Name = L"label_N";
			this->label_N->Size = System::Drawing::Size(27, 13);
			this->label_N->TabIndex = 7;
			this->label_N->Text = L"N = ";
			// 
			// textBox_N
			// 
			this->textBox_N->Location = System::Drawing::Point(43, 128);
			this->textBox_N->Name = L"textBox_N";
			this->textBox_N->Size = System::Drawing::Size(82, 20);
			this->textBox_N->TabIndex = 8;
			this->textBox_N->Text = L"73";
			this->textBox_N->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_N_TextChanged);
			// 
			// label_I
			// 
			this->label_I->AutoSize = true;
			this->label_I->Location = System::Drawing::Point(15, 157);
			this->label_I->Name = L"label_I";
			this->label_I->Size = System::Drawing::Size(22, 13);
			this->label_I->TabIndex = 9;
			this->label_I->Text = L"I = ";
			// 
			// textBox_I
			// 
			this->textBox_I->Location = System::Drawing::Point(43, 154);
			this->textBox_I->Name = L"textBox_I";
			this->textBox_I->Size = System::Drawing::Size(82, 20);
			this->textBox_I->TabIndex = 10;
			this->textBox_I->Text = L"42,4";
			this->textBox_I->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_I_TextChanged);
			// 
			// label_T1
			// 
			this->label_T1->AutoSize = true;
			this->label_T1->Location = System::Drawing::Point(138, 55);
			this->label_T1->Name = L"label_T1";
			this->label_T1->Size = System::Drawing::Size(32, 13);
			this->label_T1->TabIndex = 11;
			this->label_T1->Text = L"T1 = ";
			// 
			// textBox_T1
			// 
			this->textBox_T1->Location = System::Drawing::Point(172, 52);
			this->textBox_T1->Name = L"textBox_T1";
			this->textBox_T1->Size = System::Drawing::Size(100, 20);
			this->textBox_T1->TabIndex = 12;
			this->textBox_T1->Text = L"1";
			this->textBox_T1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_T1_TextChanged);
			// 
			// label_T2
			// 
			this->label_T2->AutoSize = true;
			this->label_T2->Location = System::Drawing::Point(138, 78);
			this->label_T2->Name = L"label_T2";
			this->label_T2->Size = System::Drawing::Size(32, 13);
			this->label_T2->TabIndex = 13;
			this->label_T2->Text = L"T2 = ";
			// 
			// textBox_T2
			// 
			this->textBox_T2->Location = System::Drawing::Point(172, 75);
			this->textBox_T2->Name = L"textBox_T2";
			this->textBox_T2->Size = System::Drawing::Size(100, 20);
			this->textBox_T2->TabIndex = 14;
			this->textBox_T2->Text = L"100";
			this->textBox_T2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_T2_TextChanged);
			// 
			// label_Th
			// 
			this->label_Th->AutoSize = true;
			this->label_Th->Location = System::Drawing::Point(138, 104);
			this->label_Th->Name = L"label_Th";
			this->label_Th->Size = System::Drawing::Size(32, 13);
			this->label_Th->TabIndex = 15;
			this->label_Th->Text = L"Th = ";
			// 
			// textBox_Th
			// 
			this->textBox_Th->Location = System::Drawing::Point(172, 101);
			this->textBox_Th->Name = L"textBox_Th";
			this->textBox_Th->Size = System::Drawing::Size(100, 20);
			this->textBox_Th->TabIndex = 16;
			this->textBox_Th->Text = L"1";
			this->textBox_Th->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_Th_TextChanged);
			// 
			// label_vp1
			// 
			this->label_vp1->AutoSize = true;
			this->label_vp1->Location = System::Drawing::Point(133, 131);
			this->label_vp1->Name = L"label_vp1";
			this->label_vp1->Size = System::Drawing::Size(37, 13);
			this->label_vp1->TabIndex = 17;
			this->label_vp1->Text = L"vp1 = ";
			// 
			// textBox_vp1
			// 
			this->textBox_vp1->Location = System::Drawing::Point(172, 128);
			this->textBox_vp1->Name = L"textBox_vp1";
			this->textBox_vp1->Size = System::Drawing::Size(100, 20);
			this->textBox_vp1->TabIndex = 18;
			this->textBox_vp1->Text = L"0,1";
			this->textBox_vp1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_vp1_TextChanged);
			// 
			// label_vp2
			// 
			this->label_vp2->AutoSize = true;
			this->label_vp2->Location = System::Drawing::Point(131, 157);
			this->label_vp2->Name = L"label_vp2";
			this->label_vp2->Size = System::Drawing::Size(37, 13);
			this->label_vp2->TabIndex = 19;
			this->label_vp2->Text = L"vp2 = ";
			// 
			// textBox_vp2
			// 
			this->textBox_vp2->Location = System::Drawing::Point(172, 154);
			this->textBox_vp2->Name = L"textBox_vp2";
			this->textBox_vp2->Size = System::Drawing::Size(100, 20);
			this->textBox_vp2->TabIndex = 20;
			this->textBox_vp2->Text = L"1";
			this->textBox_vp2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_vp2_TextChanged);
			// 
			// label_vph
			// 
			this->label_vph->AutoSize = true;
			this->label_vph->Location = System::Drawing::Point(131, 180);
			this->label_vph->Name = L"label_vph";
			this->label_vph->Size = System::Drawing::Size(37, 13);
			this->label_vph->TabIndex = 21;
			this->label_vph->Text = L"vph = ";
			this->label_vph->Click += gcnew System::EventHandler(this, &Form1::label_vph_Click);
			// 
			// textBox_vph
			// 
			this->textBox_vph->Location = System::Drawing::Point(172, 180);
			this->textBox_vph->Name = L"textBox_vph";
			this->textBox_vph->Size = System::Drawing::Size(100, 20);
			this->textBox_vph->TabIndex = 22;
			this->textBox_vph->Text = L"0,1";
			this->textBox_vph->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_vph_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(177, 226);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 24);
			this->button2->TabIndex = 23;
			this->button2->Text = L"Интегрировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// checkBox_pure
			// 
			this->checkBox_pure->AutoSize = true;
			this->checkBox_pure->Checked = true;
			this->checkBox_pure->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_pure->Location = System::Drawing::Point(172, 32);
			this->checkBox_pure->Name = L"checkBox_pure";
			this->checkBox_pure->Size = System::Drawing::Size(47, 17);
			this->checkBox_pure->TabIndex = 24;
			this->checkBox_pure->Text = L"pure";
			this->checkBox_pure->UseVisualStyleBackColor = true;
			this->checkBox_pure->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox_pure_CheckedChanged);
			// 
			// checkBox_logT
			// 
			this->checkBox_logT->AutoSize = true;
			this->checkBox_logT->Location = System::Drawing::Point(172, 203);
			this->checkBox_logT->Name = L"checkBox_logT";
			this->checkBox_logT->Size = System::Drawing::Size(50, 17);
			this->checkBox_logT->TabIndex = 25;
			this->checkBox_logT->Text = L"log T";
			this->checkBox_logT->UseVisualStyleBackColor = true;
			// 
			// checkBox_logvp
			// 
			this->checkBox_logvp->AutoSize = true;
			this->checkBox_logvp->Location = System::Drawing::Point(228, 203);
			this->checkBox_logvp->Name = L"checkBox_logvp";
			this->checkBox_logvp->Size = System::Drawing::Size(55, 17);
			this->checkBox_logvp->TabIndex = 26;
			this->checkBox_logvp->Text = L"log vp";
			this->checkBox_logvp->UseVisualStyleBackColor = true;
			// 
			// button_fin
			// 
			this->button_fin->Location = System::Drawing::Point(12, 68);
			this->button_fin->Name = L"button_fin";
			this->button_fin->Size = System::Drawing::Size(93, 36);
			this->button_fin->TabIndex = 27;
			this->button_fin->Text = L"Ввести файл с данными";
			this->button_fin->UseVisualStyleBackColor = true;
			this->button_fin->Click += gcnew System::EventHandler(this, &Form1::button_fin_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(177, 226);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(95, 24);
			this->button3->TabIndex = 28;
			this->button3->Text = L"Интегрировать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog2_FileOk);
			// 
			// label_T_scale
			// 
			this->label_T_scale->AutoSize = true;
			this->label_T_scale->Location = System::Drawing::Point(12, 131);
			this->label_T_scale->Name = L"label_T_scale";
			this->label_T_scale->Size = System::Drawing::Size(51, 13);
			this->label_T_scale->TabIndex = 29;
			this->label_T_scale->Text = L"T scale =";
			// 
			// textBox_T_scale
			// 
			this->textBox_T_scale->Location = System::Drawing::Point(69, 128);
			this->textBox_T_scale->Name = L"textBox_T_scale";
			this->textBox_T_scale->Size = System::Drawing::Size(55, 20);
			this->textBox_T_scale->TabIndex = 30;
			this->textBox_T_scale->Text = L"1";
			this->textBox_T_scale->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_T_scale_TextChanged);
			// 
			// label_sig_scale
			// 
			this->label_sig_scale->AutoSize = true;
			this->label_sig_scale->Location = System::Drawing::Point(9, 154);
			this->label_sig_scale->Name = L"label_sig_scale";
			this->label_sig_scale->Size = System::Drawing::Size(50, 13);
			this->label_sig_scale->TabIndex = 31;
			this->label_sig_scale->Text = L"Sig scale";
			// 
			// textBox_sig_scale
			// 
			this->textBox_sig_scale->Location = System::Drawing::Point(69, 154);
			this->textBox_sig_scale->Name = L"textBox_sig_scale";
			this->textBox_sig_scale->Size = System::Drawing::Size(55, 20);
			this->textBox_sig_scale->TabIndex = 32;
			this->textBox_sig_scale->Text = L"1";
			this->textBox_sig_scale->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_sig_scale_TextChanged);
			// 
			// textBox_m
			// 
			this->textBox_m->Location = System::Drawing::Point(33, 180);
			this->textBox_m->Name = L"textBox_m";
			this->textBox_m->Size = System::Drawing::Size(95, 20);
			this->textBox_m->TabIndex = 33;
			this->textBox_m->Text = L"1";
			this->textBox_m->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_m_TextChanged);
			// 
			// label_m
			// 
			this->label_m->AutoSize = true;
			this->label_m->Location = System::Drawing::Point(3, 187);
			this->label_m->Name = L"label_m";
			this->label_m->Size = System::Drawing::Size(24, 13);
			this->label_m->TabIndex = 34;
			this->label_m->Text = L"m =";
			// 
			// label_error
			// 
			this->label_error->AutoSize = true;
			this->label_error->Location = System::Drawing::Point(141, 32);
			this->label_error->Name = L"label_error";
			this->label_error->Size = System::Drawing::Size(0, 13);
			this->label_error->TabIndex = 35;
			// 
			// checkBox_shift
			// 
			this->checkBox_shift->AutoSize = true;
			this->checkBox_shift->Checked = true;
			this->checkBox_shift->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_shift->Location = System::Drawing::Point(227, 32);
			this->checkBox_shift->Name = L"checkBox_shift";
			this->checkBox_shift->Size = System::Drawing::Size(45, 17);
			this->checkBox_shift->TabIndex = 36;
			this->checkBox_shift->Text = L"shift";
			this->checkBox_shift->UseVisualStyleBackColor = true;
			// 
			// openFileDialog3
			// 
			this->openFileDialog3->FileName = L"openFileDialog3";
			this->openFileDialog3->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog3_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->checkBox_shift);
			this->Controls->Add(this->label_error);
			this->Controls->Add(this->label_m);
			this->Controls->Add(this->textBox_m);
			this->Controls->Add(this->textBox_sig_scale);
			this->Controls->Add(this->label_sig_scale);
			this->Controls->Add(this->textBox_T_scale);
			this->Controls->Add(this->label_T_scale);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button_fin);
			this->Controls->Add(this->checkBox_logvp);
			this->Controls->Add(this->checkBox_logT);
			this->Controls->Add(this->checkBox_pure);
			this->Controls->Add(this->textBox_vph);
			this->Controls->Add(this->label_vph);
			this->Controls->Add(this->textBox_vp2);
			this->Controls->Add(this->label_vp2);
			this->Controls->Add(this->textBox_vp1);
			this->Controls->Add(this->label_vp1);
			this->Controls->Add(this->textBox_Th);
			this->Controls->Add(this->label_Th);
			this->Controls->Add(this->textBox_T2);
			this->Controls->Add(this->label_T2);
			this->Controls->Add(this->textBox_T1);
			this->Controls->Add(this->label_T1);
			this->Controls->Add(this->label_file);
			this->Controls->Add(this->radioButton_formula);
			this->Controls->Add(this->radioButton_file);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Скорости ионизации";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//bool correct = true;
		correct = convert(this->textBox_a);
		correct = correct && convert(this->textBox_b);
		correct = correct && convert(this->textBox_c);
		correct = correct && convert(this->textBox_N);
		correct = correct && convert(this->textBox_I);

		correct = correct && convert(this->textBox_T1);
		correct = correct && convert(this->textBox_T2);
		correct = correct && convert(this->textBox_Th);
		correct = correct && convert(this->textBox_vp1);
		correct = correct && convert(this->textBox_vp2);
		correct = correct && convert(this->textBox_vph);

		correct = correct && convert(this->textBox_m);

		correct = correct && convert(this->textBox_T_scale);
		correct = correct && convert(this->textBox_sig_scale);	

		if (!correct) {
			//MessageBoxButtons button = MessageBoxButtons::OK;
			MessageBox::Show("Данные в неверном формате", "Ошибка", MessageBoxButtons::OK);
			//this->label_error->Text = "Данные в неверном формате";
		}
		else{
			a = Convert::ToDouble(this->textBox_a->Text);
			b = Convert::ToDouble(this->textBox_b->Text);
			c = Convert::ToDouble(this->textBox_c->Text);
			N = Convert::ToDouble(this->textBox_N->Text);
			I = Convert::ToDouble(this->textBox_I->Text);


			T1 = Convert::ToDouble(this->textBox_T1->Text);
			T2 = Convert::ToDouble(this->textBox_T2->Text);
			Th = Convert::ToDouble(this->textBox_Th->Text);
			vp1 = Convert::ToDouble(this->textBox_vp1->Text);
			vp2 = Convert::ToDouble(this->textBox_vp2->Text);
			vph = Convert::ToDouble(this->textBox_vph->Text);

			T_scale = Convert::ToDouble(this->textBox_T_scale->Text);
			sig_scale = Convert::ToDouble(this->textBox_sig_scale->Text);

			m = Convert::ToDouble(this->textBox_m->Text);
		}

		//this->label_b->Text = Convert::ToString(T2);

		counter++;
		if (counter > 100) {
			this->button1->Text = L"Чо тыкаешь?";
		}
		if (counter >= 120) {
			this->Close();
		}
	}
	/*private: System::Void label_a_Click(System::Object^ sender, System::EventArgs^ e) {
	}*/
	private: System::Void textBox_a_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		a_str = this->textBox_a->Text;
	}
	

	private: System::Void radioButton_file_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->radioButton_file->Checked) {
			this->Controls->Add(this->label_file);
			this->Controls->Add(this->button_fin);
			this->Controls->Add(this->button3);

			this->Controls->Add(this->textBox_sig_scale);
			this->Controls->Add(this->label_sig_scale);
			this->Controls->Add(this->textBox_T_scale);
			this->Controls->Add(this->label_T_scale);

			this->Controls->Remove(this->textBox_I);
			this->Controls->Remove(this->label_I);

			this->Controls->Remove(this->textBox_N);
			this->Controls->Remove(this->label_N);

			this->Controls->Remove(this->textBox_c);
			this->Controls->Remove(this->label_c);

			this->Controls->Remove(this->textBox_b);
			this->Controls->Remove(this->label_b);

			this->Controls->Remove(this->textBox_a);
			this->Controls->Remove(this->label_a);
			this->Controls->Remove(this->button2);
		}
	}

	private: System::Void radioButton_formula_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->radioButton_formula->Checked) {
			this->Controls->Add(this->button2);

			this->Controls->Add(this->textBox_I);
			this->Controls->Add(this->label_I);

			this->Controls->Add(this->textBox_N);
			this->Controls->Add(this->label_N);
			
			this->Controls->Add(this->textBox_c);
			this->Controls->Add(this->label_c);
			
			this->Controls->Add(this->textBox_b);
			this->Controls->Add(this->label_b);
			
			this->Controls->Add(this->textBox_a);
			this->Controls->Add(this->label_a);

			this->Controls->Remove(this->label_file);
			this->Controls->Remove(this->button_fin);
			this->Controls->Remove(this->button3);

			this->Controls->Remove(this->textBox_sig_scale);
			this->Controls->Remove(this->label_sig_scale);
			this->Controls->Remove(this->textBox_T_scale);
			this->Controls->Remove(this->label_T_scale);
		}
	}

private: System::Void textBox_b_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	b_str = this->textBox_b->Text;
}
private: System::Void textBox_c_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	c_str = this->textBox_c->Text;
}
private: System::Void textBox_N_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	N_str = this->textBox_N->Text;
}
private: System::Void textBox_I_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	I_str = this->textBox_I->Text;
}

private: System::Void textBox_T1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	T1_str = this->textBox_T1->Text;
}
private: System::Void textBox_T2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	T2_str = this->textBox_T2->Text;
}
private: System::Void textBox_Th_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	Th_str = this->textBox_Th->Text;
}

private: System::Void textBox_vp1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	vp1_str = this->textBox_vp1->Text;
}
private: System::Void textBox_vp2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	vp2_str = this->textBox_vp2->Text;
}
private: System::Void textBox_vph_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	vph_str = this->textBox_vph->Text;
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->openFileDialog1->ShowDialog();
	jopa = this->openFileDialog1->FileName;
	int length = jopa->Length;
	char* char_array = new char[length + 1];
	char_array[length] = '\0';
	for (int i = 0; i < length; i++) {
		char_array[i] = jopa[i];
	}
	fout.open(char_array);
	gsl_f_params jo;
	jo.T = 0; 
	pure pa;
	//pa.set_params(1, 1, 3, 1, 1, 10, 5, true, &jo, 1, 1, 1, 1, 50);
	//pa.set_params(1, 1, 100, 1, 1, 12, 1, true, &jo, 1, 1, 1, 1, 50);
	if (correct) {
		pa.set_params(m, T1, T2, Th, vp1, vp2, vph, this->checkBox_pure->Checked, this->checkBox_shift->Checked, &jo, a, b, c, N, I);
		pa.integration(fout, this->checkBox_logT->Checked, this->checkBox_logvp->Checked);
		MessageBox::Show("Интнгрирование завершено", "Готово", MessageBoxButtons::OK);
	}
	else MessageBox::Show("Не введены параметры", "Ошибка", MessageBoxButtons::OK);
	//fout << T1_str[0] << " " << T2 << " " << Th;
	flag_file_open = false;
	//fout << "txt";
	//pa.~pure();
	fout.close();
	delete[] char_array;
	
	//MessageBox::Show("Интнгрирование завершено", "Готово", MessageBoxButtons::OK);
	//this->label_error->Text = "Готово";
}


private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	flag_file_open = true;
}
private: System::Void checkBox_pure_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_fin_Click(System::Object^ sender, System::EventArgs^ e) {
	this->openFileDialog1->ShowDialog();
	jopa = this->openFileDialog1->FileName;
	int length = jopa->Length;
	char* char_array = new char[length + 1];
	char_array[length] = '\0';
	for (int i = 0; i < length; i++) {
		char_array[i] = jopa[i];
	}
	//this->textBox_vp1->Text = jopa;
	fin.open(char_array);
	//pure pa(fin, 1, 1);
	delete[] char_array;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->openFileDialog2->ShowDialog();
	jopa = this->openFileDialog2->FileName;
	int length = jopa->Length;
	char* char_array = new char[length + 1];
	char_array[length] = '\0';
	for (int i = 0; i < length; i++) {
		char_array[i] = jopa[i];
	}

	fout.open(char_array);
	
	gsl_f_params jo;
	jo.T = 0;
	//pure pa(fin, T_scale, sig_scale);
	//pa.set_params(1, 1, 3, 1, 1, 10, 5, true, &jo);
	if (flag_file_open && correct) {
		pure pa(fin, T_scale, sig_scale);
		/*System::Windows::Forms::MessageBox::Show("Неверный формат данных в файле", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK);*/
		pa.set_params(m, T1, T2, Th, vp1, vp2, vph, this->checkBox_pure->Checked, this->checkBox_shift->Checked, &jo);
		pa.integration(fout, this->checkBox_logT->Checked, this->checkBox_logvp->Checked);
	}
	else {
		if (!flag_file_open) MessageBox::Show("Не задан входной файл", "Ошибка", MessageBoxButtons::OK);
		else MessageBox::Show("Не введены параметры", "Ошибка", MessageBoxButtons::OK);
	}
	//fout << "txt";
	//pa.~pure();
	fout.close();
	delete[] char_array;
	if (flag_file_open) MessageBox::Show("Интнгрирование завершено", "Готово", MessageBoxButtons::OK);
	flag_file_open = false;
}
private: System::Void openFileDialog2_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void textBox_T_scale_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//T_scale_str = this->textBox_T_scale->Text;
	//try {
	//	//validate("jopa", v);
	//}
	//catch (const validation_error& err)
	//{
	//	this->textBox_T1->Text = Convert::ToString(err.what());
	//}
	
	T_scale_str = this->textBox_T_scale->Text;
}
private: System::Void textBox_sig_scale_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//sig_scale_str = this->textBox_sig_scale->Text;
}
private: System::Void textBox_m_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void label_vph_Click(System::Object^ sender, System::EventArgs^ e) {
	www++;

	if (www > 3){

		/*this->openFileDialog3->ShowDialog();
		jopa = this->openFileDialog3->FileName;
		int length = jopa->Length;
		char* char_array = new char[length + 1];
		char_array[length] = '\0';
		for (int i = 0; i < length; i++) {
			char_array[i] = jopa[i];
		}*/
		
		f_in_abc.open("C:/Users/andre/source/repos/app_try2/data/data_z120.txt");
		/*if (f_in_abc) {
			MessageBox::Show("jopa", "jopa", MessageBoxButtons::OK);
		}*/
		double q, y, e, r, t;
		q = 0;
		y = 0;
		e = 0;
		r = 0;
		t = 0;
		int count = 0;

		f_in_abc.clear(); // сбросить флаги потока
		f_in_abc.seekg(0);

		while (f_in_abc >> q >> e >> r >> t >> y) {
			count++;
		}

		

		double* aa = new double[count];
		double* bb = new double[count];
		double* cc = new double[count];
		int* NN = new int[count];
		double* II = new double[count];

		

		f_in_abc.clear(); // сбросить флаги потока
		f_in_abc.seekg(0);
		for (int i = 0; i < count; i++) {
			f_in_abc >> aa[i] >> bb[i] >> cc[i] >> NN[i] >> II[i];
		}

		f_in_abc.close();
		//delete[] char_array;

		/*this->openFileDialog1->ShowDialog();
		jopa = this->openFileDialog1->FileName;
		length = jopa->Length;
		char* char_array1 = new char[length + 2];
		char_array[length + 1] = '\0';
		for (int i = 0; i < length; i++) {
			char_array1[i] = jopa[i];
		}*/

		gsl_f_params jo;
		jo.T = 0;
		pure pa;

		ofstream f_array[3];
		f_array[0].open("data/z120_2.txt");
		f_array[1].open("data/z120_3.txt");
		f_array[2].open("data/z120_4.txt");

		ofstream f_array_sigma[3];
		f_array_sigma[0].open("data/z120_2_sigma.txt");
		f_array_sigma[1].open("data/z120_3_sigma.txt");
		f_array_sigma[2].open("data/z120_4_sigma.txt");

		for (int i = 0; i < count; i++) {
			//char_array1[length] = System::Convert::ToChar(i);
			//fout.open(char_array1);

			if (correct) {
				pa.set_params(m, T1, T2, Th, vp1, vp2, vph, this->checkBox_pure->Checked, this->checkBox_shift->Checked, &jo, aa[i], bb[i], cc[i], NN[i], II[i]);
				pa.integration(f_array[i], this->checkBox_logT->Checked, this->checkBox_logvp->Checked);
				MessageBox::Show("Интнгрирование завершено", "Готово", MessageBoxButtons::OK);
				pa.out_sigma(f_array_sigma[i]);
			}
			else MessageBox::Show("Не введены параметры", "Ошибка", MessageBoxButtons::OK);
			//fout << T1_str[0] << " " << T2 << " " << Th;
			//flag_file_open = false;
			//fout << "txt";
			//pa.~pure();
			fout.close();
		}

		//delete[] char_array1;
		
		

		www = 0;
		delete[] aa;
		delete[] bb;
		delete[] cc;
		delete[] NN;
		delete[] II;
		

	}
}
private: System::Void openFileDialog3_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
};



}




