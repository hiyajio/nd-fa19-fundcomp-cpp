#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}


ShoppingCart::~ShoppingCart() {

}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    this->cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        if (this->cartItems.at(i).GetName() == itemName) {
            this->cartItems.erase(cartItems.begin() + i);
            return;
        }
    }
    cout << "\nItem not found in cart. Nothing removed.";
}

void ShoppingCart::UpdateQuantity(string itemName, int newQuantity) {
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        if (this->cartItems.at(i).GetName() == itemName) {
            cartItems.at(i).SetQuantity(newQuantity);
            return;
        }
    }
    cout << "\nItem not found in cart. Nothing modified.";
}

int ShoppingCart::GetNumItemsInCart() {
    int numItems = 0;
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        numItems += cartItems.at(i).GetQuantity();
    }
    return numItems;
}

int ShoppingCart::GetCostOfCart() {
    int totalCost = 0;
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        totalCost += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() {
    cout << "Number of Items: " << GetNumItemsInCart() << "\n";
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        cout << "\n" << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice()
            << " = $" << (cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice());
    }
    if (cartItems.size() == 0) {
        cout << "\n" << "SHOPPING CART IS EMPTY";
    }
    cout << "\n\n" << "Total: $" << GetCostOfCart();
}

void ShoppingCart::PrintDescriptions() {
    cout << "\nItem Descriptions";
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        cout << "\n" << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription();
    }
}