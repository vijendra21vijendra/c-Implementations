#include<bits/stdc++.h>
using namespace std;

struct tree{
	int data;
	struct tree *left,*right;
};

tree* makeTreeNode(int data){
	tree *x = (tree*)malloc(sizeof(tree));
	x->data = data;
	x->left = x->right = NULL;
}
// here is implementation of trees
// firstly i will make a bst
tree* insertNode(tree *root,int data){
	tree *prev,*temp;
	temp = root;
	tree *x = makeTreeNode(data);
	if(temp==NULL){
		root = x;
	}else{
		int done=0;
		while(!done)
		{
			if(temp->left!=NULL && x->data < temp->data){
				temp = temp->left;
			}else if(temp->right!=NULL && x->data>temp->data){
				temp = temp->right;
			}else if(x->data < temp->data){
				temp->left = x;
				done=1;
			}else if(x->data > temp->data){
				temp->right = x;
				done=1;
			}else{
				done=1;
				cout<<"duplicate\n";
			}
		}
	}
	return root;
}
tree* makeTree(int *arr,int size){
	
	int i=0;
	tree *root,*x,*temp;
	root = makeTreeNode(arr[0]);
    for(i=1;i<size;i++){
    	root = insertNode(root,arr[i]);
	}
	return root;
}

void inOrder(tree *root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

tree* search(tree *root,int data){
	
	    if(root!=NULL){
		if(data < root->data){
			return search(root->left,data);
		}else if(data > root->data){
			return search(root->right,data);
		}else{
		  return root;	
		}		
	}
	return root;
}
int countNode(tree *root)
{
	int ret_val=0;
	if(root==NULL)
	{
		ret_val = 0;
	}
	else
	{
		ret_val = 1+countNode(root->left)+countNode(root->right);
	}
	return ret_val;
}

int countLeaves(tree *root)
{
	if(root!=NULL)
	{
		if(root->left == NULL && root->right==NULL)
		{
			return 1;
		}
		return countLeaves(root->left) + countLeaves(root->right);
	}
	return 0;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int height(tree *root)
{
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		return 1+max(height(root->left),height(root->right));
	}
}
void mirrorImage(tree *root)
{
	tree *temp;
	if(root!=NULL)
	{
		if(root->left!=NULL || root->right!=NULL)
		{
			temp = root->left;
			root->left =root->right;
			root->right = temp;
			mirrorImage(root->left);
			mirrorImage(root->right);
		}
	}
}

void DeleteNode(tree **pptr)
{
	tree *temp,*p;
	p = *pptr;
	if(p->right==NULL)
	{
		*pptr = p->left;
		free(p);
	}
	else if(p->left==NULL)
	{
		*pptr = p->right;
		free(p);
	}
	else
	{
		for(temp = p->left;temp->right!=NULL;)
		{
			temp = temp->right;
		}
		temp->right = p->right;
		*pptr = p->left;
		free(p);
	}
}
void Delete(tree **root,int data)
{
	tree *p,*prev;
	prev = NULL;
	p = *root;
	while(p!=NULL && p->data!=data)
	{
		if(p->data>data)
		{
			prev = p;
			p = p->left;
		}
		else
		{
			prev = p;
			p = p->right;
		}
	}
	if(p==NULL)
	{
		cout<<"not found\n";
	}
	else
	{
		if(prev==NULL)
		{
			DeleteNode(root);
		}
		else
		{
			if(p==prev->left)
			{
				DeleteNode(&prev->left);
			}
			else
			{
				DeleteNode(&prev->right);
			}
		}
	}
}


int main()
{
	int size=10;
	int arr[size]={10,5,3,7,13,11,12,87,85,200};
	tree *root = makeTree(arr,size);
	inOrder(root);
	cout<<"\n\n";
	
	
	
	//search
//		int data = 13;
//	tree *p = search(root,data);
//	cout<<"\n\n";
//	cout<<p->left->data<<" "<<p->right->data<<" "<<p->data<<"\n";
//	data = 41;
//	cout<<"\n\n";
//	p = search(root,data);
//	cout<<p<<"\n";	
//	
//cout<<countNode(root)<<" are nodes in the tree\n";
//cout<<countLeaves(root)<<" are leaves in the tree\n";	
//cout<<height(root)<<" is height of tree\n";
//mirrorImage(root);
//cout<<" after mirror image :- ";
//inOrder(root);

int data = 20;
Delete(&root,data);
inOrder(root);
cout<<"\n";
data = 3;
Delete(&root,data);
inOrder(root);
cout<<"\n";
data = 87;
Delete(&root,data);
inOrder(root);
	return 0;
}
