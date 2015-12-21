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
   Far
 };

struct Temperature
{
  Temperature(double value, char scale);
  Temperature();
  double value;
  char scale;
};

Temperature convert(Temperature tepm, Scale to);


istream& operator>>(istream& input, Temperature& temp);
ostream& operator<<(ostream& output, const Temperature& temp);
istream& operator>>(istream& input, Scale& scale);
ostream& operator<<(ostream& output, const Scale& scale);

//перегрузка операторов
bool operator>(const Temperature left, const Temperature right);
Temperature operator+(const Temperature& left, const Temperature& right);
Temperature operator+=(Temperature& left, const Temperature& right);
Temperature operator/(Temperature& left, const int division);
Temperature operator/=(Temperature& left, const int division);

//пункт 13
Temperature MaxTemp(vector<Temperature> temp);
Temperature MeanTemp(vector<Temperature> temp);
Temperature MinTemp(vector<Temperature> temp);
