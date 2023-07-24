#pragma once
#include <Windows.h>
#include "crudPacientesInterface.h"
#include <vector>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <string>
#include "AgregarPaciente.h"

namespace ClinicaCitas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Paciente
	/// </summary>
	public ref class Paciente : public System::Windows::Forms::Form
	{
	public:
		Paciente(void)
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
		~Paciente()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridView^ dgvPacientes;





	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Codigo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Paciente::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dgvPacientes = (gcnew System::Windows::Forms::DataGridView());
			this->Codigo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPacientes))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(172, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Código:";
			this->label1->Click += gcnew System::EventHandler(this, &Paciente::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(168, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nombre:";
			this->label2->Click += gcnew System::EventHandler(this, &Paciente::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(162, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Apellido:";
			this->label3->Click += gcnew System::EventHandler(this, &Paciente::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(249, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(162, 27);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Paciente::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(249, 99);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(162, 27);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Paciente::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(249, 130);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(162, 27);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Paciente::textBox3_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(22, 21);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Paciente::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(110, 290);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 34);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Agregar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Paciente::button1_Click_1);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(249, 290);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 34);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Modificar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Paciente::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(234, 330);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(139, 34);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Actualizar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Paciente::button4_Click);
			// 
			// dgvPacientes
			// 
			this->dgvPacientes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvPacientes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Codigo,
					this->Column2, this->Column3, this->Column4
			});
			this->dgvPacientes->Location = System::Drawing::Point(52, 170);
			this->dgvPacientes->MultiSelect = false;
			this->dgvPacientes->Name = L"dgvPacientes";
			this->dgvPacientes->Size = System::Drawing::Size(453, 109);
			this->dgvPacientes->TabIndex = 12;
			this->dgvPacientes->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Paciente::dgvPacientes_CellClick);
			this->dgvPacientes->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Paciente::dataGridView1_CellContentClick);
			// 
			// Codigo
			// 
			this->Codigo->HeaderText = L"Código";
			this->Codigo->Name = L"Codigo";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Apellidos";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Nombres";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Teléfono";
			this->Column4->Name = L"Column4";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(402, 290);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(73, 34);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Borrar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Paciente::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(248, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(125, 25);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Pacientes";
			// 
			// Paciente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(587, 384);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dgvPacientes);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Paciente";
			this->Text = L"Paciente";
			this->Load += gcnew System::EventHandler(this, &Paciente::Paciente_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvPacientes))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = dgvPacientes->CurrentCell->RowIndex;
		//String^ v = dgvPacientes->Rows[i]->Cells[0]->Value->ToString();
		//int cod = stoi(msclr::interop::marshal_as<std::string>(v));
		//bool rpta = (bool) MessageBox::Show("Are you sure to delete this item ??", "Confirm Delete!!", MessageBoxButtons::YesNo);
		if(MessageBox::Show("¿Estas seguro de eliminar?", "Confirm Delete!!", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			Borrar(i+1);
			dgvPacientes->Rows->Clear();
			ReLoad();
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Paciente_Load(System::Object^ sender, System::EventArgs^ e) {
		ReLoad();
	}

	private: System::Void ReLoad() {
		//std::vector<Paciente> v= Leer();
		//std::cout <<  "--->" << Leer()[0].nombres << std::endl;
		std::vector<Estructura::Paciente> pacientes = Leer();
		//String^ net = msclr::interop::marshal_as<String^>(Leer()[0].nombres
		for (int i = 0; i < pacientes.size(); i++) {
			Estructura::Paciente p = pacientes[i];
			llenarData(p.PacCod, p.nombres, p.apellidos, p.telefono, i);
		}
	}
		   private: System::Void llenarData(int p1, const char* p2, const char* p3, int p4, int i) {
			   dgvPacientes->Rows->Add();
			   dgvPacientes->Rows[i]->Cells[0]->Value = msclr::interop::marshal_as<String^>(std::to_string(p1));
			   dgvPacientes->Rows[i]->Cells[1]->Value = msclr::interop::marshal_as<String^>(p2);
			   dgvPacientes->Rows[i]->Cells[2]->Value = msclr::interop::marshal_as<String^>(p3);
			   dgvPacientes->Rows[i]->Cells[3]->Value = msclr::interop::marshal_as<String^>(std::to_string(p4));
		   }
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = dgvPacientes->CurrentCell->RowIndex;
		AgregarPaciente obj;
		//String^ net = msclr::interop::marshal_as<String^>(dgvPacientes->Rows[i]->Cells[0]->Value);
		obj.estaAgregando = false;
		obj.Cod->Text = dgvPacientes->Rows[i]->Cells[0]->Value->ToString();
		obj.Nom->Text = dgvPacientes->Rows[i]->Cells[1]->Value->ToString();
		obj.Ape->Text = dgvPacientes->Rows[i]->Cells[2]->Value->ToString();
		obj.Tel->Text = dgvPacientes->Rows[i]->Cells[3]->Value->ToString();
		obj.ShowDialog();
		dgvPacientes->Rows->Clear();
		ReLoad();
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		AgregarPaciente obj;
		obj.estaAgregando = true;
		obj.ShowDialog();
		dgvPacientes->Rows->Clear();
		ReLoad();
	}
private: System::Void dgvPacientes_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	
	
}
};
}
