#include <stdio.h>

int main(int argc, char* argv[]){
        int x = atoi(argv[1]);
        printf("Please enter a dollar amount:%d\n",x);
    
        printf("$20 bills:%d\n",x/20);
        printf("$10 bills:%d\n",(x%20)/10);
	printf("$5  bills:%d\n",((x%20)%10)/5);
        printf("$1  bills:%d\n",((x%20)%10)%5);
        return 0;
}

