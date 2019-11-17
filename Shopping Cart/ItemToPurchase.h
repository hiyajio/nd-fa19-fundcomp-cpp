#pragma once
#include <string>

using namespace std;

class ItemToPurchase {
    private:
        string itemName;
        int itemPrice;
        int itemQuantity;
        string itemDescription;
    public:
        ItemToPurchase(string name, string description, int price, int quantity);
        ItemToPurchase();
        ~ItemToPurchase();
        void SetName(string someString);
        string GetName();
        void SetPrice(int somePrice);
        int GetPrice();
        void SetQuantity(int someQuantity);
        int GetQuantity();
        void SetDescription(string description);
        string GetDescription();
        void PrintItemCost();
        void PrintItemDescription();
};