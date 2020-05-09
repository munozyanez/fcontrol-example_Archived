#include <complex>

#include "fcontrol.h"
#include <math.h>

#include <plotter.h>

using namespace std;

int main()
{

double dts=0.01;
//    FractionalController1DOF f1(1,dts);
    SystemBlock ipart1 (
                std::vector<double> {0,1*dts},
                std::vector<double> {-1,1});
    SystemBlock ipart2(
                std::vector<double> {0,1},
                std::vector<double> {-1,1});
FractionalDerivative f1(0.99,1);

    for (int i=0; i<10; i++)
    {
        cout << "; State: " << (10 > ipart1 > ipart2 > f1  );

//        cout << "State: " << ipart2.GetState() << endl;

    }
//    for (int i=0; i<10; i++)
//    {
//        -5 > f1;
//        cout << "State: " << f1.GetState() << endl;

//    }
//    cout << "Final State: " << f1.GetState() << endl;
    return 0;
}
