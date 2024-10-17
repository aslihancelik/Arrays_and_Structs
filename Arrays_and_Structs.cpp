// Arrays_and_Structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// This program tracks daily miles run by five marathon runners over a week.
// It calculates total and average miles for each runner and outputs a formatted table
// displaying their names, daily miles, total miles, and average miles. Implementation
// is done using a struct.
// 
// Programmer: Aslihan Celik
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

struct Runner {
    string runnerName; // Array to store the runner names
    double milesRun[NUM_DAYS]; // 2D array to store the miles run by each runner for each day
    double totalMiles; // Array to store the total miles run by each runner
    double avgMiles; // Array to store the average miles run by each runner per day
};

// Function to read and store the runners' names and number of miles run each day
void readData(Runner runners[NUM_RUNNERS]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << "Enter the name of runner " << i + 1 << ": " << endl;
        cin >> runners[i].runnerName;

        cout << "Enter the miles run by " << runners[i].runnerName << " each day for 7 days: " << endl;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Enter the miles run for day " << j + 1 << " :" << endl;
            cin >> runners[i].milesRun[j];
        }
    }
}

// Function to calculate total miles run by each runner and average number of miles run each day
void calculateTotals(Runner runners[NUM_RUNNERS]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        runners[i].totalMiles = 0.0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            runners[i].totalMiles += runners[i].milesRun[j];
        }
        runners[i].avgMiles = runners[i].totalMiles / NUM_DAYS;
    }
}

// Function to output the results in a table format
void outputResults(const Runner runners[NUM_RUNNERS]) {
    // Print the header as per your specified format
    cout << setw(10) << "RunnerName" << setw(12) << "milesDay1" << setw(12) << "milesDay2"
        << setw(12) << "milesDay3" << setw(12) << "milesDay4" << setw(12) << "milesDay5"
        << setw(12) << "milesDay6" << setw(12) << "milesDay7" << setw(12) << "Total"
        << setw(12) << "Average" << endl;

    // Print a separator line
    cout << string(123, '-') << endl;

    cout << fixed << setprecision(2);

    // Print the data for each runner
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        // Print runner's name
        cout << setw(10) << runners[i].runnerName;
        for (int j = 0; j < NUM_DAYS; ++j) {
            // Print miles for each day
            cout << setw(12) << fixed << setprecision(2) << runners[i].milesRun[j];
        }
        // Print total and average
        cout << setw(12) << fixed << setprecision(2) << runners[i].totalMiles
            << setw(12) << fixed << setprecision(2) << runners[i].avgMiles << endl;
    }
}


int main() {
   
    Runner runners[NUM_RUNNERS];

    // Step 1: Read the data of the runners' names and number of miles run each day
    readData(runners);

    // Step 2: Calculate the total and average miles for each runner
    calculateTotals(runners);

    // Step 3: Output the results in a formatted table
    outputResults(runners);

    return 0;
}