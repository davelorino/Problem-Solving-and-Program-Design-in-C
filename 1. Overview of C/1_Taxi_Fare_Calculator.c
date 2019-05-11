/* Write a program that calculates taxi fare at a rate of $1.50 per mile. Your program should interact with the user in this manner:
 * TAXI FARE CALCULATOR
 * Enter the beginning odometer reading=> 78602.5
 * Enter the ending odometer reading=> 78622.7
 * You travelled a distance of 20.2 miles. At $1.50 per mile, your fare is $30.30.
 */

#include <stdio.h>

int main(){
  double beginning, odometer_ending, distance_travelled, price;
  printf("TAXI FARE CALCULATOR\n");
  printf("Enter the beginning odometer reading=> \n");
  scanf("%2lf", &beginning);
  printf("Enter the ending odometer reading=> \n");
  scanf("%2lf", &odometer_ending);
  distance_travelled = odometer_ending - beginning;
  price = distance_travelled * 1.50;
  printf("You travelled a distance of %2lf miles. At $1.50 per mile, your fare is $%2lf.\n", distance_travelled, price);
}

