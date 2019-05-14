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