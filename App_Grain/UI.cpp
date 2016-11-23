#include "UI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	App_Grain::UI frm;        //NameOfProject::NameOfForm instanceOfForm;
	Application::Run(%frm);
}
