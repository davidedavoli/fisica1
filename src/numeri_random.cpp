// BSD LICENSE

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

constexpr size_t nrandom = 100;
constexpr int min_int = -2;
constexpr int max_int = 4;
constexpr double min_double = -1.5;
constexpr double max_double = 3.3;

int main ()
{
  std::srand((unsigned int)std::time(NULL));

  int irandom;
  double drandom;
  
  std::ofstream file_int;
  file_int.open ("integers.txt");
  std::ofstream file_real;
  file_real.open ("reals.txt");

  std::cout << "RAND_MAX=" <<  RAND_MAX << std::endl;
  std::cout << "Numeri semi-casuali interi tra " << min_int << " e " << max_int << std::endl;

  for (size_t i=0; i < nrandom; ++i)
  {
    //irandom = i1 + int(1.0*(i2-i1+1)*rand()/(RAND_MAX+1.0)); 
    //irandom = rand()%(i2-i1+1)+i1;
    drandom = rand()/double(RAND_MAX);  /* random number between 0.0 and 1.0 */
    drandom *= (max_double - min_double);
    drandom += min_double;
    irandom = int(drandom);
    std::cout << "i = " << irandom << std::endl;
    file_int  << setw(3) << irandom << std::endl; /* output to a file */
  }

  cout << endl << "Numeri semi-casuali reali tra " << min_double << " e " << max_double << endl; 
  for (size_t i=0; i < nrandom; ++i)
  {
    drandom = rand()/double(RAND_MAX);  /* random number between 0.0 and 1.0 */
    drandom *= (max_double - min_double);
    drandom += min_double;
    std::cout << "d = " << drandom << std::endl;
    file_real  << " " << drandom << std::endl;   /* output to a file */
  }

  return 0;
}


