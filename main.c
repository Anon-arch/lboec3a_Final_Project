#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "build.h"

int orderStatus = 0;
// Begin main function

int main(void) {

    menu_view();


    char drink[100], size[50], response[100];
    int quantity, i;
    int match_drink = 0;

// use strcmp to determine an invalid input,
// if customer can avail add-on or sub for frapp
// or if customer's order is hot or iced for espresso

  printf("\n\nHi! What's your order? ");
  scanf("%[^\n]s", &drink);
  while(!orderStatus){

    for (i = 0; i < 38; i++)
  {
      if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink)))
      {
          match_drink = 1;
          
        break;
      }
      if(i == 37){
        printf("invalid selection");
      }
  }
  
  if (match_drink)
  {
      printf("How many? ");
      scanf("%i", &quantity);
      printf("What size? ");
      scanf("%s", &size);

      for (i = 0; i < 3; i++)
        {
            if (!strcmp(std_formatter(drink_sizes[i]), std_formatter(size)))
            {
                
                printf("Anything else? Y/N ");
                scanf("%s", &response);

                if(!strcmp(response, "N")){
                    orderStatus = 1;
                }

                break;
            }
            if (i == 2)
            {
                 printf("Invalid input! Please enter a valid size.\n");
            }
           
        }

       
        
  }
    if(strcmp(response, "none")){
                break;
            }

  }
  
  
  // display order summar/ create receipt

    /* FILE *receipt;

    // receipt = fopen("receipt.csv", "w");

    // fprintf(receipt, "Item, Price, quantity, subtotal\n");

    // use for loop to iterate thru the orders
    fprintf(receipt, "%s, %li, %i, %li\n", drink, price, quantity, subTotal);
    fprintf(receipt, "Total Php,,, %li\n", grandTotal);
    fprintf(receipt, "Cash,,, %li\n", cash);
    fprintf(receipt, "Change,,, %li\n", change);

    fclose(receipt);
    */


    return 0;

  }

