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
    Temperature input;
    vector<Temperature> temp;
    while (cin)
    {
        cout << "Enter temperature with its scale: ";
        cin >>input.value;
        cin >>input.scale;
       try {
        temp.push_back(convert(input,Celsius));
        temp.push_back(convert(input,Kelvin));
        temp.push_back(convert(input,Far));
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
