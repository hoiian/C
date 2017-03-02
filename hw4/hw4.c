#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keyin(int N,float M[][N]);
void randomnum(int N, float M[][N]);
void add(int N, float M1[][N], float M2[][N]);
void mul(int N, float M1[][N], float M2[][N]);
float det(int n, float a[][n]);


int main(int argc, char* argv[]){
	int n , func, mart;
        n = atoi(argv[1]);
        func = atoi(argv[2]);
        mart = atoi(argv[3]);

        float result[n][n], M1[n][n], M2[n][n], R[n][n];
	
	if (mart == 1) { //keyin(); 
		if(func != 2){
		keyin(n,M1);
		keyin(n,M2);
		} else{
		keyin(n,R);
		}
	}	

	if (mart == 0){   //random()
		srand(time(NULL));
		if(func != 2){
		randomnum(n,M1);
		randomnum(n,M2);
		} else{
		randomnum(n,R);
		}
	}

	switch (func) {
	case 0: add(n,M1,M2);
		break;
	case 1: mul(n,M1,M2);
		break;
	case 2: printf("Determinant:%.0f\n",det(n,R)); 
		break;
	default: printf("WRONG. Please enter 0,1or2.");
		 break;
	}
	return 0;
}

void keyin(int N, float M[][N]){
	int i,j;
	printf("please enter %d number(s):",N*N);
        for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        scanf("%f",&M[i][j]);

        printf("The Matrix you entered:");
        for(i=0;i<N;i++) {
        printf("\n");
        for(j=0;j<N;j++)
        printf("%4.0f ", M[i][j]);}
        printf("\n");

}

void randomnum(int N, float M[][N]){
        int i, j;
        printf("\nRandom Number(s):");
        for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        M[i][j] = rand() % 100 + 1;
                
        for(i=0;i<N;i++) {
	printf("\n");
        for(j=0;j<N;j++)
        printf("%4.0f ", M[i][j]);}
        printf("\n");
}

void add(int N, float M1[][N], float M2[][N]){
        int i, j;
	float result[N][N];
        printf("\nThe Sum:");
        for(i=0;i<N;i++){
	printf("\n");
        for(j=0;j<N;j++){
                result[i][j] = M1[i][j] + M2[i][j];
                printf("%4.0f ", result[i][j]);
                }
	}
        printf("\n");
}

void mul(int N, float M1[][N], float M2[][N]){
	int i,j,k;
	float result[N][N];
	printf("\nThe Multiplication:");
	for(i=0; i<N; i++){
	printf("\n");
	for(j=0; j<N; j++){
	    result[i][j] = 0;
		for(k=0; k<N; k++)	
		{ result[i][j] = result[i][j] + (M1[i][k] * M2[k][j]); }
	    printf("%4.0f ", result[i][j]);
	    }
	}
	printf("\n");
}


float det( int n, float a[][n] )
{
	float b[n-1][n-1] ;     
	int i = 0, j = 0;
	float sum = 0;         
	int x=0, c=0, p=0;               

	if(n == 1)  return a[0][0];

	for(i = 0;i < n; i++){
        for(c = 0;c < n-1; c++){
            for(j = 0;j < n-1;j++)
            {
                if (c < i) 
		p = 0;            
                else   
		p = 1;
               
		b[c][j] = a[c+p][j+1];
            }
        }

        if(i % 2 == 0)            
        x = 1;
        else                       
        x = (-1);
    
      sum += a[i][0] * det(n - 1, b ) * x;     
//	printf("%.0f\n",det(n-1,b));
    }

    return sum;                
}

