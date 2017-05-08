
#include "fcontrol.h"
#include <math.h>

#include <IPlot.h>

int main()
{

    double Ts=0.01;

    double ka=1.1;

    //plotters
    IPlot pt(Ts),vt(Ts);

    //instantiate object motor
    SystemBlock motor(
                std::vector<double> {ka*Ts,ka*Ts},
                std::vector<double> {Ts-2,Ts+2}
                );


    //instantiate object encoder
    SystemBlock encoder(
                std::vector<double> {Ts,Ts},
                std::vector<double> {-2,+2}
                );

    PIDBlock pidControl(10,1,3,Ts);


    motor.SetSaturation(-5,5); //max motor vel



     //control a fake motor
     double fmPos=0,dPos;
     std::vector<double> motorvels(0),motorStates(0),times(0);
     double fmTarget=10;
     double actualError,actualControl;

    for(int i=0;i<400;i++)
    {
       actualError=fmTarget-fmPos;
        //std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;

       //actualControl=pidControl.OutputUpdate(actualError);


       actualError > pidControl > motor >  encoder;
       //motor.OutputUpdate(pidControl.GetState());
       fmPos = encoder.GetState();


       vt.pushBack(motor.GetState());
       pt.pushBack(fmPos);
        motorStates.push_back(fmPos);
        times.push_back(i*Ts);

        std::cout << "fmPos: " << fmPos << std::endl;
    }

    vt.Plot();
    pt.Plot();




    return 0;
}
