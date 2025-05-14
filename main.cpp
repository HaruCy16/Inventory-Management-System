#include <iostream>
#include <string>
using namespace std;

/*
    FEATURES AND FUNCTIONALITIES
    User Introduction
    Add Product
    Update Product
    Delete Product
    Display Inventory
    Exit Program
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
            } else {
                cout << "Inventory is full. Cannot add more products." << endl;
                return;
            }
        }
    
        void displayInventory() {
            if(count >= 1){
                cout << "**************************************************" << endl;
                cout << "                 Product Details:                 " << endl;
                cout << "**************************************************" << endl;

                cout << "Product Name     | Quantity      | Price          " << endl;
                for (int i = 0; i < count; i++) {
                    cout << products[i].getProductName() << "            | " 
                        << products[i].getProductQuantity() << "        | " 
                        << products[i].getProductPrice() << "\n";
                }
            } else {
                cout << "Inventory is empty!\n";
            }
        }

        //Update product logic
        bool updateProductByName( string &name, int newQuantity, double newPrice) {
            for (int i = 0; i < count; i++) {
                if (products[i].getProductName() == name) {
                    products[i].setQuantity(newQuantity);
                    products[i].setPrice(newPrice);
                    return true; // success
                }
            }
            return false; // product not found
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

    cout << "**************************************************" << endl;
    cout << "                 Adding Product                  " << endl;
    cout << "**************************************************" << endl;

    cout << "Enter product name: ";
    cin.ignore(1000,'\n');
    getline(cin, name);

    //Check product existence
    for (int i = 0; i < inventory.getCount(); i++) {
        if (inventory.getProduct(i).getProductName() == name) {
            cout << "\nProduct already exists in inventory.\n";
            return;
        }
    }

    cout << "Enter product quantity (for " << name << "): ";
    cin >> quantity;

    cout << "Enter product price (for " << name << "): ";
    cin >> price;


    Product p;
    p.setProductInformation(name, price, quantity);
    inventory.addProduct(p);

    //Input checker for quantity and price
    if (quantity < 0) {
        cout << "Invalid quantity! Quantity cannot be negative.\n" << endl;
        return;
    } else if (price < 0) {
        cout << "Invalid price! Price cannot be negative.\n" << endl;
        return;
    } else {
        cout << "\nProduct added successfully!\n" << endl;
    }
}

//UPDATE PRODUCT FUNCTION
void updateProduct(Inventory &inventory) {
    cin.ignore(1000, '\n'); // Clean buffer

    string productName;
    cout << "Enter the full product name to update: ";
    getline(cin, productName);

    int newQuantity;
    double newPrice;

    if (inventory.updateProductByName(productName, newQuantity, newPrice)) {
        cout << "Enter new quantity for '" << productName << "': ";
        cin >> newQuantity;

        cout << "Enter new price for '" << productName << "': ";
        cin >> newPrice;

        cout << "Product '" << productName << "' updated successfully.\n";
    } else {
        cout << "Product not found!\n";
    }
}


//Function to delete product from the inventory
void deleteProduct(Inventory &inventory) {
    cout << "**************************************************" << endl;
    cout << "                 Deleting Product                 " << endl;
    cout << "**************************************************" << endl;

    string productName;

    cin.ignore(1000,'\n');
    cout << "Enter product name to delete: ";
    getline(cin, productName);

    if (inventory.removeProductByName(productName)) {
        cout << "Product deleted successfully." << endl;
    } else {
        cout << "Product not found!\n" << endl; //ERROR HANDLING
    }
}

int main(){
    //User Introduction
    string personName;
    int courtesyTitleChoice;

    cout << "Enter your name: ";
    getline(cin, personName);

    cout << "Hi " << personName << ", what is your courtesy title?" << endl;
    cout << "    [1] Mr." << endl;
    cout << "    [2] Ms." << endl;
    cout << "Enter the number of your choice: ";
    cin >> courtesyTitleChoice;

    if (courtesyTitleChoice == 1){
        cout << "\nHello, Mr. " << personName << "! Welcome to the Inventory System\n"<< endl;
    } else if (courtesyTitleChoice == 2){
        cout << "\nHello, Ms. " << personName << "! Welcome to the Inventory System\n" << endl;
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
        } else {
            cout << "Ms. " << personName << ", please enter the number of your choice: ";
        }

        cin >> inventoryChoice;
        cout << endl;

        switch (inventoryChoice){
            case 1:
                addProduct(inventory);
                break;
            case 2:
                updateProduct(inventory);
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
    } while (true);
    
    return 0;
}