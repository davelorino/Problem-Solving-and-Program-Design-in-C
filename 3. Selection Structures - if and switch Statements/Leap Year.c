/*
 * Write a program that takes day, month and year as user input, returns the number of elapsed days in the year on that date, and whether or not 
 * that date belongs to a leap year. 
 */

#include <stdio.h>

#define JAN 31
#define FEB 28 
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 30 
#define JUL 31
#define AUG 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31

void leap_year(int day, int month, int year);

int main(){
  int day, month, year;
  
  printf("Enter the month, day and year (in that order) separated by spaced>\n");
  scanf("%d %d %d", &month, &day, &year);
  
  leap_year(day, month, year);
  
  
  
}

void leap_year(int day, int month, int year){
  int leap_year = 0;
  if(year % 100 == 0 && year % 400 == 0){
    printf("%d is a leap year", year);
    leap_year = 1;
  }
  else if(year % 100 != 0 && year % 4 == 0){
    printf("%d is a leap year", year);
    leap_year = 1;
  } 
  else{
    printf("%d is not a leap year", year);
  }
  
  
  
  printf()
}