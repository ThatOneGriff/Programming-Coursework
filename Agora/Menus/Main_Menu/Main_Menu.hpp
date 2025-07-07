#pragma once
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <vector>

#include "Menus/Registration/registration.hpp"
#include "listing_interface.hpp"

#include "../../Classes/random_listing_generator.hpp"
#include "../../Classes/user.hpp"
#include "../../utils.hpp"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// 'Member of an unmanaged class' bullshit made me put all of this here
std::vector<Listing> accepted_listings;
Listing listing_contractor1, listing_contractor2,
		listing_customer1,   listing_customer2;

const std::wstring PROGRAM_INFO =
	 (std::wstring)L"Agora v.1.0 от 07.07.2025\n" // it was INSISTING I was trying to initialize with 'System::String'
	 + L"Курсовой проект от Первакова А.И.\n"
	 + L"КубГАУ, Прикладная информатика, ИТ2403";


namespace Agora
{
public ref class Main_Menu : public System::Windows::Forms::Form
{
public:

	User* user;

	Listing_Interface ^contractor1_ui, ^contractor2_ui,
					  ^customer1_ui,   ^customer2_ui;

	Main_Menu(User* _user)
	: user(_user)
	{
		InitializeComponent();
		accepted_listings = load_listings(user);

		System::Drawing::Size size(665, 485);
		this->Size = size;
		/// I HATE CLR. FUCK CLR. MICROSOFT CAN GO EAT SHIT
		System::Drawing::Font^ font = gcnew System::Drawing::Font("Roboto", 7);
		this->Font = font;
		/// 1. WINDOW'S scaling somewhy depends on font size. What the f***?
		/// 2. 8 shows correct size in editor; 7 makes the release program correct.

		sidebar_pick_account(nullptr, nullptr); /// default menu may become a choice in Settings
		fill_listing_interface_objects();
		fill_account_menu();
		fill_active_listings_menu();
		fill_feed_menu();
	}

private:

	void fill_listing_interface_objects()
	{
		contractor1_ui = gcnew Listing_Interface(
			listing_contractor1_ui,			  listing_contractor1_name,		   listing_contractor1_author,
			listing_contractor1_button_info,  listing_contractor1_button_hire,
			listing_contractor1_label_per_hr, listing_contractor1_per_hr,
			listing_contractor1_label_hrs,	  listing_contractor1_picker_hrs,  listing_contractor1_total
		);

		contractor2_ui = gcnew Listing_Interface(
			listing_contractor2_ui,			  listing_contractor2_name,		   listing_contractor2_author,
			listing_contractor2_button_info,  listing_contractor2_button_hire,
			listing_contractor2_label_per_hr, listing_contractor2_per_hr,
			listing_contractor2_label_hrs,	  listing_contractor2_picker_hrs,  listing_contractor2_total
		);

		customer1_ui = gcnew Listing_Interface(
			listing_customer1_ui,			 listing_customer1_name,		  listing_customer1_author,
			listing_contractor1_button_info, listing_customer1_button_accept,
			listing_customer1_label_per_hr,  listing_customer1_per_hr,
			listing_customer1_label_hrs,	 listing_customer1_hrs,			  listing_customer1_total
		);

		customer2_ui = gcnew Listing_Interface(
			listing_customer2_ui,			 listing_customer2_name,		  listing_customer2_author,
			listing_contractor2_button_info, listing_customer2_button_accept,
			listing_customer2_label_per_hr,  listing_customer2_per_hr,
			listing_customer2_label_hrs,	 listing_customer2_hrs,			  listing_customer2_total
		);
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
private: System::Windows::Forms::Button^ button_edit;

	System::Windows::Forms::TextBox^ output_account_website;
	System::Windows::Forms::Panel^ menu_feed;
	System::Windows::Forms::Label^ label_feed;
	System::Windows::Forms::PictureBox^ bg_feed;
private: System::Windows::Forms::GroupBox^ group_contractors;

private: System::Windows::Forms::GroupBox^ group_customers;

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
private: System::Windows::Forms::GroupBox^ listing_customer1_ui;
private: System::Windows::Forms::Label^ listing_customer1_name;
private: System::Windows::Forms::Label^ listing_customer1_author;
private: System::Windows::Forms::Label^ listing_customer1_label_per_hr;
private: System::Windows::Forms::Label^ listing_customer1_per_hr;
private: System::Windows::Forms::Label^ listing_customer1_hrs;









private: System::Windows::Forms::Label^ listing_customer1_label_hrs;
private: System::Windows::Forms::Button^ listing_customer1_button_accept;

private: System::Windows::Forms::Label^ listing_customer1_total;








private: System::Windows::Forms::GroupBox^ listing_customer2_ui;
private: System::Windows::Forms::Label^ listing_customer2_total;
private: System::Windows::Forms::Button^ listing_customer2_button_accept;




private: System::Windows::Forms::Label^ listing_customer2_hrs;

private: System::Windows::Forms::Label^ listing_customer2_label_hrs;

private: System::Windows::Forms::Label^ listing_customer2_author;
private: System::Windows::Forms::Label^ listing_customer2_label_per_hr;
private: System::Windows::Forms::Label^ listing_customer2_per_hr;



private: System::Windows::Forms::Label^ listing_customer2_name;

private: System::Windows::Forms::GroupBox^ listing_contractor2_ui;
private: System::Windows::Forms::Label^ listing_contractor2_total;
private: System::Windows::Forms::Button^ listing_contractor2_button_hire;







private: System::Windows::Forms::Label^ listing_contractor2_label_hrs;

private: System::Windows::Forms::Label^ listing_contractor2_author;
private: System::Windows::Forms::Label^ listing_contractor2_label_per_hr;
private: System::Windows::Forms::Label^ listing_contractor2_per_hr;






private: System::Windows::Forms::Label^ listing_contractor2_name;




private: System::Windows::Forms::GroupBox^ listing_contractor1_ui;
private: System::Windows::Forms::Label^ listing_contractor1_total;
private: System::Windows::Forms::Button^ listing_contractor1_button_hire;






private: System::Windows::Forms::Label^ listing_contractor1_label_hrs;



private: System::Windows::Forms::Label^ listing_contractor1_author;
private: System::Windows::Forms::Label^ listing_contractor1_label_per_hr;
private: System::Windows::Forms::Label^ listing_contractor1_per_hr;





private: System::Windows::Forms::Label^ listing_contractor1_name;
private: System::Windows::Forms::NumericUpDown^ listing_contractor2_picker_hrs;

private: System::Windows::Forms::NumericUpDown^ listing_contractor1_picker_hrs;










private: System::Windows::Forms::GroupBox^ active_listing_1;
private: System::Windows::Forms::Label^ active_listing_1_total;
private: System::Windows::Forms::Button^ active_listing_1_finish;
private: System::Windows::Forms::Label^ active_listing_1_hrs;




private: System::Windows::Forms::Label^ active_listing_1_label_hrs;



private: System::Windows::Forms::Label^ active_listing_1_from;
private: System::Windows::Forms::Label^ active_listing_1_label_hourly;


private: System::Windows::Forms::Label^ active_listing_1_hourly;

private: System::Windows::Forms::Label^ active_listing_1_name;

private: System::Windows::Forms::GroupBox^ active_listing_2;
private: System::Windows::Forms::Label^ active_listing_2_total;
private: System::Windows::Forms::Button^ active_listing_2_finish;
private: System::Windows::Forms::Label^ active_listing_2_hrs;




private: System::Windows::Forms::Label^ active_listing_2_label_hrs;


private: System::Windows::Forms::Label^ active_listing_2_from;
private: System::Windows::Forms::Label^ active_listing_2_label_hourly;



private: System::Windows::Forms::Label^ active_listing_2_hourly;

private: System::Windows::Forms::Label^ active_listing_2_name;
private: System::Windows::Forms::Button^ listing_customer1_button_info;
private: System::Windows::Forms::Button^ listing_customer2_button_info;


private: System::Windows::Forms::Button^ listing_contractor2_button_info;

private: System::Windows::Forms::Button^ listing_contractor1_button_info;























	
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
		this->active_listing_2 = (gcnew System::Windows::Forms::GroupBox());
		this->active_listing_2_total = (gcnew System::Windows::Forms::Label());
		this->active_listing_2_finish = (gcnew System::Windows::Forms::Button());
		this->active_listing_2_hrs = (gcnew System::Windows::Forms::Label());
		this->active_listing_2_label_hrs = (gcnew System::Windows::Forms::Label());
		this->active_listing_2_from = (gcnew System::Windows::Forms::Label());
		this->active_listing_2_label_hourly = (gcnew System::Windows::Forms::Label());
		this->active_listing_2_hourly = (gcnew System::Windows::Forms::Label());
		this->active_listing_2_name = (gcnew System::Windows::Forms::Label());
		this->active_listing_1 = (gcnew System::Windows::Forms::GroupBox());
		this->active_listing_1_total = (gcnew System::Windows::Forms::Label());
		this->active_listing_1_finish = (gcnew System::Windows::Forms::Button());
		this->active_listing_1_hrs = (gcnew System::Windows::Forms::Label());
		this->active_listing_1_label_hrs = (gcnew System::Windows::Forms::Label());
		this->active_listing_1_from = (gcnew System::Windows::Forms::Label());
		this->active_listing_1_label_hourly = (gcnew System::Windows::Forms::Label());
		this->active_listing_1_hourly = (gcnew System::Windows::Forms::Label());
		this->active_listing_1_name = (gcnew System::Windows::Forms::Label());
		this->label_no_active_contracts = (gcnew System::Windows::Forms::RichTextBox());
		this->group_account_data = (gcnew System::Windows::Forms::GroupBox());
		this->label_account_website = (gcnew System::Windows::Forms::Label());
		this->label_account_extra = (gcnew System::Windows::Forms::Label());
		this->label_account_email = (gcnew System::Windows::Forms::Label());
		this->label_account_age = (gcnew System::Windows::Forms::Label());
		this->label_account_phone_number = (gcnew System::Windows::Forms::Label());
		this->output_account_age = (gcnew System::Windows::Forms::TextBox());
		this->output_account_website = (gcnew System::Windows::Forms::TextBox());
		this->button_edit = (gcnew System::Windows::Forms::Button());
		this->output_account_extra = (gcnew System::Windows::Forms::TextBox());
		this->output_account_email = (gcnew System::Windows::Forms::TextBox());
		this->output_account_phone_number = (gcnew System::Windows::Forms::TextBox());
		this->output_account_name = (gcnew System::Windows::Forms::TextBox());
		this->label_my_account = (gcnew System::Windows::Forms::Label());
		this->bg_my_account = (gcnew System::Windows::Forms::PictureBox());
		this->menu_feed = (gcnew System::Windows::Forms::Panel());
		this->button_feed_update = (gcnew System::Windows::Forms::Button());
		this->group_customers = (gcnew System::Windows::Forms::GroupBox());
		this->listing_customer2_ui = (gcnew System::Windows::Forms::GroupBox());
		this->listing_customer2_button_info = (gcnew System::Windows::Forms::Button());
		this->listing_customer2_total = (gcnew System::Windows::Forms::Label());
		this->listing_customer2_button_accept = (gcnew System::Windows::Forms::Button());
		this->listing_customer2_hrs = (gcnew System::Windows::Forms::Label());
		this->listing_customer2_label_hrs = (gcnew System::Windows::Forms::Label());
		this->listing_customer2_author = (gcnew System::Windows::Forms::Label());
		this->listing_customer2_label_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_customer2_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_customer2_name = (gcnew System::Windows::Forms::Label());
		this->listing_customer1_ui = (gcnew System::Windows::Forms::GroupBox());
		this->listing_customer1_button_info = (gcnew System::Windows::Forms::Button());
		this->listing_customer1_total = (gcnew System::Windows::Forms::Label());
		this->listing_customer1_button_accept = (gcnew System::Windows::Forms::Button());
		this->listing_customer1_hrs = (gcnew System::Windows::Forms::Label());
		this->listing_customer1_label_hrs = (gcnew System::Windows::Forms::Label());
		this->listing_customer1_author = (gcnew System::Windows::Forms::Label());
		this->listing_customer1_label_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_customer1_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_customer1_name = (gcnew System::Windows::Forms::Label());
		this->group_contractors = (gcnew System::Windows::Forms::GroupBox());
		this->listing_contractor2_ui = (gcnew System::Windows::Forms::GroupBox());
		this->listing_contractor2_button_info = (gcnew System::Windows::Forms::Button());
		this->listing_contractor2_picker_hrs = (gcnew System::Windows::Forms::NumericUpDown());
		this->listing_contractor2_total = (gcnew System::Windows::Forms::Label());
		this->listing_contractor2_button_hire = (gcnew System::Windows::Forms::Button());
		this->listing_contractor2_label_hrs = (gcnew System::Windows::Forms::Label());
		this->listing_contractor2_author = (gcnew System::Windows::Forms::Label());
		this->listing_contractor2_label_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_contractor2_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_contractor2_name = (gcnew System::Windows::Forms::Label());
		this->listing_contractor1_ui = (gcnew System::Windows::Forms::GroupBox());
		this->listing_contractor1_button_info = (gcnew System::Windows::Forms::Button());
		this->listing_contractor1_picker_hrs = (gcnew System::Windows::Forms::NumericUpDown());
		this->listing_contractor1_total = (gcnew System::Windows::Forms::Label());
		this->listing_contractor1_button_hire = (gcnew System::Windows::Forms::Button());
		this->listing_contractor1_label_hrs = (gcnew System::Windows::Forms::Label());
		this->listing_contractor1_author = (gcnew System::Windows::Forms::Label());
		this->listing_contractor1_label_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_contractor1_per_hr = (gcnew System::Windows::Forms::Label());
		this->listing_contractor1_name = (gcnew System::Windows::Forms::Label());
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
		this->active_listing_2->SuspendLayout();
		this->active_listing_1->SuspendLayout();
		this->group_account_data->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_my_account))->BeginInit();
		this->menu_feed->SuspendLayout();
		this->group_customers->SuspendLayout();
		this->listing_customer2_ui->SuspendLayout();
		this->listing_customer1_ui->SuspendLayout();
		this->group_contractors->SuspendLayout();
		this->listing_contractor2_ui->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listing_contractor2_picker_hrs))->BeginInit();
		this->listing_contractor1_ui->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listing_contractor1_picker_hrs))->BeginInit();
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
		this->menu_button_search->Location = System::Drawing::Point(4, 7);
		this->menu_button_search->Margin = System::Windows::Forms::Padding(4);
		this->menu_button_search->Name = L"menu_button_search";
		this->menu_button_search->Size = System::Drawing::Size(88, 94);
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
		this->sidebar->Location = System::Drawing::Point(578, 11);
		this->sidebar->Margin = System::Windows::Forms::Padding(4);
		this->sidebar->Name = L"sidebar";
		this->sidebar->Size = System::Drawing::Size(96, 503);
		this->sidebar->TabIndex = 1;
		// 
		// menu_button_info
		// 
		this->menu_button_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->menu_button_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->menu_button_info->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_info.Image")));
		this->menu_button_info->Location = System::Drawing::Point(4, 401);
		this->menu_button_info->Margin = System::Windows::Forms::Padding(4);
		this->menu_button_info->Name = L"menu_button_info";
		this->menu_button_info->Size = System::Drawing::Size(88, 94);
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
		this->menu_button_settings->Location = System::Drawing::Point(4, 304);
		this->menu_button_settings->Margin = System::Windows::Forms::Padding(4);
		this->menu_button_settings->Name = L"menu_button_settings";
		this->menu_button_settings->Size = System::Drawing::Size(88, 94);
		this->menu_button_settings->TabIndex = 3;
		this->menu_button_settings->UseVisualStyleBackColor = false;
		// 
		// menu_button_account
		// 
		this->menu_button_account->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->menu_button_account->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->menu_button_account->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_account.Image")));
		this->menu_button_account->Location = System::Drawing::Point(4, 203);
		this->menu_button_account->Margin = System::Windows::Forms::Padding(4);
		this->menu_button_account->Name = L"menu_button_account";
		this->menu_button_account->Size = System::Drawing::Size(88, 94);
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
		this->menu_button_feed->Location = System::Drawing::Point(4, 104);
		this->menu_button_feed->Margin = System::Windows::Forms::Padding(4);
		this->menu_button_feed->Name = L"menu_button_feed";
		this->menu_button_feed->Size = System::Drawing::Size(88, 94);
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
		this->menu_account->Location = System::Drawing::Point(10, 11);
		this->menu_account->Margin = System::Windows::Forms::Padding(4);
		this->menu_account->Name = L"menu_account";
		this->menu_account->Size = System::Drawing::Size(560, 502);
		this->menu_account->TabIndex = 2;
		// 
		// group_active_contracts
		// 
		this->group_active_contracts->Controls->Add(this->active_listing_2);
		this->group_active_contracts->Controls->Add(this->active_listing_1);
		this->group_active_contracts->Controls->Add(this->label_no_active_contracts);
		this->group_active_contracts->Location = System::Drawing::Point(287, 168);
		this->group_active_contracts->Margin = System::Windows::Forms::Padding(4);
		this->group_active_contracts->Name = L"group_active_contracts";
		this->group_active_contracts->Padding = System::Windows::Forms::Padding(4);
		this->group_active_contracts->Size = System::Drawing::Size(270, 327);
		this->group_active_contracts->TabIndex = 5;
		this->group_active_contracts->TabStop = false;
		this->group_active_contracts->Text = L"Активные контракты";
		// 
		// active_listing_2
		// 
		this->active_listing_2->Controls->Add(this->active_listing_2_total);
		this->active_listing_2->Controls->Add(this->active_listing_2_finish);
		this->active_listing_2->Controls->Add(this->active_listing_2_hrs);
		this->active_listing_2->Controls->Add(this->active_listing_2_label_hrs);
		this->active_listing_2->Controls->Add(this->active_listing_2_from);
		this->active_listing_2->Controls->Add(this->active_listing_2_label_hourly);
		this->active_listing_2->Controls->Add(this->active_listing_2_hourly);
		this->active_listing_2->Controls->Add(this->active_listing_2_name);
		this->active_listing_2->Font = (gcnew System::Drawing::Font(L"Roboto", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_2->Location = System::Drawing::Point(7, 168);
		this->active_listing_2->Margin = System::Windows::Forms::Padding(4);
		this->active_listing_2->Name = L"active_listing_2";
		this->active_listing_2->Padding = System::Windows::Forms::Padding(4);
		this->active_listing_2->Size = System::Drawing::Size(257, 147);
		this->active_listing_2->TabIndex = 8;
		this->active_listing_2->TabStop = false;
		this->active_listing_2->Visible = false;
		// 
		// active_listing_2_total
		// 
		this->active_listing_2_total->AutoSize = true;
		this->active_listing_2_total->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_2_total->Location = System::Drawing::Point(123, 117);
		this->active_listing_2_total->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_2_total->Name = L"active_listing_2_total";
		this->active_listing_2_total->Size = System::Drawing::Size(82, 20);
		this->active_listing_2_total->TabIndex = 7;
		this->active_listing_2_total->Text = L"Итого, ₽: ";
		// 
		// active_listing_2_finish
		// 
		this->active_listing_2_finish->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_2_finish->Location = System::Drawing::Point(5, 109);
		this->active_listing_2_finish->Margin = System::Windows::Forms::Padding(4);
		this->active_listing_2_finish->Name = L"active_listing_2_finish";
		this->active_listing_2_finish->Size = System::Drawing::Size(119, 34);
		this->active_listing_2_finish->TabIndex = 7;
		this->active_listing_2_finish->Text = L"Готово!";
		this->active_listing_2_finish->UseVisualStyleBackColor = true;
		// 
		// active_listing_2_hrs
		// 
		this->active_listing_2_hrs->AutoSize = true;
		this->active_listing_2_hrs->Location = System::Drawing::Point(111, 86);
		this->active_listing_2_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_2_hrs->Name = L"active_listing_2_hrs";
		this->active_listing_2_hrs->Size = System::Drawing::Size(126, 20);
		this->active_listing_2_hrs->TabIndex = 6;
		this->active_listing_2_hrs->Text = L"часов_работы";
		// 
		// active_listing_2_label_hrs
		// 
		this->active_listing_2_label_hrs->AutoSize = true;
		this->active_listing_2_label_hrs->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_2_label_hrs->Location = System::Drawing::Point(5, 86);
		this->active_listing_2_label_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_2_label_hrs->Name = L"active_listing_2_label_hrs";
		this->active_listing_2_label_hrs->Size = System::Drawing::Size(109, 20);
		this->active_listing_2_label_hrs->TabIndex = 5;
		this->active_listing_2_label_hrs->Text = L"всего часов:";
		// 
		// active_listing_2_from
		// 
		this->active_listing_2_from->AutoSize = true;
		this->active_listing_2_from->Location = System::Drawing::Point(5, 40);
		this->active_listing_2_from->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_2_from->Name = L"active_listing_2_from";
		this->active_listing_2_from->Size = System::Drawing::Size(134, 20);
		this->active_listing_2_from->TabIndex = 2;
		this->active_listing_2_from->Text = L"имя_заказчика";
		// 
		// active_listing_2_label_hourly
		// 
		this->active_listing_2_label_hourly->AutoSize = true;
		this->active_listing_2_label_hourly->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_2_label_hourly->Location = System::Drawing::Point(5, 63);
		this->active_listing_2_label_hourly->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_2_label_hourly->Name = L"active_listing_2_label_hourly";
		this->active_listing_2_label_hourly->Size = System::Drawing::Size(80, 20);
		this->active_listing_2_label_hourly->TabIndex = 3;
		this->active_listing_2_label_hourly->Text = L"за час, ₽:";
		// 
		// active_listing_2_hourly
		// 
		this->active_listing_2_hourly->AutoSize = true;
		this->active_listing_2_hourly->Location = System::Drawing::Point(89, 64);
		this->active_listing_2_hourly->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_2_hourly->Name = L"active_listing_2_hourly";
		this->active_listing_2_hourly->Size = System::Drawing::Size(127, 20);
		this->active_listing_2_hourly->TabIndex = 4;
		this->active_listing_2_hourly->Text = L"оплата_за_час";
		// 
		// active_listing_2_name
		// 
		this->active_listing_2_name->AutoSize = true;
		this->active_listing_2_name->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_2_name->Location = System::Drawing::Point(4, 11);
		this->active_listing_2_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_2_name->Name = L"active_listing_2_name";
		this->active_listing_2_name->Size = System::Drawing::Size(170, 24);
		this->active_listing_2_name->TabIndex = 0;
		this->active_listing_2_name->Text = L"название_заказа";
		// 
		// active_listing_1
		// 
		this->active_listing_1->Controls->Add(this->active_listing_1_total);
		this->active_listing_1->Controls->Add(this->active_listing_1_finish);
		this->active_listing_1->Controls->Add(this->active_listing_1_hrs);
		this->active_listing_1->Controls->Add(this->active_listing_1_label_hrs);
		this->active_listing_1->Controls->Add(this->active_listing_1_from);
		this->active_listing_1->Controls->Add(this->active_listing_1_label_hourly);
		this->active_listing_1->Controls->Add(this->active_listing_1_hourly);
		this->active_listing_1->Controls->Add(this->active_listing_1_name);
		this->active_listing_1->Font = (gcnew System::Drawing::Font(L"Roboto", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_1->Location = System::Drawing::Point(8, 13);
		this->active_listing_1->Margin = System::Windows::Forms::Padding(4);
		this->active_listing_1->Name = L"active_listing_1";
		this->active_listing_1->Padding = System::Windows::Forms::Padding(4);
		this->active_listing_1->Size = System::Drawing::Size(257, 147);
		this->active_listing_1->TabIndex = 1;
		this->active_listing_1->TabStop = false;
		this->active_listing_1->Visible = false;
		// 
		// active_listing_1_total
		// 
		this->active_listing_1_total->AutoSize = true;
		this->active_listing_1_total->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_1_total->Location = System::Drawing::Point(123, 117);
		this->active_listing_1_total->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_1_total->Name = L"active_listing_1_total";
		this->active_listing_1_total->Size = System::Drawing::Size(82, 20);
		this->active_listing_1_total->TabIndex = 7;
		this->active_listing_1_total->Text = L"Итого, ₽: ";
		// 
		// active_listing_1_finish
		// 
		this->active_listing_1_finish->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_1_finish->Location = System::Drawing::Point(5, 109);
		this->active_listing_1_finish->Margin = System::Windows::Forms::Padding(4);
		this->active_listing_1_finish->Name = L"active_listing_1_finish";
		this->active_listing_1_finish->Size = System::Drawing::Size(119, 34);
		this->active_listing_1_finish->TabIndex = 7;
		this->active_listing_1_finish->Text = L"Готово!";
		this->active_listing_1_finish->UseVisualStyleBackColor = true;
		this->active_listing_1_finish->Click += gcnew System::EventHandler(this, &Main_Menu::finish_active_listing);
		// 
		// active_listing_1_hrs
		// 
		this->active_listing_1_hrs->AutoSize = true;
		this->active_listing_1_hrs->Location = System::Drawing::Point(111, 86);
		this->active_listing_1_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_1_hrs->Name = L"active_listing_1_hrs";
		this->active_listing_1_hrs->Size = System::Drawing::Size(126, 20);
		this->active_listing_1_hrs->TabIndex = 6;
		this->active_listing_1_hrs->Text = L"часов_работы";
		// 
		// active_listing_1_label_hrs
		// 
		this->active_listing_1_label_hrs->AutoSize = true;
		this->active_listing_1_label_hrs->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_1_label_hrs->Location = System::Drawing::Point(5, 86);
		this->active_listing_1_label_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_1_label_hrs->Name = L"active_listing_1_label_hrs";
		this->active_listing_1_label_hrs->Size = System::Drawing::Size(109, 20);
		this->active_listing_1_label_hrs->TabIndex = 5;
		this->active_listing_1_label_hrs->Text = L"всего часов:";
		// 
		// active_listing_1_from
		// 
		this->active_listing_1_from->AutoSize = true;
		this->active_listing_1_from->Location = System::Drawing::Point(5, 40);
		this->active_listing_1_from->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_1_from->Name = L"active_listing_1_from";
		this->active_listing_1_from->Size = System::Drawing::Size(134, 20);
		this->active_listing_1_from->TabIndex = 2;
		this->active_listing_1_from->Text = L"имя_заказчика";
		// 
		// active_listing_1_label_hourly
		// 
		this->active_listing_1_label_hourly->AutoSize = true;
		this->active_listing_1_label_hourly->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_1_label_hourly->Location = System::Drawing::Point(5, 63);
		this->active_listing_1_label_hourly->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_1_label_hourly->Name = L"active_listing_1_label_hourly";
		this->active_listing_1_label_hourly->Size = System::Drawing::Size(80, 20);
		this->active_listing_1_label_hourly->TabIndex = 3;
		this->active_listing_1_label_hourly->Text = L"за час, ₽:";
		// 
		// active_listing_1_hourly
		// 
		this->active_listing_1_hourly->AutoSize = true;
		this->active_listing_1_hourly->Location = System::Drawing::Point(89, 64);
		this->active_listing_1_hourly->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_1_hourly->Name = L"active_listing_1_hourly";
		this->active_listing_1_hourly->Size = System::Drawing::Size(127, 20);
		this->active_listing_1_hourly->TabIndex = 4;
		this->active_listing_1_hourly->Text = L"оплата_за_час";
		// 
		// active_listing_1_name
		// 
		this->active_listing_1_name->AutoSize = true;
		this->active_listing_1_name->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->active_listing_1_name->Location = System::Drawing::Point(4, 11);
		this->active_listing_1_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->active_listing_1_name->Name = L"active_listing_1_name";
		this->active_listing_1_name->Size = System::Drawing::Size(170, 24);
		this->active_listing_1_name->TabIndex = 0;
		this->active_listing_1_name->Text = L"название_заказа";
		// 
		// label_no_active_contracts
		// 
		this->label_no_active_contracts->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->label_no_active_contracts->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_no_active_contracts->Location = System::Drawing::Point(1000, 113);
		this->label_no_active_contracts->Margin = System::Windows::Forms::Padding(4);
		this->label_no_active_contracts->Name = L"label_no_active_contracts";
		this->label_no_active_contracts->ReadOnly = true;
		this->label_no_active_contracts->Size = System::Drawing::Size(246, 83);
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
		this->group_account_data->Controls->Add(this->button_edit);
		this->group_account_data->Controls->Add(this->output_account_extra);
		this->group_account_data->Controls->Add(this->output_account_email);
		this->group_account_data->Controls->Add(this->output_account_phone_number);
		this->group_account_data->Controls->Add(this->output_account_name);
		this->group_account_data->Location = System::Drawing::Point(7, 168);
		this->group_account_data->Margin = System::Windows::Forms::Padding(4);
		this->group_account_data->Name = L"group_account_data";
		this->group_account_data->Padding = System::Windows::Forms::Padding(4);
		this->group_account_data->Size = System::Drawing::Size(275, 327);
		this->group_account_data->TabIndex = 2;
		this->group_account_data->TabStop = false;
		this->group_account_data->Text = L"Данные";
		// 
		// label_account_website
		// 
		this->label_account_website->AutoSize = true;
		this->label_account_website->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_website->Location = System::Drawing::Point(5, 173);
		this->label_account_website->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_account_website->Name = L"label_account_website";
		this->label_account_website->Size = System::Drawing::Size(53, 20);
		this->label_account_website->TabIndex = 9;
		this->label_account_website->Text = L"Сайт:";
		// 
		// label_account_extra
		// 
		this->label_account_extra->AutoSize = true;
		this->label_account_extra->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_extra->Location = System::Drawing::Point(5, 143);
		this->label_account_extra->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_account_extra->Name = L"label_account_extra";
		this->label_account_extra->Size = System::Drawing::Size(52, 20);
		this->label_account_extra->TabIndex = 8;
		this->label_account_extra->Text = L"Доп.:";
		// 
		// label_account_email
		// 
		this->label_account_email->AutoSize = true;
		this->label_account_email->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_email->Location = System::Drawing::Point(5, 113);
		this->label_account_email->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_account_email->Name = L"label_account_email";
		this->label_account_email->Size = System::Drawing::Size(64, 20);
		this->label_account_email->TabIndex = 7;
		this->label_account_email->Text = L"e-mail:";
		// 
		// label_account_age
		// 
		this->label_account_age->AutoSize = true;
		this->label_account_age->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_age->Location = System::Drawing::Point(5, 53);
		this->label_account_age->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_account_age->Name = L"label_account_age";
		this->label_account_age->Size = System::Drawing::Size(83, 20);
		this->label_account_age->TabIndex = 6;
		this->label_account_age->Text = L"label_age";
		// 
		// label_account_phone_number
		// 
		this->label_account_phone_number->AutoSize = true;
		this->label_account_phone_number->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_account_phone_number->Location = System::Drawing::Point(5, 83);
		this->label_account_phone_number->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_account_phone_number->Name = L"label_account_phone_number";
		this->label_account_phone_number->Size = System::Drawing::Size(84, 20);
		this->label_account_phone_number->TabIndex = 6;
		this->label_account_phone_number->Text = L"Телефон:";
		// 
		// output_account_age
		// 
		this->output_account_age->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->output_account_age->Location = System::Drawing::Point(115, 50);
		this->output_account_age->Margin = System::Windows::Forms::Padding(4);
		this->output_account_age->Name = L"output_account_age";
		this->output_account_age->ReadOnly = true;
		this->output_account_age->Size = System::Drawing::Size(154, 28);
		this->output_account_age->TabIndex = 5;
		// 
		// output_account_website
		// 
		this->output_account_website->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->output_account_website->Location = System::Drawing::Point(69, 172);
		this->output_account_website->Margin = System::Windows::Forms::Padding(4);
		this->output_account_website->Name = L"output_account_website";
		this->output_account_website->ReadOnly = true;
		this->output_account_website->Size = System::Drawing::Size(201, 28);
		this->output_account_website->TabIndex = 4;
		// 
		// button_edit
		// 
		this->button_edit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(191)),
			static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->button_edit->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button_edit->Location = System::Drawing::Point(0, 202);
		this->button_edit->Margin = System::Windows::Forms::Padding(4);
		this->button_edit->Name = L"button_edit";
		this->button_edit->Size = System::Drawing::Size(270, 37);
		this->button_edit->TabIndex = 3;
		this->button_edit->Text = L"Редактировать";
		this->button_edit->UseVisualStyleBackColor = false;
		this->button_edit->Click += gcnew System::EventHandler(this, &Main_Menu::edit_account_data);
		// 
		// output_account_extra
		// 
		this->output_account_extra->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->output_account_extra->Location = System::Drawing::Point(69, 142);
		this->output_account_extra->Margin = System::Windows::Forms::Padding(4);
		this->output_account_extra->Name = L"output_account_extra";
		this->output_account_extra->ReadOnly = true;
		this->output_account_extra->Size = System::Drawing::Size(201, 28);
		this->output_account_extra->TabIndex = 3;
		// 
		// output_account_email
		// 
		this->output_account_email->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->output_account_email->Location = System::Drawing::Point(69, 112);
		this->output_account_email->Margin = System::Windows::Forms::Padding(4);
		this->output_account_email->Name = L"output_account_email";
		this->output_account_email->ReadOnly = true;
		this->output_account_email->Size = System::Drawing::Size(201, 28);
		this->output_account_email->TabIndex = 2;
		// 
		// output_account_phone_number
		// 
		this->output_account_phone_number->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->output_account_phone_number->Location = System::Drawing::Point(115, 80);
		this->output_account_phone_number->Margin = System::Windows::Forms::Padding(4);
		this->output_account_phone_number->Name = L"output_account_phone_number";
		this->output_account_phone_number->ReadOnly = true;
		this->output_account_phone_number->Size = System::Drawing::Size(154, 28);
		this->output_account_phone_number->TabIndex = 1;
		// 
		// output_account_name
		// 
		this->output_account_name->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->output_account_name->Location = System::Drawing::Point(5, 20);
		this->output_account_name->Margin = System::Windows::Forms::Padding(4);
		this->output_account_name->Name = L"output_account_name";
		this->output_account_name->ReadOnly = true;
		this->output_account_name->Size = System::Drawing::Size(265, 28);
		this->output_account_name->TabIndex = 0;
		// 
		// label_my_account
		// 
		this->label_my_account->AutoSize = true;
		this->label_my_account->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)),
			static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)));
		this->label_my_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_my_account->Location = System::Drawing::Point(7, 7);
		this->label_my_account->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
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
		this->bg_my_account->Margin = System::Windows::Forms::Padding(4);
		this->bg_my_account->Name = L"bg_my_account";
		this->bg_my_account->Size = System::Drawing::Size(560, 169);
		this->bg_my_account->TabIndex = 1;
		this->bg_my_account->TabStop = false;
		// 
		// menu_feed
		// 
		this->menu_feed->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->menu_feed->Controls->Add(this->button_feed_update);
		this->menu_feed->Controls->Add(this->group_customers);
		this->menu_feed->Controls->Add(this->group_contractors);
		this->menu_feed->Controls->Add(this->label_feed);
		this->menu_feed->Controls->Add(this->bg_feed);
		this->menu_feed->Location = System::Drawing::Point(10, 11);
		this->menu_feed->Margin = System::Windows::Forms::Padding(4);
		this->menu_feed->Name = L"menu_feed";
		this->menu_feed->Size = System::Drawing::Size(560, 502);
		this->menu_feed->TabIndex = 3;
		// 
		// button_feed_update
		// 
		this->button_feed_update->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_feed_update.BackgroundImage")));
		this->button_feed_update->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->button_feed_update->Location = System::Drawing::Point(246, 4);
		this->button_feed_update->Margin = System::Windows::Forms::Padding(4);
		this->button_feed_update->Name = L"button_feed_update";
		this->button_feed_update->RightToLeft = System::Windows::Forms::RightToLeft::No;
		this->button_feed_update->Size = System::Drawing::Size(35, 37);
		this->button_feed_update->TabIndex = 0;
		this->button_feed_update->UseVisualStyleBackColor = true;
		this->button_feed_update->Click += gcnew System::EventHandler(this, &Main_Menu::update_feed);
		// 
		// group_customers
		// 
		this->group_customers->Controls->Add(this->listing_customer2_ui);
		this->group_customers->Controls->Add(this->listing_customer1_ui);
		this->group_customers->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->group_customers->Location = System::Drawing::Point(282, 168);
		this->group_customers->Margin = System::Windows::Forms::Padding(4);
		this->group_customers->Name = L"group_customers";
		this->group_customers->Padding = System::Windows::Forms::Padding(4);
		this->group_customers->Size = System::Drawing::Size(270, 323);
		this->group_customers->TabIndex = 6;
		this->group_customers->TabStop = false;
		this->group_customers->Text = L"Ищут подрядчика";
		// 
		// listing_customer2_ui
		// 
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_button_info);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_total);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_button_accept);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_hrs);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_label_hrs);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_author);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_label_per_hr);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_per_hr);
		this->listing_customer2_ui->Controls->Add(this->listing_customer2_name);
		this->listing_customer2_ui->Font = (gcnew System::Drawing::Font(L"Roboto", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer2_ui->Location = System::Drawing::Point(8, 168);
		this->listing_customer2_ui->Margin = System::Windows::Forms::Padding(4);
		this->listing_customer2_ui->Name = L"listing_customer2_ui";
		this->listing_customer2_ui->Padding = System::Windows::Forms::Padding(4);
		this->listing_customer2_ui->Size = System::Drawing::Size(254, 147);
		this->listing_customer2_ui->TabIndex = 8;
		this->listing_customer2_ui->TabStop = false;
		// 
		// listing_customer2_button_info
		// 
		this->listing_customer2_button_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->listing_customer2_button_info->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listing_customer2_button_info.BackgroundImage")));
		this->listing_customer2_button_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->listing_customer2_button_info->Location = System::Drawing::Point(5, 35);
		this->listing_customer2_button_info->Margin = System::Windows::Forms::Padding(4);
		this->listing_customer2_button_info->Name = L"listing_customer2_button_info";
		this->listing_customer2_button_info->Size = System::Drawing::Size(30, 30);
		this->listing_customer2_button_info->TabIndex = 8;
		this->listing_customer2_button_info->UseVisualStyleBackColor = false;
		// 
		// listing_customer2_total
		// 
		this->listing_customer2_total->AutoSize = true;
		this->listing_customer2_total->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer2_total->Location = System::Drawing::Point(123, 117);
		this->listing_customer2_total->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer2_total->Name = L"listing_customer2_total";
		this->listing_customer2_total->Size = System::Drawing::Size(82, 20);
		this->listing_customer2_total->TabIndex = 7;
		this->listing_customer2_total->Text = L"Итого, ₽: ";
		// 
		// listing_customer2_button_accept
		// 
		this->listing_customer2_button_accept->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer2_button_accept->Location = System::Drawing::Point(5, 109);
		this->listing_customer2_button_accept->Margin = System::Windows::Forms::Padding(4);
		this->listing_customer2_button_accept->Name = L"listing_customer2_button_accept";
		this->listing_customer2_button_accept->Size = System::Drawing::Size(119, 34);
		this->listing_customer2_button_accept->TabIndex = 7;
		this->listing_customer2_button_accept->Text = L"За работу!";
		this->listing_customer2_button_accept->UseVisualStyleBackColor = true;
		this->listing_customer2_button_accept->Click += gcnew System::EventHandler(this, &Main_Menu::accept_listing);
		// 
		// listing_customer2_hrs
		// 
		this->listing_customer2_hrs->AutoSize = true;
		this->listing_customer2_hrs->Location = System::Drawing::Point(111, 86);
		this->listing_customer2_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer2_hrs->Name = L"listing_customer2_hrs";
		this->listing_customer2_hrs->Size = System::Drawing::Size(126, 20);
		this->listing_customer2_hrs->TabIndex = 6;
		this->listing_customer2_hrs->Text = L"часов_работы";
		// 
		// listing_customer2_label_hrs
		// 
		this->listing_customer2_label_hrs->AutoSize = true;
		this->listing_customer2_label_hrs->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer2_label_hrs->Location = System::Drawing::Point(5, 86);
		this->listing_customer2_label_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer2_label_hrs->Name = L"listing_customer2_label_hrs";
		this->listing_customer2_label_hrs->Size = System::Drawing::Size(109, 20);
		this->listing_customer2_label_hrs->TabIndex = 5;
		this->listing_customer2_label_hrs->Text = L"всего часов:";
		// 
		// listing_customer2_author
		// 
		this->listing_customer2_author->AutoSize = true;
		this->listing_customer2_author->Location = System::Drawing::Point(35, 40);
		this->listing_customer2_author->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer2_author->Name = L"listing_customer2_author";
		this->listing_customer2_author->Size = System::Drawing::Size(134, 20);
		this->listing_customer2_author->TabIndex = 2;
		this->listing_customer2_author->Text = L"имя_заказчика";
		// 
		// listing_customer2_label_per_hr
		// 
		this->listing_customer2_label_per_hr->AutoSize = true;
		this->listing_customer2_label_per_hr->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->listing_customer2_label_per_hr->Location = System::Drawing::Point(5, 63);
		this->listing_customer2_label_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer2_label_per_hr->Name = L"listing_customer2_label_per_hr";
		this->listing_customer2_label_per_hr->Size = System::Drawing::Size(80, 20);
		this->listing_customer2_label_per_hr->TabIndex = 3;
		this->listing_customer2_label_per_hr->Text = L"за час, ₽:";
		// 
		// listing_customer2_per_hr
		// 
		this->listing_customer2_per_hr->AutoSize = true;
		this->listing_customer2_per_hr->Location = System::Drawing::Point(89, 64);
		this->listing_customer2_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer2_per_hr->Name = L"listing_customer2_per_hr";
		this->listing_customer2_per_hr->Size = System::Drawing::Size(127, 20);
		this->listing_customer2_per_hr->TabIndex = 4;
		this->listing_customer2_per_hr->Text = L"оплата_за_час";
		// 
		// listing_customer2_name
		// 
		this->listing_customer2_name->AutoSize = true;
		this->listing_customer2_name->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer2_name->Location = System::Drawing::Point(4, 11);
		this->listing_customer2_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer2_name->Name = L"listing_customer2_name";
		this->listing_customer2_name->Size = System::Drawing::Size(170, 24);
		this->listing_customer2_name->TabIndex = 0;
		this->listing_customer2_name->Text = L"название_заказа";
		// 
		// listing_customer1_ui
		// 
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_button_info);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_total);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_button_accept);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_hrs);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_label_hrs);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_author);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_label_per_hr);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_per_hr);
		this->listing_customer1_ui->Controls->Add(this->listing_customer1_name);
		this->listing_customer1_ui->Font = (gcnew System::Drawing::Font(L"Roboto", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer1_ui->Location = System::Drawing::Point(8, 20);
		this->listing_customer1_ui->Margin = System::Windows::Forms::Padding(4);
		this->listing_customer1_ui->Name = L"listing_customer1_ui";
		this->listing_customer1_ui->Padding = System::Windows::Forms::Padding(4);
		this->listing_customer1_ui->Size = System::Drawing::Size(254, 147);
		this->listing_customer1_ui->TabIndex = 0;
		this->listing_customer1_ui->TabStop = false;
		// 
		// listing_customer1_button_info
		// 
		this->listing_customer1_button_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->listing_customer1_button_info->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listing_customer1_button_info.BackgroundImage")));
		this->listing_customer1_button_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->listing_customer1_button_info->Location = System::Drawing::Point(5, 35);
		this->listing_customer1_button_info->Margin = System::Windows::Forms::Padding(4);
		this->listing_customer1_button_info->Name = L"listing_customer1_button_info";
		this->listing_customer1_button_info->Size = System::Drawing::Size(30, 30);
		this->listing_customer1_button_info->TabIndex = 5;
		this->listing_customer1_button_info->UseVisualStyleBackColor = false;
		// 
		// listing_customer1_total
		// 
		this->listing_customer1_total->AutoSize = true;
		this->listing_customer1_total->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer1_total->Location = System::Drawing::Point(123, 117);
		this->listing_customer1_total->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer1_total->Name = L"listing_customer1_total";
		this->listing_customer1_total->Size = System::Drawing::Size(82, 20);
		this->listing_customer1_total->TabIndex = 7;
		this->listing_customer1_total->Text = L"Итого, ₽: ";
		// 
		// listing_customer1_button_accept
		// 
		this->listing_customer1_button_accept->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer1_button_accept->Location = System::Drawing::Point(5, 109);
		this->listing_customer1_button_accept->Margin = System::Windows::Forms::Padding(4);
		this->listing_customer1_button_accept->Name = L"listing_customer1_button_accept";
		this->listing_customer1_button_accept->Size = System::Drawing::Size(119, 34);
		this->listing_customer1_button_accept->TabIndex = 7;
		this->listing_customer1_button_accept->Text = L"За работу!";
		this->listing_customer1_button_accept->UseVisualStyleBackColor = true;
		this->listing_customer1_button_accept->Click += gcnew System::EventHandler(this, &Main_Menu::accept_listing);
		// 
		// listing_customer1_hrs
		// 
		this->listing_customer1_hrs->AutoSize = true;
		this->listing_customer1_hrs->Location = System::Drawing::Point(111, 86);
		this->listing_customer1_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer1_hrs->Name = L"listing_customer1_hrs";
		this->listing_customer1_hrs->Size = System::Drawing::Size(126, 20);
		this->listing_customer1_hrs->TabIndex = 6;
		this->listing_customer1_hrs->Text = L"часов_работы";
		// 
		// listing_customer1_label_hrs
		// 
		this->listing_customer1_label_hrs->AutoSize = true;
		this->listing_customer1_label_hrs->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer1_label_hrs->Location = System::Drawing::Point(5, 86);
		this->listing_customer1_label_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer1_label_hrs->Name = L"listing_customer1_label_hrs";
		this->listing_customer1_label_hrs->Size = System::Drawing::Size(109, 20);
		this->listing_customer1_label_hrs->TabIndex = 5;
		this->listing_customer1_label_hrs->Text = L"всего часов:";
		// 
		// listing_customer1_author
		// 
		this->listing_customer1_author->AutoSize = true;
		this->listing_customer1_author->Location = System::Drawing::Point(35, 40);
		this->listing_customer1_author->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer1_author->Name = L"listing_customer1_author";
		this->listing_customer1_author->Size = System::Drawing::Size(134, 20);
		this->listing_customer1_author->TabIndex = 2;
		this->listing_customer1_author->Text = L"имя_заказчика";
		// 
		// listing_customer1_label_per_hr
		// 
		this->listing_customer1_label_per_hr->AutoSize = true;
		this->listing_customer1_label_per_hr->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->listing_customer1_label_per_hr->Location = System::Drawing::Point(5, 63);
		this->listing_customer1_label_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer1_label_per_hr->Name = L"listing_customer1_label_per_hr";
		this->listing_customer1_label_per_hr->Size = System::Drawing::Size(80, 20);
		this->listing_customer1_label_per_hr->TabIndex = 3;
		this->listing_customer1_label_per_hr->Text = L"за час, ₽:";
		// 
		// listing_customer1_per_hr
		// 
		this->listing_customer1_per_hr->AutoSize = true;
		this->listing_customer1_per_hr->Location = System::Drawing::Point(89, 64);
		this->listing_customer1_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer1_per_hr->Name = L"listing_customer1_per_hr";
		this->listing_customer1_per_hr->Size = System::Drawing::Size(127, 20);
		this->listing_customer1_per_hr->TabIndex = 4;
		this->listing_customer1_per_hr->Text = L"оплата_за_час";
		// 
		// listing_customer1_name
		// 
		this->listing_customer1_name->AutoSize = true;
		this->listing_customer1_name->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_customer1_name->Location = System::Drawing::Point(4, 11);
		this->listing_customer1_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_customer1_name->Name = L"listing_customer1_name";
		this->listing_customer1_name->Size = System::Drawing::Size(170, 24);
		this->listing_customer1_name->TabIndex = 0;
		this->listing_customer1_name->Text = L"название_заказа";
		// 
		// group_contractors
		// 
		this->group_contractors->Controls->Add(this->listing_contractor2_ui);
		this->group_contractors->Controls->Add(this->listing_contractor1_ui);
		this->group_contractors->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->group_contractors->Location = System::Drawing::Point(7, 168);
		this->group_contractors->Margin = System::Windows::Forms::Padding(4);
		this->group_contractors->Name = L"group_contractors";
		this->group_contractors->Padding = System::Windows::Forms::Padding(4);
		this->group_contractors->Size = System::Drawing::Size(270, 323);
		this->group_contractors->TabIndex = 5;
		this->group_contractors->TabStop = false;
		this->group_contractors->Text = L"Ищут заказчика";
		// 
		// listing_contractor2_ui
		// 
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_button_info);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_picker_hrs);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_total);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_button_hire);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_label_hrs);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_author);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_label_per_hr);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_per_hr);
		this->listing_contractor2_ui->Controls->Add(this->listing_contractor2_name);
		this->listing_contractor2_ui->Font = (gcnew System::Drawing::Font(L"Roboto", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor2_ui->Location = System::Drawing::Point(8, 168);
		this->listing_contractor2_ui->Margin = System::Windows::Forms::Padding(4);
		this->listing_contractor2_ui->Name = L"listing_contractor2_ui";
		this->listing_contractor2_ui->Padding = System::Windows::Forms::Padding(4);
		this->listing_contractor2_ui->Size = System::Drawing::Size(254, 147);
		this->listing_contractor2_ui->TabIndex = 9;
		this->listing_contractor2_ui->TabStop = false;
		// 
		// listing_contractor2_button_info
		// 
		this->listing_contractor2_button_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->listing_contractor2_button_info->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listing_contractor2_button_info.BackgroundImage")));
		this->listing_contractor2_button_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->listing_contractor2_button_info->Location = System::Drawing::Point(5, 35);
		this->listing_contractor2_button_info->Margin = System::Windows::Forms::Padding(4);
		this->listing_contractor2_button_info->Name = L"listing_contractor2_button_info";
		this->listing_contractor2_button_info->Size = System::Drawing::Size(30, 30);
		this->listing_contractor2_button_info->TabIndex = 10;
		this->listing_contractor2_button_info->UseVisualStyleBackColor = false;
		// 
		// listing_contractor2_picker_hrs
		// 
		this->listing_contractor2_picker_hrs->Location = System::Drawing::Point(114, 84);
		this->listing_contractor2_picker_hrs->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
		this->listing_contractor2_picker_hrs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		this->listing_contractor2_picker_hrs->Name = L"listing_contractor2_picker_hrs";
		this->listing_contractor2_picker_hrs->Size = System::Drawing::Size(40, 28);
		this->listing_contractor2_picker_hrs->TabIndex = 10;
		this->listing_contractor2_picker_hrs->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		this->listing_contractor2_picker_hrs->ValueChanged += gcnew System::EventHandler(this, &Main_Menu::feed_contracts_length_adjusted);
		// 
		// listing_contractor2_total
		// 
		this->listing_contractor2_total->AutoSize = true;
		this->listing_contractor2_total->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor2_total->Location = System::Drawing::Point(123, 117);
		this->listing_contractor2_total->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor2_total->Name = L"listing_contractor2_total";
		this->listing_contractor2_total->Size = System::Drawing::Size(82, 20);
		this->listing_contractor2_total->TabIndex = 7;
		this->listing_contractor2_total->Text = L"Итого, ₽: ";
		// 
		// listing_contractor2_button_hire
		// 
		this->listing_contractor2_button_hire->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor2_button_hire->Location = System::Drawing::Point(5, 109);
		this->listing_contractor2_button_hire->Margin = System::Windows::Forms::Padding(4);
		this->listing_contractor2_button_hire->Name = L"listing_contractor2_button_hire";
		this->listing_contractor2_button_hire->Size = System::Drawing::Size(119, 34);
		this->listing_contractor2_button_hire->TabIndex = 7;
		this->listing_contractor2_button_hire->Text = L"Нанять!";
		this->listing_contractor2_button_hire->UseVisualStyleBackColor = true;
		this->listing_contractor2_button_hire->Click += gcnew System::EventHandler(this, &Main_Menu::accept_listing);
		// 
		// listing_contractor2_label_hrs
		// 
		this->listing_contractor2_label_hrs->AutoSize = true;
		this->listing_contractor2_label_hrs->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor2_label_hrs->Location = System::Drawing::Point(5, 86);
		this->listing_contractor2_label_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor2_label_hrs->Name = L"listing_contractor2_label_hrs";
		this->listing_contractor2_label_hrs->Size = System::Drawing::Size(109, 20);
		this->listing_contractor2_label_hrs->TabIndex = 5;
		this->listing_contractor2_label_hrs->Text = L"всего часов:";
		// 
		// listing_contractor2_author
		// 
		this->listing_contractor2_author->AutoSize = true;
		this->listing_contractor2_author->Location = System::Drawing::Point(35, 40);
		this->listing_contractor2_author->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor2_author->Name = L"listing_contractor2_author";
		this->listing_contractor2_author->Size = System::Drawing::Size(149, 20);
		this->listing_contractor2_author->TabIndex = 2;
		this->listing_contractor2_author->Text = L"имя_подрядчика";
		// 
		// listing_contractor2_label_per_hr
		// 
		this->listing_contractor2_label_per_hr->AutoSize = true;
		this->listing_contractor2_label_per_hr->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->listing_contractor2_label_per_hr->Location = System::Drawing::Point(5, 63);
		this->listing_contractor2_label_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor2_label_per_hr->Name = L"listing_contractor2_label_per_hr";
		this->listing_contractor2_label_per_hr->Size = System::Drawing::Size(80, 20);
		this->listing_contractor2_label_per_hr->TabIndex = 3;
		this->listing_contractor2_label_per_hr->Text = L"за час, ₽:";
		// 
		// listing_contractor2_per_hr
		// 
		this->listing_contractor2_per_hr->AutoSize = true;
		this->listing_contractor2_per_hr->Location = System::Drawing::Point(89, 64);
		this->listing_contractor2_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor2_per_hr->Name = L"listing_contractor2_per_hr";
		this->listing_contractor2_per_hr->Size = System::Drawing::Size(117, 20);
		this->listing_contractor2_per_hr->TabIndex = 4;
		this->listing_contractor2_per_hr->Text = L"плата_за_час";
		// 
		// listing_contractor2_name
		// 
		this->listing_contractor2_name->AutoSize = true;
		this->listing_contractor2_name->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor2_name->Location = System::Drawing::Point(4, 11);
		this->listing_contractor2_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor2_name->Name = L"listing_contractor2_name";
		this->listing_contractor2_name->Size = System::Drawing::Size(186, 24);
		this->listing_contractor2_name->TabIndex = 0;
		this->listing_contractor2_name->Text = L"название_подряда";
		// 
		// listing_contractor1_ui
		// 
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_button_info);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_picker_hrs);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_total);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_button_hire);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_label_hrs);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_author);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_label_per_hr);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_per_hr);
		this->listing_contractor1_ui->Controls->Add(this->listing_contractor1_name);
		this->listing_contractor1_ui->Font = (gcnew System::Drawing::Font(L"Roboto", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor1_ui->Location = System::Drawing::Point(8, 20);
		this->listing_contractor1_ui->Margin = System::Windows::Forms::Padding(4);
		this->listing_contractor1_ui->Name = L"listing_contractor1_ui";
		this->listing_contractor1_ui->Padding = System::Windows::Forms::Padding(4);
		this->listing_contractor1_ui->Size = System::Drawing::Size(254, 147);
		this->listing_contractor1_ui->TabIndex = 8;
		this->listing_contractor1_ui->TabStop = false;
		// 
		// listing_contractor1_button_info
		// 
		this->listing_contractor1_button_info->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
			static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
		this->listing_contractor1_button_info->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listing_contractor1_button_info.BackgroundImage")));
		this->listing_contractor1_button_info->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->listing_contractor1_button_info->Location = System::Drawing::Point(5, 35);
		this->listing_contractor1_button_info->Margin = System::Windows::Forms::Padding(4);
		this->listing_contractor1_button_info->Name = L"listing_contractor1_button_info";
		this->listing_contractor1_button_info->Size = System::Drawing::Size(30, 30);
		this->listing_contractor1_button_info->TabIndex = 9;
		this->listing_contractor1_button_info->UseVisualStyleBackColor = false;
		// 
		// listing_contractor1_picker_hrs
		// 
		this->listing_contractor1_picker_hrs->Location = System::Drawing::Point(114, 84);
		this->listing_contractor1_picker_hrs->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
		this->listing_contractor1_picker_hrs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		this->listing_contractor1_picker_hrs->Name = L"listing_contractor1_picker_hrs";
		this->listing_contractor1_picker_hrs->Size = System::Drawing::Size(40, 28);
		this->listing_contractor1_picker_hrs->TabIndex = 9;
		this->listing_contractor1_picker_hrs->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		this->listing_contractor1_picker_hrs->ValueChanged += gcnew System::EventHandler(this, &Main_Menu::feed_contracts_length_adjusted);
		// 
		// listing_contractor1_total
		// 
		this->listing_contractor1_total->AutoSize = true;
		this->listing_contractor1_total->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor1_total->Location = System::Drawing::Point(123, 117);
		this->listing_contractor1_total->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor1_total->Name = L"listing_contractor1_total";
		this->listing_contractor1_total->Size = System::Drawing::Size(82, 20);
		this->listing_contractor1_total->TabIndex = 7;
		this->listing_contractor1_total->Text = L"Итого, ₽: ";
		// 
		// listing_contractor1_button_hire
		// 
		this->listing_contractor1_button_hire->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor1_button_hire->Location = System::Drawing::Point(5, 109);
		this->listing_contractor1_button_hire->Margin = System::Windows::Forms::Padding(4);
		this->listing_contractor1_button_hire->Name = L"listing_contractor1_button_hire";
		this->listing_contractor1_button_hire->Size = System::Drawing::Size(119, 34);
		this->listing_contractor1_button_hire->TabIndex = 7;
		this->listing_contractor1_button_hire->Text = L"Нанять!";
		this->listing_contractor1_button_hire->UseVisualStyleBackColor = true;
		this->listing_contractor1_button_hire->Click += gcnew System::EventHandler(this, &Main_Menu::accept_listing);
		// 
		// listing_contractor1_label_hrs
		// 
		this->listing_contractor1_label_hrs->AutoSize = true;
		this->listing_contractor1_label_hrs->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor1_label_hrs->Location = System::Drawing::Point(5, 86);
		this->listing_contractor1_label_hrs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor1_label_hrs->Name = L"listing_contractor1_label_hrs";
		this->listing_contractor1_label_hrs->Size = System::Drawing::Size(109, 20);
		this->listing_contractor1_label_hrs->TabIndex = 5;
		this->listing_contractor1_label_hrs->Text = L"всего часов:";
		// 
		// listing_contractor1_author
		// 
		this->listing_contractor1_author->AutoSize = true;
		this->listing_contractor1_author->Location = System::Drawing::Point(35, 40);
		this->listing_contractor1_author->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor1_author->Name = L"listing_contractor1_author";
		this->listing_contractor1_author->Size = System::Drawing::Size(149, 20);
		this->listing_contractor1_author->TabIndex = 2;
		this->listing_contractor1_author->Text = L"имя_подрядчика";
		// 
		// listing_contractor1_label_per_hr
		// 
		this->listing_contractor1_label_per_hr->AutoSize = true;
		this->listing_contractor1_label_per_hr->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->listing_contractor1_label_per_hr->Location = System::Drawing::Point(5, 63);
		this->listing_contractor1_label_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor1_label_per_hr->Name = L"listing_contractor1_label_per_hr";
		this->listing_contractor1_label_per_hr->Size = System::Drawing::Size(80, 20);
		this->listing_contractor1_label_per_hr->TabIndex = 3;
		this->listing_contractor1_label_per_hr->Text = L"за час, ₽:";
		// 
		// listing_contractor1_per_hr
		// 
		this->listing_contractor1_per_hr->AutoSize = true;
		this->listing_contractor1_per_hr->Location = System::Drawing::Point(89, 64);
		this->listing_contractor1_per_hr->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor1_per_hr->Name = L"listing_contractor1_per_hr";
		this->listing_contractor1_per_hr->Size = System::Drawing::Size(117, 20);
		this->listing_contractor1_per_hr->TabIndex = 4;
		this->listing_contractor1_per_hr->Text = L"плата_за_час";
		// 
		// listing_contractor1_name
		// 
		this->listing_contractor1_name->AutoSize = true;
		this->listing_contractor1_name->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->listing_contractor1_name->Location = System::Drawing::Point(4, 11);
		this->listing_contractor1_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->listing_contractor1_name->Name = L"listing_contractor1_name";
		this->listing_contractor1_name->Size = System::Drawing::Size(186, 24);
		this->listing_contractor1_name->TabIndex = 0;
		this->listing_contractor1_name->Text = L"название_подряда";
		// 
		// label_feed
		// 
		this->label_feed->AutoSize = true;
		this->label_feed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
			static_cast<System::Int32>(static_cast<System::Byte>(232)));
		this->label_feed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_feed->Location = System::Drawing::Point(7, 7);
		this->label_feed->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
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
		this->bg_feed->Margin = System::Windows::Forms::Padding(4);
		this->bg_feed->Name = L"bg_feed";
		this->bg_feed->Size = System::Drawing::Size(560, 169);
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
		this->menu_search->Location = System::Drawing::Point(10, 11);
		this->menu_search->Margin = System::Windows::Forms::Padding(4);
		this->menu_search->Name = L"menu_search";
		this->menu_search->Size = System::Drawing::Size(560, 502);
		this->menu_search->TabIndex = 7;
		// 
		// button_filter
		// 
		this->button_filter->BackColor = System::Drawing::SystemColors::ControlLight;
		this->button_filter->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_filter.BackgroundImage")));
		this->button_filter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->button_filter->Enabled = false;
		this->button_filter->Location = System::Drawing::Point(38, 168);
		this->button_filter->Margin = System::Windows::Forms::Padding(4);
		this->button_filter->Name = L"button_filter";
		this->button_filter->Size = System::Drawing::Size(35, 37);
		this->button_filter->TabIndex = 6;
		this->button_filter->UseVisualStyleBackColor = false;
		// 
		// label_in_future_updates
		// 
		this->label_in_future_updates->AutoSize = true;
		this->label_in_future_updates->Font = (gcnew System::Drawing::Font(L"Roboto", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_in_future_updates->Location = System::Drawing::Point(75, 248);
		this->label_in_future_updates->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_in_future_updates->Name = L"label_in_future_updates";
		this->label_in_future_updates->Size = System::Drawing::Size(411, 20);
		this->label_in_future_updates->TabIndex = 4;
		this->label_in_future_updates->Text = L"...в будущих обновлениях. Спасибо, что вы с нами!\r\n";
		// 
		// label_search_will_be
		// 
		this->label_search_will_be->AutoSize = true;
		this->label_search_will_be->Font = (gcnew System::Drawing::Font(L"Roboto", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_search_will_be->Location = System::Drawing::Point(213, 216);
		this->label_search_will_be->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_search_will_be->Name = L"label_search_will_be";
		this->label_search_will_be->Size = System::Drawing::Size(149, 24);
		this->label_search_will_be->TabIndex = 3;
		this->label_search_will_be->Text = L"Поиску - быть!";
		// 
		// button_search
		// 
		this->button_search->BackColor = System::Drawing::SystemColors::ControlLight;
		this->button_search->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_search.BackgroundImage")));
		this->button_search->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->button_search->Enabled = false;
		this->button_search->Location = System::Drawing::Point(4, 168);
		this->button_search->Margin = System::Windows::Forms::Padding(4);
		this->button_search->Name = L"button_search";
		this->button_search->Size = System::Drawing::Size(35, 37);
		this->button_search->TabIndex = 2;
		this->button_search->UseVisualStyleBackColor = false;
		// 
		// input_search
		// 
		this->input_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->input_search->Location = System::Drawing::Point(79, 173);
		this->input_search->Margin = System::Windows::Forms::Padding(4);
		this->input_search->Name = L"input_search";
		this->input_search->Size = System::Drawing::Size(472, 30);
		this->input_search->TabIndex = 1;
		// 
		// label_search
		// 
		this->label_search->AutoSize = true;
		this->label_search->Font = (gcnew System::Drawing::Font(L"Roboto", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label_search->Location = System::Drawing::Point(7, 7);
		this->label_search->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label_search->Name = L"label_search";
		this->label_search->Size = System::Drawing::Size(202, 28);
		this->label_search->TabIndex = 0;
		this->label_search->Text = L"Поиск и фильтры";
		// 
		// bg_search
		// 
		this->bg_search->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bg_search.BackgroundImage")));
		this->bg_search->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		this->bg_search->Location = System::Drawing::Point(0, -7);
		this->bg_search->Margin = System::Windows::Forms::Padding(4);
		this->bg_search->Name = L"bg_search";
		this->bg_search->Size = System::Drawing::Size(560, 169);
		this->bg_search->TabIndex = 5;
		this->bg_search->TabStop = false;
		// 
		// Main_Menu
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::Control;
		this->ClientSize = System::Drawing::Size(684, 517);
		this->Controls->Add(this->sidebar);
		this->Controls->Add(this->menu_feed);
		this->Controls->Add(this->menu_account);
		this->Controls->Add(this->menu_search);
		this->DoubleBuffered = true;
		this->Font = (gcnew System::Drawing::Font(L"Roboto", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->Margin = System::Windows::Forms::Padding(4);
		this->MaximumSize = System::Drawing::Size(702, 564);
		this->MinimumSize = System::Drawing::Size(702, 564);
		this->Name = L"Main_Menu";
		this->Text = L"Agora";
		this->sidebar->ResumeLayout(false);
		this->menu_account->ResumeLayout(false);
		this->menu_account->PerformLayout();
		this->group_active_contracts->ResumeLayout(false);
		this->active_listing_2->ResumeLayout(false);
		this->active_listing_2->PerformLayout();
		this->active_listing_1->ResumeLayout(false);
		this->active_listing_1->PerformLayout();
		this->group_account_data->ResumeLayout(false);
		this->group_account_data->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_my_account))->EndInit();
		this->menu_feed->ResumeLayout(false);
		this->menu_feed->PerformLayout();
		this->group_customers->ResumeLayout(false);
		this->listing_customer2_ui->ResumeLayout(false);
		this->listing_customer2_ui->PerformLayout();
		this->listing_customer1_ui->ResumeLayout(false);
		this->listing_customer1_ui->PerformLayout();
		this->group_contractors->ResumeLayout(false);
		this->listing_contractor2_ui->ResumeLayout(false);
		this->listing_contractor2_ui->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listing_contractor2_picker_hrs))->EndInit();
		this->listing_contractor1_ui->ResumeLayout(false);
		this->listing_contractor1_ui->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->listing_contractor1_picker_hrs))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_feed))->EndInit();
		this->menu_search->ResumeLayout(false);
		this->menu_search->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bg_search))->EndInit();
		this->ResumeLayout(false);

	}

	#pragma endregion

private:

	#pragma region ======= Feed =======

	void sidebar_pick_feed(System::Object^ sender, System::EventArgs^ e)
	{
		this->Text = "Agora: Лента";
		menu_feed->BringToFront();
	}


	void accept_listing(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ source = safe_cast<Button^>(sender);
		Listing_Interface^ respectable_listing_ui;
		User* to_set_user_as;
		if (contractor1_ui->has(source))
		{
			respectable_listing_ui = contractor1_ui;
			to_set_user_as = contractor1_ui->listing->customer;
			/// We could give it an 80% chance for a spice.
			show_info(L"Подрядчик согласился!");
		}

		else if (contractor2_ui->has(source))
		{
			respectable_listing_ui = contractor2_ui;
			to_set_user_as = contractor2_ui->listing->customer;
			show_info(L"Подрядчик согласился!");
		}

		else if (customer1_ui->has(source))
		{
			respectable_listing_ui = customer1_ui;
			to_set_user_as = customer1_ui->listing->contractor;
			show_info(L"Заказчик согласился!");
		}

		else if (customer2_ui->has(source))
		{
			respectable_listing_ui = customer2_ui;
			to_set_user_as = customer2_ui->listing->contractor;
			show_info(L"Заказчик согласился!");
		}

		else return;

		to_set_user_as = user;
		accepted_listings.push_back(*respectable_listing_ui->listing);
		respectable_listing_ui->ui_group->Enabled = false;

		save(user, USER_SAVEFILE_NAME, accepted_listings);
		fill_active_listings_menu();
	}


	void feed_contracts_length_adjusted(System::Object^ sender, System::EventArgs^ e)
	{
		NumericUpDown^ source = safe_cast<NumericUpDown^>(sender);
		Listing_Interface^ respectable_listing_ui;
		
		if (contractor1_ui->has(source))
			respectable_listing_ui = contractor1_ui;
		else if (contractor2_ui->has(source))
			respectable_listing_ui = contractor2_ui;
		else return;

		respectable_listing_ui->calculate_and_display_total(Convert::ToUInt32(source->Value));
	}


	void fill_feed_menu()
	{
		listing_contractor1 = get_random_listing(CONTRACTOR_LISTING);
		contractor1_ui->set_listing(&listing_contractor1, CONTRACTOR_LISTING);

		listing_contractor2 = get_random_listing(CONTRACTOR_LISTING);
		contractor2_ui->set_listing(&listing_contractor2, CONTRACTOR_LISTING);

		listing_customer1 = get_random_listing(CUSTOMER_LISTING);
		customer1_ui->set_listing(&listing_customer1, CUSTOMER_LISTING);

		listing_customer2 = get_random_listing(CUSTOMER_LISTING);
		customer2_ui->set_listing(&listing_customer2, CUSTOMER_LISTING);
	}


	void update_feed(System::Object^ _sender, System::EventArgs^ e)
	{
		/// Think I'm a genius. This function is used both for start and end of the 'update'. Elegant!
		button_feed_update->Enabled = ! button_feed_update->Enabled;
		group_contractors->Enabled  = ! group_contractors->Enabled;
		group_customers->Enabled	= ! group_customers->Enabled;
		update_timer->Enabled		= ! update_timer->Enabled;

		/// countdown finished
		if (! update_timer->Enabled)
			fill_feed_menu();
	}

	#pragma endregion


	#pragma region ======= Account =======

	void sidebar_pick_account(System::Object^ sender, System::EventArgs^ e)
	{
		this->Text = "Agora: Мой аккаунт";
		menu_account->BringToFront();

		Point label_pos(11, 113);
		label_no_active_contracts->Location = label_pos;
		if (! accepted_listings.empty())
		{
			label_no_active_contracts->Visible = false;
		}
		else
		{
			label_no_active_contracts->Visible = true;
			active_listing_1->Visible = false;
			active_listing_2->Visible = false;
		}

		fill_active_listings_menu();
	}


	void edit_account_data(System::Object^ sender, System::EventArgs^ e)
	{
		Registration^ registration = gcnew Registration(user);
		registration->ShowDialog();
		user = load(USER_SAVEFILE_NAME);
		if (user == nullptr)
		{
			show_error(L"Ошибка при чтении данных.");
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


	void fill_active_listings_menu()
	{
		if (accepted_listings.size() < 1)
			return;
		active_listing_1->Visible = true;
		active_listing_1->Enabled = true;
		active_listing_1_name->Text = to_dotnet_string(accepted_listings[0].name);
		if (accepted_listings[0].contractor == user)
			active_listing_1_from->Text = to_dotnet_string(accepted_listings[0].customer->name->get_short());
		else
			active_listing_1_from->Text = to_dotnet_string(accepted_listings[0].contractor->name->get_short());
		active_listing_1_hourly->Text = Convert::ToString(accepted_listings[0].per_hr);
		active_listing_1_hrs->Text	= Convert::ToString(accepted_listings[0].hrs);
		active_listing_1_total->Text  = L"Итого, ₽: " + Convert::ToString(accepted_listings[0].payment_total());

		if (accepted_listings.size() < 2)
			return;
		active_listing_2->Visible = true;
		active_listing_2->Enabled = true;
		active_listing_2_name->Text = to_dotnet_string(accepted_listings[1].name);
		if (accepted_listings[1].contractor == user)
			active_listing_2_from->Text = to_dotnet_string(accepted_listings[1].customer->name->get_short());
		else
			active_listing_2_from->Text = to_dotnet_string(accepted_listings[1].contractor->name->get_short());
		active_listing_2_hourly->Text = Convert::ToString(accepted_listings[1].per_hr);
		active_listing_2_hrs->Text	= Convert::ToString(accepted_listings[1].hrs);
		active_listing_2_total->Text  = L"Итого, ₽: " + Convert::ToString(accepted_listings[1].payment_total());
	}


	void finish_active_listing(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ source = safe_cast<Button^>(sender);
		
		if (source == active_listing_1_finish)
		{
			active_listing_1->Enabled = false;
			accepted_listings.erase(accepted_listings.begin());
		}
		if (source == active_listing_2_finish)
		{
			active_listing_2->Enabled = false;
			/// Avoiding fallthrough coming from deleting listing 1, then 2
			if (active_listing_1->Enabled)
				accepted_listings.erase(accepted_listings.begin() + 1);
			else
				accepted_listings.erase(accepted_listings.begin());
		}

		save(user, USER_SAVEFILE_NAME, accepted_listings);
	}

	#pragma endregion


	#pragma region ======= Misc. menus =======

	void sidebar_pick_info(System::Object^ sender, System::EventArgs^ e)
	{
		show_info(PROGRAM_INFO, L"О программе");
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