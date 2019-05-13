
#include <stdio.h>
#include <stdlib.h>

float calculate_acceleration(int initial_velocity, int final_velocity, int time);

int main(){
  int initial_velocity, final_velocity, time, chosen_option;
  float accel;
  
  while(1){
  printf("Calculate acceleration?\n1. Yes\n2. No\n");
    scanf("%i", &chosen_option);
  
  if(chosen_option == 1){  
  printf("Enter the initial velocity>\n");
  scanf("%d", &initial_velocity);
  
  printf("Enter the final velocity>\n");
  scanf("%d", &final_velocity);
  
  printf("Enter the time interval>\n");
  scanf("%d", &time);
  
  accel = calculate_acceleration(initial_velocity, final_velocity, time);
  
  printf("The acceleration/deceleration rate is: %f\n", accel);
  }
  else if(chosen_option == 2){
    return 0;
  }
  }
}

float calculate_acceleration(int initial_velocity, int final_velocity, int time){
  float acceleration;
  acceleration = ((float)final_velocity - (float)initial_velocity) / (float)time;
  
  return acceleration;
}




