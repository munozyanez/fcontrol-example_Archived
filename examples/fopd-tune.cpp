
#include "fcontrol.h"
#include <math.h>

#include "IPlot.h"

using namespace std;

int main()
{


    SystemBlock sys(vector<double>{1,1},vector<double>{-199,201});

    int numOrder=sys.GetNumOrder(),denOrder=sys.GetDenOrder();

    double mag,phi;
    double dts=0.01;
    sys.GetMagnitudeAndPhase(dts,1,mag,phi);

    cout << "mag: " << mag << " phi: " << phi << endl << "mag dB: " << 20*log10(mag) << " phi_deg: " << phi*180/M_PI <<endl;

    FPDTuner tuner(60,20);
    FPDBlock con;

    tuner.TuneIsom(sys,con);


}
