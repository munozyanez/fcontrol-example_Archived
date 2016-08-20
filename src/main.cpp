#include <complex>

#include "fcontrol.h"

int main()
{

    std::complex<double> a;
    TimeSignal e;

    for (int i=0; i<e.getN(); i++)
    {
        e.data[i]=sin(0.1*i*e.getDts());
        std::cout << e.data[i];

    }
    std::cout << std::endl;

    //SystemBlock
    double num[]={1,0};
    SystemBlock control;

    control.SignalParams(e);


    return 0;
}
