#include <complex>

#include "fcontrol.h"
#include <math.h>

int main()
{

    std::complex<double> a;
    TimeSignal e,c;
    TimeSignal Gc(100,10);

    for (int i=0; i<Gc.getN(); i++)
    {
        double time=i*e.getDts();
        Gc.data[i]=exp(time)-(time*exp(time));
        std::cout << Gc.data[i] << ",";

    }
    std::cout << std::endl;
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




    std::vector<double> numH = {1,0};
    std::vector<double> denH = {1,1};

    TransferFunction H(numH, denH );

    ControllerBlock newcontrol(H);


    //control a fake motor
    fmPos=0;
    fmTarget=100;

    for (int h=0; h<10; h++)
    {
        actualError=fmTarget-fmPos;
        fmPos+=newcontrol.ControlSignal(actualError);
        std::cout << fmPos << std::endl;

    }

    return 0;
}
