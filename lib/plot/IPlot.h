#ifndef PLOT_H
#define PLOT_H


#include <vector>
#include <plotter.h>
#include <plot.h>
#include <fstream>      // std::fstream

#include <iostream>
//#include <plplot/plplot.h>
//#include <plplot/plstream.h>
#define NSIZE    101

class IPlot
{
public:
    IPlot();
    long Plot(std::vector<double> datax, std::vector<double> datay, double scalex, double scaley);
    long PlotAndSave(std::vector<double> datax, std::vector<double> datay, double scalex, double scaley, std::string filename);
private:
    //PlotterParams puPlotParams;
};

#endif // PLOT_H
