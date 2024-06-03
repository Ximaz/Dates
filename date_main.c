/**
 * @author Jacob Somer
 * @brief Assignment 6
 */
#include <stdio.h>
#include "date.h"

static void print_date(const char *id, const DATE_T *date)
{
	char format[19] = { 0 };

	format_date(date, format);
	printf("%s %s\n", id, format);
}

static const char *str_date_less_than(const DATE_T *d1, const DATE_T *d2)
{
	if (date_less_than(d1, d2) == 1)
		return "TRUE";
	return "FALSE";
}

static const char *str_date_greater_than(const DATE_T *d1, const DATE_T *d2)
{
	if (date_greater_than(d1, d2) == 1)
		return "TRUE";
	return "FALSE";
}

static const char *str_date_equal(const DATE_T *d1, const DATE_T *d2)
{
	if (date_equal(d1, d2) == 1)
		return "TRUE";
	return "FALSE";
}

int main()
{
	DATE_T d1 = { 0 };
	DATE_T d2 = { 0 };
	DATE_T d3 = { 0 };

	init_date(&d1);
	set_date_to(&d2, 30, 12, 1999);
	set_date_to(&d3, 1, 1, 2000);

	print_date("d1:", &d1);
	print_date("d2:", &d2);
	print_date("d3:", &d3);
	printf("\n");

	printf("d1 < d2 ? %s\n", str_date_less_than(&d1, &d2));
	printf("d2 < d3 ? %s\n", str_date_less_than(&d2, &d3));
	printf("\n");

	next_day(&d2);
	print_date("next day d2", &d2);
	printf("d2 < d3 ? %s\n", str_date_less_than(&d2, &d3));
	printf("d2 = d3 ? %s\n", str_date_equal(&d2, &d3));
	printf("d2 > d3 ? %s\n", str_date_greater_than(&d2, &d3));
	printf("\n");

	next_day(&d2);
	print_date("next day d2", &d2);
	printf("d2 = d3 ? %s\n", str_date_equal(&d2, &d3));
	printf("\n");

	set_date_to(&d1, 28, 2, 1529);
	print_date("initialized d1 to", &d1);
	next_day(&d1);
	print_date("next day d1", &d1);
	printf("\n");

	set_date_to(&d1, 28, 2, 1460);
	print_date("initialized d1 to", &d1);
	next_day(&d1);
	print_date("next day d1", &d1);
	printf("\n");

	set_date_to(&d1, 28, 2, 1700);
	print_date("initialized d1 to", &d1);
	next_day(&d1);
	print_date("next day d1", &d1);
	printf("\n");

	set_date_to(&d1, 28, 2, 1600);
	print_date("initialized d1 to", &d1);
	next_day(&d1);
	print_date("next day d1", &d1);
	printf("\n");

	return 0;
}
