#include <complex>

#include "fcontrol.h"
#include <math.h>

#include <plotter.h>

using namespace std;

int main()
{


    FractionalController1DOF f1(-0.5,0.01);

    for (int i=0; i<10; i++)
    {
        1 > f1;

    }
    cout << "Final State: " << f1.getState() << endl;
    return 0;
}
