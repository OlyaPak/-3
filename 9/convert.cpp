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

Temperature convert(Temperature temp, char to)
{
    double tempC;
    Temperature result;
    switch (temp.scale)
    {
    case 'C':
        tempC=temp.value;
        break;
    case 'K' :
        tempC=temp.value-273.15;
        break;
    case 'F':
        tempC=5/9.0*(temp.value-32);
        break;
   // case realize :
      //  throw invalid_argument("!\n");
       // break;
    default:
        throw invalid_argument("unknown scale!\n");

    }
    if (tempC<-273.15)
    {
        throw logic_error ( "Temperature less than abs zero! \n") ;
    }
    switch (to)
    {
    case Celsius:
        result.scale='C';
        result.value=tempC;
        break;
    case Kelvin:
        result.value='K';
        result.value=tempC+273.15;
        break;
    case Far:
        result.scale='F';
        result.value=1.8*tempC+32;
        break;
    default:
        throw invalid_argument("unknown scale!\n");
    }
    return result;
}
