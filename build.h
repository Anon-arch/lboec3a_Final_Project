#include <stdio.h>
#include <string.h>

float menu_prices[13][1][3] = {
    //{tall, grande, venti}
    {130.0,145.0,160.0},    //Caffe Americano,                    
    {140.0,155.0,170.0},    //Cappuccino,
    {140.0,155.0,170.0},    //Caffe Latte,
    {165.0,180.0,195.0},    //Caffe Mocha,
    {165.0,180.0,195.0},    //Caramel Macchiato,
    {165.0,180.0,195.0},    //Flat White,
    {165.0,180.0,195.0},    //White Chocolate Mocha,
    {120.0,130.0, 0.0},     //Espresso,
    {150.0,165.0,180.0},    //Cold Coffee Craft Cold Brew,
    {165.0,180.0,195.0},    //Vanilla Sweet Cream Cold Brew,
    {165.0,180.0,195.0},    //Cold Foam Iced Espresso,
    {150.0,165.0,180.0},    //Signature Hot Chocolate,
    {150.0,165.0,180.0},    //White Hot Chocolate

};
//address of names are arranged according to row number in menu_prices
char *menu_names[] = {"Caffe Americano", "Cappuccino", "Caffe Latte", "Caffe Mocha", 
                     "Caramel Macchiato", "Flat White", "White Chocolate Mocha","Espresso", 
                     "Cold Coffee Craft Cold Brew", "Vanilla Sweet Cream Cold Brew", "Cold Foam Iced Espresso", 
                     "Signature Hot Chocolate","White Hot Chocolate"};



/*
returns menu in string to console



use for loop to iterate items in the accessed in the 3d array using this format
{menu item, tall price, grande price, venti price}

output must include

menu item  |   price per size   | stock remaining

*/
void menu_view(){
    
    printf("|   Menu Item  |    tall    |   Grande  |   Venti   |\n");

    for(int item = 0; item < 12; item++){

        printf("|   %s                  ", menu_names[item]); 
        printf("|    %.1f    |   %.1f  |   %.1f   |\n",  menu_prices[item][1][0], menu_prices[item][1][1], menu_prices[item][1][2]);
        
    }


}

/*

must return an 2d array that contains index of order and customizations chosen

{{order number}
{customizations}}

for add-ons 

*/



