#include <stdio.h>
void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
int gcd(int a,int b){
        while(a>0&&b>0){
            if(a>b)swap(&a,&b);
            b%=a;
        }
    return a;
}
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,
              int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);
int main() {
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
           &c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);

}

void fraction_adder(int a_numerator, int a_denominator, int b_numerator,int b_denominator,
int *c_numerator_ptr, int *c_denominator_ptr){
    int cd=gcd(a_denominator, b_denominator);
    int lcm=a_denominator*b_denominator/cd;
    int a=lcm/a_denominator;
    int b=lcm/b_denominator;

    a_numerator*=a;
    b_numerator*=b;
    a_numerator+=b_numerator;
    a_denominator*=a;
    

    cd=gcd(a_denominator,a_numerator);

    *c_numerator_ptr=(a_numerator)/cd;
    *c_denominator_ptr=(a_denominator)/cd;
    
}
