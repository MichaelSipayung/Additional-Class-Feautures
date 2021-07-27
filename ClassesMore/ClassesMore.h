// ClassesMore.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
//interface of class sales_data
struct Sales_data
{
	//constructor added
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s){}
	Sales_data(const std::string& s, unsigned n, double p):
		bookNo(s),unit_sold(n),revenue(p*n){}
	Sales_data(std::istream&);
	//above is the definition of four constructor
	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price()const;
	std::string bookNo;
	unsigned unit_sold = 0;
	double revenue = 0;

};
//nonmemver sales_data interface function
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, std::ostream&);
std::istream& read(std::istream&, Sales_data&);
void moveClass(Sales_data s1,Sales_data s2);

class MySalesData
{
	//declaring a friend class or function 
	//friend declaration for nonmember MySalesData operation add
friend MySalesData add(const MySalesData&, const MySalesData&);
friend std::istream&readS(std::istream& , MySalesData& );
friend std::ostream& printS(std::ostream&, const MySalesData&);
public: //access specifier added
	MySalesData() = default;
	MySalesData(const std::string &s,unsigned n,double p):
		bookNo(s),unit_sold(n),revenue(p*n){}
	MySalesData(const std::string& s) :bookNo(s) {};
	MySalesData(std::istream&);
	std::string isbn()const { return bookNo; }
	MySalesData& combine(const MySalesData&);
private://access specifier added
	double avg_price()const {
		return unit_sold ? revenue / unit_sold : 0;
	}
	std::string bookNo;
	unsigned unit_sold = 0;
	double revenue = 0.0;
};
//declarations for nonmember parts of the sales_data insterface 
//other member some as before  
