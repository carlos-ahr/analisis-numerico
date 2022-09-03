#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/*
+-----+------+------+---------+---------+--------------+------+---------+--------------+---------+
|  n  |  xi  |  xf  |  f(xi)  |  f(xf)  |  f(xi)f(xf)  |  xm  |  f(xm)  |  f(xi)f(xm)  |  Error  |
+-----+------+------+---------+---------+--------------+------+---------+--------------+---------+
*/
int main(void){
    string sepH = "+-----+------+------+---------+---------+--------------+------+---------+--------------+---------+";
    string sepV = "  |  ";
    string h1, h2, h3, h4, h5, h6, h7, h8, h9, h10;
    h1 = "n";
    h2= "xi";
    h3 = "xf";
    h4 = "f(xi)";
    h5 = "f(xf)";
    h6 = "f(xi)f(xf)";
    h7 = "xm";
    h8 = "f(xm)";
    h9 = "f(xi)f(xm)";
    h10 = "Error";
    cout<<sepH<<endl
        <<"|  "<<h1<<sepV<<h2<<sepV<<h3<<sepV<<h4<<sepV<<h5<<sepV<<h6<<sepV<<h7<<sepV<<h8<<sepV<<h9<<sepV<<h10<<"  |\n"
        <<sepH<<endl; 
    return 0;
}
