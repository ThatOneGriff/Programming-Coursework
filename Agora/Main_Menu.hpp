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
			
			for (int i = 0; i < 5; i++)
			{
				Individual individual = get_random_individual();
				std::wstring info = individual.name.get_short() + L'\n'
								  + individual.phone_number.as_text() + L'\n'
								  + individual.email.get() + L"\n\n";
				test_box->Text += to_dotnet_string(info);
			}
		}

	protected:
		~Main_Menu()
		{
			if (components)
				delete components;
		}
	private: System::Windows::Forms::RichTextBox^ test_box;
	protected:

	protected:

	#pragma region = Winforms Code =


	private: System::ComponentModel::IContainer^ components;
		void InitializeComponent(void)
		{
			this->test_box = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// test_box
			// 
			this->test_box->Location = System::Drawing::Point(327, 23);
			this->test_box->Name = L"test_box";
			this->test_box->Size = System::Drawing::Size(300, 420);
			this->test_box->TabIndex = 0;
			this->test_box->Text = L"";
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
