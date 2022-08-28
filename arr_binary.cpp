#include<iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void sortArray(int[], int);
int binarySearch(int[], int, int);
double avg(int& size, int arr[]);

int main()
{
    // Defining the variables
    const int SIZER = 50;
    int arr[SIZER];
    int size;
    int number;
    int positionNum;

    
    cout << "Enter the number of elements you'd like to input (maximum 50)" << endl; // adjusting the size of the array 
    cin >> size;

    cout << endl << endl;

    while (size > 50) // Loop statement making sure that the user doesn't input the size over the maximum capacity (50)
    {
        cout << "The number of elements you've inputed is over the maximum capacity, please try again" << endl;
        cin >> size;

        if (size <= 50)
        {
            break;
        }
    }

    cout << endl << endl;

    cout << "Enter " << size << " Elements: " << endl; // Asking the user to fill in the array
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
        
    cout << endl << endl;
    // Calling the sortArray function to sort the arrays
    sortArray(arr, size);
    cout << "The sorted array is: " << endl; // printing the sorted array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
       
    cout << endl << endl;

    cout << "Enter element you'd like to search: " << endl; // asking the user for the number he/she would like to search
    cin >> number;

    positionNum = binarySearch(arr, number, size); // calling the function to search the number
    
    while (positionNum == 0) // loop statement to make sure that the user inputs the number that is in the array
    {
        cout << endl <<  number << " isn't in the list, please try again" << endl;
        cin >> number;
        positionNum = binarySearch(arr, number, size);

        if (positionNum != 0) // condition to break the loop
        {
            break;
        }
    }
    cout << endl << number << " is at position " << positionNum << endl;

    cout << endl << endl;
    
    // Calling the function to print the average
    double callFunction = avg(size, arr);
    cout << fixed << setprecision(2); // Setting the output to produce the answer with 2 decimal places
    cout << "The average of the elements is " << callFunction << endl;

    return 0;
}

// Function definition of sortArray
void sortArray(int arr[], int size)
{
    int temp;
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function definition of binarySearch
int binarySearch(int arr[], int number, int size) // Using the binary search to locate the number that user has inputed
{ 
    int first = 0;
    int last = (size - 1);
    int middle = (first + last) / 2;

    while (first <= last)
    {
        if (arr[middle] < number)
            first = middle + 1;
        else if (arr[middle] == number)
            return (middle + 1);
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    return 0;
}

// Function definition of avg
double avg(int& size, int arr[])
{
    double sum = 0;
    double average;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i]; // Calculating the sum of the numbers in the array
    }

    average = sum / size; // Calculating the average

    return average; // Returning the value of average
}