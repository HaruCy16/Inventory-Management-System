#include <iostream>
#include <fstream>
using namespace std;

/*
    FEATURES AND FUNCTIONALITIES
    User Introduction
    Add Product
    Update Product
    Delete Product
    Display Inventory
    Search Product
    Exit Program
    Save Inventory to File
    Load Inventory from File
*/

// Product class (stores product details)
class Product {
    private:
        string name;
        double price;
        int quantity;

    public:
        // Function to set product informations
        void setProductInformation(string productName, double productPrice, int productQuantity) {
            name = productName;
            price = productPrice;
            quantity = productQuantity;
        }

        //Getter functions to retrieve product details
        string getProductName() {
            return name;
        }
        int getProductQuantity() {
            return quantity;
        }
        double getProductPrice() {
            return price;
        }

        //Setters for update product
        void setQuantity(int q) { quantity = q; }
        void setPrice(double p) { price = p; }

};

const int MAXIMUM_PRODUCTS_TO_STORE = 100; // Maximum number of products in the inventory

class Inventory {
    private:
        Product products[MAXIMUM_PRODUCTS_TO_STORE];
        int count = 0;
    
    public:
        void addProduct(Product p) {
            if (count < MAXIMUM_PRODUCTS_TO_STORE) {
                products[count] = p;
                count++;
            }
        }
    
        void displayInventory() {
            cout << "**************************************************" << endl;
            cout << "                 Product Details:                 " << endl;
            cout << "**************************************************" << endl;
            cout << "Product Name     | Quantity      | Price          " << endl;
            for (int i = 0; i < count; i++) {
                cout << products[i].getProductName() << "            | " 
                     << products[i].getProductQuantity() << "        | " 
                     << products[i].getProductPrice() << endl;
            }
        }

        //Delete product logic
        bool removeProductByName(string productName) {
            for (int i = 0; i < count; i++) {
                if (products[i].getProductName() == productName) {
                    // Shift the rest of the array left
                    for (int j = i; j < count - 1; j++) {
                        products[j] = products[j + 1];
                    }
                    count--; // Reduce the product count
                    return true; // Deletion successful
                }
            }
            return false; // Product not found
        }
    
        int getCount() {
            return count;
        }
    
        Product getProduct(int index) {
            return products[index];
        }
};

//Function to add product to the inventory
void addProduct(Inventory &inventory) {
    string name;
    double price;
    int quantity;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product quantity (for " << name << "): ";
    cin >> quantity;
    cout << "Enter product price (for " << name << "): ";
    cin >> price;

    Product p;
    p.setProductInformation(name, price, quantity);
    inventory.addProduct(p);
}

//Function to update product in the inventory
void updateProduct(Product product, Inventory inventory){
    cout << "**************************************************" << endl;
    cout << "                 Updating Product                 " << endl;
    cout << "**************************************************" << endl;

    string productName;
    double productPrice;
    int productQuantity;
    cout << "Enter product name: ";
    cin >> productName;

    // bool productFound = false;
    for (int i = 0; i < inventory.getCount(); i++) {
        if (inventory.getProduct(i).getProductName() == productName) {
            cout << "Enter new product quantity: ";
            cin >> productQuantity;
            cout << "Enter new product price: ";
            cin >> productPrice;

            product.setProductInformation(productName, productPrice, productQuantity);
            inventory.addProduct(product);
            // productFound = true;
            break;
        }
    }
}

//Function to delete product from the inventory
void deleteProduct(Inventory &inventory) {
    cout << "**************************************************" << endl;
    cout << "                 Deleting Product                 " << endl;
    cout << "**************************************************" << endl;

    string productName;
    cout << "Enter product name to delete: ";
    cin >> productName;

    if (inventory.removeProductByName(productName)) {
        cout << "Product '" << productName << "' deleted successfully." << endl;
    } else {
        cout << "Product '" << productName << "' not found in inventory." << endl;
    }
}

//STILL ON GOING AND TESTING
void saveToFile(Inventory &inventory) {
    ofstream file("inventory.txt");
    for (int i = 0; i < inventory.getCount(); i++) {
        Product p = inventory.getProduct(i);
        file << p.getProductName() << " " << p.getProductQuantity() << " " << p.getProductPrice() << endl;
    }
    file.close();
}

void loadFromFile(Inventory &inventory) {
    ifstream file("inventory.txt");
    string name;
    int quantity;
    double price;

    while (file >> name >> quantity >> price) {
        Product p;
        p.setProductInformation(name, price, quantity);
        inventory.addProduct(p);
    }

    file.close();
}

int main(){
    //User Introduction
    string personName;
    int courtesyTitleChoice;

    cout << "Enter your name: ";
    cin >> personName;
    cout << "Hi " << personName << ", what is your courtesy title?" << endl;
    cout << "    [1] Mr." << endl;
    cout << "    [2] Ms." << endl;
    cout << "Enter the number of your choice: ";
    cin >> courtesyTitleChoice;

    if (courtesyTitleChoice == 1){
        cout << "Hello, Mr. " << personName << "! Welcome to the Inventory System"<< endl;
    } else if (courtesyTitleChoice == 2){
        cout << "Welcome Ms. " << personName << "! Welcome to the Inventory System" << endl;
    } else {
        cout << "Invalid Input! Program Terminated." << endl;
        return 0;
    }

    //Display the main menu
    Inventory inventory;
    int inventoryChoice;
    do{
        cout << "**************************************************" << endl;
        cout << "                Inventory System                  " << endl;
        cout << "**************************************************" << endl;
        cout << "What would you ike to do?" << endl;
        cout << "       [1] Add Product" << endl;
        cout << "       [2] Update Product" << endl;
        cout << "       [3] Delete Product" << endl;
        cout << "       [4] Display Inventory" << endl;
        cout << "       [5] Exit Program" << endl;

        if(courtesyTitleChoice == 1){
            cout << "Mr. " << personName << ", please enter the number of your choice: ";
        } else{
            cout << "Ms. " << personName << ", please enter the number of your choice: ";
        }
        cin >> inventoryChoice;

        switch (inventoryChoice){
            case 1:
                addProduct(inventory);
                cout << "Product added successfully!\n" << endl;
                break;
            case 2:
                updateProduct(inventory.getProduct(0), inventory); // Update the first product for demonstration
                cout << "Product updated successfully!\n" << endl;
                break;
            case 3:
                deleteProduct(inventory);
                break;
            case 4:
                inventory.displayInventory();
                break;
            case 5:
            char exitChoice;
            do {
                cout << "Are you sure you want to exit? (Y/N): ";
                cin >> exitChoice;

                cin.ignore(1000,'\n');
        
                
                if (exitChoice == 'Y' || exitChoice == 'y') {
                    cout << "\nThank you for using the Inventory System." << endl;
                    return 0;
                } else if (exitChoice == 'N' || exitChoice == 'n') {
                    cout << "\nReturning to the main menu...\n" << endl;
                    break;
                } else {
                    cout << "\nInvalid Input!\n";
                }
            } while (true);
            break;
            default:
                cout << "Invalid Input! Program Terminated."<< endl;
                return 0;
        }
    } while (inventoryChoice != 6);
    
    return 0;
}