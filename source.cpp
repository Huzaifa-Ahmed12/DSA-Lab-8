#include<iostream>
using namespace std;
struct node {
	int info;
	node* next;
};
class CircularList {
private:
	node* last;
public:
	CircularList() {
		last = NULL;
	}
	void insertAtBeginning(int x) {
		node* newNode = new node;
		newNode->info = x;
		if (last == NULL) {
			last = newNode;
			last->next = last;
		}
		else {
			newNode->next = last->next;
			last->next = newNode;
		}
	}
	
	void insertInBetween(int value, int x) {
		if (last == NULL) {
			cout << "List is Empty!";
			return;
		}
		if (value == NULL) {
			cout << "Value not in list!!";
			return;
		}
		node* t = new node;
		t->info = x;
		node* p = last->next;
		do {
			if (p->info == value) {
				t->next = p->next;
				p->next = t;
				if (p == last) {
					last = t;
				}
				return;
			}p = p->next;
			
		} while (p != last->next);
	}
	void insertAtEnd(int val) {
		node* newNode = new node;
		newNode->info = val;
		if (last == NULL) {
			newNode->next = newNode;
			last = newNode;
		}
		else {
			newNode->next = last->next;
			last->next = newNode;
			last = newNode;
		}
	}
	void removeFirst() {
		if (last == NULL) {
			cout << "List is Empty";
			return;
		}
		node* temp = last->next;
		if (last == last->next) {
			temp = last;
			delete temp;
			last = NULL;
		}
		else {
			last->next = temp->next;
			delete temp;
		}
	}
	void removeLast() {
		if (last == NULL) {
			cout << "Empty Linked List: ";
			return;
		}
		if (last == last->next) {
			delete last;
			last = NULL;
		}
		node* temp = last->next;
		while (temp->next != last) {
			temp = temp->next;
		}
		temp->next = last->next;
		delete last;
		last = temp;
	}
	int removeLastWithValue() {
		if (last == NULL) {
			cout << "List is Empty!!";
			exit(0);
		}
		int x;
		if (last == last->next) {
			 x= last->info;
			delete last;
			last = NULL;
			return x;
		}
		node* temp = last->next;
		while (temp->next!=last) {
			temp = temp->next;
		}
		temp->next = last->next;
		x = last->info;
		delete last;
		last = temp;
		return x;

	}
	void removeLastWithGivenValue(int val) {
		if (last == NULL) {
			cout << "Empty Linked List!!";
			return;
		}
		node* curr = last->next;
		node* prev = last;
		do {
			if (curr->info == val) {
				if (curr == last && curr == last->next) {
					delete curr;
					last = NULL;
				}
				else if (curr == last) {
					prev->next = curr->next;
					delete curr;
					last = prev;
				}
				else {
					prev->next = curr->next;
					delete curr;
				}
				cout << "The dleeted node with value: " << val << endl;
			}
			prev = curr;
			curr = curr->next;
		} while (curr != last->next);
	}
	
	void display() {
		if (last == NULL) {
			cout << "List is Empty!!";
			return;
		}
		node* temp = last->next;
		do {
			cout << temp->info << " ";
			temp = temp->next;
		} while (temp != last->next);
		
	}
};
int main() {
	CircularList clist;
	clist.insertAtBeginning(3);
	clist.insertAtBeginning(4);
	clist.insertInBetween(3, 5);
	clist.insertInBetween(5, 7);
	clist.insertAtEnd(9);
	clist.insertInBetween(5, 6);
	clist.removeFirst();
	clist.removeLast();
	cout << "The last element is: " << clist.removeLastWithValue();
	cout << endl;
	/*clist.removeLastWithGivenValue(5);*/
	clist.display();

}