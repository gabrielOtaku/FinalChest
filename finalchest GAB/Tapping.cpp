#include <windows.h>
#include <iostream>
using namespace std;

void Tapping(const char data[], int speed) {
	int x = 0;
	while (data[x] != 0) {
		Sleep(speed);
		cout << data[x];
		x += 1;
	}
}