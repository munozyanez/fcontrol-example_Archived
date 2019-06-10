#include <complex>

#include "fcontrol.h"
#include <math.h>

#include "IPlot.h"

using namespace std;

int main()
{

    int numOrder=1,denOrder=2;
    OnlineSystemIdentification Gz(numOrder,denOrder);

    IPlot p;
    double dts=0.01;

    for (double t=0; t<2; t+=dts)

    {
        cout << Gz.UpdateSystem(1,2);
        p.pushBack(0.1);
        Gz.PrintZTransferFunction(dts);

    }

    vector<double> num(numOrder),den(denOrder);
    Gz.GetZTransferFunction(num,den);

//    vector<double> params = Gz.GetParamsVector();
//    for (int i=0; i<params.size(); i++) cout << params[i] << endl;

//    p.Plot();

    return 0;
}
