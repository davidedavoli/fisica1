//BSD License

#include <fstream>
#include <cmath>
#include <iostream>

constexpr int Nmax = 1000; //numero di segmenti

double f(const double & x)
{
  return sin(x);
}

double rettangoli(double a, double b, int N) //integra f in [a,b] con N rettangoli
{
  double sum = 0.0;
  double dx = (b - a) / N;

  for (int i = 0; i < N; i++)
  {
    // DA FARE
  }

  return sum;
}

double trapezi(double a, double b, int N)
{
  double sum = 0.0;
  double dx = (b - a) / N;

  for (int i = 0; i < N; i++)
  {
    // DA FARE
  }

  return sum;
}

int main()
{
  std::ofstream f("integratore.txt", std::ios::out);

  double truth = 1.0 - cos(1.0);

  for (int n = 1; n < Nmax; n++) //calcolo degli integrali con varie discretizzazioni(segmenti)
  {
    f << n << "\t" << rettangoli(0.0, 1.0, n) - truth /* errore con il metodo dei rettangoli */ 
           << "\t" << trapezi(0.0, 1.0, n) - truth /* errore con il metodo dei trapezi */
           << std::endl;
  }


  f.close();
  return 0;
}
