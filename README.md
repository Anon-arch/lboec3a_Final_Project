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
- The program starts by displaying the menu, You'll be prompted to enter your drink order.
- Type the name of the beverage you want *(as listed on the menu)*.

![image](https://github.com/Anon-arch/lboec3a_Final_Project/assets/54138252/7415de0e-e32c-41ae-b37c-0b0ec014f676)


### Step 2: Customization (for Specific Drinks)
- Depending on the chosen drink, the program might ask if you want it hot or iced (e.g., for espresso). Enter your preference.
- For drinks that allow add-ons or substitutes, the program displays a list of options with their price adjustments. Enter the name of the add-on/substitute you want (or type `nothing` if you don't want any).

![image](https://github.com/Anon-arch/lboec3a_Final_Project/assets/54138252/c2dbc49b-dd5b-4fc1-947b-c4ef64e2a2ae)

### Step 3: Quantity and Size
- You'll be asked to specify the quantity (number) of the drink you want. Enter a valid number greater than 0.
- Next, select the size of your drink from the available options (e.g., Tall, Grande, Venti).

![image](https://github.com/Anon-arch/lboec3a_Final_Project/assets/54138252/19d22a36-58aa-458a-a72e-f7716485a74b)

### Step 4: Multiple Orders
- If you enter `done` after placing an order, the program stops taking orders and displays the final summary and receipt.
- If you enter another drink name after placing an order, it treats it as a new order and repeats steps 1-3.

![order_summary](https://github.com/Anon-arch/lboec3a_Final_Project/assets/156874263/52da8676-9edb-4e12-9916-67e1a90ff5b5)

### Step 4: Order Confirmation and Payment

- The program summarizes your order, including the item name, price, quantity, and subtotal.
- You'll be prompted to confirm your order `(Yes/No)`.
- If you confirm, the program asks for the amount of cash you're paying. It calculates and displays your change.

![image](https://github.com/Anon-arch/lboec3a_Final_Project/assets/156874263/3ca660d8-9b21-42d6-8de9-1750459145ae)

### Step 5: Receipt Generation
- A receipt file named `receipt.csv` is created, containing details of your order (items, price, quantity, subtotal), total cost, cash paid, and change.
  
![receipt_pic](https://github.com/Anon-arch/lboec3a_Final_Project/assets/156874263/872fbd92-dc33-4413-85a0-91c6222c8cb0)



