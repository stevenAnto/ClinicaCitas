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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvDoctor = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDoctor))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(210, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(275, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"DOCTORES REGISTRADOS";
			// 
			// dgvDoctor
			// 
			this->dgvDoctor->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDoctor->Location = System::Drawing::Point(12, 67);
			this->dgvDoctor->Name = L"dgvDoctor";
			this->dgvDoctor->Size = System::Drawing::Size(737, 271);
			this->dgvDoctor->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 360);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Registrar Doctor";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(616, 360);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Ver Doctor";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// Doctor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(761, 399);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dgvDoctor);
			this->Controls->Add(this->label1);
			this->Name = L"Doctor";
			this->Text = L"Doctor";
			this->Load += gcnew System::EventHandler(this, &Doctor::Doctor_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDoctor))->EndInit();
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
	};
}
