#include <complex>

#include "fcontrol.h"
#include <math.h>
#include <chrono>

//#include <plotter.h>
#include "IPlot.h"

using namespace std;

int main()
{

    double dts=0.01;
    IPlot infig(dts,"input"),outfig(dts,"output");

//    FractionalController1DOF f1(-1.5,0.01);
//    FPDBlock f1(0,1,-1.1,0.02);
//    PIDBlock f2(0,1,0,0.02);

    FractionalDerivative f1(-0.5,dts);
//    cout << f1.GetVfir()[1];
    vector<double> vfir=f1.GetVfir();
    IPlot firfig(vfir);

    chrono::system_clock::time_point start = std::chrono::system_clock::now();

    double in=10, out=0;
    for (int i=0; i<1000; i++)
    {
//        in=i*dts;

        out = in > f1;
//        infig.pushBack(in);
//        outfig.pushBack(out);
//        cout << "State: " << f1.GetState() << endl;

    }
//    infig.Plot();
//    outfig.Plot();
    firfig.Plot();
//    cout << "Final State: " << f1.GetState() << endl;

    chrono::system_clock::time_point finish = std::chrono::system_clock::now();
    chrono::nanoseconds elapsedNanoseconds = finish.time_since_epoch() - start.time_since_epoch();
    double tiempototal = elapsedNanoseconds.count();
    cout << "Tiempo total: ms " << (tiempototal/1000000) << endl;

    return 0;
}
