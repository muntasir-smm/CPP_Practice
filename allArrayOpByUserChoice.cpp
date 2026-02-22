#include <iostream>
#include <limits>

using namespace std;

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

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

void printArray(int arr[], int n)
{
    if (n <= 0)
    {
        cout << "There is no element in the array.";
    }
    else
    {
        cout << "Your current Array: \n";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[1000];
    int n, choice;
    bool arrayDeclared = false;

    do
    {
        cout << "\n:::::::::: MENU ::::::::::\n";
        cout << "1. Declare Array size & Input element(s)\n";
        cout << "2. Search Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Insert Element\n";
        cout << "5. Sort Array\n";
        cout << "0. Exit\n";
        cout << "::::::::::::::::::::::::::\n"
             << endl;
        cout << "Enter your choice: \n";

        cin >> choice;

        if (cin.fail())
        {
            clearInput();
            cout << "Invalid choice!\n";
            continue;
        }

        if (!arrayDeclared && choice != 1 && choice != 0)
        {
            cout << "Declare array first!\n";
            continue;
        }

        if (choice == 1)
        {
            cout << "Enter array size: \n";
            cin >> n;

            if (cin.fail() || n < 1)
            {
                clearInput();
                cout << "Invalid size!\nArray size must be greater than 0.\n";
                continue;
            }

            arr[n];

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
            arrayDeclared = true;
            printArray(arr, n);
        }

        else if (choice == 2)
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
            // printArray(arr, n);
        }

        else if (choice == 3)
        {
            int x;
            cout << "Enter an element to Delete: ";
            cin >> x;
            if (cin.fail())
            {
                clearInput();
                cout << "Invalid element!\n";
                return;
            }

            // All x will delete
            int newSize = 0;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] != x)
                {
                    arr[newSize] = arr[i];
                    newSize++;
                }
            }

            if (newSize == n)
            {
                cout << x << " is not found!\n";
            }
            else
            {
                n = newSize;
                cout << x << " is deleted successfully!\n";
                printArray(arr, n);
            }
        }

        else if (choice == 4)
        {
            int x, pos;

            cout << "Enter an element to Insert in the array: \n";
            cin >> x;

            cout << "Position to insert (1 to " << n + 1 << "): ";
            cin >> pos;

            if (pos < 1 || pos > n + 1)
            {
                cout << "Invalid position!\n";
                continue;
            }

            arr[n + 1];

            for (int i = n; i >= pos; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[pos - 1] = x;
            n++;

            printArray(arr, n);
        }

        else if (choice == 5)
        {
            int ch;
            cout << "1. Ascending\n";
            cout << "2. Descending\n";
            cout << "Choice: \n";
            cin >> ch;

            if (ch == 1 || ch == 2)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if ((ch == 1 && arr[i] > arr[j]) ||
                            (ch == 2 && arr[i] < arr[j]))
                        {
                            int t = arr[i];
                            arr[i] = arr[j];
                            arr[j] = t;
                        }
                    }
                }
            }
            else
            {
                cout << "Invalid choice.\n";
                continue;
            }
            printArray(arr, n);
        }

        else if (choice == 0)
        {
            break;
        }

        else
        {
            cout << "Invalid choice!\n";
        }

    } while (continueProgram());

    cout << "\nProgram ended.\n";

    return 0;
}
