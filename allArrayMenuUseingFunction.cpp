#include <iostream>
#include <limits>
using namespace std;

const int MAX = 1000;

int arr[MAX];
int n = 0;
bool created = false;

// ---------- Utility ----------
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*:::::Array exist:::::*/
int arrayExist()
{
    if (!created)
    {
        cout << "Array not created yet.\n";
        return 0;
    }

    if (n == 0)
    {
        cout << "Array is empty.\n";
        return 0;
    }
    return 1;
}

// ---------- Create / Re-create ----------
void createArray()
{

    while (true)
    {
        cout << "Enter array size (1-" << MAX << "): ";
        cin >> n;

        if (cin.fail() || n < 1 || n > MAX)
        {
            clearInput();
            cout << "Invalid size!\n";
            continue;
        }
        break;
    }

    // arr[n];

    cout << "Enter " << n << " number(s):\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (cin.fail())
        {
            clearInput();
            cout << "Invalid element!\n";
            i--;
        }
    }

    clearInput();
    created = true;
}

// ---------- Display ----------
void displayArray()
{
    if (arrayExist())
    {
        cout << "Array: ";

        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i < n - 1)
            {
                cout << ", ";
            }
        }

        cout << endl;
    }
}

// ---------- Search ----------
void searchElement()
{
    if (arrayExist())
    {
        int x;
        cout << "Enter an element to search: \n";
        cin >> x;

        bool found = false;

        for (int i = 0; i < n; i++)
            if (arr[i] == x)
            {
                cout << x << " Found at position " << i + 1 << endl;
                found = true;
            }

        if (!found)
        {
            cout << x << " is not found!\n";
        }
    }
}

// ---------- Insert ----------
void insertElement()
{
    if (!created)
    {
        cout << "Create array first.\n";
        return;
    }

    if (n >= MAX)
    {
        cout << "Array full.\n";
        return;
    }

    int x, pos;

    cout << "Enter element to insert: ";
    cin >> x;
    if (cin.fail())
    {
        clearInput();
        cout << "Invalid input.\n";
        return;
    }

    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    if (cin.fail())
    {
        clearInput();
        cout << "Invalid input.\n";
        return;
    }

    if (pos < 0 || pos > n)
    {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = x;
    n++;

    cout << "Inserted successfully.\n";
}

// ---------- Delete First ----------
bool deleteFirst(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            for (int j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];

            n--;
            return true;
        }
    }
    return false;
}

// ---------- Delete Last ----------
bool deleteLast(int x)
{
    int pos = -1;

    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            pos = i;

    if (pos == -1)
        return false;

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
    return true;
}

// ---------- Delete All ----------
bool deleteAll(int x)
{
    int newSize = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != x)
            arr[newSize++] = arr[i];
        else
            found = true;
    }

    n = newSize;
    return found;
}

// ---------- Delete Menu ----------
void deleteMenu()
{
    if (!created || n == 0)
    {
        cout << "Array is empty. Create array first.\n";
        return;
    }

    int choice, x;

    cout << "\nDelete Menu\n";
    cout << "1. Delete First\n";
    cout << "2. Delete Last\n";
    cout << "3. Delete All\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter element: ";
    cin >> x;

    bool result = false;

    switch (choice)
    {
    case 1:
        result = deleteFirst(x);
        break;
    case 2:
        result = deleteLast(x);
        break;
    case 3:
        result = deleteAll(x);
        break;
    default:
        cout << "Invalid choice.\n";
        return;
    }

    if (result)
        cout << "Deleted successfully.\n";
    else
        cout << "Element not found.\n";
}

// ---------- Sort Ascending ----------
void sortAscending()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// ---------- Sort Descending ----------
void sortDescending()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// ---------- Sort Menu ----------
void sortMenu()
{
    if (!created || n == 0)
    {
        cout << "Array is empty. Create array first.\n";
        return;
    }

    int choice;

    cout << "\nSort Menu\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        sortAscending();
        cout << "Sorted Ascending.\n";
    }
    else if (choice == 2)
    {
        sortDescending();
        cout << "Sorted Descending.\n";
    }
    else
        cout << "Invalid choice.\n";
}

// ---------- Reverse ----------
void reverseArray()
{
    if (!created || n == 0)
    {
        cout << "Array is empty. Create array first.\n";
        return;
    }

    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    cout << "Array reversed successfully.\n";
}

/* :::::::Continue Program::::::: */
bool continueProgram()
{
    char yesNo;

    while (true)
    {
        cout << "\nDo you want to continue? (y/n): ";
        cin >> yesNo;

        clearInput();

        if (yesNo == 'y' || yesNo == 'Y')
        {
            return true;
        }
        else if (yesNo == 'n' || yesNo == 'N')
        {
            return false;
        }
        else
        {
            cout << "Invalid input. Try again.\n";
        }
    }
}

// ---------- Main ----------
int main()
{
    int choice;

    do
    {
        cout << "\n::::: MAIN MENU :::::\n";
        cout << "1. Create Array\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Insert\n";
        cout << "5. Delete\n";
        cout << "6. Sort\n";
        cout << "7. Reverse\n";
        cout << "8. Re-create Array\n";
        cout << "0. Exit\n";
        cout << "\n:::::::::::::::::::::\n";

        cout << endl
             << "Enter choice: ";
        cin >> choice;

        if (cin.fail())
        {
            clearInput();
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
        case 8:
            createArray();
            break;

        case 2:
            displayArray();
            break;

        case 3:
            searchElement();
            break;

        case 4:
            insertElement();
            break;

        case 5:
            deleteMenu();
            break;

        case 6:
            sortMenu();
            break;

        case 7:
            reverseArray();
            break;

        case 0:
            cout << "Program exited.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    } while (continueProgram());

    cout << "\nProgram ended.\n";

    return 0;
}