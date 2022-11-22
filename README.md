---
title: "C Programs"
author: "Davide Lorino"
date: "13/05/2019"
output: 
  html_document:
    keep_md: true
    code_folding: hide
    toc: true
    toc_float: true
    toc_collapsed: true 
    toc_depth: 3
    number_sections: true 
    theme: darkly
    highlight: zenburn
    df_print: paged
---




# Problem Solving and Program Design in C

A collection of C programs I wrote to solve problems in <i>Problem Solving and Program Design</i> by Jeri Hanly and Eliot Kaufman

# Overview of C<br>
## Taxi Fare Calculator<br>


```c
/* Write a program that calculates taxi fare at a rate of $1.50 per mile. Your program should interact with the user in this manner:
 * TAXI FARE CALCULATOR
 * Enter the beginning odometer reading=> 78602.5
 * Enter the ending odometer reading=> 78622.7
 * You travelled a distance of 20.2 miles. At $1.50 per mile, your fare is $30.30.
 */

#include <stdio.h>

int main(){
  double beginning, odometer_ending, distance_travelled, price;
  printf("TAXI FARE CALCULATOR\n");
  printf("Enter the beginning odometer reading=> \n");
  scanf("%2lf", &beginning);
  printf("Enter the ending odometer reading=> \n");
  scanf("%2lf", &odometer_ending);
  distance_travelled = odometer_ending - beginning;
  price = distance_travelled * 1.50;
  printf("You travelled a distance of %2lf miles. At $1.50 per mile, your fare is $%2lf.\n", distance_travelled, price);
}
```

## Electrohydraulic Dam<br>


```c
/* Write a program to assist the design of a hydroelectric dam. Prompt the user for the height of the dam and for the number of cubic meters of water  
 * that are projected to flow from the top to the bottom of the dam of each second. 
 * Predict how many megawatts (1MW = 10^6W) of power will be produced if 90% of the work done on the water by gravity is converted to electrical energy.
 * Note that the mass of one cubic meter of water is 1000kg.
 * Use 9.80 m/sec^2 as the gravitational constant G.
 * Be sure to use meaningful names for both the gravitational constant and the 90% efficiency constant.
 * For one run, use a height of 170 m and flow of 1.30 x 10^3/s.
 * The relevant formula (w = work, m = mass, g = gravity, and h = height) is: 
 * w = mgh.
 */

#include <stdio.h>

#define GRAVITATIONAL_CONSTANT = 9.8;
#define MASS = 1000;

int main(){
  double MASS, GRAVITATIONAL_CONSTANT, HEIGHT, WATER;
}
```

## Freezer Temperature Estimation<br>


```c
/* Write a program that estimates the temperature in a freezer (in degrees Celcius) given the elapsed time since a power failure.
 * Assume this temperature (T) is given by T = (4t^2 / (t + 2)) - 20 
 */

#include <stdio.h>
#include <math.h>

int main(){
  float Temperature, time_since_power_failure, hours, minutes;
  
  printf("How many hours and minutes has it been since the power failure? Enter hours and minutes separately> \n");
  scanf("%f%f", &hours, &minutes);
  
  time_since_power_failure = hours + (minutes/60);
  
  Temperature = (4 * (time_since_power_failure*time_since_power_failure) / (time_since_power_failure + 2)) - 20;
  
  printf("The temperature inside the freezer is approximately %lf degrees celcius\n", Temperature);
}
```

## Currency Conversion<br>


```c
/* Write a program to convert a sum of money in US dollars to British pounds */

#include <stdio.h>
#include <math.h>


int main(){
  float dollar, pound;
  float conversion = 0.6;
  
  printf("Enter an amount of money in US dollars> \n");
  scanf("%f", &dollar);
  
  pound = dollar * conversion;
  
  printf("You have %f GBP\n", pound);
}
```

## Pharmaceutical Infusion<br>


```c
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
```

## Minimum Percentage Requirement<br>


```c
/* Write a program that predicts the score needed on a final exam to achieve a desired grade in a course.
 * The program should interact with the user as follows:
 * Enter the desired grade> B
 * Enter the minimum average required> 79.5
 * Enter the current average in course> 74.6
 * Enter how much the final counts as a percentage of the course grade> 25
 * 
 * You need a score of 94.20 on the final to get a B.
 */

#include <stdio.h>

int main(){
  char desired_grade;
  float minimum_average_required, current_average, weight_of_final_exam, score_needed_on_final_exam;
  
  printf("Enter the desired grade>\n");
  scanf("%c", &desired_grade);
  
  printf("Enter the minimum average required>\n");
  scanf("%f", &minimum_average_required);
  
  printf("Enter your current average>\n");
  scanf("%f", &current_average);
  
  printf("Enter how much the final exam counts as a percentage>\n");
  scanf("%f", &weight_of_final_exam);
  
  score_needed_on_final_exam = minimum_average_required + current_average * (weight_of_final_exam / 100);
  
  printf("Score needed on final exam is: %f to get a grade of %c\n", score_needed_on_final_exam, desired_grade);
}
```

## BTU Oil Efficiency<br>


```c
/* Write a program that calcutes how many BTUs of heat are delivered to a house given the number of gallons of oil burned and the efficiency of the 
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
```

## Community Water Conservation<br>


```c
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
```

## Rectangular Traversion<br>


```c
/* Write a program that takes the length of a rectangular yard and the length and width of a rectangular house situated in the yard. 
 * Your program should compute the time required to cut the grass at the rate of two square feet per second.
 */

#include <stdio.h>

int main(){
  int length_of_yard, width_of_yard, time_to_cut_grass, square_feet_per_second, square_feet_of_yard;
  
  square_feet_per_second = 2;
  
  printf("Enter the length of the yard in feet> \n");
  scanf("%d", &length_of_yard);
  
  printf("Enter the width of the yard in feet> \n");
  scanf("%d", &width_of_yard);
  
  square_feet_of_yard = length_of_yard * width_of_yard;
  
  time_to_cut_grass = square_feet_of_yard / square_feet_per_second;
  
  printf("It waill take %d seconds to cut the grass in a yard of %d square feet\n", time_to_cut_grass, square_feet_of_yard);
  return 0;
}
```

## Perpendicular Bisector<br>


```c

/* Write a program that outputs the equation of the perpendicular bisector of the line segment between two points.
 * Your program should:
 *  - prompt for and input the coordinate of the two points [for example, try tge points (2.0, -4.0) and (7.0, -2.0)];
 *  - compute the slope of the line between those two points;
 *  - compute the coordinates of the midpoint of the line segment between the two points by averaging the two x-coordinates and the two y-coordinates;
 *  - compute the slope of the perendicular bisector by taking the negative reciprocal of the slope of the line segment;
 *  - compute the y-intercept of the perpendicular bisector;
 *  - output with labels the original two points, and output in y = mx + b format the equation of the perpendicular bisector.
 *  
 *  Test your program to be sure it works on different pairs of coordinates. However, there will be some pairs of coordinates for which you cant make 
 *  your program work (at least not at this stage). Think about what points will cause your program to fail, and write a paragraph describing which points 
 *  fall in this category. 
 */

#include <stdio.h>

int main(){
  double x1, y1, x2, y2, slope, xmid, ymid, per_bisect, b;
  
  printf("Enter the coordinates for the first point> \n");
  scanf("%lf%lf", &x1, &y1);
  
  printf("Enter the coordinates for the second point> \n");
  scanf("%lf%lf", &x2, &y2);
  
  slope = (y2 - y1)/(x2 - x1);
  
  xmid = (x1 + x2)/ 2;
  ymid = (y1 + y2)/ 2;
  
  per_bisect = -1/(slope);
  
  b = ymid - (per_bisect * xmid);
  
  printf("The coordinates entered were (%.2lf, %.2lf) and (%.2lf, %.2lf).\nThe perpendicular bisect of this line is y = %.2lfx + %.2lf\n", x1, y1, x2, y2, per_bisect, b);
  
}
```

## Pythagorean Triple<br>


```c
/* The Pythagorean theorem states that the sum of the squares of the sides of a right triangle is equal to the square of the hypotenuse. 
 * For example, if two sides of a right triangle have lengths of 3 and 4, then the hypotenuse must have a length of 5. Together, the integers 3, 4 and 5 
 * form a Pythagorean triple. There are an infinite number of such triples. Given two positive integers, m and n, where m > n, a Pythagorean triple can be generated 
 * by the following formulas: 
 *      side 1 = m^2 - n^2
 *      side 2 = 2mn
 *      hypotenuse = m^2 + n^2 
 */

#include <stdio.h>

int main(){
  int m, n, side1, side2, hypotenuse;
  
  printf("Enter an integer>\n");
  scanf("%d", &m);
  
  printf("Enter another integer>\n");
  scanf("%d", &n);
  
  side1 = (m * m) - (n * n);
  side2 = 2 * (m * n);
  
  hypotenuse = (m * m) + (n * n);
  
  printf("The Pythagorean triple of these integers is %d, %d and %d\n", side1, side2, hypotenuse);
}
```

## Acceleration of a Jet Fighter<br>


```c
/* Write a program the calculates the acceleration (m/s^2) of a jet fighter launched from an aircraft-carrier catapult, given the jets take off speed in km/hr
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
```

## Whole Sections of a Batch<br>
 

```c
/* Write a program the predicts how many whole sections of a batch would need to be created given the number of students enrolled in the batch. 
 * 
 * Assume that each section accomodates 30 students.
 * 
 * Prompt the user to enter the number of students enrolled. 
 * 
 * Echo print the number of students enrolled and then display both the numbers of sections that will be required and the number of of students that will be left over.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
  int number_of_students_enrolled, sections, students_per_section;
  float leftover;
  
  students_per_section = 30;
  
  printf("Enter the number of students enrolled> \n");
  scanf("%d", &number_of_students_enrolled);
  
  sections = number_of_students_enrolled / 30;
  
  leftover = number_of_students_enrolled % students_per_section;
  
  printf("With %d students enrolled, %d sections are needed, with %.0lf student(s) left over.\n", number_of_students_enrolled, sections, leftover);
  
}
```

# Top-Down Design with Functions<br>

## Calculating Interest<br>


```c
/* You have saved $500 as a down payment on a car.
 * 
 * Before begnning your car shopping, you decide to write a program to help you figure out what your monthly payment will be, given the cars purchase price,
 * the monthly interest rate, and the time period over which you will pay back the loan. The formula for calculating your repayment is:
 * 
 *    payment = (iP) / (1 - (1 + i)^-n)
 *    
 *  where
 *    P = principal (the amount you borrow)
 *    i = monthly interest rate (1/12 of the annual rate)
 *    n = total number of payments
 *    
 *  Your program should prompt the user for the purchase price, the down payment, the annual interest rate, and the total number of payments (usually 36, 38 or 60).
 *  It should then display the amount borrowed and the monthly payment including a dollar sign and two decimal places.   
 */

#include <stdio.h>
#include <math.h>

int main(){
  int purchase_price, down_payment, amount_borrowed, total_number_of_payments;
  double annual_interest_rate, monthly_interest_rate, payment; 
  
  double calculatePayment(int monthly_interest, int borrowed, int payments);
  
  printf("Enter the price of the car>\n");
  scanf("%d", &purchase_price);
  
  printf("Enter the amount of your down payment>\n");
  scanf("%d", &down_payment);
  
  printf("Enter the annual interest rate>\n");
  scanf("%lf", &annual_interest_rate);
  
  monthly_interest_rate = annual_interest_rate / 12;
  
  printf("Enter the total number of payments>\n");
  scanf("%d", &total_number_of_payments);

  amount_borrowed = purchase_price - down_payment;
  
  payment = calculatePayment(monthly_interest_rate, amount_borrowed, total_number_of_payments);
    
  printf("Amount Borrowed:\t\t$%d\nMonthly Payments:\t\t$%.2lf\n", amount_borrowed, payment);
  
}

double calculatePayment(int monthly_interest, int borrowed, int payments){
  double calculatedpayment = (monthly_interest * borrowed) / (1 - pow((1 + monthly_interest), (payments * -1)));
  return calculatedpayment;
}
```

## Draw a Circle and a Trapezium<br>


```c
/* Write to functions, one that displays a circle and one that displays a trapezium.
 * 
 * Use these functions to write a complete C program from the following outline:
 *    int main(void){
 *      draw circle;
 *      draw trapezium;
 *      display one blank line;
 *      draw circle;
 *      draw trapezium;
 *    }  
 */

#include <stdio.h>

int main(void){

  void draw_circle();
  void draw_trapezium();
  
  draw_circle();
  draw_trapezium();
  printf("\n");
  draw_circle();
  draw_trapezium();
}

void draw_circle(){
  printf("    *   \n");
  printf("*       *\n");
  printf("  *   *\n");
}

void draw_trapezium(){
  printf("\\--------\\\n");
  printf(" \\        \\\n");
  printf("  \\--------\\\n");
}
```

## Calculate Surface Area of a Cone<br>


```c
/* Write a program that prompts the user to enter the radius of the circular base of a cone and the slant height of the cone.
 * 
 * The program must compute the total surface area of a right circular cone and display it back to the user.
 */

#include <stdio.h>
#include <math.h>

int main(){
  const double PI = 3.14159;
  double radius, slant_height; /* Inputs  */
  double SA;        /* Output  */

  double surfaceArea(double radius, double slant_height, const double PI);
  
  printf("Enter the radius of the base of the circle>\n");
  scanf("%lf", &radius);
  
  printf("Enter the slant height of the cone>\n");
  scanf("%lf", &slant_height);
  
  SA = surfaceArea(radius, slant_height, PI);
  
  printf("The radius of the base of the circle is %.2lf, the slant height of the cone is %.2lf and the total surface area of the cone is %.2lf\n", radius, slant_height, SA);
 
}

double surfaceArea(double radius, double slant_height, const double PI){
  double surface_area;
  surface_area = (PI * pow(radius, 2)) + (PI * radius) * (sqrt(pow(slant_height, 2) + pow(radius, 2)));
  return surface_area;
}
```

## Positive Factorial<br>


```c
/* 
 * Find the factorial of any positive integer. 
 * 
 * For any integer > 0, n! is defined as the product n * (n - 1) * (n - 2) ... * 2 * 1.
 * 0! is defined as 1. 
 * 
 * It is sometimes useful to have a closed-form definition instead; for this purpose, an approximation can be used.
 * 
 * R. W. Grosper proposed the following such approximation formula:
 * 
 *    n! = (n^n)(e^-n)sqrt((2n + 1/3)* PI)
 *    
 * Create a program the prompts the user to enter an integer (n), users Gospers formula to approximate n!, and then displays the result. 
 * 
 * The message displaying the result should look something like this:
 * 
 * 5! equals approximately 119.97003
 * 
 * Your program will be easier to debug if you use some intermediate values instead of trying to compute the result in a single expression.
 * 
 * If you are not getting the correct results, then you can compare the results of your intermediate values to what you get when you do the calculation by hand. 
 * 
 * Use atleast two intermediate variables - one for 2n + 1/3 and one for sqrt(2n + 1/3) * PI.
 * 
 * Display each of these intermediate values to simplify debugging. 
 * 
 * Be sure to use a named constant for PI, and use the approximation 3.14159265. Test the program on nonnegative integers less than 8.
 *    
 */

#include <stdio.h>
#include <math.h>

int main(){
  double n;
  const double PI = 3.14159265;
  double intermediate1, intermediate2, factorial_final;

  double intermediator1(double n);
  double intermediator2(double var1, const double PI);
  double factorialiser(double n, double var2);
      
  printf("Enter any positive integer number>\n");
  scanf("%lf", &n);
  
  intermediate1 = intermediator1(n);
  intermediate2 = intermediator2(intermediate1, PI);
  factorial_final = factorialiser(n, intermediate2);
  
  printf("The integer you enered was %.0lf\nThe factorial of %.0lf is approximately %lf.\n", n, n, factorial_final);
}

double intermediator1(double n){
  double var1;
  var1 = (1.0 / 3.0) + (2.0 * n);
  return var1;
}

double intermediator2(double var1, const double PI){
  double var2;
  var2 = sqrt(var1 * PI);
  return var2;
}

double factorialiser(double n, double var2){
  double factorial;
  factorial = (pow(n, n) * exp((n * -1.0))) * var2;
  return factorial;
}
```

## Hours Needed<br>


```c
/* Given the value of the monthly payment obtained in programming project 1 and a certain hourly income of a student, write a program that calculates
 * how many hours the student will need to work so as to pay every months payment towards the laptop.
 */

#include <stdio.h>
#include <math.h>

int main(){
  double purchase_price, down_payment, amount_borrowed, total_number_of_payments;
  double annual_interest_rate, monthly_interest_rate, payment, hourly_pay, hours_needed; 
  
  double calculatePayment(double monthly_interest, double borrowed, double payments);
  
  double hours_to_work(double payment, double hourly_income);
  
  printf("Enter the price of the car>\n");
  scanf("%lf", &purchase_price);
  
  printf("Enter the amount of your down payment>\n");
  scanf("%lf", &down_payment);
  
  printf("Enter the annual interest rate>\n");
  scanf("%lf", &annual_interest_rate);
  
  printf("Enter your hourly income>\n");
  scanf("%lf", &hourly_pay);
  
  monthly_interest_rate = annual_interest_rate / 12;
  
  printf("Enter the total number of payments>\n");
  scanf("%lf", &total_number_of_payments);
  
  amount_borrowed = purchase_price - down_payment;
  
  payment = calculatePayment(monthly_interest_rate, amount_borrowed, total_number_of_payments);
  
  hours_needed = hours_to_work(payment, hourly_pay);
  
  printf("Amount Borrowed:\t\t$%.2lf\nMonthly Payments:\t\t$%.2lf\nYou will need to work %.2lf hours in order to pay this off.\n", amount_borrowed, payment, hours_needed);
  
}

double calculatePayment(double monthly_interest, double borrowed, double payments){
  double calculatedpayment = (monthly_interest * borrowed) / (1 - pow((1 + monthly_interest), (payments * -1)));
  return calculatedpayment;
}

double hours_to_work(double paying, double hourly_income){
  double need_to_work;
  need_to_work = paying / hourly_income;
  return need_to_work;
}
```

## MPS FPS<br>


```c
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
```

## Five Yearly Housing Expenditure<br>


```c

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
```

## Acceleration Rate<br>


```c

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
```

## Temperature at Depth<br>


```c

#include <stdio.h>

float celcius_at_depth(float kilometers);
float farenheit(float celcius);

int main(){
  float cel, far, kilometers;
  
  printf("Enter a depth in kilometers>\n");
  scanf("%f", &kilometers);
  
  cel = celcius_at_depth(kilometers);
  
  far = farenheit(cel);
  
  printf("Temperature at a Depth of %i km is:\n", (int)kilometers);
  printf("%i Degrees Celcius\n", (int)cel);
  printf("%i Degrees Farenheit\n", (int)far);
  
  
}

float celcius_at_depth(float kilometers){
  float celcius;
  celcius = (10*kilometers) + 20;
  return celcius;
}

float farenheit(float celcius){
  float faren;
  faren = (celcius*1.8) + 32;
  return faren;
}
```

## Six Speed Gearbox<br>


```c

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
```

## Speed of Sound<br>


```c
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
```

## Population Size Over Time


```c

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
```

# Selection Structures: if and switch Statements

## Student Discount


```c
/* The students cornerstore in a univeristy needs a program to implement its student discount policy. The program is to prompt the user to enter the 
 * purchase total and to indicate whether the purchaser is a student. Students are eligible to receive a 20% discount on all their purchases. 
 * The discount calculation, however, must be done before addition of the 5% sales tax. 
 * Example (Student):
 * 
 * Total Purchases                $122.00
 * Student Discount                 24.40
 * Discounted Total                 97.60
 * Sales Tax (5%)                    4.88
 * Total                          $102.48
 * 
 * Example (Not Student):
 * 
 * Total Purchases                $24.90
 * Sales Tax (5%)                   1.25
 * Total                          $26.15
 */


#include <stdio.h>

void print_menu();

int main(){
  print_menu();
  return 0;
  
}

void print_menu(void){
  float purchase_price, price_after_salestax, student_discount, discounted_total, total_tax;
  int student_status = 0;
  
  
  printf("Enter the purchase price>\n");
  scanf("%f", &purchase_price);
  
  printf("Is this customer a student?>\n1 - Yes\n2 - No\n");
  scanf("%d", &student_status);
  
  student_discount = purchase_price * 0.2;
  
  if(student_status == 1){
    discounted_total = purchase_price - (purchase_price * 0.2);
    total_tax = discounted_total * 0.05;
    price_after_salestax = discounted_total + (discounted_total * 0.05);
  }else if(student_status == 2){
    total_tax = purchase_price * 0.05;
    price_after_salestax = purchase_price + (purchase_price * 0.05);
  }
  
  
  
  if(student_status == 1){
    printf("Total Purchases %.2f \nStudent Discount %.2f \nDiscounted Total %.2f \nSales Tax %.2f \nTotal %.2f \n", 
           purchase_price, student_discount, discounted_total, total_tax, price_after_salestax);
  }else if(student_status == 2){
    printf("Total Purchases %.2f \nSales Tax %.2f \nTotal %.2f \n", 
           purchase_price, total_tax, price_after_salestax);
  }
  
  
}
```

## BMI Calculator


```c
/*
 * Write a program that calculates the users Body Mass Index (BMI) and categorises it as underweight, normal, overweight or obese., based on the following:
 * 
 * Below 18.5         Underweight
 * 18.5 - 24.9        Normal
 * 25.0 - 29.9        Overweight 
 * 30.0 and above     Obese
 * 
 * To calculate BMI based on weight in pounds (wt_lb) and height in inches (ht_in) use this formula:
 * 
 * bmi = (703 * wt_lb) / pow(ht_in, 2)
 */

#include <stdio.h>

int main(){
  float ht_in, wt_lb, bmi;
  
  printf("Enter your weight in pounds>\n");
  scanf("%f", &wt_lb);
  
  printf("Enter your height in inches>\n");
  scanf("%f", &ht_in);
  
  bmi = (703 * wt_lb) / (ht_in * ht_in);
  
  if(bmi < 18.5){
  printf("Your BMI is %.2f which makes you underweight.\n", bmi);
  }
  else if(bmi >= 18.5 && bmi < 25){
    printf("Your BMI is %.2f which makes you normal.\n", bmi);
  }
  else if(bmi >= 25 && bmi < 30){
    printf("Your BMI is %.2f which makes you overweight.\n", bmi);
  }
  else if(bmi >= 30){
    printf("Your BMI is %.2f which makes you obese.\n", bmi);
  }
  return 0;
}
```

## Short-Circuit Evaluation


```c
/* 
 * Write a program that demonstrated Cs short-circuit evaluation of the && and || operators. 
 * 
 * Include two user-defined functions, fun1 and fun2. 
 * 
 * Function fun1 should prompt the user to enter T for true or F for false. 
 * 
 * If the user input is T, the function should return 1; otherwise it should return 0;
 * 
 * Function `fun2` should simply display "function 2 executed" and then return 1.
 * 
 * Function `main` should include two conditional statements: "the test of && complete" if the && function calls to f1 and f2 is true. 
 * 
 * The second conditional statement should display "the test of || complete" if the || of calls to fun1 and fun2 is true.
 * 
 * Before the first conditional statement display the message "Testing &&" and before the second, "Testing ||" then test your program four times
 * with inputs TT, TF, FT and FF.
 * 
 * Predict the output of each run before running it to verify your understanding of the short-circuit evaluation of these two operators.  
 */

#include <stdio.h>

#define ASCII_T 84
#define ASCII_F 

int fun1(void);
int fun2(void);

int main(){
  fun1();
  fun2();
  
  
}

int fun1(void){
  char letter;
  printf("Enter a letter\n");
  scanf("%c", &letter);
  
  printf("Testing &&\n");
  
  if(letter == ASCII_T){
    printf("fun1 executed\n");
  }
  else{
    printf("fun1 failed.\n");
  }
  return 0;
}

int fun2(void){
  char letter;
  printf("Enter a letter\n");
  fgetc(stdin);
  scanf("%c", &letter);
  
  printf("Testing ||\n");
  
  if(letter == ASCII_T){
    printf("fun2 executed\n");
  } 
  else{
    printf("fun2 failed.\n");
  }
  return 0;
}
```

## Compressed Gas Cylinder


```c

/*
 * Write a progam that reports the contents of a compressed-gas cylinder based on the first letter of the cylinders colour. 
 * 
 * The program input is a character representing the observed colour of the cylinder: "Y" or "y" for yellow, "O" or "o" for orange and so on.
 * 
 * Cylinder colours and associated contents are as follows:
 * 
 * orange      ammonia
 * brown       carbon monoxide
 * yellow      hydrogen
 * green       oxygen
 * 
 * Your program should respond to input of a letter other than the first letters of the given colours with the message: contents unknown
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_O 79
#define ASCII_o 111
#define ASCII_B 66
#define ASCII_b 98
#define ASCII_Y 89
#define ASCII_y 121
#define ASCII_G 71
#define ASCII_g 103

int main(){
  char temp_color[100];
  int temp_colour = 79;
  
  printf("Enter the colour of the cylinder>\n");

  scanf("%s", temp_color);
  
  temp_colour = (int)temp_color[0];
  
  printf("String entered: %s\n", temp_color);
  printf("ASCII value of the first letter is: %d\n", temp_colour); 
  
  if((temp_colour - ASCII_O) == 0 || (temp_colour - ASCII_o) == 0)
  {
    printf("Cylinder contains: Ammonia\n");
  }
  else if((temp_colour - ASCII_B) == 0 || (temp_colour - ASCII_b) == 0)
  {
    printf("Cylinder contains: Carbon Monoxide\n");
  }
  else if((temp_colour - ASCII_Y) == 0 || (temp_colour - ASCII_y) == 0)
  {
    printf("Cylinder contains: Hydrogen\n");    
  }
  else if((temp_colour - ASCII_G) == 0 || (temp_colour - ASCII_g) == 0)
  {
    printf("Cylinder contains: Oxygen\n");    
  }
  else{printf("Contents unknown.\n");}
 return 0; 
}
```

## Monthly Data Consumption


```c
/*
 * An internet service provider charges its subscribers every month based on the following:
 * 
 * Data Usage (Gbs)          Charges
 * 0.0 < n <= 1.0            250
 * 1.0 < n <= 2.0            500
 * 2.0 < n <= 5.0            1000
 * 5.0 < n <= 10.0           1500
 * n > 10                    2000      
 * 
 * Given the amount of data used by the subscriber (i.e. n), write a program to calculate the charges paid by the subscriber.
 * 
 * Print a message to indicate bad data as well.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void monthly_internet_bill(int data_consumption);

int main(){
  char data_consumption[20];
  char data_consumption_clean[10];
  int data_consumption_int = 0, i;
  int read = 1;
  
  while(read == 1){
  printf("Enter the data consumption for the month>\n");
  scanf("%s", data_consumption);
  
  
  for(i = 0; data_consumption[i] != '\0'; i++){
  if(data_consumption[i] > 47 && data_consumption[i] < 57){
    strcpy(data_consumption_clean, data_consumption);
    data_consumption_int = atoi(data_consumption_clean);
    }
  }
  
    if(data_consumption_int == 0)
    {
      printf("Invalid input - enter a positive number in Gigabytes\n");
    }
    
    else if(data_consumption_int != 0)
    {
      read = 2;
    }
  }
  
  monthly_internet_bill(data_consumption_int);
  
}

void monthly_internet_bill(int data_consumption){
  if(data_consumption > 0 && data_consumption <= 1){
    printf("Your bill is $250\n");
  }
  else if(data_consumption > 1 && data_consumption <= 2){
    printf("Your bill is $500\n");
  }
  else if(data_consumption > 2 && data_consumption <= 5){
    printf("Your bill is $1000\n");
  }
  else if(data_consumption > 5 && data_consumption <= 10){
    printf("Your bill is $2000\n");
  }
  else{
    printf("Please enter a positive number\n");
  }
}
```

## Cartesian Plane


```c
/*
 * Write a program that takes two numbers points on a cartesian plane and tells the user which quadrant the intersection of those points belongs to.
 */

#include <stdio.h>

int main(){
  int x, y;
  printf("Enter the x coordinate>\n");
  scanf("%d", &x);
  
  printf("Enter the y coordinate>\n");
  scanf("%d", &y);
  
  if(x == 0){
    printf("X-Axis\n");
  }
  else if(y == 0){
    printf("Y-Axis\n");
  }
  else if(x > 0 && y > 0){
    printf("Quandrant 1.\n");
  }
  else if(y < 0 && y > 0){
    printf("Quadrant 2.\n");
  }
  else if(x < 0 && y < 0){
    printf("Quadrant 2.\n");
  }
  else if(x > 0 && y < 0){
    printf("Quadrant 4.\n");
  }
  return 0;
}
```

## Days Elapsed


```c
/*
 * Write a program that determines the day number (1 to 366) in a year for a 
 * date that is provided as input data. As an example, January 1, 1994, is day
 *  1. December 31, 1993 is day 365. December 31, 1996, is day 366, since 1996
 * is a leap year. A year is a leap year if it is divisible by four, except that
 * any year divisible by 100 is a leap year only if it is divisible by 400. Your
 * program should accept the month, day, and year as integers. Include a 
 * function 'leap' that returns 1 if called with a leap year, 0 otherwise. 
 */

#include <stdio.h>

int isLeapYear(int year) {
  if(((year % 4 == 0) & (year % 100 != 0)) || 
     ((year % 100 == 0) & (year % 400 == 0))) {
    printf("%d is a leap year\n", year);
    return 1;
   } else {
    printf("%d is not a leap year\n", year);
    return 0;
   }
}

int monthOutOfBounds(int month) {
  if((month < 1) | (month > 12)) {
    printf("Month is out of bounds\n");
    return 1;
  } else {
    return 0;
  }
}

int dayOutOfBounds(int day, int month, int max_day_vals[]) {
  if((day < 1) | (day > max_day_vals[month-1])) {
    printf(
      "Your chosen month can only have a date value between 1 and %d\n", 
      max_day_vals[month-1]
    );
    return 1;
  } else {
      return 0;
    }
  return 0;
}

int sumOfDaysElapsed(int month, int day, int max_day_vals[]) {
  int total_days_elapsed = 0; 
  int i;
  for(i = 0; (i == 0) | (i < (month-1)); i++) {
    if(month > 1){
      total_days_elapsed = total_days_elapsed + max_day_vals[i];
    }
  }
  total_days_elapsed = total_days_elapsed + day;
  return total_days_elapsed;
}

int main(){
  
  int year_input, 
      month_input, 
      day_input, 
      temp, 
      status, 
      is_leap_year,
      total_days_elapsed;
  
  /* Assume month out of bounds until proven otherwise */
  int month_out_of_bounds = 1;
  
  /* Assume day out of bounds until proven otherwise */
  int day_out_of_bounds = 1;
  
  /* Days per month in a non-leap year */
  int days_in_month_arr[] = 
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  /* Days per month in a leap year */
  int days_in_month_leap_year_arr[] = 
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  int max_date_vals[12];

  /* Begin the input cycle */
  printf("Enter the year in numeric format, e.g. 1991\n");
  status = scanf("%d", &year_input);
  while(status != 1){
    while((temp = getchar()) != EOF && temp != '\n');
    printf("Invalid input... please enter a year in numeric format e.g. 1991\n");
    status = scanf("%d", &year_input);
  }

  is_leap_year = isLeapYear(year_input);

  int j;
  if(is_leap_year){
    for(j = 0; j < sizeof(days_in_month_leap_year_arr) / sizeof(int); j++) {
      max_date_vals[j] = days_in_month_leap_year_arr[j];
    }
  } else {
    for(j = 0; j < sizeof(days_in_month_arr) / sizeof(int); j++) {
      max_date_vals[j] = days_in_month_arr[j];
    }
  }

  printf("Enter the month in numeric format as a number between 1 and 12\n");
  status = scanf("%d", &month_input);
  while( (status != 1) | 
        ((month_out_of_bounds = monthOutOfBounds(month_input)) == 1) ){
    while(((temp = getchar()) != EOF && temp != '\n'));
    printf("Enter the month in numeric format as a number between 1 and 12\n");
    status = scanf("%d", &month_input);
  }

  printf("Enter the day in numeric format\n");
  status = scanf("%d", &day_input);
  day_out_of_bounds = dayOutOfBounds(day_input, month_input, max_date_vals);
  while( (status != 1) | (day_out_of_bounds == 1) ){
    while(((temp = getchar()) != EOF && temp != '\n'));
    printf(
      "Enter the day in numeric format. Your specified month in the year %d has a maximum of %d days\n",
      year_input, max_date_vals[month_input-1]
    );
    status = scanf("%d", &day_input);
    day_out_of_bounds = dayOutOfBounds(day_input, month_input, max_date_vals);
  }

  printf("Your date is %d/%d/%d\n", day_input, month_input, year_input);

  total_days_elapsed = sumOfDaysElapsed(month_input, day_input, max_date_vals);
  printf("Total days elapsed in the year is %d\n", total_days_elapsed);
	
  return 0;
}

```

## Free Service


```c

/* Write a program that interact with the user like this: 
*
* (1) First free service    
* (2) Second free service
* Enter the free service number>> 2
* Enter number of miles>> 3557
* Vehicle must be serviced
*
* Use the table below to determine the appropriate message:
*
* Free Services                             Miles (k)
* ---------------------------------------------------------
* First Service                            1500 < k < 3000
* Second Service                           3001 < k < 4500
*/

#include <stdio.h>

int main(){
    
  int status, temp, miles_travelled;
  int free_service_number = 99;

  printf("(1) First Free Service\n");
  printf("(2) Second Free Service\n");
  printf("Enter the Free Service number>>\n");
  
  status = scanf("%d", &free_service_number);
  while((status != 1) | ((free_service_number != 1) & (free_service_number != 2))){
    while((temp = getchar()) != EOF && temp != '\n');
    printf("Invalid input... please enter either a (1) or a (2)\n");
    status = scanf("%d", &free_service_number);
  }

  printf("Enter the number of miles travelled in numeric format>>\n");
  status = scanf("%d", &miles_travelled);
  while( (status != 1)){
    while(((temp = getchar()) != EOF && temp != '\n'));
    printf("Enter the miles travelled in numeric format>>\n");
    status = scanf("%d", &miles_travelled);
  }

  if((free_service_number = 1) & (miles_travelled > 1500) & (miles_travelled <= 3000)){
    printf("Vehicle must be serviced.\n");
  }

  else if((free_service_number = 2) & (miles_travelled > 3001) & (miles_travelled <= 4500)){
    printf("Vehicle must be serviced.\n");
  }

  else{
    printf("Vehicle does not qualify for a free service.\n");
  }
	
  return 0;
}

```

# Repetition and Loop Statements

# Pointers and Modular Programming

# Array Pointers

# Strings

# Recursion

# Structure and Union Types

# Text and Binary File Pointers

# Programming in the Large

# Pointers and Dynamic Data Structures

# Multiprocessing Using Processes and Threads

# On to C++

# Appendix

<style>
 pre, code {
color: #FFFFFF;
background-color: #000000;
}
</style>
