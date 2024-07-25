#include "Members.h"
void members::add_mem()
{
    std::cout << "Enter the name of the member : ";
    std::cin >> name;
    std::cout << "Enter phone no. : ";
    std::cin >> phn;
    std::cout << "Enter address (in 3 lines)" << std::endl;
    std::cin >> addr_line1;
    std::cin >> addr_line2;
    std::cin >> addr_city;
    std::cout << "Enter the name of the state : ";
    std::cin >> addr_state;
    stmt.str("");
    stmt << "insert into members(name,addr1,addr2,addr_city,addr_stat,phone_no,beg_date,end_date) values ('" << name << "','" << addr_line1 << "','" << addr_line2 << "','" << addr_city << "','" << addr_state << "'," << phn << ",curdate(),Date_add(curdate(), INTERVAL 1 YEAR));";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    // fetching member id...
    stmt.str("");
    stmt << "Select id from members where phone_no = " << phn << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    row = mysql_fetch_row(res_set);
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl;
    std::cout << "Member Added successfully" << std::endl
              << std::endl
              << "Member Id : " << row[0];
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl;
}

void members::refresh()
{
    query = "Update members set valid = 'invalid' where end_date <= curdate();";
    q = query.c_str();
    mysql_query(conn, q);
}

void members::search_mem()
{
    std::cout << "Enter member id : ";
    std::cin >> id;
    stmt.str("");
    stmt << "Select * from members where id  = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        std::cout << "Member Details" << std::endl;
        std::cout << "Name : " << row[1] << std::endl;
        std::cout << "Address : " << std::endl
                  << row[2] << std::endl
                  << row[3] << std::endl
                  << row[4] << std::endl;
        std::cout << "State : " << row[5] << std::endl;
        std::cout << "Contact no. : " << row[6] << std::endl;
        std::cout << "Membership begin date : " << row[7] << std::endl;
        std::cout << "Membership end date  : " << row[8] << std::endl;
        std::cout << "Membership Status : " << row[9] << std::endl
                  << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "No Member Found!!" << std::endl
                  << std::endl
                  << std::endl;
    }
}