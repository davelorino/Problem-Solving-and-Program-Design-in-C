/* Metro City Planners proposes that a community conserve its water supply by replacing all the community's toilets with low-flush models that use only 2
 * litres per flush. 
 * Assume that there is about 1 toilet pfor every 3 persons, existing toilets use an average of 15 liters per flush, 
 * a toilet is flushed on average 14 times a day, and that the cost to install each new toilet is $150.
 * Write a program that would estimate the magnitude (litres/day) and cost of the water saved based on the community's population.
 */ 

#include <stdio.h>

int main(){
 long int new_litres_per_flush, old_litres_per_flush, cost_of_new_toilets, toilets_per_person, old_water_flushed_per_day, new_water_flushed_per_day, litres_of_water_saved_per_day, cost_of_water_saved, daily_number_of_flushes;
 long int size_of_community;  
  old_litres_per_flush = 15;
  new_litres_per_flush = 2;
  cost_of_new_toilets = 150;
  toilets_per_person = 3;
  daily_number_of_flushes = 14;
  printf("Enter the population size> \n");
  scanf("%ld", &size_of_community);
  
  cost_of_water_saved = size_of_community * cost_of_new_toilets;
  
  old_water_flushed_per_day = (((size_of_community / toilets_per_person) * daily_number_of_flushes) * old_litres_per_flush);
  
  new_water_flushed_per_day = (((size_of_community / toilets_per_person) * daily_number_of_flushes) * new_litres_per_flush);
  
  litres_of_water_saved_per_day = old_water_flushed_per_day - new_water_flushed_per_day;
  
  printf("With a community of %ld people, installing newer efficient toilets will save %ld litres per day at a cost of $%ld dollars to install the new toilets.\n", size_of_community, litres_of_water_saved_per_day, cost_of_water_saved);
  
  
}