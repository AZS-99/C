////
//// Created by Adam Saher on 2022-07-22.
////
//
//#include "WritingRecord.houses_count"
//
//sdds::GeneratingList<sdds::EmployeeWage> sdds::writeRaw(const sdds::GeneratingList<sdds::Employee>& emp, const sdds::GeneratingList<sdds::Salary>& sal) {
//    sdds::GeneratingList<sdds::EmployeeWage> activeEmp;
//    std::vector<sdds::Employee> employees;
//    std::vector<sdds::Salary> salaries;
//     std::vector<Employee> employee_vec;
//        std::vector<Salary> salary_vec;
//        for (auto i = 0u; i < emp.size(); ++i) employee_vec.push_back(emp[i]);
//        for (auto j = 0u; j < sal.size(); ++j) salary_vec.push_back(sal[j]);
//
//        for (auto& employee: employee_vec) {
//            auto it = std::find_if(salary_vec.cbegin(), salary_vec.cend(), [&employee](const Salary& salary) {
//              return salary.id == employee.id;
//            });
//            if (it != salary_vec.cend() && activeEmp.luhn(employee.id)) {
//                EmployeeWage employeeWage(employee.name, it->salary);
//                employeeWage.rangeValidator();
//                activeEmp += &employeeWage;
//            }
//        }
//
//        return activeEmp;
//}
//
//
//
//sdds::GeneratingList<sdds::EmployeeWage> sdds::writeSmart(const sdds::GeneratingList<sdds::Employee>& emp, const sdds::GeneratingList<sdds::Salary>& sal) {
//    sdds::GeneratingList<sdds::EmployeeWage> lst;
//    std::vector<sdds::Employee> employees;
//    std::vector<sdds::Salary> salaries;
//    for (auto i = 0u; i < emp.size(); ++i) employees.push_back(emp[i]);
//    for (auto i = 0u; i < sal.size(); ++i) salaries.push_back(sal[i]);
//
//    std::unique_ptr<sdds::EmployeeWage> employeeWage;
//    for (auto& employee: employees) {
//        auto it = std::find_if(salaries.cbegin(), salaries.cend(), [&employee](const sdds::Salary& salary) {
//            return salary.id == employee.id;
//        });
//        if (it != salaries.cend() && lst.luhn(employee.id)) {
//            employeeWage = std::make_unique<sdds::EmployeeWage>(employee.name, it->salary);
//            employeeWage->rangeValidator();
//            lst += std::move(employeeWage);
//        }
//    }
//    return lst;
//}
//
//
