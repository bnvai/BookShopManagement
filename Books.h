#include <iostream>
#include <mysql.h>
#include <sstream>
class books
{
private:
	int id; // Primary Key
	std::string name;
	std::string auth;
	int price;
	int qty;

	const char *q;
	MYSQL *conn;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;

public:
	books(MYSQL *connection) : conn(connection){};
	void add();
	void update_price();
	void search();
	void update();
	void display();
};
