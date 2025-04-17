#include <iostream>
#include <fstream>
using namespace std;

class Product
{
  private:
    string name;
    double price;
    int quantity;
  
  public:
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}

    void display() const
    {
        cout << "Product Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    void saveToFile(ofstream &file) const
    {
        file << name << endl;
        file << price << endl;
        file << quantity << endl;
    }
};

int main()
{
    string name;
    double price;
    int quantity;

    cout << "Enter product name: ";
    getline(cin, name);
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter product quantity: ";
    cin >> quantity;

    Product product(name, price, quantity);

    ofstream file("product.txt");
    if (file.is_open())
    {
        product.saveToFile(file);
        file.close();
        cout << "Product saved to file." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    return 0;
}