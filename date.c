#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include"date.h"


void init_date (DATE_T *date, int day, int month, int year) {
	date->day=day;
	date->month=month;
	date->year=year;
}


void init_date_1(DATE_T*date){


	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	date->day=tm.tm_mday;
	date->month=tm.tm_mon+1;
	int tmp;
	tmp=tm.tm_year;
	tmp=tmp+1900;
	date->year=tmp;
}

int date_equal(DATE_T date1, DATE_T date2){
	if (date1.day=date2.day && date1.month==date2.month && date1.year==date2.year){
		return(1);
	}
	else{
		return(0);
	}
}

int date_less_than(DATE_T date1, DATE_T date2){
	if (date1.year<date2.year){
		return(1);
	}
	else if(date1.year==date2.year){
		if(date1.month<date2.month){
			return(1);
		}
		else if (date1.month==date2.month){
			if(date1.day<date2.day){
				return (1);
			}
		}
	}
	else{
		return(0);
	}

}

static char *month_str (int month){
	if (month==1){
	    char *tmp = malloc(100);
	    strcpy(tmp, "January");
	    return (tmp);
	}
	else if (month==2){
	    char *tmp = malloc(100);
	    strcpy(tmp, "February");
	    return tmp;
	}
	else if (month==3){
	     char *tmp = malloc(100);
	    strcpy(tmp, "March");
	    return tmp;
	}
	else if (month==4){
		char *tmp = malloc(100);
	    strcpy(tmp, "April");
	    return tmp;
		}
	else if (month==5){
		char *tmp = malloc(100);
	    strcpy(tmp, "May");
	    return tmp;
		}
	else if (month==6){
		char *tmp = malloc(100);
	    strcpy(tmp, "June");
	    return tmp;
		}
	else if (month==7){
		char *tmp = malloc(100);
	    strcpy(tmp, "July");
	    return tmp;
		}
	else if (month==8){
		char *tmp = malloc(100);
	    strcpy(tmp, "August");
	    return tmp;
		}
	else if (month==9){
		char *tmp = malloc(100);
	    strcpy(tmp, "September");
	    return tmp;
		}
	else if (month==10){
		char *tmp = malloc(100);
	    strcpy(tmp, "October");
	    return tmp;
		}
	else if (month==11){
		char *tmp = malloc(100);
	    strcpy(tmp, "November");
	    return tmp;
		}
	else{
		char *tmp = malloc(100);
	    strcpy(tmp, "December");
	    return tmp;
		}

}

void format_date (DATE_T date, char *str){
	strcpy(str,month_str(date.month));
	strcat(str," ");
	char day[2];
    sprintf(day, "%d", date.day);
	strcat(str,day);
	strcat(str,", ");
	char year[4];
	sprintf(year, "%d", date.year);
	strcat(str, year);
}

static int leap_year (int year){
	if (year%4==0 && (year%100!=0)){
		return(1);
	}
	else if (year%400==0){
		return(1);
	}
	else{
		return(0);
	}
}

static int month_length (int month, int leap){
	if (month==4 || month==6 || month==9 || month==11){
		return (30);
	}
	else if (month==2){
		if (leap==1){
			return (29);
		}
		return (28);
	}
	else{
		return (31);
	}
}

void next_day (DATE_T *date){
    int x=leap_year(date->year);
	if (date->month<=11){
		if (month_length(date->month,x)==date->day){
			date->month++;
			date->day=1;
		}
		else{
			date->day++;
		}
	}
	else{

		if (month_length(date->month,x)==date->day){
			date->year++;
			date->month=1;
			date->day=1;
		}
		else{
			date->day++;
		}
	}
}
