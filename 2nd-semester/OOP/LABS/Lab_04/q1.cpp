#include <iostream>
using namespace std;

class Employee {
private:
    char* EmployeeName;
    const int EmployeeId; // EmployeeId is constant and can only be initialized once
public:
    // Default constructor
    Employee() : EmployeeId(0) {
        EmployeeName = nullptr;
    }
    // Parameterized constructor
    Employee(int EmployeeId, char* EmployeeName) : EmployeeId(EmployeeId), EmployeeName(EmployeeName) {}
    // Getter for EmployeeName
    char* getEmployeeName() {
        return EmployeeName;
    }
    // Getter for EmployeeId
    int getEmployeeId() {
        return EmployeeId;
    }
    // Setter for EmployeeName
    void setEmployeeName(char* EmployeeName) {
        this->EmployeeName = EmployeeName;
    }
    void setEmployeeId(int EmployeeId) {
        // EmployeeId cannot be changed once initialized, so this function does nothing
    }

};

int main(){
Employee Employee1(1, "Imran");
Employee Employee2(2, "Ali");
Employee Employee3(3, "Ahmed");

cout << "Employee 1: Name = " << Employee1.getEmployeeName() << ", ID = " << Employee1.getEmployeeId() << endl;
cout << "Employee 2: Name = " << Employee2.getEmployeeName() << ", ID = " << Employee2.getEmployeeId() << endl;
cout << "Employee 3: Name = " << Employee3.getEmployeeName() << ", ID = " << Employee3.getEmployeeId() << endl;

    
    return 0;
}

// Create a class ‘Employee’ having two data members ‘EmployeeName’(char*) and
// ‘EmployeeId’ (int). Keep both data members private. Create three initialized
// objects ‘Employee1’, ‘Employee2’ and ‘Employee3’ of type ‘Employee’ in such a way
// that the employee name for each employee can be changed when required but the
// employee Id for each employee must be initialized only once and should remain
// same always. Use member initializer list, accessors/getters and mutators/setters
// for appropriate data members. The result must be displayed by calling the
// accessors.
