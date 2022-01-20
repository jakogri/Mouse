#include <iostream>
#include <Windows.h>
#include <winuser.h>
#include <sstream>
#include <string>
#include <fstream>
#pragma once


namespace Mouse {

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
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(30, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(281, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Записать координаты мыши в файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(30, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(281, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Чтение данных из файла";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(394, 385);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		   
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		POINT p;
		std::ofstream out;
		std::stringstream os_x;
		std::stringstream os_y;
		GetCursorPos(&p);
        #pragma comment(lib, "user32.lib")
		os_x << (int)p.x;
		os_y << (int)p.y;
		std::string intString = "Координаты мыши: x - " + os_x.str() + "; y - " + os_y.str();
		//MessageBoxA(NULL, (LPCSTR)intString.c_str(), "Координаты мыши", MB_OK);
		out.open("mouse.txt");
		if (out.is_open())
		{
			out << intString << std::endl;
		}
		out.close();
	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		std::string line;
		std::ifstream in("mouse.txt");
		if (in.is_open())
		{
			while (getline(in, line))
			{
				in >> line;
			}
			
		}
		in.close();
		MessageBoxA(NULL, (LPCSTR)line.c_str(), "Координаты мыши", MB_OK);
	}
};
}
