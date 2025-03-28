#include<iostream>
using namespace std;

class Product{
protected:
    int ProductID;
    string name;
    double price;
    int stockquantity;
public:
    Product(int id, string n, double pr, int stQuantity):ProductID(id),name(n),price(pr),stockquantity(stQuantity){}

    virtual void applyDiscount(){
        price-=price*0.9;
        cout<<"Price after discount: "<<price<<endl;
    }

    virtual void calculateTotalPrice(){
        cout<<"Total Price: "<<price*stockquantity<<endl;
    }

    virtual void displayProductInfo(){
        cout<<"--------------------"<<endl;
        cout<<"Product ID: "<<ProductID<<endl;
        cout<<"Product Name: "<<name<<endl;
        cout<<"Product Quantity: "<<stockquantity<<endl;
    }

    Product operator+(Product &p)
    {
        return Product(0, "bulk purchase", price+p.price, stockquantity+p.stockquantity);
    }

    friend ostream& operator<<(ostream &output, Product &p);
};

ostream& operator<<(ostream &output, Product &p){
    output<<"--------------------"<<endl;
    output<<"Product ID: "<<p.ProductID<<endl;
    output<<"Product Name: "<<p.name<<endl;
    output<<"Product Quantity: "<<p.stockquantity<<endl;
}

class Electronics:public Product{
private:
    int warrantyPeriod;
    string brand;
public:
    Electronics(int id, string n, double pr, int stQuantity, int wPeriod, string br):Product(id,n,pr,stQuantity),warrantyPeriod(wPeriod),
    brand(br){}
    
    void displayProductInfo() override{
        Product::displayProductInfo();
        cout<<"Warranty Period: "<<warrantyPeriod<<endl;
        cout<<"Brand: "<<brand<<endl;
    }
};

class Clothing:public Product{
private:
    string size;
    string color;
    string fabricMaterial;
public:
    Clothing(int id, string n, double pr, int stQuantity, string sz, string cl, string fbMaterial):Product(id,n,pr,stQuantity),
    size(sz),color(cl),fabricMaterial(fbMaterial){}

    void applyDiscount() override{
        price=price*0.8;
        cout<<"Price after discount: "<<price<<endl;
    }

};

class FoodItem:public Product{
private:
    int calories;
    string expiryDate;
public:
    FoodItem(int id, string n, double pr, int stQuantity, int cal, string expDate):Product(id,n,pr,stQuantity),calories(cal),expiryDate(expDate){}
    
    void calculateTotalPrice() override{
        if(stockquantity>5){
            price=price*0.7;
        }
        cout<<"Total Price: "<<price*stockquantity<<endl;
    }
};

class Book:public Product{
private:
    string author;
    string genre;
public:
    Book(int id, string n, double pr, int stQuantity, string auth, string gen):Product(id,n,pr,stQuantity),
    author(auth),genre(gen){}
    
    void displayProductInfo() override{
        Product::displayProductInfo();
        cout<<"Book's Author Name: "<<author<<endl;
        cout<<"Genre: "<<genre<<endl;
    }
};


int main() {

    Electronics laptop(101, "Laptop", 1200, 5, 2, "Dell");
    Clothing tshirt(102, "T-Shirt", 30, 10, "L", "Red", "Cotton");
    FoodItem pizza(103, "Pizza", 15, 6, 300, "2025-05-10");
    Book novel(104, "The Great Gatsby", 20, 3, "F. Scott Fitzgerald", "Classic");

    
    cout<<"Displaying Product Information:"<<endl;
    laptop.displayProductInfo();
    tshirt.displayProductInfo();
    pizza.displayProductInfo();
    novel.displayProductInfo();

    
    cout<<endl<<"Applying Discount on Clothing:"<<endl;;
    tshirt.applyDiscount();

    
    cout<<endl<<"Calculating Total Prices:";
    laptop.calculateTotalPrice();
    tshirt.calculateTotalPrice();
    pizza.calculateTotalPrice();
    novel.calculateTotalPrice();

    cout<<endl<<"Using Operator Overloading (+) for Bulk Purchase:"<<endl;
    Product bulkOrder = laptop + tshirt;
    cout << bulkOrder;

    return 0;
    
}
