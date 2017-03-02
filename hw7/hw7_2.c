#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[])
{
	union {
	int n;
	float f;
	char s[32];	
	} num;

	int type;
	type = atoi(argv[1]);
 	
	if(type == 1){
	int  c, k;
	num.n = atoi(argv[2]);

	printf("bit pattern(integer):\n" );
	for (c = 31; c >= 0; c--)
	{
 	k = num.n >> c;
 
	if (k & 1)
  	printf("1");
  	else
  	printf("0");
	}
 
	printf("\n");
	}

	
	if(type == 2){
	
	num.f = atof(argv[2]);
	unsigned u;
	unsigned mask = 0x80000000U;
		 u = *(unsigned*)&num.f;

	printf("bit pattern(float):\n");
	while(mask){
		printf("%d",(u&mask)!= 0U);
		mask>>=1;
	}
	printf("\n");	
	
	}

	if(type == 3){
	float ans;
	int sign, exp, mant;
	int i;
//	char s[32];
	strcpy(num.s,argv[2]);
 
	printf("%s\n",num.s);
	sign = num.s[0] - '0';
	exp = 0;

	for (i = 1; i <= 8; i++)
		exp = exp * 2 + (num.s[i] - '0');
 	
	exp = exp - 127;
 	
	if (exp > -127){
 	mant = 1;  
	exp -= 23;}
  	
	else{
	mant = 0; 
 	exp = -126;
    	exp -= 23;
  	}
 
	for (i = 9; i <= 31; i++)
		mant = mant * 2 + (num.s[i] - '0');
 		ans = mant;
 
 	while (exp > 0)
 		ans *= 2, exp--;
 
  	while (exp < 0)
    		ans /= 2, exp++;
 
  	if (sign) ans = ans * -1;
	
	printf("%.23e\n", ans);

	}
	return 0;

}
