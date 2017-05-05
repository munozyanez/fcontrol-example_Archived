
#include "fcontrol.h"
#include <math.h>

#include <IPlot.h>

int main()
{

    double Ts=0.01;

    double ka=1.1;
    //SystemBlock Motor
    //numerator parameters
    std::vector<double> num(3,0);
    num[2]=ka*Ts*Ts;
    num[1]=2*ka*Ts*Ts;
    num[0]=ka*Ts*Ts;
    //denominator parameters
    std::vector<double> den(3,0);
    den[2]=(2*Ts+4);
    den[1]=-8;
    den[0]=-2*Ts+4;
    //instantiate object
    SystemBlock motor(
                std::vector<double> {ka*Ts,ka*Ts},
                std::vector<double> {Ts-2,Ts+2}
                );


    //instantiate object
    SystemBlock encoder(
                std::vector<double> {Ts,Ts},
                std::vector<double> {-2,+2}
                );

    PIDBlock pidControl(10,1,10,Ts);





     //control a fake motor
     double fmPos=0,dPos;
     std::vector<double> motorvels(0),motorStates(0),times(0);
     double fmTarget=10;
     double actualError,actualControl;

    for(int i=0;i<400;i++)
    {
       actualError=fmTarget-fmPos;
        //std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;

       actualControl=pidControl.OutputUpdate(actualError);

        //fmPos=motor.OutputUpdate(actualControl);
       //motor.OutputUpdate(actualControl);

//       actualControl >= motor;
//       motor >> encoder;
       actualControl > motor >  encoder;
       //motor.OutputUpdate(pidControl.GetState());
       fmPos = encoder.GetState();


        //std::cout << "actualControl: " << actualControl << ", dPos: " << dPos << std::endl;
        //motorStates.push_back(fmPos);
        //e.data.erase(e.data.begin());
        //e.data.push_back(actualError);
       motorvels.push_back(motor.GetState());
        motorStates.push_back(fmPos);
        times.push_back(i*Ts);

        std::cout << "fmPos: " << fmPos << std::endl;
    }

    IPlot pVt;
    pVt.Plot(times, motorStates, 10, 15);
    pVt.Plot(times, motorvels, 10, 15);



    return 0;
}
