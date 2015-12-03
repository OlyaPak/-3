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
        Scale sc=change(scale);
        temp.push_back(convert(x,sc,Celsius));
        temp.push_back(convert(x,sc,Kelvin));
        temp.push_back(convert(x,sc,Far));
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
