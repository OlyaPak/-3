
#include  "iostream"
#include  "vector"
#include  "stdio.h"
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
    default:
        return 10;
}
        if (tempC<-273.15)
        {
            return 11;
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
        default:
            return 10;
        }
}
int main()
{
    double x;
    int x1;
    char scale;
    vector<double> temp;

    while (cin)
    {
        cout << "Enter temperature with its scale: ";
        cin >>x;
        cin >>scale;
        x1=convert(x,scale,'C');
        switch(x1)
        {
        case (10):
            cout<<"unknown scale! \n";
            break;
        case (11):
            cout<<"Temperature less than abs zero ! \n";
            break ;
        default:
            temp.push_back(convert(x,scale,'C'));
            temp.push_back(convert(x,scale,'K'));
            temp.push_back(convert(x,scale,'F'));
        }
    }

    cout <<"C\t K\t F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
       printf("%6.2f\t",temp[i]);
        if ((i+1)%3==0) cout <<endl;
    }
}
