#include <windows.h>
#include <iostream>

using namespace System;

int main(array<System::String^>^ args)
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Console::OutputEncoding = System::Text::Encoding::UTF8;
    Console::InputEncoding = System::Text::Encoding::UTF8;

    while (true)
    {
        Console::WriteLine(L"   ЛАБОРАТОРНА РОБОТА №1 (ВАРІАНТ 25) - МЕНЮ   ");
        Console::WriteLine(L"1 - Завдання 1: Килимове покриття");
        Console::WriteLine(L"2 - Завдання 2: Об'єднання двох рядків");
        Console::WriteLine(L"3 - Завдання 3: Порівняння двох рядків (Compare)");
        Console::WriteLine(L"4 - Завдання 4: Додавання 'begin' та 'end', довжина");
        Console::WriteLine(L"5 - Завдання 5: Реверс рядка (у зворотному порядку)");
        Console::WriteLine(L"6 - Завдання 6: Порівняння рядків за довжиною");
        Console::WriteLine(L"0 - Вихід із програми");
        Console::Write(L"\nОберіть номер завдання (0-6): ");

        String^ choiceStr = Console::ReadLine();
        if (String::IsNullOrWhiteSpace(choiceStr)) continue;

        int choice = 0;
        try {
            choice = Int32::Parse(choiceStr);
        }
        catch (Exception^) {
            Console::WriteLine(L"Помилка: введіть коректне число від 0 до 6!");
            continue;
        }

        if (choice == 0)
        {
            Console::WriteLine(L"Завершення роботи програми...");
            break;
        }

        Console::WriteLine(L"\n----------------------------------------------");

        switch (choice)
        {
        case 1:
        {
            Console::WriteLine(L"--- ЗАВДАННЯ 1: Килимове покриття ---");
            Console::WriteLine(L"(За варіантом 25 за замовчуванням: L = 35, W = 30, C = 25)");

            try {
                Console::Write(L"Введіть довжину кімнати L (м): ");
                double L = Double::Parse(Console::ReadLine());

                Console::Write(L"Введіть ширину кімнати W (м): ");
                double W = Double::Parse(Console::ReadLine());

                Console::Write(L"Введіть ціну за 1 кв.м (грн): ");
                double C = Double::Parse(Console::ReadLine());

                if (L <= 0 || W <= 0 || C <= 0) {
                    Console::WriteLine(L"Помилка: параметри мають бути більшими за нуль!");
                }
                else {
                    double area = L * W;
                    double price = area * C;
                    Console::WriteLine(L"\nРезультат:");
                    Console::WriteLine(L"Розмір кімнати: {0:F2} метрів на {1:F2} метрів", L, W);
                    Console::WriteLine(L"Площа кімнати: {0:F2} квадратних метрів", area);
                    Console::WriteLine(L"Ціна килимового покриття: {0:F2} грн", price);
                }
            }
            catch (Exception^) {
                Console::WriteLine(L"Помилка введення числових значень!");
            }
            break;
        }

        case 2:
        {
            Console::WriteLine(L"--- ЗАВДАННЯ 2: Об'єднання двох рядків ---");
            Console::Write(L"Введіть перший рядок: ");
            String^ str1 = Console::ReadLine();

            Console::Write(L"Введіть другий рядок: ");
            String^ str2 = Console::ReadLine();

            String^ merged = str1 + L" " + str2;
            Console::WriteLine(L"\nРезультат об'єднання:");
            Console::WriteLine(L"\"{0}\"", merged);
            break;
        }

        case 3:
        {
            Console::WriteLine(L"--- ЗАВДАННЯ 3: Порівняння двох рядків (Compare) ---");
            Console::Write(L"Введіть перший рядок: ");
            String^ s1 = Console::ReadLine();

            Console::Write(L"Введіть другий рядок: ");
            String^ s2 = Console::ReadLine();

            int cmp = String::Compare(s1, s2);
            Console::WriteLine(L"\nРезультат порівняння:");
            if (cmp > 0)
                Console::WriteLine(L"Рядок 1 більший за Рядок 2 (лексикографічно).");
            else if (cmp < 0)
                Console::WriteLine(L"Рядок 1 менший за Рядок 2 (лексикографічно).");
            else
                Console::WriteLine(L"Рядки повністю однакові.");
            break;
        }

        case 4:
        {
            Console::WriteLine(L"--- ЗАВДАННЯ 4: Додавання 'begin' та 'end' ---");
            Console::Write(L"Введіть вихідний рядок: ");
            String^ text = Console::ReadLine();

            String^ modText = L"begin " + text + L" end";
            Console::WriteLine(L"\nРезультат модифікації: \"{0}\"", modText);
            Console::WriteLine(L"Довжина одержаного рядка: {0} символів", modText->Length);
            break;
        }

        case 5:
        {
            Console::WriteLine(L"--- ЗАВДАННЯ 5: Реверс рядка ---");
            Console::Write(L"Введіть рядок для реверсу: ");
            String^ orig = Console::ReadLine();

            array<wchar_t>^ arr = orig->ToCharArray();
            Array::Reverse(arr);
            String^ rev = gcnew String(arr);

            Console::WriteLine(L"\nРезультат:");
            Console::WriteLine(L"Вихідний рядок: \"{0}\"", orig);
            Console::WriteLine(L"Зворотний рядок: \"{0}\"", rev);
            break;
        }

        case 6:
        {
            Console::WriteLine(L"--- ЗАВДАННЯ 6: Порівняння рядків за довжиною ---");
            Console::Write(L"Введіть перший рядок: ");
            String^ lineA = Console::ReadLine();

            Console::Write(L"Введіть другий рядок: ");
            String^ lineB = Console::ReadLine();

            Console::WriteLine(L"\nДовжина рядка 1: {0}", lineA->Length);
            Console::WriteLine(L"Довжина рядка 2: {0}", lineB->Length);

            if (lineA->Length > lineB->Length)
                Console::WriteLine(L"Результат: Перший рядок довший за другий.");
            else if (lineA->Length < lineB->Length)
                Console::WriteLine(L"Результат: Другий рядок довший за перший.");
            else
                Console::WriteLine(L"Результат: Рядки однакової довжини.");
            break;
        }

        default:
            Console::WriteLine(L"Невірний вибір! Оберіть число від 0 до 6.");
            break;
        }

        Console::WriteLine(L"----------------------------------------------");
        Console::WriteLine(L"Натисніть Enter, щоб повернутися до меню...");
        Console::ReadLine();
    }

    return 0;
}