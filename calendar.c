/*
THIS IS A C PROGRAM TO CALCULATE AND DISPLAY THE CALENDAR OF A PARTICULAR YEAR.
THIS PROGRAM TAKES YEAR(1753 TO 9999) AS INPUT AND GIVES THE CALENDAR 
(ACCORDING TO GREGORIAN CALENDAR) AS THE OUTPUT.

GIT HUB REPOSITORY : "https://github.com/Nagendra0446/special_programs.git"

CODE BY: 
NAGENDRA NAINALA
JNTU SULTHANPUR
*/ 


#include<stdio.h>

int key_year(int);		// FUNCTION TO FIND THE KEY OF THE YEAR.
/*
	KEY OF A YEAR = KEY OF JAN MONTH WHICH NOTHING BUT THE DISPLACEMENT OF 1st with Sunday.
	For Example:	If 1st of Jan of a year is Sunday the key is 0
					If 1st of Jan of a year is Monday the key is 1 
*/

int leap(int);			// FUNCTION TO CHECK LEAP YEAR OR NOT.
/*
	THIS IS THE FUNCTION USED BY THE key_year() FUNCTION TO CALCULATE THE KEY
*/


void print_name(int);		//FUNCTION TO PRINT NAME OF THE MONTH.

char* month_names[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY"
						, "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};



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
			
	if(leap(year)) 					//FUNCTION TO CHECK LEAP YEAR OR NOT.
		days[2] = 29;
	
	key[1] = key_year(year);		//FUNCTION TO FIND THE KEY OF THE YEAR. 	

	for(i=2;i<=12;i++)
		key[i] = (((days[i-1])%(7)) + key[i-1])%7;         //CALCULATING KEY FOR ALL THE MONTHS INTO AN ARRAY "KEY".

	//PRINTING FINAL OUTPUT.
	printf("\n\t\t     %d\n\n",year);

	for(m=1;m<=12;m++)
	{
		print_name(m);		//FUNCTION TO PRINT NAME OF THE MONTH.

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




// FUNCTION TO FIND LEAP YEAR OR NOT.

int leap(int year)
{
	if((year % 100 != 0 && year%4 != 0) || (year % 100 == 0 && year % 400 != 0))
		return 0;
		
	else
		return 1;
}



// FUNCTION TO FIND KEY OF THE YEAR.

int key_year(int year)
{
	int year_key[10001];
	int i;

	year_key[1753] = 1;
	
	for(i = 1753;i <= year;i++)
	{

		if(leap(i))
			year_key[i+1] = ((366 % 7) + year_key[i]) % 7;
		else
			year_key[i+1] = ((365 % 7) + year_key[i]) % 7;
	}
	return (year_key[year]);
}




// FUCTION TO PRINT NAME OF THE MONTHS.

void print_name(int m)
{
	printf("\t");   
	printf(month_names[m-1]);
	printf("\n\n");
}

































