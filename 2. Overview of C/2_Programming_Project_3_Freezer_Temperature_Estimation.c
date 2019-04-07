/* Write a program that estimates the temperature in a freezer (in degrees Celcius) given the elapsed time since a power failure.
 * Assume this temperature (T) is given by T = (4t^2 / (t + 2)) - 20 
 */

#include <stdio.h>
#include <math.h>

int main(){
  float Temperature, time_since_power_failure, hours, minutes;
  printf("How many hours and minutes has it been since the power failure? Enter hours and minutes separately> \n");
  scanf("%f%f", &hours, &minutes);
  time_since_power_failure = hours + (minutes/60);
  Temperature = (4 * (time_since_power_failure*time_since_power_failure) / (time_since_power_failure + 2)) - 20;
  printf("The temperature inside the freezer is approximately %lf degrees celcius\n", Temperature);
}

