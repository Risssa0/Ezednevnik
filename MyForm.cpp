#include "MyForm.h" // Include the header file of your WinForms form
#include <stdio.h>
#include <clocale>

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ arg) {
    setlocale(LC_ALL, "Rus");
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Ezednevnik::MyForm form; //WinFormsTest - ��� ������ ������� 
    Application::Run(% form);
}
