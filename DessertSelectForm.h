#pragma once
#include "GlobalData.h"

namespace CoffeeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DessertSelectForm : public System::Windows::Forms::Form
	{
	private:
		// Состояние кондитерской чаши 
		bool cookieAdded = false;
		bool fillingAdded = false;
		bool creamAdded = false;
		bool doughAdded = false;

	public:
		DessertSelectForm(void)
		{
			InitializeComponent();
			lbDessertRecipes->Items->Add("Чизкейк: Печенье + Начинка + Крем");
			lbDessertRecipes->Items->Add("Кекс: Тесто + Начинка");
			lbDessertRecipes->Items->Add("Макарон: Тесто + Начинка");
			RefreshOvenStatus();
		}

	protected:
		~DessertSelectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ lbDessertRecipes;
	private: System::Windows::Forms::Button^ btnAddCookie;
	private: System::Windows::Forms::Button^ btnAddFilling;
	private: System::Windows::Forms::Button^ btnAddCream;
	private: System::Windows::Forms::Button^ btnAddDough;
	private: System::Windows::Forms::Label^ lblOvenMix;
	private: System::Windows::Forms::Button^ btnBake;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DessertSelectForm::typeid));
			   this->lbDessertRecipes = (gcnew System::Windows::Forms::ListBox());
			   this->btnAddCookie = (gcnew System::Windows::Forms::Button());
			   this->btnAddFilling = (gcnew System::Windows::Forms::Button());
			   this->btnAddCream = (gcnew System::Windows::Forms::Button());
			   this->btnAddDough = (gcnew System::Windows::Forms::Button());
			   this->lblOvenMix = (gcnew System::Windows::Forms::Label());
			   this->btnBake = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // lbDessertRecipes
			   // 
			   this->lbDessertRecipes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->lbDessertRecipes->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lbDessertRecipes->FormattingEnabled = true;
			   this->lbDessertRecipes->ItemHeight = 24;
			   this->lbDessertRecipes->Location = System::Drawing::Point(130, 32);
			   this->lbDessertRecipes->Name = L"lbDessertRecipes";
			   this->lbDessertRecipes->Size = System::Drawing::Size(320, 48);
			   this->lbDessertRecipes->TabIndex = 0;
			   // 
			   // btnAddCookie
			   // 
			   this->btnAddCookie->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddCookie->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddCookie->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddCookie->Location = System::Drawing::Point(76, 147);
			   this->btnAddCookie->Name = L"btnAddCookie";
			   this->btnAddCookie->Size = System::Drawing::Size(150, 40);
			   this->btnAddCookie->TabIndex = 1;
			   this->btnAddCookie->Text = L"Всыпать Печенье";
			   this->btnAddCookie->UseVisualStyleBackColor = false;
			   this->btnAddCookie->Click += gcnew System::EventHandler(this, &DessertSelectForm::BakeIngredient_Click);
			   // 
			   // btnAddFilling
			   // 
			   this->btnAddFilling->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddFilling->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddFilling->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddFilling->Location = System::Drawing::Point(330, 147);
			   this->btnAddFilling->Name = L"btnAddFilling";
			   this->btnAddFilling->Size = System::Drawing::Size(150, 40);
			   this->btnAddFilling->TabIndex = 2;
			   this->btnAddFilling->Text = L"Добавить Начинку";
			   this->btnAddFilling->UseVisualStyleBackColor = false;
			   this->btnAddFilling->Click += gcnew System::EventHandler(this, &DessertSelectForm::BakeIngredient_Click);
			   // 
			   // btnAddCream
			   // 
			   this->btnAddCream->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddCream->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddCream->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddCream->Location = System::Drawing::Point(76, 219);
			   this->btnAddCream->Name = L"btnAddCream";
			   this->btnAddCream->Size = System::Drawing::Size(150, 40);
			   this->btnAddCream->TabIndex = 3;
			   this->btnAddCream->Text = L"Выдавить Крем";
			   this->btnAddCream->UseVisualStyleBackColor = false;
			   this->btnAddCream->Click += gcnew System::EventHandler(this, &DessertSelectForm::BakeIngredient_Click);
			   // 
			   // btnAddDough
			   // 
			   this->btnAddDough->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnAddDough->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddDough->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnAddDough->Location = System::Drawing::Point(330, 219);
			   this->btnAddDough->Name = L"btnAddDough";
			   this->btnAddDough->Size = System::Drawing::Size(150, 40);
			   this->btnAddDough->TabIndex = 4;
			   this->btnAddDough->Text = L"Замесить Тесто";
			   this->btnAddDough->UseVisualStyleBackColor = false;
			   this->btnAddDough->Click += gcnew System::EventHandler(this, &DessertSelectForm::BakeIngredient_Click);
			   // 
			   // lblOvenMix
			   // 
			   this->lblOvenMix->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->lblOvenMix->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lblOvenMix->Location = System::Drawing::Point(126, 324);
			   this->lblOvenMix->Name = L"lblOvenMix";
			   this->lblOvenMix->Size = System::Drawing::Size(320, 45);
			   this->lblOvenMix->TabIndex = 5;
			   this->lblOvenMix->Text = L"В миске...";
			   // 
			   // btnBake
			   // 
			   this->btnBake->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			   this->btnBake->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnBake->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnBake->Location = System::Drawing::Point(192, 422);
			   this->btnBake->Name = L"btnBake";
			   this->btnBake->Size = System::Drawing::Size(190, 45);
			   this->btnBake->TabIndex = 6;
			   this->btnBake->Text = L"Испечь десерт";
			   this->btnBake->UseVisualStyleBackColor = false;
			   this->btnBake->Click += gcnew System::EventHandler(this, &DessertSelectForm::btnBake_Click);
			   // 
			   // DessertSelectForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(575, 526);
			   this->ControlBox = false;
			   this->Controls->Add(this->btnBake);
			   this->Controls->Add(this->lblOvenMix);
			   this->Controls->Add(this->btnAddDough);
			   this->Controls->Add(this->btnAddCream);
			   this->Controls->Add(this->btnAddFilling);
			   this->Controls->Add(this->btnAddCookie);
			   this->Controls->Add(this->lbDessertRecipes);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"DessertSelectForm";
			   this->ShowIcon = false;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->ResumeLayout(false);

		   }
#pragma endregion

		   void RefreshOvenStatus() {
			   lblOvenMix->Text = "Замешано: " +
				   (cookieAdded ? "[Печенье] " : "") + (fillingAdded ? "[Начинка] " : "") +
				   (creamAdded ? "[Крем] " : "") + (doughAdded ? "[Тесто]" : "");
		   }

		   // Клик по ингридиентам 
		   System::Void BakeIngredient_Click(System::Object^ sender, System::EventArgs^ e) {
			   Button^ currentBtn = (Button^)sender;

			   if (currentBtn == btnAddCookie && GlobalData::CookieCount > 0) {
				   cookieAdded = true; GlobalData::CookieCount--;
			   }
			   else if (currentBtn == btnAddFilling && GlobalData::FillingCount > 0) {
				   fillingAdded = true; GlobalData::FillingCount--;
			   }
			   else if (currentBtn == btnAddCream && GlobalData::CreamCount > 0) {
				   creamAdded = true; GlobalData::CreamCount--;
			   }
			   else if (currentBtn == btnAddDough && GlobalData::DoughCount > 0) {
				   doughAdded = true; GlobalData::DoughCount--;
			   }
			   else {
				   MessageBox::Show("Недостаточно продуктов на складе!", "Ресурсы исчерпаны", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			   }
			   RefreshOvenStatus();
		   }

		   // Выпекание десерта
		   System::Void btnBake_Click(System::Object^ sender, System::EventArgs^ e) {
			   System::String^ cookedDessert = "";

			   if (cookieAdded && fillingAdded && creamAdded && !doughAdded) {
				   cookedDessert = "Чизкейк";
			   }
			   else if (!cookieAdded && fillingAdded && !creamAdded && doughAdded) {
				   if (GlobalData::CurrentDessert == "Макарон") {
					   cookedDessert = "Макарон";
				   }
				   else {
					   cookedDessert = "Кекс";
				   }
			   }

			   if (cookedDessert != "") {
				   GlobalData::PlayerDessert = cookedDessert;
				   MessageBox::Show("Вы успешно испекли: " + cookedDessert, "Готово!", MessageBoxButtons::OK, MessageBoxIcon::Information);

				   this->DialogResult = System::Windows::Forms::DialogResult::OK;
				   this->Close();
			   }
			   else {
				   MessageBox::Show("Ингредиенты сгорели! Сверьтесь с книгой рецептов.", "Рецепт не удался", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   GlobalData::PlayerDessert = "";
				   this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				   this->Close();
			   }
		   }
	};
}