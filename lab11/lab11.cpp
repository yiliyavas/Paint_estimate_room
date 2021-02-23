//==========================================================
//
// Title:      <Lab 11>
// Course:     CSC 1101
// Lab Number: <11>
// Author:     <Yuliya Vaskiv>
// Date:       <02/23/2021>     
// Description:
//   This C++ console application estimates the cost and 
// time to paint the walls of a square room (width of each 
// wall is same; height of each wall is same - I hope!).  
// It prompts for and gets from the user the following 
// inputs:
//   -Number of painters in the range 1 - 4
//   -Wall width in feet in the range 10 - 40
//   -Wall height in feet in the range 7 - 11
// If any of the inputs are out of range, it requests the user
// enter proper values. Once all of the inputs are in range, the 
// application calculates and prints the area, estimated 
// cost, and estimated time. Lastly, the user has the option 
// to run the program as long as they enter 'y' when prompted.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{
    // Declare constants
    const int WALLS = 4;
    const double WALL_RATE = 1.75;  // $ per square foot
    const double PAINT_RATE = 20;  // Square feet per hour per painter
    const int COLFMT1 = 30;
    const int COLFMT2 = 10;

    // Declare variables
    int painters;
    int width;
    int height;
    int area;
    double costEstimate;
    double timeEstimate;

    // declare variable with initial value for choice <------------------------------------
    char choice = 'y';

    // Format real numbers
    cout << fixed << setprecision(2);

    // Show application header
    cout << "Welcome to Satin Stylers" << endl;
    cout << "------------------------" << endl << endl;

    //while loop
    while (choice == 'y') {

        // Prompt for and get job type
        cout << "Enter the number of painters (1-4): ";
        cin >> painters;

        // Test painters
        while (painters < 1 || painters > 4) {
            cout << "Invalid value, entrer new value: ";
            cin >> painters;
        }

        // Prompt for and get width
        cout << "Enter the wall width in feet (10-40): ";
        cin >> width;

        // Test width
        while (width < 10 || width > 40) {
            cout << "Invalid value, entrer new value: ";
            cin >> width;
        }

        // Prompt for and get height
        cout << "Enter the wall height in feet (7-11): ";
        cin >> height;

        // Test height
        while (height < 7 || height > 11) {
            cout << "Invalid value, entrer new value: ";
            cin >> height;
        }

        // Calculate cost and time estimates
        area = width * height * WALLS;
        costEstimate = area * WALL_RATE;
        timeEstimate = (area / PAINT_RATE) / painters;

        // Show job estimate
        cout << endl;
        cout << setw(COLFMT1) << left << "Painters:"
            << setw(COLFMT2) << right << painters << endl;
        cout << setw(COLFMT1) << left << "Wall width (feet):"
            << setw(COLFMT2) << right << width << endl;
        cout << setw(COLFMT1) << left << "Wall height (feet):"
            << setw(COLFMT2) << right << height << endl;
        cout << setw(COLFMT1) << left << "Four-wall area (square feet):"
            << setw(COLFMT2) << right << area << endl;
        cout << setw(COLFMT1) << left << "Cost estimate ($):"
            << setw(COLFMT2) << right << costEstimate << endl;
        cout << setw(COLFMT1) << left << "Time estimate (hours):"
            << setw(COLFMT2) << right << timeEstimate << endl;

        //update for sentinel loop
        cout << "\n-------------------------------------------------------\n";
        cout << "Would you like to check another lob estimate (y/n): ";
        cin >> choice;
    }

       


// Show application close
    cout << "\nEnd of Satin Stylers" << endl;
}
