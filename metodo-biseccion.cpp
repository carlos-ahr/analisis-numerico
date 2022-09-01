#include <ios>
#include <iostream>
#include <cmath>

using namespace std;

class biseccion{
    double xi, xf, er;
    int n;
public:
    biseccion(double i, double f, double e, int num){xi=i, xf=f, er=e, n=num;};
    double f(double x){return pow(x, 2)-2;};
    void calc_raiz();
    ~biseccion(){cout<<"Limpiando memoria..."<<endl;};
};

void biseccion::calc_raiz(){
    double xm=(xi+xf)/2;
    int num=1;
    cout<<"n    xi    xf    f(xi)    (xm)    f(xi)f(xf)    xm    f(xm)    Error"<<endl;
    if(f(xi)*f(xf)<0){
        do{
            if (f(xi)*f(xm)==0) {
            cout<<"La raiz es: "<<xm<<endl;
            }
            else if (f(xi)*f(xm)<0){
                cout<<num<<" "
                    <<xi<<" "
                    <<xf<<" "
                    <<f(xi)<<" "
                    <<f(xf)<<" "
                    <<f(xi)*f(xf)<<" "
                    <<xm<<" "
                    <<f(xm)<<" "
                    <<f(xi)/f(xm)<<" "
                    <<fabs((xi-xm)/xm*100)<<endl;
                xf=xm;
            }
            else if (f(xi)*f(xm)>0){
                cout<<num<<"\t"
                    <<xi<<"\t"
                    <<xf<<"\t"
                    <<f(xi)<<"\t"
                    <<f(xf)<<"\t"
                    <<f(xi)*f(xf)<<"\t"
                    <<xm<<"\t"
                    <<f(xm)<<"\t"
                    <<f(xi)/f(xm)<<"\t"
                    <<fabs((xi-xm)/xm*100)<<endl;
                xi=xm;
            }
        }   
        while(fabs((xi-xm)/xm*100)<er);
    }
}

int main(){
    biseccion raiz(-2, -1, 1, 5);
    raiz.calc_raiz();
    return 0;
}
