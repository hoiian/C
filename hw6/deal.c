#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

void deal(void){
	char rcode[]={'2','3','4','5','6','7','8','9','t','J','Q','K','A'};
	char scode[]={'c','d','h','s'};
	int r,s;
	int p;
	int i=0;
	srand((unsigned) time(NULL));

	for(p=0;p<PLAYER;p++){
	for(r=0;r<RANK;r++){
		rnum[p][r] = 0;
		for(s=0;s<SUIT;s++){
		exist[r][s] = false;
		snum[p][s] = 0;
		}
	}
	}

	for(p=0;p<PLAYER;p++){
	i=0;
	printf("P%d:",p+1);
	while(i<CARD){
	r = rand() % RANK;
	s = rand() % SUIT;
		if(!exist[r][s]){
		rnum[p][r]++;
		snum[p][s]++;
		exist[r][s] = true;
		printf("%c%c ",rcode[r],scode[s]);
		i++;
		}
	}
	printf("\n");
	}

}
