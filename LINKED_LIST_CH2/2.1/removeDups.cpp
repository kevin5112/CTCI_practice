#include <iostream>
#include <unordered_set>
using namespace std;

//*
// * Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 

void removeDups(ListNode* &head)
{
	unordered_set<int> mySet;
	ListNode* trailer = head;
	for(auto it = head; it != NULL; it = it->next) 
	{
		if(mySet.find(it->val) != mySet.end())
		{
			if(!it->next) 
			{
				trailer->next = NULL;
				// delete it;
				break;
			}
			trailer->next = it->next;
			// delete it;
			it = trailer;
		}
		else
		{
			mySet.insert(it->val);
			trailer = it;
		}
	}


}

int main()
{
	ListNode doo(5);
	ListNode* head = &doo;
	ListNode newNode(7);
	ListNode* temp = head;
	temp->next = &newNode;
	temp = temp->next;
	ListNode foo(2);
	temp->next = &foo;
	temp = temp->next;
	ListNode poo(7);
	temp->next = &poo;
	temp = temp->next;
	ListNode shoe(2);
	temp->next = &shoe;
	temp = temp->next;

	for(ListNode* it = head; it != NULL; it = it->next)
	{
		cout << it->val << " -> ";
	}
	cout << "NULL\n";

	removeDups(head);

	for(ListNode* it = head; it != NULL; it = it->next)
	{
		cout << it->val << " -> ";
	}
	cout << "NULL\n";

	return 0;
}