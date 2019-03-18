#include<bits/stdc++.h>
using namespace std;

// this is priority queue making 
struct Node{
	int data;
	Node *next;
};

struct Pq{
	Node *pq[32];
};

void Initialize(Pq *p){
	cout<<"in Inititalize\n";
	for(int i=0;i<32;i++){
		p->pq[i] = NULL;
	}
}

Node* makeNode(int data)
{
	Node *x = (Node*)malloc(sizeof(Node));
	x->data = data;
	x->next = NULL;
}

void insert(Pq *p , int data)
{
	//printf("in insert\n");
	int pri = data%32;
	Node *x;
	x = p->pq[pri];
	if(x==NULL){
		p->pq[pri] = makeNode(data);
	}else{
		while(x->next!=NULL){
			x = x->next;
		}
		x->next = makeNode(data);
	}
}

int Delete(Pq *p){
	Node *x,*prev;
	x = p->pq[0];
	int i=0;
	while(i<31)
	{
		if(x==NULL){
			i++;
			x = p->pq[i];
		}else{
			break;
		}
	}
	p->pq[i] = NULL;
	prev = x;
	while(x!=NULL){
		cout<<x->data<<" ";
		prev = x;
		x=x->next;
		free(prev);
	}
	if(i==31){
		return 0;
	}else{
		cout<<"\n";
		return 1;
	}
}

int main(int argc, char** argv) {
	int k,data;
	Pq p;
	Initialize(&p);
	int arr[] = {1,7,2,3,4,37,23,85,8,504,6784,940,345,5,39,541};
	for(int i=0;i<16;i++){
		insert(&p,arr[i]);
	}
	while(Delete(&p));
	return 0;
}

