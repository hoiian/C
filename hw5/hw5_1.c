#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

long long func(long long x, long long y, long long z);

int main(int argc, char* argv[]){
	char sg[MAX],sn[MAX];
	int i,leng,lenn,type;
	long long n;
	type = atoi(argv[1]);
	strcpy(sg,argv[2]);
//	strcpy(sn,argv[3]);
	n = atoll(argv[3]);

//        leng = strlen(sg);
//        lenn = strlen(sn);

	long long remainder =0;
	for(i=0; sg[i] != '\0' ; ++i) {
		remainder = (remainder*10 + sg[i] - '0')% n;
	}
        printf("g%%n =  %lld \n", remainder);

	if(type == 0){
	printf("(g+g)%%n = %lld\n",func(remainder*2,1,n));
	
	}

	if(type==1){  //mul  (gxg)
	printf("(gxg)%%n = %lld\n",func(remainder,2,n));
	}

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
