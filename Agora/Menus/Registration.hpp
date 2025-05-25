#pragma once

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
		Registration(void)
		{
			InitializeComponent();
		}

	protected:
		~Registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Hello_World;
	protected:

	private:
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->Hello_World = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Hello_World
			// 
			this->Hello_World->AutoSize = true;
			this->Hello_World->Location = System::Drawing::Point(198, 133);
			this->Hello_World->Name = L"Hello_World";
			this->Hello_World->Size = System::Drawing::Size(84, 16);
			this->Hello_World->TabIndex = 0;
			this->Hello_World->Text = L"Hello, World!";
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(507, 351);
			this->Controls->Add(this->Hello_World);
			this->Name = L"Registration";
			this->Text = L"Регистрация";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion
	};
}
