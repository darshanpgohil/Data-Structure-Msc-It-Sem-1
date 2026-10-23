#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

struct edgelist
{
	int destin;
	struct edgelist *edgeptr;
};

struct nodediv
{
	int reach;
	int nodeno;
	char data;
	int dist;
	struct edgelist *listptr;
};

struct nodediv ynd[6];

void Insert_Edge(int src,int dest)
{
	struct edgelist *newNode;

	newNode = (struct edgelist*)malloc(sizeof(struct edgelist));

	if(newNode == NULL)
	{
		cout<<"\n Memory Allocation Is Failed";
		exit(0);
	}

	newNode->destin = dest;
	newNode->edgeptr = ynd[src].listptr;
	ynd[src].listptr = newNode;
}

struct edgelist *EDGE_PTR(int link)
{
	      return ynd[link].listptr;
}

void DFS(int index)
{
      int link;
      struct edgelist *linkptr;

      ynd[index].reach = 1;

      cout<<ynd[index].data<<" ";

      linkptr = EDGE_PTR(index);

      while(linkptr != NULL)
      {
	     link = linkptr->destin;

	     if(ynd[link].reach == 0)
	     {
		  DFS(link);
	     }

	     linkptr = linkptr->edgeptr;
      }

}

void BFS(int start, int n)
{
	int queue[6];
	int front=0,rear=0;
	int index,link;
	struct edgelist *linkptr;

	for(index=0;index<n;index++)
	{
		ynd[index].reach = 0;
	}

	ynd[start].reach = 1;

	queue[rear++] = start;

	while(front < rear)
	{
		index = queue[front++];

		cout<<ynd[index].data<<" ";

		linkptr = EDGE_PTR(index);

		while(linkptr != NULL)
		{
			link = linkptr->destin;

			if(ynd[link].reach == 0)
			{
				ynd[link].reach = 1;
				queue[rear++] = link;
			}
			linkptr = linkptr->edgeptr;
		}
	}
}

void main()
{
	int n,e;

	int src,dest;
	int index,i;

	clrscr();

	cout<<"\n Enter The Maximum Node (6) : ";
	cin>>n;

	if(n<1 || n>6)
	{
		cout<<"\n Invalide Number Of Nodes";
		return;
	}

	for(i=0;i<n;i++)
	{
		ynd[i].nodeno = i;
		ynd[i].reach = 0;
		ynd[i].dist = 0;
		ynd[i].listptr = NULL;

		cout<<"\n Enter Data For Node "<<i<<" : ";
		cin>>ynd[i].data;
	}

	cout<<"\n Enter The No Of Edges : ";
	cin>>e;

	for(i=0;i<e;i++)
	{
		cout<<"\n Enter The Source and Destination : ";
		cin>>src>>dest;

		if(src<0 || src>=n || dest<0 || dest>=n)
		{
			cout<<"\n Invalide Edge";
			i--;
			continue;
		}

		Insert_Edge(src,dest);
	}

	cout<<"\n Enter The Starting Node Index : ";
	cin>>index;

	if(index < 0 || index >= n)
	{
		cout<<"\n Invalide Index";
		return;
	}

	cout<<"\n Dfs Traversal";
	DFS(index);

	cout<<"\n Bfs Traversal";
	BFS(index,n);

	getch();
}
