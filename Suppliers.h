#include <iostream>
#include <mysql.h>
#include <sstream>

class suppliers
{
    int id; // Primary Key
    std::string name;
    long int phn;
    std::string addr_line1;
    std::string addr_line2;
    std::string addr_city;
    std::string addr_state;

    const char *q;
    MYSQL *conn;
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    std::stringstream stmt;
    std::string query;

public:
    suppliers(MYSQL *connection) : conn(connection){};
    void add_sup();
    void remove_supplier();
    void search_id();
};
