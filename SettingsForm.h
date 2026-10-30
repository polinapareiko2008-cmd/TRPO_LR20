#pragma once
#include "GlobalData.h"

namespace CoffeeGame {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Button^ btnToggleMusic;
		System::Windows::Forms::Button^ btnMainMenu;
		System::Windows::Forms::Button^ btnExit;
		System::Windows::Forms::Button^ btnClose;

	public:
		System::String^ Action;

		SettingsForm(void)
		{
			Action = "";
			InitializeComponent();
			UpdateButtonText();
		}

	private:
		void InitializeComponent(void)
		{
			this->btnToggleMusic = (gcnew System::Windows::Forms::Button());
			this->btnMainMenu = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			int r = 1258 % 256; // Получится 234
			int g = 655 % 256;  // Получится 143
			int b = (1258 + 655) % 256; // Сбалансированный синий компонент (111)
			System::Drawing::Color buttonBackColor = System::Drawing::Color::FromArgb(150, r, g, b);

			// 
			// btnToggleMusic
			// 
			this->btnToggleMusic->Location = System::Drawing::Point(30, 20);
			this->btnToggleMusic->Size = System::Drawing::Size(180, 35);
			this->btnToggleMusic->BackColor = buttonBackColor;
			this->btnToggleMusic->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnToggleMusic->UseVisualStyleBackColor = false;
			this->btnToggleMusic->Click += gcnew System::EventHandler(this, &SettingsForm::btnToggleMusic_Click);

			// 
			// btnMainMenu
			// 
			this->btnMainMenu->Text = L"Главное меню";
			this->btnMainMenu->Location = System::Drawing::Point(30, 70);
			this->btnMainMenu->Size = System::Drawing::Size(180, 35);
			this->btnMainMenu->BackColor = buttonBackColor;
			this->btnMainMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMainMenu->UseVisualStyleBackColor = false;
			this->btnMainMenu->Click += gcnew System::EventHandler(this, &SettingsForm::btnMainMenu_Click);

			// 
			// btnExit
			// 
			this->btnExit->Text = L"Выйти из игры";
			this->btnExit->Location = System::Drawing::Point(30, 120);
			this->btnExit->Size = System::Drawing::Size(180, 35);
			this->btnExit->BackColor = buttonBackColor;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &SettingsForm::btnExit_Click);

			// 
			// btnClose
			// 
			this->btnClose->Text = L"Назад к игре";
			this->btnClose->Location = System::Drawing::Point(30, 170);
			this->btnClose->Size = System::Drawing::Size(180, 35);
			this->btnClose->BackColor = buttonBackColor;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &SettingsForm::btnClose_Click);

			// 
			// SettingsForm
			// 
			this->ClientSize = System::Drawing::Size(240, 230);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnMainMenu);
			this->Controls->Add(this->btnToggleMusic);

			// Установка единого шрифта Monotype Corsiva, 12pt, Bold + Italic для всей формы
			this->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12,
				static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));

			// Настройки цвета фона самой формы 
			this->BackColor = System::Drawing::Color::FromArgb(255, 255, 255, 255);

			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Настройки";
			this->ResumeLayout(false);
		}

		void UpdateButtonText() {
			if (GlobalData::IsMusicPlaying) {
				btnToggleMusic->Text = L"Выключить музыку";
			}
			else {
				btnToggleMusic->Text = L"Включить музыку";
			}
		}

		System::Void btnToggleMusic_Click(Object^ sender, EventArgs^ e) {
			GlobalData::ToggleMusic();
			UpdateButtonText();
		}

		System::Void btnMainMenu_Click(Object^ sender, EventArgs^ e) {
			this->Action = "MainMenu";
			this->Close();
		}

		System::Void btnExit_Click(Object^ sender, EventArgs^ e) {
			this->Action = "Exit";
			this->Close();
		}

		System::Void btnClose_Click(Object^ sender, EventArgs^ e) {
			this->Action = "Close";
			this->Close();
		}
	};
}