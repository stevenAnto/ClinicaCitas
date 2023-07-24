#pragma once

namespace ClinicaCitas {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Doctor
	/// </summary>
	public ref class Doctor : public System::Windows::Forms::Form
	{
	public:
		Doctor(void)
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
		~Doctor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dgvDoctor;


	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Doctor::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvDoctor = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDoctor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(330, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ROTACION";
			this->label1->Click += gcnew System::EventHandler(this, &Doctor::label1_Click);
			// 
			// dgvDoctor
			// 
			this->dgvDoctor->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDoctor->Location = System::Drawing::Point(22, 170);
			this->dgvDoctor->Name = L"dgvDoctor";
			this->dgvDoctor->Size = System::Drawing::Size(712, 276);
			this->dgvDoctor->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(22, 21);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(22, 21);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Doctor::pictureBox1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(103, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 18);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Nombre del Médico:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(149, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 18);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Especialidad:";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Oscar Ramirez", L"Edith Cano", L"Cesar Baluarte" });
			this->comboBox2->Location = System::Drawing::Point(292, 114);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(281, 26);
			this->comboBox2->TabIndex = 22;
			this->comboBox2->Text = L"Seleccione Médico";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Odontología", L"Pediatría", L"Medicina General",
					L"Neumología", L"Gastroenterología"
			});
			this->comboBox1->Location = System::Drawing::Point(292, 83);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(281, 26);
			this->comboBox1->TabIndex = 21;
			this->comboBox1->Text = L"Seleccione Especialidad";
			// 
			// Doctor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(761, 472);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dgvDoctor);
			this->Controls->Add(this->label1);
			this->Name = L"Doctor";
			this->Text = L"Rotacion";
			this->Load += gcnew System::EventHandler(this, &Doctor::Doctor_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDoctor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Doctor_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dgvDoctor->ColumnCount = 6;
		this->dgvDoctor->Columns[0]->Name= "ID";
		this->dgvDoctor->Columns[1]->Name = "Apellidos";
		this->dgvDoctor->Columns[2]->Name = "Nombres";
		this->dgvDoctor->Columns[3]->Name = "Especialidad";
		this->dgvDoctor->Columns[4]->Name = "Celular";
		this->dgvDoctor->Columns[5]->Name = "Est. Registro";
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
