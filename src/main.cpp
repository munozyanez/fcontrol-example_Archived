#include <complex>

#include "fcontrol.h"
#include <math.h>

int main()
{

    std::complex<double> a;
    TimeSignal e,c;
    TimeSignal Gc(100,10);

    for (int i=0; i<e.getN(); i++)
    {
        //double time=i*e.getDts();
        e.data[i]=0;
        //std::cout << e.data[i] << ",";

    }

    for (int i=0; i<Gc.getN(); i++)
    {
        //double time=i*e.getDts();
        Gc.data[i]=pow(-1,i)*3;
        //std::cout << Gc.data[i] << ",";

    }
    Gc.data[0]=11;
    Gc.data[1]=0;
    std::cout << std::endl;

    double Ts=0.001;

    //SystemBlock controller
    //numerator parameters    
    std::vector<double> num(3,0);
    num[2]=(3*Ts*Ts+10*Ts+12);
    num[1]=(6*Ts*Ts-24);
    num[0]=3*Ts*Ts-10*Ts+12;

    //denominator parameters
    std::vector<double> den(3,0);
    den[2]=2*Ts;
    den[1]=0.0;
    den[0]=-2*Ts;


    //instantiate object
    SystemBlock control(num,den);


    //SystemBlock Motor
    //numerator parameters
    //std::vector<double> num(3,0);
    num[2]=5*Ts*Ts;
    num[1]=10*Ts*Ts;
    num[0]=5*Ts*Ts;
    //denominator parameters
    //std::vector<double> den(3,0);
    den[2]=(10*Ts+2);
    den[1]=-4;
    den[0]=-10*Ts+2;

    //instantiate object
    SystemBlock motor(num,den);

    //std::vector<double> motorStates(den.size(),0);

    for (int i=0; i<c.getN(); i++)
    {

        //std::cout << c.data[i]-e.data[i] << std::endl;

    }

    //control a fake motor
    double fmPos,dPos;
    std::vector<double> motorStates(1,0);
    double fmTarget=10;
    double actualError,actualControl;


    for (int i=0; i<e.getN(); i++)
    {
        e.data[i]=0;
        //std::cout << e.data[i];

    }

    for (int h=0; h<10; h++)
    {
        fmPos=motorStates.back();
        actualError=fmTarget-fmPos;
        std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;

        actualControl=control.OutputUpdate(actualError);
        dPos=motor.OutputUpdate(actualControl);
        fmPos+=dPos;

        std::cout << "actualControl: " << actualControl << ", dPos: " << dPos << std::endl;

        motorStates.push_back(fmPos);
        //e.data.erase(e.data.begin());
        //e.data.push_back(actualError);

    }


/*

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
*/
    return 0;
}
