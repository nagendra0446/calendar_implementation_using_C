/*
THIS IS A C PROGRAM TO CALCULATE AND DISPLAY THE CALENDAR OF A PARTICULAR YEAR.
THIS PROGRAM TAKES YEAR(1753 TO 9999) AS INPUT AND GIVES THE CALENDAR
(ACCORDING TO GREGORIAN CALENDAR) AS THE OUTPUT.

CODE BY: 
NAGENDRA NAINALA
GIT HUB : "https://github.com/nagendra0446"
*/ 

#include<stdio.h>

int key_year(int year)		// FUNCTION TO FIND KEY OF THE GIVEN YEAR.
{
	/*
	KEY OF A YEAR = KEY OF JAN MONTH WHICH IS THE DISPLACEMENT OF '1ST JAN' WITH SUNDAY.
	FOR EXAMPLE:	IF 1ST OF JAN OF A YEAR IS SUNDAY THE KEY IS 0
					IF 1ST OF JAN OF A YEAR IS MONDAY THE KEY IS 1 
	*/

   	int key=1, i=0, offset;

   	for(i=1753; i<year; i++)
	{
		offset = leap(i) ? 2 : 1;
       	key = (key + offset) % 7;
	}
    return key;
}

int leap(int year)			// FUNCTION TO CHECK LEAP YEAR OR NOT.
{
	if((year % 100 != 0 && year%4 != 0) || (year % 100 == 0 && year % 400 != 0))
		return 0;
	else
		return 1;
}

char* month_names[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY"
						, "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

void print_name(int m)		//FUNCTION TO PRINT NAME OF THE MONTH.
{
	printf("\t");   
	printf(month_names[m-1]);
	printf("\n\n");
}



int main()
{
	int i, m, j, s, year, leap_res, key[20];
	int days[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	do
	{
		printf("Enter the year(1753 - 9999) : ");
		scanf("%d", &year);
	}while((year < 1753 || year >9999) && 
		printf("\n\t\t\tCALENDER CANNOT BE CALCULATED BELOW 1753 AND ABOVE 9999\n\n"));
			
	if(leap(year)) 				//FUNCTION TO CHECK LEAP YEAR OR NOT.
		days[2] = 29;
	
	key[1] = key_year(year);	//FUNCTION TO FIND THE KEY OF THE YEAR. 	

	for(i=2;i<=12;i++)
		key[i] = 				// CALCULATING KEY FOR ALL THE MONTHS INTO AN ARRAY "KEY".
			(((days[i-1])%(7)) + key[i-1])%7;	

	//PRINTING FINAL OUTPUT.
	printf("\n\t\t     %d\n\n",year);

	for(m=1;m<=12;m++)
	{
		print_name(m);			//FUNCTION TO PRINT NAME OF THE MONTH.

		printf("\tSu    M    T    W   Th    F   Sa\n");

		printf("\t");
		for(s=1;s<=key[m];s++)
		{
			if(key[m] == 0) 
				break;
			else
				printf("     ");
		}
		
		//printf("\t");
		for(i=1;i<=days[m];i++)
		{
			printf("%2d   ",i);

			if(key[m]==0 && i%7 ==0)
				printf("\n\t");
			if((i%7)==(7-key[m]))
				printf("\n\t");
		}
		printf("\n\n");
	}
}