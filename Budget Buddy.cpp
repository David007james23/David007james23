#include <iostream>
#include <string>
#include <iomanip> // For setw and fixed
#include <conio.h> // for getch
#include <windows.h> // for color text and background
using namespace std;

struct Add_Expense_Data {
    string Description;
    float Gurano;
    string Category;
    string Date;
    bool Recurring;
};

const int Max_Gastos = 999;
Add_Expense_Data Array_Expenses[Max_Gastos];
int Ginastos = 0;
float Total_Budget = 0;
float Total_Gastos = 0;

bool User_Authenticator() {
    string Password; // User-defined password
    string Entered_Password;
    char choice;

    while (true) {
        system("cls"); // Clear the screen
        system("Color 1F");
        cout << "\n\t\033[1m------------------------------------------------------------ \033[1mBUDGET BUDDY\033[1;3m ----------------------------------------------------------------------------\n" << endl;
        cout << "\t\t\t CHOOSE AN OPTION: \n\n";
        cout << "\t\t\t\t\t1. SET PASSWORD\n";
        cout << "\t\t\t\t\t2. ENTER PASSWORD\n";
        cout << "\t\t\t\t\t3. EXIT";
        cout << "\n\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;

        cout << "\tENTER YOUR CHOICE: ";

        cin >> choice;

        if (choice == '1') {
            system("Color 1F");
            cout << "\n\t\t \033[1;3mENTER YOUR DESIRED PASSWORD: \033[1m";
            cin.ignore(); // Ignore the newline character left in the buffer
            
            char Asterisk;
            while ((Asterisk = getch()) != 13) { // Read characters until Enter is pressed
                if (Asterisk == 8) { // Backspace
                    if (!Password.empty()) {
                        cout << "\b \b"; // Move the cursor back, erase the character, and move back again
                        Password.pop_back(); // Remove the last character from enteredPassword
                    }
                } else {
                    Password.push_back(Asterisk);
                    cout << '*'; // Print asterisk (*) for masking
                }
            }
            
            cout << "\n\n\t\tPASSWORD SET SUCCESSFULLY!\n";
            cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
            getch(); // Wait for spacebar
        } else if (choice == '2') {
            system("Color 1F");
            Entered_Password.clear(); // Clear the entered password for each retry
            cout << "\n\t \033[1;3mENTER PASSWORD TO ACCESS BUDGET BUDDY: \033[1m";
            char Asterisk;
            while ((Asterisk = _getch()) != 13) { // Read characters until Enter is pressed
                if (Asterisk == 8) { // Backspace
                    if (!Entered_Password.empty()) {
                        cout << "\b \b"; // Move the cursor back, erase the character, and move back again
                        Entered_Password.pop_back(); // Remove the last character from enteredPassword
                    }
                } else {
                    Entered_Password.push_back(Asterisk);
                    cout << '*'; // Print asterisk (*) for masking
                }
            }

            if (Entered_Password == Password) {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t\t\tAUTHENTICATION SUCCESSFUL!\n";
                return true;
            } else {
                cout << "\n\n\t\tINCORRECT PASSWORD\n";
                cout << "\n\t\tPLEASE TRY AGAIN.\n" << endl;
                system("pause"); // Wait for user input before clearing the screen
            }
        } else if (choice == '3') {
                system("cls");
                cout << "\n\t\033[1m------------------------------------------------------------ \033[1mBUDGET BUDDY\033[1;3m ----------------------------------------------------------------------------\n" << endl;
                cout << "\t\tExiting.... Hope you like it, thank you!\n";
                cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
                return false;
        } else {
            cout << "Invalid choice. Please try again.\n";
            system("pause");
        }
    }
}



// Function to set the budget
void Budget() {
    system("cls");
    cout << "\n\t\033[1;3m------------------------------------------------------------ \033[1mBUDGET BUDDY\033[1m ----------------------------------------------------------------------------\n" << endl;
    cout << "\t\tEnter your Budget: ";
    cin >> Total_Budget;
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\n\t\tNice! You have ₱" << fixed << setprecision(2)<< Total_Budget << " Budget" << endl;
            cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
    getch();
}

// Function to add an expense
void Add_Expense() {
    system("cls");
    if (Ginastos < Max_Gastos) {
        cout << "Enter expense Description: ";
        cin.ignore();
        getline(cin, Array_Expenses[Ginastos].Description);
        cout << "Enter expense amount: ₱";
        cin >> Array_Expenses[Ginastos].Gurano;
        cout << "Select Category (Groceries, Transportation, School Supplies, Entertainment, Other): ";
        cin.ignore();
        getline(cin, Array_Expenses[Ginastos].Category);
        cout << "Enter expense Date (MM/DD/YYYY): ";
        getline(cin, Array_Expenses[Ginastos].Date);
        cout << "Is this expense Recurring? (1 for Yes, 0 for No): ";
        cin >> Array_Expenses[Ginastos].Recurring;
        cout <<"\n\t\t\t\t\t\t\t\tExpense " << Array_Expenses[Ginastos].Description << " is added successfully!\n" << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";

        Total_Gastos += Array_Expenses[Ginastos].Gurano;
        Ginastos++;

        if (Total_Gastos > Total_Budget && Total_Budget != 0) {
            cout << "\nWarning: Total Expenses exceed the budget!\n";
            cout << endl;
            getch();
        }
        else if (Total_Budget == 0) {
            cout << "\nHow much Budget do you have? Please input your Budget first, thank you!\n";
            cout << endl;
            getch();
        }
    }
    getch();
}

// Function to display expenses
void Display_Expenses() {
    system("cls");
    if (Ginastos == 0) {
    cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------\n" << endl;
        cout << "\nThere are no expenses to Display yet.\n";
        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
        getch();
    }
    else {
    cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------\n";
    cout << setw(30) << "Description:" << setw(30) << "Amount:" << setw(30) << "Category:" << setw(30) << "Date:" << setw(30) << "Recurring:" << endl;
    for (int i = 0; i < Ginastos; ++i) {
        cout << "\nExpense No: " << (i + 1) << "\n";
        cout << setw(27) << Array_Expenses[i].Description << setw(28) << "₱" << setprecision(2) << Array_Expenses[i].Gurano << setw(30) << Array_Expenses[i].Category  << setw(33) << Array_Expenses[i].Date << setw(26) << (Array_Expenses[i].Recurring ? "Yes" : "No") << endl;
    }
        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
     cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
     getch();
    }
}

// Function to search for an expense
void Search_Expense() {
    system("cls");
    if (Ginastos == 0) {
    cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------\n";
        cout << "\nThere are no expenses to search yet.\n";
        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
        getch();
    } else {
        string searchDescription;
        int Search_Number;
        bool Search_Found_Desc = false; // Flag to track if the expense is found by description
        bool Search_Found_Num = false; // Flag to track if the expense is found by number
        
        cout << "Note! Press Enter if you don't know the Description. \n" << "\nEnter the Description of the expense to search: \n";
        cin.ignore(); // Clear the input buffer
        getline(cin, searchDescription);
        cout << "\nSearching for " << searchDescription << ".......\n";
        // Search for the expense by description
        for (int i = 0; i < Ginastos; ++i) {
            if (Array_Expenses[i].Description == searchDescription) {
                cout << "\nSearch Results:" << endl;
                cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------------\n";
                cout << setw(30) << "Description:" << setw(30) << "Amount:" << setw(30) << "Category:" << setw(30) << "Date:" << setw(30) << "Recurring:" << endl;   
                cout << "\nExpense No: " << (i + 1) << "\n";
                cout << setw(27) << Array_Expenses[i].Description << setw(28) << "₱" << setprecision(2) << Array_Expenses[i].Gurano << setw(30) << Array_Expenses[i].Category  << setw(33) << Array_Expenses[i].Date << setw(26) << (Array_Expenses[i].Recurring ? "Yes" : "No") << endl;
    
                cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
                cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
                Search_Found_Desc = true; // Set flag to true if expense is found by description
                break; // Exit the loop once the expense is found
            }
        }
        
        // Check if the expense is not found by description
        if (!Search_Found_Desc) {
            cout << "\n-----------------------Expense " << searchDescription << " not found by Description-----------------------" << endl;
            cout << "\nEnter the Expense Number to search: ";
            cin >> Search_Number;
            // Check if the entered expense number is valid
                cout << "\nSearching for No. " << Search_Number << " ......." << endl;
            if (Search_Number >= 1 && Search_Number <= Ginastos) {
                // Search for the expense by number
                for (int i = 0; i < Ginastos; ++i) {
                    if ((i + 1) == Search_Number) {
                        cout << "\nSearch Results:" << endl;
                        cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------\n";
                        cout << setw(20) << "Description:" << setw(20) << "Amount:" << setw(20) << "Category:" << setw(20) << "Date:" << setw(20) << "Recurring:" << endl;
                        cout << "Expense No: " << (i + 1) << "\n";
                        cout << setw(20) << Array_Expenses[i].Description << setw(17) << "₱" << fixed << setprecision(2) << Array_Expenses[i].Gurano << setw(22) << fixed << Array_Expenses[i].Category << setw(24) << fixed << Array_Expenses[i].Date << setw(13) << (Array_Expenses[i].Recurring ? "Yes" : "No") << endl;
                        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
                        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
                        Search_Found_Num = true; // Set flag to true if expense is found by number
                        break; // Exit the loop once the expense is found
                    }
                }
            } else {
                cout << "\n-----------------------Expense No. "<< Search_Number << " not found-----------------------" << endl; // Display if expense number is invalid
            }
        }   
    }
    getch();
}




// Function to edit an expense
void Edit_Expense() {
    system("cls");
    if (Ginastos == 0) {
        cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------\n";
        cout << "\nThere are no expenses to edit yet.\n";
        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
        getch();
        return;
    }

    string searchDescription;
    int Search_Number;
    bool Search_Found_Desc = false; // Flag to track if the expense is found by description
    bool Search_Found_Num = false; // Flag to track if the expense is found by number

    cout << "Note! Press Enter if you don't know the Description. \n" << "\nEnter the Description of the expense to edit: \n";
    cin.ignore(); // Clear the input buffer
    getline(cin, searchDescription);
    cout << "\nSearching for " << searchDescription << ".......\n";

    // Search for the expense by description
    for (int i = 0; i < Ginastos; ++i) {
        if (Array_Expenses[i].Description == searchDescription) {
            cout << "\nSearch Results:" << endl;
            cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------\n";
            cout << setw(20) << "Description:" << setw(20) << "Amount:" << setw(20) << "Category:" << setw(20) << "Date:" << setw(20) << "Recurring:" << endl;
            cout << "Expense No: " << (i + 1) << "\n";
            cout << setw(20) << Array_Expenses[i].Description << setw(17) << "₱" << fixed << setprecision(2) << Array_Expenses[i].Gurano << setw(22) << fixed << Array_Expenses[i].Category << setw(24) << fixed << Array_Expenses[i].Date << setw(13) << (Array_Expenses[i].Recurring ? "Yes" : "No") << endl;
            cout << "\n----------------------------------------------------------------------------------------------------------" << endl;

            // Edit the expense
            int Dati_Gurano = Array_Expenses[i].Gurano; // Store the original amount
            cout << "Enter new Description: ";
            getline(cin, Array_Expenses[i].Description);
            cout << "Enter new Amount: ₱";
            cin >> Array_Expenses[i].Gurano;
            cout << "Enter new Category: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, Array_Expenses[i].Category);
            cout << "Enter new Date (MM/DD/YYYY): ";
            getline(cin, Array_Expenses[i].Date);
            cout << "Is this expense Recurring? (1 for Yes, 0 for No): ";
            cin >> Array_Expenses[i].Recurring;
            Total_Gastos = Total_Gastos - Dati_Gurano + Array_Expenses[i].Gurano; // Update total expenses
            cout << "\nExpense edited successfully!" << endl;

            Search_Found_Desc = true; // Set flag to true if expense is found by description
            break; // Exit the loop once the expense is found
        }
    }

    // Check if the expense is not found by description
    if (!Search_Found_Desc) {
        cout << "\n-----------------------Expense " << searchDescription << " not found by Description-----------------------" << endl;
        cout << "\nEnter the Expense Number to search: ";
        cin >> Search_Number;
        // Check if the entered expense number is valid
        cout << "\nSearching for No. " << Search_Number << " ......." << endl;
        if (Search_Number >= 1 && Search_Number <= Ginastos) {
            // Search for the expense by number
            for (int i = 0; i < Ginastos; ++i) {
                if ((i + 1) == Search_Number) {
                    cout << "\nSearch Results:" << endl;
                    cout << "----------------------- Expenses -------------------------------------------------------------------------" << endl;
                    cout << setw(20) << "Description:" << setw(20) << "Amount:" << setw(20) << "Category:" << setw(20) << "Date:" << setw(20) << "Recurring:" << endl;
                    cout << "Expense No: " << (i + 1) << "\n";
                    cout << setw(20) << Array_Expenses[i].Description << setw(17) << "₱" << fixed << setprecision(2) << Array_Expenses[i].Gurano << setw(22) << fixed << Array_Expenses[i].Category << setw(24) << fixed << Array_Expenses[i].Date << setw(13) << (Array_Expenses[i].Recurring ? "Yes" : "No") << endl;
                    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;

                    // Edit the expense
                    int Dati_Gurano = Array_Expenses[i].Gurano; // Store the original amount
                    cout << "Enter new Description: ";
                    cin.ignore();
                    getline(cin, Array_Expenses[i].Description);
                    cout << "Enter new Amount: ₱";
                    cin >> Array_Expenses[i].Gurano;
                    cout << "Enter new Category: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, Array_Expenses[i].Category);
                    cout << "Enter new Date (MM/DD/YYYY): ";
                    getline(cin, Array_Expenses[i].Date);
                    cout << "Is this expense Recurring? (1 for Yes, 0 for No): ";
                    cin >> Array_Expenses[i].Recurring;
                    Total_Gastos = Total_Gastos - Dati_Gurano + Array_Expenses[i].Gurano; // Update total expenses
                    cout << "\nExpense edited successfully!" << endl;

                    Search_Found_Num = true; // Set flag to true if expense is found by number
                    break; // Exit the loop once the expense is found
                }
            }
        } else {
            cout << "\n-----------------------Expense No. "<< Search_Number << " not found-----------------------" << endl; // Display if expense number is invalid
        }
    }
    cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
    getch();
}


// Function to delete an expense
void Delete_Expense() {
    system("cls");
    if (Ginastos == 0) {
        cout << "----------------------- EXPENSES --------------------------------------------------------" << endl;
        cout << "\nThere are no expenses to delete yet.\n";
        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
        getch();
        return;
    }

cout << "----------------------- Expenses -------------------------------------------------------------------------" << endl;
cout << setw(20) << "Description:" << setw(20) << "Amount:" << setw(20) << "Category:" << setw(20) << "Date:" << setw(20) << "Recurring:" << endl;
for (int i = 0; i < Ginastos; ++i) {
    cout << "Expense No: " << (i + 1) << "\n";
    cout << setw(20) << Array_Expenses[i].Description << setw(17) << "₱" << fixed << setprecision(2) << Array_Expenses[i].Gurano << setw(22) << fixed << Array_Expenses[i].Category << setw(24) << fixed << Array_Expenses[i].Date << setw(13) << (Array_Expenses[i].Recurring ? "Yes" : "No") << endl;
}
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;


    string searchDescription;
    int Search_Number;
    bool Search_Found_Desc = false; // Flag to track if the expense is found by description
    bool Search_Found_Num = false; // Flag to track if the expense is found by number

    cout << "Note! Press Enter if you don't know the Description. \n" << "\nEnter the Description of the expense to delete: \n";
    cin.ignore(); // Clear the input buffer
    getline(cin, searchDescription);
    cout << "\nSearching for " << searchDescription << ".......\n";

    // Search for the expense by description
    for (int i = 0; i < Ginastos; ++i) {
        if (Array_Expenses[i].Description == searchDescription) {
            cout << "\nSearch Results:" << endl;
            cout << "----------------------- Expenses -------------------------------------------------------------------------" << endl;
            cout << setw(20) << "Description:" << setw(20) << "Amount:" << setw(20) << "Category:" << setw(20) << "Date:" << setw(20) << "Recurring:" << endl;
            cout << "Expense No: " << (i + 1) << "\n";
            cout << setw(20) << Array_Expenses[i].Description << setw(17) << "₱" << fixed << setprecision(2) << Array_Expenses[i].Gurano << setw(22) << fixed << Array_Expenses[i].Category << setw(24) << fixed << Array_Expenses[i].Date << setw(13) << (Array_Expenses[i].Recurring ? "Yes" : "No") << endl;
            cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
            cout << "Expense " << searchDescription << " deleted successfully!\n" << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";

            // Delete the expense
            Total_Gastos -= Array_Expenses[i].Gurano;
            for (int j = i; j < Ginastos - 1; ++j) {
                Array_Expenses[j] = Array_Expenses[j + 1];
            }
            Ginastos--;

            Search_Found_Desc = true; // Set flag to true if expense is found by description
            break; // Exit the loop once the expense is found
        }
    }

    // Check if the expense is not found by description
    if (!Search_Found_Desc) {
    cout << "\n-----------------------Expense " << searchDescription << " not found by Description-----------------------" << endl;
    cout << "\nEnter the Expense Number to delete: ";
    cin >> Search_Number;
    // Check if the entered expense number is valid
    cout << "\nSearch Results:" << endl;
    cout << "----------------------- Expenses -------------------------------------------------------------------------" << endl;
    cout << setw(20) << "Description:" << setw(20) << "Amount:" << setw(20) << "Category:" << setw(20) << "Date:" << setw(20) << "Recurring:" << endl;
    cout << "Expense No: " << Search_Number << "\n";
    cout << setw(20) << Array_Expenses[Search_Number - 1].Description << setw(17) << "₱" << fixed << setprecision(2) << Array_Expenses[Search_Number - 1].Gurano << setw(22) << fixed << Array_Expenses[Search_Number - 1].Category << setw(24) << fixed << Array_Expenses[Search_Number - 1].Date << setw(13) << (Array_Expenses[Search_Number - 1].Recurring ? "Yes" : "No") << endl;
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\nExpense No. " << Search_Number << " deleted successfully!\n"; 
    if (Search_Number >= 1 && Search_Number <= Ginastos) {
        // Delete the expense by number
        int indexToDelete = Search_Number - 1;
        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
        Total_Gastos -= Array_Expenses[indexToDelete].Gurano;
        for (int i = indexToDelete; i < Ginastos - 1; ++i) {
            Array_Expenses[i] = Array_Expenses[i + 1];
        }
        Ginastos--;

        Search_Found_Num = true; // Set flag to true if expense is found by number
    } else {
        cout << "\n-----------------------Expense No. "<< Search_Number << " not found-----------------------" << endl; // Display if expense number is invalid
    }
}


    // Display message if the expense is not found
    if (!Search_Found_Desc && !Search_Found_Num) {
        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
    }
    getch();
}




// Function to calculate remaining budget and display expenses summary
void RemainingBudget_TotalExpenses() {
    system("cls");
    if (Ginastos == 0) {
        cout << "\t------------------------------------------------------------ EXPENSE ----------------------------------------------------------------------------\n";
        cout << "\n\t\tThere are no expenses to Calculate yet\n";
        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
        cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
        getch();
    }
    else {
    cout << "\t----------------------- Summary of Expenses -----------------------" << endl;
    cout << setw(20) << "Total Budget: " << "₱" << Total_Budget<< endl;
    cout << setw(20) << "Total Expense: " << "₱" << Total_Gastos << endl;
    cout << setw(20) << "Remaining Budget: "<< "₱" << Total_Budget - Total_Gastos << endl;
    cout << "----------------------- Expenses Summary for Each Category --------------------------" << endl;
    
    const int MAX_CATEGORIES = 5; // 5 since there are 5 categories 
    string Categories[MAX_CATEGORIES] = {"Groceries", "Transportation", "School Supplies", "Entertainment", "Other"};
    int Category_Expenses[MAX_CATEGORIES] = {0}; // Initialize to zero for each category

    // Calculate total expenses for each category
    for (int i = 0; i < Ginastos; ++i) {
        for (int j = 0; j < MAX_CATEGORIES; ++j) {
            if (Array_Expenses[i].Category == Categories[j]) {
                Category_Expenses[j] += Array_Expenses[i].Gurano;
                break; // Move to the next category
            }
        }
    }

    // Display expenses for each category
    for (int i = 0; i < MAX_CATEGORIES; ++i) {
        cout << setw(20) << Categories[i] << ": ₱" << fixed << setprecision(3) << Category_Expenses[i] << endl;
    }

    cout << "----------------------- Remaining Budget for Each Category -----------------------" << endl;
    // Calculate remaining budget for each category
    int Remaining_Budget = Total_Budget - Total_Gastos;
    int Category_Of_Remaining_Budget;
    for (int i = 0; i < MAX_CATEGORIES; ++i) {
        Category_Of_Remaining_Budget = Total_Budget / MAX_CATEGORIES - Category_Expenses[i];
        cout << setw(20) << Categories[i] << ": ₱" << fixed << setprecision(3) << Category_Of_Remaining_Budget << endl;
    }
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
        getch();
    }
}

// Function to provide financial tips for students
void Gastos_Tips() {
    system("cls");
    cout << "\n--------------------- Financial Tips for Students ---------------------" << endl;
    cout << "1. Create a budget and stick to it." << endl;
    cout << "2. Cook your meals instead of eating out." << endl;
    cout << "3. Use public transportation or carpool to save on transportation costs." << endl;
    cout << "4. Take advantage of student discounts." << endl;
    cout << "5. Avoid impulse purchases." << endl;
    cout << "6. Keep track of your Expenses regularly." << endl;
    cout << "7. Consider part-time jobs or freelance work for extra income." << endl;
    cout << "8. Start saving early for long-term goals." << endl;
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\n\t\t\t\t\t\t\t\t Please press Spacebar to proceed\n";
    getch();
}

// Main function
int main() {
    if (!User_Authenticator()) {
        cout <<"kalbo";
    }
    else {
    int Menu;
    int choice;
    system("Color 1F");
    cout << "\n\t\033[1m------------------------------------------------------------ \033[1mBUDGET BUDDY\033[1m ----------------------------------------------------------------------------\n" << endl;
    cout << "\t\t\t\t\t 1. MANAGE BUDGET";
    cout << "\n\t\t\t\t\t 2. EXIT\n";
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t ENTER YOUR MENU: ";
    cin >> Menu;

   
   if (Menu == 1) {
    while (Menu != 2) {
        system("cls");
        cout << "\n\t\033[1;3m------------------------------------------------------------ \033[1mBUDGET BUDDY\033[1m ----------------------------------------------------------------------------\n" << endl;
        cout << "\t\t\t1. Set Budget"<< "\t\t\t\t\t4. Search Expense"<< "\t\t\t\t7. Calculate Remaining Budget" << endl;
        cout << "\t\t\t2. Add Expense" << "\t\t\t\t\t5. Edit Expense"<< "\t\t\t\t\t8. Financial Tips for Students" <<  endl;
        cout << "\t\t\t3. Display Expenses" << "\t\t\t\t6. Delete Expense" << "\t\t\t\t9. Exit" << endl;
        cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Budget();
                break;
            case 2:
                Add_Expense();
                break;
            case 3:
                Display_Expenses();
                break;
            case 4:
                Search_Expense();
                break;
            case 5:
                Edit_Expense();
                break;
            case 6:
                Delete_Expense();
                break;
            case 7:
                RemainingBudget_TotalExpenses();
                break;
            case 8:
                Gastos_Tips();
                break;
            case 9:
    system("cls");
    cout << "\n\t\033[1m------------------------------------------------------------ \033[1mBUDGET BUDDY\033[1;3m ----------------------------------------------------------------------------\n" << endl;
    cout << "\t\tExiting.... Hope you like it, thank you!\n";
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    return 0 ;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
else if (Menu == 2){
    system("cls");
    cout << "\n\t\033[1m------------------------------------------------------------ \033[1mBUDGET BUDDY\033[1;3m ----------------------------------------------------------------------------\n" << endl;
    cout << "\t\tExiting.... Hope you like it, thank you!\n";
    cout << "\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    return 0 ;
}
    }
    return 0;
}
