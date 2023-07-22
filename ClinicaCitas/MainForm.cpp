#include "MainForm.h"

using namespace ClinicaCitas;

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
}