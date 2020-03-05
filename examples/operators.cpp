
#include "fcontrol.h"
#include <math.h>

#include <IPlot.h>

int main()
{

    double dts=0.01;

    double ka=1.1;

    //plotters
    IPlot ptPlot(dts),vtPlot(dts);

    //instantiate object motor
    SystemBlock motor(
                std::vector<double> {ka*dts,ka*dts},
                std::vector<double> {dts-2,dts+2}
                );


    //instantiate object encoder
    SystemBlock encoder(
                std::vector<double> {dts,dts},
                std::vector<double> {-2,+2}
                );

    PIDBlock pidControl(1,0,0,dts);


    //motor.SetSaturation(-10,10); //max motor vel



    //control a fake motor
    double fmPos=0,dPos;
    TimeSignal tsPos(100,dts);
    std::vector<double> motorvels(0),motorStates(0),times(0);
    double fmTarget=10;
    double actualError,actualControl;

    for(int i=0;i<400;i++)
    {
        actualError=fmTarget-fmPos;
        std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;
        actualError > pidControl > motor >  encoder > tsPos;
//encoder > fmPos;

        fmPos = tsPos.GetValue(0);
//        fmPos = encoder.GetState();


        vtPlot.pushBack(motor.GetState());
        ptPlot.pushBack(fmPos);
        motorStates.push_back(fmPos);
        times.push_back(i*dts);

        std::cout << "fmPos: " << fmPos << std::endl;
    }

    vtPlot.Plot();
    ptPlot.Plot();




    return 0;
}
