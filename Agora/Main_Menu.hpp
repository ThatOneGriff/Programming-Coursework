#pragma once
#include "Menus/Registration.hpp"

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
		}

	protected:
		~Main_Menu()
		{
			if (components)
				delete components;
		}

	protected:

	private:
		System::ComponentModel::Container ^components;


		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 455);
			this->Name = L"Main_Menu";
			this->Text = L"Main_Menu";
			this->ResumeLayout(false);

		}

		#pragma endregion

	private:
	};
}
