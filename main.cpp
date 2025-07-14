#include <iostream>
using namespace std;

class Product {
public:
    char name[20];
    float price;
    int quantity;

    void getInput() {
        cout << "Enter product name: ";
        cin.ignore(); 
        cin.getline(name, 20); 
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void show() {
        cout << name << " Rs " << price << " x " << quantity 
		<< " = Rs " << price * quantity << "\n";
    }

    float total() {
        return price * quantity;
    }

    // Operator overloading to add total price
    float operator+(float t) {
        return t + (price * quantity);
    }
};

int main() {
    Product p[5];
    int n;
    float discount, total = 0;

    cout << "How many products (max 5)? :- ";
    cin >> n;

    // Input products
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << ":\n";
        p[i].getInput();
    }

    // Show products
    cout << "\n--- Cart Items ---\n";
    for (int i = 0; i < n; i++) {
        p[i].show();
        total = p[i] + total;
    }

    // Apply discount
    cout << "\nEnter discount percentage: ";
    cin >> discount;

    float discountAmount = (discount / 100) * total;
    float finalAmount = total - discountAmount;

    cout << "\nTotal: Rs " << total << "\n";
    cout << "Discount: Rs " << discountAmount << "\n";
    cout << "Final Bill: Rs " << finalAmount << "\n";

    return 0;
}
