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

    for (double t=0; t<2; t+=0.01)

    {
        Gz.UpdateSystem(1,2);
        p.pushBack(0.1);

    }

    vector<double> num(numOrder),den(denOrder);
    Gz.GetZTransferFunction(num,den);
    for (int i=0; i<num.size(); i++) cout << num[i] << ", ";
    cout << endl;
    for (int i=0; i<den.size(); i++) cout << den[i] << ", ";
    cout << endl;

//    vector<double> params = Gz.GetParamsVector();
//    for (int i=0; i<params.size(); i++) cout << params[i] << endl;

//    p.Plot();

    return 0;
}
