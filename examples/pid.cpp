
#include "fcontrol.h"
#include <math.h>

#include <IPlot.h>

int main()
{

    double Ts=0.01;

    //SystemBlock Motor
    //numerator parameters
    std::vector<double> num(3,0);
    num[2]=5*Ts*Ts;
    num[1]=10*Ts*Ts;
    num[0]=5*Ts*Ts;
    //denominator parameters
    std::vector<double> den(3,0);
    den[2]=(10*Ts+2);
    den[1]=-4;
    den[0]=-10*Ts+2;

    //instantiate object
    SystemBlock motor(num,den);


    PIDBlock pidControl(5,0.2,0.2,Ts);


    std::vector<double> numCon(2,0);
     numCon[1]=-(2*Ts-2);
     numCon[0]=-2*Ts-2;
     //numCon[0]=3*Ts*Ts-10*Ts+12;

     //denominator parameters
     std::vector<double> denCon(2,0);
     denCon[1]=(Ts+2);
     denCon[0]=+Ts-2;
     //denCon[0]=-2*Ts;
     SystemBlock control(numCon,denCon);



     //control a fake motor
     double fmPos,dPos;
     std::vector<double> motorStates(0),times(0);
     double fmTarget=10;
     double actualError,actualControl;

    for(int i=0;i<400;i++)
    {
        //fmPos=motorStates.back();
       actualError=fmTarget-fmPos;
        //std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;

        //actualControl=control.OutputUpdate(actualError);
       actualControl=pidControl.OutputUpdate(actualError);

        fmPos=motor.OutputUpdate(actualControl);
        //fmPos+=dPos;

        //std::cout << "actualControl: " << actualControl << ", dPos: " << dPos << std::endl;
        //motorStates.push_back(fmPos);
        //e.data.erase(e.data.begin());
        //e.data.push_back(actualError);
        motorStates.push_back(fmPos);
        times.push_back(i*Ts);

        std::cout << "fmPos: " << fmPos << std::endl;
    }

    IPlot pVt;
    pVt.Plot(times, motorStates, 10, 15);

    return 0;
}
