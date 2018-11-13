#ifndef MATEMATICA_H
#define MATEMATICA_H  

class Matematica {
    public:
        static double somar(double, double);
        static double subtrair(double, double);
        static double multiplicar(double, double);
        static double dividir(double, double);
        static int somar(int, int);
        static int subtrair(int, int);
        static int multiplicar(int, int);
        static int dividir(int, int);

        static double elevado(double, int);
        static double raiz(double, double);
    private:
        Matematica() {};
};

#endif