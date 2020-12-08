#ifndef HEAD_H
#define HEAD_H

typedef struct DATE_T {
   int day;
   int month;
   int year;
}DATE_T;


static void init_date (DATE_T *date, int day, int month, int year);

static void init_date_1(DATE_T*date);

static int date_equal(DATE_T date1, DATE_T date2);

static int date_less_than(DATE_T date1, DATE_T date2);

static char *month_str (int month);

static void format_date (DATE_T date, char *str);

static int leap_year (int year);

static int month_length (int month, int leap);

static void next_day (DATE_T *date);

#endif
