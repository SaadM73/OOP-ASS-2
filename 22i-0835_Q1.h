#ifndef Q1_H_
#define Q1_H_
#include<iostream>
using namespace std;

class CSR {
	int csrID;
	char* csrName;
	int hours;
	int complaintsResolved;
	float payrate;
	float wage;
	static int totalComplaintsResolved;

public:

	int getCSRID();
	char* getName();
	int getHours();
	int getComplaintsResolved();
	float getPayrate();
	float getWage();
	void setCSRID(int ID);
	void setName(char* n);
	void setHours(int hours);
	void setComplaintsResolved(int cpsResolved);
	static void setTotalCpsResolved(int totalCpsResolved);
	void calcPayrate();
	void calcWage();
	static int getTotalCpsResolved();
	CSR getCSR_at(CSR employees[7], int index);
	void calcTotalComplaints(CSR employees[7]);
	void calcAllEmployeeWages(CSR employees[7]);
	void SortByHours(CSR employees[7]);
	void SortByComplaintsRes(CSR employees[7]);
	void SortByWages(CSR employees[7]);
	void print();
};  


#endif