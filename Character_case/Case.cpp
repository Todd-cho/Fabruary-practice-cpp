#include <iostream>

using namespace std;

int distinguishCase(char* word) {
	while (1) {
		bool camel = false; // 케이스 확인 변수
		bool pascal = false;
		bool snake = false;
		bool kebab = false;

		if (word[0] >= 65 && word[0] <= 90) { //맨 처음 단어가 대문자인지 확인
			int i = 1;
			while (word[i] != '\0') {

				if (word[i] == '_') {
					snake = true;
					break;
				}
				else if (word[i] == '-') {
					kebab = true;
					break;
				}
				i++;
			}
			if (snake || kebab) pascal = false;
			else pascal = true;
		}

		else if (word[0] >= 97 && word[0] <= 122) { //맨 처음 문자가 소문자이면 
			int i = 1;
			while (word[i] != '\0') {
				if (word[i] == '_') {
					snake = true;
					break;
				}
				else if (word[i] == '-') {
					kebab = true;
					break;
				}
				i++;
			}
			if (snake || kebab) camel = false;
			else camel = true;
		}
		else return 5;

		if (camel) return 1;
		else if (pascal) return 2;
		else if (snake) return 3;
		else if (kebab) return 4;
	}

}
int Change(int cur,int num,char* word) { // 1 camel   2 pascal  3 snake  4 kebab
	char temp[50] = { '0', }; // 임시 저장 배열

 /////////////////////// camel -> other ///////////////////////
	if (cur == 1) { 
		if (num == 2) {
			word[0] = word[0] - 32;
			return 0;
		}
		else if (num == 3) { //소문자 밖에 없는데 snake or kebab으로 바꾸려 하면 오류
			int i = 0;
			int j = 0;
			int count = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] >= 65 && word[j] <= 90) {
					temp[i] = '_';
					temp[i + 1] = word[j] + 32;
					i += 2;
					j++;
					count++; //소문자 밖에 없으면 count 가 증가 하지 않음
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') break;
				word[i] = temp[i];
			}
			if (count == 0) return 1;
			return 0;
		}
		else { // case 4
			int i = 0;
			int j = 0;
			int count = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] >= 65 && word[j] <= 90) {
					temp[i] = '-';
					temp[i + 1] = word[j] + 32;
					i += 2;
					j++;
					count++;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') break;
				word[i] = temp[i];
			}
			if (count == 0) return 1;
			return 0;
		}
	}

////////////////////////////// pascal -> other//////////////////////////
	if (cur == 2) { 
		if (num == 1) {
			word[0] = word[0] + 32;
			return 0;
		}
		else if (num == 3) {
			word[0] += 32;
			int i = 0;
			int j = 0;
			int count = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] >= 65 && word[j] <= 90) {
					temp[i] = '_';
					temp[i + 1] = word[j] + 32;
					i += 2;
					j++;
					count++;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') break;
				word[i] = temp[i];
			}
			if (count == 0) return 1;
			return 0;
		}
		else { // case 4
			word[0] += 32;
			int i = 0;
			int j = 0;
			int count = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] >= 65 && word[j] <= 90) {
					temp[i] = '-';
					temp[i + 1] = word[j] + 32;
					i += 2;
					j++;
					count++;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') break;
				word[i] = temp[i];
			}
			if (count == 0) return 1;
			return 0;
		}
	}
	///////////////////////// snake -> other /////////////////////
	if (cur == 3) { 
		if (num == 1) {
			int i = 0;
			int j = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] == '_') {
					temp[i] = word[j + 1] - 32;
					i++;
					j += 2;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') {
					word[i] = temp[i];
					break;
				}
				word[i] = temp[i];
			}
			return 0;
		}
		else if (num == 2) {
			word[0] -= 32;
			int i = 0;
			int j = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] == '_') {
					temp[i] = word[j + 1] - 32;
					i++;
					j += 2;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') {
					word[i] = temp[i];
					break;
				}
				word[i] = temp[i];
			}
			return 0;
		}
		else { // case 4
			int i = 0;
			int j = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] == '_') {
					temp[i] = '-';
					i++;
					j++;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') break;
				word[i] = temp[i];
			}
			return 0;
		}
	}
	
	//////////////////////// kebab -> other ///////////////////////
	if (cur == 4) { 
		if (num == 1) {
			int i = 0;
			int j = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] == '-') {
					temp[i] = word[j + 1] - 32;
					i++;
					j += 2;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') {
					word[i] = temp[i];
					break;
				}
				word[i] = temp[i];
			}
			return 0;
		}
		else if (num == 2) {
			word[0] -= 32;
			int i = 0;
			int j = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] == '-') {
					temp[i] = word[j + 1] - 32;
					i++;
					j += 2;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') {
					word[i] = temp[i];
					break;
				}
				word[i] = temp[i];
			}
			return 0;
		}
		else { // case 3
			int i = 0;
			int j = 0;
			while (1)
			{
				if (word[j] == '\0') break;
				else if (word[j] == '-') {
					temp[i] = '_';
					i++;
					j++;
				}
				else {
					temp[i] = word[j];
					i++;
					j++;
				}
			}
			for (int i = 0; i < 50; i++) {
				if (temp[i] == '\0') break;
				word[i] = temp[i];
			}
			return 0;
		}
	}
}

int main() {
	int num;
	int Case = 0;
	int changeNum = 0;
	char word[50] = { '0', };
	while (1) {
		cout << "Check my word case: ";
		cin >> word;
		Case = distinguishCase(word);
		switch(Case){
			case 1: 
				cout << "camelCase" << endl << endl;
				break;
			case 2: 
				cout << "PascalCase" << endl << endl;
				break;
			case 3: 
				cout << "snake_case" << endl << endl;
				break;
			case 4: 
				cout << "kebab-case" << endl << endl;
				break;
			default: 
				cout << "No such case" << endl << endl;
				break;
		}
		if (Case == 5) continue;
		cout << "Want to Change(1) or Not(2). Please Enter the number: ";
		cin >> num;

		if (num == 1) {
			char mode[10] = { '0', };
			cout << "What do you want to change? Please write the case name: ";
			cin >> mode;

			if (mode[0] == 'c' || mode[0] == 'C') {
				if (Case == 1) {
					cout << "It's already camelCase" << endl << endl;
				}
				else {
					if(Change(Case, 1, word) == 0)
					{
						for (int i = 0; i < 50; i++) {
							cout << word[i];
							if (word[i] == '\0') {
								cout << endl << endl;
								break;
							}
						}
					}
					else {
						cout << "It can't change!" << endl << endl;
						continue;
					}
				}
			}
			else if (mode[0] == 'p' || mode[0] == 'P') {
				if (Case == 2) {
					cout << "It's already PascalCase" << endl << endl;
				}
				else {
					if (Change(Case, 2, word) == 0)
					{
						for (int i = 0; i < 50; i++) {
							cout << word[i];
							if (word[i] == '\0') {
								cout << endl << endl;
								break;
							}
						}
					}
					else {
						cout << "It can't change!" << endl << endl;
						continue;
					}
				}
			}
			else if (mode[0] == 's' || mode[0] == 'S') {
				if (Case == 3) {
					cout << "It's already snakeCase" << endl << endl;
				}
				else {
					if (Change(Case, 3, word) == 0)
					{
						for (int i = 0; i < 50; i++) {
							cout << word[i];
							if (word[i] == '\0') {
								cout << endl << endl;
								break;
							}
						}
					}
					else {
						cout << "It can't change!" << endl << endl;
						continue;
					}
				}
			}
			else if (mode[0] == 'k' || mode[0] == 'K') {
				if (Case == 4) {
					cout << "It's already kebabCase" << endl << endl;
				}
				else {
					if (Change(Case, 4, word) == 0)
					{
						for (int i = 0; i < 50; i++) {
							cout << word[i];
							if (word[i] == '\0') {
								cout << endl << endl;
								break;
							}
						}
					}
					else {
						cout << "It can't change!" << endl << endl;
						continue;
					}
				}
			}
			else {
				cout << "Please enter the right number" << endl << endl;
			}
		}
		else if (num == 2) continue;
		else cout << "Please enter the right number" << endl << endl;
	}	
}