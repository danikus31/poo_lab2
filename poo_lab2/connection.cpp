#pragma once

#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include <algorithm>
#include <fstream>
#include "VariadicTable.h"

using namespace std;


static void pressToMenu() {
    cin.ignore();
    cout << "press enter to menu";
    cin.get();
    system("cls");
}