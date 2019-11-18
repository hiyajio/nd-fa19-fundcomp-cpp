#include <iostream>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

void AddItem(ShoppingCart &cart) {
    ItemToPurchase addItem;
    string addItemName;
    string addItemDescription;
    int addItemPrice;
    int addItemQuantity;

    cout << "\nADD ITEM TO CART";
    cout << "\nEnter the item name:";
    cin.ignore();
    getline(cin, addItemName);
    addItem.SetName(addItemName);
    cout << "\nEnter the item description:";
    getline(cin, addItemDescription);
    addItem.SetDescription(addItemDescription);
    cout << "\nEnter the item price:";
    cin >> addItemPrice;
    addItem.SetPrice(addItemPrice);
    cout << "\nEnter the item quantity:";
    cin >> addItemQuantity;
    addItem.SetQuantity(addItemQuantity);
    cart.AddItem(addItem);
}

void RemoveItem(ShoppingCart &cart) {
    string removeItem;

    cout << "\nREMOVE ITEM FROM CART";
    cout << "\nEnter name of item to remove:";
    cin.ignore();
    getline(cin, removeItem);
    cart.RemoveItem(removeItem);
}

void ChangeItemQuantity(ShoppingCart &cart) {
    string changeQuantityItem;
    int changeQuantityNumber;

    cout << "\nCHANGE ITEM QUANTITY";
    cout << "\nEnter the item name:";
    cin.ignore();
    getline(cin, changeQuantityItem);
    cout << "\nEnter the new quantity:";
    cin >> changeQuantityNumber;
    cart.UpdateQuantity(changeQuantityItem, changeQuantityNumber);
}

void OutputItemsDescriptions(ShoppingCart cart, string customerName, string todaysDate) {
    cout << "OUTPUT ITEMS' DESCRIPTIONS";
    cout << "\n" << customerName << "'s Shopping Cart - " << todaysDate << "\n";
    cart.PrintDescriptions();
}

void OutputShoppingCart(ShoppingCart cart, string customerName, string todaysDate) {
    cout << "\nOUTPUT SHOPPING CART";
    cout << "\n" << customerName << "'s Shopping Cart - " << todaysDate << "\n";
    cart.PrintTotal();
}

void PrintMenu(ShoppingCart cart) {
    string customerName;
    string todaysDate;
    char userOption = '1';

    cout << "Enter customer's name:";
    getline(cin, customerName);
    cout << "\nEnter today's date:";
    getline(cin, todaysDate);
    cout << "\n\nCustomer name: " << customerName;
    cout << "\nToday's date: " << todaysDate << "\n";

    do {
        cout << "\nMENU" << "\na - Add item to cart" << "\nd - Remove item from cart" << "\nc - Change item quantity"
            << "\ni - Output items\' descriptions" << "\no - Output shopping cart" << "\nq - Quit\n";
        do {
            cout << "\nChoose an option:";
            cin >> userOption;
            if (cin.fail()) {
                cin.clear();
                cin.ignore('\n', 1000);
                return;
            }
        } while (userOption != 'a' && userOption != 'd' && userOption != 'c' && userOption != 'i' && userOption != 'o' && userOption != 'q');
            if (userOption == 'a') {
                AddItem(cart);
            }
            else if (userOption == 'd') {
                RemoveItem(cart);
            }
            else if (userOption == 'c') {
                ChangeItemQuantity(cart);
            }
            else if (userOption == 'i') {
                OutputItemsDescriptions(cart, customerName, todaysDate);
            }
            else if (userOption == 'o') {
                OutputShoppingCart(cart, customerName, todaysDate);
            }
        cout << "\n";
    } while (userOption != 'q');
}

int main() {
    ShoppingCart cart;
    PrintMenu(cart);

    return 0;
}