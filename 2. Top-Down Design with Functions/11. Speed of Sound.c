#include <stdio.h>
#include <math.h>

float speed_of_sound_at_farenheit(float farenheit);

int main(){
  float farenheit, speed_of_sound;
  
  printf("Enter a temperature in degrees farenheit>\n");
  scanf("%f", &farenheit);
  
  speed_of_sound = speed_of_sound_at_farenheit(farenheit);
  
  
  printf("At a temperature of %.2f degrees farenheit the speed of sound travels at %.2f ft/sec\n", farenheit, speed_of_sound);
  
  return 0;
  
}

float speed_of_sound_at_farenheit(float farenheit){
  float speed_of_sound;
  
  speed_of_sound = 1086*(sqrt(((5*farenheit) + 297) / 247));
  
  return speed_of_sound;
  
}