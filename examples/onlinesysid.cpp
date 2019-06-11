#include <complex>

#include "fcontrol.h"
#include <math.h>

#include "IPlot.h"

using namespace std;

int main()
{

    SystemBlock sys(1,1,-199,201);

    int numOrder=1,denOrder=1;
    OnlineSystemIdentification Gz(numOrder,denOrder);

    IPlot p;
    double dts=0.01;
    double in,out;

    for (double t=0; t<10; t+=dts)

    {
        in=1;//*(rand() % 10 + 1)-5;
        out=in > sys;
        cout << Gz.UpdateSystem(in,out);
        p.pushBack(out);
        Gz.PrintZTransferFunction(dts);
//        Gz.PrintParamsVector();

    }

    vector<double> num(numOrder),den(denOrder);
    Gz.GetZTransferFunction(num,den);

//    vector<double> params = Gz.GetParamsVector();
//    for (int i=0; i<params.size(); i++) cout << params[i] << endl;

    p.Plot();

    return 0;
}
