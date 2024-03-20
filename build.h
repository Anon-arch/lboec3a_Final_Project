#include <stdio.h>
#include <string.h>

long menu_prices[38][3] = {
    //{tall, grande, venti}
    // ESPRESSO & MORE
    {130,145,160},    //Caffe Americano,
    {140,155,170},    //Cappuccino,
    {140,155,170},    //Caffe Latte,
    {165,180,195},    //Caffe Mocha,
    {165,180,195},    //Caramel Macchiato,
    {165,180,195},    //Flat White,
    {165,180,195},    //White Chocolate Mocha,
    {120,130, 0},     //Espresso,
    {150,165,180},    //Cold Coffee Craft Cold Brew,
    {165,180,195},    //Vanilla Sweet Cream Cold Brew,
    {165,180,195},    //Cold Foam Iced Espresso,
    {150,165,180},    //Signature Hot Chocolate,
    {150,165,180},    //White Hot Chocolate
    // FRAPPUCCINO
    {165, 180, 195},  // Caramel
    {165, 180, 195},  // Mocha
    {160, 175, 190},  // White Mocha
    {170, 185, 200},  // Coffee Jelly
    {170, 185, 200},  // Java Chip
    {180, 195, 210},  // Dark Mocha
    {150, 165, 180},  // Chocolate Cream
    {150, 165, 180},  // Vanilla Cream
    {155, 170, 185},  // Caramel Cream
    {170, 185, 200},  // Chocolate Chip Cream
    {170, 185, 200},  // Strawberries & Cream
    {170, 185, 200},  // Green Tea Cream
    // TEAVANA TEAS
    {140, 155, 170},  // Iced Shaken Black Tea with Ruby Grapefruit & Honey
    {140, 155, 170},  // Iced Shaken Hibiscus Tea with Pomegranate Pearls
    {155, 170, 185},  // Matcha & Espresso Fusion
    {125, 140, 155},  // Green Iced Shaken
    {125, 140, 155},  // Black Iced Shaken
    {125, 140, 155},  // Caffeine-free hibiscus herbal Iced Shaken
    {140, 155, 170},  // Black Tea Latte
    {155, 170, 185},  // Chai Tea Latte
    {155, 170, 185},  // Green Tea Latte
    {120, 135, 150},  // Green Full-Leaf
    {125, 140, 155},  // White Full-Leaf
    {125, 140, 155},  // Black Full-Leaf
    {125, 140, 155},  // Caffeine-free herbal Tea Full-Leaf
};
//address of names are arranged according to row number in menu_prices
char *menu_names[] = {"Caffe Americano", "Cappuccino", "Caffe Latte", "Caffe Mocha",
                     "Caramel Macchiato", "Flat White", "White Chocolate Mocha","Espresso",
                     "Cold Coffee Craft Cold Brew", "Vanilla Sweet Cream Cold Brew", "Cold Foam Iced Espresso",
                     "Signature Hot Chocolate","White Hot Chocolate", "Caramel", "Mocha", "White Mocha", "Coffee Jelly",
                     "Java Chip", "Dark Mocha", "Chocolate Cream", "Vanilla Cream", "Caramel Cream", "Chocolate Chip Cream",
                     "Starwberries & Cream", "Green Tea Cream", "Iced Shaken Black Tea with Ruby Grapefruit & Honey",
                     "Iced Shaken Hibiscus Tea with Pomegranate Pearls", "Matcha & Espresso Fusion", "Green Iced Shaken", "Black Iced Shaken",
                     "Caffeine-free hibiscus herbal Iced Shaken", "Black Tea Latte", "Chai Tea Latte", "Green Tea Latte", "Green Full-Leaf",
                     "White Full-Leaf", "Black Full-Leaf", "Caffeine-free herbal Tea Full-Leaf"};

//sizes for drinks
char *drink_sizes[] = {"Tall", "Venti", "Grande"};

int add_ons[7][1] = {
  {20}, // Flavored Syrup
  {30}, // Espresso Shot
  {20}, // White Mocha
  {20}, // Heavy Cream
  {20}, // Cold Foam
  {20}, // organic Soymilk
  {20}  // Breve
};

//customizations for frappuccino drinks
char *customizations[] = {"Flavored Syrup", "Espresso Shot", "White Mocha", "Heavy Cream", "Cold Foam",
                          "Organic Soymilk", "Breve"};

/*
returns menu in string to console



use for loop to iterate items in the accessed in the 3d array using this format
menu item, tall price, grande price, venti price

output must include

menu item  |   price per size   | stock remaining

*/
void menu_view() {

  printf("ESPRESSO & MORE\n");
  printf("%-80s  |    %-6s    |   %-6s  |   %-6s   |\n", "Espresso Beverages", "Tall", "Grande", "Venti");

  for (int item = 0; item < 8; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

  printf("\nCold Coffee Craft\n");
  for (int item = 8; item < 11; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

  printf("\nChocolate\n");
  for (int item = 11; item < 13; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

// -------------

  printf("\nFRAPPUCCINO\n");
  printf("%-80s  |    %-6s    |   %-6s  |   %-6s   |\n", "Blended Coffee", "Tall", "Grande", "Venti");
  for (int item = 13; item < 19; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

  printf("\nBlended Cream\n");
  for (int item = 19; item < 25; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

  printf("\nCustomize Your Beverage\n");
  printf("ADD\n");
  for (int custom = 0; custom < 5; custom++)
  {
    printf(" - %s +%i\n", customizations[custom], add_ons[custom][0]);
  }

  printf("Substitute\n");
  for (int custom = 5; custom < 7; custom++)
  {
    printf(" - %s +%i\n", customizations[custom], add_ons[custom][0]);
  }

// -------------

  printf("\nTEAVANA TEAS\n");
  printf("%-80s  |    %-6s    |   %-6s  |   %-6s   |\n", "Signature Tea Beverage", "Tall", "Grande", "Venti");
  for (int item = 25; item < 28; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

  printf("\nTeavana Iced Shaken Tea\n");
  for (int item = 28; item < 31; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

  printf("\nTeavana Tea Latte\n");
  for (int item = 31; item < 34; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }

  printf("\nTeavana Full-Leaf Brewed Tea\n");
  for (int item = 34; item < 38; item++) {
  printf("|   %-60s                  ", menu_names[item]);
  printf("|    %6.1li    |   %6.1li  |   %6.1li   |\n",  menu_prices[item][0], menu_prices[item][1], menu_prices[item][2]);
  }
}


/*

must return an 2d array that contains index of order and customizations chosen

{{order number}
{customizations}}

for add-ons

*/
