#include <stdio.h>
#include <string.h>
#include <stdint.h>


typedef struct saleslines {
    char salesid[20];
    char consignmentid[20];
    char dataareaid[20];
    uint64_t TotalDiscount;
} salesline;

int main(){
   salesline salesline1;
    strcpy( salesline1.salesid, "SO0001");
    strcpy( salesline1.consignmentid, "FWOO0001");
    strcpy( salesline1.dataareaid, "au");
    salesline1.TotalDiscount = 179;
    
    salesline salesline2;
    strcpy( salesline2.salesid, "SO0001");
    strcpy( salesline2.consignmentid, "FWOO0001");
    strcpy( salesline2.dataareaid, "au");
    salesline2.TotalDiscount = 179;
    
    salesline salesline3;
    strcpy( salesline3.salesid, "SO0001");
    strcpy( salesline3.consignmentid, "FWOO0001");
    strcpy( salesline3.dataareaid, "au");
    salesline3.TotalDiscount = salesline2.TotalDiscount * salesline1.TotalDiscount;

  
  printf("SALESLINE 1\nSalesid:\t %s\nConsignment ID:\t %s\nDataareaid:\t %s\nTotalDiscount:\t %llu\n\n", 
         salesline1.salesid, salesline1.consignmentid, salesline1.dataareaid, salesline1.TotalDiscount);
  
  printf("SALESLINE 2\nSalesid:\t %s\nConsignment ID:\t %s\nDataareaid:\t %s\nTotalDiscount:\t %llu\n\n", 
         salesline2.salesid, salesline2.consignmentid, salesline2.dataareaid, salesline2.TotalDiscount);
  
  printf("SALESLINE 3\nSalesid:\t %s\nConsignment ID:\t %s\nDataareaid:\t %s\nTotalDiscount:\t %llu\n\n", 
         salesline3.salesid, salesline3.consignmentid, salesline3.dataareaid, salesline3.TotalDiscount);
  
  
  return 0;
}
