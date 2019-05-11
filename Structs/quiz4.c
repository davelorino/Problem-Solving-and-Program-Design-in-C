
#include <stdio.h>

int LENGTH = 5;
char dot;

  
  
  void print_ipaddr(ipaddr_t ip){
    printf("%i.%i.%i.%i", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
  }
    

  int is_valid(ipaddr_t ip){
    if(ip.octet1 > 0 && ip.octet1 < 256 &&
       ip.octet2 > 0 && ip.octet2 < 256 &&
       ip.octet3 > 0 && ip.octet3 < 256 &&
       ip.octet4 > 0 && ip.octet4 < 256){
      return 1;
    }
      else({
        return(0);});
   
   return 0;
    
  }

int is_equal(ipaddr_t ip1, ipaddr_t ip2){
  if(ip1.octet1 == ip2.octet1 &&
     ip1.octet2 == ip2.octet2 &&
     ip1.octet3 == ip2.octet3 &&
     ip1.octet4 == ip2.octet4){
    return 1;
  }
  else return 0;
}

int is_same_subnet(ipaddr_t ip1, ipaddr_t ip2){
  if(ip1.octet1 == ip2.octet1 &&
     ip1.octet2 == ip2.octet2 &&
     ip1.octet3 == ip2.octet3){
    return 1;
  }
  else return 0;
}

int get_valid_ipaddrs(ipaddr_t addr_array[], int addr_array_len){
  int valid_inputs = 0, i;
  for(i = 0; i < addr_array_len; i++){
  scanf("%i%c%i%c%i%c%i", &addr_array[i].octet1, &dot, &addr_array[i].octet2, &dot, 
                            &addr_array[i].octet3, &dot, &addr_array[i].octet4);
  
  if(addr_array[i].octet1 > 0 && addr_array[i].octet1 < 256 &&
     addr_array[i].octet2 > 0 && addr_array[i].octet2 < 256 &&
     addr_array[i].octet3 > 0 && addr_array[i].octet3 < 256 &&
     addr_array[i].octet4 > 0 && addr_array[i].octet4 < 256){
      valid_inputs = valid_inputs + 1;
      }
    
   else if(addr_array[i].octet1 == -1 &&
            addr_array[i].octet2 == -1 &&
            addr_array[i].octet3 == -1 &&
            addr_array[i].octet4 == -1){
      return valid_inputs + 1;
      }
   
   else if(addr_array[i].octet1 < 0 || addr_array[i].octet1 > 255 ||
           addr_array[i].octet2 < 0 || addr_array[i].octet2 > 255 ||
           addr_array[i].octet3 < 0 || addr_array[i].octet3 > 255 ||
           addr_array[i].octet4 < 0 || addr_array[i].octet4 > 255){
     printf("Invalid input\n");
        }
   }
  
  return valid_inputs;
  
}

void print_same_subnet(const ipaddr_t addr_array[], int addr_array_len){
  int i;
    for(i=0; i < addr_array_len; i++){
      if(is_same_subnet(addr_array[i], addr_array[i]))
      {
        printf("I tried.");
      } 
    }
}
  

   




