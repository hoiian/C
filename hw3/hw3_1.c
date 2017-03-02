/*************************************
*學號:F34035031
*姓名:黃凱欣
*編譯方式: gcc hw3_1.c -o hw3_1
*執行方式:./hw3_1 1 -1
	  ./hw3 2 100
*程式功課:選擇不同的format(interger/float),print出bit pattern
*更新日期:2016/11/1
**************************************/

#include <stdio.h>
#include <stdlib.h>
 
int main( int argc, char* argv[])
{
	int n, c, k, type;
	type = atoi(argv[1]);
	n = atoi(argv[2]);
 	
	if(type == 1){
	printf("bit pattern(integer):\n" );
	for (c = 31; c >= 0; c--)
	{
 	k = n >> c;
 
	if (k & 1)
  	printf("1");
  	else
  	printf("0");
	}
 
	printf("\n");
	}

	
	if(type == 2){
	
	float f = atof(argv[2]);
	unsigned u;
	unsigned mask = 0x80000000U;
		 u = *(unsigned*)&f;

	printf("bit pattern(float):\n");
	while(mask){
		printf("%d",(u&mask)!= 0U);
		mask>>=1;
	}
	printf("\n");	

	}
	return 0;

}
