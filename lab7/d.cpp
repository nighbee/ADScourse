#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

struct Student {
    string lastname;
    string firstname;
    int numSubjects;
    vector<pair<string, int>> subjects;
    double gpa;
};

map<string, double> gradeToGPA = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

double calculateGPA(const vector<pair<string, int>>& subjects) {
    double totalPoints = 0;
    int totalCredits = 0;
    for (const auto& subject : subjects) {
        totalPoints += gradeToGPA[subject.first] * subject.second;
        totalCredits += subject.second;
    }
    return totalCredits ? totalPoints / totalCredits : 0;
}

bool compareStudents(const Student& a, const Student& b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa; // Change to ascending order
    if (a.lastname != b.lastname) return a.lastname < b.lastname;
    return a.firstname < b.firstname;
}

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        cin >> students[i].lastname >> students[i].firstname >> students[i].numSubjects;
        students[i].subjects.resize(students[i].numSubjects);
        for (int j = 0; j < students[i].numSubjects; ++j) {
            cin >> students[i].subjects[j].first >> students[i].subjects[j].second;
        }
        students[i].gpa = calculateGPA(students[i].subjects);
    }

    sort(students.begin(), students.end(), compareStudents);

    for (const auto& student : students) {
        cout << student.lastname << " " << student.firstname << " " << fixed << setprecision(3) << student.gpa << endl;
    }

    return 0;
}