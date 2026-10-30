#pragma once
#include "GameForm.h"
#include "SettingsForm.h"
namespace CoffeeGame {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging; // для работы с графикой

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		// Сюда будем сохранять оригинальные картинки кнопок, чтобы возвращать их обратно
		System::Drawing::Image^ originalStartImg;
		System::Drawing::Image^ originalAuthorImg;
	private: System::Windows::Forms::Button^ btnExit;
	public: System::Windows::Forms::HelpProvider^ helpProvider1;
	private: System::Windows::Forms::Button^ button1;
	public:
	private:



		System::Drawing::Image^ originalAboutImg;

	public:
		MainForm(void)
		{
			InitializeComponent();

			// Сохраняем оригинальные изображения, загруженные дизайнером из ресурсов
			originalStartImg = btnStart->BackgroundImage;
			originalAuthorImg = btnExit->BackgroundImage;
			originalAboutImg = btnAbout->BackgroundImage;

			// Динамически привязываем события мыши, чтобы всё работало прямо на форме
			this->btnStart->MouseEnter += gcnew System::EventHandler(this, &MainForm::Button_MouseEnter);
			this->btnStart->MouseLeave += gcnew System::EventHandler(this, &MainForm::Button_MouseLeave);

			this->btnExit->MouseEnter += gcnew System::EventHandler(this, &MainForm::Button_MouseEnter);
			this->btnExit->MouseLeave += gcnew System::EventHandler(this, &MainForm::Button_MouseLeave);

			this->btnAbout->MouseEnter += gcnew System::EventHandler(this, &MainForm::Button_MouseEnter);
			this->btnAbout->MouseLeave += gcnew System::EventHandler(this, &MainForm::Button_MouseLeave);

			GlobalData::StartMusic();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnStart;


	private: System::Windows::Forms::Button^ btnAbout;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			   this->btnStart = (gcnew System::Windows::Forms::Button());
			   this->btnAbout = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->btnExit = (gcnew System::Windows::Forms::Button());
			   this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // btnStart
			   // 
			   this->btnStart->BackColor = System::Drawing::Color::Transparent;
			   this->btnStart->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnStart.BackgroundImage")));
			   this->btnStart->FlatAppearance->BorderSize = 0;
			   this->btnStart->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnStart->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnStart->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, System::Drawing::FontStyle::Bold));
			   this->btnStart->Location = System::Drawing::Point(585, 295);
			   this->btnStart->Name = L"btnStart";
			   this->btnStart->Size = System::Drawing::Size(278, 57);
			   this->btnStart->TabIndex = 0;
			   this->btnStart->UseVisualStyleBackColor = false;
			   this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
			   // 
			   // btnAbout
			   // 
			   this->btnAbout->BackColor = System::Drawing::Color::Transparent;
			   this->btnAbout->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAbout.BackgroundImage")));
			   this->btnAbout->FlatAppearance->BorderSize = 0;
			   this->btnAbout->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnAbout->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnAbout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAbout->Location = System::Drawing::Point(596, 358);
			   this->btnAbout->Name = L"btnAbout";
			   this->btnAbout->Size = System::Drawing::Size(267, 57);
			   this->btnAbout->TabIndex = 2;
			   this->btnAbout->UseVisualStyleBackColor = false;
			   this->btnAbout->Click += gcnew System::EventHandler(this, &MainForm::btnAbout_Click);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Font = (gcnew System::Drawing::Font(L"ScriptC", 72, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::PaleVioletRed;
			   this->label1->Location = System::Drawing::Point(458, 62);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(592, 192);
			   this->label1->TabIndex = 3;
			   this->label1->Text = L"Кофейня";
			   // 
			   // btnExit
			   // 
			   this->btnExit->BackColor = System::Drawing::Color::Transparent;
			   this->btnExit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnExit.BackgroundImage")));
			   this->btnExit->FlatAppearance->BorderSize = 0;
			   this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			   this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			   this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnExit->Location = System::Drawing::Point(596, 421);
			   this->btnExit->Name = L"btnExit";
			   this->btnExit->Size = System::Drawing::Size(267, 55);
			   this->btnExit->TabIndex = 4;
			   this->btnExit->UseVisualStyleBackColor = false;
			   this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			   // 
			   // helpProvider1
			   // 
			   this->helpProvider1->HelpNamespace = L"C:\\Users\\user\\Desktop\\КУРСОВАЯ С++\\проект\\проект\\CoffeeGame\\x64\\Debug\\spravka.chm"
				   L"";
			   // 
			   // button1
			   // 
			   this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				   static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			   this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->button1->Location = System::Drawing::Point(28, 35);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(167, 41);
			   this->button1->TabIndex = 7;
			   this->button1->Text = L"СПРАВКА";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			   // 
			   // MainForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(1386, 702);
			   this->ControlBox = false;
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->btnExit);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->btnAbout);
			   this->Controls->Add(this->btnStart);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			   this->MaximizeBox = false;
			   this->MinimizeBox = false;
			   this->Name = L"MainForm";
			   this->ShowIcon = false;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private:
		//  метод - рисует полупрозрачную розовую подсветку поверх картинки
		System::Void Button_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			Button^ btn = (Button^)sender;
			Image^ originalImg = nullptr;

			// Определяем, какая именно кнопка вывела событие
			if (btn == btnStart) originalImg = originalStartImg;
			else if (btn == btnExit) originalImg = originalAuthorImg;
			else if (btn == btnAbout) originalImg = originalAboutImg;

			if (originalImg != nullptr) {
				// Создаем копию картинки в оперативной памяти, чтобы рисовать на ней
				Bitmap^ bmp = gcnew Bitmap(originalImg);
				Graphics^ g = Graphics::FromImage(bmp);

				// Настраиваем нежный полупрозрачный розовый цвет
				SolidBrush^ pinkBrush = gcnew SolidBrush(Color::FromArgb(60, 255, 182, 193));

				// Закрашиваем этим фильтром всю область картинки кнопочки
				g->FillRectangle(pinkBrush, 0, 0, bmp->Width, bmp->Height);

				delete g;
				btn->BackgroundImage = bmp; // Устанавливаем подсвеченную версию
			}
		}

		// Когда мышка уходит — просто возвращаем сохраненную чистую картинку
		System::Void Button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			Button^ btn = (Button^)sender;

			if (btn == btnStart) btn->BackgroundImage = originalStartImg;
			else if (btn == btnExit) btn->BackgroundImage = originalAuthorImg;
			else if (btn == btnAbout) btn->BackgroundImage = originalAboutImg;
		}

		// "Начать игру" - переключаемся на игровой зал
		System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
			GameForm^ game = gcnew GameForm();
			this->Hide();
			game->ShowDialog();
			this->Show();
		}

		//  "Выйти из игры"
		System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
		//  "Информация об игре"
		System::Void btnAbout_Click(System::Object^ sender, System::EventArgs^ e) {
			Form^ infoForm = gcnew Form();
			infoForm->Size = System::Drawing::Size(450, 250);
			infoForm->StartPosition = FormStartPosition::CenterParent;
			infoForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Делаем аккуратное окно без растягивания
			infoForm->MaximizeBox = false;
			infoForm->MinimizeBox = false;

			// Установка общего шрифта для формы 
			System::Drawing::Font^ customFont = gcnew System::Drawing::Font(L"Monotype Corsiva", 12,
				static_cast<System::Drawing::FontStyle>(System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic));
			infoForm->Font = customFont;

			try {
				// Загружаем картинку "фон истории.png" из папки с проектом
				infoForm->BackgroundImage = gcnew System::Drawing::Bitmap(L"фон истории.png");
				infoForm->BackgroundImageLayout = ImageLayout::Stretch;
			}
			catch (...) {
				// Если пути в отладчике отличаются, смотрим в базовой директории приложения
				try {
					System::String^ exePath = System::AppDomain::CurrentDomain->BaseDirectory;
					infoForm->BackgroundImage = gcnew System::Drawing::Bitmap(System::IO::Path::Combine(exePath, L"фон истории.png"));
					infoForm->BackgroundImageLayout = ImageLayout::Stretch;
				}
				catch (...) {
					// Резервный цвет, если картинку вообще не нашли в папке
					infoForm->BackColor = System::Drawing::Color::MistyRose;
				}
			}
			Label^ lblText = gcnew Label();
			// Делаем фон текста прозрачным, чтобы было видно картинку за ним
			lblText->BackColor = System::Drawing::Color::Transparent;
			lblText->Text = L"Вы открыли свою собственную кофейню! Ваша задача — принимать заказы, правильно комбинировать ингредиенты для напитков и выпечки, следить за временем и управлять бюджетом, докупая товары на складе.";
			lblText->Dock = DockStyle::Fill;
			lblText->Padding = System::Windows::Forms::Padding(20);
			lblText->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			

			// Назначаем этот же шрифт для текста 
			lblText->Font = customFont;

			infoForm->Controls->Add(lblText);
			infoForm->ShowDialog(); 
		}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Help::ShowHelp(this, "Spravka.chm", HelpNavigator::Topic,
		" Introduction.htm");
}
};
}