#include <stdio.h>
#include <stdlib.h>

long long func(long long x, long long y, long long z); 

int main(int argc, char* argv[]){
	long long g,h,n;
	g=atol(argv[1]);
	h=atol(argv[2]);
	n=atol(argv[3]);

	printf("ANS = %lld \n", func(g,h,n));
	return 0;
}

long long func(long long x, long long y, long long z){  // compute = x^y % z
	long long ans = 1;
	while(y){
		if( y & 1 ) {ans = ans * x % z;}
		x = x * x % z;
		y = y / 2;
	}
	return ans;
}
