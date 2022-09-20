#include<iostream>
#include<cmath>
using namespace std;
class biseccion{
	private:
		double xi, xf, err, error;
		int n;
	public:
		int res;
		biseccion():xi(0.0), xf(0.0), err(0.0), error(0.0), n(0){};
		void leerDatos();
		double f(double x){return pow(x, 2)-2;}
		double m(double i, double f){return(i+f)/2;}
		double e(double m, double i){return abs((m-i)/m)*100;}
		void calcRaizDo();
		void calcRaizFor();
		~biseccion(){cout<<"Limpiando memoria..."<<endl;}
};
void biseccion::leerDatos(){
	cout<<"Ingrese el valor inicial: ";
	cin>>xi;
	cout<<"Ingrese el valor final: ";
	cin>>xf;
	cout<<"Ingrese el numero de iteraciones: ";
	cin>>n;
	cout<<"Ingrese el error: ";
	cin>>err;
	cout<<"Iterador(1) | Error(2): ";
	cin>>res;
	cout<<endl;
}
void biseccion::calcRaizDo(){
	int cont = 1;
	do{
		double fxi=f(xi);
		double fxf=f(xf);
		if(fxi*fxf<0){
			double xm=m(xi, xf);
			double fxm=f(xm);
			error=e(xm, xi);
			if(fxi*fxm==0){
				cout<<"La raiz es: "<<xm<<endl;
				break;
			}
			else if(fxi*fxm<0){
				cout<<"n: "<<cont<<endl;
				cout<<"Xi: "<<xi<<endl;
				cout<<"Xf: "<<xf<<endl;
				cout<<"F(Xi): "<<fxi<<endl;
				cout<<"F(Xf): "<<fxf<<endl;
				cout<<"F(Xi)F(Xf): "<<fxi*fxf<<endl;
				cout<<"Xm: "<<xm<<endl;
				cout<<"F(Xm): "<<fxm<<endl;
				cout<<"F(Xi)F(Xm): "<<fxi*fxm<<endl;
				cout<<"Error: "<<error<<"%"<<endl<<endl;
				xf=xm;
				cont++;
			}
			else if(fxi*fxm>0){
				cout<<"n: "<<cont<<endl;
				cout<<"Xi: "<<xi<<endl;
				cout<<"Xf: "<<xf<<endl;
				cout<<"F(Xi): "<<fxi<<endl;
				cout<<"F(Xf): "<<fxf<<endl;
				cout<<"F(Xi)F(Xf): "<<fxi*fxf<<endl;
				cout<<"Xm: "<<xm<<endl;
				cout<<"F(Xm): "<<fxm<<endl;
				cout<<"F(Xi)F(Xm): "<<fxi*fxm<<endl;
				cout<<"Error: "<<error<<"%"<<endl<<endl;
				xi=xm;
				cont++;
			}
		}
		else{
			cout<<"Intervalo invalido :c"<<endl;
		}
	}while(error>err);
}
void biseccion::calcRaizFor(){
	int cont = 1;
	for (int i = 0; i < n; i++){
		double fxi=f(xi);
		double fxf=f(xf);
		if(fxi*fxf<0){
			double xm=m(xi, xf);
			double fxm=f(xm);
			error=e(xm, xi);
			if(fxi*fxm==0){
				cout<<"La raiz es: "<<xm<<endl;
				break;
			}
			else if(fxi*fxm<0){
				cout<<"n: "<<cont<<endl;
				cout<<"Xi: "<<xi<<endl;
				cout<<"Xf: "<<xf<<endl;
				cout<<"F(Xi): "<<fxi<<endl;
				cout<<"F(Xf): "<<fxf<<endl;
				cout<<"F(Xi)F(Xf): "<<fxi*fxf<<endl;
				cout<<"Xm: "<<xm<<endl;
				cout<<"F(Xm): "<<fxm<<endl;
				cout<<"F(Xi)F(Xm): "<<fxi*fxm<<endl;
				cout<<"Error: "<<error<<"%"<<endl<<endl;
				xf=xm;
				cont++;
			}
			else if(fxi*fxm>0){
				cout<<"n: "<<cont<<endl;
				cout<<"Xi: "<<xi<<endl;
				cout<<"Xf: "<<xf<<endl;
				cout<<"F(Xi): "<<fxi<<endl;
				cout<<"F(Xf): "<<fxf<<endl;
				cout<<"F(Xi)F(Xf): "<<fxi*fxf<<endl;
				cout<<"Xm: "<<xm<<endl;
				cout<<"F(Xm): "<<fxm<<endl;
				cout<<"F(Xi)F(Xm): "<<fxi*fxm<<endl;
				cout<<"Error: "<<error<<"%"<<endl<<endl;
				xi=xm;
				cont++;
			}
		}
	}
}
int main(void){
	biseccion r1;
	r1.leerDatos();
	if(r1.res==1){
		r1.calcRaizFor();
	}
	else if(r1.res==2){
		r1.calcRaizDo();
	}
	else{
		cout<<"Opcion invalida"<<endl;
	}
	return 0;
}