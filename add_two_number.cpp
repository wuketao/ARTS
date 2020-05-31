#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using std::string;
using std::reverse;
using std::cout;
using std::to_string;
using std::endl;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode *makeNextNode(ListNode *cur, int val1, int val2, int *pcarry)
	{
		int carry = *pcarry;
		int val = val1 + val2 + *pcarry;
		*pcarry = val / 10;	
		cur->next = new ListNode(val % 10);

		cout << __func__ << " val1=" << val1 << " val2=" << val2 << " value=" << cur->next->val << " carry=" << *pcarry << "<-" << carry<< endl;
		return cur->next;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *sum = new ListNode(); 
		ListNode *node = NULL;
		int carry;

		for (node = sum, carry = 0; 
				l1 && l2; 
				l1 = l1->next, l2 = l2->next) {
			node = makeNextNode(node, l1->val, l2->val, &carry);
		}

		cout << "======begin========" << endl;

		cout << "carry: " << carry << ", l1: " << endl;
		printList(l1);
		printList(sum);
		for (; l1; l1 = l1->next) 
			node = makeNextNode(node, l1->val, 0, &carry);


		cout << "carry: " << carry << ", l2: " << endl;
		printList(l2);
		printList(sum);
		for (; l2; l2 = l2->next)
			node = makeNextNode(node, 0, l2->val, &carry);


		cout << "carry: " << carry << endl;
		if (carry)
			node = makeNextNode(node, 0, 0, &carry);

		printList(sum);

		/* Delete dummy node in head */
		sum = pop_front(sum);

		printList(sum);
		
		cout << "======end========" << endl;


		return sum;
	}

	ListNode *pop_front(ListNode *lst)
	{
		ListNode *node = lst;
		lst = lst->next;
		delete node;

		return lst;
	}

	ListNode *make_list(const int *arr, int num)
	{
		ListNode *list = new ListNode();

		ListNode *node = list;
		for (int i = 0;  i < num; ++i) {
			node->next = new ListNode(arr[i]);
			node = node->next;
		}

		/* Delete dummy node in head */
		list = pop_front(list);

		return list;
	}

	void printList(const ListNode *list)
	{
		string s;

		if (list == nullptr) {
			cout << "empty list" << endl;
			return;
		}

		for (; list; list = list->next) {
			s += to_string(list->val);
			//cout << s << endl;
		}
		
		reverse(s.begin(), s.end());
		cout << std::setw(20) << s << endl;
	}

	bool is_equal_list(ListNode *l1, ListNode *l2)
	{
		return true;
	}

	void base_test(const int *arr1, int arr1_len, const int *arr2, int arr2_len)
	{
		ListNode *l1 = make_list(arr1, arr1_len);
		ListNode *l2 = make_list(arr2, arr2_len);
		ListNode *sum = addTwoNumbers(l1, l2);
		
		printList(l1);
		printList(l2);
		printList(sum);

		cout << "------" << endl;
	}

	void test_two_list_equal_length(void)
	{
		int arr1[15] = {9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 7, 9};
		int arr2[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 7, 9, 5};
		base_test(arr1, 15, arr2, 15);

		for (int i = 0; i < 15; ++i)
			arr1[i] = arr2[i] = 9;
		base_test(arr1, 14, arr2, 15);


		for (int i = 0; i < 15; ++i)
			arr1[i] = arr2[i] = 5;
		base_test(arr1, 14, arr2, 15);

	}
};

int main(void)
{
	class Solution add_two_numbers;

	add_two_numbers.test_two_list_equal_length();

	return 0;
}
