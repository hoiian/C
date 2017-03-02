#include <stdio.h>
int main(int argc, char* argv[]){
        int x = atoi(argv[1]);
        printf("When integer x = %d\n", x);
        printf("3x^5+2x^4-5x^3-x^2+7x-6 = ");
        printf("%d\n",(3*x*x*x*x*x)+(2*x*x*x*x)-(5*x*x*x)-(x*x)+(7*x)-6);
        return 0;
}
