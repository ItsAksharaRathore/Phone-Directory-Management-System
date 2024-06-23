#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure for each contact node in the linked list
struct node
{
    long long int number; // Phone number
    int index;            // Index in the directory
    string name;          // Name of the contact
    node *next;           // Pointer to the next node
    node *prev;           // Pointer to the previous node
} *head = NULL;           // Head pointer of the linked list

// Function to update indices of all nodes in the linked list
void updateIndex()
{
    int index = 1;
    node *temp = head;
    while (temp != NULL)
    {
        temp->index = index; // Update index
        temp = temp->next;   // Move to the next node
        index++;
    }
}

// Function to add a new contact to the directory
void addNumber(string name, long long int number)
{
    node *p = new node; // Create a new node
    p->name = name;     // Assign name
    p->number = number; // Assign number

    node *current = head;
    node *prev = NULL;

    // Traverse until correct position or end of list is found
    while (current != NULL && name > current->name)
    {
        prev = current;
        current = current->next;
    }

    // Insert at the beginning if list is empty or new name is smallest
    if (prev == NULL)
    {
        p->next = head;
        if (head != NULL)
        {
            head->prev = p;
        }
        head = p;
    }
    else
    {
        // Insert at correct position in the middle or end of the list
        prev->next = p;
        p->prev = prev;
        p->next = current;
        if (current != NULL)
        {
            current->prev = p;
        }
    }
    updateIndex(); // Update indices after insertion
    cout << "Contact Created Successfully." << endl;
}

// Function to display all contacts in the directory
void display()
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "Directory is empty." << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << "Index: " << temp->index << endl
                 << "Contact Name: " << temp->name << endl
                 << "Number: " << temp->number << endl
                 << endl;
            temp = temp->next;
        }
    }
}

// Function to modify contact details by phone number
void modify(long long int number)
{
    node *current = head;

    // Traverse until contact with specified number is found
    while (current != NULL && current->number != number)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        cout << "Contact doesn't exist." << endl;
        return;
    }
    cout << "Enter new name: ";
    cin >> current->name; // Update contact name

    cout << "Contact Modified Successfully." << endl;
}

// Function to modify contact details by name
void modify(string name)
{
    node *current = head;

    // Traverse until contact with specified name is found
    while (current != NULL && current->name != name)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        cout << "Contact doesn't exist." << endl;
        return;
    }
    cout << "Enter new number: ";
    cin >> current->number; // Update contact number

    cout << "Contact Modified Successfully." << endl;
}

// Function to delete contact by phone number
void deleteNumber(long long int number)
{
    node *current = head;
    node *prev = NULL;

    // Traverse until contact with specified number is found
    while (current != NULL && current->number != number)
    {
        prev = current;
        current = current->next;
    }

    // Handle if contact not found
    if (current == NULL)
    {
        cout << "Contact doesn't exist" << endl;
        return;
    }

    // Remove from the beginning of the list
    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        // Remove from middle or end of the list
        prev->next = current->next;
        if (current->next != NULL)
        {
            (current->next)->prev = prev;
        }
    }
    updateIndex(); // Update indices after deletion
    cout << "Contact Deleted Successfully." << endl;
}

// Function to delete contact by name
void deleteName(string name)
{
    node *current = head;
    node *prev = NULL;

    // Traverse until contact with specified name is found
    while (current != NULL && current->name != name)
    {
        prev = current;
        current = current->next;
    }

    // Handle if contact not found
    if (current == NULL)
    {
        cout << "Contact doesn't exist" << endl;
        return;
    }

    // Remove from the beginning of the list
    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        // Remove from middle or end of the list
        prev->next = current->next;
        if (current->next != NULL)
        {
            (current->next)->prev = prev;
        }
    }
    updateIndex(); // Update indices after deletion
    cout << "Contact Deleted Successfully." << endl;
}

// Function to count the number of contacts in the directory
int contactCount()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

// Function to search for a contact by name
void searchName(string name)
{
    if (head == NULL)
    {
        cout << "Directory is empty." << endl;
    }
    else
    {
        node *temp = head;
        while (temp->name != name)
        {
            temp = temp->next;
        }
        cout << "Index: " << temp->index << endl
             << "Contact Name: " << temp->name << endl
             << "Number: " << temp->number << endl
             << endl;
    }
}

// Function to search for a contact by phone number
void searchNumber(long long int number)
{
    if (head == NULL)
    {
        cout << "Directory is empty." << endl;
    }
    else
    {
        node *temp = head;
        while (temp->number != number)
        {
            temp = temp->next;
        }
        cout << "Index: " << temp->index << endl
             << "Contact Name: " << temp->name << endl
             << "Number: " << temp->number << endl
             << endl;
    }
}

// Function to export the contact directory to CSV or TXT file
void exportDirectory()
{
    int ch;
    cout << "Choose File Format: " << endl
         << "1. CSV" << endl
         << "2. TXT" << endl
         << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> ch;

    if (ch == 1)
    {
        fstream file;
        file.open("Directory_export.csv", ios::out);
        if (!file.is_open())
        {
            cout << "Directory cannot be exported." << endl;
            return;
        }

        file << "INDEX,NAME,PHONE NUMBER" << endl;
        node *temp = head;
        while (temp != NULL)
        {
            file << temp->index << "," << temp->name << "," << temp->number << endl;
            temp = temp->next;
        }
        file.close();
    }
    else if (ch == 2)
    {
        fstream file;
        file.open("Directory_export.txt", ios::out);
        if (!file.is_open())
        {
            cout << "Directory cannot be exported." << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            file << "Index: " << temp->index << endl
                 << "Contact Name: " << temp->name << endl
                 << "Number: " << temp->number << endl
                 << endl;
            temp = temp->next;
        }
        file.close();
    }
    else
    {
        return;
    }
    cout << "Directory exported successfully." << endl;
}

// Function to import contacts from CSV file
void importDirectory()
{
    fstream file;
    file.open("Directory_export.csv", ios::in);

    if (!file.is_open())
    {
        cout << "File doesn't exists." << endl;
        return;
    }

    head = NULL;
    string s;
    getline(file, s); // Skip header line

    int index;
    while (getline(file, s))
    {
        string ind;
        string name;
        string phone;
        int i;
        for (i = 0; s[i] != ','; i++)
        {
            ind = ind + s[i]; // Read index
        }
        for (i = i + 1; s[i] != ','; i++)
        {
            name = name + s[i]; // Read name
        }
        for (i = i + 1; s[i] != '\0'; i++)
        {
            phone = phone + s[i]; // Read phone number
        }

        index = stoi(ind);                   // Convert index string to integer
        long long int number = stoll(phone); // Convert phone number string to long long int

        // Create a new node with imported data
        node *p = new node;
        p->name = name;
        p->index = index;
        p->number = number;
        p->prev = p->next = NULL;

        // Insert node into the linked list
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
            p->prev = temp;
        }
    }
    file.close();

    cout << "Directory Imported Successfully." << endl;
}

// Main function to run the directory management system
int main()
{
    // Display project information
    cout << endl
         << "SKILL BASED MINI PROJECT BY: " << endl
         << "AKSHARA RATHORE (@itsAksharaRathore)" << endl
         << "VAIBHAV SHARMA (@itsVaibhavSharma)" << endl;

    int ch; // Choice variable for menu selection

    // Display menu options
    cout << "Enter 1 to CREATE NEW CONTACT" << endl
         << "Enter 2 to IMPORT CONTACTS" << endl
         << "Enter 3 to EXPORT CONTACTS" << endl
         << "Enter 4 to MODIFY CONTACT" << endl
         << "Enter 5 to DELETE CONTACT" << endl
         << "Enter 6 to DISPLAY DIRECTORY" << endl
         << "Enter 7 to SEARCH CONTACT (using name)" << endl
         << "Enter 8 to SEARCH CONTACT (using number)" << endl
         << "Enter 9 to SHOW SIZE OF DIRECTORY" << endl
         << "Enter 10 to CLEAR DIRECTORY" << endl
         << "Enter 0 to EXIT" << endl;

    do
    {
        cout << endl;
        cout << "Enter Function: ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            break;
        case 1:
        {
            long long int number;
            string name;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter number: ";
            cin >> number;

            addNumber(name, number); // Add new contact
        }
        break;
        case 2:
            importDirectory(); // Import contacts from file
            break;
        case 3:
            exportDirectory(); // Export contacts to file
            break;
        case 4:
        {
            int choice;
            cout << "Enter 1 to modify Name or Enter 2 to modify Number: ";
            cin >> choice;
            if (choice == 1)
            {
                long long int number;
                cout << "Enter number: ";
                cin >> number;
                modify(number); // Modify contact by number
            }
            else if (choice == 2)
            {
                string name;
                cout << "Enter name: ";
                cin >> name;
                modify(name); // Modify contact by name
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
        }
        break;
        case 5:
        {
            int choice;
            cout << "Enter 1 to delete using Name or Enter 2 to delete using Number: ";
            cin >> choice;
            if (choice == 2)
            {
                long long int number;
                cout << "Enter number: ";
                cin >> number;
                deleteNumber(number); // Delete contact by number
            }
            else if (choice == 1)
            {
                string name;
                cout << "Enter name: ";
                cin >> name;
                deleteName(name); // Delete contact by name
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
        }
        break;
        case 6:
            display(); // Display all contacts
            break;
        case 7:
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            searchName(name); // Search contact by name
        }
        break;
        case 8:
        {
            long long int number;
            cout << "Enter number: ";
            cin >> number;
            searchNumber(number); // Search contact by number
        }
        break;
        case 9:
            cout << "Total no. of Contacts: " << contactCount() << endl; // Display total number of contacts
            break;
        case 10:
            head = NULL; // Clear the directory
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

    } while (ch != 0);

    // Display project credits and exit message
    cout << endl
         << "SKILL BASED MINI PROJECT BY: " << endl
         << "AKSHARA RATHORE (@itsAksharaRathore)" << endl
         << "VAIBHAV SHARMA (@itsVaibhavSharma)" << endl
         << endl
         << "PROGRAM EXITED!!";

    return 0;
}
