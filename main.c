#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "build.h"


// This holds the order details
typedef struct {
    char drink[100];
    char size[50];
    char options[50];
    int quantity;
    int price;
    int drink_category;
    int add_ons_price;
} Order;

int orderStatus = 0;

int main(void) {
    // Displays the menu
    menu_view();

    // This array stores the orders
    Order orders[100];
    int orderCount = 0;

    char drink[100], size[50], response[100], add_ons_response[50], option[50];
    int quantity, i;
    int match_drink;
    int price;
    long totalCost = 0;

// if customer can avail add-on or sub for frapp
// or if customer's order is hot or iced for espresso

printf("\n\nHi! What's your order? ");
scanf(" %[^\n]s", drink); // Corrected scanf format specifier
while (!orderStatus) {

// if customer can avail add-on or sub for frapp
// or if customer's order is hot or iced for espresso
  while(!match_drink){
        
        

        for (i = 0; i < 38; i++) {
            if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink)) && i <= 8) { // Assuming menu_names is an array of strings
                match_drink = 1;
                
                break;
            }
            else if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink)) && i > 8 && i < 28) { // Assuming menu_names is an array of strings
                match_drink = 2;
                break;
            }
            else if(!strcmp(std_formatter(menu_names[i]), std_formatter(drink)) && i >= 28){
                match_drink = 3;
                break;
            }

        }

        if (!match_drink) {
            printf("\n Invalid selection! Please enter a valid item.");
            // Clear the input buffer
            while ((getchar()) != '\n');

            printf("\nWhat's your order? ");
            scanf(" %[^\n]s", drink);
        }

  }

 // CUSTOMIZATION FUNCTION
        if(match_drink == 1){
            

            while(i){
                printf("Is it Hot or Iced? ");
                scanf(" %[^\n]s", add_ons_response);

                if(!strcmp(std_formatter(add_ons_response), "hot") || !strcmp(std_formatter(add_ons_response), "iced")){
                    break;
                }
                printf("Invalid Option\n");

            }
            strcat(add_ons_response, " ");
            strcpy(orders[orderCount].options, add_ons_response);
            price = 0;
        }
        else if(match_drink == 2){
            printf("\nCustomize Your Beverage\n");
            printf("ADD\n");
            for (int custom = 0; custom < 7; custom++)
            {
                printf(" - %s + %i\n", customizations[custom], add_ons[custom][0]);
            
            if(custom == 5)
            {
                printf("\nSubstitute\n");
            }

            }
            
            printf("\n\nAny Add-ons/Substitute? ");
            scanf(" %[^\n]s", add_ons_response);

            if(!strcmp(std_formatter(add_ons_response), "nothing")){
                strcpy(orders[orderCount].options, "nothing");
                price = 0;
            }

            
            for (int custom = 0; custom < 7; custom++){

                if (!strcmp(std_formatter(customizations[custom]), std_formatter(add_ons_response))){

                price = add_ons[custom][0];
                orders[orderCount].add_ons_price = add_ons[custom][0];
                
                strcpy(orders[orderCount].options, customizations[custom]);
                break;
            }


            }       

            
        }
  

        bool quantity_checker = false;
        
        while (!quantity_checker) {
        printf("How many? ");
        if (scanf("%d", &quantity) == 1 && quantity > 0) {
            quantity_checker = true;
        } else {
            printf("\nInvalid input! Please enter a valid quantity.\n");
            // Clear the input buffer
            while ((getchar()) != '\n');
        }
    }
        
        // Check if the inputted size is valid
        bool valid_size = false;
        while(!valid_size){
            printf("What size? ");
            scanf("%s", &size);

            for (i = 0; i < 3; i++) {
                if (!strcmp(std_formatter(drink_sizes[i]), std_formatter(size))) {
                    valid_size = true;
                   strcpy(orders[orderCount].size, drink_sizes[i]);
                }
            }
            if(!valid_size){
                printf("Invalid input! Please enter a valid size.\n");
            }
           
        }
        

        // Retrieve the price based on the selected drink and size
        int drinkIndex;
        for (int i = 0; i < 38; i++) {
            if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink))) {
                strcpy(orders[orderCount].drink, menu_names[i]);
                drinkIndex = i;
                break;
            }
        }

       
        // Menu prices for venti and grande are being switched :(
        for (int i = 0; i < 3; i++) {
            if (!strcmp(std_formatter(size), std_formatter(drink_sizes[i]))) {
            // Adjust the indexing to access the correct price based on the selected size
            int price_index = (i == 1) ? 2 : (i == 2) ? 1 : i; // Switching indexes for venti and grande
            price += menu_prices[drinkIndex][price_index];
            break;
        }
        }

        
        // Store the order details
        // "option " variable stores addons, customizations, hot/cold


        
        orders[orderCount].quantity = quantity;
        orders[orderCount].price = price;
        orders[orderCount].drink_category = match_drink;
        orderCount++;

        // Reset match_drink for the next iteration


        // Calculate subtotal for the current order
        long subtotal = quantity * price;

        // Update total cost
        totalCost += subtotal;

        printf("Anything else? ");
        scanf(" %[^\n]s", drink);

        if (!strcmp(std_formatter(drink), "done")) {
            // prints order summary
            // displays the order summary (fix format, refer to canvas)
            
            printf("\nOrder summary:\n\n");

            printf("%-30s%10s%10s%10s\n\n", "Item", "Price", "Quantity", "Subtotal");
            for (i = 0; i < orderCount; i++)
            {

                // please align the letters
                long subtotal = orders[i].quantity*orders[i].price;
                if(orders[i].drink_category == 1){
                    strcat(orders[i].drink, orders[i].options);
                    strcat(orders[i].drink, orders[i].size);

                    printf("%-30s%10d%10d%10d   \n", orders[i].drink, orders[i].price, orders[i].quantity, subtotal);
                }
                if(orders[i].drink_category == 2){


                    strcat(orders[i].drink, orders[i].size);
                    printf("%-30s%10d%10d%10d   \n",orders[i].drink, orders[i].price, orders[i].quantity, subtotal);

                    if(strcmp(orders[i].options, "nothing")){
                        printf(" - %s + %i\n", orders[i].options, orders[i].add_ons_price);
                    }
                    
                }
                 if(orders[i].drink_category == 3){
                    printf("%-30s%10d%10d%10d   \n",orders[i].drink, orders[i].price, orders[i].quantity, subtotal);
                 }
                
                
            }

            printf("\n __________________________________________________________________________________");
            printf("\nTotal cost: %d\n\n", totalCost);

            long cash, change;
            char confirm_response[10];

            printf("Would you like to confirm your order [Yes/No]? ");
            scanf(" %[^\n]s", &confirm_response);

            if (!strcmp(std_formatter(confirm_response), std_formatter("Yes"))) {
                printf("How much is your cash? ");
                scanf("%li", &cash);

                change = cash - totalCost;

               
                // while loop to handle insufficient cash
                while (change < 0)
                {
                    printf("insufficient funds, please pay again\n");

                    printf("How much is your cash? ");
                    scanf("%li", &cash);

                    change = cash - totalCost;
                }
                if(change >= 0){
                 printf("Your change is: %li\n", change); 
                // print the receipt
                FILE *receipt;

                receipt = fopen("receipt.csv", "w");

                fprintf(receipt, "%-30s%10s%10s%10s\n\n", "Item", "Price", "Quantity", "Subtotal");
                for (i = 0; i < orderCount; i++)
            {

                // please align the letters
                long subtotal = orders[i].quantity*orders[i].price;
                if(orders[i].drink_category == 1){
                    strcat(orders[i].drink, orders[i].options);
                    strcat(orders[i].drink, orders[i].size);

                    fprintf(receipt, "%-30s%10d%10d%10d   \n", orders[i].drink, orders[i].price, orders[i].quantity, subtotal);
                }
                if(orders[i].drink_category == 2){


                    strcat(orders[i].drink, orders[i].size);
                    fprintf(receipt, "%-30s%10d%10d%10d   \n",orders[i].drink, orders[i].price, orders[i].quantity, subtotal);

                    if(strcmp(orders[i].options, "nothing")){
                        fprintf(receipt, " - %s + %i\n", orders[i].options, orders[i].add_ons_price);
                    }
                    
                }
                if(orders[i].drink_category == 3){
                    fprintf("%-30s%10d%10d%10d   \n",orders[i].drink, orders[i].price, orders[i].quantity, subtotal);
                 }
                
            }

                fprintf(receipt, "Total Php:    %li\n", totalCost);
                fprintf(receipt, "Cash:   %li\n", cash);
                fprintf(receipt, "Change:   %li\n", change);

                fclose(receipt);

                printf("Saving your transaction into receipt.csv...\n");
                printf("Thank you for visiting Starbucks! See you again!");
                orderStatus = 1;
                break;

                }
                
                
            }

            else if (!strcmp(std_formatter(confirm_response), std_formatter("No"))) {
                printf("Anything else? "); // must take another order
                scanf(" %[^\n]s", drink);
            }
        }

        // match drink reset buffer
        match_drink = 0;


    }

return 0;
}
    