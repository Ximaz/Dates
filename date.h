#ifndef HEAD_H
#define HEAD_H

typedef struct DATE_T {
   int day;
   int month;
   int year;
} DATE_T;

void init_date(DATE_T *date);

void set_date_to(DATE_T *date, int day, int month, int year);

int date_equal(const DATE_T *d1, const DATE_T *d2);

int date_less_than(const DATE_T *d1, const DATE_T *d2);

int date_greater_than(const DATE_T *d1, const DATE_T *d2);

void format_date(const DATE_T *date, char *str);

int leap_year(int year);

int month_length(int month, int leap);

void next_day(DATE_T *date);

#endif
