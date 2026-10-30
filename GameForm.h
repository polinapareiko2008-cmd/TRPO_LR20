#pragma once
#include "GlobalData.h"
#include "DrinkForm.h"
#include "SettingsForm.h"

namespace CoffeeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GameForm : public System::Windows::Forms::Form
	{
	private:
		System::Drawing::Image^ trayBaseImage;

		array<System::String^>^ greetings;
		array<System::String^>^ drinks;
		array<System::Drawing::Image^>^ clientImages;
		array<System::String^>^ desserts;
		array<System::String^>^ goodReviews;
		array<System::String^>^ midReviews;
		array<System::String^>^ badReviews;
		int lastClientIndex = -1;

		System::Windows::Forms::Label^ lblStoreState;
		System::Windows::Forms::Button^ btnBuyCoffee;
		System::Windows::Forms::Button^ btnBuyMilk;
		System::Windows::Forms::Button^ btnBuySyrup;
		System::Windows::Forms::Button^ btnBuyCookie;
		System::Windows::Forms::Button^ btnBuyFilling;
		System::Windows::Forms::Button^ btnBuyCream;
		System::Windows::Forms::Button^ btnBuyDough;
		System::Windows::Forms::Button^ btnCloseShop;
		System::Windows::Forms::Button^ SettingsButton;

		System::Windows::Forms::PrintDialog^ printDialog1;



	public:
		GameForm(void)
		{
			InitializeComponent();
			clientImages = gcnew array<System::Drawing::Image^>(10);

			try {
				System::String^ exePath = System::IO::Path::GetDirectoryName(System::Windows::Forms::Application::ExecutablePath);

				clientImages[0] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client1.png"));
				clientImages[1] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client2.png"));
				clientImages[2] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client3.png"));
				clientImages[3] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client4.png"));
				clientImages[4] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client5.png"));
				clientImages[5] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client6.png"));
				clientImages[6] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client7.png"));
				clientImages[7] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client8.png"));
				clientImages[8] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client9.png"));
				clientImages[9] = System::Drawing::Image::FromFile(System::IO::Path::Combine(exePath, "client10.png"));
			}
			catch (System::Exception^ ex) {
				MessageBox::Show(L"Не удалось загрузить картинки клиентов!\nОшибка: " + ex->Message,
					L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			greetings = gcnew array<System::String^>{
				L"Здравствуйте мне пожалуйста", L"Добрый день можно мне пожалуйста",
				L"Привет, я хочу попробовать", L"Будьте добры"
			};
			drinks = gcnew array<System::String^>{ L"Американо", L"Капучино", L"Раф" };
			desserts = gcnew array<System::String^>{ L"Чизкейк", L"Кекс", L"Макарон" };

			goodReviews = gcnew array<System::String^>{
				L"«Спасибо, это очень вкусно!»", L"«Это великолепно!»", L"«Просто изумительно:)»"
			};
			midReviews = gcnew array<System::String^>{
				L"«Спасибо, но это не совсем то, что я хотела»", L"«Могло быть и лучше»", L"«Мм спасибо»"
			};
			badReviews = gcnew array<System::String^>{
				L"«Это просто ужасно!»", L"«Я отказываюсь это есть!»", L"«До свидания, это ужасная кофейня.»"
			};

			InitShopControls();

			

			gbShop->Visible = false;
			btnGiveOrder->Visible = false;
			btnAcceptOrder->Visible = false;

			UpdateInterface();

			pbClient->Visible = false;
			lblOrderBubble->Text = L"Кофейня открывается...";
			lblTimer->Text = L"Время: --";

			spawnTimer->Start();
		}

	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbClient;
	private: System::Windows::Forms::Label^ lblOrderBubble;
	private: System::Windows::Forms::Label^ lblBudget;
	private: System::Windows::Forms::Label^ lblTimer;
	private: System::Windows::Forms::Button^ btnAcceptOrder;
	private: System::Windows::Forms::Button^ btnGiveOrder;
	private: System::Windows::Forms::Button^ btnShop;
	private: System::Windows::Forms::Timer^ mainTimer;
	private: System::Windows::Forms::Timer^ spawnTimer;
	private: System::Windows::Forms::GroupBox^ gbShop;
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			   this->pbClient = (gcnew System::Windows::Forms::PictureBox());
			   this->lblOrderBubble = (gcnew System::Windows::Forms::Label());
			   this->lblBudget = (gcnew System::Windows::Forms::Label());
			   this->lblTimer = (gcnew System::Windows::Forms::Label());
			   this->btnAcceptOrder = (gcnew System::Windows::Forms::Button());
			   this->btnGiveOrder = (gcnew System::Windows::Forms::Button());
			   this->btnShop = (gcnew System::Windows::Forms::Button());
			   this->mainTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->spawnTimer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->gbShop = (gcnew System::Windows::Forms::GroupBox());
			   this->SettingsButton = (gcnew System::Windows::Forms::Button());
			   this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbClient))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pbClient
			   // 
			   this->pbClient->BackColor = System::Drawing::Color::Transparent;
			   this->pbClient->Location = System::Drawing::Point(444, 141);
			   this->pbClient->Name = L"pbClient";
			   this->pbClient->Size = System::Drawing::Size(599, 442);
			   this->pbClient->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pbClient->TabIndex = 0;
			   this->pbClient->TabStop = false;
			   // 
			   // lblOrderBubble
			   // 
			   this->lblOrderBubble->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->lblOrderBubble->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->lblOrderBubble->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lblOrderBubble->Location = System::Drawing::Point(872, 105);
			   this->lblOrderBubble->Name = L"lblOrderBubble";
			   this->lblOrderBubble->Size = System::Drawing::Size(350, 110);
			   this->lblOrderBubble->TabIndex = 1;
			   // 
			   // lblBudget
			   // 
			   this->lblBudget->BackColor = System::Drawing::Color::MistyRose;
			   this->lblBudget->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->lblBudget->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lblBudget->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->lblBudget->Location = System::Drawing::Point(431, 14);
			   this->lblBudget->Name = L"lblBudget";
			   this->lblBudget->Size = System::Drawing::Size(200, 25);
			   this->lblBudget->TabIndex = 2;
			   this->lblBudget->Text = L"Бюджет: $100";
			   // 
			   // lblTimer
			   // 
			   this->lblTimer->BackColor = System::Drawing::Color::MistyRose;
			   this->lblTimer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->lblTimer->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->lblTimer->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->lblTimer->Location = System::Drawing::Point(650, 14);
			   this->lblTimer->Name = L"lblTimer";
			   this->lblTimer->Size = System::Drawing::Size(200, 25);
			   this->lblTimer->TabIndex = 3;
			   this->lblTimer->Text = L"Время: --";
			   // 
			   // btnAcceptOrder
			   // 
			   this->btnAcceptOrder->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			   this->btnAcceptOrder->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAcceptOrder->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->btnAcceptOrder->Location = System::Drawing::Point(1265, 656);
			   this->btnAcceptOrder->Name = L"btnAcceptOrder";
			   this->btnAcceptOrder->Size = System::Drawing::Size(177, 41);
			   this->btnAcceptOrder->TabIndex = 4;
			   this->btnAcceptOrder->Text = L"Оформить заказ";
			   this->btnAcceptOrder->UseVisualStyleBackColor = false;
			   this->btnAcceptOrder->Click += gcnew System::EventHandler(this, &GameForm::btnAcceptOrder_Click);
			   // 
			   // btnGiveOrder
			   // 
			   this->btnGiveOrder->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			   this->btnGiveOrder->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnGiveOrder->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnGiveOrder->Location = System::Drawing::Point(1059, 656);
			   this->btnGiveOrder->Name = L"btnGiveOrder";
			   this->btnGiveOrder->Size = System::Drawing::Size(177, 41);
			   this->btnGiveOrder->TabIndex = 5;
			   this->btnGiveOrder->Text = L"Отдать заказ";
			   this->btnGiveOrder->UseVisualStyleBackColor = false;
			   this->btnGiveOrder->Click += gcnew System::EventHandler(this, &GameForm::btnGiveOrder_Click);
			   // 
			   // btnShop
			   // 
			   this->btnShop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->btnShop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnShop->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->btnShop->Location = System::Drawing::Point(32, 33);
			   this->btnShop->Name = L"btnShop";
			   this->btnShop->Size = System::Drawing::Size(167, 41);
			   this->btnShop->TabIndex = 6;
			   this->btnShop->Text = L"Продукты";
			   this->btnShop->UseVisualStyleBackColor = false;
			   this->btnShop->Click += gcnew System::EventHandler(this, &GameForm::btnShop_Click);
			   // 
			   // mainTimer
			   // 
			   this->mainTimer->Interval = 1000;
			   this->mainTimer->Tick += gcnew System::EventHandler(this, &GameForm::mainTimer_Tick);
			   // 
			   // spawnTimer
			   // 
			   this->spawnTimer->Interval = 5000;
			   this->spawnTimer->Tick += gcnew System::EventHandler(this, &GameForm::spawnTimer_Tick);
			   // 
			   // gbShop
			   // 
			   this->gbShop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->gbShop->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->gbShop->Location = System::Drawing::Point(32, 80);
			   this->gbShop->Name = L"gbShop";
			   this->gbShop->Size = System::Drawing::Size(320, 450);
			   this->gbShop->TabIndex = 7;
			   this->gbShop->TabStop = false;
			   this->gbShop->Text = L"Склад и Закупки";
			   // 
			   // SettingsButton
			   // 
			   this->SettingsButton->BackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SettingsButton.BackgroundImage")));
			   this->SettingsButton->FlatAppearance->BorderSize = 0;
			   this->SettingsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->SettingsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->SettingsButton->Location = System::Drawing::Point(1362, 15);
			   this->SettingsButton->Name = L"SettingsButton";
			   this->SettingsButton->Size = System::Drawing::Size(65, 65);
			   this->SettingsButton->TabIndex = 8;
			   this->SettingsButton->UseVisualStyleBackColor = false;
			   this->SettingsButton->Click += gcnew System::EventHandler(this, &GameForm::SettingsButton_Click);
			   // 
			   // printDialog1
			   // 
			   this->printDialog1->UseEXDialog = true;
			   // 
			   // GameForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(1454, 722);
			   this->ControlBox = false;
			   this->Controls->Add(this->SettingsButton);
			   this->Controls->Add(this->gbShop);
			   this->Controls->Add(this->btnShop);
			   this->Controls->Add(this->btnGiveOrder);
			   this->Controls->Add(this->btnAcceptOrder);
			   this->Controls->Add(this->lblTimer);
			   this->Controls->Add(this->lblBudget);
			   this->Controls->Add(this->lblOrderBubble);
			   this->Controls->Add(this->pbClient);
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"GameForm";
			   this->ShowIcon = false;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbClient))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private:
		System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e) {
			this->btnAcceptOrder->Visible = false;
		}

		void InitShopControls() {
			lblStoreState = gcnew System::Windows::Forms::Label();
			lblStoreState->Location = System::Drawing::Point(15, 25);
			lblStoreState->Size = System::Drawing::Size(290, 140);
			gbShop->Controls->Add(lblStoreState);

			btnBuyCoffee = gcnew System::Windows::Forms::Button();
			btnBuyCoffee->Text = "Кофе (+$10)"; btnBuyCoffee->Location = System::Drawing::Point(15, 175);
			btnBuyCoffee->Click += gcnew System::EventHandler(this, &GameForm::BuyIngredient_Click);
			gbShop->Controls->Add(btnBuyCoffee);

			btnBuyMilk = gcnew System::Windows::Forms::Button();
			btnBuyMilk->Text = "Молоко (+$8)"; btnBuyMilk->Location = System::Drawing::Point(15, 210);
			btnBuyMilk->Click += gcnew System::EventHandler(this, &GameForm::BuyIngredient_Click);
			gbShop->Controls->Add(btnBuyMilk);

			btnBuySyrup = gcnew System::Windows::Forms::Button();
			btnBuySyrup->Text = "Сироп (+$5)"; btnBuySyrup->Location = System::Drawing::Point(15, 245);
			btnBuySyrup->Click += gcnew System::EventHandler(this, &GameForm::BuyIngredient_Click);
			gbShop->Controls->Add(btnBuySyrup);

			btnBuyCookie = gcnew System::Windows::Forms::Button();
			btnBuyCookie->Text = "Печенье (+$6)"; btnBuyCookie->Location = System::Drawing::Point(160, 175);
			btnBuyCookie->Click += gcnew System::EventHandler(this, &GameForm::BuyIngredient_Click);
			gbShop->Controls->Add(btnBuyCookie);

			btnBuyFilling = gcnew System::Windows::Forms::Button();
			btnBuyFilling->Text = "Начинка (+$7)"; btnBuyFilling->Location = System::Drawing::Point(160, 210);
			btnBuyFilling->Click += gcnew System::EventHandler(this, &GameForm::BuyIngredient_Click);
			gbShop->Controls->Add(btnBuyFilling);

			btnBuyCream = gcnew System::Windows::Forms::Button();
			btnBuyCream->Text = "Крем (+$6)"; btnBuyCream->Location = System::Drawing::Point(160, 245);
			btnBuyCream->Click += gcnew System::EventHandler(this, &GameForm::BuyIngredient_Click);
			gbShop->Controls->Add(btnBuyCream);

			btnBuyDough = gcnew System::Windows::Forms::Button();
			btnBuyDough->Text = "Тесто (+$5)"; btnBuyDough->Location = System::Drawing::Point(15, 280);
			btnBuyDough->Click += gcnew System::EventHandler(this, &GameForm::BuyIngredient_Click);
			gbShop->Controls->Add(btnBuyDough);

			btnCloseShop = gcnew System::Windows::Forms::Button();
			btnCloseShop->Text = "Закрыть склад"; btnCloseShop->Location = System::Drawing::Point(90, 350); btnCloseShop->Size = System::Drawing::Size(130, 35);
			btnCloseShop->Click += gcnew System::EventHandler(this, &GameForm::btnCloseShop_Click);
			gbShop->Controls->Add(btnCloseShop);
		}

		void SpawnNewClient() {
			if (clientImages != nullptr && clientImages->Length > 1 && clientImages[0] != nullptr) {
				int randomClientIndex;
				do {
					randomClientIndex = GlobalData::Rand->Next(clientImages->Length);
				} while (randomClientIndex == lastClientIndex);

				lastClientIndex = randomClientIndex;
				pbClient->Image = clientImages[randomClientIndex];
			}
			else if (clientImages != nullptr && clientImages->Length == 1 && clientImages[0] != nullptr) {
				pbClient->Image = clientImages[0];
			}

			// Сбрасываем старый выбор игрока перед началом сборки нового заказа
			GlobalData::PlayerDrink = "";
			GlobalData::PlayerDessert = "";

			GlobalData::CurrentGreeting = greetings[GlobalData::Rand->Next(greetings->Length)];

			int orderType = GlobalData::Rand->Next(3);
			if (orderType == 0) {
				GlobalData::CurrentDrink = drinks[GlobalData::Rand->Next(drinks->Length)];
				GlobalData::CurrentDessert = "";
				GlobalData::NeedsDrink = true;
				GlobalData::NeedsDessert = false;
			}
			else if (orderType == 1) {
				GlobalData::CurrentDrink = "";
				GlobalData::CurrentDessert = desserts[GlobalData::Rand->Next(desserts->Length)];
				GlobalData::NeedsDrink = false;
				GlobalData::NeedsDessert = true;
			}
			else {
				GlobalData::CurrentDrink = drinks[GlobalData::Rand->Next(drinks->Length)];
				GlobalData::CurrentDessert = desserts[GlobalData::Rand->Next(desserts->Length)];
				GlobalData::NeedsDrink = true;
				GlobalData::NeedsDessert = true;
			}

			System::String^ textResult = GlobalData::CurrentGreeting + " ";

			if (GlobalData::NeedsDrink && GlobalData::NeedsDessert) {
				textResult += GlobalData::CurrentDrink + " и " + GlobalData::CurrentDessert;
			}
			else if (GlobalData::NeedsDrink) {
				textResult += GlobalData::CurrentDrink;
			}
			else if (GlobalData::NeedsDessert) {
				textResult += GlobalData::CurrentDessert;
			}

			textResult += ".";

			lblOrderBubble->Text = textResult;

			// Даем клиенту 30 секунд на ожидание и запускаем таймер на главной форме
			GlobalData::OrderTimeLeft =40;
			lblTimer->Text = "Осталось: " + GlobalData::OrderTimeLeft + " сек.";
			mainTimer->Start();

			btnGiveOrder->Visible = false;
			pbClient->Visible = true;
			btnAcceptOrder->Visible = true;
		}

		void UpdateInterface() {
			lblBudget->Text = "Бюджет: $" + GlobalData::Budget;
			lblStoreState->Text = "Остатки на складе:\n" +
				"Кофе: " + GlobalData::CoffeeCount + " шт.\n" +
				"Молоко: " + GlobalData::MilkCount + " шт.\n" +
				"Сироп: " + GlobalData::SyrupCount + " шт.\n" +
				"Печенье: " + GlobalData::CookieCount + " шт.\n" +
				"Начинка: " + GlobalData::FillingCount + " шт.\n" +
				"Крем: " + GlobalData::CreamCount + " шт.\n" +
				"Тесто: " + GlobalData::DoughCount + " шт.";
		}

		System::Void mainTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (GlobalData::OrderTimeLeft > 0) {
				GlobalData::OrderTimeLeft--;
				lblTimer->Text = "Осталось: " + GlobalData::OrderTimeLeft + " сек.";
			}
			else {
				mainTimer->Stop();
				GlobalData::OrderTimeLeft = 0;
				btnAcceptOrder->Visible = false;

				MessageBox::Show("Время ожидания вышло! Клиент ушел недовольным.", "Провал", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				GlobalData::Budget -= 10;
				ClearClientArea();
			}
		}
		System::Void btnAcceptOrder_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btnAcceptOrder->Enabled = false;
			mainTimer->Stop(); // Останавливаем основной поток времени

			System::Windows::Forms::DialogResult res = System::Windows::Forms::DialogResult::None;

			if (CoffeeGame::GlobalData::NeedsDrink) {
				CoffeeGame::DrinkForm^ drinkScreen = gcnew CoffeeGame::DrinkForm();
				res = drinkScreen->ShowDialog();
			}
			else if (CoffeeGame::GlobalData::NeedsDessert) {
				CoffeeGame::DessertForm^ dessertScreen = gcnew CoffeeGame::DessertForm();
				res = dessertScreen->ShowDialog();
			}

			// ПРОВЕРКА: Если пока мы были на кухне, время закончилось
			if (GlobalData::OrderTimeLeft <= 0) {
				GlobalData::OrderTimeLeft = 0;
				btnAcceptOrder->Visible = false;
				MessageBox::Show("Время ожидания вышло! Клиент ушел недовольным.", "Провал", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				GlobalData::Budget -= 10;
				ClearClientArea();
				this->btnAcceptOrder->Enabled = true;
				return;
			}

			if (res == System::Windows::Forms::DialogResult::OK) {
				CheckOrderResults();
			}
			else {
				// Если игрок просто вернулся (например, из настроек или закрыл окно десертов назад к напиткам)
				lblTimer->Text = "Осталось: " + GlobalData::OrderTimeLeft + " сек.";
				mainTimer->Start(); // Продолжаем отсчет
			}

			this->btnAcceptOrder->Enabled = true;
		}
		void CheckOrderResults() {
			bool drinkCorrect = (!GlobalData::NeedsDrink && System::String::IsNullOrEmpty(GlobalData::PlayerDrink)) ||
				(GlobalData::NeedsDrink && GlobalData::PlayerDrink == GlobalData::CurrentDrink);

			bool dessertCorrect = (!GlobalData::NeedsDessert && System::String::IsNullOrEmpty(GlobalData::PlayerDessert)) ||
				(GlobalData::NeedsDessert && GlobalData::PlayerDessert == GlobalData::CurrentDessert);

			// Начисляем деньги или штрафуем
			if (drinkCorrect && dessertCorrect) {
				int reward = 25;
				if (GlobalData::NeedsDrink && GlobalData::NeedsDessert) reward = 45; // за двойной заказ больше
				GlobalData::Budget += reward;
				MessageBox::Show(goodReviews[GlobalData::Rand->Next(goodReviews->Length)] + "\nВы заработали: $" + reward, "Успех!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else if (drinkCorrect || dessertCorrect) {
				GlobalData::Budget += 10;
				MessageBox::Show(midReviews[GlobalData::Rand->Next(midReviews->Length)] + "\nВы получили только часть оплаты: $10", "Частичный успех", MessageBoxButtons::OK, MessageBoxIcon::Question);
			}
			else {
				GlobalData::Budget -= 15;
				MessageBox::Show(badReviews[GlobalData::Rand->Next(badReviews->Length)] + "\nВы получили штраф: -$15", "Провал", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			// Провожаем клиента и готовимся к новому
			ClearClientArea();
		}

		System::Void btnGiveOrder_Click(System::Object^ sender, System::EventArgs^ e) {
			CheckOrderResults();
		}
		void ClearClientArea() {
			// Останавливаем таймер текущего клиента насовсем
			mainTimer->Stop();

			pbClient->Visible = false;

			
			// Сбрасываем глобальные данные сделанного игроком выбора
			GlobalData::PlayerDrink = "";
			GlobalData::PlayerDessert = "";
			

			lblOrderBubble->Text = "Ожидание нового клиента...";
			lblTimer->Text = "Время: --";

			btnGiveOrder->Visible = false;
			btnAcceptOrder->Visible = false;

			UpdateInterface();
			spawnTimer->Start(); // Ждем 5 секунд до следующего клиента
		}

		System::Void spawnTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
			spawnTimer->Stop();
			SpawnNewClient();
		}

		System::Void btnShop_Click(System::Object^ sender, System::EventArgs^ e) { gbShop->Visible = true; UpdateInterface(); }
		System::Void btnCloseShop_Click(System::Object^ sender, System::EventArgs^ e) { gbShop->Visible = false; }

		System::Void BuyIngredient_Click(System::Object^ sender, System::EventArgs^ e) {
			Button^ clicked = (Button^)sender;

			if (clicked == btnBuyCoffee && GlobalData::Budget >= GlobalData::PriceCoffee) {
				GlobalData::Budget -= GlobalData::PriceCoffee; GlobalData::CoffeeCount++;
			}
			else if (clicked == btnBuyMilk && GlobalData::Budget >= GlobalData::PriceMilk) {
				GlobalData::Budget -= GlobalData::PriceMilk; GlobalData::MilkCount++;
			}
			else if (clicked == btnBuySyrup && GlobalData::Budget >= GlobalData::PriceSyrup) {
				GlobalData::Budget -= GlobalData::PriceSyrup; GlobalData::SyrupCount++;
			}
			else if (clicked == btnBuyCookie && GlobalData::Budget >= GlobalData::PriceCookie) {
				GlobalData::Budget -= GlobalData::PriceCookie; GlobalData::CookieCount++;
			}
			else if (clicked == btnBuyFilling && GlobalData::Budget >= GlobalData::PriceFilling) {
				GlobalData::Budget -= GlobalData::PriceFilling; GlobalData::FillingCount++;
			}
			else if (clicked == btnBuyCream && GlobalData::Budget >= GlobalData::PriceCream) {
				GlobalData::Budget -= GlobalData::PriceCream; GlobalData::CreamCount++;
			}
			else if (clicked == btnBuyDough && GlobalData::Budget >= GlobalData::PriceDough) {
				GlobalData::Budget -= GlobalData::PriceDough; GlobalData::DoughCount++;
			}
			else {
				MessageBox::Show("Недостаточно средств для покупки!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			UpdateInterface();
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