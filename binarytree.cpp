#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
	int info;
	struct node *r;
	struct node *l;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE a;
	a=new node;
	a->l=NULL;
	a->r=NULL;
	return a;
}
//Function to insert based on the given directions
NODE insert(NODE root)
{
	NODE a,k,x;
	int len,i,ele;
	char s[10];
	a=getnode();
	cout<<"ENter element\n";
	cin>>ele;
	a->info=ele;
	cout<<"enter directions(eg. LLR (caps) )\n";
	cin>>s;
	if(root==NULL)	
	{
		root=a;	//The new node is made the root if root is null regardless of directions
		cout<<"new node is the root\n";
		return root;
	}
	len=strlen(s);
	k=root;
	for(i=0;i<len-1;i++)
	{	
		toupper(s[i]);
		if(s[i]=='L')
		{
			if(k->l==NULL)
			{
				cout<<"Invalid directions\n";
				return root;
			}
			else
				k=k->l;
		}
		else if(s[i]=='R')
		{
			if(k->r==NULL)
			{
				cout<<"Invalid directions\n";
				return root;
			}
			else
				k=k->r;
		}
	}
	toupper(s[i]);
	if(s[i]=='L')
	{
		if(k->l==NULL)
			k->l=a;
		else
			cout<<"node already exists\n";
	}
	if(s[i]=='R')
	{
		if(k->r==NULL)
			k->r=a;
		else
			cout<<"node already exists\n";
	}
	return root;
}
//Function to insert node based on the level order
NODE insert1(NODE root)
{
	NODE a,t;
	int ele;
	a=getnode();
	cout<<"ENter element\n";
	cin>>ele;
	a->info=ele;
	if(root==NULL)
	{
		root=a;//The new node is made the root if root is null
		cout<<"new node is the root\n";
		return root;
	}	
	queue <NODE> q;
	//BFS is used for level order traversal
	q.push(root);
	while(!q.empty())
	{
		t=q.front();
		if(t->l==NULL)
		{
			t->l=a;
			return root;
		}
		else
			q.push(t->l);
		if(t->r==NULL)
		{
			t->r=a;
			return root;
		}
		else
			q.push(t->r);
		q.pop();
	}
}
//Function to delete the given node	  	
void delete1(NODE root,int ele)
{
	queue <NODE> q;
	NODE t,key,x;
	//BFS is used to search the given element in the tree in a level order manner
	q.push(root);
	while(!q.empty())
	{
		t=q.front();
		if(t->info==ele)
		key=t;
		if(t->l!=NULL)
		q.push(t->l);
		if(t->r!=NULL)
		q.push(t->r);
		q.pop();
	}
	key->info=t->info; //the element to be deleted is replaced with the bottom right most element  
	cout<<ele<<" is deleted\n"; 
	x=t;//x is the bottom right most element 
	//BFS is used to free up the space for the node
	q.push(root);
	while(!q.empty())
	{
		t=q.front();
		if(t->l==x)
		{
			delete(x);
			t->l=NULL;
			return;
		}
		else if(t->l!=NULL)
			q.push(t->l);
		if(t->r==x)
		{
			delete(x);
			t->r=NULL;
			return;
		}
		else if(t->r!=NULL)
			q.push(t->r);
		q.pop();
	}	
}  
//Function for the postorder traversal of the tree		
void postorder(NODE root)
{
	if(root==NULL)
	return;
	postorder(root->l);
	postorder(root->r);
	cout<<root->info<<endl;
}
//Function for the preorder traversal of the tree		
void preorder(NODE root)
{
	if(root==NULL)
	return;
	cout<<root->info<<endl;
	preorder(root->l);
	preorder(root->r);
	
}
//Function for the inorder traversal of the tree	
void inorder(NODE root)
{
	if(root==NULL)
	return;
	inorder(root->l);
	cout<<root->info<<endl;
	inorder(root->r);
	
}
int main()
{
	int n,ele;
	NODE root,k;
	root=NULL;
	for(;;)
	{
		cout<<"1.insertion using directions\n2.insertion according to the level order\n3.deletion of a node\n4.exit\n";
		cin>>n;
		switch(n)
		{
			case 1:root=insert(root);
				//traversals after the insertion
				cout<<"preorder\n";
				preorder(root);
				cout<<"inorder\n";
				inorder(root);
				cout<<"postorder\n";
				postorder(root);
				break;
			case 2:root=insert1(root);
				//traversals after the insertion
				cout<<"preorder\n";
				preorder(root);
				cout<<"inorder\n";
				inorder(root);
				cout<<"postorder\n";
				postorder(root);
				break;		
			case 3:cout<<"Enter no to be deleted\n";
				cin>>ele;	
				delete1(root,ele);
				break;
			case 4:exit(0);
			
		}		
	}			
	return 0;
}						
