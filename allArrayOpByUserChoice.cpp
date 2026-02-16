/*
Take input array size and elements
1. Search an element by user input
2. Delete an element by user input
3. Insert an element at user given index
4. Sort the array using bubble sort
*/

#include <iostream>
using namespace std;

float printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice;
    bool arrayDeclared = false;
    char cont;
    do
    {
        cout << "\n MENU \nChoose an option:\n"
             << endl;
        cout << "1. Declare Array Size & Input element(s). \n";
        cout << "2. Search an Element\n";
        cout << "3. Delete an Element\n";
        cout << "4. Insert an Element\n";
        cout << "5. Sort the Array\n";
        cout << "0. Exit\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (!arrayDeclared && choice != 1 && choice != 0)
        {
            cout << "Declare array first!\n";
            continue;
        }
        if (choice == 1)
        {
            int n;

            cout << "Enter array size: \n";
            cin >> n;

            float arr[n];

            cout << "Enter " << n << " element(s): \n";

            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            cout << "Your current array is \n";
            printArray(arr, n);
        }
        else if (choice == 2)
        {
            /* code */
        }
        else
        {
            /* code */
        }

    } while (true);
}