#pragma once
extern "C" {
#include "main.h"
}

#include <msclr/marshal_cppstd.h>

namespace App_Grain {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;


	/// <summary>
	/// Summary for UI
	/// </summary>
	public ref class UI : public System::Windows::Forms::Form
	{
		public:UI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			fileDialog->Filter = "BMP Files (*.bmp)|*.bmp";
			//txtPath->Text = "C:\\Users\\a0717016\\Desktop\\BMPS\\";
		}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~UI()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^  btnOpenFile;
		private: System::Windows::Forms::OpenFileDialog^  fileDialog;

		private: System::Windows::Forms::Button^  btnEncrypt;

		private: System::Windows::Forms::TextBox^  txtPath;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::TextBox^  txtIV;
		private: System::Windows::Forms::TextBox^  txtKey;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Button^  btnAutoKey;
		private: System::Windows::Forms::Button^  btnAutoIV;
		private: String^ _key;
		private: String^ _IV;
		private: String^ _alphabet = "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


		protected:

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UI::typeid));
				this->btnOpenFile = (gcnew System::Windows::Forms::Button());
				this->fileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->btnEncrypt = (gcnew System::Windows::Forms::Button());
				this->txtPath = (gcnew System::Windows::Forms::TextBox());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->txtIV = (gcnew System::Windows::Forms::TextBox());
				this->txtKey = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->btnAutoKey = (gcnew System::Windows::Forms::Button());
				this->btnAutoIV = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// btnOpenFile
				// 
				this->btnOpenFile->Location = System::Drawing::Point(420, 40);
				this->btnOpenFile->Name = L"btnOpenFile";
				this->btnOpenFile->Size = System::Drawing::Size(75, 23);
				this->btnOpenFile->TabIndex = 0;
				this->btnOpenFile->Text = L"Open File";
				this->btnOpenFile->UseVisualStyleBackColor = true;
				this->btnOpenFile->Click += gcnew System::EventHandler(this, &UI::btnOpenFile_Click);
				// 
				// btnEncrypt
				// 
				this->btnEncrypt->Enabled = false;
				this->btnEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->btnEncrypt->Location = System::Drawing::Point(22, 168);
				this->btnEncrypt->Name = L"btnEncrypt";
				this->btnEncrypt->Size = System::Drawing::Size(151, 23);
				this->btnEncrypt->TabIndex = 2;
				this->btnEncrypt->Text = L"Encrypt/Decrypt";
				this->btnEncrypt->UseVisualStyleBackColor = true;
				this->btnEncrypt->Click += gcnew System::EventHandler(this, &UI::btnEncrypt_Click);
				// 
				// txtPath
				// 
				this->txtPath->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->txtPath->Location = System::Drawing::Point(57, 42);
				this->txtPath->Name = L"txtPath";
				this->txtPath->Size = System::Drawing::Size(343, 20);
				this->txtPath->TabIndex = 4;
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->BackColor = System::Drawing::Color::Transparent;
				this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label3->ForeColor = System::Drawing::Color::Black;
				this->label3->Location = System::Drawing::Point(21, 126);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(23, 13);
				this->label3->TabIndex = 13;
				this->label3->Text = L"IV:";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->BackColor = System::Drawing::Color::Transparent;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->ForeColor = System::Drawing::Color::Black;
				this->label2->Location = System::Drawing::Point(19, 88);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(32, 13);
				this->label2->TabIndex = 12;
				this->label2->Text = L"Key:";
				// 
				// txtIV
				// 
				this->txtIV->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->txtIV->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtIV->Location = System::Drawing::Point(57, 125);
				this->txtIV->MaxLength = 12;
				this->txtIV->Name = L"txtIV";
				this->txtIV->Size = System::Drawing::Size(116, 20);
				this->txtIV->TabIndex = 11;
				this->txtIV->TextChanged += gcnew System::EventHandler(this, &UI::txtIV_TextChanged);
				this->txtIV->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UI::txtIV_KeyPress);
				// 
				// txtKey
				// 
				this->txtKey->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->txtKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txtKey->Location = System::Drawing::Point(57, 85);
				this->txtKey->MaxLength = 16;
				this->txtKey->Name = L"txtKey";
				this->txtKey->Size = System::Drawing::Size(152, 20);
				this->txtKey->TabIndex = 10;
				this->txtKey->TextChanged += gcnew System::EventHandler(this, &UI::txtKey_TextChanged);
				this->txtKey->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UI::txtKey_KeyPress);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->BackColor = System::Drawing::Color::Transparent;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label1->ForeColor = System::Drawing::Color::Black;
				this->label1->Location = System::Drawing::Point(19, 45);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(37, 13);
				this->label1->TabIndex = 14;
				this->label1->Text = L"Path:";
				// 
				// btnAutoKey
				// 
				this->btnAutoKey->Location = System::Drawing::Point(228, 83);
				this->btnAutoKey->Name = L"btnAutoKey";
				this->btnAutoKey->Size = System::Drawing::Size(75, 23);
				this->btnAutoKey->TabIndex = 15;
				this->btnAutoKey->Text = L"Auto";
				this->btnAutoKey->UseVisualStyleBackColor = true;
				this->btnAutoKey->Click += gcnew System::EventHandler(this, &UI::btnAutoKey_Click);
				// 
				// btnAutoIV
				// 
				this->btnAutoIV->Location = System::Drawing::Point(228, 126);
				this->btnAutoIV->Name = L"btnAutoIV";
				this->btnAutoIV->Size = System::Drawing::Size(75, 23);
				this->btnAutoIV->TabIndex = 16;
				this->btnAutoIV->Text = L"Auto";
				this->btnAutoIV->UseVisualStyleBackColor = true;
				this->btnAutoIV->Click += gcnew System::EventHandler(this, &UI::btnAutoIV_Click);
				// 
				// UI
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				this->ClientSize = System::Drawing::Size(553, 231);
				this->Controls->Add(this->btnAutoIV);
				this->Controls->Add(this->btnAutoKey);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->txtIV);
				this->Controls->Add(this->txtKey);
				this->Controls->Add(this->txtPath);
				this->Controls->Add(this->btnEncrypt);
				this->Controls->Add(this->btnOpenFile);
				this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
				this->Name = L"UI";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Grain 128 - UTN Criptografia";
				this->ResumeLayout(false);
				this->PerformLayout();

			}

		private: System::Void btnOpenFile_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				txtPath->Text = fileDialog->FileName;
				fileDialog->FileName = "C:\\";
			}
		}

		private: System::Void btnEncrypt_Click(System::Object^  sender, System::EventArgs^  e)
		{
			bmpInfoHeader header;
			char *body = NULL;
			char* dir = this->GetCharArray(txtPath->Text);
			char* key = this->GetCharArray(txtKey->Text);
			char* IV = this->GetCharArray(txtIV->Text);

			open_image(dir, &header, &body);

			char* result = encrypt_decrypt(dir, body, header, key, IV);
		}

		private: char* GetCharArray(String^ obj)
		{
			IntPtr tmpHandle = Marshal::StringToHGlobalAnsi(obj);
			return static_cast<char*>(tmpHandle.ToPointer());
		}

		private: System::Void txtKey_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			EnableEncryption();
		}

		private: System::Void txtIV_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			EnableEncryption();
		}

		private: void EnableEncryption()
		{
			if (txtIV->Text->Length == 12 && txtKey->Text->Length == 16)
				btnEncrypt->Enabled = true;
		}

		private: System::Void btnAutoKey_Click(System::Object^  sender, System::EventArgs^  e)
		{
			txtKey->Text = "";
			_key = "";
			System::Random^ ran = gcnew System::Random();
			for (int i = 0; i < 16; i++)
			{
				_key += _alphabet[ran->Next(_alphabet->Length)];
			}

			txtKey->Text = _key;
		}

		private: System::Void btnAutoIV_Click(System::Object^  sender, System::EventArgs^  e)
		{
			txtIV->Text = "";
			_IV = "";
			System::Random^ ran = gcnew System::Random();
			for (int i = 0; i < 12; i++)
			{
				_IV += _alphabet[ran->Next(_alphabet->Length)];
			}

			txtIV->Text = _IV;
		}

		private: System::Void txtIV_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			EnableEncryption();
		}

		private: System::Void txtKey_TextChanged(System::Object^  sender, System::EventArgs^  e)
		{
			EnableEncryption();
		}
	};
}
