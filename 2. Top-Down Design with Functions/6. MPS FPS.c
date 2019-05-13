/* 
 * Four track stars have entered the mile race at the Penn Relays. Write a program that scans in the race time in minutes and seconds for a runner and
 * computes and displays the speed in feet per second (fps) and in meters per second (mps). 
 * 
 * 5,280 feet = 1 mile
 * 
 * 1km = 3,282 feet
 * 
 * Write and call a function that displays instructions to the progmram user.
 * 
 * Run the program for each stars data. 
 * 
 *              MINUTES             SECONDS
 *                    3               52.83
 *                    3               59.83
 *                    4               00.03
 *                    4               16.22       
 */

#include <stdio.h>
#include <math.h>

int main(){
  double fps, mps;
  double minutes, seconds, timer;

  double timer_function(double mins, double secs);
  double feet_per_second(double time_taken);
  double meters_per_second(double time_taken);
    
  printf("Enter the minutes taken to complete the race> \n");
  scanf("%lf", &minutes);
  
  printf("Enter the remaining seconds taken to complete the race>\n");
  scanf("%lf", &seconds);
  
  timer = timer_function(minutes, seconds);
  
  fps = feet_per_second(timer);
  
  mps = meters_per_second(timer);
  
  printf("With a time of %.0lf minutes and %.0lf seconds, your f/s is %.2lf and your m/s is %.2lf\n", minutes, seconds, fps, mps);
  
}

double timer_function(double mins, double secs){
  double total_mins;
  total_mins = mins + (secs / 60);
  return total_mins;
}

double feet_per_second(double time_taken){
  double eff_pee_ess, seconds_taken;
  seconds_taken = time_taken * 60;
  eff_pee_ess = 5280 / seconds_taken;
  return eff_pee_ess;
}

double meters_per_second(double time_taken){
  double meters_in_a_mile, meters_per_sec, seconds_taken;
  seconds_taken = time_taken * 60;
  meters_in_a_mile = 1609.34;
  meters_per_sec =  meters_in_a_mile / seconds_taken;
  return meters_per_sec;
}

  