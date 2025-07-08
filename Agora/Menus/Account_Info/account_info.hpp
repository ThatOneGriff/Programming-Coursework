#pragma once

#include "../../Classes/User.hpp"

namespace Agora {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Account_Info : public System::Windows::Forms::Form
	{
	public:
		Account_Info(User* about, System::String^ heading, const bool contract_made)
		{
			InitializeComponent();
			this->Text = heading;
			
			/// Straightforward.

			name->Text = to_dotnet_string(about->name->get_full());

			/// Things any user type may or may not have.

			if (about->email != L"")
				email->Text = to_dotnet_string(about->email);
			else
			{
				email->Text = L"-";
				email->Enabled = false;
				label_email->Enabled = false;
			}

			if (about->extra_contacts != L"")
				 extra_contacts->Text = to_dotnet_string(about->extra_contacts);
			else
			{
				extra_contacts->Text = L"-";
				extra_contacts->Enabled = false;
				label_extra_contacts->Enabled = false;
			}

			if (about->website != L"")
				website->Text = to_dotnet_string(about->website);
			else
			{
				website->Text = L"-";
				website->Enabled = false;
				label_website->Enabled = false;
			}

			/// User-type specifics.

			if (typeid(*about) == typeid(Individual))
			{
				label_name->Text = L"Полное имя:";

				if (contract_made == true)
					phone_number->Text = to_dotnet_string(about->phone_number.as_text());
				else
					phone_number->Text = to_dotnet_string(about->phone_number.conceal());

				birthdate->Text	= to_dotnet_string(about->birth_date.dd_month_yyyy_genitive());
				label_birthdate->Text = L"Дата рождения:";
			}

			if (typeid(*about) == typeid(Company))
			{
				label_name->Text = L"Имя компании:";

				phone_number->Text = to_dotnet_string(about->phone_number.as_text());

				birthdate->Text	= to_dotnet_string(about->birth_date.month_yyyy_genitive());
				label_birthdate->Text = L"На рынке с:";
			}
		}

	#pragma region = Winforms code =

	protected:

		~Account_Info()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_info;
	private: System::Windows::Forms::PictureBox^ bg_info;
	private: System::Windows::Forms::Label^ label_name;
	private: System::Windows::Forms::Label^ label_birthdate;
	private: System::Windows::Forms::Label^ label_phone_number;
	private: System::Windows::Forms::Label^ label_email;
	private: System::Windows::Forms::Label^ label_extra_contacts;
	private: System::Windows::Forms::Label^ label_website;
	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::TextBox^ birthdate;
	private: System::Windows::Forms::TextBox^ phone_number;
	private: System::Windows::Forms::TextBox^ email;
	private: System::Windows::Forms::TextBox^ extra_contacts;
	private: System::Windows::Forms::TextBox^ website;
	protected:

    protected:













	private:
		System::ComponentModel::Container ^components;
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Account_Info::typeid));
			this->label_info = (gcnew System::Windows::Forms::Label());
			this->bg_info = (gcnew System::Windows::Forms::PictureBox());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->label_birthdate = (gcnew System::Windows::Forms::Label());
			this->label_phone_number = (gcnew System::Windows::Forms::Label());
			this->label_email = (gcnew System::Windows::Forms::Label());
			this->label_extra_contacts = (gcnew System::Windows::Forms::Label());
			this->label_website = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->birthdate = (gcnew System::Windows::Forms::TextBox());
			this->phone_number = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->extra_contacts = (gcnew System::Windows::Forms::TextBox());
			this->website = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_info))->BeginInit();
			this->SuspendLayout();
			// 
			// label_info
			// 
			this->label_info->AutoSize = true;
			this->label_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->label_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_info->Location = System::Drawing::Point(10, 10);
			this->label_info->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_info->Name = L"label_info";
			this->label_info->Size = System::Drawing::Size(177, 29);
			this->label_info->TabIndex = 2;
			this->label_info->Text = L"Информация";
			// 
			// bg_info
			// 
			this->bg_info->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bg_info.BackgroundImage")));
			this->bg_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->bg_info->Location = System::Drawing::Point(0, 1);
			this->bg_info->Margin = System::Windows::Forms::Padding(4);
			this->bg_info->Name = L"bg_info";
			this->bg_info->Size = System::Drawing::Size(343, 138);
			this->bg_info->TabIndex = 3;
			this->bg_info->TabStop = false;
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name->Location = System::Drawing::Point(12, 149);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(85, 20);
			this->label_name->TabIndex = 4;
			this->label_name->Text = L"label_name";
			// 
			// label_birthdate
			// 
			this->label_birthdate->AutoSize = true;
			this->label_birthdate->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_birthdate->Location = System::Drawing::Point(11, 183);
			this->label_birthdate->Name = L"label_birthdate";
			this->label_birthdate->Size = System::Drawing::Size(107, 20);
			this->label_birthdate->TabIndex = 5;
			this->label_birthdate->Text = L"label_birthdate";
			// 
			// label_phone_number
			// 
			this->label_phone_number->AutoSize = true;
			this->label_phone_number->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_phone_number->Location = System::Drawing::Point(11, 217);
			this->label_phone_number->Name = L"label_phone_number";
			this->label_phone_number->Size = System::Drawing::Size(132, 20);
			this->label_phone_number->TabIndex = 6;
			this->label_phone_number->Text = L"Номер телефона:";
			// 
			// label_email
			// 
			this->label_email->AutoSize = true;
			this->label_email->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_email->Location = System::Drawing::Point(11, 251);
			this->label_email->Name = L"label_email";
			this->label_email->Size = System::Drawing::Size(54, 20);
			this->label_email->TabIndex = 7;
			this->label_email->Text = L"e-mail:";
			// 
			// label_extra_contacts
			// 
			this->label_extra_contacts->AutoSize = true;
			this->label_extra_contacts->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_extra_contacts->Location = System::Drawing::Point(12, 285);
			this->label_extra_contacts->Name = L"label_extra_contacts";
			this->label_extra_contacts->Size = System::Drawing::Size(118, 20);
			this->label_extra_contacts->TabIndex = 8;
			this->label_extra_contacts->Text = L"Доп. контакты:";
			// 
			// label_website
			// 
			this->label_website->AutoSize = true;
			this->label_website->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_website->Location = System::Drawing::Point(11, 319);
			this->label_website->Name = L"label_website";
			this->label_website->Size = System::Drawing::Size(47, 20);
			this->label_website->TabIndex = 9;
			this->label_website->Text = L"Сайт:";
			// 
			// name
			// 
			this->name->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->name->Location = System::Drawing::Point(149, 146);
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Size = System::Drawing::Size(181, 28);
			this->name->TabIndex = 10;
			// 
			// birthdate
			// 
			this->birthdate->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->birthdate->Location = System::Drawing::Point(149, 180);
			this->birthdate->Name = L"birthdate";
			this->birthdate->ReadOnly = true;
			this->birthdate->Size = System::Drawing::Size(181, 28);
			this->birthdate->TabIndex = 11;
			// 
			// phone_number
			// 
			this->phone_number->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->phone_number->Location = System::Drawing::Point(149, 214);
			this->phone_number->Name = L"phone_number";
			this->phone_number->ReadOnly = true;
			this->phone_number->Size = System::Drawing::Size(181, 28);
			this->phone_number->TabIndex = 12;
			// 
			// email
			// 
			this->email->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->email->Location = System::Drawing::Point(149, 248);
			this->email->Name = L"email";
			this->email->ReadOnly = true;
			this->email->Size = System::Drawing::Size(181, 28);
			this->email->TabIndex = 13;
			// 
			// extra_contacts
			// 
			this->extra_contacts->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->extra_contacts->Location = System::Drawing::Point(149, 282);
			this->extra_contacts->Name = L"extra_contacts";
			this->extra_contacts->ReadOnly = true;
			this->extra_contacts->Size = System::Drawing::Size(181, 28);
			this->extra_contacts->TabIndex = 14;
			// 
			// website
			// 
			this->website->Font = (gcnew System::Drawing::Font(L"Roboto Condensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->website->Location = System::Drawing::Point(149, 316);
			this->website->Name = L"website";
			this->website->ReadOnly = true;
			this->website->Size = System::Drawing::Size(181, 28);
			this->website->TabIndex = 15;
			// 
			// account_info
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(342, 358);
			this->Controls->Add(this->website);
			this->Controls->Add(this->extra_contacts);
			this->Controls->Add(this->email);
			this->Controls->Add(this->phone_number);
			this->Controls->Add(this->birthdate);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label_website);
			this->Controls->Add(this->label_extra_contacts);
			this->Controls->Add(this->label_email);
			this->Controls->Add(this->label_phone_number);
			this->Controls->Add(this->label_birthdate);
			this->Controls->Add(this->label_name);
			this->Controls->Add(this->label_info);
			this->Controls->Add(this->bg_info);
			this->MaximumSize = System::Drawing::Size(360, 405);
			this->MinimumSize = System::Drawing::Size(360, 405);
			this->Name = L"account_info";
			this->Text = L"Об аккаунте";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_info))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
