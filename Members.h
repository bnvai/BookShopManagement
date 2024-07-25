#include <iostream>
#include <mysql.h>
#include <sstream>
#include "Enum.h"

class members
{
	int id; // Primary Key
	std::string name;
	std::string addr_line1;
	std::string addr_line2;
	std::string addr_city;
	std::string addr_state;
	long int phn;
	date beg_date;
	date end_date;
	std::string valid;

    const char *q;
    MYSQL *conn;
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    std::stringstream stmt;
    std::string query;

public:
    members(MYSQL *connection) : conn(connection){};
	void add_mem();
	void refresh();
	void search_mem();
};