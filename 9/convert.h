
#include <conio.h>
#include <vector>
#include <exception>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>
using namespace std;

enum Scale
{
    Celsius,
    Kelvin,
    Far,
  //  realize,
};
struct Temperature
{
  Temperature(double value, char scale);
   Temperature();
  double value;
  char scale;
};

Temperature convert(Temperature tepm, char to);

