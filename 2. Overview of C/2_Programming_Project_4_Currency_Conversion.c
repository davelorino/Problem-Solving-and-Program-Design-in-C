/* Write a program to convert a sum of money in US dollars to British pounds */

#include <stdio.h>
#include <math.h>


int main(){
  float dollar, pound;
  float conversion = 0.6;
  printf("Enter an amount of money in US dollars> \n");
  scanf("%f", &dollar);
  pound = dollar * conversion;
  printf("You have %f GBP\n", pound);
}