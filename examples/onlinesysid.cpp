#include <complex>

#include "fcontrol.h"
#include <math.h>

#include "IPlot.h"

using namespace std;

int main()
{



//    SystemBlock sys(vector<double>{1,1,1},vector<double>{0.5,-0.9,1});
    SystemBlock sys(vector<double>{10},vector<double>{-199,201});
    //Low system gains lead to identification errors!!!

    int numOrder=sys.GetNumOrder(),denOrder=sys.GetDenOrder();
    OnlineSystemIdentification Gz(numOrder,denOrder);

    double dts=0.01;
    IPlot real(dts,"t(s)","Out","real");
    IPlot id(dts,"t(s)","Out","id");

    double in=0,out=0;
    double tmax=5;

    for (double t=0; t<tmax; t+=dts)

    {
        in=1+0.001*((rand() % 10 + 1)-5); //u_{i-1}
        out=in > sys;//y_{i}

        Gz.UpdateSystem(in,out);

        real.pushBack(out);
        //Gz.PrintParamsVector();

    }
//    real.SetParameters("set lc 'blue'");
    real.Plot();

    Gz.PrintZTransferFunction(dts);


    vector<double> num(numOrder+1),den(denOrder+1);
    Gz.GetZTransferFunction(num,den);
    SystemBlock idsys(num,den);

    for (double t=0; t<tmax; t+=dts)

    {
        in=1;//*(rand() % 10 + 1)-5;
        out=in > idsys;
        id.pushBack(out);
        //Gz.PrintZTransferFunction(dts);
        //Gz.PrintParamsVector();

    }

    id.Plot();

//    vector<double> params = Gz.GetParamsVector();
//    for (int i=0; i<params.size(); i++) cout << params[i] << endl;

//    p.Plot();

    return 0;
}
