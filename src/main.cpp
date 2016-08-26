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

    //SystemBlock
    //numerator parameters    
    std::vector<double> num(2,0);
    num[0]=0.5;
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
    double actualError,actualControl;


    for (int i=0; i<e.getN(); i++)
    {
        e.data[i]=0;
        //std::cout << e.data[i];

    }

    for (int h=0; h<10; h++)
    {
        actualError=fmTarget-fmPos;
        actualControl=control.TimeResponseUpdate(e,actualError);
        fmPos+=actualControl;
        e.data.erase(e.data.begin());
        e.data.push_back(actualError);
        std::cout << fmPos << std::endl;

    }



    ControllerBlock newcontrol;

    return 0;
}
