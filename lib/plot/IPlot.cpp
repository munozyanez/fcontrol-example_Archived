#include "IPlot.h"

IPlot::IPlot()
{

}

long IPlot::Plot(std::vector<double> datax, std::vector<double> datay, double scalex, double scaley)
{
    PlotterParams newParams;
    newParams.setplparam("PAGESIZE", (char *)"a4");
    newParams.setplparam("BITMAPSIZE", (char *)"600x600");

    XPlotter plt(newParams);
    plt.fspace(-100, 100, -600, 600);
    //plt.fscale(2,2);
    plt.openpl();
    plt.pencolorname("blue");



    for (ulong i=1; i<datax.size(); i++)
    {
        //plt.fpoint(datax[i]/scalex,datay[i]/scaley);
        plt.fmove(datax[i]/scalex,datay[i]/scaley);
        plt.fline(datax[i-1]/scalex,datay[i-1]/scaley,datax[i]/scalex,datay[i]/scaley);
        //plt.fcircle(datax[i]/scalex,datay[i]/scaley,std::max(scalex,scaley)/10000.);

        //plt.endpath();
        //plt.flushpl();

    }

    plt.endpath();
    plt.flushpl();
    plt.closepl();


}

long IPlot::PlotAndSave(std::vector<double> datax, std::vector<double> datay, double scalex, double scaley, std::string filename)
{
    PlotterParams newParams;
    newParams.setplparam("PAGESIZE", (char *)"a4");
    newParams.setplparam("BITMAPSIZE", (char *)"600x600");

    XPlotter plt(newParams);
    plt.fspace(-100, 100, -600, 600);
    //plt.fscale(2,2);
    plt.openpl();
    plt.pencolorname("blue");


    std::fstream datafile;
    datafile.open (filename, std::fstream::out);

    for (ulong i=1; i<datax.size(); i++)
    {
        //plt.fpoint(datax[i]/scalex,datay[i]/scaley);
        plt.line(datax[i-1],datay[i-1],datax[i],datay[i]);
        plt.fmove(datax[i]/scalex,datay[i]/scaley);
        plt.fcircle(datax[i]/scalex,datay[i]/scaley,std::max(scalex,scaley)/10000.);
        //plt.endpath();
        //plt.flushpl();

        //fprintf (gdata, "%f - %f - %f - %f \n",Ts*i,vel,actualVel,jointPos);
        datafile << datax[i] << " - "
                 << datay[i] << ""

                 << std::endl;


    }



    plt.endpath();
    plt.flushpl();
    plt.closepl();
    datafile.close();


}
