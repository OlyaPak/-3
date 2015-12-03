
#include  "iostream"
#include  "vector"
#include  "stdio.h"
using namespace std;

enum errors
{
    wrongscale,
    abszero,
};
errors convert(double temp, char from, char to,double& result)
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
        return wrongscale;
    }
    if (tempC<-273.15)
    {
        return abszero;
    }
    switch (to)
    {
    case 'C':
        result=tempC;
        break;
    case 'K':
        result=tempC+273.15;
        break;
    case 'F':
        result=1.8*tempC+32;
        break;
    default:
        return wrongscale ;
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
        switch (convert(x,scale,'K',result))
        {
        case (wrongscale):
            cout<<"unknown scale! \n";
            break;
        case (abszero):
            cout<<"Temperature less than abs zero ! \n";
            break ;
        default:
                  convert(x,scale,'C',result);
                  temp.push_back(result);
                  convert(x,scale,'K',result);
                  temp.push_back(result);
                  convert(x,scale,'F',result);
                  temp.push_back(result);
        }
    }
    cout <<"C\t K\t F\t\n";
    for (int i=0; i<temp.size(); i++)
    {
        printf("%6.2f\t",temp[i]);
        if ((i+1)%3==0) cout <<endl;
    }
}
