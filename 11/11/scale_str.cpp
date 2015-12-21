#include <conio.h>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include  "stdio.h"
#include  "convert.h"
using std::cout;
using std::endl;
using std::cin;
using namespace std;

Temperature::Temperature(double value, Scale scale)
{
    this->scale = scale;
    this->value = value;
}


Temperature::Temperature()
{
    this->value = 0;
   this->scale = Kelvin;
}
//оператор вывода
ostream& operator <<(ostream&output, const Temperature& temp)
{
    output <<temp.value<<temp.scale;
    return output;
}
//оператор ввода
istream& operator>>(istream& input, Temperature& temp)
{
    input>>temp.value >>temp.scale;
    return input;
}
//оператор вывода для стурктуры
ostream& operator<<(ostream& output, const Scale& scale)
{
    switch(scale)
    {
        case Celsius: output<<'C';
        break;
        case Kelvin: output<<'K';
        break;
        case Far: output<<'F';
        break;
    }
    return output;
}
//оператор ввола для структуры
istream& operator>>(istream& input, Scale& scale)
{
    char s;
    input>>s;
    switch(s)
    {
        case 'C': scale=Celsius;
        break;
        case 'K': scale=Kelvin;
        break;
        case 'F': scale=Far;
        break;
        default: input.setstate(ios_base::failbit); // сообщение об ошибке
    }
    return input;
}
