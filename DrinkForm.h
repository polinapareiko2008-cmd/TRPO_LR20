#pragma once
#include "GlobalData.h"
#include "DessertForm.h"
#include "CoffeeMachineForm.h"
#include "SettingsForm.h"

namespace CoffeeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DrinkForm : public System::Windows::Forms::Form
	{
	public:
		DrinkForm(void)
		{
			InitializeComponent();
			this->btnFinish->DialogResult = System::Windows::Forms::DialogResult::None;
			this->btnNext->DialogResult = System::Windows::Forms::DialogResult::None;

			// Если в заказе есть десерт, кнопку "Отдать заказ" прячем
			if (GlobalData::NeedsDessert) {
				this->btnFinish->Visible = false;
			}
			else {
				this->btnFinish->Visible = true;

				this->formTimer = gcnew System::Windows::Forms::Timer();
				this->formTimer->Interval = 1000;
				this->formTimer->Tick += gcnew System::EventHandler(this, &DrinkForm::FormTimer_Tick);
				this->formTimer->Start();
			}

			InitTimerControl();
			
			// Выводим информацию о заказе в лейбл
			System::String^ orderInfo = "";
			if (GlobalData::NeedsDrink) orderInfo += L"Напиток: " + GlobalData::CurrentDrink + L"\n";
			if (GlobalData::NeedsDessert) orderInfo += L"Десерт: " + GlobalData::CurrentDessert;

			this->lblOrderText->Text = orderInfo;
		}

	protected:
		~DrinkForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCoffeeMachine;
	private: System::Windows::Forms::Button^ btnNext;
	private: System::Windows::Forms::Button^ btnFinish;
	private: System::Windows::Forms::Button^ btnClear;

		   // Новые элементы для локального отслеживания времени
	private: System::Windows::Forms::Label^ lblTimer;
	private: System::Windows::Forms::Timer^ formTimer;
	private: System::Windows::Forms::Button^ SettingsButton;


	private: System::Windows::Forms::Label^ lblOrderText;



	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DrinkForm::typeid));
			   this->btnCoffeeMachine = (gcnew System::Windows::Forms::Button());
			   this->btnNext = (gcnew System::Windows::Forms::Button());
			   this->btnFinish = (gcnew System::Windows::Forms::Button());
			   this->btnClear = (gcnew System::Windows::Forms::Button());
			   this->SettingsButton = (gcnew System::Windows::Forms::Button());
			   this->lblOrderText = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // btnCoffeeMachine
			   // 
			   this->btnCoffeeMachine->BackColor = System::Drawing::Color::Transparent;
			   this->btnCoffeeMachine->FlatAppearance->BorderSize = 0;
			   this->btnCoffeeMachine->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnCoffeeMachine->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnCoffeeMachine->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnCoffeeMachine->Location = System::Drawing::Point(187, 133);
			   this->btnCoffeeMachine->Name = L"btnCoffeeMachine";
			   this->btnCoffeeMachine->Size = System::Drawing::Size(350, 316);
			   this->btnCoffeeMachine->TabIndex = 0;
			   this->btnCoffeeMachine->UseVisualStyleBackColor = false;
			   this->btnCoffeeMachine->Click += gcnew System::EventHandler(this, &DrinkForm::btnCoffeeMachine_Click);
			   // 
			   // btnNext
			   // 
			   this->btnNext->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			   this->btnNext->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnNext->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnNext->Location = System::Drawing::Point(1272, 649);
			   this->btnNext->Name = L"btnNext";
			   this->btnNext->Size = System::Drawing::Size(160, 45);
			   this->btnNext->TabIndex = 3;
			   this->btnNext->Text = L"Десерты-->";
			   this->btnNext->UseVisualStyleBackColor = false;
			   this->btnNext->Click += gcnew System::EventHandler(this, &DrinkForm::btnNext_Click);
			   // 
			   // btnFinish
			   // 
			   this->btnFinish->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnFinish->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnFinish->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnFinish->Location = System::Drawing::Point(1094, 649);
			   this->btnFinish->Name = L"btnFinish";
			   this->btnFinish->Size = System::Drawing::Size(160, 45);
			   this->btnFinish->TabIndex = 4;
			   this->btnFinish->Text = L"Отдать заказ";
			   this->btnFinish->UseVisualStyleBackColor = false;
			   this->btnFinish->Click += gcnew System::EventHandler(this, &DrinkForm::btnFinish_Click);
			   // 
			   // btnClear
			   // 
			   this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				   static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			   this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnClear->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnClear->Location = System::Drawing::Point(114, 648);
			   this->btnClear->Name = L"btnClear";
			   this->btnClear->Size = System::Drawing::Size(203, 46);
			   this->btnClear->TabIndex = 2;
			   this->btnClear->Text = L"Выбросить напиток";
			   this->btnClear->UseVisualStyleBackColor = false;
			   this->btnClear->Click += gcnew System::EventHandler(this, &DrinkForm::btnClear_Click);
			   // 
			   // SettingsButton
			   // 
			   this->SettingsButton->BackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SettingsButton.BackgroundImage")));
			   this->SettingsButton->FlatAppearance->BorderSize = 0;
			   this->SettingsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->SettingsButton->Location = System::Drawing::Point(1351, 20);
			   this->SettingsButton->Name = L"SettingsButton";
			   this->SettingsButton->Size = System::Drawing::Size(65, 65);
			   this->SettingsButton->TabIndex = 6;
			   this->SettingsButton->UseVisualStyleBackColor = false;
			   this->SettingsButton->Click += gcnew System::EventHandler(this, &DrinkForm::SettingsButton_Click);
			   // 
			   // lblOrderText
			   // 
			   this->lblOrderText->AutoSize = true;
			   this->lblOrderText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->lblOrderText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->lblOrderText->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lblOrderText->Location = System::Drawing::Point(481, 20);
			   this->lblOrderText->Name = L"lblOrderText";
			   this->lblOrderText->Size = System::Drawing::Size(221, 24);
			   this->lblOrderText->TabIndex = 9;
			   this->lblOrderText->Text = L"Текущий заказ клиента:";
			   // 
			   // DrinkForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(1444, 725);
			   this->ControlBox = false;
			   this->Controls->Add(this->lblOrderText);
			   this->Controls->Add(this->SettingsButton);
			   this->Controls->Add(this->btnFinish);
			   this->Controls->Add(this->btnNext);
			   this->Controls->Add(this->btnClear);
			   this->Controls->Add(this->btnCoffeeMachine);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"DrinkForm";
			   this->ShowIcon = false;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // Динамическое добавление таймера
		   void InitTimerControl() {
			   lblTimer = gcnew System::Windows::Forms::Label();
			   lblTimer->BackColor = System::Drawing::Color::MistyRose;
			   lblTimer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   lblTimer->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			   lblTimer->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   lblTimer->Location = System::Drawing::Point(650, 14);
			   lblTimer->Size = System::Drawing::Size(200, 25);
			   lblTimer->Text = "Осталось: " + GlobalData::OrderTimeLeft + " сек.";
			   this->Controls->Add(lblTimer);

			   formTimer = gcnew System::Windows::Forms::Timer();
			   formTimer->Interval = 1000;
			   formTimer->Tick += gcnew System::EventHandler(this, &DrinkForm::FormTimer_Tick);
			   formTimer->Start();
		   }
		   // Обработчик тика времени на этой форме
		   System::Void FormTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			   if (GlobalData::OrderTimeLeft > 0) {
				   GlobalData::OrderTimeLeft--;
				   this->lblTimer->Text = "Осталось: " + GlobalData::OrderTimeLeft + " сек.";
			   }

			   if (GlobalData::OrderTimeLeft <= 0) {
				   this->formTimer->Stop();
				   // Если время вышло на кухне, закрываем форму с отменой
				   this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				   this->Close();
			   }
		   }
		 
		   System::Void btnCoffeeMachine_Click(System::Object^ sender, System::EventArgs^ e) {
			   formTimer->Stop();
			   CoffeeMachineForm^ machine = gcnew CoffeeMachineForm();
			   if (machine->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			   }
			   formTimer->Start();
		   }

		   System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
			   GlobalData::PlayerDrink = "";
			   
		   }

		   System::Void btnNext_Click(System::Object^ sender, System::EventArgs^ e) {
			   formTimer->Stop();

			   DessertForm^ dessertScreen = gcnew DessertForm();
			   System::Windows::Forms::DialogResult res = dessertScreen->ShowDialog();

			   // Если на форме десертов нажали "Отдать заказ" (OK)
			   if (res == System::Windows::Forms::DialogResult::OK) {
				   // Закрываем форму напитков со статусом OK, чтобы цепочка вернулась в GameForm
				   this->DialogResult = System::Windows::Forms::DialogResult::OK;
				   this->Close();
				   return;
			   }
			   else if (res == System::Windows::Forms::DialogResult::Abort) {
				   this->DialogResult = System::Windows::Forms::DialogResult::Abort;
				   this->Close();
				   return;
			   }

			   formTimer->Start();
			   
		   }

		   System::Void btnFinish_Click(System::Object^ sender, System::EventArgs^ e) {
			   formTimer->Stop();

			   // говорим главной форме, что заказ успешно выполнен
			   this->DialogResult = System::Windows::Forms::DialogResult::OK;
			   this->Close();
		   }
		   System::Void SettingsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   SettingsForm^ settings = gcnew SettingsForm();
			   settings->ShowDialog();

			   if (settings->Action == "Exit") {
				   Application::Exit();
			   }
			   else if (settings->Action == "MainMenu") {
				   this->DialogResult = System::Windows::Forms::DialogResult::Abort;
				   this->Close();
			   }
		   }
	};
}