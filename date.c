#include <stdio.h>
#include <string.h>
#include <time.h>
#include "date.h"

static const char *MONTHS[12] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

static const int MONTHS_LENGTH[12] = {
	31,
	28, /* leapness computed in month_length() */
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

static int is_month_valid(int month)
{
	return month >= 1 && month <= 12;
}

static const char *month_str(int month)
{
	if (!is_month_valid(month))
		return NULL;
	return MONTHS[month - 1];
}

void init_date(DATE_T *date)
{
	time_t timer = time(NULL);
	struct tm *current_time = localtime(&timer);

	date->day = current_time->tm_mday;
	date->month = current_time->tm_mon + 1;
	date->year = current_time->tm_year + 1900;
}

void set_date_to(DATE_T *date, int day, int month, int year)
{
	date->day = day;
	date->month = month;
	date->year = year;
}

int date_equal(const DATE_T *d1, const DATE_T *d2)
{
	if (d1->year != d2->year)
		return 0;
	if (d1->month != d2->month)
		return 0;
	if (d1->day != d2->day)
		return 0;
	return 1;
}

int date_less_than(const DATE_T *d1, const DATE_T *d2)
{
	if (d1->year < d2->year)
		return 1;
	if (d1->month < d2->month)
		return 1;
	if (d1->day < d2->day)
		return 1;
	return 0;
}

int date_greater_than(const DATE_T *d1, const DATE_T *d2)
{
	if (d2->year < d1->year)
		return 0;
	if (d2->month < d1->month)
		return 0;
	if (d2->day < d1->day)
		return 0;
	return 1;
}

void format_date(const DATE_T *date, char *str)
{
	const char *month = month_str(date->month);

	sprintf(str, "%s %d, %d", month, date->day, date->year);
}

int leap_year(int year)
{
	if ((year % 4) == 0 && (year % 100) != 0)
		return 1;
	if ((year % 400) == 0)
		return 1;
	return 0;
}

int month_length(int month, int leap)
{
	if (!is_month_valid(month))
		return -1;
	if (month == 2 && leap == 1)
		return 29;
	return MONTHS_LENGTH[month];
}

void next_day(DATE_T *date)
{
	int is_leap_year = leap_year(date->year);

	if (date->day < month_length(date->month, is_leap_year)) {
		date->day++;
		return;
	}
	if (date->month <= 11)
		date->month++;
	else {
		date->year++;
		date->month = 1;
	}
	date->day = 1;
}
