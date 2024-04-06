#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "build.h"


// This holds the order details
typedef struct {
    char drink[100];
    char size[50];
    char option[50];
    int quantity;
    long price;
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

    printf("\n\nHi! What's your order? ");

    while (!orderStatus) {
        while(!match_drink){
            scanf(" %[^\n]s", drink); // Corrected scanf format specifier

                for (i = 0; i < 38; i++) {
                    if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink)) && i <= 8) { // Assuming menu_names is an array of strings
                        match_drink = 1;
                        break;
                    }
                    else if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink)) && i > 8 && i < 28) { // Assuming menu_names is an array of strings
                        match_drink = 2;
                        break;
                    }

                }

                if (!match_drink) {
                    printf("\nInvalid selection! Please enter a valid item.\n");
                    printf("Hi! What's your order? ");
                    continue;
                }

        }
                // Asks for the number of drinks
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

                // Asks for the drink size
                bool valid_size = false;

                while(!valid_size){
                    printf("What size? ");
                    scanf("%s", &size);

                    for (i = 0; i < 3; i++) {
                        if (!strcmp(std_formatter(drink_sizes[i]), std_formatter(size))) {
                            valid_size = true;
                        }
                    }
                    if(!valid_size){
                        printf("Invalid input! Please enter a valid size.\n");
                    }

                }

        // CUSTOMIZATION FUNCTION
                if (match_drink == 1)
                {
                    bool valid_option = false;
                    while (!valid_option)
                    {
                        printf("Is it Hot or Iced? ");
                        scanf(" %[^\n]s", add_ons_response);
                        strcpy(option, add_ons_response);
                        price = 0;
                        if (!strcmp(std_formatter(option), std_formatter("hot")) || !strcmp(std_formatter(option), std_formatter("iced")))
                        {
                            valid_option = true;
                            break;
                        }
                        else {
                            printf("Please enter either 'Hot' or 'Iced.\n");
                        }
                    }
                }


                else if (match_drink == 2){
                    bool valid_custom = false;

                    while (!valid_custom)
                    {
                        printf("Any Add-ons/Substitute? ");
                        scanf(" %[^\n]s", add_ons_response);

                        for (int custom = 0; custom < 7; custom++) {
                            if (!strcmp(std_formatter(customizations[custom]), std_formatter(add_ons_response))){
                                price = add_ons[custom][1];
                                strcpy(option, customizations[custom]);
                                valid_custom = true;
                                break;
                            }

                            else if (!strcmp(std_formatter(add_ons_response), "none")) {
                                price = 0;
                                valid_custom = true;
                                break;
                            }
                        }

                        if (!valid_custom)
                        {
                            printf("Please enter a valid add-on/substitute.\n");
                        }

                    }
                }


                // Retrieve the price based on the selected drink and size
                int drinkIndex;
                for (int i = 0; i < 38; i++) {
                    if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink))) {
                        drinkIndex = i;
                        break;
                    }
                }

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
                strcpy(orders[orderCount].drink, drink);
                strcpy(orders[orderCount].size, size);
                strcpy(orders[orderCount].option, option);
                orders[orderCount].quantity = quantity;
                orders[orderCount].price = price;
                orderCount++;

                // Reset match_drink for the next iteration
                match_drink = 0;

                // If the response is a drink item, treat it as another order
                for (i = 0; i < 38; i++) {
                    if (!strcmp(std_formatter(menu_names[i]), std_formatter(response))) {
                        strcpy(drink, response);
                    }
                }

                // Calculate subtotal for the current order
                long subtotal = quantity * price;

                // Update total cost
                totalCost += subtotal;

                printf("Anything else? ");
                scanf(" %[^\n]s", drink);

                if (!strcmp(std_formatter(drink), "done")) {
                    // prints order summary
                    // displays the order summary (fix format, refer to canvas)
                    printf("\nOrder summary:\n");

                    printf("%-60s      %-6s       %-6s     %-6s   \n", "Item", "Price", "Quantity", "Subtotal");
                    for (i = 0; i < orderCount; i++)
                    {
                        long subtotal = orders[i].quantity*orders[i].price;
                        orders[i].drink[0] = toupper(orders[i].drink[0]);
                        printf("%-60s %s %s      %-6d       %-6d       %-6d   \n", orders[i].drink, orders[i].option, orders[i].size, orders[i].price, orders[i].quantity, subtotal);
                    }


                    printf("Total cost: %d\n\n", totalCost);

                    long cash, change;
                    char confirm_response[10];

                    printf("Would you like to confirm your order [Yes/No]? ");
                    scanf(" %[^\n]s", &confirm_response);

                    if (!strcmp(std_formatter(confirm_response), std_formatter("Yes"))) {
                        // Raises an error when cash is insufficient/invalid number
                        bool sufficient_cash = false;
                        while (!sufficient_cash)
                        {
                            printf("How much is your cash? ");
                            if (scanf("%li", &cash) != 1)
                            {
                                printf("Invalid Input! Please enter a valid amount of cash.\n");
                                while (getchar() != '\n');
                            }
                            else if (cash >= totalCost)
                            {
                                change = cash - totalCost;
                                printf("Your change is: %li\n", change);
                                sufficient_cash = true;
                            }
                            else if (!sufficient_cash)
                            {
                                printf("You have insufficient cash!\n");
                            }
                        }

                        // Print the receipt
                        FILE *receipt;

                        receipt = fopen("receipt.csv", "w");

                        fprintf(receipt, "Item, Price, quantity, subtotal\n");

                        for (int i = 0; i < orderCount; i++)
                        {
                            long subtotal = orders[i].price * orders[i].quantity;
                            orders[i].size[0] = toupper(orders[i].size[0]);
                            orders[i].option[0] = toupper(orders[i].option[0]);
                            // for espresso drinks
                            fprintf(receipt, "\"%s %s %s\", %li, %d, %li\n", orders[i].drink, orders[i].option, orders[i].size, orders[i].price, orders[i].quantity, subtotal);

                            // for others
                            fprintf(receipt, "\"%s\", %li, %d, %li\n", orders[i].drink, orders[i].price, orders[i].quantity, subtotal);

                            // for frappuccino
                            fprintf(receipt, "\"%s\", %li, %d, %li\n", orders[i].drink, orders[i].price, orders[i].quantity, subtotal);
                            fprintf(receipt, "\"%s\", %li, %d, %d\n", orders[i].option, orders[i].quantity, orders[i].price);

                        }

                        fprintf(receipt, "Total Php,,, %li\n", totalCost);
                        fprintf(receipt, "Cash,,, %li\n", cash);
                        fprintf(receipt, "Change,,, %li\n", change);

                        fclose(receipt);

                        printf("\nSaving your transaction into receipt.csv...\n");
                        printf("Thank you for visiting Starbucks! See you again!");
                        orderStatus = 1;
                        break;
                    }

                    else if (!strcmp(std_formatter(confirm_response), std_formatter("No"))) {
                        printf("Anything else? "); // takes another order
                    }
                }


        }

    return 0;
}

