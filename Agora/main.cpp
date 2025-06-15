#include <Windows.h>

#include "Main_Menu.hpp"
#include "Menus/Registration/Registration.hpp"

#include "Utils.hpp"
using namespace Agora;
using namespace System::Windows::Forms;


[System::STAThread]
int WINAPI WinMain(const HINSTANCE, const HINSTANCE, const LPSTR, const int)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	User* user = nullptr;
	while(user == nullptr)
	{
		user = load(USER_SAVEFILE_NAME);
		if (user == nullptr)
			Application::Run(gcnew Registration);
	}

	/// = Known Errors =
	/// - window cycle
	/// - preemptive savefile check

	System::Windows::Forms::MessageBox::Show(to_dotnet_string(user->serialize()));
    Application::Run(gcnew Main_Menu);

    return 0;
}