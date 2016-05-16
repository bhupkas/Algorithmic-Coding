/*

bhupkas

Problem Link : https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

Problem Statement : Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/


using namespace std;

#include "bits/stdc++.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v) :	val(v), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v) : val(v), left(NULL) , right(NULL) {}
};

void printLinkedList(ListNode * head) {
  while(head != NULL) {
    cout << head -> val << " ";
    head = head -> next;
  }
  cout << endl;
}

ListNode * reverseLinkedList (ListNode * head) {
  if(head == NULL || head -> next == NULL)  return head;
  ListNode* first, *second, *temp;
  first = head;
  second = head -> next;
  while(second != NULL) {
    temp = second -> next;
    second -> next = first;
    first = second;
    second = temp;
  }
  head -> next = NULL;
  return first;
}

ListNode * pushFront(ListNode * head, int val) {
  ListNode * newNode = new ListNode(val);
  newNode -> next = head;
  return newNode;
}

ListNode * create() {
  int n;
  cin >> n;
  ListNode * head = NULL;
  for(int i = 0 ; i < n ; ++i) {
    int temp;
    cin >> temp;
    head = pushFront(head, temp);
  }
  head = reverseLinkedList(head);
  printLinkedList(head);
  return head;
}

TreeNode * recur(ListNode ** head , int l , int r)
{
    if(r < l)   return NULL;
    int mid = (l +r)/2;
    TreeNode * root;
    root = new TreeNode(0);
    root -> left = recur(head,l,mid-1);
    root -> val = (*head) -> val;
    (*head) = (*head) -> next;
    root -> right = recur(head,mid+1,r);
    return root;
}

TreeNode * getSol(ListNode * head) {
	int len = 0;
	TreeNode * root;
	if(head == NULL)	return root;
	ListNode * t = head;
	while(t != NULL) {
		t = t -> next;
		len ++;
	}
	return recur(&head , 0, len - 1);
}

void inOrder(TreeNode * root) {
	if(!root) return;
	inOrder(root -> left);
	cout << root -> val << " ";
	inOrder(root -> right);
}

int main() {
	ListNode * head = create();
	TreeNode * ans = getSol(head);
	inOrder(ans);
	cout << endl;
	return 0;
}