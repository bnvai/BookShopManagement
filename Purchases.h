#include <iostream>
#include <mysql.h>
#include <sstream>
#include "Enum.h"

class purchases
{
	int ord_id;	 // Primary Key
	int book_id; // FK ref (books)
	int sup_id;	 // FK ref (suppliers)
	int qty;
	date dt_ordered;
	int eta;
	char received; // Check(T or C or F) def (F)
	int inv;

    const char *q;
    MYSQL *conn;
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    std::stringstream stmt;
    std::string query;

public:
    purchases(MYSQL *connection) : conn(connection){};
	void new_ord();
	void view();
	void mar_cancel();
	void mark_reciv();
};
