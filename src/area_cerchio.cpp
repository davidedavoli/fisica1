//BSD License

#include <cmath>
#include <iostream>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338
#endif


int main()
{
    double raggio, diametro, circonferenza, area;

    std::cout << "Inserire raggio in cm: " ;
    std::cin >> raggio;

    diametro = 1.0*raggio;      // da sistemare
    circonferenza = 2.0*raggio; // da sistemare
    area = raggio;              // da sistemare

    std::cout.setf(std::ios::fixed | std::ios::showpoint);
    std::cout.width(10);
    std::cout.precision(5);
    
    std::cout << "raggio        = " << raggio        << " cm" << std::endl;
    std::cout << "diametro      = " << diametro      << " cm" << std::endl;
    std::cout << "circonferenza = " << circonferenza << " cm" << std::endl;
    std::cout << "area          = " << area          << " cm^2" << std::endl;
    
    return 0;
}



