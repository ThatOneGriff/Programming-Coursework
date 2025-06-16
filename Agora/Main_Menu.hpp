#pragma once
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <stdio.h> // File removal

#include "Menus/Registration/Registration.hpp"

#include "Classes/User.hpp"
#include "Utils.hpp"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Agora {
public ref class Main_Menu : public System::Windows::Forms::Form
{
public:

	User* user;

	Main_Menu(User* _user)
	: user(_user)
	{
		InitializeComponent();
	}

	#pragma region = Winforms Code =

	protected:
		~Main_Menu()
		{
			if (components)
				delete components;
		}

	private: System::Windows::Forms::Button^ menu_button_search;
	private: System::Windows::Forms::Panel^ sidebar;
	private: System::Windows::Forms::Button^ menu_button_info;
	private: System::Windows::Forms::Button^ menu_button_settings;
	private: System::Windows::Forms::Button^ menu_button_account;
	private: System::Windows::Forms::Button^ menu_button_feed;
	private: System::Windows::Forms::Panel^ menu_account;
private: System::Windows::Forms::Label^ label_my_account;

private: System::Windows::Forms::PictureBox^ bg_my_account;
private: System::Windows::Forms::GroupBox^ group_account_data;
private: System::Windows::Forms::TextBox^ output_account_email;

private: System::Windows::Forms::TextBox^ output_account_phone_number;


private: System::Windows::Forms::TextBox^ output_account_name;
private: System::Windows::Forms::TextBox^ output_account_extra;







private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::TextBox^ output_account_website;
private: System::Windows::Forms::Panel^ menu_feed;
private: System::Windows::Forms::Label^ label_feed;
private: System::Windows::Forms::PictureBox^ bg_feed;
private: System::Windows::Forms::GroupBox^ group_active_duties;


private: System::Windows::Forms::GroupBox^ group_offers;
private: System::Windows::Forms::GroupBox^ group_orders;
private: System::Windows::Forms::Button^ button_feed_update;
private: System::Windows::Forms::Timer^ timer;












	private: System::ComponentModel::IContainer^ components;

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_Menu::typeid));
			this->menu_button_search = (gcnew System::Windows::Forms::Button());
			this->sidebar = (gcnew System::Windows::Forms::Panel());
			this->menu_button_info = (gcnew System::Windows::Forms::Button());
			this->menu_button_settings = (gcnew System::Windows::Forms::Button());
			this->menu_button_account = (gcnew System::Windows::Forms::Button());
			this->menu_button_feed = (gcnew System::Windows::Forms::Button());
			this->menu_account = (gcnew System::Windows::Forms::Panel());
			this->group_active_duties = (gcnew System::Windows::Forms::GroupBox());
			this->group_account_data = (gcnew System::Windows::Forms::GroupBox());
			this->output_account_website = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->output_account_extra = (gcnew System::Windows::Forms::TextBox());
			this->output_account_email = (gcnew System::Windows::Forms::TextBox());
			this->output_account_phone_number = (gcnew System::Windows::Forms::TextBox());
			this->output_account_name = (gcnew System::Windows::Forms::TextBox());
			this->label_my_account = (gcnew System::Windows::Forms::Label());
			this->bg_my_account = (gcnew System::Windows::Forms::PictureBox());
			this->menu_feed = (gcnew System::Windows::Forms::Panel());
			this->button_feed_update = (gcnew System::Windows::Forms::Button());
			this->group_orders = (gcnew System::Windows::Forms::GroupBox());
			this->group_offers = (gcnew System::Windows::Forms::GroupBox());
			this->label_feed = (gcnew System::Windows::Forms::Label());
			this->bg_feed = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->sidebar->SuspendLayout();
			this->menu_account->SuspendLayout();
			this->group_account_data->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_my_account))->BeginInit();
			this->menu_feed->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_feed))->BeginInit();
			this->SuspendLayout();
			// 
			// menu_button_search
			// 
			this->menu_button_search->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->menu_button_search->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menu_button_search->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_search.Image")));
			this->menu_button_search->Location = System::Drawing::Point(5, 9);
			this->menu_button_search->Name = L"menu_button_search";
			this->menu_button_search->Size = System::Drawing::Size(75, 75);
			this->menu_button_search->TabIndex = 1;
			this->menu_button_search->UseVisualStyleBackColor = false;
			// 
			// sidebar
			// 
			this->sidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(191)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->sidebar->Controls->Add(this->menu_button_info);
			this->sidebar->Controls->Add(this->menu_button_settings);
			this->sidebar->Controls->Add(this->menu_button_account);
			this->sidebar->Controls->Add(this->menu_button_feed);
			this->sidebar->Controls->Add(this->menu_button_search);
			this->sidebar->Location = System::Drawing::Point(552, 12);
			this->sidebar->Name = L"sidebar";
			this->sidebar->Size = System::Drawing::Size(85, 415);
			this->sidebar->TabIndex = 1;
			// 
			// menu_button_info
			// 
			this->menu_button_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->menu_button_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menu_button_info->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_info.Image")));
			this->menu_button_info->Location = System::Drawing::Point(5, 333);
			this->menu_button_info->Name = L"menu_button_info";
			this->menu_button_info->Size = System::Drawing::Size(75, 75);
			this->menu_button_info->TabIndex = 4;
			this->menu_button_info->UseVisualStyleBackColor = false;
			// 
			// menu_button_settings
			// 
			this->menu_button_settings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->menu_button_settings->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menu_button_settings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_settings.Image")));
			this->menu_button_settings->Location = System::Drawing::Point(5, 253);
			this->menu_button_settings->Name = L"menu_button_settings";
			this->menu_button_settings->Size = System::Drawing::Size(75, 75);
			this->menu_button_settings->TabIndex = 3;
			this->menu_button_settings->UseVisualStyleBackColor = false;
			// 
			// menu_button_account
			// 
			this->menu_button_account->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->menu_button_account->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menu_button_account->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_account.Image")));
			this->menu_button_account->Location = System::Drawing::Point(5, 173);
			this->menu_button_account->Name = L"menu_button_account";
			this->menu_button_account->Size = System::Drawing::Size(75, 75);
			this->menu_button_account->TabIndex = 2;
			this->menu_button_account->UseVisualStyleBackColor = false;
			this->menu_button_account->Click += gcnew System::EventHandler(this, &Main_Menu::sidebar_pick_account);
			// 
			// menu_button_feed
			// 
			this->menu_button_feed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->menu_button_feed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menu_button_feed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_feed.Image")));
			this->menu_button_feed->Location = System::Drawing::Point(5, 93);
			this->menu_button_feed->Name = L"menu_button_feed";
			this->menu_button_feed->Size = System::Drawing::Size(75, 75);
			this->menu_button_feed->TabIndex = 0;
			this->menu_button_feed->UseVisualStyleBackColor = false;
			this->menu_button_feed->Click += gcnew System::EventHandler(this, &Main_Menu::sidebar_pick_feed);
			// 
			// menu_account
			// 
			this->menu_account->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->menu_account->Controls->Add(this->group_active_duties);
			this->menu_account->Controls->Add(this->group_account_data);
			this->menu_account->Controls->Add(this->label_my_account);
			this->menu_account->Controls->Add(this->bg_my_account);
			this->menu_account->Location = System::Drawing::Point(12, 12);
			this->menu_account->Name = L"menu_account";
			this->menu_account->Size = System::Drawing::Size(534, 415);
			this->menu_account->TabIndex = 2;
			// 
			// group_active_duties
			// 
			this->group_active_duties->Location = System::Drawing::Point(281, 157);
			this->group_active_duties->Name = L"group_active_duties";
			this->group_active_duties->Size = System::Drawing::Size(248, 250);
			this->group_active_duties->TabIndex = 5;
			this->group_active_duties->TabStop = false;
			this->group_active_duties->Text = L"Активные подряды";
			// 
			// group_account_data
			// 
			this->group_account_data->Controls->Add(this->output_account_website);
			this->group_account_data->Controls->Add(this->button1);
			this->group_account_data->Controls->Add(this->output_account_extra);
			this->group_account_data->Controls->Add(this->output_account_email);
			this->group_account_data->Controls->Add(this->output_account_phone_number);
			this->group_account_data->Controls->Add(this->output_account_name);
			this->group_account_data->Location = System::Drawing::Point(8, 157);
			this->group_account_data->Name = L"group_account_data";
			this->group_account_data->Size = System::Drawing::Size(267, 250);
			this->group_account_data->TabIndex = 2;
			this->group_account_data->TabStop = false;
			this->group_account_data->Text = L"Данные";
			// 
			// output_account_website
			// 
			this->output_account_website->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->output_account_website->Location = System::Drawing::Point(6, 118);
			this->output_account_website->Name = L"output_account_website";
			this->output_account_website->ReadOnly = true;
			this->output_account_website->Size = System::Drawing::Size(255, 26);
			this->output_account_website->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(191)),
				static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(6, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(255, 40);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Редактировать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Main_Menu::edit_account_data);
			// 
			// output_account_extra
			// 
			this->output_account_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->output_account_extra->Location = System::Drawing::Point(6, 150);
			this->output_account_extra->Name = L"output_account_extra";
			this->output_account_extra->ReadOnly = true;
			this->output_account_extra->Size = System::Drawing::Size(255, 26);
			this->output_account_extra->TabIndex = 3;
			// 
			// output_account_email
			// 
			this->output_account_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->output_account_email->Location = System::Drawing::Point(6, 85);
			this->output_account_email->Name = L"output_account_email";
			this->output_account_email->ReadOnly = true;
			this->output_account_email->Size = System::Drawing::Size(255, 26);
			this->output_account_email->TabIndex = 2;
			// 
			// output_account_phone_number
			// 
			this->output_account_phone_number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->output_account_phone_number->Location = System::Drawing::Point(6, 53);
			this->output_account_phone_number->Name = L"output_account_phone_number";
			this->output_account_phone_number->ReadOnly = true;
			this->output_account_phone_number->Size = System::Drawing::Size(255, 26);
			this->output_account_phone_number->TabIndex = 1;
			// 
			// output_account_name
			// 
			this->output_account_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->output_account_name->Location = System::Drawing::Point(6, 21);
			this->output_account_name->Name = L"output_account_name";
			this->output_account_name->ReadOnly = true;
			this->output_account_name->Size = System::Drawing::Size(255, 26);
			this->output_account_name->TabIndex = 0;
			// 
			// label_my_account
			// 
			this->label_my_account->AutoSize = true;
			this->label_my_account->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->label_my_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_my_account->Location = System::Drawing::Point(3, 8);
			this->label_my_account->Name = L"label_my_account";
			this->label_my_account->Size = System::Drawing::Size(167, 29);
			this->label_my_account->TabIndex = 0;
			this->label_my_account->Text = L"Мой аккаунт";
			// 
			// bg_my_account
			// 
			this->bg_my_account->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bg_my_account.BackgroundImage")));
			this->bg_my_account->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->bg_my_account->Location = System::Drawing::Point(-1, -1);
			this->bg_my_account->Name = L"bg_my_account";
			this->bg_my_account->Size = System::Drawing::Size(534, 152);
			this->bg_my_account->TabIndex = 1;
			this->bg_my_account->TabStop = false;
			// 
			// menu_feed
			// 
			this->menu_feed->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->menu_feed->Controls->Add(this->button_feed_update);
			this->menu_feed->Controls->Add(this->group_orders);
			this->menu_feed->Controls->Add(this->group_offers);
			this->menu_feed->Controls->Add(this->label_feed);
			this->menu_feed->Controls->Add(this->bg_feed);
			this->menu_feed->Location = System::Drawing::Point(12, 12);
			this->menu_feed->Name = L"menu_feed";
			this->menu_feed->Size = System::Drawing::Size(534, 415);
			this->menu_feed->TabIndex = 3;
			// 
			// button_feed_update
			// 
			this->button_feed_update->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_feed_update.BackgroundImage")));
			this->button_feed_update->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button_feed_update->Location = System::Drawing::Point(265, 6);
			this->button_feed_update->Name = L"button_feed_update";
			this->button_feed_update->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button_feed_update->Size = System::Drawing::Size(35, 35);
			this->button_feed_update->TabIndex = 0;
			this->button_feed_update->UseVisualStyleBackColor = true;
			this->button_feed_update->Click += gcnew System::EventHandler(this, &Main_Menu::update_feed);
			// 
			// group_orders
			// 
			this->group_orders->Location = System::Drawing::Point(274, 157);
			this->group_orders->Name = L"group_orders";
			this->group_orders->Size = System::Drawing::Size(255, 253);
			this->group_orders->TabIndex = 6;
			this->group_orders->TabStop = false;
			this->group_orders->Text = L"Ищут подрядчика";
			// 
			// group_offers
			// 
			this->group_offers->Location = System::Drawing::Point(8, 157);
			this->group_offers->Name = L"group_offers";
			this->group_offers->Size = System::Drawing::Size(255, 253);
			this->group_offers->TabIndex = 5;
			this->group_offers->TabStop = false;
			this->group_offers->Text = L"Ищут заказчика";
			// 
			// label_feed
			// 
			this->label_feed->AutoSize = true;
			this->label_feed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)));
			this->label_feed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_feed->Location = System::Drawing::Point(3, 8);
			this->label_feed->Name = L"label_feed";
			this->label_feed->Size = System::Drawing::Size(247, 29);
			this->label_feed->TabIndex = 0;
			this->label_feed->Text = L"Лента объявлений";
			// 
			// bg_feed
			// 
			this->bg_feed->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bg_feed.BackgroundImage")));
			this->bg_feed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->bg_feed->Location = System::Drawing::Point(-1, -1);
			this->bg_feed->Name = L"bg_feed";
			this->bg_feed->Size = System::Drawing::Size(534, 152);
			this->bg_feed->TabIndex = 1;
			this->bg_feed->TabStop = false;
			// 
			// timer
			// 
			this->timer->Interval = 500;
			this->timer->Tick += gcnew System::EventHandler(this, &Main_Menu::update_feed);
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(639, 437);
			this->Controls->Add(this->sidebar);
			this->Controls->Add(this->menu_feed);
			this->Controls->Add(this->menu_account);
			this->DoubleBuffered = true;
			this->Name = L"Main_Menu";
			this->Text = L"Agora";
			this->sidebar->ResumeLayout(false);
			this->menu_account->ResumeLayout(false);
			this->menu_account->PerformLayout();
			this->group_account_data->ResumeLayout(false);
			this->group_account_data->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_my_account))->EndInit();
			this->menu_feed->ResumeLayout(false);
			this->menu_feed->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_feed))->EndInit();
			this->ResumeLayout(false);

		}

		#pragma endregion

private:

	#pragma region ======= Feed =======

	void sidebar_pick_feed(System::Object^ sender, System::EventArgs^ e)
	{
		this->Text = "Agora: Лента";
		menu_feed->BringToFront();

		//fill_feed_menu();
	}


	void update_feed(System::Object^ _sender, System::EventArgs^ e)
	{
		group_orders->Enabled = ! group_orders->Enabled;
		group_offers->Enabled = ! group_offers->Enabled;
		timer->Enabled = ! timer->Enabled;
	}

	#pragma endregion



	#pragma region ======= Account =======

	void sidebar_pick_account(System::Object ^ sender, System::EventArgs ^ e)
	{
		this->Text = "Agora: Мой аккаунт";
		menu_account->BringToFront();

		fill_account_menu();
	}


	void edit_account_data(System::Object^ sender, System::EventArgs^ e)
	{
		Registration^ registration = gcnew Registration(user);
		registration->ShowDialog();
		user = load(USER_SAVEFILE_NAME);
		if (user == nullptr)
		{
			MessageBox::Show("Couldn't read updated data.");
			this->Close();
			return;
		}

		fill_account_menu();
	}


	void fill_account_menu()
	{
		if (typeid(*user) == typeid(Individual))
			output_account_name->Text =	 to_dotnet_string(user->name->get_short());
		else if (typeid(*user) == typeid(Company))
		{
			output_account_name->Text  = to_dotnet_string(user->name->get_full()); // A question rises: do companies even need short names?
			output_account_website->Text = to_dotnet_string(user->website); // I genuinely have no time to try and fit extra contacts into 'Company'
		}
		
		output_account_phone_number->Text = to_dotnet_string(user->phone_number.as_text());
		output_account_email->Text =		to_dotnet_string(user->email);
		if (output_account_email->Text == "")
			output_account_email->Text = "-";
		output_account_extra->Text = to_dotnet_string(user->extra_contacts);
		if (output_account_extra->Text == "")
			output_account_extra->Text = "-";
	}

	#pragma endregion
};
}

#endif