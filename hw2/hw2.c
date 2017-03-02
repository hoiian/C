#include <stdio.h>

int main(int argc ,char* argv[])
{
	int year = atoi(argv[1]);
        int week, d1, d2, d3;
	int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	char *months[]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};

        if(year% 4 == 0 && year%100 != 0 || year%400 == 0)
        {  days[2] = 29;  }
        else
        {  days[2] = 28;  }
	//check if it was leapyear.

	d1 = (year - 1)/ 4;
	d2 = (year - 1)/ 100;
	d3 = (year - 1)/ 400;
	week = (year + d1 - d2 + d3) %7;
	//omit 356days because 365=52*7+1
	//week means whatday at 01/01

	if(argc == 2){
	int month, d;
	for ( month = 1; month <= 12; month++ )
	{
		printf("\n%s,%d", months[month],year);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		for ( d = 1; d <= week ; d++ )
		{
			printf("     ");
		}
		
		for ( d = 1; d <= days[month]; d++ )
		{
			printf("%3d", d);
			if ( (d + week) % 7 > 0 ) printf("  ");
			else	printf("\n");
		}
		
		printf("\n\n");
		week = ( week + days[month] ) % 7;
	}
	}
	//it shows the whole year

        if( argc == 3) {
	int m  = atoi(argv[2]), d, i;

	for ( i=1; i < m; i++){ week = (week + days[i] ) % 7;  }        

		printf("\n%s,%d",months[m],year);
                printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

                for ( d = 1; d <= 1 + week * 5; d++ )
                {   printf(" ");    }

                for ( d = 1; d <= days[m]; d++ )
                {
                        printf("%2d", d );

                        if ( ( d + week ) % 7 > 0 )
                                printf("   " );
                        else
                                printf("\n " );
           	 }
		printf("\n\n");
	}
	//it shows the specific month.
}
