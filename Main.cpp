#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Property {
    string id;
    string address;
    double price;
    bool isForSale;
};

vector<Property> properties;

void saveDataToFile() {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (const auto& property : properties) {
            file << property.id << "," << property.address << "," << property.price << "," << (property.isForSale ? "Sale" : "Rent") << "\n";
        }
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

void readDataFromFile() {
    ifstream file("data.txt");
    if (file.is_open()) {
        properties.clear();
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Property property;
            getline(ss, property.id, ',');
            getline(ss, property.address, ',');
            ss >> property.price;
            ss.ignore();
            string saleStatus;
            getline(ss, saleStatus, ',');
            property.isForSale = (saleStatus == "Sale");
            properties.push_back(property);
        }
        file.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }
}

void printProperty(const Property& property) {
    cout << "ID: " << property.id << endl;
    cout << "Address: " << property.address << endl;
    cout << "Price: $" << fixed << setprecision(2) << property.price << endl;
    cout << "Status: " << (property.isForSale ? "For Sale" : "For Rent") << endl;
}

void listProperties() {
    if (properties.empty()) {
        cout << "No properties found." << endl;
    } else {
        for (const auto& property : properties) {
            printProperty(property);
            cout << endl;
        }
    }
}

void addProperty() {
    Property property;
    cout << "Is the property for sale or rent? (Sale/Rent): ";
    string status;
    cin >> status;
    property.isForSale = (status == "Sale" || status == "sale");
    cout << "Enter property price: $";
    cin >> property.price;
    cout << "Enter property ID: ";
    cin >> property.id;
    cout << "Enter property address: ";
    cin.ignore();
    getline(cin, property.address);
    properties.push_back(property);
    saveDataToFile();
    cout << "Property added successfully." << endl;
}

void updateProperty() {
    string id;
    cout << "Enter property ID to update: ";
    cin >> id;
    bool found = false;
    for (auto& property : properties) {
        if (property.id == id) {
            cout << "Enter new property address: ";
            cin.ignore();
            getline(cin, property.address);
            cout << "Enter new property price: $";
            cin >> property.price;
            cout << "Is the property for sale or rent? (Sale/Rent): ";
            string status;
            cin >> status;
            property.isForSale = (status == "Sale" || status == "sale");
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Property with ID " << id << " not found." << endl;
    } else {
        saveDataToFile();
        cout << "Property updated successfully." << endl;
    }
}

void deleteProperty() {
    string id;
    cout << "Enter property ID to delete: ";
    cin >> id;
    auto it = properties.begin();
    while (it != properties.end()) {
        if (it->id == id) {
            it = properties.erase(it);
            saveDataToFile();
            cout << "Property deleted successfully." << endl;
            return;
        } else {
            ++it;
        }
    }
    cout << "Property with ID " << id << " not found." << endl;
}

int main() {
    readDataFromFile();

    char choice;
    do {
        cout << "MENU:\n"
             << "1. List Properties\n"
             << "2. Add Property\n"
             << "3. Update Property\n"
             << "4. Delete Property\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                listProperties();
                break;
            case '2':
                addProperty();
                break;
            case '3':
                updateProperty();
                break;
            case '4':
                deleteProperty();
                break;
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
