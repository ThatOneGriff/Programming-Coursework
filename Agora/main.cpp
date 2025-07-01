#include <string>
#include <Windows.h>

#include "Menus/Main_Menu/main_menu.hpp"
#include "Menus/Registration/registration.hpp"

#include "utils.hpp"
using namespace Agora;
using namespace System::Windows::Forms;
	

/// = TODO =
/// - Check the inclusion of all headers
/// - Settings


[System::STAThread]
int WINAPI wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	User* user = load(USER_SAVEFILE_NAME);
	if (user == nullptr) /// Not registered.
	{
		Application::Run(gcnew Registration(user));
		user = load(USER_SAVEFILE_NAME); /// loading saved data
	}
	if (user == nullptr) /// Registration didn't work, or user closed the window.
		return 0;

    Application::Run(gcnew Main_Menu(user));
	

    return 0;
}