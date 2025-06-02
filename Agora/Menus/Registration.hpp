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
		Registration()
		{
			InitializeComponent();
			input_name->Focus();
			set_greeting_time_based();
		}

	protected:
		~Registration()
		{
			if (components)
			{
				delete components;
			}
		}

	#pragma region = WinForms code =

	private: System::Windows::Forms::Label^ label_registration;
	private: System::Windows::Forms::Label^ label_kalimera;
	private: System::Windows::Forms::Label^ label_no_account;
	private: System::Windows::Forms::RadioButton^ button_individual;
	private: System::Windows::Forms::RadioButton^ button_company;


	private: System::Windows::Forms::GroupBox^ registration_individual;
	private: System::Windows::Forms::TextBox^ input_name;


	private: System::Windows::Forms::Label^ label_name;
	private: System::Windows::Forms::Label^ label_patronym;
	private: System::Windows::Forms::TextBox^ input_patronym;



	private: System::Windows::Forms::Label^ label_surname;
	private: System::Windows::Forms::TextBox^ input_surname;
	private: System::Windows::Forms::Label^ label_if_you_have_patronym;

	private: System::Windows::Forms::TextBox^ input_country_code;
	private: System::Windows::Forms::TextBox^ input_carrier_code;
	private: System::Windows::Forms::Label^ label_phone;



	private: System::Windows::Forms::TextBox^ input_phone_number_body;
	private: System::Windows::Forms::GroupBox^ group_contacts;


	private: System::Windows::Forms::Label^ label_email;
	private: System::Windows::Forms::TextBox^ input_email;

	private: System::Windows::Forms::Label^ label_if_you_have_email;
	private: System::Windows::Forms::Label^ label_if_you_have_extra;

	private: System::Windows::Forms::TextBox^ input_extra;

	private: System::Windows::Forms::Label^ label_extra;
	private: System::Windows::Forms::GroupBox^ registration_company;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Button^ button_register;


	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->label_registration = (gcnew System::Windows::Forms::Label());
			this->label_kalimera = (gcnew System::Windows::Forms::Label());
			this->label_no_account = (gcnew System::Windows::Forms::Label());
			this->button_individual = (gcnew System::Windows::Forms::RadioButton());
			this->button_company = (gcnew System::Windows::Forms::RadioButton());
			this->registration_individual = (gcnew System::Windows::Forms::GroupBox());
			this->input_phone_number_body = (gcnew System::Windows::Forms::TextBox());
			this->input_country_code = (gcnew System::Windows::Forms::TextBox());
			this->input_carrier_code = (gcnew System::Windows::Forms::TextBox());
			this->label_phone = (gcnew System::Windows::Forms::Label());
			this->label_if_you_have_patronym = (gcnew System::Windows::Forms::Label());
			this->label_patronym = (gcnew System::Windows::Forms::Label());
			this->group_contacts = (gcnew System::Windows::Forms::GroupBox());
			this->label_if_you_have_extra = (gcnew System::Windows::Forms::Label());
			this->input_extra = (gcnew System::Windows::Forms::TextBox());
			this->label_extra = (gcnew System::Windows::Forms::Label());
			this->label_if_you_have_email = (gcnew System::Windows::Forms::Label());
			this->input_email = (gcnew System::Windows::Forms::TextBox());
			this->label_email = (gcnew System::Windows::Forms::Label());
			this->input_patronym = (gcnew System::Windows::Forms::TextBox());
			this->label_surname = (gcnew System::Windows::Forms::Label());
			this->input_surname = (gcnew System::Windows::Forms::TextBox());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->input_name = (gcnew System::Windows::Forms::TextBox());
			this->registration_company = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button_register = (gcnew System::Windows::Forms::Button());
			this->registration_individual->SuspendLayout();
			this->group_contacts->SuspendLayout();
			this->registration_company->SuspendLayout();
			this->groupBox2->SuspendLayout();
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
			this->label_registration->TabIndex = 1000;
			this->label_registration->Text = L"Регистрация";
			// 
			// label_kalimera
			// 
			this->label_kalimera->AutoSize = true;
			this->label_kalimera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_kalimera->Location = System::Drawing::Point(199, 45);
			this->label_kalimera->Name = L"label_kalimera";
			this->label_kalimera->Size = System::Drawing::Size(52, 20);
			this->label_kalimera->TabIndex = 1000;
			this->label_kalimera->Text = L"Добр";
			// 
			// label_no_account
			// 
			this->label_no_account->AutoSize = true;
			this->label_no_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_no_account->Location = System::Drawing::Point(46, 76);
			this->label_no_account->Name = L"label_no_account";
			this->label_no_account->Size = System::Drawing::Size(408, 20);
			this->label_no_account->TabIndex = 1000;
			this->label_no_account->Text = L"Ваш аккаунт не был обнаружен в системе. Вы...";
			// 
			// button_individual
			// 
			this->button_individual->AutoSize = true;
			this->button_individual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_individual->Location = System::Drawing::Point(90, 112);
			this->button_individual->Name = L"button_individual";
			this->button_individual->Size = System::Drawing::Size(114, 24);
			this->button_individual->TabIndex = 7;
			this->button_individual->Text = L"Физ. лицо";
			this->button_individual->UseVisualStyleBackColor = true;
			this->button_individual->CheckedChanged += gcnew System::EventHandler(this, &Registration::pick_as_individual);
			// 
			// button_company
			// 
			this->button_company->AutoSize = true;
			this->button_company->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_company->Location = System::Drawing::Point(310, 112);
			this->button_company->Name = L"button_company";
			this->button_company->Size = System::Drawing::Size(104, 24);
			this->button_company->TabIndex = 8;
			this->button_company->Text = L"Юр. лицо";
			this->button_company->UseVisualStyleBackColor = true;
			this->button_company->CheckedChanged += gcnew System::EventHandler(this, &Registration::pick_as_company);
			// 
			// registration_individual
			// 
			this->registration_individual->Controls->Add(this->input_phone_number_body);
			this->registration_individual->Controls->Add(this->input_country_code);
			this->registration_individual->Controls->Add(this->input_carrier_code);
			this->registration_individual->Controls->Add(this->label_phone);
			this->registration_individual->Controls->Add(this->label_if_you_have_patronym);
			this->registration_individual->Controls->Add(this->label_patronym);
			this->registration_individual->Controls->Add(this->group_contacts);
			this->registration_individual->Controls->Add(this->input_patronym);
			this->registration_individual->Controls->Add(this->label_surname);
			this->registration_individual->Controls->Add(this->input_surname);
			this->registration_individual->Controls->Add(this->label_name);
			this->registration_individual->Controls->Add(this->input_name);
			this->registration_individual->Enabled = false;
			this->registration_individual->Location = System::Drawing::Point(50, 142);
			this->registration_individual->Name = L"registration_individual";
			this->registration_individual->Size = System::Drawing::Size(404, 278);
			this->registration_individual->TabIndex = 0;
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
			this->input_phone_number_body->TabIndex = 4;
			this->input_phone_number_body->TabStop = false;
			this->input_phone_number_body->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_phone_number_body->TextChanged += gcnew System::EventHandler(this, &Registration::on_phone_number_body_input);
			this->input_phone_number_body->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_digits);
			// 
			// input_country_code
			// 
			this->input_country_code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_country_code->Location = System::Drawing::Point(184, 145);
			this->input_country_code->Name = L"input_country_code";
			this->input_country_code->ReadOnly = true;
			this->input_country_code->Size = System::Drawing::Size(38, 26);
			this->input_country_code->TabIndex = 1000;
			this->input_country_code->TabStop = false;
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
			this->input_carrier_code->TabIndex = 3;
			this->input_carrier_code->TabStop = false;
			this->input_carrier_code->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_carrier_code->TextChanged += gcnew System::EventHandler(this, &Registration::on_carrier_code_input);
			this->input_carrier_code->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_digits);
			// 
			// label_phone
			// 
			this->label_phone->AutoSize = true;
			this->label_phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_phone->Location = System::Drawing::Point(22, 148);
			this->label_phone->Name = L"label_phone";
			this->label_phone->Size = System::Drawing::Size(160, 20);
			this->label_phone->TabIndex = 1000;
			this->label_phone->Text = L"Номер телефона:";
			// 
			// label_if_you_have_patronym
			// 
			this->label_if_you_have_patronym->AutoSize = true;
			this->label_if_you_have_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_if_you_have_patronym->Location = System::Drawing::Point(200, 115);
			this->label_if_you_have_patronym->Name = L"label_if_you_have_patronym";
			this->label_if_you_have_patronym->Size = System::Drawing::Size(102, 17);
			this->label_if_you_have_patronym->TabIndex = 1000;
			this->label_if_you_have_patronym->Text = L"(при наличии)";
			// 
			// label_patronym
			// 
			this->label_patronym->AutoSize = true;
			this->label_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_patronym->Location = System::Drawing::Point(16, 85);
			this->label_patronym->Name = L"label_patronym";
			this->label_patronym->Size = System::Drawing::Size(96, 20);
			this->label_patronym->TabIndex = 1000;
			this->label_patronym->Text = L"Отчество:";
			// 
			// group_contacts
			// 
			this->group_contacts->Controls->Add(this->label_if_you_have_extra);
			this->group_contacts->Controls->Add(this->input_extra);
			this->group_contacts->Controls->Add(this->label_extra);
			this->group_contacts->Controls->Add(this->label_if_you_have_email);
			this->group_contacts->Controls->Add(this->input_email);
			this->group_contacts->Controls->Add(this->label_email);
			this->group_contacts->Location = System::Drawing::Point(0, 131);
			this->group_contacts->Name = L"group_contacts";
			this->group_contacts->Size = System::Drawing::Size(404, 147);
			this->group_contacts->TabIndex = 3;
			this->group_contacts->TabStop = false;
			this->group_contacts->Text = L"Контакты";
			// 
			// label_if_you_have_extra
			// 
			this->label_if_you_have_extra->AutoSize = true;
			this->label_if_you_have_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_if_you_have_extra->Location = System::Drawing::Point(200, 124);
			this->label_if_you_have_extra->Name = L"label_if_you_have_extra";
			this->label_if_you_have_extra->Size = System::Drawing::Size(102, 17);
			this->label_if_you_have_extra->TabIndex = 1000;
			this->label_if_you_have_extra->Text = L"(при наличии)";
			// 
			// input_extra
			// 
			this->input_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_extra->Location = System::Drawing::Point(169, 95);
			this->input_extra->MaxLength = 50;
			this->input_extra->Name = L"input_extra";
			this->input_extra->Size = System::Drawing::Size(219, 26);
			this->input_extra->TabIndex = 6;
			this->input_extra->TabStop = false;
			this->input_extra->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_extra->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_individual_registration_check);
			this->input_extra->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::keyboard_focus_switch_check);
			// 
			// label_extra
			// 
			this->label_extra->AutoSize = true;
			this->label_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_extra->Location = System::Drawing::Point(22, 98);
			this->label_extra->Name = L"label_extra";
			this->label_extra->Size = System::Drawing::Size(147, 20);
			this->label_extra->TabIndex = 1000;
			this->label_extra->Text = L"Дополнительно:";
			// 
			// label_if_you_have_email
			// 
			this->label_if_you_have_email->AutoSize = true;
			this->label_if_you_have_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_if_you_have_email->Location = System::Drawing::Point(200, 75);
			this->label_if_you_have_email->Name = L"label_if_you_have_email";
			this->label_if_you_have_email->Size = System::Drawing::Size(102, 17);
			this->label_if_you_have_email->TabIndex = 1000;
			this->label_if_you_have_email->Text = L"(при наличии)";
			// 
			// input_email
			// 
			this->input_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_email->Location = System::Drawing::Point(124, 46);
			this->input_email->MaxLength = 254;
			this->input_email->Name = L"input_email";
			this->input_email->Size = System::Drawing::Size(264, 26);
			this->input_email->TabIndex = 5;
			this->input_email->TabStop = false;
			this->input_email->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_email->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::keyboard_focus_switch_check);
			// 
			// label_email
			// 
			this->label_email->AutoSize = true;
			this->label_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_email->Location = System::Drawing::Point(22, 49);
			this->label_email->Name = L"label_email";
			this->label_email->Size = System::Drawing::Size(96, 20);
			this->label_email->TabIndex = 1000;
			this->label_email->Text = L"Эл. почта:";
			// 
			// input_patronym
			// 
			this->input_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_patronym->Location = System::Drawing::Point(113, 82);
			this->input_patronym->MaxLength = 40;
			this->input_patronym->Name = L"input_patronym";
			this->input_patronym->Size = System::Drawing::Size(275, 26);
			this->input_patronym->TabIndex = 2;
			this->input_patronym->TabStop = false;
			this->input_patronym->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_patronym->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_individual_registration_check);
			this->input_patronym->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_letters);
			// 
			// label_surname
			// 
			this->label_surname->AutoSize = true;
			this->label_surname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_surname->Location = System::Drawing::Point(15, 24);
			this->label_surname->Name = L"label_surname";
			this->label_surname->Size = System::Drawing::Size(92, 20);
			this->label_surname->TabIndex = 1000;
			this->label_surname->Text = L"Фамилия:";
			// 
			// input_surname
			// 
			this->input_surname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_surname->Location = System::Drawing::Point(114, 21);
			this->input_surname->MaxLength = 40;
			this->input_surname->Name = L"input_surname";
			this->input_surname->Size = System::Drawing::Size(274, 26);
			this->input_surname->TabIndex = 0;
			this->input_surname->TabStop = false;
			this->input_surname->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_surname->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_individual_registration_check);
			this->input_surname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_letters);
			this->input_surname->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name->Location = System::Drawing::Point(16, 53);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(47, 20);
			this->label_name->TabIndex = 1000;
			this->label_name->Text = L"Имя:";
			// 
			// input_name
			// 
			this->input_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_name->Location = System::Drawing::Point(113, 50);
			this->input_name->MaxLength = 40;
			this->input_name->Name = L"input_name";
			this->input_name->Size = System::Drawing::Size(275, 26);
			this->input_name->TabIndex = 1;
			this->input_name->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_name->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_individual_registration_check);
			this->input_name->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_letters);
			// 
			// registration_company
			// 
			this->registration_company->Controls->Add(this->textBox1);
			this->registration_company->Controls->Add(this->textBox2);
			this->registration_company->Controls->Add(this->textBox3);
			this->registration_company->Controls->Add(this->label1);
			this->registration_company->Controls->Add(this->label2);
			this->registration_company->Controls->Add(this->groupBox2);
			this->registration_company->Controls->Add(this->label9);
			this->registration_company->Controls->Add(this->textBox8);
			this->registration_company->Location = System::Drawing::Point(50, 142);
			this->registration_company->Name = L"registration_company";
			this->registration_company->Size = System::Drawing::Size(404, 278);
			this->registration_company->TabIndex = 1001;
			this->registration_company->TabStop = false;
			this->registration_company->Text = L"Данные компании";
			this->registration_company->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(279, 145);
			this->textBox1->MaxLength = 9;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(90, 26);
			this->textBox1->TabIndex = 4;
			this->textBox1->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(184, 145);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(38, 26);
			this->textBox2->TabIndex = 1000;
			this->textBox2->TabStop = false;
			this->textBox2->Text = L"+7";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(228, 145);
			this->textBox3->MaxLength = 5;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(45, 26);
			this->textBox3->TabIndex = 3;
			this->textBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(22, 148);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 20);
			this->label1->TabIndex = 1000;
			this->label1->Text = L"Номер телефона:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(200, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 17);
			this->label2->TabIndex = 1000;
			this->label2->Text = L"(при наличии)";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Location = System::Drawing::Point(0, 131);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(404, 147);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Контакты";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(200, 124);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 17);
			this->label4->TabIndex = 1000;
			this->label4->Text = L"(при наличии)";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(169, 95);
			this->textBox4->MaxLength = 50;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(219, 26);
			this->textBox4->TabIndex = 6;
			this->textBox4->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(22, 98);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(147, 20);
			this->label5->TabIndex = 1000;
			this->label5->Text = L"Дополнительно:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(200, 75);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 17);
			this->label6->TabIndex = 1000;
			this->label6->Text = L"(при наличии)";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(124, 46);
			this->textBox5->MaxLength = 254;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(264, 26);
			this->textBox5->TabIndex = 5;
			this->textBox5->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(22, 49);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 20);
			this->label7->TabIndex = 1000;
			this->label7->Text = L"Эл. почта:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(16, 24);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(47, 20);
			this->label9->TabIndex = 1000;
			this->label9->Text = L"Имя:";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(113, 21);
			this->textBox8->MaxLength = 20;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(275, 26);
			this->textBox8->TabIndex = 0;
			// 
			// button_register
			// 
			this->button_register->Enabled = false;
			this->button_register->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_register->Location = System::Drawing::Point(145, 426);
			this->button_register->Name = L"button_register";
			this->button_register->Size = System::Drawing::Size(220, 35);
			this->button_register->TabIndex = 100;
			this->button_register->Text = L"Зарегистрироваться";
			this->button_register->UseVisualStyleBackColor = true;
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 468);
			this->Controls->Add(this->button_register);
			this->Controls->Add(this->registration_individual);
			this->Controls->Add(this->button_company);
			this->Controls->Add(this->button_individual);
			this->Controls->Add(this->label_no_account);
			this->Controls->Add(this->label_kalimera);
			this->Controls->Add(this->label_registration);
			this->Controls->Add(this->registration_company);
			this->Name = L"Registration";
			this->Text = L"Регистрация";
			this->registration_individual->ResumeLayout(false);
			this->registration_individual->PerformLayout();
			this->group_contacts->ResumeLayout(false);
			this->group_contacts->PerformLayout();
			this->registration_company->ResumeLayout(false);
			this->registration_company->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion

private:

	System::Void pick_as_individual(System::Object^ sender, System::EventArgs^ e)
	{
		get_focusable_nodes_individual();
		MAX_FOCUS = _MAX_FOCUS_INDIVIDUAL;
		registration_individual->Enabled = true;
		registration_individual->Show();

		registration_company->Enabled = false;
		registration_company->Hide();
		sufficient_input_for_individual_registration_check(nullptr, nullptr);
	}


	System::Void pick_as_company(System::Object^ sender, System::EventArgs^ e)
	{
		registration_company->Enabled = true;
		registration_company->Show();

		registration_individual->Enabled = false;
		registration_individual->Hide();
	}


	void set_greeting_time_based()
	{
		int time = get_time();
		if (time < 40000)
			label_kalimera->Text += "ый вечер!";
		else if (time < 120000)
			label_kalimera->Text += "ое утро!";
		else if (time < 170000)
			label_kalimera->Text += "ый день!";
		else
			label_kalimera->Text += "ый вечер!";
	}


	#pragma region = Focus (Common) =

	int focus = 0;
	int MAX_FOCUS;
	array<Control^>^ FOCUSABLE_NODES = gcnew array<Control^>(7);

	
	void next_focus()
	{
		if (++focus > MAX_FOCUS) focus = 0;
		FOCUSABLE_NODES[focus]->Focus();
	}


	void prev_focus()
	{
		if (--focus < 0) focus = MAX_FOCUS;
		FOCUSABLE_NODES[focus]->Focus();
	}


	System::Void keyboard_focus_switch_check(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		System::Char key = e->KeyChar;
		if (key == ENTER)
			next_focus();
		else if (key == BACKSPACE)
		{
			Control^ source = safe_cast<Control^>(sender);
			if (source->Text == "")
				prev_focus();
		}
	}


	System::Void mouse_focus_switch_check(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		Control^ source = safe_cast<Control^>(sender);
		focus = source->TabIndex;
	}

	#pragma endregion


	#pragma region = Input limiting (Common) =

	System::Void only_digits(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		System::Char key = e->KeyChar;
		if (! is_digit(key))
			e->Handled = true;
		keyboard_focus_switch_check(sender, e);
	}


	System::Void only_letters(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		System::Char key = e->KeyChar;
		if (! is_letter(key))
			e->Handled = true;
		keyboard_focus_switch_check(sender, e);
	}

	#pragma endregion


	#pragma region = Input (Individual) =

	// TODO: Get it into utils?
	const int _MAX_FOCUS_INDIVIDUAL = 6;
	void get_focusable_nodes_individual()
	{
		/// Why am I writing such a shitty code?
		/// Take a wild fucking guess.
		/// .NET doesn't allow me to create a constant array in-place, instead forcing me to do... this
		/// DOTNET SUCKS BALLS
		FOCUSABLE_NODES[0] = input_surname;
		FOCUSABLE_NODES[1] = input_name;
		FOCUSABLE_NODES[2] = input_patronym;

		FOCUSABLE_NODES[3] = input_carrier_code;
		FOCUSABLE_NODES[4] = input_phone_number_body;

		FOCUSABLE_NODES[5] = input_email;
		FOCUSABLE_NODES[6] = input_extra;
	}


	System::Void sufficient_input_for_individual_registration_check(System::Object^ sender, System::EventArgs^ e)
	{
		button_register->Enabled =
		   (input_surname->Text->Length  >= 2 &&
			input_name->Text->Length     >= 2 &&

			input_carrier_code->Text->Length	  == 5 &&
			input_phone_number_body->Text->Length == 9);
	}


	int _carrier_code_previous_length = 0;
	System::Void on_carrier_code_input(System::Object^ sender, System::EventArgs^ e)
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
			next_focus();
		}

		_carrier_code_previous_length = input_carrier_code->Text->Length;
		sufficient_input_for_individual_registration_check(nullptr, nullptr);
	}


	int _phone_number_body_previous_length = 0;
	System::Void on_phone_number_body_input(System::Object^ sender, System::EventArgs^ e)
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

		// Focusing on next
		else if (input_phone_number_body->Text->Length == 9)
			next_focus();

		_phone_number_body_previous_length = input_phone_number_body->Text->Length;
		sufficient_input_for_individual_registration_check(nullptr, nullptr);
	}

	#pragma endregion
};
}

#endif