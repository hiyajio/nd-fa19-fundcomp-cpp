#pragma once
#include <string>
#include "ItemToPurchase.h"
#include <vector>
#include <iostream>

using namespace std;

class ShoppingCart {
    private:
        string customerName;
        string currentDate;
        vector <ItemToPurchase> cartItems;
    public:
        ShoppingCart();
        ShoppingCart(string name, string date);
        ~ShoppingCart();
        string GetCustomerName();
        string GetDate();
        void AddItem(ItemToPurchase item);
        void RemoveItem(string itemName);
        void UpdateQuantity(string itemname, int newQuantity);
        int GetNumItemsInCart();
        int GetCostOfCart();
        void PrintTotal();
        void PrintDescriptions();
};