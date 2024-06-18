//Written by: Klaire Npaolitano     1-BSCS      05/11/24

#include <iostream>
using namespace std;
#include <cmath> //This is for the built-in function sqrt and pow

// Function prototypes
void userInputData(int arr[], int& size); // Function to input data into array
int findLargest(const int arr[], int size); // Function to find the largest number
int findSmallest(const int arr[], int size); // Function to find the smallest number
double findPopulationAverage(const int arr[], int size); // Function to find the average
double findPopulationVariance(const int arr[], int size, double average); // Function to find the variance
double findPopulationStandardDeviation(const int arr[], int size, double average); // Function to find the standard deviation
void displayResults(int largest, int smallest, double average, double variance, double standardDeviation); // Function to display the results

//This is the main function 
int main() {
    const int maxSize = 10;
    int numbers[maxSize];
    int size = 0;

    // Output program introduction
    cout << "==========================================================================================================================================\n";
    cout << "|                                                      Programming Exercise 05                                                            |\n";
    cout << "==========================================================================================================================================\n";
    cout << "|                                                  Submitted by:Klaire S. Napolitano                                                      |\n";
    cout << "==========================================================================================================================================\n";
    cout << "This program will ask the user to input various numbers (positive or negative but not zero) and perform basic statistics on these numbers.\n";
    cout << "REMINDER: User input must only be positive or negative numbers. If the user inputs a 0, the program will stop.                           \n";
    cout << "==========================================================================================================================================\n\n";

    // Input data
    userInputData(numbers, size);

    // Calculate statistics
    int largest = findLargest(numbers, size);
    int smallest = findSmallest(numbers, size);
    double average = findPopulationAverage(numbers, size);
    double variance = findPopulationVariance(numbers, size, average);
    double standardDeviation = findPopulationStandardDeviation(numbers, size, average);

    // Display results
    displayResults(largest, smallest, average, variance, standardDeviation);

    return 0;
}

// This function to input data into array
void userInputData(int arr[], int& size) {
    cout << "Input a positive or negative integer but not zero: ";
    cin >> arr[size];
    while (arr[size] != 0 && size < 10) { // Loop until user inputs 0 or reaches maximum size
        size++; // Increment the size
        if (size < 10) { // Check if array size is within bounds
            cout << "Input a positive or negative integer but not zero: ";
            cin >> arr[size]; // Input next number
        }
    }
}

// This function to find the largest number
int findLargest(const int arr[], int size) {
    int largest = arr[0]; // Initialize largest as the first element
    for (int i = 1; i < size; ++i) { // Iterate through the array
        if (arr[i] > largest) { // If current element is larger than current largest
            largest = arr[i]; // Update largest
        }
    }
    return largest; // Return the largest number found
}

// Function to find the smallest number
int findSmallest(const int arr[], int size) {
    int smallest = arr[0]; // Initialize smallest as the first element
    for (int i = 1; i < size; ++i) { // Iterate through the array
        if (arr[i] < smallest) { // If current element is smaller than current smallest
            smallest = arr[i]; // Update smallest
        }
    }
    return smallest; // Return the smallest number found
}

// This function to find the average
double findPopulationAverage(const int arr[], int size) {
    double sum = 0; // Initialize sum
    for (int i = 0; i < size; ++i) { // Iterate through the array
        sum += arr[i]; // Add current element to sum
    }
    return sum / size; // Return the average
}

// This function to find the variance
double findPopulationVariance(const int arr[], int size, double average) {
    double variance = 0; // Initialize variance
    for (int i = 0; i < size; ++i) { // Iterate through the array
        variance += pow(arr[i] - average, 2); // Add squared deviation from average to variance
    }
    return variance / size; // Return the variance
}

// This function to find the standard deviation
double findPopulationStandardDeviation(const int arr[], int size, double average) {
    return sqrt(findPopulationVariance(arr, size, average)); // Return square root of variance
}

// This function is to display the results of the following function solving for the largest, smallest, the average, variance, and standard deviation
void displayResults(int largest, int smallest, double average, double variance, double standardDeviation) {
    cout << "\nLargest = " << largest << endl; // Output the largest number
    cout << "Smallest = " << smallest << endl; // Output the smallest number
    cout << "Average = " << average << endl; // Output the average
    cout << "Standard deviation = " << standardDeviation << endl; // Output the standard deviation
    cout << "Variance = " << variance << endl; // Output the variance
}
