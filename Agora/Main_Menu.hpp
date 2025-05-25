#pragma once
#include "User/Contacts.hpp" //TEST
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
	#pragma region = Winforms Code =

	public:
		Main_Menu(void)
		{
			InitializeComponent();
			Phone_Number num;
			output_test->Text = to_dotnet_string(num.as_text());
		}

	protected:
		~Main_Menu()
		{
			if (components)
				delete components;
		}

	protected:

    protected:
    private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ output_test;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:



		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->output_test = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// output_test
			// 
			this->output_test->Location = System::Drawing::Point(255, 174);
			this->output_test->Name = L"output_test";
			this->output_test->Size = System::Drawing::Size(100, 22);
			this->output_test->TabIndex = 2;
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 455);
			this->Controls->Add(this->output_test);
			this->Name = L"Main_Menu";
			this->Text = L"Main_Menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion

	private:
	};
}
