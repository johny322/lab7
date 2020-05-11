// Example program
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
double dif_ur(double x, double y, double p_y, double p2_y){
return sin(x) + 4.0 * y - 4.0 * p_y + 5 * p2_y;
}
int main()
{
fstream f1,f2,f3;
double e = 0.01;    
double p2_y1 = 0, p_y1 = 0, y1 = 0;
int n=20;
double x1=0,x2=2;
double x[21],y[21],p_y[21],p2_y[21];
double h=(x2-x1)/n;


y[0] = 1.0;
x[0] = x1;
p_y[0] = 0;
p2_y[0] = 0;
for(int i=0;i<n+1;i++)
{
x[i+1]=x[i]+h;
do{
p2_y[i+1] = p2_y[i] + h * dif_ur(x[i],y[i],p_y[i], p2_y[i]);
h /= 2;
p2_y1 = p2_y[i] + h * dif_ur(x[i],y[i],p_y[i], p2_y[i]);
}while ( fabs(p2_y[i+1] - p2_y1) >= e);
h=(x2-x1)/n;
do{
p_y[i+1] = p_y[i] + h * dif_ur(x[i],y[i],p_y[i], p2_y[i]);
h /= 2;
p_y1 = p_y[i] + h * dif_ur(x[i],y[i],p_y[i], p2_y[i]);
}while ( fabs(p_y[i+1] - p_y1) >= e);
h=(x2-x1)/n;
do{
y[i+1] = y[i] + h * dif_ur(x[i],y[i],p_y[i], p2_y[i]);
h /= 2;
y1 = y[i] + h * dif_ur(x[i],y[i],p_y[i], p2_y[i]);
}while ( fabs(y[i+1] - y1) >= e);
h=(x2-x1)/n;
do{
    p2_y[i+1] = p2_y[i] + (h / 2) * (dif_ur(x[i+1],y[i+1],p_y[i+1], p2_y[i+1]) + dif_ur(x[i],y[i],p_y[i], p2_y[i]));
    h /= 2;
    p2_y1 = p2_y[i] + (h / 2) * (dif_ur(x[i+1],y[i+1],p_y[i+1], p2_y[i+1]) + dif_ur(x[i],y[i],p_y[i], p2_y[i]));
}while ( fabs(p2_y[i+1] - p2_y1) >= e);
h = (x2-x1)/n;

do{
p_y[i+1] = p_y[i] + (h / 2) * (dif_ur(x[i+1],y[i+1],p_y[i+1], p2_y[i+1]) + dif_ur(x[i],y[i],p_y[i], p2_y[i]));
h /= 2;
p_y1 = p_y[i] + (h / 2) * (dif_ur(x[i+1],y[i+1],p_y[i+1], p2_y[i+1]) + dif_ur(x[i],y[i],p_y[i], p2_y[i]));
}while ( fabs(p_y[i+1] - p_y1) >= e);
h=(x2-x1)/n;

do{
y[i+1] = y[i] + (h / 2) * (dif_ur(x[i+1],y[i+1],p_y[i+1], p2_y[i+1]) + dif_ur(x[i],y[i],p_y[i], p2_y[i]));
h /= 2;
y1 = y[i] + (h / 2) * (dif_ur(x[i+1],y[i+1],p_y[i+1], p2_y[i+1]) + dif_ur(x[i],y[i],p_y[i], p2_y[i]));
}while ( fabs(y[i+1] - y1) >= e);
h=(x2-x1)/n;

}
f1.open("y.txt", ios::out);
for(int i = 0; i < n+1; i++){
    if (f1){f1 << x[i] << "    " << y[i] << endl;}
}
f1.close();

f2.open("p_y.txt", ios::out);
for(int i = 0; i < n+1; i++){
    if (f2){f2 << x[i] << "    " << p_y[i] << endl;}
}
f2.close();

f3.open("y_and_p_y.txt", ios::out);
for(int i = 0; i < n+1; i++){
    if (f3){f3 << y[i] << "    " << p_y[i] << endl;}
}
f3.close();
return 0;
}
