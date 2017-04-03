//BSD License

#include <cmath>
#include <iostream>
#include <iomanip>

int main()
{
    double a, b, c, delta, sol1, sol2;
    std::cout << "Soluzione equazione ax^2 + bx + c = 0" << std::endl;
    std::cout << "Inserisci a: " ;
    std::cin >> a;
    std::cout << "Inserisci b: " ;
    std::cin >> b;
    std::cout << "Inserisci c: " ;
    std::cin >> c;

    std::cout << "Preparo le soluzioni dell'equazione " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;

    delta = b*b-4*a*c;                   // da sistemare
    sol1 = -b + std::sqrt(delta)/(2*a);
    sol2 = 1.0;                          // da sistemare

    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    
    std::cout << "Sol #1: " << sol1 << std::endl;
    std::cout << "Sol #2: " << sol2 << std::endl;
    
    return 0;
}



