#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
	string val;
	ListNode* next;
	ListNode(string x) : val(x), next(NULL) {} 

};

void push_back(string x, ListNode* &head)
{
	ListNode* newNode = new ListNode(x);
	if(!head)
	{
		head = newNode;
		return;
	}

	ListNode* tracker = head;

	while(tracker->next)
	{
		tracker = tracker->next;
	}

	tracker->next = newNode;
	return;
}

void print(ListNode* head)
{
	ListNode* tracker = head;

	cout << "printingList: ";

	while(tracker)
	{
		cout << tracker->val << ' ';
		tracker = tracker->next;
	}
	cout << endl;
}

void weaveList(ListNode* head)
{
	cout << "Weaving list...\n";
	ListNode* slow = head;
	ListNode* fast = head;

	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	fast = head;
	ListNode* tmpFast = fast->next;
	ListNode* tmpSlow = slow->next;
	ListNode* placeHolder = slow;

	// cout << placeHolder->val << endl;
	// cout << slow->val << endl;
	// cout << fast->val << endl;

	while(slow->next)
	{
		// cout << fast->val << endl;
		fast->next = slow;
		fast = tmpFast;
		tmpFast = tmpFast->next;
		slow->next = fast;
		slow = tmpSlow;
		tmpSlow = tmpSlow->next;
	}
	fast->next = slow;
}


int main()
{
	ListNode* head = NULL;

	push_back("a1", head);
	push_back("a2", head);
	push_back("a3", head);
	push_back("b1", head);
	push_back("b2", head);
	push_back("b3", head);

	print(head);

	weaveList(head);
	print(head);

	return 0;
}