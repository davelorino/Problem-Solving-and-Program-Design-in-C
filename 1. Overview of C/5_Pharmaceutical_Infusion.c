/* Hospitals use programmable pumps to deliver medications and fluids to intravenous lines at a set number of milliliters per hour.
 * Write a program to output information for the labels the hospital pharmacy places on bags of I.V. medications indicating the volume of medication to be 
 * infused and the rate at which the pump should be set. The program should prompt the user ti enter the quantity of fluid in the bag and the number of 
 * minutes over which it should be infused. Output the VTBI (volume to be infused) in ml and the infusion rate in Ml/h (millitres per hour)
 */ 

#include <stdio.h>

int main(){
  double volume_to_be_infused, minutes_to_infuse, rate, hours;
  
  printf("Volume to be infused (ml) => ");
  scanf("%lf", &volume_to_be_infused);
  
  printf("Minutes over which to infuse => ");
  scanf("%lf", &minutes_to_infuse);
  
  hours = minutes_to_infuse / 60;
  
  rate = (3 * volume_to_be_infused) / hours;
  
  printf("\nVTBI: %lf ml\n", volume_to_be_infused);
  
  printf("Rate: %lf ml/h\n", rate);
}