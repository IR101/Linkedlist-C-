#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node* head = NULL;

	void insert_at_start(int v) {
		if (head == NULL) {
			node* temp = new node;
			temp->data = v;
			temp->next = NULL;
			head = temp;
		}
		else {
			node* temp = head;
			node* n = new node;
			n->data = v;
			n->next = temp;
			head = n;
		}
	}
	void insert_at_end(int v) {
		if (head == NULL) {
			node* temp = new node;
			temp->data = v;
			temp->next = NULL;
			head = temp;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			node* n = new node;
			n->data = v;
			n->next = NULL;
			temp->next = n;

		}
	}
	void insert_at_position(int v, int p) {
		if (head == NULL) {
			node* temp = new node;
			temp->data = v;
			temp->next = NULL;
			head = temp;
		}
		int m = 0;
		node* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			m++;
		}
		if (p > m || p < 0) {
			cout << "Position Invalid \n";
		}
		else if (p == 0) {
			insert_at_start(v);
		}
		else {
			node* temp = head;
			while (p>1) {
				temp = temp->next;
				p--;
			}
			node* n = new node;
			n->data = v;
			n->next = temp->next;
			temp->next = n;
		}
	}
	void display() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "-->";
			temp = temp->next;
		}
		if (temp == NULL) {
			cout << "NULL";
		}
		cout << endl;
	}
	void delete_at_start() {
		if (head == NULL) {
			return;
		}
		else {
			node* temp = head;
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
	void delete_at_end() {
		if (head->next == NULL) {
			delete head;
			head = NULL;
		}
		else {
			node* temp = head;
			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
	}
	void delete_at_position(int p) {
		node* temp = head;
		int m = 0;
		while (temp != NULL) {
			temp = temp->next;
			m++;
		}
		if (p == 0) {
			delete_at_start();
		}
		else if (p > m) {
			cout << "Invalid Position \n";
		}
		else {
			node* temp = head;
			while (p > 1) {
				temp = temp->next;
				p--;
			}
			node* n = temp;
			n = temp->next->next;
			delete temp->next;
			temp->next = n;
		}
	}
};
int main()
{
	node q;
	bool flag = true;
	int op = 0;
	cout << "1. Insert at start \n";
	cout << "2. Insert at end \n";
	cout << "3. Insert at specific position \n";
	cout << "4. Delete at start \n";
	cout << "5. Delete at end \n";
	cout << "6. Delete at position \n";
	while (flag) {
		cout << "Choose Option: ";
		cin >> op;
		if (op == 1) {
			int num;
			cout << "Enter number: ";
			cin >> num;
			q.insert_at_start(num);
			q.display();
		}
		else if (op == 2) {
			int num;
			cout << "Enter Number: ";
			cin >> num;
			q.insert_at_end(num);
			q.display();
		}
		else if (op == 3) {
			int num, pos;
			cout << "Enter Number: ";
			cin >> num;
			cout << endl;
			cout << "Enter Position: ";
			cin >> pos;
			q.insert_at_position(num, pos);
			q.display();
		}
		else if (op == 4) {
			q.delete_at_start();
			q.display();
		}
		else if (op == 5) {
			q.delete_at_end();
			q.display();
		}
		else if (op == 6) {
			int num;
			cout << "Enter Position: ";
			cin >> num;
			q.delete_at_position(num);
			q.display();
		}
		else {
			flag = false;
		}
	}
	return 0;
}