#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//created by: joshwell
//date: Saturday, 18 July 2026, 7:13:15 pm

//structures:
typedef struct 
{
    char name[10];
    int price;
} food;

//types of food:
food menu[] =
{
    {"Burger", 55},
    {"Fries", 35},
    {"Coke", 30},
    {"Pizza", 120},
    {"Chicken", 95},
    {"Ice Cream", 40}
};

typedef struct
{
    food item;
    int quantity;
    int cost;
} cart;

//this is where i store my items when picked.
cart shoppingCart[20];

//FUNCTIONS:

void clear(){
    printf("\e[1H\e[2J");
}

//clear input buffer function
void clearBuffer()
{
    while (getchar() != '\n');
}

//prints lines and blank function
void line(int num)
{
    if (num == 0){
        printf("\n");
    }
    else if (num == 1){
        printf("------------------------------\n");
    }
    else if(num == 2){
        printf("==============================\n");
    }
}

//prints invalid function
void invalid()
{
    printf("Error: Invalid Input!\n");
}
//wallet function
void wallet(int money)
{
    printf("Wallet: $%d\n", money);
}
//number only function
void numberOnly()
{
    invalid();
    clearBuffer();
}


//MENUS:

//add money
void addMoney(int *money)
{
    int input;

    while (true)
    {

        line(2);
        printf("ADD MONEY\n");
        line(2);
        wallet(*money);
        line(0);
        printf("[0] Return\n");
        line(1);
        printf("Enter desired amount: ");

        if (scanf("%d", &input) != 1 || input < 0){
            clear();
            numberOnly();
            continue;
        }
        if (input == 0)
        {
            clearBuffer();
            clear();
            return;
        }
        else
        {
            clear();
            *money += input;
            printf("Money added Successfully!\n");
            clearBuffer();
        }
    }
}

//view menu
void viewMenu(int money, int *cartCount)
{
    int input;
    int i;
    int much;
    int cost;
    while (true)
    {
        line(2);
        printf("MENU\n");
        line(2);
        printf("Cart Capacity: %d/20\n", *cartCount);
        wallet(money);
        line(0);

        //size of one menu var food is 16 bytes
        for (i = 0; i < sizeof(menu)/sizeof(menu[0]); i++)
        {
        printf("[%d] %s $%d\n", i + 1, menu[i].name, menu[i].price);
        }

        line(0);
        printf("[0] Return\n");
        line(1);
        printf("Enter Choice: ");

        if (scanf("%d", &input) != 1){
            clear();
            numberOnly();
            continue;
        }

        if (input == 0){
            clear();
            return;
        }

        if (*cartCount == 20){
            clearBuffer();
            clear();
            printf("Cart is Full!\n");
            continue;
        }
        else if (input >= 1 && input <= i)
        {
            clearBuffer();
            food selectedFood = menu[input - 1];

            clear();
            line(2);
            printf("Selected food: %s\n", selectedFood.name);
            line(2);
            printf("Price: $%d\n", selectedFood.price);
            line(1);
            printf("Enter Quantity: ");
            if (scanf("%d", &much) != 1){
                clear();
                numberOnly();
                continue;
            }
            if (much == 0){
                clear();
                much = 0;
                continue;
            }

            clear();
            line(2);
            printf("Item Added to Cart!\n");
            line(2);

            cart picked;
            picked.item = selectedFood;
            picked.quantity = much;
            picked.cost = much * picked.item.price;

            printf("Item: %s\nQuantity: %d\nPrice: $%d\n", picked.item.name, picked.quantity ,picked.item.price);
            shoppingCart[*cartCount] = picked;
            (*cartCount)++;

            line(1);
            printf("Enter any key to return...");
            getchar();
            clearBuffer();
            clear();
            continue;
        }    
        clearBuffer();
        clear();    
        invalid();
    }
}

//view cart
void viewCart(int money, int *cartCount)
{
    int input;
    int i;
    int choice;
    while (true)
    {

        line(2);
        printf("VIEWING CART\n");
        line(2);
        printf("Cart Capacity: %d/20\n", *cartCount);
        wallet(money);
        if (*cartCount == 0){
            line(0);
            printf("Cart is Empty!\n");
            line(1);
            printf("Press and Enter any key to return...");
            getchar();
            clear();
            return;
        }
        for (i = 0; i < *cartCount; i++){
            line(1);
            printf("[%d]\nItem: %s\nPrice: $%d\nQuantity: %d\n", i + 1, shoppingCart[i].item, shoppingCart[i].item.price, shoppingCart[i].quantity);
            line(1);
        }
        printf("Enter the number of an item you wish to remove.\n");
        line(0);
        printf("[0] Return\n");
        line(0);
        printf("Enter Choice: ");
        if (scanf("%d", &input)!=1){
            clearBuffer();
            clear();
            invalid();
            continue;
        }
        if (input == 0){
            clearBuffer();
            clear();
            return;
        }
        for (i = 0; i < *cartCount; i++){
            shoppingCart[i];
            if (input == i + 1){
                clear();
                line(2);
                printf("%s Selected\n", shoppingCart[i]);
                line(2);
                printf("Remove item?\n");
                printf("[1] Proceed\n[2] Cancel\n");
                line(1);
                printf("Enter Choice: ");
                if (scanf("%d", &choice)!=1){
                    clearBuffer();
                    clear();
                    invalid();
                    continue;
                }
                if (choice != 1){
                    clearBuffer();
                    clear();
                    invalid();
                    invalid();
                    continue;
                }
                else{
                    for (i; i < *cartCount-1; i++){
                        shoppingCart[i] = shoppingCart[i+1];
                    }
                    *cartCount -= 1;
                    clearBuffer();
                    clear();
                    line(2);
                    printf("Item Removed Successfully!\n");
                    line(2);
                    printf("Enter any key to return...");
                    getchar();
                    clear();
                    continue;

                }
            }
        }
        clear();
    }
}
//checkout
void checkout(int *money, int *cartCount, int *totalCost)
{
    int input;
    while (true)
    {
        line(2);
        printf("CHECKOUT\n");
        line(2);
        *totalCost = 0;

        for (int i = 0; i < *cartCount; i++)
        {
            *totalCost += shoppingCart[i].cost;
        }
        printf("Cart Capacity: %d/20\n", *cartCount);
        wallet(*money);
        line(0);
        printf("Total Cost: $%d\n", *totalCost);
        line(1);
        printf("[1] Proceed to Checkout\n[0] Return\n");
        line(0);
        printf("Enter Choice: ");

        if (scanf("%d", &input)!= 1){
            clearBuffer();
            clear();
            invalid();
            continue;
        }
        clearBuffer();
        clear();

        switch (input)
        {
        case 1:

            if (*cartCount == 0)
            {
                printf("Cart is Empty!\n");
                continue;
            }
            if (*money < *totalCost)
            {
                printf("Insufficient Funds!\n");
                continue;
            }
            else
            {
            *money = *money - *totalCost;
            *totalCost = *totalCost - *money;
            *cartCount = 0;

            printf("Checked out Successfully!\n");
            }

        case 0:
            clear();
            return;

        default:
            clear();
            invalid();
            continue;
        }

        clearBuffer();
        break;
    }
}

//main
int main(void)
{
    int money = 500;
    int cartCount = 0;
    int totalCost = 0;
    int input;
    while (true)
    {
        input = 0;
        line(2);
        printf("FOOD ORDER SYSTEM\n");
        line(2);
        printf("Cart Capacity: %d/20\n", cartCount);
        wallet(money);
        line(0);
        printf("[1] View Menu\n[2] View Cart\n[3] Checkout\n[4] Add Money\n");
        line(0);
        printf("[0] Exit\n");
        line(1);
        printf("Enter Choice: ");

        if (scanf("%d", &input)!= 1){
            clearBuffer();
            clear();
            invalid();
            continue;
        }
        clear();
        clearBuffer();

        switch (input)
        {
        case 0:
            return 0;
        case 1:
            viewMenu(money, &cartCount);
            break;
        case 2:
            viewCart(money, &cartCount);
            break;
        case 3:
            checkout(&money, &cartCount, &totalCost);
            break;
        case 4:
            addMoney(&money);
            break;
        
        default:
            invalid();
            break;
        }           
    }
}