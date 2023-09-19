#pragma once

// My game features

void intro();
void myGame();
void startGame();
void iniTab(char mat[][COLONNE]);
void iniTab(bool mat2[][COLONNE]);
void display(char mat[][COLONNE], bool mat2[][COLONNE]);
void displayStat(int, int);
void result(int&, int&, int&, int&, bool mat2[][COLONNE], char mat[][COLONNE]);
void endGame();