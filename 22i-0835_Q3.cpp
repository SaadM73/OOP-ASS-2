#include"22i-0835_Q3.h"

String::String() {
	data = nullptr;
	length = 0;
}

String::String(int size) {
	length = size;
	data = new char[size];
}


String::String( char* str) {
	int x = 0;
	while (str[x] != '\0') {
		x++;
	}
	length = x+1;
	data = new char[x+1];
	for (int i = 0; i < x+1; i++) {
		data[i] = str[i];
	}
	data[x] = '\0';
}

String::String(const String& str) {
	length = str.length;
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}
	data = new char[length+1];
	for (int i = 0; i < length; i++) {
		data[i] = str.data[i];
	}
	data[length] = '\0';
}
int String::strLength() {
	return length;
}

void String::clear() {

	data[0] = '\0';
}

bool String::empty() {
	if (data == nullptr) {
		return true;
	}
	return false;
}

int String::charAt(char c) {
//	int x = -1;
	for (int i = 0; i < length; i++) {
		if (data[i] == c) {
			return i;
		}
	}
	return -1;
}

void String::CompressString() {


		if (length <= 1) {
			return;  // No need to compress an empty or single-character string.
		}

		int compressed_length = 1; // Initialize with 1 for the first character.
		int i = 1;

		do {
			if (data[i] != data[i - 1]) {
				data[compressed_length] = data[i];
				compressed_length++;
			}
			i++;
		} while (i < length);

		data[compressed_length] = '\0'; // Terminate the compressed string.

		// Reallocate the memory for the compressed data.
		char* compressed_data = new char[compressed_length + 1];
		int x = 0;
		int j = 0;

		do {
			compressed_data[j] = data[j];
			j++;
		} while (j <= compressed_length);

		// Delete the old data and set the pointer to the compressed data.
		delete[] data;
		data = compressed_data;
		length = compressed_length;





	//int x = 0;
	//char* compress = new char[length];
	//int i = 0;
	//while (data[x] != '\0' && x<length-1) {
	//	char ch = data[x];
	//	compress[i] = ch;
	//	i++;
	//	if (x < length) {
	//		while (data[x] == data[x + 1]) {
	//			x++;
	//		}
	//	}
	//}
	//compress[i] = '\0';
	//
	//delete[] data;
	//data = nullptr;
	//i = 0;
	//while (compress[i] != '\0') {
	//	i++;
	//}

	//data = new char[i+1];
	//for (int j = 0; j < i+1; j++) {
	//	data[j] = compress[j];
	//}
	//data[i] = '\0';

	//delete[] compress;

}

void String::findMinStr(char* secretStr) {
	char* magicStr = data;
	int lengthsecret = 0;
	while (secretStr[lengthsecret] != '\0') {
		lengthsecret++;
	}
	bool flag = 0;
	int start = 0;
	int end = 0;
	int totchar=0;
	int x = 0;
	int y = 0;
	while (magicStr[x] != '\0') {
		if (magicStr[x] == secretStr[y]) {
			if (y == 0) {
				start = x;

			}
			totchar++;
			y++;
			if (y == lengthsecret) {
				flag = 1;
				end = x;
				break;
			}
		}
		x++;
	}
	if (magicStr[start] == magicStr[start + 1]) {
		start++;
	}

	if (flag) {
		for (int i = start; i <= end; i++) {
			cout << magicStr[i];
		}
	}
	else {
		cout << "Not Found" << endl;
	}
}

bool String::equalsIgnoreCase(char* str) {
	bool flag = 1;
	String temp(data);
	for (int i = 0; i < length; i++) {
		if (data[i] >= 'A' && data[i] <= 'Z') {
			temp.data[i] = data[i] + 32;
		}
		else {
			temp.data[i] = data[i];
		}
	}

	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
//	temp.display();
//	cout << str << endl;

	for (int i = 0; i < length; i++) {
		if (temp.data[i] != str[i]) {
			flag = 0;
		}
	}
	return flag;
}

char* String::substring(char* substr, int startIndex) {
	char temp[50];
	int x = startIndex;
	int y = 0;
	int start = 0;
	bool flag = 0;
	int lengthsubstr = 0;
	while (substr[lengthsubstr] != '\0') {
		lengthsubstr++;
	}
	while (data[x] != '\0') {
		if (data[x] == substr[y]) {
			if (y == 0) {
				start = x;
			}
			y++;
			if (y == lengthsubstr) {
				flag = 1;
			}
		}
		x++;
	}

	if (flag) {
		int a = 0;
		for (int i = start; i < length; i++) {
			temp[a++] = data[i];
		}
		temp[a] = '\0';
		return temp;
	}
	return nullptr;
}


char* String::substring(char* substr, int startIndex, int endIndex) {
	char temp[50];
	int x = startIndex;
	int y = 0;
	int start = 0;
	bool flag = 0;
	int lengthsubstr = 0;
	while (substr[lengthsubstr] != '\0') {
		lengthsubstr++;
	}
	while (data[x] != '\0') {
		if (data[x] == substr[y]) {
			if (y == 0) {
				start = x;
			}
			y++;
			if (y == lengthsubstr) {
				flag = 1;
			}
		}
		x++;
	}

	if (flag) {
		int a = 0;
		for (int i = start; i <= endIndex; i++) {
			temp[a++] = data[i];
		}
		temp[a] = '\0';
		return temp;
	}
	return nullptr;
}

int String::ColorChallange(char* hand) {
	char* board = data;
	int lengthHand = 0;
	while (hand[lengthHand] != '\0') {
		lengthHand++;
	}
	bool flag = 1;
	while (flag) {
		int i = 1;
		int count = 0;
		if (i == length - 1) {
			break;
		}
		for (i = 1; i < length; i++) {
			if (board[i] == board[i - 1]) {
				for (int j = 0; j < lengthHand; j++) {
					if (board[i] == hand[j]) {
						count++;
						hand[j] = 1;
						board[i] = 1;
						board[i - 1] = 1;
						for (int a = 0; a < length; a++) {
							for (int b = a+1; b < length; b++) {
								if (board[a] > board[b]) {
									char temp = board[a];
									board[a] = board[b];
									board[b] = temp;
								}
							}
						}
						bool flag2 = 1;
						for (int c = 0; c < length-1; c++) {
							if (board[c] != 1) {
								flag2 = 0;
							}
						}


						if (flag2) {
							flag = 0;
							return count;
						}
					}

				}
			}
		}
	}
		return -1;


}


void String::display() {
	cout << data << endl;
}

String::~String() {
	delete[] data;
	data = nullptr;
}