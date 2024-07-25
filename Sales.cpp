#include "Sales.h"

void sales::add()
{
    std::cout << "Enter Menber id :";
    std::cin >> member_id;
    std::cout << "Enter the book id : ";
    std::cin >> book_id;
    std::cout << "Enter the quantity : ";
    std::cin >> qty;
    stmt.str("");
    stmt << "select price*" << qty << " from books where id = " << book_id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        std::cout << "The bill amount : " << row[0] << std::endl
                  << std::endl;
        amount = atoi(row[0]);
    }
    else
    {
        std::cout << "Book Id invalid!!" << std::endl;
        getch();
        return;
    }
    stmt.str("");
    stmt << "insert into sales(mem_id,book_id,qty,amt,sales_date) values (" << member_id << "," << book_id << "," << qty << "," << amount << ",curdate());";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    // fetching invoice id...
    stmt.str("");
    stmt << "select inv_id from sales where mem_id = " << member_id << " AND book_id = " << book_id << " AND qty = " << qty << " AND sales_date = curdate();";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        std::cout << "The Invoice id for the bill is " << row[0] << std::endl
                  << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "The entered details maybe wrong." << std::endl
                  << "Please Recheck and Enter again" << std::endl
                  << std::endl
                  << std::endl;
    }
}

void sales::find_total_sales()
{
    query = "select sum(amt) from sales where year(sales_date) = year(curdate());";
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        std::cout << "Total sales this year : " << row[0] << std::endl
                  << std::endl
                  << std::endl
                  << std::endl;
    }
}