#pragma once
#include "crudPacientesInterface.h"
#include <string>
#include <msclr/marshal_cppstd.h>

namespace ClinicaCitas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AgregarPaciente
	/// </summary>
	public ref class AgregarPaciente : public System::Windows::Forms::Form
	{
	public:
		AgregarPaciente(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AgregarPaciente()
		{
			if (components)
			{
				delete components;
			}
		}
	public: bool estaAgregando = true;
	private: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::TextBox^ Ape;
	protected:

	public: System::Windows::Forms::TextBox^ Nom;

	public: System::Windows::Forms::TextBox^ Cod;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ Tel;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Ape = (gcnew System::Windows::Forms::TextBox());
			this->Nom = (gcnew System::Windows::Forms::TextBox());
			this->Cod = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Tel = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(130, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 25);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Paciente";
			// 
			// Ape
			// 
			this->Ape->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ape->Location = System::Drawing::Point(131, 134);
			this->Ape->Name = L"Ape";
			this->Ape->Size = System::Drawing::Size(162, 27);
			this->Ape->TabIndex = 19;
			// 
			// Nom
			// 
			this->Nom->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom->Location = System::Drawing::Point(131, 103);
			this->Nom->Name = L"Nom";
			this->Nom->Size = System::Drawing::Size(162, 27);
			this->Nom->TabIndex = 18;
			// 
			// Cod
			// 
			this->Cod->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cod->Location = System::Drawing::Point(131, 73);
			this->Cod->Name = L"Cod";
			this->Cod->Size = System::Drawing::Size(162, 27);
			this->Cod->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(44, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 18);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Apellido:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(47, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 18);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Nombre:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(54, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 18);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Código:";
			// 
			// Tel
			// 
			this->Tel->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Tel->Location = System::Drawing::Point(131, 167);
			this->Tel->Name = L"Tel";
			this->Tel->Size = System::Drawing::Size(162, 27);
			this->Tel->TabIndex = 22;
			this->Tel->TextChanged += gcnew System::EventHandler(this, &AgregarPaciente::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(41, 170);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 18);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Telefono:";
			this->label5->Click += gcnew System::EventHandler(this, &AgregarPaciente::label5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(218, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 23;
			this->button1->Text = L"Actualizar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AgregarPaciente::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 235);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 24;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AgregarPaciente::button2_Click);
			// 
			// AgregarPaciente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(363, 280);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Tel);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Ape);
			this->Controls->Add(this->Nom);
			this->Controls->Add(this->Cod);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AgregarPaciente";
			this->Text = L"AgregarPaciente";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string codigo = msclr::interop::marshal_as<std::string>(this->Cod->Text);
		std::string nombre = msclr::interop::marshal_as<std::string>(this->Nom->Text);
		std::string apellido = msclr::interop::marshal_as<std::string>(this->Ape->Text);
		std::string telefono = msclr::interop::marshal_as<std::string>(this->Tel->Text);
		if (estaAgregando) {
			Crear(stoi(codigo), nombre.c_str(), apellido.c_str(), stoi(telefono));
		}
		else {
			Actualizar(stoi(codigo), nombre.c_str(), apellido.c_str(), stoi(telefono));
		}
		this->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
