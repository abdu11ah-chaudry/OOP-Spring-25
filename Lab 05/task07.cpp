#include <iostream>
using namespace std;

class Product {
public:
    int ID;
    string name;
    int quantity;

    Product() {} 

    Product(int id, string n, int q) {
        ID=id;
        name=n;
        quantity=q;
    }

    void display() const {
        cout<<"-----------------------------"<<endl;
        cout<<"Product ID: " <<ID<<endl;
        cout<<"Product Name: " <<name<<endl;
        cout<<"Quantity in Stock: "<<quantity<<endl;
    }
};

class Inventory {
private:
    Product products[10];
    int count;
public:

    Inventory() : count(0) {} 

    void addProduct(int id, string name, int quantity) {
        if (count < 100) { 
            products[count++] = Product(id, name, quantity);
        } else {
            cout << "Inventory is full!"<<endl;
        }
    }

    void sortProducts() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (products[i].name > products[j].name) {
                    swap(products[i], products[j]); 
                }
            }
        }
    }

    void searchProductByID(int id) const {
        for (int i = 0; i < count; i++) {
            if (products[i].ID == id) {
                products[i].display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found.\n";
    }

    void displayAllProducts() const {
        if (count == 0) {
            cout << "No products in inventory.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            products[i].display();
        }
    }
};

int main() {
    Inventory inventory;


    inventory.addProduct(101, "Laptop", 5);
    inventory.addProduct(102, "Chair", 10);
    inventory.addProduct(103, "Apple", 20);
    inventory.addProduct(104, "Table", 7);

    cout<<"Before Sorting: "<<endl;
    inventory.displayAllProducts();

    inventory.sortProducts();
    cout<<endl<<"After Sorting Alphabetically:"<<endl;
    inventory.displayAllProducts();

    cout<<endl<<"Searching for Product with ID 102:"<<endl;
    inventory.searchProductByID(102);

    return 0;
}
