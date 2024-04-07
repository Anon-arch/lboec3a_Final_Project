# LBYEC2A Coffee Project - Starbucks
By: Lorenzo Raphael Cabaero & Aniemor Delos Santos

## Introduction
The Starbucks Order Management System is a command-line application designed to facilitate ordering and processing transactions at Starbucks outlets. This system allows customers to place orders for various beverages and customizations, calculates the total cost, and generates a receipt for the transaction.

### Key Features:

***Menu Display:*** The system starts by displaying a menu of available Starbucks beverages along with their prices and options for customization.

***Order Placement:*** Customers can place orders by specifying the Starbucks beverage, size, quantity, and any desired customizations or add-ons.

***Input Validation:*** The system validates user inputs such as drink selection, quantity, and size to ensure accurate order processing. Furthermore, the system employs a fool-proof feature utilizing the `std_formatter()` custom function, which formats user inputs by removing spaces and converting characters to lowercase, thereby minimizing errors due to inconsistent input formats.

***Customization Options:*** Depending on the selected Starbucks beverage, customers are provided with options for customizations such as hot or iced variants, as well as additional add-ons or substitutions.

***Order Summary:*** After completing the Starbucks order, the system generates an order summary displaying the details of each item ordered, including price, quantity, and subtotal.

***Transaction Confirmation:*** Customers are prompted to confirm their Starbucks orders and input the payment amount. The system calculates the change due and generates a receipt for the transaction.

***Receipt Generation:*** Upon confirmation, the system generates a receipt in CSV format containing itemized details of the Starbucks order, total cost, payment amount, and change.

***User-Friendly Interface:*** The system provides clear prompts and messages to guide users through the Starbucks ordering process, ensuring a seamless user experience.



## Step-by-Step Guide

### Step 1: Placing an Order

- Open the `main.c` file then start the program.
- The program starts by displaying the menu,
```
SPRESSO & MORE
Espresso Beverages                                                                |    Tall      |   Grande  |   Venti    |
|   Caffe Americano                                                               |       130    |      145  |      160   |
|   Cappuccino                                                                    |       140    |      155  |      170   |
|   Caffe Latte                                                                   |       140    |      155  |      170   |
|   Caffe Mocha                                                                   |       165    |      180  |      195   |
|   Caramel Macchiato                                                             |       165    |      180  |      195   |
|   Flat White                                                                    |       165    |      180  |      195   |
|   White Chocolate Mocha                                                         |       165    |      180  |      195   |
|   Espresso                                                                      |       120    |      130  |        0   |
```
You'll be prompted to enter your drink order.

```
Hi! What's your order?
```
- Type the name of the beverage you want here*(as listed on the menu)*.

### Step 2: Customization (for Specific Drinks)
- Depending on the chosen drink, the program might ask if you want it hot or iced (e.g., for espresso). Enter your preference.
**EXAMPLE 1: Your drink is an espresso drink**

  ```
  Hi! What's your order? // cappuccino
  Is it Hot or Iced? // Hot

  NOTE: "//" is user input
  ```

- For drinks that allow add-ons or substitutes, the program displays a list of options with their price adjustments. Enter the name of the add-on/substitute you want (or type `nothing` if you don't want any).
**CASE 2: Your drink is an frappuccino**

 ```
   Hi! What's your order? Caramel

Customize Your Beverage
ADD
 - Flavored Syrup + 20
 - Espresso Shot + 30
 - White Mocha + 20
 - Heavy Cream + 20
 - Cold Foam + 20

Substitute
 - Organic Soymilk +20
 - Breve +20


Any Add-ons/Substitute? // Cold Foam


 NOTE: "//" is user input
```

### Step 3: Quantity and Size

- You'll be asked to specify the quantity (number) of the drink you want. Enter a valid number greater than 0.
  
   ```
    How many? // 1

    NOTE: "//" is user input
    ```
- Next, select the size of your drink from the available options (e.g., Tall, Grande, Venti).
  
   ```
    What size? // grande
  
    NOTE: "//" is user input
   ```


### Step 4: Multiple Orders
- If you enter `done` after placing an order, the program stops taking orders and displays the final summary and receipt.
- If you enter another drink name after placing an order, it treats it as a new order and repeats steps 1-3.

![image](https://github.com/Anon-arch/lboec3a_Final_Project/assets/54138252/43f3ce71-defe-49c1-adc5-af7e8a77bee0)


### Step 4: Order Confirmation and Payment

- The program summarizes your order, including the item name, price, quantity, and subtotal.
```
Order summary:

Item                               Price  Quantity  Subtotal

Cappuccino Hot Grande                155         1       155
Caramel Grande                       200         1       200
 - Cold Foam + 20

 __________________________________________________________________________________
Total cost: 355

```
- You'll be prompted to confirm your order `(Yes/No)`.

`Would you like to confirm your order [Yes/No]? Yes`

- If you confirm, the program asks for the amount of cash you're paying
  
**If you input insufficient money, it prompts the user to input again the sufficient amount of money***
```
How much is your cash? // 100
insufficient funds, please pay again


  NOTE: "//" is user input
```
**If you input sufficient money, It calculates and displays your change***
```

How much is your cash? // 400
Your change is:  45

NOTE: "//" is user input
```


### Step 5: Receipt Generation and End of Transaction
- A receipt file named `receipt.csv` is created, containing details of your order (items, price, quantity, subtotal), total cost, cash paid, and change.
```
  Saving your transaction into receipt.csv...
  Thank you for visiting Starbucks! See you again!
```

***CONTENTS OF CSV RECEIPT***
```
Item                               Price  Quantity  Subtotal

Cappuccino Hot Grande              155         1       155   
Caramel GrandeGrande               200         1       200   
 - Cold Foam + 20


Total Php:    355
Cash:   400
Change:   45
```

