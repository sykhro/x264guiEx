﻿//  -----------------------------------------------------------------------------------------
//    拡張 x264 出力(GUI) Ex  v1.xx by rigaya
//  -----------------------------------------------------------------------------------------
//   ソースコードについて
//   ・無保証です。
//   ・本ソースコードを使用したことによるいかなる損害・トラブルについてrigayaは責任を負いません。
//   以上に了解して頂ける場合、本ソースコードの使用、複製、改変、再頒布を行って頂いて構いません。
//  -----------------------------------------------------------------------------------------

#pragma once

#include "auo_util.h"
#include "auo_clrutil.h"
#include "auo_settings.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


namespace x264guiEx {

	/// <summary>
	/// frmAutoSaveLogSettings の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class frmAutoSaveLogSettings : public System::Windows::Forms::Form
	{
	private:
		guiEx_settings *fas_ex_stg;
	public:
		frmAutoSaveLogSettings(void)
		{
			fas_ex_stg = new guiEx_settings(true);

			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~frmAutoSaveLogSettings()
		{
			if (components)
			{
				delete components;
			}
			delete fas_ex_stg;
		}
	private:
		static frmAutoSaveLogSettings^ _instance;
	public:
		static property frmAutoSaveLogSettings^ Instance {
			frmAutoSaveLogSettings^ get() {
				if (_instance == nullptr || _instance->IsDisposed)
					_instance = gcnew frmAutoSaveLogSettings();
				return _instance;
			}
		}
	private: System::Windows::Forms::Label^  fasLBAutoSaveLog;
	protected: 

	private: System::Windows::Forms::ComboBox^  fasCXAutoSaveLog;
	private: System::Windows::Forms::TextBox^  fasTXAutoSaveLog;
	protected: 


	private: System::Windows::Forms::Button^  fasBTAutoSaveLog;
	private: System::Windows::Forms::Button^  fasBTCancel;
	private: System::Windows::Forms::Button^  fasBTOK;





	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->fasLBAutoSaveLog = (gcnew System::Windows::Forms::Label());
			this->fasCXAutoSaveLog = (gcnew System::Windows::Forms::ComboBox());
			this->fasTXAutoSaveLog = (gcnew System::Windows::Forms::TextBox());
			this->fasBTAutoSaveLog = (gcnew System::Windows::Forms::Button());
			this->fasBTCancel = (gcnew System::Windows::Forms::Button());
			this->fasBTOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// fasLBAutoSaveLog
			// 
			this->fasLBAutoSaveLog->AutoSize = true;
			this->fasLBAutoSaveLog->Location = System::Drawing::Point(23, 28);
			this->fasLBAutoSaveLog->Name = L"fasLBAutoSaveLog";
			this->fasLBAutoSaveLog->Size = System::Drawing::Size(119, 15);
			this->fasLBAutoSaveLog->TabIndex = 0;
			this->fasLBAutoSaveLog->Text = L"自動ログ保存ファイル名";
			// 
			// fasCXAutoSaveLog
			// 
			this->fasCXAutoSaveLog->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->fasCXAutoSaveLog->FormattingEnabled = true;
			this->fasCXAutoSaveLog->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"出力先と同じ", L"カスタム"});
			this->fasCXAutoSaveLog->Location = System::Drawing::Point(148, 25);
			this->fasCXAutoSaveLog->Name = L"fasCXAutoSaveLog";
			this->fasCXAutoSaveLog->Size = System::Drawing::Size(178, 23);
			this->fasCXAutoSaveLog->TabIndex = 1;
			// 
			// fasTXAutoSaveLog
			// 
			this->fasTXAutoSaveLog->Location = System::Drawing::Point(52, 54);
			this->fasTXAutoSaveLog->Name = L"fasTXAutoSaveLog";
			this->fasTXAutoSaveLog->Size = System::Drawing::Size(290, 23);
			this->fasTXAutoSaveLog->TabIndex = 2;
			// 
			// fasBTAutoSaveLog
			// 
			this->fasBTAutoSaveLog->Location = System::Drawing::Point(348, 53);
			this->fasBTAutoSaveLog->Name = L"fasBTAutoSaveLog";
			this->fasBTAutoSaveLog->Size = System::Drawing::Size(33, 23);
			this->fasBTAutoSaveLog->TabIndex = 3;
			this->fasBTAutoSaveLog->Text = L"..";
			this->fasBTAutoSaveLog->UseVisualStyleBackColor = true;
			this->fasBTAutoSaveLog->Click += gcnew System::EventHandler(this, &frmAutoSaveLogSettings::fasBTAutoSaveLog_Click);
			// 
			// fasBTCancel
			// 
			this->fasBTCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->fasBTCancel->Location = System::Drawing::Point(227, 93);
			this->fasBTCancel->Name = L"fasBTCancel";
			this->fasBTCancel->Size = System::Drawing::Size(75, 32);
			this->fasBTCancel->TabIndex = 4;
			this->fasBTCancel->Text = L"キャンセル";
			this->fasBTCancel->UseVisualStyleBackColor = true;
			this->fasBTCancel->Click += gcnew System::EventHandler(this, &frmAutoSaveLogSettings::fasBTCancel_Click);
			// 
			// fasBTOK
			// 
			this->fasBTOK->Location = System::Drawing::Point(311, 93);
			this->fasBTOK->Name = L"fasBTOK";
			this->fasBTOK->Size = System::Drawing::Size(75, 32);
			this->fasBTOK->TabIndex = 5;
			this->fasBTOK->Text = L"OK";
			this->fasBTOK->UseVisualStyleBackColor = true;
			this->fasBTOK->Click += gcnew System::EventHandler(this, &frmAutoSaveLogSettings::fasBTOK_Click);
			// 
			// frmAutoSaveLogSettings
			// 
			this->AcceptButton = this->fasBTOK;
			this->CancelButton = this->fasBTCancel;
			this->ClientSize = System::Drawing::Size(393, 137);
			this->Controls->Add(this->fasBTOK);
			this->Controls->Add(this->fasBTCancel);
			this->Controls->Add(this->fasBTAutoSaveLog);
			this->Controls->Add(this->fasTXAutoSaveLog);
			this->Controls->Add(this->fasCXAutoSaveLog);
			this->Controls->Add(this->fasLBAutoSaveLog);
			this->Font = (gcnew System::Drawing::Font(L"Meiryo UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmAutoSaveLogSettings";
			this->ShowIcon = false;
			this->Text = L"自動ログ保存";
			this->Load += gcnew System::EventHandler(this, &frmAutoSaveLogSettings::frmAutoSaveLogSettings_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void SetCXIndex(ComboBox^ CX, int index) {
			CX->SelectedIndex = clamp(index, 0, CX->Items->Count - 1);
		}
	private:
		System::Void SavefasToStg() {
			fas_ex_stg->load_log_win();
			fas_ex_stg->s_log.auto_save_log_mode = fasCXAutoSaveLog->SelectedIndex;
			GetCHARfromString(fas_ex_stg->s_log.auto_save_log_path, sizeof(fas_ex_stg->s_log.auto_save_log_path), fasTXAutoSaveLog->Text);
			fas_ex_stg->save_log_win();
		}
	private: 
		System::Void frmAutoSaveLogSettings_Load(System::Object^  sender, System::EventArgs^  e) {
			fas_ex_stg->load_log_win();
			SetCXIndex(fasCXAutoSaveLog, fas_ex_stg->s_log.auto_save_log_mode);
			fasTXAutoSaveLog->Text = String(fas_ex_stg->s_log.auto_save_log_path).ToString();
		}
	private: 
		System::Void fasBTOK_Click(System::Object^  sender, System::EventArgs^  e) {
			SavefasToStg();
			this->Close();
		}
	private: 
		System::Void fasBTCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}
	private: 
		System::Void fasBTAutoSaveLog_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ CurrentDir = Directory::GetCurrentDirectory();
			SaveFileDialog^ sfd = gcnew SaveFileDialog();
			sfd->FileName = L"";
			if (fasTXAutoSaveLog->Text->Length) {
				String^ fileName = nullptr;
				try {
					fileName = Path::GetFileName(fasTXAutoSaveLog->Text);
				} catch (...) {
					//invalid charによる例外は破棄
				}
				if (fileName != nullptr)
					sfd->FileName = fileName;
			}
			sfd->Filter = L"ログファイル(*.txt)|*.txt|すべてのファイル(*.*)|*.*";
			if (sfd->ShowDialog() == Windows::Forms::DialogResult::OK) {
				fasTXAutoSaveLog->Text = sfd->FileName;
				fasTXAutoSaveLog->SelectionStart = fasTXAutoSaveLog->Text->Length;
			}
			Directory::SetCurrentDirectory(CurrentDir);
			return;
		}
};
}