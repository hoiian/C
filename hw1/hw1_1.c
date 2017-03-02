#include <stdio.h>

int main(){
	int r=10;
	float v;
	v = 4.0f/3.0f*3.14159*r*r*r;
	printf("The volume of a sphere with a 10-meter radius is ");
	printf("%.2fcubic metre\n",v);
	return 0;
}
