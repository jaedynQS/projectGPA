//Developer: Jose Reyes & Jaedyn Quinlan-Sadler
//COP 2006 Programing 1
//04/02/2024
//This program functions as a gpa calculator.
#include <iostream>
#include <map>
#include <string>

// Function to calculate GPA
double calculateGPA(std::map<std::string, std::pair<double, double>>& grades) {
    double totalHonorPoints = 0; // Initialize total honor points to zero
    double totalCreditHours = 0; // Initialize total credit hours to zero

    // Grading system: Map letter grades to corresponding grade points
    std::map<std::string, double> gradePoints = {
            {"A+", 4.3},
            {"A", 4.0},
            {"A-", 3.7},
            {"B+", 3.3},
            {"B", 3.0},
            {"B-", 2.7},
            {"C+", 2.3},
            {"C", 2.0},
            {"C-", 1.7},
            {"D+", 1.3},
            {"D", 1.0},
            {"D-", 0.7},
            {"F", 0.0}
    };

    // Iterate over grades and calculate total honor points and total credit hours
    for (auto& grade : grades) {
        // Check if the grade is present in the grading system
        if (gradePoints.find(grade.first) != gradePoints.end()) {
            double gradePoint = gradePoints[grade.first]; // Get grade point for the letter grade
            double creditHours = grade.second.first; // Get credit hours for the course
            double numberOfCourses = grade.second.second; // Get the number of courses with this grade
            totalHonorPoints += gradePoint * creditHours * numberOfCourses; // Calculate honor points
            totalCreditHours += creditHours * numberOfCourses; // Calculate total credit hours
        }
    }

    // Calculate GPA
    if (totalCreditHours != 0)
        return totalHonorPoints / totalCreditHours; // GPA = Total honor points / Total credit hours
    else
        return 0; // To avoid division by zero
}

int main() {
    // Map to store grades, credit hours, and the number of courses for each grade
    std::map<std::string, std::pair<double, double>> grades;

    char choice;
    do {
        std::string grade;
        double creditHours, numberOfCourses;

        // Input grade, credit hours, and number of courses
        std::cout << "Enter your grade (A/A+/A-/B+/B/B-/C+/C/C-/D+/D/D-/F):";
        std::cin >> grade;
        std::cout << "Enter the credit hours for the course:" << std::endl;
        std::cin >> creditHours;
        std::cout << "Enter the number of courses with this grade:";
        std::cin >> numberOfCourses;

        // Add grade, credit hours, and number of courses to the map
        grades[grade] = std::make_pair(creditHours, numberOfCourses);

        // Ask if the user wants to input more grades
        std::cout << "Do you want to enter more grades? (y/n):" << std::endl;
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Calculate and display GPA
    double gpa = calculateGPA(grades); // Call function to calculate GPA
    std::cout << "Your GPA is: " << gpa << std::endl; // Display GPA

    return 0;
}
