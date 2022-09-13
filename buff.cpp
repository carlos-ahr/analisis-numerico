#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

string linea = "------------------------------------------------------------------------------------------------------------";
string separador = "  |  ";
string t0 = "n";
string t1 = "Xi";
string t2 = "Xf";
string t3 = "f(Xi)";
string t4 ="f(Xf)";
string t5 = "f(Xi)f(Xf)";
string t6 = "Xm";
string t7 = "f(Xm)";
string t8 = "f(Xi)f(Xf)";
string t9 = "Error";

class biseccion{
    private:
        double xi, xf, err, error;
        int n;
    public:
        int res;
        biseccion():xi(0.0), xf(0.0), err(0.0), error(0.0), n(0), res(0){};
        void leerDatos();
        double f(double x){return pow(x, 2)-2;}
        double m(double i, double f){return (i+f)/2;}
        double e(double i, double m){return (abs((m-i)/m))*100;}
        void calcRaizFOR();
        void calcRaizDO();
        ~biseccion(){}
};

void biseccion::leerDatos(){
    cout<<"Ingrese el valor inicial:"<<endl;
    cin>>xi;
    cout<<"Ingrese el valor final:"<<endl;
    cin>>xf;
    cout<<"Ingrese el numero de iteraciones:"<<endl;
    cin>>n;
    cout<<"Ingrese el error: "<<endl;
    cin>>err;
    cout<<"(1)Iterador | (2)Error"<<endl;
    cin>>res;
}

void biseccion::calcRaizFOR(){
    cout<<linea<<endl
        <<"|  "<<left<<t0
        <<separador<<setw(5)<<t1
        <<separador<<setw(5)<<t2
        <<separador<<setw(5)<<t3
        <<separador<<setw(5)<<t4
        <<separador<<setw(10)<<t5
        <<separador<<setw(5)<<t6
        <<separador<<setw(5)<<t7
        <<separador<<setw(10)<<t8
        <<separador<<setw(6)<<t9<<"  |"<<endl
        <<linea<<endl;
    int cont = 1;
    for(int i = 0; i < n; i++){
        double fxi = f(xi);
        double fxf = f(xf);
        if(fxi*fxf < 0){
            double xm = m(xi, xf);
            double fxm = f(xm);
            error = e(xi, xm);
            
            if(fxi*fxm == 0){
                cout<<"La raiz es: "<<xm<<endl;
                break;
            }
            else if(fxi*fxm < 0){
                cout<<fixed<<setprecision(2)<<"|  "<<cont
                    <<separador<<setw(5)<<xi
                    <<separador<<setw(5)<<xf
                    <<separador<<setw(5)<<fxi
                    <<separador<<setw(5)<<fxf
                    <<separador<<setw(10)<<fxi*fxf
                    <<separador<<setw(5)<<xm
                    <<separador<<setw(5)<<fxm
                    <<separador<<setw(10)<<fxi*fxm
                    <<separador<<setw(5)<<error<<"%"<<"  |"<<endl
                    <<linea<<endl;
                xf = xm;
                cont++;
            }
            else if(fxi*fxm > 0){
                cout<<fixed<<setprecision(2)<<"|  "<<cont
                    <<separador<<setw(5)<<xi
                    <<separador<<setw(5)<<xf
                    <<separador<<setw(5)<<fxi
                    <<separador<<setw(5)<<fxf
                    <<separador<<setw(10)<<fxi*fxf
                    <<separador<<setw(5)<<xm
                    <<separador<<setw(5)<<fxm
                    <<separador<<setw(10)<<fxi*fxm
                    <<separador<<setw(5)<<error<<"%"<<"  |"<<endl
                    <<linea<<endl;   
                xi = xm;
                cont++;
            }
        }
        else{
            cout<<"Intervalo invalido"<<endl;
        }
    }
}

void biseccion::calcRaizDO(){
    cout<<linea<<endl
        <<"|  "<<left<<t0
        <<separador<<setw(5)<<t1
        <<separador<<setw(5)<<t2
        <<separador<<setw(5)<<t3
        <<separador<<setw(5)<<t4
        <<separador<<setw(10)<<t5
        <<separador<<setw(5)<<t6
        <<separador<<setw(5)<<t7
        <<separador<<setw(10)<<t8
        <<separador<<setw(6)<<t9<<"  |"<<endl
        <<linea<<endl;
    int cont = 1;
	do{
		double fxi=f(xi);
		double fxf=f(xf);
		if(fxi*fxf<0){
			double xm=m(xi, xf);
			double fxm=f(xm);
			error=e(xi, xm);
			if(fxi*fxm==0){
				cout<<"La raiz es: "<<xm<<endl;
				break;
			}
			else if(fxi*fxm<0){
				cout<<fixed<<setprecision(2)<<"|  "<<cont
                    <<separador<<setw(5)<<xi
                    <<separador<<setw(5)<<xf
                    <<separador<<setw(5)<<fxi
                    <<separador<<setw(5)<<fxf
                    <<separador<<setw(10)<<fxi*fxf
                    <<separador<<setw(5)<<xm
                    <<separador<<setw(5)<<fxm
                    <<separador<<setw(10)<<fxi*fxm
                    <<separador<<setw(5)<<error<<"%"<<"  |"<<endl
                    <<linea<<endl;
                xf = xm;
                cont++;
			}
			else if(fxi*fxm>0){
                cout<<fixed<<setprecision(2)<<"|  "<<cont
                    <<separador<<setw(5)<<xi
                    <<separador<<setw(5)<<xf
                    <<separador<<setw(5)<<fxi
                    <<separador<<setw(5)<<fxf
                    <<separador<<setw(10)<<fxi*fxf
                    <<separador<<setw(5)<<xm
                    <<separador<<setw(5)<<fxm
                    <<separador<<setw(10)<<fxi*fxm
                    <<separador<<setw(5)<<error<<"%"<<"  |"<<endl
                    <<linea<<endl;
                xi = xm;
                cont++;	
			}
		}
		else{
			cout<<"Intervalo invalido"<<endl;
		}
	}while(error>err);
}

int main(void){
    biseccion raiz;
    raiz.leerDatos();
    if(raiz.res == 1){
        raiz.calcRaizFOR();
    }
    else if(raiz.res == 2){
        raiz.calcRaizDO();
    }
    else{
        cout<<"Opcion invalida"<<endl;
    }
    return 0;
}

