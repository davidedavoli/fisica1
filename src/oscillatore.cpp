// BSD License

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>


constexpr double intervallo_dt = 0.02;
constexpr size_t numero_steps = 100000;


//#derivata nel tempo del punto dello spazio delle fasi S(t)=[X,V], oscillatore armonico
double df0_dt(const double X, const double V) //derivata 
{
  return V;
}
double df1_dt(const double X, const double V)
{
  return -X;
}

void integratore(double dt, int nsteps)
{
  std::vector<double> X, V, norm; //teniamo a memoria tutta la traiettoria e la distanza in questi vettori
  X.resize(nsteps + 1);
  V.resize(nsteps + 1);
  norm.resize(nsteps + 1);

  X[0] = 1; //condizione iniziale
  V[0] = 0;
  norm[0] = sqrt(X[0] * X[0] + V[0] * V[0]); 
  std::cout << "0\t" << X[0] << "\t" << V[0] << "\t" << norm[0] << std::endl;

  for (int n = 0; n < nsteps; n++)
  {
    X[n + 1] = X[n] + 0; // DA FARE: completare utilizzando un metodo di integrazione
    V[n + 1] = V[n] + 0;

    norm[n + 1] = sqrt(X[n + 1] * X[n + 1] + V[n + 1] * V[n + 1]); 
    std::cout << n << "\t" << X[n+1] << "\t" << V[n+1] << "\t" << norm[n + 1] << std::endl;
  }
}


int main()
{
  integratore(intervallo_dt, numero_steps);

  return 0;
}




