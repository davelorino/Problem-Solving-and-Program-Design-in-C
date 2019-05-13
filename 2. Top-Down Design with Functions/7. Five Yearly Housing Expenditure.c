
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void five_year_cost_summary(int initial_cost, int annual_fuel_cost, float annual_tax_rate);

int main(){
  
  int initial_cost = 0, annual_fuel_cost = 0, annual_tax_rate = 0;
  int chosen_option = 0;
  
  while(1){
  printf("Calculate expenditure?\n1. - Yes\n2. - No\n");
  scanf("%d", &chosen_option);
  
  if(chosen_option == 1){
    five_year_cost_summary(initial_cost, annual_fuel_cost, annual_tax_rate);
  }
  else if(chosen_option == 2){
    return 0;
  }
  }
  return 0;
}


void five_year_cost_summary(int initial_cost, int annual_fuel_cost, float annual_tax_rate){
  
  int five_year_cost1, five_year_cost2;
  
  printf("Enter the initial cost of your house>\n");
  fgetc(stdin);
  scanf("%d", &initial_cost);
  
  printf("Enter the annual fuel expenditure of your house>\n");
  scanf("%d", &annual_fuel_cost);
          
  printf("Enter the annual tax rate of your house>\n");
  scanf("%f", &annual_tax_rate);
  
  five_year_cost1 = (initial_cost + (annual_fuel_cost * 5));
  five_year_cost2 = five_year_cost1 + ((float)five_year_cost1 * annual_tax_rate);
  
  printf("Your five-yearly housing expenditure is: %d\n", five_year_cost2);
 
}