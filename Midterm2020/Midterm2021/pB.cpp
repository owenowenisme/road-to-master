#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
//#define int long long
double cube(double a){
    return pow(a,3);
}
double cuboid(double a,double b,double c){
    return a*b*c;
}
double cylinder(double a,double b){
    return a*a*3.14*b;
}
double tetrahedron(double a){
    return pow(a,3)*sqrt(2)/12;
}
int main(){
    int mode;double a,b,c;
    scanf("%d",&mode);
    if(mode==1){
        scanf("%lf",&a);
        printf("%.2lf",cube(a));
    }
    if(mode==2){
        scanf("%lf %lf %lf",&a,&b,&c);
        printf("%.2lf",cuboid(a,b,c));
    }
    if(mode==3){
        scanf("%lf %lf",&a,&b);
        printf("%.2lf",cylinder(a,b));
    }
    if(mode==4){
        scanf("%lf",&a);
        printf("%.2lf",tetrahedron(a));
    }
    
    return 0;
}