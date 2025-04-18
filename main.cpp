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

//Product class to represent each product in the inventory
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
};

const int MAXIMUM_PRODUCTS_TO_STORE = 100; // Maximum number of products in the inventory

class Inventory
{

};

//Function to add product to the inventory
void addProduct(Product product, Inventory inventory){
    cout << "**************************************************" << endl;
    cout << "                 Adding Product                   " << endl;
    cout << "**************************************************" << endl;

    string productName;
    double productPrice;
    int productQuantity;
    cout << "Enter product name: ";
    cin >> productName;
    cout << "Enter product quantity (for" << productName << "): ";
    cin >> productQuantity;
    cout << "Enter product price (for" << productName << "): ";
    cin >> productPrice;


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
                // Call addProduct function
                break;
            case 2:
                // Call updateProduct function
                break;
            case 3:
                // Call deleteProduct function
                break;
            case 4:
                // Call displayInventory function
                break;
            case 5:
                cout << "Are you sure you want to exit? (Y/N)"<< endl;
                char exitChoice;
                cin >> exitChoice;
                if (exitChoice == 'Y' || exitChoice == 'y'){
                    cout << "Thank you for using the Inventory System. Goodbye!" << endl;
                    return 0;
                } else if (exitChoice == 'N' || exitChoice == 'n'){
                    cout << "Returning to the main menu..." << endl;
                } else {
                    cout << "Invalid Input! Program Terminated."<< endl;
                    return 0;
                }
                break;
            default:
                cout << "Invalid Input! Program Terminated."<< endl;
                return 0;
        }
    } while (inventoryChoice != 6);
}