/*************************************
*學號:F34035031
*姓名:黃凱欣
*編譯方式: gcc hw3_1.c -o hw3_1
*執行方式:./hw3_2 00000100000000000000000000000
*程式功課:利用IEEE-745的方式把binary的轉成浮點數,且要用%.23e的方式輸出
*更新日期:2016/11/1
**************************************/

#include <stdio.h>

int main(int argc, char*argv[])
{

	float hw(char s[32]){

	float ans;
	int sign, exp, mant; //分三段
	int i;
 
	sign = s[0] - '0';
	exp = 0;

	for (i = 1; i <= 8; i++)
		exp = exp * 2 + (s[i] - '0');
 	
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
		mant = mant * 2 + (s[i] - '0');
 		ans = mant;
 
 	while (exp > 0)
 		ans *= 2, exp--;
 
  	while (exp < 0)
    		ans /= 2, exp++;
 
  	if (sign) ans = ans * -1;

	return ans;
	}
 

	printf("%s :\n",argv[1]);
	printf("%.23e\n", hw(argv[1]));

	return 0;
}
