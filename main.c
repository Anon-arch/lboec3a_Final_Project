#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "build.h"


// This holds the order details
typedef struct {
    char drink[100];
    char size[50];
    int quantity;
} Order;

int orderStatus = 0;

int main(void) {
    // Displays the menu
    menu_view();

    // This array stores the orders
    Order orders[100];
    int orderCount = 0;

    char drink[100], size[50], response[100];
    int quantity, i;
    int match_drink = 0;

// use strcmp to determine an invalid input,
// if customer can avail add-on or sub for frapp
// or if customer's order is hot or iced for espresso

    printf("\n\nHi! What's your order? ");
    scanf("%[^\n]s", &drink);

    while (!orderStatus) {
        for (i = 0; i < 38; i++) {
            if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink))) {
                match_drink = 1;
                break;
            }
        }

        if (!match_drink) {
            printf("Invalid selection! Please enter a valid item.\n");
            break;
        }

        printf("How many? ");
        // checks if the input is an integer
        if (scanf("%d", &quantity) != 1)
        {
            printf("Please enter a valid quantity!");
            break;
        }


        printf("What size? ");
        scanf("%s", &size);

        // Check if the inputted size is valid
        bool valid_size = false;
        for (i = 0; i < 3; i++) {
            if (!strcmp(std_formatter(drink_sizes[i]), std_formatter(size))) {
                valid_size = true;
                break;
            }
        }

        if (!valid_size) {
            printf("Invalid input! Please enter a valid size.\n");
            break;
        }

        printf("Anything else? ");
        scanf(" %[^\n]s", &response);

        if (!strcmp(std_formatter(response), "Done")) {
            orderStatus = 1;
            break;
        }

        // Store the order details
        strcpy(orders[orderCount].drink, drink);
        strcpy(orders[orderCount].size, size);
        orders[orderCount].quantity = quantity;
        orderCount++;

        // Reset match_drink for the next iteration
        match_drink = 0;

        // If the response is a drink item, treat it as another order
        for (i = 0; i < 38; i++) {
            if (!strcmp(std_formatter(menu_names[i]), std_formatter(response))) {
                strcpy(drink, response);
            }
            else if (!strcmp(response, "Done")) {
              orderStatus = 1;
              break;
            }
        }

    }

    printf("\nOrder summary:\n");
    for (i = 0; i < orderCount; i++) {
        printf("%d. %d %s of %s\n", i + 1, orders[i].quantity, orders[i].size, orders[i].drink);
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