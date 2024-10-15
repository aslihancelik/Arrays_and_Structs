// Arrays_and_Structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program tracks daily miles run by five marathon runners over a week.
// It calculates total and average miles for each runner and outputs a formatted table
// displaying their names, daily miles, total miles, and average miles.
// 
// Programmer: Aslihan Celik
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Function to read and store the runners' names and number of miles run each day
void readData(string runners[], double miles[NUM_RUNNERS][NUM_DAYS]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << "Enter the name of runner " << i + 1 << ": " << endl;
        cin >> runners[i];

        cout << "Enter the miles run by " << runners[i] << " each day for 7 days: " << endl;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Enter the miles run for day " << j + 1 << " :" << endl;
            cin >> miles[i][j];
        }
    }
}

// Function to calculate total miles run by each runner and average number of miles run each day
void calculateTotals(const double miles[NUM_RUNNERS][NUM_DAYS], double totalMiles[], double avgMiles[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        totalMiles[i] = 0.0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles[i] += miles[i][j];
        }
        avgMiles[i] = totalMiles[i] / NUM_DAYS; 
    }
}

// Function to output the results in a table format
void outputResults(const string runners[], const double miles[NUM_RUNNERS][NUM_DAYS], const double totalMiles[], const double avgMiles[]) {
    // Print the header as per your specified format
    cout << setw(10) << "RunnerName" << setw(12) << "milesDay1" << setw(12) << "milesDay2"
        << setw(12) << "milesDay3" << setw(12) << "milesDay4" << setw(12) << "milesDay5"
        << setw(12) << "milesDay6" << setw(12) << "milesDay7" << setw(12) << "Total"
        << setw(12) << "Average" << endl;

    // Print a separator line
    cout << string(116, '-') << endl;

    // Print the data for each runner
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        // Print runner's name
        cout << setw(10) << runners[i]; 
        for (int j = 0; j < NUM_DAYS; ++j) {
            // Print miles for each day
            cout << setw(12) << miles[i][j]; 
        }
        // Print total and average
        cout << setw(12) << totalMiles[i] << setw(12) << avgMiles[i] << endl; 
    }
}


int main() {
    string runners[NUM_RUNNERS];  // Array to store the runner names
    double miles[NUM_RUNNERS][NUM_DAYS];  // 2D array to store the miles run by each runner for each day
    double totalMiles[NUM_RUNNERS];  // Array to store the total miles run by each runner
    double avgMiles[NUM_RUNNERS];    // Array to store the average miles run by each runner per day

    // Step 1: Read the data of the runners' names and number of miles run each day
    readData(runners, miles);

    // Step 2: Calculate the total and average miles for each runner
    calculateTotals(miles, totalMiles, avgMiles);

    // Step 3: Output the results in a formatted table
    outputResults(runners, miles, totalMiles, avgMiles);

    return 0;
}