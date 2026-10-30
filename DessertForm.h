#pragma once
#include "GlobalData.h"
#include "DessertSelectForm.h"
#include "SettingsForm.h"

namespace CoffeeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DessertForm : public System::Windows::Forms::Form
	{
	public:
		DessertForm(void)
		{
			InitializeComponent();

			this->SettingsButton->Click += gcnew System::EventHandler(this, &DessertForm::SettingsButton_Click);
			this->btnOpenOven->DialogResult = System::Windows::Forms::DialogResult::None;
			this->btnClearDessert->DialogResult = System::Windows::Forms::DialogResult::None;
			this->btnFinishOrder->DialogResult = System::Windows::Forms::DialogResult::None;

			
			this->formTimer = gcnew System::Windows::Forms::Timer();
			this->formTimer->Interval = 1000;
			this->formTimer->Tick += gcnew System::EventHandler(this, &DessertForm::FormTimer_Tick);
			this->formTimer->Start();

			InitTimerControl();
			
			// Выводим информацию о заказе в созданный через конструктор лейбл
			System::String^ orderInfo = "";
			if (GlobalData::NeedsDrink) orderInfo += L"Напиток: " + GlobalData::CurrentDrink + L"\n";
			if (GlobalData::NeedsDessert) orderInfo += L"Десерт: " + GlobalData::CurrentDessert;

			this->lblOrderText->Text = orderInfo;
		}
	protected:
		~DessertForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnOpenOven;
	private: System::Windows::Forms::Button^ btnFinishOrder;
	private: System::Windows::Forms::Button^ btnClearDessert;
	private: System::Windows::Forms::Label^ lblTimer;
	private: System::Windows::Forms::Timer^ formTimer;
	private: System::Windows::Forms::Button^ SettingsButton;



	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblOrderText;

	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DessertForm::typeid));
			   this->btnOpenOven = (gcnew System::Windows::Forms::Button());
			   this->btnFinishOrder = (gcnew System::Windows::Forms::Button());
			   this->btnClearDessert = (gcnew System::Windows::Forms::Button());
			   this->SettingsButton = (gcnew System::Windows::Forms::Button());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblOrderText = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // btnOpenOven
			   // 
			   this->btnOpenOven->BackColor = System::Drawing::Color::Transparent;
			   this->btnOpenOven->FlatAppearance->BorderSize = 0;
			   this->btnOpenOven->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnOpenOven->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnOpenOven->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnOpenOven->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnOpenOven->Location = System::Drawing::Point(144, 109);
			   this->btnOpenOven->Name = L"btnOpenOven";
			   this->btnOpenOven->Size = System::Drawing::Size(951, 442);
			   this->btnOpenOven->TabIndex = 0;
			   this->btnOpenOven->UseVisualStyleBackColor = false;
			   this->btnOpenOven->Click += gcnew System::EventHandler(this, &DessertForm::btnOpenOven_Click);
			   // 
			   // btnFinishOrder
			   // 
			   this->btnFinishOrder->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnFinishOrder->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnFinishOrder->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnFinishOrder->Location = System::Drawing::Point(1258, 655);
			   this->btnFinishOrder->Name = L"btnFinishOrder";
			   this->btnFinishOrder->Size = System::Drawing::Size(177, 41);
			   this->btnFinishOrder->TabIndex = 3;
			   this->btnFinishOrder->Text = L"Отдать заказ";
			   this->btnFinishOrder->UseVisualStyleBackColor = false;
			   this->btnFinishOrder->Click += gcnew System::EventHandler(this, &DessertForm::btnFinishOrder_Click);
			   // 
			   // btnClearDessert
			   // 
			   this->btnClearDessert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				   static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(33)));
			   this->btnClearDessert->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnClearDessert->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnClearDessert->Location = System::Drawing::Point(114, 655);
			   this->btnClearDessert->Name = L"btnClearDessert";
			   this->btnClearDessert->Size = System::Drawing::Size(201, 41);
			   this->btnClearDessert->TabIndex = 2;
			   this->btnClearDessert->Text = L"Выбросить десерт";
			   this->btnClearDessert->UseVisualStyleBackColor = false;
			   this->btnClearDessert->Click += gcnew System::EventHandler(this, &DessertForm::btnClearDessert_Click);
			   // 
			   // SettingsButton
			   // 
			   this->SettingsButton->BackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SettingsButton.BackgroundImage")));
			   this->SettingsButton->FlatAppearance->BorderSize = 0;
			   this->SettingsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->SettingsButton->Location = System::Drawing::Point(1367, 18);
			   this->SettingsButton->Name = L"SettingsButton";
			   this->SettingsButton->Size = System::Drawing::Size(65, 65);
			   this->SettingsButton->TabIndex = 4;
			   this->SettingsButton->UseVisualStyleBackColor = false;
			   // 
			   // lblOrderText
			   // 
			   this->lblOrderText->AutoSize = true;
			   this->lblOrderText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->lblOrderText->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lblOrderText->Location = System::Drawing::Point(509, 18);
			   this->lblOrderText->Name = L"lblOrderText";
			   this->lblOrderText->Size = System::Drawing::Size(221, 24);
			   this->lblOrderText->TabIndex = 7;
			   this->lblOrderText->Text = L"Текущий заказ клиента:";
			   // 
			   // DessertForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(1449, 734);
			   this->ControlBox = false;
			   this->Controls->Add(this->lblOrderText);
			   this->Controls->Add(this->SettingsButton);
			   this->Controls->Add(this->btnFinishOrder);
			   this->Controls->Add(this->btnClearDessert);
			   this->Controls->Add(this->btnOpenOven);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"DessertForm";
			   this->ShowIcon = false;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

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
			   formTimer->Tick += gcnew System::EventHandler(this, &DessertForm::FormTimer_Tick);
			   formTimer->Start();
		   }

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

	

		   System::Void btnOpenOven_Click(System::Object^ sender, System::EventArgs^ e) {
			   formTimer->Stop();
			   DessertSelectForm^ oven = gcnew DessertSelectForm();
			   if (oven->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				  
			   }
			   formTimer->Start();
		   }

		   System::Void btnClearDessert_Click(System::Object^ sender, System::EventArgs^ e) {
			   GlobalData::PlayerDessert = "";
			
		   }

		   System::Void btnFinishOrder_Click(System::Object^ sender, System::EventArgs^ e) {
			   formTimer->Stop();

			   // Возвращаем OK главной форме, сообщая, что заказ успешно собран
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