/*
 * Write a program that determines the day number (1 to 366) in a year for a 
 * date that is provided as input data. As an example, January 1, 1994, is day
 *  1. December 31, 1993 is day 365. December 31, 1996, is day 366, since 1996
 * is a leap year. A year is a leap year if it is divisible by four, except that
 * any year divisible by 100 is a leap year only if it is divisible by 400. Your
 * program should accept the month, day, and year as integers. Include a 
 * function 'leap' that returns 1 if called with a leap year, 0 otherwise. 
 */

#include <stdio.h>

int isLeapYear(int year) {
  if(((year % 4 == 0) & (year % 100 != 0)) || 
     ((year % 100 == 0) & (year % 400 == 0))) {
    printf("%d is a leap year\n", year);
    return 1;
   } else {
    printf("%d is not a leap year\n", year);
    return 0;
   }
}

int monthOutOfBounds(int month) {
  if((month < 1) | (month > 12)) {
    printf("Month is out of bounds\n");
    return 1;
  } else {
    return 0;
  }
}

int dayOutOfBounds(int day, int month, int max_day_vals[]) {
  if((day < 1) | (day > max_day_vals[month-1])) {
    printf(
      "Your chosen month can only have a date value between 1 and %d\n", 
      max_day_vals[month-1]
    );
    return 1;
  } else {
      return 0;
    }
  return 0;
}

int sumOfDaysElapsed(int month, int day, int max_day_vals[]) {
  int total_days_elapsed = 0; 
  int i;
  for(i = 0; (i == 0) | (i < (month-1)); i++) {
    if(month > 1){
      total_days_elapsed = total_days_elapsed + max_day_vals[i];
    }
  }
  total_days_elapsed = total_days_elapsed + day;
  return total_days_elapsed;
}

int main(){
    
  int year_input, 
      month_input, 
      day_input, 
      temp, 
      status, 
      is_leap_year,
      total_days_elapsed;
  int month_out_of_bounds = 1;
  int day_out_of_bounds = 1;
  int days_in_month_arr[] = 
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days_in_month_leap_year_arr[] = 
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int max_date_vals[12];

  printf("Enter the year in numeric format, e.g. 1991\n");
  status = scanf("%d", &year_input);
  while(status != 1){
    while((temp = getchar()) != EOF && temp != '\n');
    printf("Invalid input... please enter a year in numeric format e.g. 1991\n");
    status = scanf("%d", &year_input);
  }

  is_leap_year = isLeapYear(year_input);

  int j;
  if(is_leap_year){
    for(j = 0; j < sizeof(days_in_month_leap_year_arr) / sizeof(int); j++) {
      max_date_vals[j] = days_in_month_leap_year_arr[j];
    }
  } else {
    for(j = 0; j < sizeof(days_in_month_arr) / sizeof(int); j++) {
      max_date_vals[j] = days_in_month_arr[j];
    }
  }

  printf("Enter the month in numeric format as a number between 1 and 12\n");
  status = scanf("%d", &month_input);
  while( (status != 1) | 
        ((month_out_of_bounds = monthOutOfBounds(month_input)) == 1) ){
    while(((temp = getchar()) != EOF && temp != '\n'));
    printf("Enter the month in numeric format as a number between 1 and 12\n");
    status = scanf("%d", &month_input);
  }

  printf("Enter the day in numeric format\n");
  status = scanf("%d", &day_input);
  day_out_of_bounds = dayOutOfBounds(day_input, month_input, max_date_vals);
  while( (status != 1) | (day_out_of_bounds == 1) ){
    while(((temp = getchar()) != EOF && temp != '\n'));
    printf(
      "Enter the day in numeric format. Your specified month in the year %d has a maximum of %d days\n",
      year_input, max_date_vals[month_input-1]
    );
    status = scanf("%d", &day_input);
    day_out_of_bounds = dayOutOfBounds(day_input, month_input, max_date_vals);
  }

  printf("Your date is %d/%d/%d\n", day_input, month_input, year_input);

  total_days_elapsed = sumOfDaysElapsed(month_input, day_input, max_date_vals);
  printf("Total days elapsed in the year is %d\n", total_days_elapsed);
	
  return 0;
}