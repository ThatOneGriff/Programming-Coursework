#pragma once
#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

namespace Agora {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Registration : public System::Windows::Forms::Form
	{
	public:
		Registration(void)
		{
			InitializeComponent();
		}

	protected:
		~Registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_registration;
	private: System::Windows::Forms::Label^ label_kalimera;
	private: System::Windows::Forms::Label^ label_no_account;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::GroupBox^ registration_individual;
	private: System::Windows::Forms::TextBox^ input_name;


	private: System::Windows::Forms::Label^ label_name;
	private: System::Windows::Forms::Label^ label_patronym;
	private: System::Windows::Forms::TextBox^ input_patronym;



	private: System::Windows::Forms::Label^ label_surname;
	private: System::Windows::Forms::TextBox^ input_surname;
	private: System::Windows::Forms::Label^ label_if_you_have;
	private: System::Windows::Forms::TextBox^ input_country_code;
	private: System::Windows::Forms::TextBox^ input_carrier_code;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ input_phone_number_body;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;









	protected:



    protected:

	protected:

	private:
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label_registration = (gcnew System::Windows::Forms::Label());
			this->label_kalimera = (gcnew System::Windows::Forms::Label());
			this->label_no_account = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->registration_individual = (gcnew System::Windows::Forms::GroupBox());
			this->input_phone_number_body = (gcnew System::Windows::Forms::TextBox());
			this->input_country_code = (gcnew System::Windows::Forms::TextBox());
			this->input_carrier_code = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_if_you_have = (gcnew System::Windows::Forms::Label());
			this->label_patronym = (gcnew System::Windows::Forms::Label());
			this->input_patronym = (gcnew System::Windows::Forms::TextBox());
			this->label_surname = (gcnew System::Windows::Forms::Label());
			this->input_surname = (gcnew System::Windows::Forms::TextBox());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->input_name = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->registration_individual->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_registration
			// 
			this->label_registration->AutoSize = true;
			this->label_registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_registration->Location = System::Drawing::Point(186, 9);
			this->label_registration->Name = L"label_registration";
			this->label_registration->Size = System::Drawing::Size(142, 25);
			this->label_registration->TabIndex = 0;
			this->label_registration->Text = L"Регистрация";
			// 
			// label_kalimera
			// 
			this->label_kalimera->AutoSize = true;
			this->label_kalimera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_kalimera->Location = System::Drawing::Point(141, 46);
			this->label_kalimera->Name = L"label_kalimera";
			this->label_kalimera->Size = System::Drawing::Size(222, 20);
			this->label_kalimera->TabIndex = 1;
			this->label_kalimera->Text = L"Доброе утро/день/вечер!";
			// 
			// label_no_account
			// 
			this->label_no_account->AutoSize = true;
			this->label_no_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_no_account->Location = System::Drawing::Point(46, 76);
			this->label_no_account->Name = L"label_no_account";
			this->label_no_account->Size = System::Drawing::Size(408, 20);
			this->label_no_account->TabIndex = 2;
			this->label_no_account->Text = L"Ваш аккаунт не был обнаружен в системе. Вы...";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(90, 112);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(114, 24);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Физ. лицо";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(310, 112);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(104, 24);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Юр. лицо";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// registration_individual
			// 
			this->registration_individual->Controls->Add(this->input_phone_number_body);
			this->registration_individual->Controls->Add(this->input_country_code);
			this->registration_individual->Controls->Add(this->input_carrier_code);
			this->registration_individual->Controls->Add(this->label1);
			this->registration_individual->Controls->Add(this->label_if_you_have);
			this->registration_individual->Controls->Add(this->label_patronym);
			this->registration_individual->Controls->Add(this->groupBox1);
			this->registration_individual->Controls->Add(this->input_patronym);
			this->registration_individual->Controls->Add(this->label_surname);
			this->registration_individual->Controls->Add(this->input_surname);
			this->registration_individual->Controls->Add(this->label_name);
			this->registration_individual->Controls->Add(this->input_name);
			this->registration_individual->Location = System::Drawing::Point(50, 142);
			this->registration_individual->Name = L"registration_individual";
			this->registration_individual->Size = System::Drawing::Size(404, 242);
			this->registration_individual->TabIndex = 5;
			this->registration_individual->TabStop = false;
			this->registration_individual->Text = L"ФИО";
			// 
			// input_phone_number_body
			// 
			this->input_phone_number_body->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->input_phone_number_body->Location = System::Drawing::Point(279, 145);
			this->input_phone_number_body->MaxLength = 9;
			this->input_phone_number_body->Name = L"input_phone_number_body";
			this->input_phone_number_body->Size = System::Drawing::Size(90, 26);
			this->input_phone_number_body->TabIndex = 9;
			this->input_phone_number_body->TextChanged += gcnew System::EventHandler(this, &Registration::input_phone_number_body_TextChanged);
			this->input_phone_number_body->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_take_digits);
			// 
			// input_country_code
			// 
			this->input_country_code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_country_code->Location = System::Drawing::Point(184, 145);
			this->input_country_code->Name = L"input_country_code";
			this->input_country_code->ReadOnly = true;
			this->input_country_code->Size = System::Drawing::Size(38, 26);
			this->input_country_code->TabIndex = 6;
			this->input_country_code->Text = L"+7";
			// 
			// input_carrier_code
			// 
			this->input_carrier_code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_carrier_code->Location = System::Drawing::Point(228, 145);
			this->input_carrier_code->MaxLength = 5;
			this->input_carrier_code->Name = L"input_carrier_code";
			this->input_carrier_code->Size = System::Drawing::Size(45, 26);
			this->input_carrier_code->TabIndex = 7;
			this->input_carrier_code->TextChanged += gcnew System::EventHandler(this, &Registration::input_carrier_code_TextChanged);
			this->input_carrier_code->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_take_digits);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(22, 148);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Номер телефона";
			// 
			// label_if_you_have
			// 
			this->label_if_you_have->AutoSize = true;
			this->label_if_you_have->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_if_you_have->Location = System::Drawing::Point(200, 115);
			this->label_if_you_have->Name = L"label_if_you_have";
			this->label_if_you_have->Size = System::Drawing::Size(102, 17);
			this->label_if_you_have->TabIndex = 6;
			this->label_if_you_have->Text = L"(при наличии)";
			// 
			// label_patronym
			// 
			this->label_patronym->AutoSize = true;
			this->label_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_patronym->Location = System::Drawing::Point(16, 85);
			this->label_patronym->Name = L"label_patronym";
			this->label_patronym->Size = System::Drawing::Size(91, 20);
			this->label_patronym->TabIndex = 5;
			this->label_patronym->Text = L"Отчество";
			// 
			// input_patronym
			// 
			this->input_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_patronym->Location = System::Drawing::Point(113, 82);
			this->input_patronym->MaxLength = 20;
			this->input_patronym->Name = L"input_patronym";
			this->input_patronym->Size = System::Drawing::Size(275, 26);
			this->input_patronym->TabIndex = 4;
			this->input_patronym->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_take_letters);
			// 
			// label_surname
			// 
			this->label_surname->AutoSize = true;
			this->label_surname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_surname->Location = System::Drawing::Point(16, 56);
			this->label_surname->Name = L"label_surname";
			this->label_surname->Size = System::Drawing::Size(87, 20);
			this->label_surname->TabIndex = 3;
			this->label_surname->Text = L"Фамилия";
			// 
			// input_surname
			// 
			this->input_surname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_surname->Location = System::Drawing::Point(113, 53);
			this->input_surname->MaxLength = 20;
			this->input_surname->Name = L"input_surname";
			this->input_surname->Size = System::Drawing::Size(275, 26);
			this->input_surname->TabIndex = 2;
			this->input_surname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_take_letters);
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name->Location = System::Drawing::Point(16, 24);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(42, 20);
			this->label_name->TabIndex = 1;
			this->label_name->Text = L"Имя";
			// 
			// input_name
			// 
			this->input_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_name->Location = System::Drawing::Point(113, 21);
			this->input_name->MaxLength = 20;
			this->input_name->Name = L"input_name";
			this->input_name->Size = System::Drawing::Size(275, 26);
			this->input_name->TabIndex = 0;
			this->input_name->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_take_letters);
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(0, 131);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(404, 111);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Контакты";
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 417);
			this->Controls->Add(this->registration_individual);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label_no_account);
			this->Controls->Add(this->label_kalimera);
			this->Controls->Add(this->label_registration);
			this->Name = L"Registration";
			this->Text = L"Регистрация";
			this->registration_individual->ResumeLayout(false);
			this->registration_individual->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion
private:

	#define BACKSPACE (char)8


	System::Void only_take_letters(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		System::Char key = e->KeyChar;
		if (! is_letter(key) && key != BACKSPACE && key != L'\'' && key != L'-' && key != L' ')
			e->Handled = true;
	}


	System::Void only_take_digits(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		System::Char key = e->KeyChar;
		if (! is_digit(key) && key != BACKSPACE)
			e->Handled = true;
	}


	int _carrier_code_previous_length = 0;
	System::Void input_carrier_code_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// inserting '('
		if (input_carrier_code->Text->Length == 1 && _carrier_code_previous_length == 0)
		{
			input_carrier_code->Text = "(" + input_carrier_code->Text;
			input_carrier_code->SelectionStart = 2;
		}

		// inserting ')'
		else if (input_carrier_code->Text->Length == 4 && _carrier_code_previous_length == 3)
		{
			input_carrier_code->Text += L')';
			input_carrier_code->SelectionStart = 5;
		}

		_carrier_code_previous_length = input_carrier_code->Text->Length;
	}


	int _phone_number_body_previous_length = 0;
	System::Void input_phone_number_body_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// inserting first '-'
		if (input_phone_number_body->Text->Length == 3 && _phone_number_body_previous_length == 2)
		{
			input_phone_number_body->Text += L'-';
			input_phone_number_body->SelectionStart = 4;
		}

		// inserting second '-'
		else if (input_phone_number_body->Text->Length == 6 && _phone_number_body_previous_length == 5)
		{
			input_phone_number_body->Text += L'-';
			input_phone_number_body->SelectionStart = 7;
		}

		_phone_number_body_previous_length = input_phone_number_body->Text->Length;
	}
};
}

#endif