//Author: Jacob Somer
//Assignment 6
#include <stdio.h>
#include <stdlib.h>
#include"date.c"


int main(){
	DATE_T *d1, d2, d3;
	char format_str[50];
	d1= malloc(350);
	init_date_1(d1);
	init_date(&d2,30,12,1999);
	init_date(&d3,1,1,2000);

	format_date(*d1, format_str);
	printf("%s","d1: ");
	printf("%s\n", format_str);
	format_date(d2, format_str);
	printf("%s","d2: ");
	printf("%s\n", format_str);
	format_date(d3, format_str);
	printf("%s","d3: ");
	printf("%s\n", format_str);
	printf("%s\n","");

 	printf("%s\n",format_str);
 	if (date_less_than(*d1,d2)==1){
 	    printf("%s\n","d1 < d2? TRUE");}
 	else{
 	    printf("%s\n","d1 < d2? FALSE");
 	}
 	if (date_less_than(d2,d3)==1){
 	    printf("%s\n","d2 < d3? TRUE");}
 	else{
 	    printf("%s\n","d2 < d3? FALSE");
 	}
 	printf("%s\n","");
 	next_day(&d2);
 	format_date(d2,format_str);
 	printf("%s","next day d2: ");
 	printf("%s\n",format_str);
 	if (date_less_than(d2,d3)==1){
 	    printf("%s\n","d2 < d3? TRUE");}
 	else{
 	    printf("%s\n","d2 < d3? FALSE");}
 	if (date_equal(d2,d3)==1){
 	    printf("%s\n","d2 = d3? TRUE");}
 	else{
 	    printf("%s\n","d2 = d3? FALSE");}
 	if (date_less_than(d2,d3)==0){
 	    printf("%s\n","d2 > d3? TRUE");}
 	else{
 	    printf("%s\n","d2 > d3? FALSE");}
 	printf("%s\n","");
 	next_day(&d2);
 	format_date(d2,format_str);
 	printf("%s","next day d2: ");
 	printf("%s\n",format_str);
 	if (date_equal(d2,d3)==1){
 	    printf("%s\n","d2 = d3? TRUE");}
 	else{
 	    printf("%s\n","d2 = d3? FALSE");}
 	printf("%s\n","");

 	printf("%s","initialized d1 to ");
 	init_date(d1,28,2,1529);
 	format_date(*d1,format_str);
 	printf("%s\n",format_str);
 	next_day(d1);
 	format_date(*d1,format_str);
 	printf("%s","next day d1: ");
 	printf("%s\n",format_str);
 	printf("%s\n","");

 	printf("%s","initialized d1 to ");
 	init_date(d1,28,2,1460);
 	format_date(*d1,format_str);
 	printf("%s\n",format_str);
 	next_day(d1);
 	format_date(*d1,format_str);
 	printf("%s","next day d1: ");
 	printf("%s\n",format_str);
 	printf("%s\n","");

 	printf("%s","initialized d1 to ");
 	init_date(d1,28,2,1700);
 	format_date(*d1,format_str);
 	printf("%s\n",format_str);
 	next_day(d1);
 	format_date(*d1,format_str);
 	printf("%s","next day d1: ");
 	printf("%s\n",format_str);
 	printf("%s\n","");

 	printf("%s","initialized d1 to ");
 	init_date(d1,28,2,1600);
 	format_date(*d1,format_str);
 	printf("%s\n",format_str);
 	next_day(d1);
 	format_date(*d1,format_str);
 	printf("%s","next day d1: ");
 	printf("%s\n",format_str);
 	printf("%s\n","");
	return (0);
}
