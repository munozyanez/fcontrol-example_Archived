
#include "fcontrol.h"
#include <math.h>

#include "IPlot.h"

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


    PIDBlock pidControl(1,1,0,Ts);
    pidControl.SetSaturation(-5,5);
    pidControl.AntiWindup(-5,5);

    IPlot cs(Ts, "Control signal vs time ", "Time (s)", "Control signal ");
    IPlot pVt(Ts,"Position vs time ", "Time (s)", "Position signal (rad) ");
    IPlot err(Ts,"Error vs time ", "Time (s)", "Error (rad)");


     //control a fake motor
     double fmPos=0,dPos;
     std::vector<double> motorStates(0),times(0);
     double fmTarget=10;
     double actualError,actualControl;

    //Control loop
    for(int i=0;i<2000;i++)
    {
        //fmPos=motorStates.back();
       actualError=fmTarget-fmPos;
        //std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;

        //actualControl=control.OutputUpdate(actualError);
       actualControl=pidControl.OutputUpdate(actualError);


        fmPos=motor.OutputUpdate(actualControl);
        //fmPos+=dPos;

        err.pushBack(actualError);
        cs.pushBack(actualControl);
        pVt.pushBack(fmPos);

        //std::cout << "actualControl: " << actualControl << ", dPos: " << dPos << std::endl;
        //motorStates.push_back(fmPos);
        //e.data.erase(e.data.begin());
        //e.data.push_back(actualError);
//        motorStates.push_back(fmPos);
//        times.push_back(i*Ts);

//        std::cout << "fmPos: " << fmPos << std::endl;
    }

    pVt.Plot();
//    cs.Plot();
//    err.Plot();


    return 0;
}
