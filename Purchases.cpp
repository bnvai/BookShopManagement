#include "Purchases.h"
void purchases::new_ord()
{
    std::cout << "Enter the book Id : ";
    std::cin >> book_id;
    std::cout << "Enter Supplier Id : ";
    std::cin >> sup_id;
    std::cout << "Enter the Quantity : ";
    std::cin >> qty;
    std::cout << "Estimated expected Delivery (in days) : ";
    std::cin >> eta;
    stmt.str("");
    stmt << "Insert into purchases (book_id,sup_id,qty,dt_ord,eta) values ( " << book_id << "," << sup_id << "," << qty << ",curdate(),Date_add(curdate(), INTERVAL " << eta << " DAY)" << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    std::cout << "New order Added!!";
}

void purchases::mark_reciv()
{
    std::cout << "Enter the order id for order recieved : ";
    std::cin >> ord_id;
    stmt.str("");
    stmt << "Update puchases set recieved = 'T' where ord_id = " << ord_id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    std::cout << "Recieved Marked successfully";
}

void purchases::mar_cancel()
{
    std::cout << "Enter the order id for order cancelled : ";
    std::cin >> ord_id;
    stmt.str("");
    stmt << "Update puchases set recieved = 'C' where ord_id = " << ord_id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    std::cout << "Cancelled Marked successfully";
}

void purchases::view()
{
    int c;
    std::cout << "Select an Option" << std::endl;
    std::cout << "1. View orders not Recieved" << std::endl;
    std::cout << "2. View orders Cancelled" << std::endl;
    std::cout << "3. View orders Recieved" << std::endl;
    std::cout << "Enter Your choice : ";
    std::cin >> c;
    if (c == 1)
        received = 'F';
    else if (c == 2)
        received = 'C';
    else if (c == 3)
        received = 'T';
    else
        return;
    stmt.str("");
    stmt << "Select * from purchases where recieved = '" << received << "';";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if (c == 1)
        std::cout << std::endl
                  << "Orders not recieved are" << std::endl;
    else if (c == 2)
        std::cout << std::endl
                  << "Orders Cancelled are" << std::endl;
    else if (c == 3)
        std::cout << std::endl
                  << "Orders recieved are" << std::endl;
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        std::cout << std::endl;
        std::cout << "Order Id : " << row[0] << std::endl;
        std::cout << "Book Id : " << row[1] << std::endl;
        std::cout << "Supplier Id :" << row[2] << std::endl;
        std::cout << "Quantity : " << row[3] << std::endl;
        std::cout << "Date Ordered : " << row[4] << std::endl;
        std::cout << "Estimated Delivery date : " << row[5] << std::endl;
        std::cout << std::endl
                  << std::endl
                  << std::endl;
    }
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl
              << std::endl;
}