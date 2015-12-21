#include <conio.h>
#include <vector>
#include <exception>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>
using namespace std;

#include "convert.h"

int main()
{
    Temperature input;
    vector<Temperature> temp, tempC; //temp хранение значений температуры
                                     //tempC хранение в одной шкале
     cout << "Enter temperature with its scale: ";
    while (cin)
    {
        cin >>input.value;
        cin >>input.scale;
        try
        {
            temp.push_back(convert(input,Celsius));
            temp.push_back(convert(input,Kelvin));
            temp.push_back(convert(input,Far));
            tempC.push_back(convert(input,Celsius));
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
            cerr <<"Unknown error!\n";
        }
        cout << "Enter temperature with its scale: ";
    }
    //вывод на экран
    cout<<endl;
    cout <<"   C\t   K\t   F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
       printf("%6.2f\t",temp[i]);
        if ((i+1)%3==0) cout <<endl;
    }
    cout <<endl;
    cout <<"Max temperature=" <<MaxTemp(tempC)<<endl;
    cout <<"Min temperature=" <<MinTemp(tempC)<<endl;
    cout <<"Mean temperature=" <<MeanTemp(tempC)<<endl;
}


