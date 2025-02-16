#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string Name;
    int Age;

public:
    Student(string name, int age) : Name(name), Age(age) {}
    
    void setAge(int age) { Age = age; }
    void setName(string name) { Name = name; }
    string getName() const { return Name; }
    int getAge() const { return Age; }
    void printStudentInfo() const { cout << "Student " << Name << " Age " << Age << endl; }
};

int main() {
    int selection = 0;
    vector<Student> studentList;

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection) {
            case 0: {
                string name;
                int age;
                cout << "Student name ? ";
                cin >> name;
                cout << "Student age ? ";
                cin >> age;
                studentList.push_back(Student(name, age));
                cout << "Added student: " << name << " Age " << age << endl;
                break;
            }
            case 1:
                cout << "Printing all students:" << endl;
                for (const auto &student : studentList) {
                    student.printStudentInfo();
                }
                break;
            case 2:
                cout << "Sorting students by name..." << endl;
                sort(studentList.begin(), studentList.end(), [](const Student &a, const Student &b) {
                    return a.getName() < b.getName();
                });
                cout << "Sorted list:" << endl;
                for (const auto &student : studentList) {
                    student.printStudentInfo();
                }
                break;
            case 3:
                cout << "Sorting students by age..." << endl;
                sort(studentList.begin(), studentList.end(), [](const Student &a, const Student &b) {
                    return a.getAge() < b.getAge();
                });
                cout << "Sorted list:" << endl;
                for (const auto &student : studentList) {
                    student.printStudentInfo();
                }
                break;
            case 4: {
                string searchName;
                cout << "Student to be found name = ? ";
                cin >> searchName;
                auto it = find_if(studentList.begin(), studentList.end(), [&searchName](const Student &s) {
                    return s.getName() == searchName;
                });
                if (it != studentList.end()) {
                    cout << "Student found: ";
                    it->printStudentInfo();
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            default:
                cout << "Wrong selection, stopping..." << endl;
                break;
        }
    } while (selection < 5);

    return 0;
}
