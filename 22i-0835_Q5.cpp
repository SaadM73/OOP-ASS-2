#include"22i-0835_Q5.h"

Sandwich::Sandwich() {
	name = nullptr;
	filling = nullptr;
	size = nullptr;
	is_ready = false;
	price = 0.0;
}

Sandwich::Sandwich(const char* fillingVal, double priceVal) {
	name = nullptr;
	size = nullptr;
	is_ready = 0;
	price = priceVal;
	int x = 0;
	while (fillingVal[x] != '\0') {
		x++;
	}
	int x2 = x + 1;
	filling = new char[x2];
	for (int i = 0; i <= x; i++) {
		filling[i] = fillingVal[i];
	}
}

Sandwich::Sandwich(const char* fillingVal, double priceVal,const char* nameVal,const char* sizeVal, bool ready_status) {
	int x = 0;
	while (fillingVal[x] != '\0') {
		x++;
	}
	int x2 = x + 1;
	filling = new char[x2];
	for (int i = 0; i <= x; i++) {
		filling[i] = fillingVal[i];
	}


	int y = 0;
	while (nameVal[y] != '\0') {
		y++;
	}
	int y2 = y + 1;
	name = new char[y2];
	for (int i = 0; i <= y; i++) {
		name[i] = nameVal[i];
	}


	int z = 0;
	while (sizeVal[z] != '\0') {
		z++;
	}
	int z2 = z + 1;
	size = new char[z2];
	for (int i = 0; i <= z; i++) {
		size[i] = sizeVal[i];
	}

	price = priceVal;
	is_ready = ready_status;
}

Sandwich::Sandwich(const Sandwich& sandwich) {
	int x = 0;
	while (sandwich.filling[x] != '\0') {
		x++;
	}
	int x2 = x + 1;
	filling = new char[x2];
	for (int i = 0; i <= x; i++) {
		filling[i] = sandwich.filling[i];
	}


	int y = 0;
	while (sandwich.name[y] != '\0') {
		y++;
	}
	int y2 = y + 1;
	name = new char[y2];
	for (int i = 0; i <= y; i++) {
		name[i] = sandwich.name[i];
	}


	int z = 0;
	while (sandwich.size[z] != '\0') {
		z++;
	}
	int z2 = z + 1;
	size = new char[z2];
	for (int i = 0; i <= z; i++) {
		size[i] = sandwich.size[i];
	}

	price = sandwich.price;
	is_ready = sandwich.is_ready;
}


void Sandwich::setFilling(const char* fillingVal) {
	int x = 0;
	while (fillingVal[x] != '\0') {
		x++;
	}
	if (filling != NULL) {
		delete[]filling;
		filling = NULL;
	}
	int x2 = x + 1;
	filling = new char[x2];
	for (int i = 0; i <= x; i++) {
		filling[i] = fillingVal[i];
	}
}

void Sandwich::setPrice(double priceVal) {
	price = priceVal;
}

void Sandwich::setName(const char* nameVal) {
	int y = 0;
	while (nameVal[y] != '\0') {
		y++;
	}
	if (name != NULL) {
		delete[]name;
		name = NULL;
	}
	int y2 = y + 1;
	name = new char[y2];
	for (int i = 0; i <= y; i++) {
		name[i] = nameVal[i];
	}

}

void Sandwich::setSize(const char* sizeVal) {
	int z = 0;
	while (sizeVal[z] != '\0') {
		z++;
	}
	if (size != NULL) {
		delete[]size;
		size = NULL;
	}
	int z2 = z + 1;
	size = new char[z2];
	for (int i = 0; i <= z; i++) {
		size[i] = sizeVal[i];
	}
}

char* Sandwich::getFilling() {
	return filling;
}

double Sandwich::getPrice() {
	return price;
}

char* Sandwich::getName() {
	return name;
}

char* Sandwich::getSize() {
	return size;
}

void Sandwich::makeSandwich() {
	if (filling != NULL) {
		is_ready = true;
	}
}

bool Sandwich::check_status() {
	return is_ready;
}

void Sandwich::print() {
	cout << "Name : " << name << endl;
	cout << "Size : " << size << endl;
	cout << "Filling : " << filling << endl;
	cout << "Price : " << price << endl;
	cout << "Status : ";
	if (is_ready) {
		cout << "Ready" << endl;
	}
	else {
		cout << "Not Ready" << endl;
	}
}


Sandwich::~Sandwich() {
	delete[] name;
	delete[] size;
	delete[] filling;
}
