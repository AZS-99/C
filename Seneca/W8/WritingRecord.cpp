//
// Created by Adam Saher on 2022-07-22.
//

#include "WritingRecord.h"

sdds::GeneratingList<sdds::EmployeeWage> sdds::writeRaw(const sdds::GeneratingList<sdds::Employee>& emp, const sdds::GeneratingList<sdds::Salary>& sal) {
    sdds::GeneratingList<sdds::EmployeeWage> lst;
    sdds::EmployeeWage* employeeWage;
    std::vector<sdds::Employee> employees;
    std::vector<sdds::Salary> salaries;
    for (auto i = 0u; i < emp.size(); ++i) employees.push_back(emp[i]);
    for (auto i = 0u; i < sal.size(); ++i) salaries.push_back(sal[i]);

    for (auto& employee: employees) {
        auto it = std::find_if(salaries.cbegin(), salaries.cend(), [employee](const sdds::Salary& salary) {
            return salary.id == employee.id;
        });
        if (it != salaries.cend()) {
            employeeWage = new sdds::EmployeeWage(employee.name, it->salary);
            lst += employeeWage;
        }
    }
    return lst;
}