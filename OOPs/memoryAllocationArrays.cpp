#include <iostream>
using namespace std;

class Shop {
private:
    int ItemId[100];
    int ItemPrice[100];
    int counter;

public:
    void initCounter() { counter = 0; } // function to initialize counter
    void setPrice();
    void displayPrice();
};

void Shop::setPrice() {
    if (counter < 100) {
        cout << "Enter ID of your item " << counter + 1 << ": ";
        cin >> ItemId[counter];
        cout << "Enter the price of your item: ";
        cin >> ItemPrice[counter];
        counter++;
    } else {
        cout << "Shop capacity reached. Cannot add more items." << endl;
    }
}

void Shop::displayPrice() {
    cout << "Items in the shop:" << endl;
    for (int i = 0; i < counter; i++) {
        cout << "Item ID: " << ItemId[i] << ", Price: " << ItemPrice[i] << endl;
    }
}

int main() {
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();

    dukaan.displayPrice();

    return 0;
}
