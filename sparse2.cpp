#include<bits/stdc++.h>
using namespace std;
//linked representation

struct Node{
	int data;
	int row;
	int col;
	Node *down,*right;
};

Node* makeNode(int data,int row,int col){
  Node *x = (Node*)malloc(sizeof(Node));
  x->col = col;
  x->data = data;
  x->row=row;
  x->right = x->down = NULL;	
}
struct rows{
	Node* arr[10];
};

struct cols{
	Node *arr[10];
};

struct sparseMatrix{
	rows *ver;
	cols *hor;
};

void Initialize(sparseMatrix *mat)
{
	rows *x = (rows*)malloc(sizeof(rows));
	cols *y = (cols*)malloc(sizeof(cols));
	int i;
	for(i=0;i<10;i++)
	{
		x->arr[i] = y->arr[i] = NULL;
	}
	mat->hor = y;
	mat->ver = x;
}

void insert(sparseMatrix *mat,int data,int row,int col){
	
	Node *x,*y,*prevx,*prevy;
	x = mat->ver->arr[row];
	y = mat->hor->arr[col];
	Node *p = makeNode(data,row,col);
	if(x==NULL){
		mat->ver->arr[row] = p;
	}else{
		
	    prevx =mat->ver->arr[row] ;
	    while( x!=NULL &&x->col < col){
		prevx = x;
		x = x->right;
	   }
	   p->right  =x;
	   prevx->right = p;
	}
	
		if(y==NULL){
		mat->hor->arr[col] = p;
	}else{
	    prevy =mat->hor->arr[col];
	    while( y!=NULL &&y->row < row){
		prevy = y;
		y = y->down;
	   }
	   p->down = y;
	   prevy->down = p;
	}
}
int main()
{
	int m,n;
	int i,j;
	cout<<"enter n and m: ";
	cin>>n>>m;
	int arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	sparseMatrix mat;
	Initialize(&mat);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(arr[i][j]!=0){
			insert(&mat,arr[i][j],i,j);	
		}
		}
	}
	Node *p;
	for(i=0;i<n;i++)
	{
		p = mat.ver->arr[i];
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p = p->right;
		}
		cout<<"\n";
	}
	cout<<"\n";
	cout<<"\n";
	for(i=0;i<m;i++)
	{
		p = mat.hor->arr[i];
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p = p->down;
		}
		cout<<"\n";	
	}	
	return 0;
}
