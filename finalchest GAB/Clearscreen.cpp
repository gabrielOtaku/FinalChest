#include <windows.h>
#include <iostream>
using namespace std;

void ClearScreen() {
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(StdOut, &csbi);

    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    cout << csbi.dwSize.X << " " << csbi.dwSize.Y;

    DWORD count = 0;
    COORD homeCoords = { 0, 0 };
    FillConsoleOutputCharacter(StdOut, ' ', cellCount, homeCoords, &count);

    FillConsoleOutputAttribute(StdOut, csbi.wAttributes, cellCount, homeCoords, &count);

    SetConsoleCursorPosition(StdOut, homeCoords);
}