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
    long price;
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
    long totalCost = 0;

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


        // Retrieve the price based on the selected drink and size
        int drinkIndex = -1;
        for (int i = 0; i < 38; i++) {
            if (!strcmp(std_formatter(menu_names[i]), std_formatter(drink))) {
                drinkIndex = i;
                break;
            }
        }

        // Menu prices for venti and grande are being switched :(
        long price = menu_prices[drinkIndex][0];
        for (int i = 0; i < 3; i++) {
            if (!strcmp(std_formatter(size), std_formatter(drink_sizes[i]))) {
                price = menu_prices[drinkIndex][i];
                break;
            }
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
        orders[orderCount].price = price;
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

        // Calculate subtotal for the current order
        long subtotal = quantity * price;

        // Update total cost
        totalCost += subtotal;

    }

    // displays the order summary (fix format, refer to canvas)
    printf("\nOrder summary:\n");

    printf("%-60s      %-6s       %-6s     %-6s   \n", "Item", "Price", "Quantity", "Subtotal");
    for (i = 0; i < orderCount; i++)
    {
        long subtotal = orders[i].quantity*orders[i].price;
        printf("%-60s      %-6d       %-6d     %-6d   \n",orders[i].drink, orders[i].price, orders[i].quantity, subtotal);
    }


    printf("Total cost: %d\n\n", totalCost);

    long cash, change;
    char confirm_response[10];

    printf("Would you like to confirm your order [Yes/No]? ");
    scanf(" %[^\n]s", &confirm_response);

    if (!strcmp(std_formatter(confirm_response), std_formatter("Yes"))) {
        printf("How much is your cash? ");
        scanf("%li", &cash);

        change = cash - totalCost;

        printf("Your change is: %li\n", change); // do something when inputted cash is insufficient

        // print the receipt
        FILE *receipt;

        receipt = fopen("receipt.csv", "w");

        fprintf(receipt, "Item, Price, quantity, subtotal\n");

        for (int i = 0; i < orderCount; i++)
        {
            long subtotal = orders[i].price * orders[i].quantity;
            fprintf(receipt, "\"%s\", %li, %i, %li\n", orders[i].drink, orders[i].price, orders[i].quantity, subtotal);
        }

        fprintf(receipt, "Total Php,,, %li\n", totalCost);
        fprintf(receipt, "Cash,,, %li\n", cash);
        fprintf(receipt, "Change,,, %li\n", change);

        fclose(receipt);

        printf("Saving your transaction into receipt.csv...\n");
        printf("Thank you for visiting Starbucks! See you again!");
    }

    else if (!strcmp(std_formatter(confirm_response), std_formatter("No"))) {
        printf("Anything else?"); // must take another order
    }


    return 0;

  }