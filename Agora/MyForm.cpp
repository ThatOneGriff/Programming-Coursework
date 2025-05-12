#include "MyForm.hpp"
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Agora::MyForm form;
	Application::Run(% form);

	return 0;
}