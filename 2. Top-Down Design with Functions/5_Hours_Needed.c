/* Given the value of the monthly payment obtained in programming project 1 and a certain hourly income of a student, write a program that calculates
 * how many hours the student will need to work so as to pay every month's payment towards the laptop.
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