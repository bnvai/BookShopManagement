#include "Books.h"

void books::add()
{
	std::cout << "Input Book Information: ";

	std::cout << "\nID: ";
	std::cin >> id;
	std::cin.ignore();

	std::cout << "Name: ";
	std::getline(std::cin, name);

	std::cout << "Author: ";
	std::getline(std::cin, auth);

	std::cout << "Price: ";
	std::cin >> price;
	std::cin.ignore();

	std::cout << "Quantity: ";
	std::cin >> qty;
	std::cin.ignore();

	std::ostringstream queryStream;
	queryStream << "INSERT INTO BOOKS(id, name, auth, price, qty) VALUES (";
	queryStream << id << ", ";
	queryStream << "'" << name << "', ";
	queryStream << "'" << auth << "', ";
	queryStream << price << ", ";
	queryStream << qty << ")";

	query = queryStream.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
		std::cout << std::endl
				  << std::endl
				  << "Book Record Inserted Successfully" << std::endl
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

void books::update_price()
{
	char choice;
	std::cout << "Enter the id of the book for update in price : ";
	std::cin >> id;
	stmt.str("");
	stmt << "Select name,price from books where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "The Name of the book is : " << row[0] << std::endl;
		std::cout << "The current price of the book is : " << row[1] << std::endl;
		std::cout << "Do you Want to Update the Price [y/n] : ";
		std::cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			std::cout << "Enter the new price : ";
			std::cin >> price;
			stmt.str("");
			stmt << "Update books set price = " << price << " where id = " << id << ";";

			query = stmt.str();
			q = query.c_str();
			mysql_query(conn, q);

			res_set = mysql_store_result(conn);
			if (!(res_set))
				std::cout << std::endl
						  << std::endl
						  << "Book Price Updated Successfully" << std::endl
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
		else
		{
			std::cout << "No changes Made!!";
		}
	}
	else
	{
		std::cout << "No Book found!!!";
	}
}

void books::search()
{
	std::cout << "Enter book id for details : ";
	std::cin >> id;
	stmt.str("");
	stmt << "Select * from books where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "The Details of Book Id " << row[0] << std::endl;
		std::cout << "The Name of the book is : " << row[1] << std::endl;
		std::cout << "THE Author of " << row[1] << " is " << row[2] << std::endl;
		std::cout << "The Price of the book is : " << row[3] << std::endl;
		std::cout << "The inventory count is " << row[4] << std::endl;
	}
	else
	{
		std::cout << "No record Found" << std::endl;
	}
}

void books::update()
{
	int b_id[100], qty[100], i = 0, max;
	stmt.str("");
	stmt << "Select book_id,qty from purchases where recieves = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);

	stmt.str("");
	stmt << "Update purchases set inv = 1 where recieves = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);

	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		b_id[i] = atoi(row[0]);
		qty[i] = atoi(row[4]);
		i++;
	}
	max = i;
	for (i = 0; i <= max; i++)
	{
		stmt.str("");
		stmt << "update books set qty = " << qty[i] << " where id = " << b_id[i] << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
	}
	std::cout << "The orders recieved have been updated.";
}

void books::display()
{
	int i = 0;
	query = "Select * from books;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		std::cout << "Name for book " << ++i << " : " << row[1] << std::endl;
		std::cout << "Name of Author : " << row[2] << std::endl;
		std::cout << "Price : " << row[3] << std::endl;
		std::cout << "Quantity : " << row[4] << std::endl;
		std::cout << std::endl
				  << std::endl;
	}
}
