#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student Class
class Student
{
public:
    int roll;
    string name;
    string dept;
    float cgpa;

    void inputData()
    {
        cout << "Enter Roll: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Department: ";
        getline(cin, dept);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void displayData()
    {
        cout << "Roll: " << roll << " | Name: " << name
             << " | Dept: " << dept << " | CGPA: " << cgpa << endl;
    }
};

int main()
{
    vector<Student> students; // store all students
    int choice;

    do
    {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search Student by Roll\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Student s;
            s.inputData();
            students.push_back(s);
            cout << "✅ Student Added Successfully!\n";
        }
        else if (choice == 2)
        {
            cout << "\n--- Student List ---\n";
            for (auto &s : students)
            {
                s.displayData();
            }
        }
        else if (choice == 3)
        {
            int roll;
            cout << "Enter Roll to Search: ";
            cin >> roll;
            bool found = false;
            for (auto &s : students)
            {
                if (s.roll == roll)
                {
                    s.displayData();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "❌ Student Not Found!\n";
        }
        else if (choice == 4)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}