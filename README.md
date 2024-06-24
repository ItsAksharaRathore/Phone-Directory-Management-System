# Phone Directory Management System

## Introduction

The Phone Directory Management System is a robust application developed by Akshara Rathore and Vaibhav Sharma. It allows users to efficiently manage their contacts through a command-line interface. This system supports adding, modifying, deleting, searching, importing, exporting, and displaying contacts stored in a doubly linked list.

### Features

- **Add Contact:** Add a new contact with a name and phone number. Contacts are automatically sorted alphabetically by name upon insertion.
  
- **Import and Export:** Import contacts from a CSV file into the directory and export contacts to either CSV or TXT formats for backup or sharing purposes.
  
- **Modify Contact:** Modify contact details either by name or phone number. Update contact names or numbers seamlessly.
  
- **Delete Contact:** Delete contacts from the directory using either name or phone number. Maintain an organized list of active contacts.
  
- **Display Directory:** View all contacts in the directory, including their index, name, and phone number. Easily navigate through entries.
  
- **Search Contacts:** Find specific contacts by name or phone number and display detailed information quickly.
  
- **Directory Size:** Check the total number of contacts currently stored in the directory.
  
- **Clear Directory:** Remove all contacts from the directory at once, starting fresh when needed.

### Implementation Details

The system is implemented in C++ using a doubly linked list, providing efficient insertion, deletion, and traversal operations. Contacts are sorted upon insertion to maintain alphabetical order by name, enhancing readability and search efficiency. Dynamic index updating ensures accurate indexing of contacts as operations are performed.

## How to Use?

### Installation and Setup

1. **Clone the Repository:**
   - Open your terminal or command prompt.
   - Clone the repository using the following command:
     ```bash
     git clone https://github.com/itsAksharaRathore/Phone-Directory-Management-System.git
     ```
   - Navigate into the project directory:
     ```bash
     cd Phone-Directory-Management-System
     ```

2. **Compile the Program:**
   - Compile the main.cpp file to create an executable:
     ```bash
     g++ main.cpp -o phone_directory
     ```

3. **Run the Program:**
   - Execute the compiled program:
     ```bash
     ./phone_directory
     ```
   - This command will start the Phone Directory Management System.

### User Interface

Upon running the program, you will be presented with a command-line interface (CLI) that offers various functionalities to manage your phone directory.

### Main Menu

The main menu allows you to choose from several options:

- **1. Create New Contact:** Add a new contact to the directory by entering the contact's name and phone number.
- **2. Import Contacts:** Import contacts from a CSV file into the directory.
- **3. Export Contacts:** Export contacts from the directory to either a CSV or TXT file.
- **4. Modify Contact:** Update existing contact details, such as changing the name or phone number.
- **5. Delete Contact:** Remove a contact from the directory using either their name or phone number.
- **6. Display Directory:** View all contacts currently stored in the directory.
- **7. Search Contact (by Name):** Search for a contact by their name and display their details.
- **8. Search Contact (by Number):** Search for a contact by their phone number and display their details.
- **9. Show Size of Directory:** Display the total number of contacts in the directory.
- **10. Clear Directory:** Remove all contacts from the directory.

### Using the Options

#### Adding a New Contact (Option 1)

- Select option 1 from the main menu.
- Enter the name and phone number of the new contact as prompted.
- The contact will be added to the directory and sorted alphabetically by name.

#### Importing Contacts (Option 2)

- Select option 2 from the main menu.
- Ensure your contacts are stored in a CSV file formatted with "name,phone_number".
- The program will import contacts from the CSV file into the directory.

#### Exporting Contacts (Option 3)

- Select option 3 from the main menu.
- Choose between exporting contacts to a CSV or TXT file format.
- The program will export all contacts in the directory to the selected file format.

#### Modifying a Contact (Option 4)

- Select option 4 from the main menu.
- Choose whether to modify the contact by name or phone number.
- Enter the new name or number for the contact you wish to update.

#### Deleting a Contact (Option 5)

- Select option 5 from the main menu.
- Choose whether to delete the contact by name or phone number.
- Confirm deletion to remove the selected contact from the directory.

#### Displaying the Directory (Option 6)

- Select option 6 from the main menu.
- The program will display a list of all contacts in the directory.
- Each contact's index, name, and phone number will be shown.

#### Searching for a Contact (Options 7 and 8)

- Select option 7 to search for a contact by their name.
- Select option 8 to search for a contact by their phone number.
- Enter the name or number of the contact you wish to find.
- The program will display the details of the contact if found.

#### Showing the Size of the Directory (Option 9)

- Select option 9 from the main menu.
- The program will display the total number of contacts currently stored in the directory.

#### Clearing the Directory (Option 10)

- Select option 10 from the main menu.
- Confirm to clear all contacts from the directory.
- This action will reset the directory to an empty state.

### Exiting the Program

To exit the Phone Directory Management System, simply choose option 0 or follow the on-screen instructions.

### Additional Notes

- **Error Handling:** The program includes basic error handling for invalid inputs and file operations.
- **Sorting:** Contacts are automatically sorted alphabetically by name upon insertion to maintain order.
- **File Formats:** CSV and TXT formats are supported for importing and exporting contacts.

## Usage

1. **Adding a Contact:**
   - Enter the name and phone number of the contact you wish to add.
   - Contacts are automatically sorted alphabetically by name upon insertion.

2. **Modifying a Contact:**
   - Choose to modify either the name or phone number of an existing contact.
   - Enter the new details to update the contact's information.

3. **Deleting a Contact:**
   - Select the contact to delete based on either their name or phone number.
   - Remove unwanted contacts to keep your directory organized.

4. **Searching for a Contact:**
   - Search for a contact by entering their name or phone number.
   - View detailed information about specific contacts quickly.

5. **Importing and Exporting Contacts:**
   - Import contacts from an existing CSV file into the directory.
   - Export contacts to CSV or TXT formats for backup or sharing purposes.

6. **Displaying the Directory:**
   - Display all contacts stored in the directory, including their index, name, and phone number.
   - Navigate through contacts efficiently using the displayed indices.

7. **Clearing the Directory:**
   - Clear all contacts from the directory at once to start fresh when needed.

## Contributors

- **Akshara Rathore** - [@itsAksharaRathore](https://github.com/itsAksharaRathore)
- **Vaibhav Sharma** - [@itsVaibhavSharma](https://github.com/itsVaibhavSharma)

## Acknowledgments
 
We would like to express our gratitude to our mentors and professors who provided invaluable guidance and support throughout the development of this project.
