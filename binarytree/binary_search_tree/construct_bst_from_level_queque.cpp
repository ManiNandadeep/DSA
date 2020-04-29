#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
	int data; 
	Node* right; 
	Node* left; 

	Node(int x) 
	{ 
		data = x; 
		right = NULL; 
		left = NULL; 
	} 
}; 
struct Details { 
	Node* ptr; 
	int min, max; 
}; 
void inorder(Node*root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* newNode(int data) 
{ 
	Node* tmp1 = new Node(data); 
	tmp1->left =tmp1->right = NULL; 
	return tmp1; 
} 
Node* constructBst(int arr[], int n) 
{ 
	if (n == 0) 
		return NULL; 
	Node* root; 
	queue<Details> q; 
	int i = 0; 
	Details tmp; 
	tmp.ptr = newNode(arr[i++]); 
	tmp.min = INT_MIN; 
	tmp.max = INT_MAX; 
	q.push(tmp); 
	root = tmp.ptr; 
	while (i != n) { 
		Details tmp1 = q.front(); 
		q.pop(); 
		if (i < n && (arr[i] < tmp1.ptr->data 
						&& arr[i] > tmp1.min)) { 
			tmp.ptr = newNode(arr[i++]); 
			tmp.min = tmp1.min; 
			tmp.max = tmp1.ptr->data; 
			q.push(tmp); 
			tmp1.ptr->left = tmp.ptr; 
		} 
		if (i < n && (arr[i] > tmp1.ptr->data 
						&& arr[i] < tmp1.max)) { 

			tmp.ptr = newNode(arr[i++]); 
			tmp.min = tmp1.ptr->data; 
			tmp.max = tmp1.max; 
			q.push(tmp); 
			tmp1.ptr->right = tmp.ptr; 
		} 
	} 
	return root; 
} 
int main() 
{ 
	int arr[] = {8,5,1,7,10,12}; 
    int n=sizeof(arr)/sizeof(arr[0]);
	Node* root = constructBst(arr, n); 
	inorder(root); 
	return 0; 
} 
