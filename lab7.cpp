#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
double f(double x, double y, double d_y, double d2_y){
return sin(x) + 4.0 * y - 4.0 * d_y + 5 * d2_y;
}
int main(){
fstream f1,f2,f3;
//double e = 0.01;
//double p2_y1 = 0, p_y1 = 0, y1 = 0;
int n=10000;
int p = 256;
//double x1=0,x2=2;
//double y11, d_y11, d2_y11, h1;
double x[n],y[n], d_y[n], d2_y[n];
//double h=(x2-x1)/n;
double h = 0.1/p;
int i = 0;
x[0] = 0; y[0] = 1.0; d_y[0] = 0; d2_y[0] = 0;
//y1[0] = 1.0; p_y1[0] = 0; p2_y1[0] = 0;
 do{
    x[i+1] = x[i] + h;
    y[i+1] = y[i] + h * d_y[i];
    d_y[i+1] = d_y[i] + h * d2_y[i];
    d2_y[i+1] = d2_y[i] + h * f(x[i], y[i], d_y[i], d2_y[i]);
    y[i+1] = y[i] + (h/2.0) * (d_y[i] + d_y[i+1]);
    d_y[i+1] = d_y[i] + (h/2.0) * (d2_y[i] + d2_y[i+1]);
    d2_y[i+1] = d2_y[i] + (h/2.0) * (f(x[i], y[i], d_y[i], d2_y[i]) + f(x[i+1], y[i+1], d_y[i+1], d2_y[i+1]));
    i++;
}while(x[i] < 2.0);
    f1.open("y.txt", ios::out);f2.open("d_y.txt", ios::out);f3.open("d2_y.txt", ios::out);
    for (int j = 0; j < i + 1; j+=p){
        if(f1){f1 << x[j] << "   " << y[j] << endl;}
        if(f2){f2 << x[j] << "   " << d_y[j] << endl;}
        if(f3){f3 << d_y[j] << "   " << d2_y[j] << endl;}
        }
    f1.close();f2.close();f3.close();
    return 0;
}
