
#include <stdio.h>
#include <math.h>

float speeds_ratio(int min_speed, int max_speed);

int main(){
  int min_speed, max_speed;
  float speeds;
  
  printf("Enter a max speed>\n");
  scanf("%i", &max_speed);
  
  printf("Enter a min speed>\n");
  scanf("%i", &min_speed);
  
  speeds = speeds_ratio(min_speed, max_speed);
  
  printf("The ratio between successive speeds of a six-speed gearbox with maximum speed of %i rpm and a minimum speed of %i rpm is %f rpm\n", 
         max_speed, min_speed, speeds);
  
}

float speeds_ratio(int min_speed, int max_speed){
  float speeds_ratio = pow((max_speed / min_speed), 1/5.);
  return speeds_ratio;
}



