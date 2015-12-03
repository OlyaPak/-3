#include "convert.h"
#include <conio.h>
#include <vector>
#include <exception>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>
using namespace std;

Temperature::Temperature(double value, char scale)
{
    this->scale = scale;
    this->value = value;
}


Temperature::Temperature()
{
    this->value = 0;
   this->scale = Kelvin;
}
