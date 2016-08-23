#include <complex>

#include "fcontrol.h"

int main()
{

    std::complex<double> a;
    TimeSignal e,c;

    for (int i=0; i<e.getN(); i++)
    {
        e.data[i]=sin(0.1*i*e.getDts());
        std::cout << e.data[i];

    }
    std::cout << std::endl;

    //SystemBlock
    //numerator parameters
    double nume[]={1,0};
    std::vector<double> num(nume[0],nume[1]);

    //denominator parameters
    double deno[]={1,0};
    std::vector<double> den(deno[0],deno[1]);

    //instantiate object
    SystemBlock control(num,den);

    //configure for the input signal
    control.TimeResponse(e,c);




    return 0;
}
