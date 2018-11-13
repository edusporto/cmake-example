#include "Matematica.h"

double Matematica::somar(double numero1, double numero2)
{
    return numero1 + numero2;
}

double Matematica::subtrair(double numero1, double numero2)
{
    return numero1 - numero2;
}

double Matematica::multiplicar(double numero1, double numero2)
{
    return numero1 * numero2;
}

double Matematica::dividir(double numero1, double numero2)
{
    return numero1 / numero2;
}


int Matematica::somar(int numero1, int numero2)
{
    return numero1 + numero2;
}

int Matematica::subtrair(int numero1, int numero2)
{
    return numero1 - numero2;
}

int Matematica::multiplicar(int numero1, int numero2)
{
    return numero1 * numero2;
}

int Matematica::dividir(int numero1, int numero2)
{
    return numero1 / numero2;
}


double Matematica::elevado(double base, int potencia)
{
    if (potencia == 0)
        return 1;

    if (potencia < 0)
    {
        base = 1/base;
        potencia = 0-potencia;
    }
    
    int ret = 1;

    for (int i=0; i<potencia; i++)
        ret *= base;
    
    return ret;
}

double Matematica::raiz(double numero, double numero2)
{
    // SERA MELHORADO

    double x;
    double A(numero);
    double dx;
    double eps(10e-6);
    double n(numero2);
    x = A * 0.5;
    dx = (A/Matematica::elevado(x,n-1)-x)/n;
    while(dx >= eps || dx <= -eps){
        x = x + dx;
        dx = (A/Matematica::elevado(x,n-1)-x)/n;
    }
   return x;
}