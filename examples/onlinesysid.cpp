#include <complex>

#include "fcontrol.h"
#include <math.h>

#include "IPlot.h"

using namespace std;

int main()
{

    OnlineSystemIdentification Gz;

    IPlot p;

    for (double t=0; t<2; t+=0.01)

    {
        Gz.UpdateSystem(1,2);
        p.pushBack(0.1);

    }

    p.Plot();

    return 0;
}
