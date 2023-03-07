// Lab1-MTSD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include "QuadraticEquation.h"

int main(int argc, char* argv[])
{
    if(argc == 2)
    { 
        FILE* stream = nullptr;
        fopen_s(&stream, argv[1], "r");
        if (stream == NULL) {
            std::cout << "file " << argv[1] << " does not exist";
            return 0;
        }
        int a = 0, b = 0, c = 0;
        if(fwscanf_s(stream, L"%d %d %d\n", &a, &b, &c) == 0)
            std::cout << "invalid file format";
    }


    int a = 0, b = 0, c = 0;

    std::wcout << L"\x1b[0ma = \x1b[1;32m";
    while (wscanf_s(L"%d", &a) != 1) {
        wchar_t inputbuff[256]{};
        wscanf_s(L"%s", inputbuff, 256);
        std::wcout << L"Error. Expected a valid real number, got " << inputbuff << " instead" << std::endl;
        while ((getchar()) != '\n');

        std::wcout << L"\x1b[0ma = \x1b[1;32m";
        std::wcout << L"\x1b[0m";
    }

    std::wcout << L"\x1b[0mb = \x1b[1;32m";
    while (wscanf_s(L"%d", &b) != 1) {
        wchar_t inputbuff[256]{};
        wscanf_s(L"%s", inputbuff, 256);
        std::wcout << L"Error. Expected a valid real number, got " << inputbuff << " instead" << std::endl;
        while ((getchar()) != '\n');

        std::wcout << L"\x1b[0mb = \x1b[1;32m";
        std::wcout << L"\x1b[0m";
    }

    std::wcout << L"\x1b[0mc = \x1b[1;32m";
    while (wscanf_s(L"%d", &c) != 1) {
        wchar_t inputbuff[256]{};
        wscanf_s(L"%s", inputbuff, 256);
        std::wcout << L"Error. Expected a valid real number, got " << inputbuff << " instead" << std::endl;
        while ((getchar()) != '\n');

        std::wcout << L"\x1b[0mc = \x1b[1;32m";
        std::wcout << L"\x1b[0m";
    }
    std::wcout << L"\x1b[0m";

    wchar_t eqBuff[256]{};
    int rootNumber = 0;
    double x1 = 0, x2 = 0;

    try {
        QuadraticEquation QE(a, b, c);

        QE.GetStrEquation(eqBuff);
        rootNumber = QE.GetRootsNumber();
        QE.GetRoots(&x1, &x2);
    }
    catch (std::exception e) {
        std::wcout << e.what();
        return 0;
    }

    std::wcout << L"Equation is: " << eqBuff << std::endl;
    std::wcout << L"There are " << rootNumber << L" roots" << std::endl;

    if (rootNumber >= 1)
        std::wcout << L"x1 = " << x1 << std::endl;
    if (rootNumber >= 2)
        std::wcout << L"x2 = " << x2 << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
