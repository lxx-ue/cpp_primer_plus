#include <iostream>
#include "ch12_3.h"

Stock::Stock()
{
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares cant be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{

}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased cant be negative; "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares sold cant be negative; "
			<<  "Transaction is aborted.\n";
	}
	else if (num>shares)
		std::cout << "You cant sell more than you have!; "
		<< "Transaction is aborted.\n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	std::cout << "Company " << company
		<< "\nShares " << shares
		<< "\nShare price: $" << share_val
		<< "\nTotal worth: $" << total_val;
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val) return s;
	else return *this;
}