#include<iostream>
#include<cmath>
using namespace std;
class biseccion{
	private:
		double xi, xf, err, error;
	public:
		biseccion();
		void leerDatos();
		double f(double x){return pow(x, 2)-x-1;}
		double m(double i, double f){return(i+f)/2;}
		double e(double m, double i){return abs((m-i)/m)*100;}
		void calcRaiz();
		~biseccion();
};
biseccion::biseccion(){
	xi=0.0;
	xf=0.0;
	err=0.0;
	error=0.0;
}
void biseccion::leerDatos(){
	cout<<"Ingrese el valor inicial:"<<endl;
	cin>>xi;
	cout<<"Ingrese el valor final:"<<endl;
	cin>>xf;
	cout<<"Ingrese el error: "<<endl;
	cin>>err;
	cout<<endl;
}
void biseccion::calcRaiz(){
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
			}
			else if(fxi*fxm>0){
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
			}
		}
		else{
			cout<<"Intervalo invalido :c"<<endl;
		}
	}while(error>err);
}
biseccion::~biseccion(){
	cout<<"Limpiando memoria..."<<endl;
}
int main(void){
	biseccion r1;
	r1.leerDatos();
	r1.calcRaiz();
	return 0;
}
