#include <iostream>
#include <cmath>

using namespace std;

class newtonRaphson{
	private:
		double xi, err, error;
		int n;
    public:
		int res;
		newtonRaphson():xi(0.0), err(0.0), error(0.0), n(0){};
		void leerDatos();
		double f(double x){return pow(x, 2)-2;}
		double fp(double x){return (2*x)-1;}
		double x1(double xi, double fxi, double fpxi){return xi-(fxi/fpxi);}
		double e(double xi1, double xi){return abs((xi1-xi)/xi1)*100;}
		void calcRaizDo();
		void calcRaizFor();
		~newtonRaphson(){cout<<"Limpiando memoria..."<<endl;}
};
void newtonRaphson::leerDatos(){
	cout<<"Ingrese el valor inicial: ";
	cin>>xi;
	cout<<"Ingrese el numero de iteraciones: ";
	cin>>n;
	cout<<"Ingrese el error: ";
	cin>>err;
	cout<<"Iterador(1) | Error(2): ";
	cin>>res;
	cout<<endl;
}
void newtonRaphson::calcRaizDo(){
	int cont = 1;
	do{
		double fxi = f(xi);
		double fpxi = fp(xi);
		double xi1 = x1(xi, fxi, fpxi);
		error = e(xi1, xi);
		if(error>err){
			cout<<"n: "<<cont<<endl;
			cout<<"Xi: "<<xi<<endl;
			cout<<"f(Xi): "<<fxi<<endl;
			cout<<"f'(Xi): "<<fpxi<<endl;
			cout<<"Xi+1: "<<xi1<<endl;
			cout<<"Error: "<<error<<endl<<endl;
			xi = xi1;
			cont++;
		}
		else if(error<err){
			cout<<"La raiz es: "<<xi<<endl;
			break;
		}
	}while (error>err);
}
void newtonRaphson::calcRaizFor(){
	int cont = 1;
	for(int i = 0; i < n; i++){
		double fxi = f(xi);
		double fpxi = fp(xi);
		double xi1 = x1(xi, fxi, fpxi);
		error = e(xi1, xi);
		if(error>err){
			cout<<"n: "<<cont<<endl;
			cout<<"Xi: "<<xi<<endl;
			cout<<"f(Xi): "<<fxi<<endl;
			cout<<"f'(Xi): "<<fpxi<<endl;
			cout<<"Xi+1: "<<xi1<<endl;
			cout<<"Error: "<<error<<endl;
			xi = xi1;
			cont++;
		}
		else if(error<err){
			cout<<"La raiz es: "<<xi<<endl<<endl;
			break;
		}
	}
}
int main(){
	newtonRaphson r1;
	r1.leerDatos();
	if(r1.res== 1){
		r1.calcRaizFor();
	}
	else if(r1.res == 2){
		r1.calcRaizDo();
	}
	else{
		cout<<"Opcion invalida"<<endl;
	}
	return 0;
}
