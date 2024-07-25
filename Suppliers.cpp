#include "Suppliers.h"
void suppliers::add_sup()
{
    std::cout << "Enter the Supplier Name : ";
    std::cin >> name;
    std::cout << "Enter Phone no. : ";
    std::cin >> phn;
    std::cout << "Enter the address (in 3 lines) : ";
    std::cin >> addr_line1;
    std::cin >> addr_line2;
    std::cin >> addr_city;
    std::cout << "Enter State : ";
    std::cin >> addr_state;
    stmt.str("");
    stmt << "Insert into suppliers(name,phone_no,addr1,addr2,addr_city,addr_stat) values('" << name << "'," << phn << ",'" << addr_line1 << "','" << addr_line2 << "','" << addr_city << "','" << addr_state << "');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if (!(res_set))
        std::cout << std::endl
                  << std::endl
                  << "Supplier Record Inserted Successfully" << std::endl
                  << std::endl
                  << std::endl;
    else
        std::cout << std::endl
                  << std::endl
                  << "Entry ERROR !" << std::endl
                  << "Contact Technical Team " << std::endl
                  << std::endl
                  << std::endl;
}

void suppliers::remove_supplier()
{
    std::cout << "Enter the supplier id to remove the Supplier : ";
    std::cin >> id;
    stmt.str("");
    stmt << "Delete from suppliers where id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    std::cout << "Supplier Removed.";
}

void suppliers::search_id()
{
    std::cout << "Enter the supplier id to find the Supplier details : ";
    std::cin >> id;
    stmt.str("");
    stmt << "Select * from suppliers where id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        std::cout << "Details of Supplier Id : " << row[0] << std::endl;
        std::cout << "Name : " << row[1] << std::endl;
        std::cout << "Phone no. : " << row[2] << std::endl;
        std::cout << "Address Line 1 : " << row[3] << std::endl;
        std::cout << "Address Line 2 : " << row[4] << std::endl;
        std::cout << "City : " << row[5] << std::endl;
        std::cout << "State : " << row[6] << std::endl;
    }
    else
    {
        std::cout << "No Supplier Found!!";
    }
}