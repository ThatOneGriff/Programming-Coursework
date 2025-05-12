**1.** Создание "Пустого проекта CLR".

**2.** Добавление WinForms в проект:
	 Проводник VS -> ПКМ на *название решения* -> Add -> New Item -> UI -> Windows Form

**3.** Добавление в исходник `{ProjectName}.cpp`:
	```using namespace System;
	using namespace System::Windows::Forms;
	[STAThread]
	void main(array<String^>^ arg) {
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		ProjectName::MyForm form;
		Application::Run(%form);
	}```

**4.** Настройка:
	*Название решения* -> ПКМ -> Properties -> Linker
		-> System -> Subsystem -> **= выбрать "Windows" =**
		-> Advanced -> Entry point -> **= прописать "main" =**

**5.** Нажать "Принять".