#include <iostream>
#include <mysql.h>
#include <sstream>
#include "Enum.h"

class employees
{
    int id; // Primary Key
    std::string name;
    std::string addr_line1;
    std::string addr_line2;
    std::string addr_city;
    std::string addr_state;
    long int phn;
    date date_of_joining;
    long int salary;
    std::string mgr_status; // check(T or F) def f

    const char *q;
    MYSQL *conn;
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    std::stringstream stmt;
    std::string query;

public:
    employees(MYSQL *connection) : conn(connection){};
    void add_emp();
    void search_emp();
    void assign_mgr_stat();
    void display();
    void update_sal();
};