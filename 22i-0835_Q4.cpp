#include"22i-0835_Q4.h"

void CustomerAccount::OpenCustomerAccount(CustomerAccount* customers[], int& accountsOpen, char* NameVal,char* addVal, char* cityVal, char* stateVal, int zipcodeVal, long long phoneVal, float balanceVal) {
//	CustomerAccount customers[accountsOpen];
	customers[accountsOpen] = new CustomerAccount;
	customers[accountsOpen]->accountNum = new char[6];
	
	customers[accountsOpen]->accountNum[0] = 'P';
	customers[accountsOpen]->accountNum[1] = 'K';
//	customers[accountsOpen]->accountNum[2] = '0';
//	customers[accountsOpen]->accountNum[3] = '0';
	
	int temp = 0;
	temp = accountsOpen+1;
	int x = 0;
	int arr[3]{};
	for (int i = 2; i >= 0; i--) {
		x = temp % 10;
		temp = temp / 10;
		arr[i] = x;
	}
	 
	customers[accountsOpen]->accountNum[2] =arr[0]+48;
	customers[accountsOpen]->accountNum[3] = arr[1]+48;
	int saad = accountsOpen + 1;
	customers[accountsOpen]->accountNum[4] =arr[2]+48;
	customers[accountsOpen]->accountNum[5] = '\0';



	x = 0;
	while (NameVal[x] != '\0') {
		x++;
	}
	customers[accountsOpen]->name = new char[x + 1];
	for (int i = 0; i < x + 1; i++) {
		customers[accountsOpen]->name[i] = NameVal[i];
	}
	customers[accountsOpen]->name[x + 1] = '\0';



	customers[accountsOpen]->phoneNum = phoneVal;
	customers[accountsOpen]->balance = balanceVal;




	x = 0;
	while (addVal[x] != '\0') {
		x++;

	}
	customers[accountsOpen]->address.address = new char[x + 1];
	for (int i = 0; i < x + 1; i++) {
		customers[accountsOpen]->address.address[i] = addVal[i];
	}

	customers[accountsOpen]->address.address[x] = '\0';




	x = 0;
	while (cityVal[x] != '\0') {
		x++;

	}
	customers[accountsOpen]->address.city = new char[x + 1];
	for (int i = 0; i < x + 1; i++) {
		customers[accountsOpen]->address.city[i] = cityVal[i];
	}

	customers[accountsOpen]->address.city[x] = '\0';




	x = 0;
	while (stateVal[x] != '\0') {
		x++;

	}
	customers[accountsOpen]->address.state = new char[x + 1];
	for (int i = 0; i < x + 1; i++) {
		customers[accountsOpen]->address.state[i] = stateVal[i];
	}

	customers[accountsOpen]->address.state[x] = '\0';


	customers[accountsOpen]->address.zip_code = zipcodeVal;

	accountsOpen++;

}

int CustomerAccount::SearchCustomer(CustomerAccount* customers[], int accountsOpen, char* accountNum) {
	bool flag = 1;
	int x = -1;
	for (int i = 0; i < accountsOpen; i++) {
		for (int j = 0; j < 5; j++) {
			if (customers[i]->accountNum[j] != accountNum[j]) {
				flag = 0;
			}

		}
		if (flag) {
			x = i;
			return x;
		}
		flag = 1;
	}
		return x;
	

}

bool CustomerAccount::UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNumVal, Address addressVal) {
	int x = -1;
	bool flag = 1;
	for (int i = 0; i < accountsOpen; i++) {
		for (int j = 0; j < 5; j++) {
			if ((customers[i]->accountNum[j]) != accountNumVal[j]) {
				flag = 0;
			}

		}
		if (flag) {
			x = i;
		}
		flag = 1;

	}
	if (x == -1) {
		flag = 0;
		return flag;
	}
	else {
		flag = 1;
	}
	delete customers[x]->address.address;
	customers[x]->address.address = addressVal.address;

	delete customers[x]->address.city;
	customers[x]->address.city = addressVal.city;

	delete customers[x]->address.state;
	customers[x]->address.state = addressVal.state;

	customers[x]->address.zip_code = addressVal.zip_code;
	
	return flag;
}

bool CustomerAccount::UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNumVal, long long phoneVal) {
	int x = -1;
	bool flag = 1;
	for (int i = 0; i < accountsOpen; i++) {
		for (int j = 0; j < 5; j++) {
			if ((customers[i]->accountNum[j]) != accountNumVal[j]) {
				flag = 0;
			}

		}
		if (flag) {
			x = i;
		}
		flag = 1;
	}
	if (x == -1) {
		flag = 0;
		return flag;
	}
	else {
		flag = 1;
	}

	customers[x]->phoneNum = phoneVal;
	return flag;

}


bool CustomerAccount::UpdateCustomerAccount(CustomerAccount* customers[], int accountsOpen, char* accountNumVal, float balanceVal) {
	int x = -1;
	bool flag = 1;
	for (int i = 0; i < accountsOpen; i++) {
		for (int j = 0; j < 5; j++) {
			if ((customers[i]->accountNum[j]) != accountNumVal[j]) {
				flag = 0;
			}
		}
		if (flag) {
			x = i;
		}
		flag = 1;
	}
	if (x == -1) {
		flag = 0;
		return flag;
	}
	else {
		flag = 1;
	}

	customers[x]->balance = balanceVal;
	return flag;
}

void CustomerAccount:: DisplayAllCustomers(CustomerAccount* customers[], int accountsOpen) {
	for (int i = 0; i < accountsOpen; i++) {
		cout << "Name : " << customers[i]->name << endl << endl;;
		cout << "Address : " << customers[i]->address.address << endl;
		cout << "  -city : " << customers[i]->address.city << endl;
		cout << "  -state: " << customers[i]->address.state << endl;
		cout << "  -zipc : " << customers[i]->address.zip_code << endl << endl;;
		cout << "Phone No : " << customers[i]->phoneNum << endl;
		cout << "Balance : " << customers[i]->balance << endl;
		cout << "Account No : " << customers[i]->accountNum <<endl;
		cout << "==================================================";
		cout << endl << endl;
	}
}





