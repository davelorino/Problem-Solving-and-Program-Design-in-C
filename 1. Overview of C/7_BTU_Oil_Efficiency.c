/* Write a program that calcutes ho2 many BTUs of heat are delivered to a house given the number of gallons of oil burned and the efficiency of the 
 * house's oil furnace. Assume that a barrel of oil (42 gallons) has an energy equivalent of 5,800,000 BTU. (Note: this number is too large to represent as
 * an int on some personal computers.) For one test, use an efficiency of 65% and 100 gallons of oil.
 */ 

#include <stdio.h>

int main(){
  double BTU_PER_GALLON, gallons, barrels, efficiency;
  printf("Enter the efficiency of your house's oil furnace as a percentage> \n");
  scanf("%lf", &efficiency);
  printf("Enter the number of gallons of oil burned> \n");
  scanf("%lf", &gallons);
  gallons = barrels / 42;
  BTU_PER_GALLON = 5800000;
  
}


