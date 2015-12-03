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
double convert(double temp, char from, char to)
{

    double tempC;
    switch (from)
    {
    case 'C':
        tempC=temp;
        break;
    case 'K':
        tempC=temp-273.15;
        break;
    case 'F':
        tempC=5/9.0*(temp-32);
        break;
   default: throw invalid_argument("Unknown scale!\n");

    }
    if (tempC<-273.15)
    {
      throw logic_error ( " Temperature less than abs zero! \n") ;
    }
    switch (to)
    {
    case 'C':
        return tempC;

        break;
    case 'K':
        return tempC+273.15;

        break;
    case 'F':
        return 1.8*tempC+32;

        break;
     default: throw invalid_argument(" Unknown scale!\n");
                 return 0;
    }
}
