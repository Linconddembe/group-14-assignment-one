#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// Function to validate the password
bool validatePassword(const string& correctPassword) {
    string inputPassword;
    for (int attempts = 0; attempts < 3; attempts++) {
        cout << "Enter the course code as password: ";
        cin >> inputPassword;
        if (inputPassword == correctPassword) {
            return true;
        } else {
            cout << "Incorrect password. Try again." << endl;
        }
    }
    cout << "Too many incorrect attempts. Exiting program." << endl;
    return false;
}

// Function to calculate GPA
double calculateGPA(const vector<int>& marks) {
    double total = 0;
    for (int mark : marks) {
        total += mark;
    }
    return total / marks.size();
}

// Function to calculate age
void calculateAge(const string& dob) {
    int day, month, year;
    sscanf(dob.c_str(), "%d/%d/%d", &day, &month, &year);

    time_t t = time(0);
    tm* now = localtime(&t);
    
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int ageYears = currentYear - year;
    int ageMonths = currentMonth - month;
    int ageDays = currentDay - day;

    if (ageDays < 0) {
        ageMonths--;
        ageDays += 30;  // Approximate correction
    }
    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }

    cout << "Your age is: " << ageYears << " years, " << ageMonths << " months, " << ageDays << " days." << endl;
}

int main() {
    string fullName, courseCode;
    char continueOption;

    cout << "Enter your full name: ";
    getline(cin, fullName);
    cout << "Enter the course code (password): ";
    cin >> courseCode;

    while (true) {
        // Step 1: Password Check
        if (!validatePassword(courseCode)) {
            break; // Exit if password validation fails
        }

        // Step 2: Capturing Marks and GPA Calculation
        int numSubjects;
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        vector<int> marks(numSubjects);
        for (int i = 0; i < numSubjects; i++) {
            do {
                cout << "Enter marks for subject " << (i + 1) << " (0-100): ";
                cin >> marks[i];
                if (marks[i] < 0 || marks[i] > 100) {
                    cout << "Invalid marks. Please enter again." << endl;
                }
            } while (marks[i] < 0 || marks[i] > 100);
        }

        double gpa = calculateGPA(marks);
        cout << fixed << setprecision(2);
        cout << "Your GPA is: " << gpa << endl;

        // Step 3: Age Calculation
        string dob;
        cout << "Enter your date of birth (DD/MM/YYYY): ";
        cin >> dob;
        calculateAge(dob);

        // Ask user if they want to continue
        cout << "Do you want to continue? (y/n): ";
        cin >> continueOption;
        if (continueOption != 'y' && continueOption != 'Y') {
            break; // Exit the loop
        }
    }

    cout << "Thank you for using the program!" << endl;
    return 0;
}
