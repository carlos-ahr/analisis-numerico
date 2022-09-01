#include <iostream>
#include <cmath>
using namespace std;
class biseccion{
    double xi, xf, err;
    int n;
    public:
        biseccion();
        void leer_datos(double, double, int);
        double f(double);
        void calc_raiz();
        ~biseccion();

};
void biseccion::leer_datos(double i, double f, int num, double e){
    xi=i;
    xf=f;
    n=num;
    e=err;

}
double biseccion::f(double x){
    return pow(x, 2)-2;
}
void biseccion::calc_raiz(){
    if(f(xi)*f(xf)<0){
        for(while n>0){
            double xm=(xi+xf)/2;
            if (f(xi)*f(xm)<0){
                xf=xm;

            }
            else if(f(xi)*f(xm)>0){
                xi=xm;

            }
        }
    }
}

int main(){
return 0;
}
