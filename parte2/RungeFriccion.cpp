#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

const double K = 50;
const double M = 2;
const double LAMBDA = 1;
const double DeltaT = 0.01;
//Se agrega la fricción
const double Gamma=0.3;


double f0(double t, double y0, double y1); 
double f1(double t, double y0, double y1); 
void rungekutta4(double t, double h, double & y0, double & y1); 


double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K/M)*pow(y0, LAMBDA)-(Gamma*y1);
}

void rungekutta4(double t, double h, double & y0, double & y1)
{
  double k10, k11, k20, k21, k30, k31, k40, k41;
  k10 = h*f0(t, y0, y1);
  k11 = h*f1(t, y0, y1);
  k20 = h*f0(t+h/2, y0 + k10/2, y1 + k11/2);
  k21 = h*f1(t+h/2, y0 + k10/2, y1 + k11/2);
  k30 = h*f0(t+h/2, y0 + k20/2, y1 + k21/2);
  k31 = h*f1(t+h/2, y0 + k20/2, y1 + k21/2);
  k40 = h*f0(t + h, y0 + k30, y1 + k31);
  k41 = h*f1(t + h, y0 + k30, y1 + k31);

  y0 = y0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  y1 = y1 + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
}

int main(void)
{
  ofstream outfile;
  outfile.open("friccion.dat");
  double x, v, time;
  x = 1;
  v = 0;
  for(time = 0; time < 20; time += DeltaT) {
    outfile<< time << "\t" << x << "\t" << v << endl;
    rungekutta4(time, DeltaT, x, v);
    
  }
  outfile.close();

  return 0;
}
