
#include  "iostream"
#include  "vector"
#include  "stdio.h"
using namespace std;

enum errors
{   allright,
    wrongscale,
    abszero,
};
errors last_error = allright;
errors get_last_error()
{
return last_error;
}
double convert(double temp, char from, char to)
{
    double tempC;
    switch (from)
    {
    case 'C':
        tempC=temp;
        last_error=allright;
        break;
    case 'K':
        tempC=temp-273.15;
        last_error=allright;
        break;
    case 'F':
        tempC=5/9.0*(temp-32);
        last_error=allright;
        break;
    default:
       last_error=wrongscale;
    }
    if (tempC<-273.15)
    {
       last_error=abszero;
    }
    switch (to)
    {
    case 'C':
        return tempC;
        last_error=allright;
        break;
    case 'K':
        return tempC+273.15;
        last_error=allright;
        break;
    case 'F':
        return 1.8*tempC+32;
        last_error=allright;
        break;
    default:
        last_error=wrongscale ;
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

        result=convert(x,scale,'K');
        switch (get_last_error())
        {
        case (wrongscale):
            cout<<"unknown scale! \n";
            break;
        case (abszero):
            cout<<"Temperature less than abs zero ! \n";
            break ;
        case (allright):
        temp.push_back(convert(x,scale,'C'));
        temp.push_back(convert(x,scale,'K'));
        temp.push_back(convert(x,scale,'F'));
            break;
            default: break;
        }
    }
    cout <<"C\t K\t F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
        printf("%6.2f\t",temp[i]);
        if ((i+1)%3==0) cout <<endl;
    }
}
