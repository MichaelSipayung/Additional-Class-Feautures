// ClassesMore.cpp : Defines the entry point for the application.
//

#include "ClassesMore.h"


int main()
{
	std::cout << "More about classes" << std::endl;
	Sales_data sales1;//defaul contructor call
	sales1.bookNo = "0xsaa";
	std::cout << "sales book \t: " << sales1.bookNo << std::endl;
	std::cout << "sales1 \t " << sales1.unit_sold << std::endl;
	std::cout << "understanding copy assignment and destruction" << std::endl;
	Sales_data temp, destination;
	temp.unit_sold = 12;
	destination.unit_sold = temp.unit_sold; //copy assignment 
	std::cout << "test copy assignment\t" << destination.unit_sold << std::endl;
	Sales_data firstSales, secondSales;
	firstSales.unit_sold = 12;
	secondSales.unit_sold = 13;
	moveClass(firstSales, secondSales);
	MySalesData mySales_1;
	//mySales_1.unit_sold;//can't access unit_sold data member
	std::cout << "reading isbn \t: "<<mySales_1.isbn()<<std::endl;
	MySalesData newSales("isbn");
	std::cout << "reading isbn \t: " << newSales.isbn() << std::endl;
	MySalesData currentSales("0xcbn",12,5); //access the constructor 
	
	return 0;
}

double Sales_data::avg_price()const {
	if (unit_sold)
	{
		return revenue / unit_sold;
	}
	else {
		return 0;
	}
}
Sales_data& Sales_data::combine(const Sales_data&rhs) {
	unit_sold += rhs.unit_sold; //add the member of rhs into 
	revenue += rhs.revenue;		// the members of 'this' object
	return *this; //return the object on which the function was called
}
std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.unit_sold >> price;
	item.revenue = price * item.unit_sold;
	return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.unit_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;//copy data member from lhs into sum
	sum.combine(rhs);//add data members from rhs into sum
	return sum;
}
//define constructor outside class body
Sales_data::Sales_data(std::istream& is) {
	read(is, *this); // read will read a transaction from is into this object 
}
void moveClass(Sales_data s1, Sales_data s2) {
	Sales_data tempor;
	tempor = s1;
	s1 = s2;
	s2 = tempor;
	std::cout << "1.move tempor test \t: " << s1.unit_sold << std::endl;
	std::cout << "2.move tempor test \t: " << s2.unit_sold << std::endl;
}
//using class keyword
MySalesData add(const MySalesData& lhs, const MySalesData& rhs) {
	MySalesData  sum = lhs;
	sum.combine(rhs);
	return sum;
}
MySalesData& MySalesData::combine(const MySalesData& rhs) {
	unit_sold += rhs.unit_sold;
	revenue += rhs.revenue;
	return *this;
}
std::istream& readS(std::istream& is, MySalesData& item) {
	double price;
	is >> item.bookNo >> item.unit_sold >> price;
	item.revenue = price * item.unit_sold;
	return is;
}
std::ostream& printS(std::ostream& os, const MySalesData& item) {
	os << item.isbn() << " " << item.unit_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
MySalesData::MySalesData(std::istream& is) {
	readS(is, *this);
}
//noted : next section is about additional class features 
