// Лабораторна робота №5. Перевірка коду
#include <windows.h>

using namespace System;

// Функція варіанта 25: f(x) = (x + 2*w)^3 / ln(x + 0.75) при w = 1.0
double CalculateFunction(double x)
{
    double w = 1.0;
    double numerator = Math::Pow(x + 2.0 * w, 3.0);
    double denominator = Math::Log(x + 0.75);
    return numerator / denominator;
}

int main(array<System::String^>^ args)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Console::OutputEncoding = System::Text::Encoding::UTF8;
    Console::InputEncoding = System::Text::Encoding::UTF8;

    
   
    Console::WriteLine(" ЛАБОРАТОРНА РОБОТА № 5. МАСИВИ CLR (ВАРІАНТ 25)   \n");

    // ------------------------------------------------------------
    // ЗАВДАННЯ 1: Одновимірний масив
    // ------------------------------------------------------------
    Console::WriteLine("--- ЗАВДАННЯ 1: Значення функції для 10 непарних чисел (починаючи з 5) ---");

    const int N_ITEMS = 10;
    array<int>^ oddNumbers = gcnew array<int>(N_ITEMS);
    array<double>^ funcValues = gcnew array<double>(N_ITEMS);

    for (int i = 0; i < oddNumbers->Length; i++)
    {
        oddNumbers[i] = 5 + 2 * i; // 5, 7, 9, 11, 13, 15, 17, 19, 21, 23
        funcValues[i] = CalculateFunction(oddNumbers[i]);
    }

    Console::WriteLine("-------------------------------------------------");
    Console::WriteLine("|  №  | Непарне число (x) |   Значення функції f(x)   |");
    Console::WriteLine("-------------------------------------------------");
    for (int i = 0; i < N_ITEMS; i++)
    {
        Console::WriteLine("| {0,2}  |        {1,2}        |       {2,14:F4}      |",
            (i + 1), oddNumbers[i], funcValues[i]);
    }
    Console::WriteLine("-------------------------------------------------\n");

    // ------------------------------------------------------------
    // ЗАВДАННЯ 2: Двовимірний масив (Матриця N x N)
    // ------------------------------------------------------------
    Console::WriteLine("--- ЗАВДАННЯ 2: Симетризація квадратної матриці A (N x N) ---");

    const int N = 4;
    array<double, 2>^ matrixA = gcnew array<double, 2>(N, N);
    array<double, 2>^ matrixB = gcnew array<double, 2>(N, N);

    double initialValues[N][N] = {
        { 1.2,  3.5, -2.1,  4.0 },
        { 8.7,  5.3,  0.9, -1.4 },
        { 6.4, -4.2,  7.1,  3.8 },
        { 2.9,  1.1, -5.6,  9.0 }
    };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrixA[i, j] = initialValues[i][j];
        }
    }

    // Симетризація: b_ij = a_ij при j >= i; b_ij = a_ji при j < i
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j >= i)
            {
                matrixB[i, j] = matrixA[i, j];
            }
            else
            {
                matrixB[i, j] = matrixA[j, i];
            }
        }
    }

    Console::WriteLine("Початкова дійсна матриця A ({0}x{0}):", N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Console::Write("{0,7:F1} ", matrixA[i, j]);
        }
        Console::WriteLine();
    }
    Console::WriteLine();

    Console::WriteLine("Отримана матриця B ({0}x{0}) за умовою варіанта 25:", N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Console::Write("{0,7:F1} ", matrixB[i, j]);
        }
        Console::WriteLine();
    }

    Console::WriteLine("\n============================================================");
    Console::WriteLine("Натисніть будь-яку клавішу для завершення роботи...");
    Console::ReadKey();
    return 0;
}
