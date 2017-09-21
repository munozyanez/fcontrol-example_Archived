#include <complex>

#include "fcontrol.h"
#include <math.h>

#include <plotter.h>

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

    double Ts=0.01;

    //SystemBlock controller
    //numerator parameters

  /*   std::vector<double> numCon(2,0);
     numCon[1]=-(2*Ts+2);
     numCon[0]=-2*Ts+2;
     //numCon[0]=3*Ts*Ts-10*Ts+12;

     //denominator parameters
     std::vector<double> denCon(2,0);
     denCon[1]=(Ts-2);
     denCon[0]=+Ts+2;
     //denCon[0]=-2*Ts;
     SystemBlock control(numCon,denCon);


   std::vector<double> numCon(3,0);
    numCon[2]=(3*Ts*Ts+10*Ts+12);
    numCon[1]=(6*Ts*Ts-24);
    numCon[0]=3*Ts*Ts-10*Ts+12;

    //denominator parameters
    std::vector<double> denCon(3,0);
    denCon[2]=2*Ts;
    denCon[1]=0.0;
    denCon[0]=-2*Ts;

    std::vector<double> numCon(1,0);
    numCon[0]=5;
    std::vector<double> denCon(1,0);
    denCon[0]=1;


    //instantiate object
    SystemBlock control(numCon,denCon);
*/

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

    PIDBlock pidControl(5,2,2,Ts);


    //do
    for(int i=0;i<200;i++)
    {
        //fmPos=motorStates.back();
       actualError=fmTarget-fmPos;
        //std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;

        //actualControl=control.OutputUpdate(actualError);
       actualControl=pidControl.UpdateControl(actualError);

        fmPos=motor.OutputUpdate(actualControl);
        //fmPos+=dPos;

        //std::cout << "actualControl: " << actualControl << ", dPos: " << dPos << std::endl;
        //motorStates.push_back(fmPos);
        //e.data.erase(e.data.begin());
        //e.data.push_back(actualError);

        std::cout << "fmPos: " << fmPos << std::endl;
/*        //std::cout << "pid: " << pidControl.UpdateControl(actualError) << std::endl;


        std::cout << "motor.OutputUpdate: " << motor.OutputUpdate(-10) << std::endl;
*/

    }//while(actualError>0.1);

    fmTarget=0;

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


    for(int i=0;i<400;i++)
    {
        //fmPos=motorStates.back();
       actualError=fmTarget-fmPos;
        //std::cout << "error: " << actualError << ", fmPos: " << fmPos << std::endl;

        //actualControl=control.OutputUpdate(actualError);
       actualControl=control.OutputUpdate(actualError);

        fmPos=motor.OutputUpdate(actualControl);
        //fmPos+=dPos;

        //std::cout << "actualControl: " << actualControl << ", dPos: " << dPos << std::endl;
        //motorStates.push_back(fmPos);
        //e.data.erase(e.data.begin());
        //e.data.push_back(actualError);

        std::cout << "fmPos2: " << fmPos << std::endl;
    }

    //Plotter result;

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
