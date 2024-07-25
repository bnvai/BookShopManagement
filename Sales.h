#include <iostream>
#include <mysql.h>
#include <sstream>
#include <conio.h>
#include "Enum.h"

class sales
{
    int invoice_id; // Primary key
    int member_id;  // FK ref member(id)
    int book_id;    // FK ref books(id)
    int qty;
    int amount;
    date date_s;

    const char *q;
    MYSQL *conn;
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    std::stringstream stmt;
    std::string query;

public:
    sales(MYSQL *connection) : conn(connection){};
    void add();
    void find_total_sales();
};