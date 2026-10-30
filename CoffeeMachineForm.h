#pragma once
#include "GlobalData.h"

namespace CoffeeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CoffeeMachineForm : public System::Windows::Forms::Form
	{
	private:
		bool waterAdded;
		bool coffeeAdded;
		bool milkAdded;
		bool syrupAdded;

	public:
		CoffeeMachineForm(void)
		{
			InitializeComponent();
			waterAdded = false;
			coffeeAdded = false;
			milkAdded = false;
			syrupAdded = false;

			lbRecipes->Items->Add("Американо: Вода + Кофе");
			lbRecipes->Items->Add("Капучино: Вода + Кофе + Milk");
			lbRecipes->Items->Add("Раф: Вода + Кофе + Молоко + Сироп");
			RefreshStatus();
		}

	protected:
		~CoffeeMachineForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ lbRecipes;
	private: System::Windows::Forms::Button^ btnAddWater;
	private: System::Windows::Forms::Button^ btnAddCoffee;
	private: System::Windows::Forms::Button^ btnAddMilk;
	private: System::Windows::Forms::Button^ btnAddSyrup;
	private: System::Windows::Forms::Label^ lblCurrentMix;
	private: System::Windows::Forms::Button^ btnMix;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CoffeeMachineForm::typeid));
			   this->lbRecipes = (gcnew System::Windows::Forms::ListBox());
			   this->btnAddWater = (gcnew System::Windows::Forms::Button());
			   this->btnAddCoffee = (gcnew System::Windows::Forms::Button());
			   this->btnAddMilk = (gcnew System::Windows::Forms::Button());
			   this->btnAddSyrup = (gcnew System::Windows::Forms::Button());
			   this->lblCurrentMix = (gcnew System::Windows::Forms::Label());
			   this->btnMix = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // lbRecipes
			   // 
			   this->lbRecipes->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->lbRecipes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->lbRecipes->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lbRecipes->FormattingEnabled = true;
			   this->lbRecipes->ItemHeight = 24;
			   this->lbRecipes->Location = System::Drawing::Point(138, 49);
			   this->lbRecipes->Name = L"lbRecipes";
			   this->lbRecipes->Size = System::Drawing::Size(320, 48);
			   this->lbRecipes->TabIndex = 0;
			   // 
			   // btnAddWater
			   // 
			   this->btnAddWater->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddWater->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddWater->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddWater->Location = System::Drawing::Point(82, 149);
			   this->btnAddWater->Name = L"btnAddWater";
			   this->btnAddWater->Size = System::Drawing::Size(150, 40);
			   this->btnAddWater->TabIndex = 1;
			   this->btnAddWater->Text = L"Добавить Воду";
			   this->btnAddWater->UseVisualStyleBackColor = false;
			   this->btnAddWater->Click += gcnew System::EventHandler(this, &CoffeeMachineForm::Ingredient_Click);
			   // 
			   // btnAddCoffee
			   // 
			   this->btnAddCoffee->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddCoffee->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddCoffee->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddCoffee->Location = System::Drawing::Point(332, 149);
			   this->btnAddCoffee->Name = L"btnAddCoffee";
			   this->btnAddCoffee->Size = System::Drawing::Size(150, 40);
			   this->btnAddCoffee->TabIndex = 2;
			   this->btnAddCoffee->Text = L"Добавить Кофе";
			   this->btnAddCoffee->UseVisualStyleBackColor = false;
			   this->btnAddCoffee->Click += gcnew System::EventHandler(this, &CoffeeMachineForm::Ingredient_Click);
			   // 
			   // btnAddMilk
			   // 
			   this->btnAddMilk->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddMilk->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddMilk->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddMilk->Location = System::Drawing::Point(82, 223);
			   this->btnAddMilk->Name = L"btnAddMilk";
			   this->btnAddMilk->Size = System::Drawing::Size(150, 40);
			   this->btnAddMilk->TabIndex = 3;
			   this->btnAddMilk->Text = L"Добавить Молоко";
			   this->btnAddMilk->UseVisualStyleBackColor = false;
			   this->btnAddMilk->Click += gcnew System::EventHandler(this, &CoffeeMachineForm::Ingredient_Click);
			   // 
			   // btnAddSyrup
			   // 
			   this->btnAddSyrup->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddSyrup->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddSyrup->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddSyrup->Location = System::Drawing::Point(332, 223);
			   this->btnAddSyrup->Name = L"btnAddSyrup";
			   this->btnAddSyrup->Size = System::Drawing::Size(150, 40);
			   this->btnAddSyrup->TabIndex = 4;
			   this->btnAddSyrup->Text = L"Добавить Сироп";
			   this->btnAddSyrup->UseVisualStyleBackColor = false;
			   this->btnAddSyrup->Click += gcnew System::EventHandler(this, &CoffeeMachineForm::Ingredient_Click);
			   // 
			   // lblCurrentMix
			   // 
			   this->lblCurrentMix->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->lblCurrentMix->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->lblCurrentMix->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->lblCurrentMix->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lblCurrentMix->Location = System::Drawing::Point(138, 314);
			   this->lblCurrentMix->Name = L"lblCurrentMix";
			   this->lblCurrentMix->Size = System::Drawing::Size(320, 45);
			   this->lblCurrentMix->TabIndex = 5;
			   this->lblCurrentMix->Text = L"Содержимое...";
			   // 
			   // btnMix
			   // 
			   this->btnMix->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			   this->btnMix->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnMix->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnMix->Location = System::Drawing::Point(193, 448);
			   this->btnMix->Name = L"btnMix";
			   this->btnMix->Size = System::Drawing::Size(190, 45);
			   this->btnMix->TabIndex = 6;
			   this->btnMix->Text = L"Включить Смешивание";
			   this->btnMix->UseVisualStyleBackColor = false;
			   this->btnMix->Click += gcnew System::EventHandler(this, &CoffeeMachineForm::btnMix_Click);
			   // 
			   // CoffeeMachineForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(575, 526);
			   this->ControlBox = false;
			   this->Controls->Add(this->btnMix);
			   this->Controls->Add(this->lblCurrentMix);
			   this->Controls->Add(this->btnAddSyrup);
			   this->Controls->Add(this->btnAddMilk);
			   this->Controls->Add(this->btnAddCoffee);
			   this->Controls->Add(this->btnAddWater);
			   this->Controls->Add(this->lbRecipes);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"CoffeeMachineForm";
			   this->ShowIcon = false;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   void RefreshStatus() {
			   lblCurrentMix->Text = "В баке: " +
				   (waterAdded ? "[Вода] " : "") + (coffeeAdded ? "[Кофе] " : "") +
				   (milkAdded ? "[Молоко] " : "") + (syrupAdded ? "[Сироп]" : "");
		   }

		   System::Void Ingredient_Click(System::Object^ sender, System::EventArgs^ e) {
			   Button^ currentBtn = (Button^)sender;

			   if (currentBtn == btnAddWater) {
				   waterAdded = true;
			   }
			   else if (currentBtn == btnAddCoffee && GlobalData::CoffeeCount > 0) {
				   coffeeAdded = true; GlobalData::CoffeeCount--;
			   }
			   else if (currentBtn == btnAddMilk && GlobalData::MilkCount > 0) {
				   milkAdded = true; GlobalData::MilkCount--;
			   }
			   else if (currentBtn == btnAddSyrup && GlobalData::SyrupCount > 0) {
				   syrupAdded = true; GlobalData::SyrupCount--;
			   }
			   else {
				   MessageBox::Show("Этого ингредиента нет на складе! Закупите его в зале.", "Ошибка ресурсов", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			   }
			   RefreshStatus();
		   }

		   System::Void btnMix_Click(System::Object^ sender, System::EventArgs^ e) {
			   System::String^ resultProduct = "";

			   if (waterAdded && coffeeAdded && !milkAdded && !syrupAdded) {
				   resultProduct = "Американо";
			   }
			   else if (waterAdded && coffeeAdded && milkAdded && !syrupAdded) {
				   resultProduct = "Капучино";
			   }
			   else if (waterAdded && coffeeAdded && milkAdded && syrupAdded) {
				   resultProduct = "Раф";
			   }

			   if (resultProduct != "") {
				   GlobalData::PlayerDrink = resultProduct;
				   MessageBox::Show("Вы успешно приготовили: " + resultProduct, "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);

				   this->DialogResult = System::Windows::Forms::DialogResult::OK;
				   this->Close();
			   }
			   else {
				   MessageBox::Show("Из этой комбинации ингредиентов ничего не получилось! Попробуйте другой рецепт.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   GlobalData::PlayerDrink = "";
				   this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				   this->Close();
			   }
		   }
	};
}