# Property Management System

## Purpose
The Property Management System is a command-line application designed to manage listings of properties for sale or rent. It allows users to perform CRUD (Create, Read, Update, Delete) operations on property records stored in a text file, ensuring data persistence between different sessions. The system also provides input validation to prevent errors and ensure data integrity.

## Design Decisions
- **Command Line Interface (CLI):** All interactions with the application occur via the command line interface, providing a simple and intuitive user experience.
- **Data Persistence:** Property data is stored in a text file (`data.txt`) to ensure persistence between different sessions, enabling users to retrieve and modify property information over time.
- **Modular Design:** The code is divided into logical modules and functions for better organization and reusability, enhancing maintainability and scalability.
- **Input Validation:** User inputs are validated to prevent errors and ensure the integrity of the property data, enhancing the reliability of the application.
- **CRUD Operations:** Users can create, read, update, and delete property records, providing full control over property management tasks.

## Algorithms and Data Structures
- **Input Validation:** Basic input validation techniques such as checking for empty inputs, validating numerical inputs, and ensuring unique property IDs are employed to validate user inputs.
- **File I/O Operations:** Simple file input/output operations are used to read property data from and write property data to the `data.txt` file for data persistence.
- **Vector:** The standard library `vector` is utilized to store property records, providing dynamic resizing and efficient access to property data.

## Functions/Modules Created
1. **Main Menu:** The main menu module provides options for users to perform various property management tasks, including listing properties, adding properties, updating properties, deleting properties, and exiting the application.
2. **List Properties Function (`listProperties`):** This function lists all properties currently stored in the system, displaying their IDs, addresses, prices, and status (for sale or rent).
3. **Add Property Function (`addProperty`):** This function allows users to add a new property to the system by providing details such as ID, address, price, and status (for sale or rent).
4. **Update Property Function (`updateProperty`):** This function enables users to update an existing property's information, such as address, price, and status (for sale or rent), by specifying the property's ID.
5. **Delete Property Function (`deleteProperty`):** This function allows users to delete a property from the system by specifying the property's ID.
6. **Save Data to File Function (`saveDataToFile`):** This function saves the current property data stored in memory to the `data.txt` file for data persistence.
7. **Read Data from File Function (`readDataFromFile`):** This function reads property data from the `data.txt` file into memory when the application starts, ensuring that existing property records are loaded into the system.

## How to Use the Software
1. **Installation/Setup:**
   - Download or clone the project repository to your local machine.
   - Compile the source code using a C++ compiler.
2. **Running the Application:**
   - Open a command-line interface.
   - Navigate to the directory containing the compiled executable file.
   - Run the executable file to launch the Property Management System.
3. **Using the Application:**
   - Upon launching the application, the main menu will be displayed.
   - ![Screenshot_28](https://github.com/AktanAlmazovich/Final-project/assets/163660855/cccaa3af-b2e5-4b3e-ae1c-c85376a9f138)
   - Follow the on-screen prompts to perform property management tasks:
     - Enter '1' to list properties.
     - Enter '2' to add a new property.
     - Enter '3' to update an existing property.
     - Enter '4' to delete a property.
     - Enter '5' to exit the application.

### List Properties
- To list all properties currently stored in the system:
  - Enter `1` at the main menu prompt and press Enter.
  - The system will display a list of all properties, showing their IDs, addresses, prices, and status (for sale or rent).

### Add Property
- To add a new property to the system:
  - Enter `2` at the main menu prompt and press Enter.
  - Follow the prompts to enter the details of the new property:
    ```
    Enter property ID: 1
    Enter property address: University Ala-Too
    Enter property price: $1000000
    Is the property for sale or rent? (Sale/Rent): Sale
    ```
  - If the ID already exists in the system, you will receive an error message and be returned to the main menu.

### Update Property
- To update an existing property's information:
  - Enter `3` at the main menu prompt and press Enter.
  - You will be prompted to enter the ID of the property you want to update:
    ```
    Enter property ID to update: 1
    ```
  - If the property ID is found, you will be prompted to enter the new details for the property:
    ```
    Enter new property address: KNU University
    Enter new property price: $10000
    Is the property for sale or rent? (Sale/Rent): Sale
    ```
  - The system will update the property information and confirm the update.
  - If the property ID is not found, you will receive an error message and be returned to the main menu.

### Delete Property
- To delete a property from the system:
  - Enter `4` at the main menu prompt
  - You will be prompted to enter the ID of the property you want to delete:
    ```
    Enter property ID to delete: 1
    Property deleted successfully.
    ```
### Exit Program
- To exit program 
  - Enter `5` at the main menu prompt
  - You will be out of the program terminal


