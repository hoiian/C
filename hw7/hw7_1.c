#include <stdio.h>
#include <stdlib.h>

typedef double(*F)(double,int);

double power(double a,int b){
	int i;
	double c=1;
	for(i=0;i<b;i++)
	c = c*a;
	return c;
}

double multiply(double a,int b){
	return a*b;
}

double divide(double a,int b){
	return a/b;
}

double powerpower(F f, double a ,int b,int c){
	double ans=1;
	int i;
	for(i=0;i<c;i++)
	ans = ans * f(a,b);
	return ans;
}

int main(int argc, char* argv[]){
	double x = atof(argv[1]);
	int n = atoi(argv[2]);
	int m = atoi(argv[3]);	
//	printf("x=%f,n=%d,m=%d\n",x,n,m);
	F f = power;
//	printf("power:%f\n",f(x,n));
	printf("%f\n",powerpower(f,x,n,m));
	f = multiply;
        printf("%f\n",powerpower(f,x,n,m));
        f = divide;
        printf("%f\n",powerpower(f,x,n,m));
}


