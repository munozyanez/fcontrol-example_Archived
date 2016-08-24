#include <complex>

#include "fcontrol.h"

int main()
{

    std::complex<double> a;
    TimeSignal e,c;

    for (int i=0; i<e.getN(); i++)
    {
        e.data[i]=sin(0.1*i*e.getDts());
        //std::cout << e.data[i];

    }
    std::cout << std::endl;

    //SystemBlock
    //numerator parameters    
    std::vector<double> num(2,0);
    num[0]=1;
    //denominator parameters
    std::vector<double> den(2,0);
    den[0]=1;

    //instantiate object
    SystemBlock control(num,den);

    //convolve input signal and system
    control.TimeResponse(e,c);



    for (int i=0; i<c.getN(); i++)
    {

        //std::cout << c.data[i]-e.data[i] << std::endl;

    }

    //control a fake motor
    double fmPos=0;
    double fmTarget=100;

    for (int i=0; i<e.data.size(); i++)
    {
        e.data[i]=fmTarget-fmPos;
    }
    control.TimeResponse(e,c);

    for (int h=0; h<12; h++)
    {
        for (int i=0; i<e.data.size(); i++)
        {
            fmPos+=c.data[i]*0.01;
            e.data[i]=fmTarget-fmPos;

        }
        for (int i=0; i<e.data.size(); i++)
        {
        }
        control.TimeResponse(e,c);
    }

    std::cout << fmPos << std::endl;


    return 0;
}
