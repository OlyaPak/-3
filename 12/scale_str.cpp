#include "convert.h"
#include <conio.h>
#include <vector>
#include <exception>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>
using namespace std;

Temperature::Temperature()
{
    this->value=451;
    this->scale='F';
}

Temperature::Temperature(double value, char scale)
{
    this->value=value;
    this->scale=scale;
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

//перегрузка операторов
bool operator>(const Temperature& left, const Temperature& right)
{
    return left.value>right.value;
}

Temperature operator+(const Temperature& left, const Temperature& right)
{
    return  {left.value+right.value,
             left.scale};
}

Temperature operator+=(Temperature& left, const Temperature& right)
{
    left.value+=right.value;
    return left;
}

Temperature operator/(Temperature& left, const int division)
{
    return  {left.value/division,
             left.scale};
}


Temperature operator/=(Temperature& left, const int division)
{
    left.value/=division;
    return left;
}

//пункт 13
Temperature MaxTemp(vector<Temperature> temp)
{
    Temperature MaxT;
    MaxT.value=-373;
    MaxT.scale='C';
    for (int i=0; i < temp.size(); i++)
    {
        if (temp[i].value > MaxT.value)
            MaxT=temp[i];
    }
    return MaxT;
}

Temperature MinTemp(vector<Temperature> temp)
{
    Temperature MinT;
    MinT.value=10000;
    MinT.scale='C';
    for (int i=0; i < temp.size(); i++)
    {
        if (temp[i].value < MinT.value)
            MinT=temp[i];
    }
    return MinT;
}

Temperature MeanTemp(vector<Temperature> temp)
{
    Temperature MeanT;
    MeanT.value=0;
    MeanT.scale='C';
    for (int i=0; i < (temp.size()-1); i++)
    {
        MeanT+=temp[i];
    }
        MeanT/=(temp.size()-1);
        return MeanT;
}
