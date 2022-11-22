
/* 
* Chatflow Wireless offers customers 600 weekday minutes at a rate of 39.99. 
* Night (8PM to 7AM) and weekend minutes are free, but additional weekday 
* minutes cost 0.40 each. There are taxes of 5.25% on all charges. Write a
* program that prompts the user to enter the number of weekday minutes, night
* minutes and weekend minutes used, and calculates the monthly bill and average
* cost of a minute before taxes. The program should display with labels all the
* input data, the pretax bill and average minute cost, the taxes and the total
* bill. Store all monetary values as whole cents (rounding the taxes and 
* average minutes cost), and divide up by 100 for display of results.
*/

#include <stdio.h>
#include <math.h>

int main(){
    
    int weekday_minutes, night_minutes, weekend_minutes, status, temp;
  
    printf("Enter the total monthly weekday minutes>>\n");
  
    status = scanf("%d", &weekday_minutes);
    while((status != 1)){
        while((temp = getchar()) != EOF && temp != '\n');
        printf("Invalid input... please enter weekday minutes as a number>>\n");
        status = scanf("%d", &weekday_minutes);
    }

    printf("Enter the total monthly night minutes>>\n");

    status = scanf("%d", &night_minutes);
    while((status != 1)){
        while((temp = getchar()) != EOF && temp != '\n');
        printf("Invalid input... please enter night minutes as a number>>\n");
        status = scanf("%d", &night_minutes);
    }

    printf("Enter the total monthly weekend minutes>>\n");

    status = scanf("%d", &weekend_minutes);
    while((status != 1)){
        while((temp = getchar()) != EOF && temp != '\n');
        printf("Invalid input... please enter weekend minutes as a number>>\n");
        status = scanf("%d", &weekend_minutes);
    }

    float cost_of_weekday_minutes_before_tax, cost_of_weekday_minutes_after_tax,
    total_tax, ave_cost_per_minute_before_tax;
    if(weekday_minutes <= 600){
        cost_of_weekday_minutes_before_tax = 39.99;
    } if(weekday_minutes > 600){
        cost_of_weekday_minutes_before_tax = 39.99 + ((weekday_minutes % 600) * 0.4);
    }

    total_tax = cost_of_weekday_minutes_before_tax * .0525;

    cost_of_weekday_minutes_after_tax = cost_of_weekday_minutes_before_tax + total_tax;

    ave_cost_per_minute_before_tax = 
        (weekend_minutes + weekday_minutes + night_minutes) / 
        cost_of_weekday_minutes_before_tax;

    printf("Weekday minutes: %d\n", weekday_minutes);
    printf("Night minutes: %d\n", night_minutes);
    printf("Weekend minutes: %d\n\n", weekend_minutes);

    printf("Cost before tax: $%.2f\n", cost_of_weekday_minutes_before_tax);
    printf("Cost after tax: $%.2f\n", cost_of_weekday_minutes_after_tax);
    printf("Total tax: $%.2f\n\n", total_tax);

    printf("Average cost per minute before tax: $%.2f\n", ave_cost_per_minute_before_tax);

  return 0;
}