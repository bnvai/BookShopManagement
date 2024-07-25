#include "Employees.h"

void employees::add_emp()
{
    std::cout << "Enter Your Id for verification : ";
    std::cin >> id;
    stmt.str("");
    stmt << "Select mgr_stat from employees where id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        std::cout << "Employee Not Found!!" << std::endl
                  << std::endl
                  << std::endl;
        return;
    }
    else
    {
        mgr_status = (char *)row[0];
        if (mgr_status == "T")
        {
            std::cout << "You Do Not have Manager Rights!!!" << std::endl
                      << std::endl;
            return;
        }
    }
    std::cout << "Enter The details of new employees!!";
    std::cout << "Enter The name of the employee : ";
    std::cin >> name;
    std::cout << "Enter the Address (in 3 lines) : " << std::endl;
    std::cin >> addr_line1;
    std::cin >> addr_line2;
    std::cin >> addr_city;
    std::cout << "Enter State : ";
    std::cin >> addr_state;
    std::cout << "Enter phone no.";
    std::cin >> phn;
    std::cout << "Enter the salary : ";
    std::cin >> salary;
    stmt.str("");
    stmt << "Insert into employees (name,addr1,addr2,addr_city,addr_stat,phone_no,doj,salary) values ('" << name << "','" << addr_line1 << "','" << addr_line2 << "','" << addr_city << "','" << addr_state << "'," << phn << ",curdate()," << salary << ");";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    std::cout << std::endl
              << std::endl
              << "Employee Added Succesfully!" << std::endl
              << std::endl
              << std::endl;
}

void employees::assign_mgr_stat()
{
    std::cout << "Enter Your Id for verification : ";
    std::cin >> id;
    stmt.str("");
    stmt << "Select mgr_stat from employees where id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        std::cout << "Employee Not Found!!" << std::endl
                  << std::endl
                  << std::endl;
        return;
    }
    else
    {
        mgr_status = (char *)row[0];
        if (mgr_status == "T")
        {
            std::cout << "You Do Not have Manager Rights!!!" << std::endl
                      << std::endl;
            return;
        }
    }
    std::cout << "Enter the employee id to grant Manager status : ";
    std::cin >> id;
    stmt.str("");
    stmt << "update employees set mgr_stat = 'T' where id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    std::cout << std::endl
              << std::endl
              << std::endl;
    std::cout << "Manager Status granted";
    std::cout << std::endl
              << std::endl
              << std::endl;
}

void employees::search_emp()
{
    std::cout << "Enter the id for searching an employee : ";
    std::cin >> id;
    stmt.str("");
    stmt << "Select * from employees where id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        std::cout << "Employees Details" << std::endl;
        std::cout << "Name : " << row[1] << std::endl;
        std::cout << "Address : " << std::endl
                  << row[2] << std::endl
                  << row[3] << std::endl
                  << row[4] << std::endl;
        std::cout << "State : " << row[5] << std::endl;
        std::cout << "Contact no. : " << row[6] << std::endl;
        std::cout << "Date of Joining" << row[7] << std::endl;
        std::cout << "Salary : " << row[8] << std::endl
                  << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "No Employee Found!!" << std::endl
                  << std::endl
                  << std::endl;
    }
}

void employees::display()
{
    int i = 0;
    query = "Select * from employees;";
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        do
        {
            std::cout << "Employees Details of Emp no." << ++i << std::endl;
            std::cout << "Name : " << row[1] << std::endl;
            std::cout << "Address : " << std::endl
                      << row[2] << std::endl
                      << row[3] << std::endl
                      << row[4] << std::endl;
            std::cout << "State : " << row[5] << std::endl;
            std::cout << "Contact no. : " << row[6] << std::endl;
            std::cout << "Date of Joining" << row[7] << std::endl;
            std::cout << "Salary : " << row[8] << std::endl;
            std::cout << std::endl
                      << std::endl
                      << std::endl
                      << std::endl;
        } while ((row = mysql_fetch_row(res_set)) != NULL);
    }
    else
    {
        std::cout << "Employees Not found!" << std::endl;
    }
}

void employees::update_sal()
{
    std::cout << "Enter the id to update the salary of an employee : ";
    std::cin >> id;
    std::cout << "Enter the updated salary : ";
    std::cin >> salary;
    stmt.str("");
    stmt << "Update employees set salary = " << salary << " where id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl;
    std::cout << "Salary update Successfully";
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl;
}