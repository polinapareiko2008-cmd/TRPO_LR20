#pragma once

namespace CoffeeGame {

    public ref class GlobalData {
    public:
        // Управляемый генератор случайных чисел
        static System::Random^ Rand = gcnew System::Random();

        static int Budget = 100;

        static int CoffeeCount = 5;
        static int MilkCount = 5;
        static int SyrupCount = 5;
        static int CookieCount = 5;
        static int FillingCount = 5;
        static int CreamCount = 5;
        static int DoughCount = 5;

        static const int PriceCoffee = 10;
        static const int PriceMilk = 8;
        static const int PriceSyrup = 5;
        static const int PriceCookie = 6;
        static const int PriceFilling = 7;
        static const int PriceCream = 6;
        static const int PriceDough = 5;

        static System::String^ CurrentGreeting = "";
        static System::String^ CurrentDrink = "";
        static System::String^ CurrentDessert = "";
        static bool NeedsDrink = false;
        static bool NeedsDessert = false;

        static System::String^ PlayerDrink = "";
        static System::String^ PlayerDessert = "";

        static int OrderTimeLeft = 0;
        static System::Media::SoundPlayer^ BackgroundMusic = gcnew System::Media::SoundPlayer();
        static bool IsMusicPlaying = false;

        static void StartMusic() {
            try {
                System::String^ exePath = System::IO::Path::GetDirectoryName(System::Windows::Forms::Application::ExecutablePath);
                BackgroundMusic->SoundLocation = System::IO::Path::Combine(exePath, L"Coffee Machine - Blooming Garden (hitmo.net).wav");
                BackgroundMusic->PlayLooping();
                IsMusicPlaying = true;
            }
            catch (...) {}
        }

        static void ToggleMusic() {
            if (IsMusicPlaying) {
                BackgroundMusic->Stop();
                IsMusicPlaying = false;
            }
            else {
                BackgroundMusic->PlayLooping();
                IsMusicPlaying = true;
            }
        }
    
    };
}