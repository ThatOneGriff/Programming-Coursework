#pragma once
#include "User/Contacts.hpp" //TEST
#include "User/Random_User_Generator.hpp" //TEST
#include "Menus/Registration.hpp"
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
			
			for (int i = 0; i < 15; i++)
			{
				Phone_Number num = _get_random_phone_number();
				test_box->Items->Add(to_dotnet_string(num.as_text()));
			}
		}

	protected:
		~Main_Menu()
		{
			if (components)
				delete components;
		}
	private: System::Windows::Forms::ListBox^ test_box;
	protected:

	#pragma region = Winforms Code =


	private: System::ComponentModel::IContainer^ components;
		void InitializeComponent(void)
		{
			this->test_box = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// test_box
			// 
			this->test_box->FormattingEnabled = true;
			this->test_box->ItemHeight = 16;
			this->test_box->Location = System::Drawing::Point(392, 19);
			this->test_box->Name = L"test_box";
			this->test_box->Size = System::Drawing::Size(197, 420);
			this->test_box->TabIndex = 0;
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 455);
			this->Controls->Add(this->test_box);
			this->Name = L"Main_Menu";
			this->Text = L"Main_Menu";
			this->ResumeLayout(false);

		}

		#pragma endregion

	private:
	};
}
