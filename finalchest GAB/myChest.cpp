#include <iostream>
#include "myConstant.h"
#include "myFunction.h"

using namespace std;

//Master boot

int main()
{
	srand(unsigned(time(NULL)));
	myGame();
	intro();
}
