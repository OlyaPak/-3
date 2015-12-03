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
Scale change(char scale)
{
    switch (scale)
    {
    case 'C':
        return Celsius;
        break;
    case 'K':
        return Kelvin;
        break;
    case 'F':
        return Far;
        break;
    default:
        throw invalid_argument("unknown scale!\n");
    }
}
double convert(double temp, Scale from, Scale to)
{
    double tempC;
    switch (from)
    {
    case Celsius:
        tempC=temp;
        break;
    case Kelvin :
        tempC=temp-273.15;
        break;
    case Far:
        tempC=5/9.0*(temp-32);
        break;
    default:
        throw invalid_argument("Unknown scale!\n");

    }
    if (tempC<-273.15)
    {
        throw logic_error ( " Temperature less than abs zero! \n") ;
    }
    switch (to)
    {
    case Celsius:
        return tempC;
        break;
    case Kelvin:
        return tempC+273.15;
        break;
    case Far:
        return 1.8*tempC+32;
        break;
    default:
        throw invalid_argument(" unknown scale!\n");
    }
}
