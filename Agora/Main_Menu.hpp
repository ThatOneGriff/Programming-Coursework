#pragma once
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Menus/Registration/Registration.hpp"
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
		Main_Menu()
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
	protected:

	protected:

	private: System::Windows::Forms::Button^ menu_button_info;

	private: System::Windows::Forms::Button^ menu_button_settings;



	private: System::Windows::Forms::Button^ menu_button_account;

	private: System::Windows::Forms::Button^ menu_button_feed;
	private: System::Windows::Forms::Panel^ menu_account;




	protected:

	protected:

	protected:

	protected:

	protected:


	private: System::ComponentModel::IContainer^ components;
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_Menu::typeid));
			this->menu_button_search = (gcnew System::Windows::Forms::Button());
			this->sidebar = (gcnew System::Windows::Forms::Panel());
			this->menu_button_feed = (gcnew System::Windows::Forms::Button());
			this->menu_button_account = (gcnew System::Windows::Forms::Button());
			this->menu_button_settings = (gcnew System::Windows::Forms::Button());
			this->menu_button_info = (gcnew System::Windows::Forms::Button());
			this->menu_account = (gcnew System::Windows::Forms::Panel());
			this->sidebar->SuspendLayout();
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
			this->menu_button_search->TabIndex = 0;
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
			// menu_button_feed
			// 
			this->menu_button_feed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)),
				static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(202)));
			this->menu_button_feed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->menu_button_feed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_button_feed.Image")));
			this->menu_button_feed->Location = System::Drawing::Point(5, 93);
			this->menu_button_feed->Name = L"menu_button_feed";
			this->menu_button_feed->Size = System::Drawing::Size(75, 75);
			this->menu_button_feed->TabIndex = 1;
			this->menu_button_feed->UseVisualStyleBackColor = false;
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
			// menu_account
			// 
			this->menu_account->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->menu_account->Location = System::Drawing::Point(12, 12);
			this->menu_account->Name = L"menu_account";
			this->menu_account->Size = System::Drawing::Size(534, 415);
			this->menu_account->TabIndex = 2;
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(639, 437);
			this->Controls->Add(this->menu_account);
			this->Controls->Add(this->sidebar);
			this->DoubleBuffered = true;
			this->Name = L"Main_Menu";
			this->Text = L"Agora";
			this->sidebar->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		#pragma endregion

	private:
	};
}

#endif