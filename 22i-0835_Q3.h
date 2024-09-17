#ifndef Q3_H_
#define Q3_H_
#include<iostream>
#include<string>
using namespace std;

class String {
	char* data;
	int length;

public:
	String();
	String(int size);
	String( char* str);
	String(const String& str);
	int strLength();
	void clear();
	bool empty();
	int charAt(char c);
	void CompressString();
	void findMinStr(char* secretStr);
	bool equalsIgnoreCase(char* str);
	char* substring(char* substr, int startIndex);
	char* substring(char* substr, int startIndex, int endIndex);
	int ColorChallange(char* hand);
	void display();


	~String();
};

#endif