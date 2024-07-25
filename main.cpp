#include <iostream>
#include <mysql.h>
#include <conio.h>
#include "Books.h"
#include "Employees.h"
#include "Members.h"
#include "Suppliers.h"
#include "Purchases.h"
#include "Sales.h"

#define HOST "localhost"
#define USER "gaDev"
#define PASS "123456"
#define DATABASE "school"
#define PORT 3306
#define PASSWORD 1234

MYSQL *conn;

// books menu
void book_menu()
{
	int c;
	books m_book(conn);
	std::cout << "*************************************************" << std::endl;
	std::cout << "                  BOOK MENU" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "   1. ADD" << std::endl;
	std::cout << "   2. UPDATE PRICE" << std::endl;
	std::cout << "   3. SEARCH" << std::endl;
	std::cout << "   4. UPDATE STATUS" << std::endl;
	std::cout << "   5. DISPLAY ALL" << std::endl;
	std::cout << "   6. RETURN TO MAIN MENU" << std::endl
			  << std::endl
			  << std::endl;
	std::cout << "Enter Your Choice : ";
	std::cin >> c;
	switch (c)
	{
	case 1:
		m_book.add();
		break;
	case 2:
		m_book.update_price();
		break;
	case 3:
		m_book.search();
		break;
	case 4:
		m_book.update();
		break;
	case 5:
		m_book.display();
		break;
	case 6:
		return;
		break;
	default:
		std::cout << "Wrong Input" << std::endl
				  << "Invalid input";
		break;
	}
	return;
}

// suppliers

void sup_menu()
{
	int c;
	suppliers m_sup(conn);
	std::cout << "*************************************************" << std::endl;
	std::cout << "                SUPPLIER MENU" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "   1. ADD" << std::endl;
	std::cout << "   2. REMOVE" << std::endl;
	std::cout << "   3. SEARCH" << std::endl;
	std::cout << "   4. RETURN TO MAIN MENU" << std::endl
		 << std::endl
		 << std::endl;
	std::cout << "Enter Your Choice : ";
	std::cin >> c;
	switch (c)
	{
	case 1:
		m_sup.add_sup();
		break;
	case 2:
		m_sup.remove_supplier();
		break;
	case 3:
		m_sup.search_id();
		break;
	case 4:
		return;
	default:
		std::cout << "Wrong Input" << std::endl
			 << "Invalid input";
		break;
	}
}

// purchase menu

void pur_menu()
{
	int c;
	purchases m_pur(conn);
	std::cout << "*************************************************" << std::endl;
	std::cout << "                PURCHASES MENU" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "   1. New Order" << std::endl;
	std::cout << "   2. View All" << std::endl;
	std::cout << "   3. Cancel Order" << std::endl;
	std::cout << "   4. Recieved Order" << std::endl;
	std::cout << "   5. RETURN TO MAIN MENU" << std::endl
		 << std::endl
		 << std::endl;
	std::cout << "Enter Your Choice : ";
	std::cin >> c;
	switch (c)
	{
	case 1:
		m_pur.new_ord();
		break;
	case 2:
		m_pur.view();
		break;
	case 3:
		m_pur.mar_cancel();
		break;
	case 4:
		m_pur.mark_reciv();
		break;
	case 5:
		return;
	default:
		std::cout << "Wrong Input" << std::endl
			 << "Invalid input";
		break;
	}
}

// emp_menu

void emp_menu()
{
	int c;
	employees m_emp(conn);
	std::cout << "*************************************************" << std::endl;
	std::cout << "                 EMPLOYEE MENU" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "   1. New Employee" << std::endl;
	std::cout << "   2. Search Employee" << std::endl;
	std::cout << "   3. Assign Manager" << std::endl;
	std::cout << "   4. View All" << std::endl;
	std::cout << "   5. Update Salary" << std::endl;
	std::cout << "   6. RETURN TO MAIN MENU" << std::endl
		 << std::endl
		 << std::endl;
	std::cout << "Enter Your Choice : ";
	std::cin >> c;
	switch (c)
	{
	case 1:
		m_emp.add_emp();
		break;
	case 2:
		m_emp.search_emp();
		break;
	case 3:
		m_emp.assign_mgr_stat();
		break;
	case 4:
		m_emp.display();
		break;
	case 5:
		m_emp.update_sal();
		break;
	case 6:
		return;
	default:
		std::cout << "Wrong Input" << std::endl
			 << "Invalid input";
		break;
	}
}

// mem menu

void mem_menu()
{
	int c;
	members m_mem(conn);
	m_mem.refresh();
	std::cout << "*************************************************" << std::endl;
	std::cout << "                 MEMBERS MENU" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "   1. New Member" << std::endl;
	std::cout << "   2. Search Member" << std::endl;
	std::cout << "   3. RETURN TO MAIN MENU" << std::endl
		 << std::endl
		 << std::endl;
	std::cout << "Enter Your Choice : ";
	std::cin >> c;
	switch (c)
	{
	case 1:
		m_mem.add_mem();
		break;
	case 2:
		m_mem.search_mem();
		break;
	case 3:
		return;
	default:
		std::cout << "Wrong Input" << std::endl
			 << "Invalid input";
		break;
	}
}

// sal_menu

void sal_menu()
{
	int c;
	sales m_sal(conn);
	std::cout << "*************************************************" << std::endl;
	std::cout << "                 SALES MENU" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "   1. Add New Bill" << std::endl;
	std::cout << "   2. Total Sales Of The Year" << std::endl;
	std::cout << "   3. RETURN TO MAIN MENU" << std::endl
		 << std::endl
		 << std::endl;
	std::cout << "Enter Your Choice : ";
	std::cin >> c;
	switch (c)
	{
	case 1:
		m_sal.add();
		break;
	case 2:
		m_sal.find_total_sales();
		break;
	case 3:
		return;
	default:
		std::cout << "Wrong Input" << std::endl
			 << "Invalid input";
		break;
	}
}

void main_menu()
{
	int c;
	std::cout << "*************************************************" << std::endl;
	std::cout << "         BOOKSHOP MANGEMENT SYSTEM" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "   1. BOOKS" << std::endl;
	std::cout << "   2. SUPPLIERS" << std::endl;
	std::cout << "   3. PURCHASES" << std::endl;
	std::cout << "   4. EMPLOYEES" << std::endl;
	std::cout << "   5. MEMBERS" << std::endl;
	std::cout << "   6. SALES" << std::endl;
	std::cout << "   7. EXIT" << std::endl
			  << std::endl
			  << std::endl;
	std::cout << "Enter Your Choice : ";
	std::cin >> c;
	switch (c)
	{
	case 1:
		system("cls");
		book_menu();
		getch();
		break;
	case 2:
		system("cls");
		sup_menu();
		getch();
		break;
	case 3:
		system("cls");
		pur_menu();
		getch();
		break;
	case 4:
		system("cls");
		emp_menu();
		getch();
		break;
	case 5:
		system("cls");
		mem_menu();
		getch();
		break;
	case 6:
		system("cls");
		sal_menu();
		getch();
		break;
	case 7:
		exit(1);
	default:
		system("cls");
		std::cout << "Wrong Input" << std::endl
				  << std::endl
				  << "Invalid input";
		getch();
		break;
	}
	return;
}

void pass()
{
	int num = 0;
	std::cout << "Enter password : ";
	for (int i = 0; i < 4; i++)
	{
		num = num * 10 + (getch() - 48);
		std::cout << "*";
	}
	if (num == PASSWORD)
	{
		std::cout << std::endl
				  << std::endl
				  << "Correct Password" << std::endl
				  << std::endl;
		std::cout << "Press any key...";
		getch();
	}
	else
	{
		std::cout << std::endl
				  << std::endl
				  << "Incorrect Password" << std::endl
				  << std::endl;
		std::cout << "Press any key...";
		getch();
		exit(1);
	}
	return;
}

void book_menu();
void sup_menu();
void pur_menu();
void emp_menu();
void mem_menu();
void sal_menu();

int main()
{
	std::cout << "*************************************************" << std::endl;
	std::cout << "               WELCOME TO BOOKSHOP" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "               	PLEASE LOGIN" << std::endl;
	std::cout << "*************************************************" << std::endl;
	pass();

	conn = mysql_init(NULL); // Initialize MySQL object
	conn = mysql_real_connect(conn, HOST, USER, PASS, DATABASE, PORT, NULL, 0);

	if (conn)
	{
		while (1)
		{
			system("cls");
			std::cout << "Connected to database." << std::endl;
			main_menu();
		}
	}
	else
	{
		system("cls");
		std::cout << "Error While connection to database." << std::endl
				  << mysql_error(conn) << std::endl
				  << "Contact Tech Expert." << std::endl;
		getch();
	}

	mysql_close(conn); // Close MySQL connection
	return 0;
}
