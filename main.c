#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "build.h"

// Begin main function
int main(void) {

    menu_view();

    char drink[100], size[50], response[100];
    int quantity, i;
    int match_drink = 0;

// use strcmp to determine an invalid input,
// if customer can avail add-on or sub for frapp
// or if customer's order is hot or iced for espresso

    printf("Hi! What's your order? ");
    scanf("%[^\n]s", &drink);

    for (i = 0; i < 38; i++)
    {
        if (strcmp(menu_names[i], drink) == 0)
        {
            match_drink = 1;
            printf("How many? ");
            scanf("%i", &quantity);

            printf("What size? ");
            scanf("%s", &size);

        }
    }

    int match_size = 0;
    for (i = 0; i < 3; i++)
    {
        if (strcmp(drink_sizes[i], size) == 0)
        {
            match_size = 1;
            printf("Anything else? ");
            scanf("%s", &response);
        }
    }

    if (match_size != 1)
    {
        printf("Invalid input! Please enter a valid size.\n");
    }


    if (match_drink != 1)
    {
        printf("Invalid input! Please enter a valid menu item.");
    }

    // display order summary
    // create receipt

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
