#include <complex>

#include "fcontrol.h"
#include <math.h>

//#include <plotter.h>
#include "IPlot.h"

using namespace std;

int main()
{


//    FractionalController1DOF f1(-1.5,0.01);
    FPDBlock f1(0,1,-1.1,0.02);
//    PIDBlock f2(0,1,0,0.02);

    for (int i=0; i<100; i++)
    {
        10 > f1;
//        cout << "State: " << f1.GetState() << endl;

    }
    cout << "Final State: " << f1.GetState() << endl;
    return 0;
}
