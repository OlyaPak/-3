#include <conio.h>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include  "stdio.h"
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
int main()
{
    double x,result;
    char scale;
    vector<double> temp;
    while (cin)
    {
        cout << "Enter temperature with its scale: ";
        cin >>x;
        cin >>scale;
       try {
        temp.push_back(convert(x,scale,'C'));
        temp.push_back(convert(x,scale,'K'));
        temp.push_back(convert(x,scale,'F'));
        }
       catch (const invalid_argument& a)
        {
            cerr <<a.what();
        }
        catch (const logic_error& b)
        {
            cerr <<b.what();
        }
        catch (...)
        {
            cerr <<"Unknown error! \n";
        }
    }
    cout <<"   C\t   K\t   F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
       printf("%6.2f\t",temp[i]);
        if ((i+1)%3==0) cout <<endl;
    }
}
