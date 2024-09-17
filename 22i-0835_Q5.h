#ifndef Q5_H_
#define Q5_H_
#include<iostream>
using namespace std;


class Sandwich {

	char* name;
	char* filling;
	char* size;
	bool is_ready;
	double price;

public:
	Sandwich();
	Sandwich(const char* fillingVal, double priceVal);
	Sandwich(const char* fillingVal, double priceVal,const char* nameVal,const char* sizeVal, bool ready_status);
	Sandwich(const Sandwich& sandwich);
	void setFilling(const char* fillingVal);
	void setPrice(double priceVal);
	void setName(const char* nameVal);
	void setSize(const char* sizeVal);
	char* getFilling();
	double getPrice();
	char* getName();
	char* getSize();
	void makeSandwich();
	bool check_status();
	void print();
	~Sandwich();

};


#endif
 