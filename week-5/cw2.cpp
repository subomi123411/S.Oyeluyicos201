#include <iostream>
using namespace std;

int main() {
    const int MAX_STUDENTS = 100;
    int scores[MAX_STUDENTS];
    char grades[MAX_STUDENTS];
    int numStudents;
    
    // Prompt user for number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;
    
    // Validate input
    while (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        cout << "Please enter a number between 1 and " 
             << MAX_STUDENTS << ": ";
        cin >> numStudents;
    }
    
    // Prompt user for scores
    cout << "Enter " << numStudents << " scores: ";
    for (int i = 0; i < numStudents; i++) {
        cin >> scores[i];
    }
    
    // Find the best score
    int bestScore = scores[0];
    for (int i = 1; i < numStudents; i++) {
        if (scores[i] > bestScore) {
            bestScore = scores[i];
        }
    }
    
    // Assign grades based on the scheme
    for (int i = 0; i < numStudents; i++) {
        int score = scores[i];
        
        if (score >= bestScore - 10) {
            grades[i] = 'A';
        } else if (score >= bestScore - 20) {
            grades[i] = 'B';
        } else if (score >= bestScore - 30) {
            grades[i] = 'C';
        } else if (score >= bestScore - 40) {
            grades[i] = 'D';
        } else {
            grades[i] = 'F';
        }
    }
    
    // Display results
    cout << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i << " score is " << scores[i] 
             << " and grade is " << grades[i] << endl;
    }
    
    return 0;
}