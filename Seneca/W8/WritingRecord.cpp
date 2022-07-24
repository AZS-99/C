//
// Created by Adam Saher on 2022-07-22.
//

#include "WritingRecord.h"

sdds::GeneratingList<sdds::EmployeeWage> sdds::writeRaw(const sdds::GeneratingList<sdds::Employee>& emp, const sdds::GeneratingList<sdds::Salary>& sal) {
    sdds::GeneratingList<sdds::EmployeeWage> lst;
    std::vector<sdds::Employee> employees;
    std::vector<sdds::Salary> salaries;
    for (auto i = 0u; i < emp.size(); ++i) employees.push_back(emp[i]);
    for (auto i = 0u; i < sal.size(); ++i) salaries.push_back(sal[i]);

    sdds::EmployeeWage* employeeWage;
    for (auto& employee: employees) {
        auto it = std::find_if(salaries.cbegin(), salaries.cend(), [&employee](const sdds::Salary& salary) {
            return salary.id == employee.id;
        });
        if (it != salaries.cend() && lst.luhn(employee.id)) {
            employeeWage = new sdds::EmployeeWage(employee.name, it->salary);
            employeeWage->rangeValidator();
            lst += employeeWage;
            delete employeeWage; 
        }
    }
    return lst;
}


sdds::GeneratingList<sdds::EmployeeWage> sdds::writeSmart(const sdds::GeneratingList<sdds::Employee>& emp, const sdds::GeneratingList<sdds::Salary>& sal) {
    sdds::GeneratingList<sdds::EmployeeWage> lst;
    std::vector<sdds::Employee> employees;
    std::vector<sdds::Salary> salaries;
    for (auto i = 0u; i < emp.size(); ++i) employees.push_back(emp[i]);
    for (auto i = 0u; i < sal.size(); ++i) salaries.push_back(sal[i]);

    std::unique_ptr<sdds::EmployeeWage> employeeWage;
    for (auto& employee: employees) {
        auto it = std::find_if(salaries.cbegin(), salaries.cend(), [&employee](const sdds::Salary& salary) {
            return salary.id == employee.id;
        });
        if (it != salaries.cend() && lst.luhn(employee.id)) {
            employeeWage = std::make_unique<sdds::EmployeeWage>(employee.name, it->salary);
            employeeWage->rangeValidator();
            lst += std::move(employeeWage);
        }
    }
    return lst;
}


