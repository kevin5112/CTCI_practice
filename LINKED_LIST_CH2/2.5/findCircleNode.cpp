#include <iostream>
#include <unordered_set>
using namespace std;

struct node {
	int val;
	node* next;
	node(int v) : val(v), next(nullptr) {}
};

void printList(node* head){
	node* tracker = head;
	for(int i = 0; i < 20; ++i) {
		cout << tracker->val << ((i == 19) ? "\n" : " -> ");
		tracker = tracker->next;
	}
}

node* findCycleNode(node* head) {
	unordered_set<node*> s;
	node* tracker = head;
	while(s.find(tracker) == s.end()) {
		s.insert(tracker);
		tracker = tracker->next;
	}
	return tracker;
}

int main()
{
	node* head = new node(1);
	node* tracker = head;
	for(int i = 2; i < 10; ++i)
	{	
		node* newNode = new node(i);
		tracker->next = newNode;
		tracker = tracker->next;
	}
	node* cycleNode = head->next;
	tracker->next = cycleNode;
	cout << tracker->next->val << endl;
	printList(head);

	node* foo = findCycleNode(head);
	cout << foo->val << endl;

	return 0;
}


