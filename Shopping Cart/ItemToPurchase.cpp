#include "ItemToPurchase.h"
#include <iostream>

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}


ItemToPurchase::~ItemToPurchase() {

}

void ItemToPurchase::SetName(string someString) {
    this->itemName = someString;
}

string ItemToPurchase::GetName() {
    return itemName;
}

void ItemToPurchase::SetPrice(int somePrice) {
    this->itemPrice = somePrice;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int someQuantity) {
    this->itemQuantity = someQuantity;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string description) {
    this->itemDescription = description;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

void ItemToPurchase::PrintItemCost() {
    cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice() << " = $" << GetQuantity() * GetPrice();
}

void ItemToPurchase::PrintItemDescription() {
    cout << GetName() << ": " << GetDescription();
}