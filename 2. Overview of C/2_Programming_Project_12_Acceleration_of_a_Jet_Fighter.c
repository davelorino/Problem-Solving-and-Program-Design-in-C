/* Write a program the calculates the acceleration (m/s^2) of a jet fighter launched from an aircraft-carrier catapult, given the jet's take off speed in km/hr
 * and the distance (in meters) over which the catapult accelerates the jet from rest to takeoff.
 * 
 * Assume constant acceleration.
 * 
 * Also calculate the time (seconds) for the fighter to be accelerated to takeoff speed. 
 * 
 * When you prompt the user, be sure to indicate the units for each input.
 * 
 * For one run, use a takeoff speed of 278 km/hr and a distance of 94 meters. Relevant formulas (v = velocity, a = acceleration, t = time and s = distance):
 *        v = at
 *        s - 0.5 * at^2
 */

#include <stdio.h>

int main(){
  double acceleration, takeoff_speed, distance, time;
  
  printf("Enter the jet's takeoff speed in km/hr> \n");
  scanf("%lf", &takeoff_speed);
  
  printf("Enter the distance over which the catapult accelerates the jet from rest to takeoff (in meters)>\n");
  scanf("%lf", &distance);
  
  time = (2 * distance) / takeoff_speed;
  acceleration = takeoff_speed / time;
  
  printf("The time (in seconds) for the jet to accelerate to takeoff speed is %2.2f.\n", time);
  printf("The constant acceleration (in meters per seconds squared) of the jet is %.2f.\n", acceleration);
  
}