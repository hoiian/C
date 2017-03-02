#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

void det(void){
	int consec[PLAYER] = {0};
	int p,r,s;
	bool straight[PLAYER]={false},flush[PLAYER]={false},four[PLAYER]={false},three[PLAYER]={false};
	int pairs[PLAYER]={0};
//        int snum[4][4] = {{5,0,0,0},{0,0,5,0},{0,5,0,0},{1,2,1,1}};

	for(p=0;p<PLAYER;p++){ 
		for(s=0;s<SUIT;s++) //flush
		if(snum[p][s] == CARD) flush[p] = true;
	
		r = 0;   //straight
		consec[p] = 0;
		while(rnum[p][r] == 0 ) r++;
		for(;(r<RANK && (rnum[p][r] == 1)); r++)
		{consec[p]++;}
		if(consec[p] == CARD){ straight[p] = true;}

		pairs[p] = 0;
		for(r=0;r<RANK;r++){
		if(rnum[p][r] == 4) four[p] = true;
	        if(rnum[p][r] == 3) three[p] = true;
	        if(rnum[p][r] == 2) pairs[p]++;
		}
	}

/************** result ****/
	int i,j;
	int score[PLAYER] = {0};
	int max,winner=0,maxnum=0;
	char *scode[] = {"","High Card","Pair","Two pairs","Three of a kind","Straight","Flush","Full house","Four of a kind","Straight flush"};
	int mscore[PLAYER] = {0};
	int maxcard_r[PLAYER] = {0};
	int mmaxcard_r;

	for(p=0;p<PLAYER;p++){
//	printf("P%d:",p+1);
	if(straight[p] && flush[p]) 	{score[p] = 9;}
	else if(four[p])  		{score[p] = 8;}
        else if(three[p] && pairs[p] == 1)  {score[p] = 7;}
        else if(flush[p]) 		{score[p] = 6;}
        else if(straight[p]) 		{score[p] = 5;}
        else if(three[p]) 		{score[p] = 4;}
        else if(pairs[p] == 2) 		{score[p] = 3;}
        else if(pairs[p] == 1) 		{score[p] = 2;}
	else				{score[p] = 1;}
//	printf("%s\n",scode[score[p]]);
	}
	
	max = score[0];
	for(p=0;p<PLAYER;p++){
	if(score[p]>max){
	winner = p;
	max = score[p];
	}
	}
	//same score
	for(p=0;p<PLAYER;p++){
		if(score[p] == max ){
		mscore[p] = 1; 
		maxnum++;
		}
	}

//	printf("maxnumber:%d\n",maxnum);
	if(maxnum>1){
	if(max == 1){
       		for(p=0;p<PLAYER;p++){
		r = RANK-1;
		while(rnum[p][r]==0) {r--;} maxcard_r[p] = r;
//		printf("P%d max card : %d\n",p+1,maxcard_r[p]);
		}
			mmaxcard_r = maxcard_r[0];
			for(i=0;i<PLAYER;i++){
			if(maxcard_r[i] > mmaxcard_r) 
			{mmaxcard_r = maxcard_r[i];
			winner = i;
			}
			}
	/*		
			if(maxcard_r[i] == mmaxcard_r)
			{s=3;
			while(!exist[mmaxcard_r][s])s--;
			maxcard_s[p] = s;
			}
			for(i=0;i<PLAYER;i++){
				if(maxcard_r[i] == mmaxcard_r)
				//	snum[i][s]
	*/
			
	}

	if(max == 2){
		for(p=0;p<PLAYER;p++){
		for(r=0;r<RANK;r++)
		if(rnum[p][r]==2) maxcard_r[p] = r;
//		printf("P%d max card : %d\n",p+1,maxcard_r[p]);
		}
                        mmaxcard_r = maxcard_r[0];
                        for(i=0;i<PLAYER;i++){
                        if(maxcard_r[i] > mmaxcard_r)
                        {mmaxcard_r = maxcard_r[i];
                        winner = i;
			}
			/*	else if(maxcard_r[i] == mmaxcard_r)
				{
				
				}
			*/
			}
	}

	if(max == 3){ //two pairs
                for(p=0;p<PLAYER;p++){
                r = RANK-1;
		while(rnum[p][r] != 2) r--;
		maxcard_r[p] = r;
  //              printf("P%d max card : %d\n",p+1,maxcard_r[p]);		
		}

                        mmaxcard_r = maxcard_r[0];
                        for(i=0;i<PLAYER;i++){
                        if(maxcard_r[i] > mmaxcard_r)
                        {mmaxcard_r = maxcard_r[i];
                        winner = i;
                        }
                        }

	}

	if(max == 4 || max == 7){ //three
                for(p=0;p<PLAYER;p++){
                for(r=0;r<RANK;r++)
                if(rnum[p][r]==3) maxcard_r[p] = r;
//                printf("P%d max card : %d\n",p+1,maxcard_r[p]);
                }

                        mmaxcard_r = maxcard_r[0];
                        for(i=0;i<PLAYER;i++){
                        if(maxcard_r[i] > mmaxcard_r)
                        {mmaxcard_r = maxcard_r[i];
                        winner = i;
                        }
                        }
	}

	if(max == 5 || max == 9){ //straight
                for(p=0;p<PLAYER;p++){
                r = RANK-1;
                while(rnum[p][r] == 0 ) r--;
                maxcard_r[p] = r;
    //            printf("P%d max card : %d\n",p+1,maxcard_r[p]);
                }

                        mmaxcard_r = maxcard_r[0];
                        for(i=0;i<PLAYER;i++){
                        if(maxcard_r[i] > mmaxcard_r)
                        {mmaxcard_r = maxcard_r[i];
                        winner = i;
                        }
                        }

	}

	if(max == 6){ //flush
                for(p=0;p<PLAYER;p++){
                for(s=0;r<SUIT;s++)
                if(snum[p][s]==5) maxcard_r[p] = s;
  //              printf("P%d max card : %d\n",p+1,maxcard_r[p]);
                }
                        mmaxcard_r = maxcard_r[0];
                        for(i=0;i<PLAYER;i++){
                        if(maxcard_r[i] > mmaxcard_r)
                        {mmaxcard_r = maxcard_r[i];
                        winner = i;
                        }
                        }

	}

	if(max == 8 ){ //four
	 for(p=0;p<PLAYER;p++){
                for(r=0;r<RANK;r++)
                if(rnum[p][r]==4) maxcard_r[p] = r;
//                printf("P%d max card : %d\n",p+1,maxcard_r[p]);
                }

                        mmaxcard_r = maxcard_r[0];
                        for(i=0;i<PLAYER;i++){
                        if(maxcard_r[i] > mmaxcard_r)
                        {mmaxcard_r = maxcard_r[i];
                        winner = i;
                        }
                        }
	}

	}

	printf("Winner: P%d - %s\n",winner+1,scode[max]);
}
