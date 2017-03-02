#include <stdio.h>

int main(int argc ,char* argv[]){
        int x = atoi(argv[1]);
        printf("When integer x = %d\n",x);
        printf("((((3x+2)x-5)x-1)x+7)x-6 = ");
        printf("%d\n",((((3*x+2)*x-5)*x-1)*x+7)*x-6);
        return 0;
}

