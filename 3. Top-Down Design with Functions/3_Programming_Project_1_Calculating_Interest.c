/* You have saved $500 as a down payment on a car.
 * 
 * Before begnning your car shopping, you decide to write a program to help you figure out what your monthly payment will be, given the car's purchase price,
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
  
  payment = (monthly_interest_rate * amount_borrowed) / (1 - pow((1 + monthly_interest_rate), (total_number_of_payments * -1)));
  
  printf("Amount Borrowed:\t\t$%d\nMonthly Payments:\t\t$%.2lf\n", amount_borrowed, payment);
  
}