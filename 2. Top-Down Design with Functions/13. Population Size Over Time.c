
#include <stdio.h>

float population(int year);

int main(){
  int year;
  float pop;
  
  while(1){
  printf("Enter a year after 1990>\n");
  scanf("%d", &year);
  
  if(year > 1990){
    pop = population(year);
    printf("The population of Gotham City in the year %d is approximately %.2f people\n", year, pop);
    return 0;
  }
  else(printf("Invalid - Enter a year greater than 1990\n"));
  }
}

float population(int year){
  float pop;
  pop = 52.966 + (2.18*year);
  return pop * 1000;
}