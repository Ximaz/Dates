# Date program

This project aims to demonstrate proficiency in C programming.

# Available date functions

```c
/**
 * @brief Initialise the date using the computer system's clock.
 */
void init_date(DATE_T *date);

/**
 * @brief Modify the date to the specified day, month and year.
 */
void set_date_to(DATE_T *date, int day, int month, int year);

/**
 * @brief Returns whether or not two dates are equal.
 */
int date_equal(const DATE_T *d1, const DATE_T *d2);

/**
 * @brief Returns whether d1 < d2 or not.
 */
int date_less_than(const DATE_T *d1, const DATE_T *d2);

/**
 * @brief Returns whether d1 > d2 or not.
 */
int date_greater_than(const DATE_T *d1, const DATE_T *d2);

/**
 * @brief Format the date's attributes into 'str'.
 *
 * The buffer must be large enough (19 bytes should be the most required).
 */
void format_date(const DATE_T *date, char *str);

/**
 * @brief Returns whether or not the year is leap.
 */
int leap_year(int year);

/**
 * @brief Returns the number of days for the specified month.
 */
int month_length(int month, int leap);

/**
 * @brief Compute the next date by updating day, month and year accordingly.
 */
void next_day(DATE_T *date);
```
