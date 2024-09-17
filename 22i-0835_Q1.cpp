#include"22i-0835_Q1.h"

int CSR::totalComplaintsResolved = 0;

int CSR::getCSRID() {
	return csrID;
}

char* CSR::getName() {
	return csrName;
}

int CSR::getHours() {
	return hours;
}

int CSR::getComplaintsResolved() {
	return complaintsResolved;
}

float CSR::getPayrate() {
	return payrate;
}

float CSR::getWage() {
	return wage;
}

void CSR::setCSRID(int ID) {
	csrID = ID;
}

void CSR::setName(char* n) {
	int x = 0;
	while (n[x] != '\0') {
		x++;
	}
	csrName = new char[x+1];
	for (int i = 0; i < x+1; i++) {
		csrName[i] = n[i];
	}
	csrName[x] = '\0';
}

void CSR::setHours(int hour) {
	hours = hour;
}

void CSR::setComplaintsResolved(int cpsResolved) {
	complaintsResolved = cpsResolved;
}

void CSR::setTotalCpsResolved(int totalCpsResolved) {
	totalComplaintsResolved = totalCpsResolved;
}

void CSR::calcPayrate() {
	payrate = 25 + (25 * (float(complaintsResolved) / float(totalComplaintsResolved)));
}

void CSR::calcWage() {
	wage = hours * payrate;
}

int CSR::getTotalCpsResolved() {
	return totalComplaintsResolved;
}

CSR CSR::getCSR_at(CSR employees[7], int index) {
	return employees[index];
}

void CSR::calcTotalComplaints(CSR employees[7]) {
	int x = 0;
	for (int i = 0; i < 7; i++) {
		x += employees[i].getComplaintsResolved();

	}
	totalComplaintsResolved = x;
}

void CSR::calcAllEmployeeWages(CSR employees[7]) {
	for (int i = 0; i < 7; i++) {
		employees[i].wage = employees[i].getHours() * employees[i].getPayrate();
	}
}

void CSR::SortByHours(CSR employees[7]) {
	int temp = 0;
	float temp2 = 0;
	char* temp3;
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (employees[i].hours < employees[j].hours) {
				temp = employees[i].hours;
				employees[i].hours = employees[j].hours;
				employees[j].hours = temp;

				temp = employees[i].csrID;
				employees[i].csrID = employees[j].csrID;
				employees[j].csrID = temp;

				temp = employees[i].complaintsResolved;
				employees[i].complaintsResolved = employees[j].complaintsResolved;
				employees[j].complaintsResolved = temp;

				temp2 = employees[i].payrate;
				employees[i].payrate = employees[j].payrate;
				employees[j].payrate = temp2;

				temp2 = employees[i].wage;
				employees[i].wage = employees[j].wage;
				employees[j].wage = temp2;
				
				int x = 0, x2 = 0;
				while (employees[i].csrName[x] != '\0') {
					x++;
				}
				x++;
				temp3 = new char[x];
				for (int z = 0; z < x; z++) {
					temp3[z] = employees[i].csrName[z];
				}

				while (employees[j].csrName[x2] != '\0') {
					x2++;
				}
				x2++;


				delete[] employees[i].csrName;
				employees[i].csrName = new char[x2];
				for (int z = 0; z < x2; z++) {
					employees[i].csrName[z] = employees[j].csrName[z];
				}

				delete[] employees[j].csrName;
				employees[j].csrName = new char[x];
				for (int z = 0; z < x; z++) {
					 employees[j].csrName[z]= temp3[z];
				}

				
			}
		}
	}
}

void CSR::SortByComplaintsRes(CSR employees[7]) {
	int temp = 0;
	float temp2 = 0;
	char* temp3;
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (employees[i].complaintsResolved < employees[j].complaintsResolved) {
				temp = employees[i].hours;
				employees[i].hours = employees[j].hours;
				employees[j].hours = temp;

				temp = employees[i].csrID;
				employees[i].csrID = employees[j].csrID;
				employees[j].csrID = temp;

				temp = employees[i].complaintsResolved;
				employees[i].complaintsResolved = employees[j].complaintsResolved;
				employees[j].complaintsResolved = temp;

				temp2 = employees[i].payrate;
				employees[i].payrate = employees[j].payrate;
				employees[j].payrate = temp2;

				temp2 = employees[i].wage;
				employees[i].wage = employees[j].wage;
				employees[j].wage = temp2;

				int x = 0, x2 = 0;
				while (employees[i].csrName[x] != '\0') {
					x++;
				}
				x++;
				temp3 = new char[x];
				for (int z = 0; z < x; z++) {
					temp3[z] = employees[i].csrName[z];
				}

				while (employees[j].csrName[x2] != '\0') {
					x2++;
				}
				x2++;


				delete[] employees[i].csrName;
				employees[i].csrName = new char[x2];
				for (int z = 0; z < x2; z++) {
					employees[i].csrName[z] = employees[j].csrName[z];
				}

				delete[] employees[j].csrName;
				employees[j].csrName = new char[x];
				for (int z = 0; z < x; z++) {
					employees[j].csrName[z] = temp3[z];
				}

			}
		}
	}
}

void CSR::SortByWages(CSR employees[7]) {
	int temp = 0;
	float temp2 = 0;
	char* temp3;
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			if (employees[i].wage < employees[j].wage) {
				temp = employees[i].hours;
				employees[i].hours = employees[j].hours;
				employees[j].hours = temp;

				temp = employees[i].csrID;
				employees[i].csrID = employees[j].csrID;
				employees[j].csrID = temp;

				temp = employees[i].complaintsResolved;
				employees[i].complaintsResolved = employees[j].complaintsResolved;
				employees[j].complaintsResolved = temp;

				temp2 = employees[i].payrate;
				employees[i].payrate = employees[j].payrate;
				employees[j].payrate = temp2;

				temp2 = employees[i].wage;
				employees[i].wage = employees[j].wage;
				employees[j].wage = temp2;

				int x = 0, x2 = 0;
				while (employees[i].csrName[x] != '\0') {
					x++;
				}
				x++;
				temp3 = new char[x];
				for (int z = 0; z < x; z++) {
					temp3[z] = employees[i].csrName[z];
				}

				while (employees[j].csrName[x2] != '\0') {
					x2++;
				}
				x2++;


				delete[] employees[i].csrName;
				employees[i].csrName = new char[x2];
				for (int z = 0; z < x2; z++) {
					employees[i].csrName[z] = employees[j].csrName[z];
				}

				delete[] employees[j].csrName;
				employees[j].csrName = new char[x];
				for (int z = 0; z < x; z++) {
					employees[j].csrName[z] = temp3[z];
				}

			}
		}
	}
}

void CSR::print() {
	cout << "CSR ID : " << csrID << endl;
	cout << "CSR Name : " << csrName << endl;
	cout << "Hours : " << hours << endl;
	cout << "Complaints Resolved : " << complaintsResolved << endl;
	cout << "PayRate : " << payrate << endl;
	cout << "Wage : " << wage << endl;
	cout << "TComplaintsResolved : " << getTotalCpsResolved() << endl;
}


