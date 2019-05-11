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