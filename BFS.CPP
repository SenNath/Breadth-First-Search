#include<iostream>

using namespace std;

struct edge
{
	int data;
	edge *next;
};
struct vertex
{
	int visit;
	char value;
	int index;
	int dist;
	edge *eptr;
};
struct queue
{
	int data;
	queue *next;
};
queue * ENQ(queue *q,int x)
{
	queue *nq;

/*Insertion at front*/

	nq = new queue;
	nq->data = x;
	nq->next = q;

	return(nq);

}
queue * DEQ(queue *q,int &x)
{
	x=-1;

/*Deletion at End*/

	if(q==NULL)
		return(q);

	queue *t,*p;

	t = q;
	p = NULL;

	while(t->next!=NULL)
	{
		p=t;
		t = t->next;
	}

	x = t->data;

	if(p==NULL)
		return(p);

	p->next = NULL;
	return(q);
}

void bfs(vertex *g,int st)
{
	queue *Q=NULL;
	edge *t;
	cout<<"\n\nBREADTH FIRST TRAVERSAL: \n\n\t";
	int p,x;
	p = st;

	g[p].visit = 1;
	cout<<g[p].value;
	g[p].dist = 0;
	Q = ENQ(Q,p);
	
	while(Q!=NULL)
	{
		Q = DEQ(Q,p);
		t = g[p].eptr;
		while(t!=NULL)
		{
			x = t->data;
			if(g[x].visit==0)
			{
				g[x].visit = 1;
				cout<<" --> "<<g[x].value;
				g[x].dist = g[p].dist + 1;
				Q = ENQ(Q,x);
			}
			t = t->next;
		}
	}
}

void display(vertex *g,int n)
{
	int i;
	edge *t;
	cout<<"\n\n\n\tNODE\tINDEX\tVISIT\tDIST\tEDGES";
	for(i=0;i<n;i++)
	{
		cout<<"\n\n\t"<<g[i].value;
		cout<<"\t"<<g[i].index;
		cout<<"\t"<<g[i].visit;
		cout<<"\t"<<g[i].dist;
		t = g[i].eptr;
		while(t!=NULL)
		{
			cout<<"\t"<<t->data;
			t = t->next;
		}
	}
}
int main()
{
	
	int n,p,i,m,j;

	cout<<"\nEnter No. of Vertices: ";
	cin>>n;

	vertex *g;
	g = new vertex[n];

	edge *nedge,*t;

	for(i=0;i<n;i++)
	{
		cout<<"\n\nNODE-"<<i+1<<": ";
		cout<<"\n\nValue: ";
		cin>>g[i].value;
		g[i].visit = 0;
		g[i].index = i;
		g[i].dist = -1;
		g[i].eptr = NULL;
		cout<<"No. of Adj. Nodes: ";
		cin>>m;
		for(j=0;j<m;j++)
		{
			cout<<"Node-"<<j+1<<": ";
			cin>>p;

			nedge = new edge;
			nedge->data = p;
			nedge->next = NULL;

			if(j==0)
				g[i].eptr = nedge;
			else
			{
				t = g[i].eptr;
				while(t->next!=NULL)
					t = t->next;
				t->next = nedge;
			}
		}
	}
	bfs(g,0);
	display(g,n);
}
