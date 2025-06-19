#pragma once
#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include "Classes/listing.hpp"
#include "Classes/user.hpp"
#include   "../../save_load.hpp"

#include <string>
#include <vector>


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
		Registration(User* user)
		{
			InitializeComponent();
			pick_as_individual(nullptr, nullptr);

			if (user == nullptr) // fresh user
			{
				set_greeting_time_based();
				return;
			}

			/// = Re-registration =
			
			this->Text = "Редактирование данных аккаунта";
			label_registration->Text = "Редактирование";
			label_kalimera->Text =	   "Изменение данных.";
			label_no_account->Text =   "Текущие данные вашего аккаунта введены.";

			std::vector<std::wstring> name = user->name->as_vector();
			if (typeid(*user) == typeid(Individual))
			{
				button_individual->Select();
				pick_as_individual(nullptr, nullptr);

				this->input_surname->Text  = to_dotnet_string(name[0]);
				this->input_name->Text =	 to_dotnet_string(name[1]);
				this->input_patronym->Text = to_dotnet_string(name[2]);
			}
			else if (typeid(*user) == typeid(Company))
			{
				button_company->Select();
				pick_as_company(nullptr, nullptr);
				
				this->input_legal_form->SelectedItem = to_dotnet_string(name[0]);
				this->input_company_name->Text = to_dotnet_string(name[1]);
				
				this->input_website->Text = to_dotnet_string(user->website);
			}
			else
			{
				MessageBox::Show("Type error: couldn't resolve user's account type");
				this->Close();
			}

			/// = Common between both account types =
			std::vector<std::wstring> phone = separate(user->phone_number.as_text());
			this->input_country_code->Text = to_dotnet_string(phone[0]);
			this->input_carrier_code->Text = to_dotnet_string(phone[1]);
			this->input_phone_number_body->Text = to_dotnet_string(phone[2]);

			this->input_email->Text = to_dotnet_string(user->email);
			this->input_extra->Text = to_dotnet_string(user->extra_contacts);
		}

    #pragma region ========== WinForms code ==========

	protected:
		~Registration()
		{
			if (components)
				delete components;
		}

	private: System::Windows::Forms::Label^ label_registration;
	private: System::Windows::Forms::Label^ label_kalimera;
	private: System::Windows::Forms::Label^ label_no_account;
	private: System::Windows::Forms::RadioButton^ button_individual;
	private: System::Windows::Forms::RadioButton^ button_company;


	private: System::Windows::Forms::GroupBox^ registration_individual;



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
	private: System::Windows::Forms::GroupBox^ contacts;





	private: System::Windows::Forms::Label^ label_email;
	private: System::Windows::Forms::TextBox^ input_email;

	private: System::Windows::Forms::Label^ label_if_you_have_email;
	private: System::Windows::Forms::Label^ label_if_you_have_extra;

	private: System::Windows::Forms::TextBox^ input_extra;

	private: System::Windows::Forms::Label^ label_extra;
	private: System::Windows::Forms::GroupBox^ registration_company;














	private: System::Windows::Forms::Label^ label_company_name;
	private: System::Windows::Forms::TextBox^ input_company_name;


	private: System::Windows::Forms::Button^ button_register;
	private: System::Windows::Forms::ComboBox^ input_legal_form;






	private: System::Windows::Forms::Label^ label_website;

	private: System::Windows::Forms::Label^ label_est;
	private: System::Windows::Forms::TextBox^ input_website;





	private: System::Windows::Forms::Label^ label_month;
	private: System::Windows::Forms::Label^ label_year;
	private: System::Windows::Forms::TextBox^ input_name;
private: System::Windows::Forms::TextBox^ input_ind_day;



private: System::Windows::Forms::Label^ label_birthdate;

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::TextBox^ input_ind_year;


private: System::Windows::Forms::Label^ label_y;
private: System::Windows::Forms::TextBox^ input_year;
private: System::Windows::Forms::ComboBox^ input_month;
private: System::Windows::Forms::ComboBox^ input_ind_month;












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
			this->input_ind_month = (gcnew System::Windows::Forms::ComboBox());
			this->input_ind_day = (gcnew System::Windows::Forms::TextBox());
			this->label_birthdate = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->input_ind_year = (gcnew System::Windows::Forms::TextBox());
			this->input_name = (gcnew System::Windows::Forms::TextBox());
			this->label_if_you_have_patronym = (gcnew System::Windows::Forms::Label());
			this->label_patronym = (gcnew System::Windows::Forms::Label());
			this->input_patronym = (gcnew System::Windows::Forms::TextBox());
			this->label_surname = (gcnew System::Windows::Forms::Label());
			this->input_surname = (gcnew System::Windows::Forms::TextBox());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->input_phone_number_body = (gcnew System::Windows::Forms::TextBox());
			this->input_country_code = (gcnew System::Windows::Forms::TextBox());
			this->input_carrier_code = (gcnew System::Windows::Forms::TextBox());
			this->label_phone = (gcnew System::Windows::Forms::Label());
			this->contacts = (gcnew System::Windows::Forms::GroupBox());
			this->label_if_you_have_extra = (gcnew System::Windows::Forms::Label());
			this->input_extra = (gcnew System::Windows::Forms::TextBox());
			this->label_extra = (gcnew System::Windows::Forms::Label());
			this->label_if_you_have_email = (gcnew System::Windows::Forms::Label());
			this->input_email = (gcnew System::Windows::Forms::TextBox());
			this->label_email = (gcnew System::Windows::Forms::Label());
			this->registration_company = (gcnew System::Windows::Forms::GroupBox());
			this->label_year = (gcnew System::Windows::Forms::Label());
			this->label_month = (gcnew System::Windows::Forms::Label());
			this->input_website = (gcnew System::Windows::Forms::TextBox());
			this->label_y = (gcnew System::Windows::Forms::Label());
			this->input_year = (gcnew System::Windows::Forms::TextBox());
			this->input_month = (gcnew System::Windows::Forms::ComboBox());
			this->label_website = (gcnew System::Windows::Forms::Label());
			this->label_est = (gcnew System::Windows::Forms::Label());
			this->input_legal_form = (gcnew System::Windows::Forms::ComboBox());
			this->label_company_name = (gcnew System::Windows::Forms::Label());
			this->input_company_name = (gcnew System::Windows::Forms::TextBox());
			this->button_register = (gcnew System::Windows::Forms::Button());
			this->registration_individual->SuspendLayout();
			this->contacts->SuspendLayout();
			this->registration_company->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_registration
			// 
			this->label_registration->AutoSize = true;
			this->label_registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_registration->Location = System::Drawing::Point(186, 9);
			this->label_registration->Name = L"label_registration";
			this->label_registration->Size = System::Drawing::Size(185, 31);
			this->label_registration->TabIndex = 1000;
			this->label_registration->Text = L"Регистрация";
			this->label_registration->TextChanged += gcnew System::EventHandler(this, &Registration::center_x);
			// 
			// label_kalimera
			// 
			this->label_kalimera->AutoSize = true;
			this->label_kalimera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_kalimera->Location = System::Drawing::Point(187, 51);
			this->label_kalimera->Name = L"label_kalimera";
			this->label_kalimera->Size = System::Drawing::Size(62, 25);
			this->label_kalimera->TabIndex = 1000;
			this->label_kalimera->Text = L"Добр";
			this->label_kalimera->TextChanged += gcnew System::EventHandler(this, &Registration::center_x);
			// 
			// label_no_account
			// 
			this->label_no_account->AutoSize = true;
			this->label_no_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_no_account->Location = System::Drawing::Point(57, 84);
			this->label_no_account->Name = L"label_no_account";
			this->label_no_account->Size = System::Drawing::Size(456, 25);
			this->label_no_account->TabIndex = 1000;
			this->label_no_account->Text = L"Ваш аккаунт не был обнаружен в системе. Вы...";
			this->label_no_account->TextChanged += gcnew System::EventHandler(this, &Registration::center_x);
			// 
			// button_individual
			// 
			this->button_individual->AutoSize = true;
			this->button_individual->Checked = true;
			this->button_individual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_individual->Location = System::Drawing::Point(133, 115);
			this->button_individual->Name = L"button_individual";
			this->button_individual->Size = System::Drawing::Size(130, 29);
			this->button_individual->TabIndex = 7;
			this->button_individual->TabStop = true;
			this->button_individual->Text = L"Физ. лицо";
			this->button_individual->UseVisualStyleBackColor = true;
			this->button_individual->CheckedChanged += gcnew System::EventHandler(this, &Registration::pick_as_individual);
			// 
			// button_company
			// 
			this->button_company->AutoSize = true;
			this->button_company->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_company->Location = System::Drawing::Point(341, 115);
			this->button_company->Name = L"button_company";
			this->button_company->Size = System::Drawing::Size(119, 29);
			this->button_company->TabIndex = 8;
			this->button_company->Text = L"Юр. лицо";
			this->button_company->UseVisualStyleBackColor = true;
			this->button_company->CheckedChanged += gcnew System::EventHandler(this, &Registration::pick_as_company);
			// 
			// registration_individual
			// 
			this->registration_individual->Controls->Add(this->input_ind_month);
			this->registration_individual->Controls->Add(this->input_ind_day);
			this->registration_individual->Controls->Add(this->label_birthdate);
			this->registration_individual->Controls->Add(this->label1);
			this->registration_individual->Controls->Add(this->input_ind_year);
			this->registration_individual->Controls->Add(this->input_name);
			this->registration_individual->Controls->Add(this->label_if_you_have_patronym);
			this->registration_individual->Controls->Add(this->label_patronym);
			this->registration_individual->Controls->Add(this->input_patronym);
			this->registration_individual->Controls->Add(this->label_surname);
			this->registration_individual->Controls->Add(this->input_surname);
			this->registration_individual->Controls->Add(this->label_name);
			this->registration_individual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->registration_individual->Location = System::Drawing::Point(45, 150);
			this->registration_individual->Name = L"registration_individual";
			this->registration_individual->Size = System::Drawing::Size(468, 183);
			this->registration_individual->TabIndex = 0;
			this->registration_individual->TabStop = false;
			this->registration_individual->Text = L"ФИО";
			// 
			// input_ind_month
			// 
			this->input_ind_month->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Append;
			this->input_ind_month->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->input_ind_month->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_ind_month->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_ind_month->FormattingEnabled = true;
			this->input_ind_month->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"января", L"февраля", L"марта", L"апреля",
					L"мая", L"июня", L"июля", L"августа", L"сентября", L"октября", L"ноября", L"декабря"
			});
			this->input_ind_month->Location = System::Drawing::Point(243, 146);
			this->input_ind_month->MaxLength = 4;
			this->input_ind_month->Name = L"input_ind_month";
			this->input_ind_month->Size = System::Drawing::Size(97, 28);
			this->input_ind_month->TabIndex = 1012;
			// 
			// input_ind_day
			// 
			this->input_ind_day->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_ind_day->Location = System::Drawing::Point(189, 145);
			this->input_ind_day->MaxLength = 2;
			this->input_ind_day->Name = L"input_ind_day";
			this->input_ind_day->Size = System::Drawing::Size(48, 30);
			this->input_ind_day->TabIndex = 1011;
			// 
			// label_birthdate
			// 
			this->label_birthdate->AutoSize = true;
			this->label_birthdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_birthdate->Location = System::Drawing::Point(16, 147);
			this->label_birthdate->Name = L"label_birthdate";
			this->label_birthdate->Size = System::Drawing::Size(167, 25);
			this->label_birthdate->TabIndex = 1010;
			this->label_birthdate->Text = L"Дата рождения:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(426, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 25);
			this->label1->TabIndex = 1009;
			this->label1->Text = L"г.";
			// 
			// input_ind_year
			// 
			this->input_ind_year->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_ind_year->Location = System::Drawing::Point(346, 145);
			this->input_ind_year->MaxLength = 4;
			this->input_ind_year->Name = L"input_ind_year";
			this->input_ind_year->Size = System::Drawing::Size(74, 30);
			this->input_ind_year->TabIndex = 1007;
			// 
			// input_name
			// 
			this->input_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_name->Location = System::Drawing::Point(132, 57);
			this->input_name->MaxLength = 40;
			this->input_name->Name = L"input_name";
			this->input_name->Size = System::Drawing::Size(320, 30);
			this->input_name->TabIndex = 1001;
			this->input_name->TabStop = false;
			this->input_name->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_name->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_individual_registration_check);
			this->input_name->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_letters);
			// 
			// label_if_you_have_patronym
			// 
			this->label_if_you_have_patronym->AutoSize = true;
			this->label_if_you_have_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_if_you_have_patronym->Location = System::Drawing::Point(240, 126);
			this->label_if_you_have_patronym->Name = L"label_if_you_have_patronym";
			this->label_if_you_have_patronym->Size = System::Drawing::Size(102, 17);
			this->label_if_you_have_patronym->TabIndex = 1000;
			this->label_if_you_have_patronym->Text = L"(при наличии)";
			// 
			// label_patronym
			// 
			this->label_patronym->AutoSize = true;
			this->label_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_patronym->Location = System::Drawing::Point(16, 96);
			this->label_patronym->Name = L"label_patronym";
			this->label_patronym->Size = System::Drawing::Size(110, 25);
			this->label_patronym->TabIndex = 1000;
			this->label_patronym->Text = L"Отчество:";
			// 
			// input_patronym
			// 
			this->input_patronym->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_patronym->Location = System::Drawing::Point(132, 93);
			this->input_patronym->MaxLength = 40;
			this->input_patronym->Name = L"input_patronym";
			this->input_patronym->Size = System::Drawing::Size(319, 30);
			this->input_patronym->TabIndex = 2;
			this->input_patronym->TabStop = false;
			this->input_patronym->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_patronym->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_individual_registration_check);
			this->input_patronym->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_letters);
			// 
			// label_surname
			// 
			this->label_surname->AutoSize = true;
			this->label_surname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_surname->Location = System::Drawing::Point(16, 24);
			this->label_surname->Name = L"label_surname";
			this->label_surname->Size = System::Drawing::Size(109, 25);
			this->label_surname->TabIndex = 1000;
			this->label_surname->Text = L"Фамилия:";
			// 
			// input_surname
			// 
			this->input_surname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_surname->Location = System::Drawing::Point(132, 21);
			this->input_surname->MaxLength = 40;
			this->input_surname->Name = L"input_surname";
			this->input_surname->Size = System::Drawing::Size(319, 30);
			this->input_surname->TabIndex = 0;
			this->input_surname->TabStop = false;
			this->input_surname->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_surname->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_individual_registration_check);
			this->input_surname->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_letters);
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name->Location = System::Drawing::Point(16, 60);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(60, 25);
			this->label_name->TabIndex = 1000;
			this->label_name->Text = L"Имя:";
			// 
			// input_phone_number_body
			// 
			this->input_phone_number_body->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->input_phone_number_body->Location = System::Drawing::Point(346, 25);
			this->input_phone_number_body->MaxLength = 9;
			this->input_phone_number_body->Name = L"input_phone_number_body";
			this->input_phone_number_body->Size = System::Drawing::Size(111, 30);
			this->input_phone_number_body->TabIndex = 4;
			this->input_phone_number_body->TabStop = false;
			this->input_phone_number_body->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_phone_number_body->TextChanged += gcnew System::EventHandler(this, &Registration::on_phone_number_body_input);
			this->input_phone_number_body->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_digits);
			this->input_phone_number_body->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// input_country_code
			// 
			this->input_country_code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_country_code->Location = System::Drawing::Point(239, 25);
			this->input_country_code->Name = L"input_country_code";
			this->input_country_code->ReadOnly = true;
			this->input_country_code->Size = System::Drawing::Size(38, 30);
			this->input_country_code->TabIndex = 1000;
			this->input_country_code->TabStop = false;
			this->input_country_code->Text = L"+7";
			// 
			// input_carrier_code
			// 
			this->input_carrier_code->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_carrier_code->Location = System::Drawing::Point(283, 25);
			this->input_carrier_code->MaxLength = 5;
			this->input_carrier_code->Name = L"input_carrier_code";
			this->input_carrier_code->Size = System::Drawing::Size(59, 30);
			this->input_carrier_code->TabIndex = 3;
			this->input_carrier_code->TabStop = false;
			this->input_carrier_code->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_carrier_code->TextChanged += gcnew System::EventHandler(this, &Registration::on_carrier_code_input);
			this->input_carrier_code->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_digits);
			this->input_carrier_code->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// label_phone
			// 
			this->label_phone->AutoSize = true;
			this->label_phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_phone->Location = System::Drawing::Point(16, 28);
			this->label_phone->Name = L"label_phone";
			this->label_phone->Size = System::Drawing::Size(183, 25);
			this->label_phone->TabIndex = 1000;
			this->label_phone->Text = L"Номер телефона:";
			// 
			// contacts
			// 
			this->contacts->Controls->Add(this->input_phone_number_body);
			this->contacts->Controls->Add(this->label_if_you_have_extra);
			this->contacts->Controls->Add(this->input_carrier_code);
			this->contacts->Controls->Add(this->input_country_code);
			this->contacts->Controls->Add(this->input_extra);
			this->contacts->Controls->Add(this->label_extra);
			this->contacts->Controls->Add(this->label_phone);
			this->contacts->Controls->Add(this->label_if_you_have_email);
			this->contacts->Controls->Add(this->input_email);
			this->contacts->Controls->Add(this->label_email);
			this->contacts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->contacts->Location = System::Drawing::Point(45, 339);
			this->contacts->Name = L"contacts";
			this->contacts->Size = System::Drawing::Size(468, 153);
			this->contacts->TabIndex = 3;
			this->contacts->TabStop = false;
			this->contacts->Text = L"Контакты";
			// 
			// label_if_you_have_extra
			// 
			this->label_if_you_have_extra->AutoSize = true;
			this->label_if_you_have_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_if_you_have_extra->Location = System::Drawing::Point(18, 126);
			this->label_if_you_have_extra->Name = L"label_if_you_have_extra";
			this->label_if_you_have_extra->Size = System::Drawing::Size(102, 17);
			this->label_if_you_have_extra->TabIndex = 1000;
			this->label_if_you_have_extra->Text = L"(при наличии)";
			// 
			// input_extra
			// 
			this->input_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_extra->Location = System::Drawing::Point(191, 97);
			this->input_extra->MaxLength = 50;
			this->input_extra->Name = L"input_extra";
			this->input_extra->Size = System::Drawing::Size(266, 30);
			this->input_extra->TabIndex = 6;
			this->input_extra->TabStop = false;
			this->input_extra->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_extra->TextChanged += gcnew System::EventHandler(this, &Registration::common_contacts_sufficient_input_check);
			this->input_extra->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::keyboard_focus_switch_check);
			this->input_extra->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// label_extra
			// 
			this->label_extra->AutoSize = true;
			this->label_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_extra->Location = System::Drawing::Point(16, 101);
			this->label_extra->Name = L"label_extra";
			this->label_extra->Size = System::Drawing::Size(169, 25);
			this->label_extra->TabIndex = 1000;
			this->label_extra->Text = L"Дополнительно:";
			// 
			// label_if_you_have_email
			// 
			this->label_if_you_have_email->AutoSize = true;
			this->label_if_you_have_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_if_you_have_email->Location = System::Drawing::Point(18, 84);
			this->label_if_you_have_email->Name = L"label_if_you_have_email";
			this->label_if_you_have_email->Size = System::Drawing::Size(102, 17);
			this->label_if_you_have_email->TabIndex = 1000;
			this->label_if_you_have_email->Text = L"(при наличии)";
			// 
			// input_email
			// 
			this->input_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_email->Location = System::Drawing::Point(126, 61);
			this->input_email->MaxLength = 254;
			this->input_email->Name = L"input_email";
			this->input_email->Size = System::Drawing::Size(331, 30);
			this->input_email->TabIndex = 5;
			this->input_email->TabStop = false;
			this->input_email->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_email->TextChanged += gcnew System::EventHandler(this, &Registration::common_contacts_sufficient_input_check);
			this->input_email->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::keyboard_focus_switch_check);
			this->input_email->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// label_email
			// 
			this->label_email->AutoSize = true;
			this->label_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_email->Location = System::Drawing::Point(16, 64);
			this->label_email->Name = L"label_email";
			this->label_email->Size = System::Drawing::Size(109, 25);
			this->label_email->TabIndex = 1000;
			this->label_email->Text = L"Эл. почта:";
			// 
			// registration_company
			// 
			this->registration_company->Controls->Add(this->label_year);
			this->registration_company->Controls->Add(this->label_month);
			this->registration_company->Controls->Add(this->input_website);
			this->registration_company->Controls->Add(this->label_y);
			this->registration_company->Controls->Add(this->input_year);
			this->registration_company->Controls->Add(this->input_month);
			this->registration_company->Controls->Add(this->label_website);
			this->registration_company->Controls->Add(this->label_est);
			this->registration_company->Controls->Add(this->input_legal_form);
			this->registration_company->Controls->Add(this->label_company_name);
			this->registration_company->Controls->Add(this->input_company_name);
			this->registration_company->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->registration_company->Location = System::Drawing::Point(547, 286);
			this->registration_company->Name = L"registration_company";
			this->registration_company->Size = System::Drawing::Size(404, 139);
			this->registration_company->TabIndex = 1001;
			this->registration_company->TabStop = false;
			this->registration_company->Text = L"Данные компании";
			// 
			// label_year
			// 
			this->label_year->AutoSize = true;
			this->label_year->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_year->Location = System::Drawing::Point(265, 85);
			this->label_year->Name = L"label_year";
			this->label_year->Size = System::Drawing::Size(37, 17);
			this->label_year->TabIndex = 1009;
			this->label_year->Text = L"года";
			// 
			// label_month
			// 
			this->label_month->AutoSize = true;
			this->label_month->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_month->Location = System::Drawing::Point(150, 85);
			this->label_month->Name = L"label_month";
			this->label_month->Size = System::Drawing::Size(56, 17);
			this->label_month->TabIndex = 1008;
			this->label_month->Text = L"месяца";
			// 
			// input_website
			// 
			this->input_website->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_website->Location = System::Drawing::Point(69, 106);
			this->input_website->Name = L"input_website";
			this->input_website->Size = System::Drawing::Size(319, 26);
			this->input_website->TabIndex = 2;
			this->input_website->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_website->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_company_registration_check);
			this->input_website->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::keyboard_focus_switch_check);
			this->input_website->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// label_y
			// 
			this->label_y->AutoSize = true;
			this->label_y->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_y->Location = System::Drawing::Point(343, 60);
			this->label_y->Name = L"label_y";
			this->label_y->Size = System::Drawing::Size(21, 20);
			this->label_y->TabIndex = 1006;
			this->label_y->Text = L"г.";
			// 
			// input_year
			// 
			this->input_year->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_year->Location = System::Drawing::Point(239, 57);
			this->input_year->MaxLength = 4;
			this->input_year->Name = L"input_year";
			this->input_year->Size = System::Drawing::Size(89, 26);
			this->input_year->TabIndex = 1;
			this->input_year->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_year->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_company_registration_check);
			this->input_year->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_digits);
			this->input_year->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// input_month
			// 
			this->input_month->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Append;
			this->input_month->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->input_month->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_month->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_month->FormattingEnabled = true;
			this->input_month->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"января", L"февраля", L"марта", L"апреля", L"мая",
					L"июня", L"июля", L"августа", L"сентября", L"октября", L"ноября", L"декабря"
			});
			this->input_month->Location = System::Drawing::Point(124, 57);
			this->input_month->MaxLength = 4;
			this->input_month->Name = L"input_month";
			this->input_month->Size = System::Drawing::Size(109, 28);
			this->input_month->TabIndex = 1004;
			this->input_month->SelectedValueChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_company_registration_check);
			this->input_month->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// label_website
			// 
			this->label_website->AutoSize = true;
			this->label_website->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_website->Location = System::Drawing::Point(18, 109);
			this->label_website->Name = L"label_website";
			this->label_website->Size = System::Drawing::Size(56, 20);
			this->label_website->TabIndex = 1003;
			this->label_website->Text = L"Сайт:";
			// 
			// label_est
			// 
			this->label_est->AutoSize = true;
			this->label_est->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_est->Location = System::Drawing::Point(18, 60);
			this->label_est->Name = L"label_est";
			this->label_est->Size = System::Drawing::Size(107, 20);
			this->label_est->TabIndex = 1002;
			this->label_est->Text = L"На рынке с:";
			// 
			// input_legal_form
			// 
			this->input_legal_form->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Append;
			this->input_legal_form->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->input_legal_form->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_legal_form->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_legal_form->FormattingEnabled = true;
			this->input_legal_form->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"ИП", L"ПК", L"ГУП", L"МУП", L"НКО", L"ООО",
					L"ПАО", L"НПАО"
			});
			this->input_legal_form->Location = System::Drawing::Point(69, 19);
			this->input_legal_form->MaxLength = 4;
			this->input_legal_form->Name = L"input_legal_form";
			this->input_legal_form->Size = System::Drawing::Size(85, 28);
			this->input_legal_form->TabIndex = 1001;
			this->input_legal_form->SelectedValueChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_company_registration_check);
			this->input_legal_form->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// label_company_name
			// 
			this->label_company_name->AutoSize = true;
			this->label_company_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_company_name->Location = System::Drawing::Point(16, 24);
			this->label_company_name->Name = L"label_company_name";
			this->label_company_name->Size = System::Drawing::Size(47, 20);
			this->label_company_name->TabIndex = 1000;
			this->label_company_name->Text = L"Имя:";
			// 
			// input_company_name
			// 
			this->input_company_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input_company_name->Location = System::Drawing::Point(160, 18);
			this->input_company_name->MaxLength = 20;
			this->input_company_name->Name = L"input_company_name";
			this->input_company_name->Size = System::Drawing::Size(228, 26);
			this->input_company_name->TabIndex = 0;
			this->input_company_name->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			this->input_company_name->TextChanged += gcnew System::EventHandler(this, &Registration::sufficient_input_for_company_registration_check);
			this->input_company_name->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::only_letters);
			this->input_company_name->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Registration::mouse_focus_switch_check);
			// 
			// button_register
			// 
			this->button_register->Enabled = false;
			this->button_register->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_register->Location = System::Drawing::Point(171, 498);
			this->button_register->Name = L"button_register";
			this->button_register->Size = System::Drawing::Size(248, 55);
			this->button_register->TabIndex = 100;
			this->button_register->Text = L"Зарегистрироваться";
			this->button_register->UseVisualStyleBackColor = true;
			this->button_register->Click += gcnew System::EventHandler(this, &Registration::registration);
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 563);
			this->Controls->Add(this->button_register);
			this->Controls->Add(this->button_company);
			this->Controls->Add(this->contacts);
			this->Controls->Add(this->button_individual);
			this->Controls->Add(this->label_no_account);
			this->Controls->Add(this->label_kalimera);
			this->Controls->Add(this->label_registration);
			this->Controls->Add(this->registration_company);
			this->Controls->Add(this->registration_individual);
			this->MaximumSize = System::Drawing::Size(600, 610);
			this->MinimumSize = System::Drawing::Size(600, 610);
			this->Name = L"Registration";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Регистрация";
			this->registration_individual->ResumeLayout(false);
			this->registration_individual->PerformLayout();
			this->contacts->ResumeLayout(false);
			this->contacts->PerformLayout();
			this->registration_company->ResumeLayout(false);
			this->registration_company->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion

private:

	void center_x(System::Object^ sender, System::EventArgs^ e)
	{
		Control^ target = safe_cast<Control^>(sender);
		/// Don't y'all love variables that don't state they're readonly?
		System::Drawing::Size size = TextRenderer::MeasureText(target->Text, target->Font);
		target->Size = size;
		System::Drawing::Point location((this->Width - size.Width) / 2, target->Location.Y);
		target->Location = location;
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


	System::Void registration(System::Object^ sender, System::EventArgs^ e)
	{
		/// Common between 'Individual' and 'Company'.
		std::wstring email = to_std_wstring(input_email->Text);
		std::wstring extra_contacts = to_std_wstring(input_extra->Text);

		std::wstring carrier_code = to_std_wstring(input_carrier_code->Text);
		carrier_code = erase_at(carrier_code, 0); // '('
		carrier_code = erase_at(carrier_code, 3); // ')', taking the previous removal and the resulting shift of positions into account
		std::wstring body = to_std_wstring(input_phone_number_body->Text);
		body = erase_at(body, 3); // '-'
		body = erase_at(body, 5); // '-'

		Phone_Number phone_number(to_std_wstring(input_country_code->Text), carrier_code, body);

		// Saving an individual
		if (button_individual->Checked)
		{
			Individual_Name name(to_std_wstring(input_name->Text), to_std_wstring(input_surname->Text), to_std_wstring(input_patronym->Text));
			Individual new_user(name, phone_number, email, extra_contacts);
			save(&new_user, USER_SAVEFILE_NAME);
			// SETTING USER IN-PROGRAM, NOT READING FILES
		}

		// Saving a company
		else if (button_company->Checked)
		{
			std::wstring website = to_std_wstring(input_website->Text);
			Company_Name name(to_std_wstring(input_legal_form->Text), to_std_wstring(input_company_name->Text));
			Company new_user(name, phone_number, email, website, extra_contacts);
			save(&new_user, USER_SAVEFILE_NAME);
		}

		//user = new_user;
		this->Close();
	}



	#pragma region ========== Individual ==========

	System::Void pick_as_individual(System::Object^ sender, System::EventArgs^ e)
	{
		FOCUSABLE_NODES = focus_params_individual();
		node_manipulations_individual();
		sufficient_input_for_individual_registration_check(nullptr, nullptr);
	}


	array<Control^>^ focus_params_individual()
	{
		/// Why am I writing such a shitty code?
		/// Take a wild fucking guess.
		/// .NET doesn't allow me to create a constant array in-place, instead forcing me to do... *this.*
		/// DOTNET SUCKS BALLS
		
		array<Control^>^ result = gcnew array<Control^>(7);

		result[0] = input_surname;
		result[1] = input_name;
		result[2] = input_patronym;

		result[3] = input_carrier_code;
		result[4] = input_phone_number_body;

		result[5] = input_email;
		result[6] = input_extra;

		MAX_FOCUS = 6;
		focus = 0;
		result[0]->Select();

		return result;
	}


	void node_manipulations_individual()
	{
		label_if_you_have_email->Show();
		registration_individual->BringToFront();
	}
	
	
	System::Void sufficient_input_for_individual_registration_check(System::Object^ sender, System::EventArgs^ e)
	{
		button_register->Enabled = (
			input_surname->Text->Length >= 2 &&
			input_name->Text->Length    >= 2 &&

			input_carrier_code->Text->Length	  == 5 &&
			input_phone_number_body->Text->Length == 9
		);
	}

	#pragma endregion



	#pragma region ========== Company ==========

	System::Void pick_as_company(System::Object^ sender, System::EventArgs^ e)
	{
		FOCUSABLE_NODES = focus_params_company();
		node_manipulations_company();
		sufficient_input_for_company_registration_check(nullptr, nullptr);
	}


	array<Control^>^ focus_params_company()
	{
		array<Control^>^ result = gcnew array<Control^>(9);

		result[0] = input_company_name;

		result[1] = input_year;

		result[2] = input_website;

		result[3] = input_carrier_code;
		result[4] = input_phone_number_body;

		result[5] = input_email;
		result[6] = input_extra;

		MAX_FOCUS = 6;
		focus = 0;
		result[0]->Select();

		return result;
	}


	void node_manipulations_company()
	{
		label_if_you_have_email->Hide();
		registration_company->BringToFront();
	}
	
	
	System::Void sufficient_input_for_company_registration_check(System::Object^ sender, System::EventArgs^ e)
	{
		button_register->Enabled = (
			input_legal_form->SelectedIndex  > -1 &&
			input_company_name->Text->Length > 0  &&

			input_month->SelectedIndex > -1 &&
			input_year->Text->Length == 4   &&

			input_email->Text->Length	> 0 &&
			input_website->Text->Length > 0 &&

			input_carrier_code->Text->Length	  == 5 &&
			input_phone_number_body->Text->Length == 9
		);
	}

	#pragma endregion



	#pragma region ========== Focus (Common) ==========

	int focus = 0;
	int MAX_FOCUS;
	array<Control^>^ FOCUSABLE_NODES;

	
	void next_focus()
	{
		// Focus wrapping had been decided to be disabled.
		if (++focus > MAX_FOCUS) focus = MAX_FOCUS; //0;
		FOCUSABLE_NODES[focus]->Focus();
	}


	void prev_focus()
	{
		// Focus wrapping had been decided to be disabled.
		if (--focus < 0) focus = 0; //MAX_FOCUS;
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



	#pragma region ========== Input limiting (Common) ==========

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



	#pragma region ========== Input (Contacts) ==========

	void common_contacts_sufficient_input_check(System::Object^ sender, System::EventArgs^ e)
	{
		if (button_individual->Checked)
			sufficient_input_for_individual_registration_check(nullptr, nullptr);
		else if (button_company->Checked)
			sufficient_input_for_company_registration_check(nullptr, nullptr);
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
		common_contacts_sufficient_input_check(nullptr, nullptr);
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
		common_contacts_sufficient_input_check(nullptr, nullptr);
	}

	#pragma endregion
};
}

#endif