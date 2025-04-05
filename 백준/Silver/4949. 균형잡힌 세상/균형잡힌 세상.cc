#include<iostream>
#include<string>
using namespace std;

struct stackNode {
	char item;
	struct stackNode* link;
};
stackNode* top = NULL;


void push(char a) {
	stackNode* temp = new stackNode();
	temp->item = a;
	temp->link = top;
	top = temp;
}

void pop() {
	if (top == NULL)
		return;

	else {
		top = top->link;
	}
}

int main() {
	string s;
	bool exitsentence = 0;
	while (true) {
		getline(cin, s, '.');
		s = s + '.';

		if (s == ".")
			break;
		else {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '(' || s[i] == '[') {
					push(s[i]);
				}
				else if (s[i] == ')') {
					if (top != NULL && top->item == '(') {
						pop();
					}
					else {
						exitsentence = 1;
						break;
					}
				}
				else if (s[i] == ']') {
					if (top != NULL && top->item == '[') {
						pop();
					}
					else {
						exitsentence = 1;
						break;
					}
				}
			}
			if (top == NULL && exitsentence == 0)
				cout << "yes\n";
			else {
				cout << "no\n";
				while (top != NULL) {
					pop();
				}
				exitsentence = 0;
			}
			cin.ignore();

		}

		
	}

	
}