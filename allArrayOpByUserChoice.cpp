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