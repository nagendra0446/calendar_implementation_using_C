/*
THIS IS A C PROGRAM TO CALCULATE AND DISPLAY THE CALENDAR OF A PARTICULAR YEAR.
THIS PROGRAM TAKES YEAR(1753 TO 400000000) AS INPUT AND GIVES THE CALENDAR
(ACCORDING TO GREGORIAN CALENDAR) AS THE OUTPUT.

CODE BY: 
NAGENDRA NAINALA
GIT HUB : "https://github.com/nagendra0446"
*/ 

#include<stdio.h>

int key_year(unsigned int year)		// FUNCTION TO FIND KEY OF THE GIVEN YEAR.
{
	/*
	KEY OF A YEAR = KEY OF JAN MONTH WHICH IS THE DISPLACEMENT OF '1ST JAN' WITH SUNDAY.
	FOR EXAMPLE:	IF 1ST OF JAN OF A YEAR IS SUNDAY THE KEY IS 0
					IF 1ST OF JAN OF A YEAR IS MONDAY THE KEY IS 1 
	*/
	unsigned int i;
   	int key=1, offset;

   	for(i=1753; i<year; i++)
	{
		offset = leap(i) ? 2 : 1;
       	key = (key + offset) % 7;
	}
    return key;
}

int leap(unsigned int year)			// FUNCTION TO CHECK LEAP YEAR OR NOT.
{
	if((year % 100 != 0 && year%4 != 0) || (year % 100 == 0 && year % 400 != 0))
		return 0;
	else
		return 1;
}

int main()
{
	unsigned int year;
	int i, j, m, s, key[12];
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char* month_names[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", 
					"JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
	
	do
	{
		printf("Enter the year(1753 - 40,00,00,000) : ");
		scanf("%u", &year);
		if(year >= 1753 && year <= 400000000)
			break;
		else
		{
			printf("\n\t\t\tCALENDER CAN BE CALCULATED ONLY"); 
			printf("\n\t\t\tBETWEEN 1753 AND 40,00,00,000\n\n");
		}
	}while(1);
		
			
	if(leap(year)) 				//FUNCTION TO CHECK LEAP YEAR OR NOT.
		days[2] = 29;
	
	key[0] = key_year(year);	//FUNCTION TO FIND THE KEY OF THE YEAR. 	

	for(i=1;i<12;i++)			// CALCULATING KEY FOR ALL MONTHS INTO ARRAY "KEY".
		key[i] = (((days[i-1])%(7)) + key[i-1])%7;	

	//PRINTING FINAL OUTPUT.
	printf("\n\tYEAR: %u \n\n",year);

	for(m=1;m<=12;m++)
	{
		printf("\t%s \n\n", month_names[m-1]);

		printf("\tSu    M    T    W   Th    F   Sa\n");

		printf("\t");
		for(s=1;s<=key[m-1];s++)
			printf("     ");
		
		for(i=1;i<=days[m-1];i++)
		{
			printf("%2d   ",i);

			if((i+key[m-1]) % 7 == 0)
				printf("\n\t");
		}
		printf("\n\n");
	}
}