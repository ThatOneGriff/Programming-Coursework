#pragma once
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Menus/Registration/registration.hpp"
// Should menus be able to include each other?
// Or should we opt for a more modular approach?

#include "../../Classes/user.hpp"
#include "../../utils.hpp"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Agora
{
public ref class Main_Menu : public System::Windows::Forms::Form
{
public:

	User* user;

	Main_Menu(User* _user)
	: user(_user)
	{
		InitializeComponent();

		/// Centering everything
		center_x(label_search_will_be, menu_search);
		center_x(label_in_future_updates, menu_search);

		System::Drawing::Size size(665, 485);
		this->Size = size;

		sidebar_pick_account(nullptr, nullptr); /// default menu may become a choice in Settings
	}

	#pragma region = Winforms Code =

protected:
	~Main_Menu()
	{
		if (components)
			delete components;
	}

private:
	System::Windows::Forms::Button^ menu_button_search;
	System::Windows::Forms::Panel^ sidebar;
	System::Windows::Forms::Button^ menu_button_info;
	System::Windows::Forms::Button^ menu_button_settings;
	System::Windows::Forms::Button^ menu_button_account;
	System::Windows::Forms::Button^ menu_button_feed;
	System::Windows::Forms::Panel^ menu_account;
	System::Windows::Forms::Label^ label_my_account;
	System::Windows::Forms::PictureBox^ bg_my_account;
	System::Windows::Forms::GroupBox^ group_account_data;
	System::Windows::Forms::TextBox^ output_account_email;
	System::Windows::Forms::TextBox^ output_account_phone_number;
	System::Windows::Forms::TextBox^ output_account_name;
	System::Windows::Forms::TextBox^ output_account_extra;
	System::Windows::Forms::Button^ button1;
	System::Windows::Forms::TextBox^ output_account_website;
	System::Windows::Forms::Panel^ menu_feed;
	System::Windows::Forms::Label^ label_feed;
	System::Windows::Forms::PictureBox^ bg_feed;
	System::Windows::Forms::GroupBox^ group_offers;
	System::Windows::Forms::GroupBox^ group_orders;
	System::Windows::Forms::Button^ button_feed_update;
	System::Windows::Forms::Timer^ update_timer;
	System::Windows::Forms::Panel^ menu_search;
	System::Windows::Forms::Label^ label_in_future_updates;
	System::Windows::Forms::Label^ label_search_will_be;
	System::Windows::Forms::Button^ button_search;
	System::Windows::Forms::TextBox^ input_search;
	System::Windows::Forms::Label^ label_search;
	System::Windows::Forms::PictureBox^ bg_search;
	System::Windows::Forms::GroupBox^ group_active_contracts;
	System::Windows::Forms::TextBox^ output_account_age;
	System::Windows::Forms::Label^ label_account_website;
	System::Windows::Forms::Label^ label_account_extra;
	System::Windows::Forms::Label^ label_account_email;
	System::Windows::Forms::Label^ label_account_age;
	System::Windows::Forms::Label^ label_account_phone_number;
	System::Windows::Forms::RichTextBox^ label_no_active_contracts;
	System::Windows::Forms::Button^ button_filter;
	System::Windows::Forms::Label^ label_feed_customers_WIP;
	System::Windows::Forms::Label^ label_feed_contractors_WIP;
	
	System::ComponentModel::IContainer^ components;

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
		this->group_active_contracts = (gcnew System::Windows::Forms::GroupBox());
		this->label_no_active_contracts = (gcnew System::Windows::Forms::RichTextBox());
		this->group_account_data = (gcnew System::Windows::Forms::GroupBox());
		this->label_account_website = (gcnew System::Windows::Forms::Label());
		this->label_account_extra = (gcnew System::Windows::Forms::Label());
		this->label_account_email = (gcnew System::Windows::Forms::Label());
		this->label_account_age = (gcnew System::Windows::Forms::Label());
		this->label_account_phone_number = (gcnew System::Windows::Forms::Label());
		this->output_account_age = (gcnew System::Windows::Forms::TextBox());
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
		this->label_feed_customers_WIP = (gcnew System::Windows::Forms::Label());
		this->group_offers = (gcnew System::Windows::Forms::GroupBox());
		this->label_feed_contractors_WIP = (gcnew System::Windows::Forms::Label());
		this->label_feed = (gcnew System::Windows::Forms::Label());
		this->bg_feed = (gcnew System::Windows::Forms::PictureBox());
		this->update_timer = (gcnew System::Windows::Forms::Timer(this->components));
		this->menu_search = (gcnew System::Windows::Forms::Panel());
		this->button_filter = (gcnew System::Windows::Forms::Button());
		this->label_in_future_updates = (gcnew System::Windows::Forms::Label());
		this->label_search_will_be = (gcnew System::Windows::Forms::Label());
		this->button_search = (gcnew System::Windows::Forms::Button());
		this->input_search = (gcnew System::Windows::Forms::TextBox());
		this->label_search = (gcnew System::Windows::Forms::Label());
		this->bg_search = (gcnew System::Windows::Forms::PictureBox());
		this->sidebar->SuspendLayout();
		this->menu_account->SuspendLayout();
		this->group_active_contracts->SuspendLayout();
		this->group_account_data->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_my_account))->BeginInit();
		this->menu_feed->SuspendLayout();
		this->group_orders->SuspendLayout();
		this->group_offers->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_feed))->BeginInit();
		this->menu_search->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_search))->BeginInit();
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
		this->menu_button_search->Size = System::Drawing::Size(100, 100);
		this->menu_button_search->TabIndex = 1;
		this->menu_button_search->UseVisualStyleBackColor = false;
		this->menu_button_search->Click += gcnew System::EventHandler(this, &Main_Menu::sidebar_pick_search);
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
		this->sidebar->Location = System::Drawing::Point(660, 12);
		this->sidebar->Name = L"sidebar";
		this->sidebar->Size = System::Drawing::Size(110, 535);
		this->sidebar->TabIndex = 1;
		// 
		// menu_button_info
		// 
		this->menu_button_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->menu_button_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->menu_button_info->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_info.Image")));
		this->menu_button_info->Location = System::Drawing::Point(5, 429);
		this->menu_button_info->Name = L"menu_button_info";
		this->menu_button_info->Size = System::Drawing::Size(100, 100);
		this->menu_button_info->TabIndex = 4;
		this->menu_button_info->UseVisualStyleBackColor = false;
		this->menu_button_info->Click += gcnew System::EventHandler(this, &Main_Menu::sidebar_pick_info);
		// 
		// menu_button_settings
		// 
		this->menu_button_settings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->menu_button_settings->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->menu_button_settings->Enabled = false;
		this->menu_button_settings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_settings.Image")));
		this->menu_button_settings->Location = System::Drawing::Point(5, 323);
		this->menu_button_settings->Name = L"menu_button_settings";
		this->menu_button_settings->Size = System::Drawing::Size(100, 100);
		this->menu_button_settings->TabIndex = 3;
		this->menu_button_settings->UseVisualStyleBackColor = false;
		// 
		// menu_button_account
		// 
		this->menu_button_account->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->menu_button_account->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->menu_button_account->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_account.Image")));
		this->menu_button_account->Location = System::Drawing::Point(5, 217);
		this->menu_button_account->Name = L"menu_button_account";
		this->menu_button_account->Size = System::Drawing::Size(100, 100);
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
		this->menu_button_feed->Location = System::Drawing::Point(5, 111);
		this->menu_button_feed->Name = L"menu_button_feed";
		this->menu_button_feed->Size = System::Drawing::Size(100, 100);
		this->menu_button_feed->TabIndex = 0;
		this->menu_button_feed->UseVisualStyleBackColor = false;
		this->menu_button_feed->Click += gcnew System::EventHandler(this, &Main_Menu::sidebar_pick_feed);
		// 
		// menu_account
		// 
		this->menu_account->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->menu_account->Controls->Add(this->group_active_contracts);
		this->menu_account->Controls->Add(this->group_account_data);
		this->menu_account->Controls->Add(this->label_my_account);
		this->menu_account->Controls->Add(this->bg_my_account);
		this->menu_account->Location = System::Drawing::Point(12, 12);
		this->menu_account->Name = L"menu_account";
		this->menu_account->Size = System::Drawing::Size(640, 535);
		this->menu_account->TabIndex = 2;
		// 
		// group_active_contracts
		// 
		this->group_active_contracts->Controls->Add(this->label_no_active_contracts);
		this->group_active_contracts->Location = System::Drawing::Point(328, 178);
		this->group_active_contracts->Name = L"group_active_contracts";
		this->group_active_contracts->Size = System::Drawing::Size(307, 350);
		this->group_active_contracts->TabIndex = 5;
		this->group_active_contracts->TabStop = false;
		this->group_active_contracts->Text = L"Активные контракты";
		// 
		// label_no_active_contracts
		// 
		this->label_no_active_contracts->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->label_no_active_contracts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->label_no_active_contracts->Location = System::Drawing::Point(6, 121);
		this->label_no_active_contracts->Name = L"label_no_active_contracts";
		this->label_no_active_contracts->ReadOnly = true;
		this->label_no_active_contracts->Size = System::Drawing::Size(301, 87);
		this->label_no_active_contracts->TabIndex = 0;
		this->label_no_active_contracts->Text = L"Активных контрактов нет.\n\nЗайдите в Ленту и выберите!";
		// 
		// group_account_data
		// 
		this->group_account_data->Controls->Add(this->label_account_website);
		this->group_account_data->Controls->Add(this->label_account_extra);
		this->group_account_data->Controls->Add(this->label_account_email);
		this->group_account_data->Controls->Add(this->label_account_age);
		this->group_account_data->Controls->Add(this->label_account_phone_number);
		this->group_account_data->Controls->Add(this->output_account_age);
		this->group_account_data->Controls->Add(this->output_account_website);
		this->group_account_data->Controls->Add(this->button1);
		this->group_account_data->Controls->Add(this->output_account_extra);
		this->group_account_data->Controls->Add(this->output_account_email);
		this->group_account_data->Controls->Add(this->output_account_phone_number);
		this->group_account_data->Controls->Add(this->output_account_name);
		this->group_account_data->Location = System::Drawing::Point(8, 178);
		this->group_account_data->Name = L"group_account_data";
		this->group_account_data->Size = System::Drawing::Size(314, 350);
		this->group_account_data->TabIndex = 2;
		this->group_account_data->TabStop = false;
		this->group_account_data->Text = L"Данные";
		// 
		// label_account_website
		// 
		this->label_account_website->AutoSize = true;
		this->label_account_website->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_website->Location = System::Drawing::Point(6, 185);
		this->label_account_website->Name = L"label_account_website";
		this->label_account_website->Size = System::Drawing::Size(61, 20);
		this->label_account_website->TabIndex = 9;
		this->label_account_website->Text = L"Сайт:";
		// 
		// label_account_extra
		// 
		this->label_account_extra->AutoSize = true;
		this->label_account_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_extra->Location = System::Drawing::Point(6, 153);
		this->label_account_extra->Name = L"label_account_extra";
		this->label_account_extra->Size = System::Drawing::Size(56, 20);
		this->label_account_extra->TabIndex = 8;
		this->label_account_extra->Text = L"Доп.:";
		// 
		// label_account_email
		// 
		this->label_account_email->AutoSize = true;
		this->label_account_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_email->Location = System::Drawing::Point(6, 121);
		this->label_account_email->Name = L"label_account_email";
		this->label_account_email->Size = System::Drawing::Size(67, 20);
		this->label_account_email->TabIndex = 7;
		this->label_account_email->Text = L"e-mail:";
		// 
		// label_account_age
		// 
		this->label_account_age->AutoSize = true;
		this->label_account_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_age->Location = System::Drawing::Point(6, 56);
		this->label_account_age->Name = L"label_account_age";
		this->label_account_age->Size = System::Drawing::Size(89, 20);
		this->label_account_age->TabIndex = 6;
		this->label_account_age->Text = L"label_age";
		// 
		// label_account_phone_number
		// 
		this->label_account_phone_number->AutoSize = true;
		this->label_account_phone_number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->label_account_phone_number->Location = System::Drawing::Point(6, 88);
		this->label_account_phone_number->Name = L"label_account_phone_number";
		this->label_account_phone_number->Size = System::Drawing::Size(98, 20);
		this->label_account_phone_number->TabIndex = 6;
		this->label_account_phone_number->Text = L"Телефон:";
		// 
		// output_account_age
		// 
		this->output_account_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->output_account_age->Location = System::Drawing::Point(131, 53);
		this->output_account_age->Name = L"output_account_age";
		this->output_account_age->ReadOnly = true;
		this->output_account_age->Size = System::Drawing::Size(177, 26);
		this->output_account_age->TabIndex = 5;
		// 
		// output_account_website
		// 
		this->output_account_website->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->output_account_website->Location = System::Drawing::Point(79, 182);
		this->output_account_website->Name = L"output_account_website";
		this->output_account_website->ReadOnly = true;
		this->output_account_website->Size = System::Drawing::Size(229, 26);
		this->output_account_website->TabIndex = 4;
		// 
		// button1
		// 
		this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(191)),
			static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button1->Location = System::Drawing::Point(0, 214);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(308, 40);
		this->button1->TabIndex = 3;
		this->button1->Text = L"Редактировать";
		this->button1->UseVisualStyleBackColor = false;
		this->button1->Click += gcnew System::EventHandler(this, &Main_Menu::edit_account_data);
		// 
		// output_account_extra
		// 
		this->output_account_extra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->output_account_extra->Location = System::Drawing::Point(79, 150);
		this->output_account_extra->Name = L"output_account_extra";
		this->output_account_extra->ReadOnly = true;
		this->output_account_extra->Size = System::Drawing::Size(229, 26);
		this->output_account_extra->TabIndex = 3;
		// 
		// output_account_email
		// 
		this->output_account_email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->output_account_email->Location = System::Drawing::Point(79, 118);
		this->output_account_email->Name = L"output_account_email";
		this->output_account_email->ReadOnly = true;
		this->output_account_email->Size = System::Drawing::Size(229, 26);
		this->output_account_email->TabIndex = 2;
		// 
		// output_account_phone_number
		// 
		this->output_account_phone_number->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->output_account_phone_number->Location = System::Drawing::Point(131, 85);
		this->output_account_phone_number->Name = L"output_account_phone_number";
		this->output_account_phone_number->ReadOnly = true;
		this->output_account_phone_number->Size = System::Drawing::Size(177, 26);
		this->output_account_phone_number->TabIndex = 1;
		// 
		// output_account_name
		// 
		this->output_account_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->output_account_name->Location = System::Drawing::Point(6, 21);
		this->output_account_name->Name = L"output_account_name";
		this->output_account_name->ReadOnly = true;
		this->output_account_name->Size = System::Drawing::Size(302, 26);
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
		this->bg_my_account->Location = System::Drawing::Point(0, -7);
		this->bg_my_account->Name = L"bg_my_account";
		this->bg_my_account->Size = System::Drawing::Size(640, 180);
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
		this->menu_feed->Size = System::Drawing::Size(640, 535);
		this->menu_feed->TabIndex = 3;
		// 
		// button_feed_update
		// 
		this->button_feed_update->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_feed_update.BackgroundImage")));
		this->button_feed_update->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->button_feed_update->Location = System::Drawing::Point(264, 3);
		this->button_feed_update->Name = L"button_feed_update";
		this->button_feed_update->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->button_feed_update->Size = System::Drawing::Size(40, 40);
		this->button_feed_update->TabIndex = 0;
		this->button_feed_update->UseVisualStyleBackColor = true;
		this->button_feed_update->Click += gcnew System::EventHandler(this, &Main_Menu::update_feed);
		// 
		// group_orders
		// 
		this->group_orders->Controls->Add(this->label_feed_customers_WIP);
		this->group_orders->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->group_orders->Location = System::Drawing::Point(322, 178);
		this->group_orders->Name = L"group_orders";
		this->group_orders->Size = System::Drawing::Size(308, 343);
		this->group_orders->TabIndex = 6;
		this->group_orders->TabStop = false;
		this->group_orders->Text = L"Ищут подрядчика";
		// 
		// label_feed_customers_WIP
		// 
		this->label_feed_customers_WIP->AutoSize = true;
		this->label_feed_customers_WIP->Enabled = false;
		this->label_feed_customers_WIP->Location = System::Drawing::Point(50, 159);
		this->label_feed_customers_WIP->Name = L"label_feed_customers_WIP";
		this->label_feed_customers_WIP->Size = System::Drawing::Size(200, 20);
		this->label_feed_customers_WIP->TabIndex = 1;
		this->label_feed_customers_WIP->Text = L"Работа в процессе...";
		// 
		// group_offers
		// 
		this->group_offers->Controls->Add(this->label_feed_contractors_WIP);
		this->group_offers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->group_offers->Location = System::Drawing::Point(8, 178);
		this->group_offers->Name = L"group_offers";
		this->group_offers->Size = System::Drawing::Size(308, 343);
		this->group_offers->TabIndex = 5;
		this->group_offers->TabStop = false;
		this->group_offers->Text = L"Ищут заказчика";
		// 
		// label_feed_contractors_WIP
		// 
		this->label_feed_contractors_WIP->AutoSize = true;
		this->label_feed_contractors_WIP->Enabled = false;
		this->label_feed_contractors_WIP->Location = System::Drawing::Point(53, 159);
		this->label_feed_contractors_WIP->Name = L"label_feed_contractors_WIP";
		this->label_feed_contractors_WIP->Size = System::Drawing::Size(200, 20);
		this->label_feed_contractors_WIP->TabIndex = 0;
		this->label_feed_contractors_WIP->Text = L"Работа в процессе...";
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
		this->bg_feed->Location = System::Drawing::Point(0, -7);
		this->bg_feed->Name = L"bg_feed";
		this->bg_feed->Size = System::Drawing::Size(640, 180);
		this->bg_feed->TabIndex = 1;
		this->bg_feed->TabStop = false;
		// 
		// update_timer
		// 
		this->update_timer->Interval = 500;
		this->update_timer->Tick += gcnew System::EventHandler(this, &Main_Menu::update_feed);
		// 
		// menu_search
		// 
		this->menu_search->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->menu_search->Controls->Add(this->button_filter);
		this->menu_search->Controls->Add(this->label_in_future_updates);
		this->menu_search->Controls->Add(this->label_search_will_be);
		this->menu_search->Controls->Add(this->button_search);
		this->menu_search->Controls->Add(this->input_search);
		this->menu_search->Controls->Add(this->label_search);
		this->menu_search->Controls->Add(this->bg_search);
		this->menu_search->Location = System::Drawing::Point(12, 12);
		this->menu_search->Name = L"menu_search";
		this->menu_search->Size = System::Drawing::Size(640, 535);
		this->menu_search->TabIndex = 7;
		// 
		// button_filter
		// 
		this->button_filter->BackColor = System::Drawing::SystemColors::ControlLight;
		this->button_filter->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_filter.BackgroundImage")));
		this->button_filter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->button_filter->Enabled = false;
		this->button_filter->Location = System::Drawing::Point(44, 178);
		this->button_filter->Name = L"button_filter";
		this->button_filter->Size = System::Drawing::Size(40, 40);
		this->button_filter->TabIndex = 6;
		this->button_filter->UseVisualStyleBackColor = false;
		// 
		// label_in_future_updates
		// 
		this->label_in_future_updates->AutoSize = true;
		this->label_in_future_updates->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->label_in_future_updates->Location = System::Drawing::Point(118, 266);
		this->label_in_future_updates->Name = L"label_in_future_updates";
		this->label_in_future_updates->Size = System::Drawing::Size(431, 20);
		this->label_in_future_updates->TabIndex = 4;
		this->label_in_future_updates->Text = L"...в будущих обновлениях. Спасибо, что вы с нами!\r\n";
		// 
		// label_search_will_be
		// 
		this->label_search_will_be->AutoSize = true;
		this->label_search_will_be->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_search_will_be->Location = System::Drawing::Point(247, 230);
		this->label_search_will_be->Name = L"label_search_will_be";
		this->label_search_will_be->Size = System::Drawing::Size(161, 25);
		this->label_search_will_be->TabIndex = 3;
		this->label_search_will_be->Text = L"Поиску - быть!";
		// 
		// button_search
		// 
		this->button_search->BackColor = System::Drawing::SystemColors::ControlLight;
		this->button_search->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_search.BackgroundImage")));
		this->button_search->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->button_search->Enabled = false;
		this->button_search->Location = System::Drawing::Point(3, 178);
		this->button_search->Name = L"button_search";
		this->button_search->Size = System::Drawing::Size(40, 40);
		this->button_search->TabIndex = 2;
		this->button_search->UseVisualStyleBackColor = false;
		// 
		// input_search
		// 
		this->input_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->input_search->Location = System::Drawing::Point(90, 183);
		this->input_search->Name = L"input_search";
		this->input_search->Size = System::Drawing::Size(539, 30);
		this->input_search->TabIndex = 1;
		// 
		// label_search
		// 
		this->label_search->AutoSize = true;
		this->label_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_search->Location = System::Drawing::Point(3, 8);
		this->label_search->Name = L"label_search";
		this->label_search->Size = System::Drawing::Size(229, 29);
		this->label_search->TabIndex = 0;
		this->label_search->Text = L"Поиск и фильтры";
		// 
		// bg_search
		// 
		this->bg_search->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bg_search.BackgroundImage")));
		this->bg_search->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->bg_search->Location = System::Drawing::Point(0, -7);
		this->bg_search->Name = L"bg_search";
		this->bg_search->Size = System::Drawing::Size(640, 180);
		this->bg_search->TabIndex = 5;
		this->bg_search->TabStop = false;
		// 
		// Main_Menu
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::Control;
		this->ClientSize = System::Drawing::Size(782, 553);
		this->Controls->Add(this->sidebar);
		this->Controls->Add(this->menu_account);
		this->Controls->Add(this->menu_search);
		this->Controls->Add(this->menu_feed);
		this->DoubleBuffered = true;
		this->MaximumSize = System::Drawing::Size(800, 600);
		this->MinimumSize = System::Drawing::Size(800, 600);
		this->Name = L"Main_Menu";
		this->Text = L"Agora";
		this->sidebar->ResumeLayout(false);
		this->menu_account->ResumeLayout(false);
		this->menu_account->PerformLayout();
		this->group_active_contracts->ResumeLayout(false);
		this->group_account_data->ResumeLayout(false);
		this->group_account_data->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_my_account))->EndInit();
		this->menu_feed->ResumeLayout(false);
		this->menu_feed->PerformLayout();
		this->group_orders->ResumeLayout(false);
		this->group_orders->PerformLayout();
		this->group_offers->ResumeLayout(false);
		this->group_offers->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_feed))->EndInit();
		this->menu_search->ResumeLayout(false);
		this->menu_search->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_search))->EndInit();
		this->ResumeLayout(false);

	}

	#pragma endregion

private:

	void center_x(Control^ target, Control^ relative_to)
	{
		/// Don't y'all love variables that don't state they're readonly?
		System::Drawing::Size size = TextRenderer::MeasureText(target->Text, target->Font);
		target->Size = size;
		System::Drawing::Point location((relative_to->Width - size.Width) / 2, target->Location.Y);
		target->Location = location;
	}

	#pragma region ======= Feed =======

	void sidebar_pick_feed(System::Object^ sender, System::EventArgs^ e)
	{
		this->Text = "Agora: Лента";
		menu_feed->BringToFront();

		//fill_feed_menu();
	}


	void update_feed(System::Object^ _sender, System::EventArgs^ e)
	{
		/// Think I'm a genius. This function is used both for start and end of the 'update'. Elegant!
		button_feed_update->Enabled = ! button_feed_update->Enabled;
		group_orders->Enabled = ! group_orders->Enabled;
		group_offers->Enabled = ! group_offers->Enabled;
		update_timer->Enabled = ! update_timer->Enabled;
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
			show_error(L"Couldn't read updated data.");
			this->Close();
			return;
		}

		fill_account_menu();
	}


	void fill_account_menu()
	{
		if (typeid(*user) == typeid(Individual))
		{
			output_account_name->Text = to_dotnet_string(user->name->get_short());
			label_account_website-> Enabled = false;
			output_account_website->Enabled = false;

			label_account_age->Text = "Возраст:";
			output_account_age->Text = to_dotnet_string(std::to_wstring(user->birth_date.years_since()) + L" лет");
		}
		else if (typeid(*user) == typeid(Company))
		{
			output_account_name->Text = to_dotnet_string(user->name->get_full());
			output_account_website->Text = to_dotnet_string(user->website);
			label_account_website-> Enabled = true;
			output_account_website->Enabled = true;

			label_account_age->Text = "На рынке с:";
			output_account_age->Text = to_dotnet_string(user->birth_date.month_yyyy_genitive());
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


	#pragma region ======= Misc. menus =======

	void sidebar_pick_info(System::Object^ sender, System::EventArgs^ e)
	{
		show_info(program_info, L"О программе");
	}


	void sidebar_pick_search(System::Object^ sender, System::EventArgs^ e)
	{
		this->Text = "Agora: Поиск объявлений и аккаунтов";
		menu_search->BringToFront();
	}

	#pragma endregion
};
}

#endif