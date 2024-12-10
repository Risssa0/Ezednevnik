#pragma once
#include <fstream>
#include <msclr/marshal_cppstd.h>

namespace Ezednevnik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &MyForm::Form1_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
		}

	private:
		// Метод для сохранения элементов из первого списка в файл
		void SaveListBoxItems() {
			// Создаем новый StreamWriter для записи в файл "listbox_items.txt"
			System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("listbox_items.txt");

			// Проходим по каждому элементу в listBox1
			for each (System::String ^ item in listBox1->Items) {
				// Записываем элемент в файл с новой строки
				writer->WriteLine(item);
			}

			// Закрываем StreamWriter, чтобы освободить ресурсы
			writer->Close();
		}

		// Метод для загрузки элементов из файла в первый список
		void LoadListBoxItems() {
			// Очищаем элементы в listBox1 перед загрузкой новых данных
			listBox1->Items->Clear();

			// Проверяем, существует ли файл "listbox_items.txt"
			if (System::IO::File::Exists("listbox_items.txt")) {
				// Создаем новый StreamReader для чтения из файла
				System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("listbox_items.txt");

				// Читаем файл до конца
				while (!reader->EndOfStream) {
					// Читаем строку из файла
					System::String^ line = reader->ReadLine();

					// Добавляем прочитанную строку в listBox1
					listBox1->Items->Add(line);
				}

				// Закрываем StreamReader, чтобы освободить ресурсы
				reader->Close();
			}
		}

		// Метод для сохранения элементов из второго списка в файл
		void SaveListBoxItems2() {
			// Создаем новый StreamWriter для записи в файл "listbox2_items.txt"
			System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("listbox2_items.txt");

			// Проходим по каждому элементу в listBox2
			for each (System::String ^ item in listBox2->Items) {
				// Записываем элемент в файл с новой строки
				writer->WriteLine(item);
			}

			// Закрываем StreamWriter, чтобы освободить ресурсы
			writer->Close();
		}

		// Метод для загрузки элементов из файла во второй список
		void LoadListBoxItems2() {
			// Очищаем элементы в listBox2 перед загрузкой новых данных
			listBox2->Items->Clear();

			// Проверяем, существует ли файл "listbox2_items.txt"
			if (System::IO::File::Exists("listbox2_items.txt")) {
				// Создаем новый StreamReader для чтения из файла
				System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("listbox2_items.txt");

				// Читаем файл до конца
				while (!reader->EndOfStream) {
					// Читаем строку из файла
					System::String^ line = reader->ReadLine();

					// Добавляем прочитанную строку в listBox2
					listBox2->Items->Add(line);
				}

				// Закрываем StreamReader, чтобы освободить ресурсы
				reader->Close();
			}
		}


		void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
			LoadListBoxItems();  // Загружаем элементы первого ListBox
			LoadListBoxItems2(); // Загружаем элементы второго ListBox
		}

		void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			SaveListBoxItems();  // Сохраняем элементы первого ListBox
			SaveListBoxItems2(); // Сохраняем элементы второго ListBox
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: bool isDragging = false;
	private: System::Drawing::Point dragCursorPoint;
	private: System::Drawing::Point dragFormPoint;




	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button5;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(609, 96);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// button5
			// 
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button5->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			this->button5->Location = System::Drawing::Point(554, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(54, 49);
			this->button5->TabIndex = 20;
			this->button5->Text = L"X";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(109, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(413, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ежедневник";
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::Color::Fuchsia;
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->ForeColor = System::Drawing::Color::White;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Location = System::Drawing::Point(16, 191);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(260, 378);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->BackColor = System::Drawing::Color::Fuchsia;
			this->listBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox2->ForeColor = System::Drawing::Color::White;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 18;
			this->listBox2->Location = System::Drawing::Point(333, 191);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(264, 378);
			this->listBox2->TabIndex = 2;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox2_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(87, 101);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(455, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Fuchsia;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(63, 138);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 34);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Друзья";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Fuchsia;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(382, 138);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 34);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Враги";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Fuchsia;
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(282, 294);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(45, 42);
			this->button3->TabIndex = 6;
			this->button3->Text = L"<->";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(12, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 24);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Ф.И.О";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Fuchsia;
			this->ClientSize = System::Drawing::Size(609, 698);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrWhiteSpace(textBox1->Text)) {
			listBox1->Items->Add(textBox1->Text);
			textBox1->Clear();
		}
		else {
			MessageBox::Show("Введите текст перед добавлением!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!String::IsNullOrWhiteSpace(textBox1->Text)) {
		listBox2->Items->Add(textBox1->Text);
		textBox1->Clear();
	}
	else {
		MessageBox::Show("Введите текст перед добавлением!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //test
	if (listBox1->SelectedItem != nullptr) {
		// Получаем выбранный элемент
		auto selectedItem = listBox1->SelectedItem;

		// Удаляем его из ListBox1
		listBox1->Items->Remove(selectedItem);

		// Добавляем его в ListBox2
		listBox2->Items->Add(selectedItem);
	}
	// Проверяем, выбран ли элемент во втором ListBox
	else if (listBox2->SelectedItem != nullptr) {
		// Получаем выбранный элемент
		auto selectedItem = listBox2->SelectedItem; // save

		// Удаляем его из ListBox2
		listBox2->Items->Remove(selectedItem);

		// Добавляем его в ListBox1
		listBox1->Items->Add(selectedItem);
	}
	else {
		MessageBox::Show("Пожалуйста, выберите элемент для перемещения!", 
			"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning); 
		// выдает ошибку, если пользователь не выбрал ФИО
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listBox2->SelectedItem != nullptr) {
		// Получаем выбранный элемент
		auto selectedItem = listBox2->SelectedItem;

		// Удаляем его из ListBox2
		listBox2->Items->Remove(selectedItem);

		// Добавляем его в ListBox1
		listBox1->Items->Add(selectedItem);
	}
	else {
		MessageBox::Show("Пожалуйста, выберите элемент для перемещения!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}


   private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	   this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseDown);
	   this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseMove);
	   this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
	   this->label1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseDown);
	   this->label1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseMove);
	   this->label1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
   }

		  private: System::Void panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			  if (e->Button == System::Windows::Forms::MouseButtons::Left) {
				  isDragging = true;
				  dragCursorPoint = System::Drawing::Point(e->X, e->Y);
				  dragFormPoint = this->Location;
			  }
		  }

  private: System::Void panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	  if (isDragging) {
		  // Вычисляем новое положение формы
		  int deltaX = e->Location.X - dragCursorPoint.X;
		  int deltaY = e->Location.Y - dragCursorPoint.Y;
		  System::Drawing::Point newLocation = System::Drawing::Point(dragFormPoint.X + deltaX, dragFormPoint.Y + deltaY);
		  this->Location = newLocation;
	  }
  }


   private: System::Void panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	   if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		   isDragging = false;
	   }
   }

private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
