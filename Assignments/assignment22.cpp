#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *adj[20];
int vertex[20];
int visited[20];

void create();
int findVertex(int);
void Bfs(int);
void dfs(int);
void startDfs();
void display();

int n;

int main()
{
    int ch,start;

    do 
    {
        cout<<"\n 1. Create Graph \n 2. Bfs \n 3. Dfs \n 4. Display \n 5. Exit \n ";

        cout<<"\n Enter The Ch : ";
        cin>>ch;

        switch(ch)
        {
            case 1: create();
                    break;

            case 2: cout<<"\n Enter The Start : ";
                    cin>>start;

                    int index;
                    index = findVertex(start);

                    if(index == -1)
                        cout<<"\n Invalid Vertex \n";
                    else
                        Bfs(index);
                    break;

            case 3: startDfs();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);
                    break;

            default: cout<<"\n Wrong Choice";
        }
    }while(ch != 5);
}

int findVertex(int value)
{
    for(int i=0;i<n;i++)
    {
        if(vertex[i] == value)
        {
            return i;
        }
    }

    return -1;
}

void create()
{
    int edge,u,v;

    cout<<"\n Enter The N : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"\n Enter The Vertex Value : ";
        cin>>vertex[i];

        adj[i] = NULL;
    }

    cout<<"Enter The Edges : ";
    cin>>edge;

    for(int i=0;i<edge;i++)
    {
        cout<<"\n Enter The U & V (Source To Destination) : ";
        cin>>u>>v;

        int a = findVertex(u);
        int b = findVertex(v);

        if(a==-1 || b==-1)
        {
            cout<<"\n Invalid Vetex"<<endl;
            i--;
            continue;
        }

        struct node *newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = b;
        newNode->next = adj[a];
        adj[a] = newNode;

        struct node *newNode2 = (struct node*)malloc(sizeof(struct node));

        newNode2->data = a;
        newNode2->next = adj[b];
        adj[b] = newNode2;
    }

    cout<<"\n Graph Created Successfully"<<endl;
}

void Bfs(int start)
{
    queue<int> q;

    for(int i=0;i<n;i++)
    {
        visited[i] = 0;       
    }

    visited[start] = 1;

    q.push(start);

    while(!q.empty())
    {
        int v = q.front();

        q.pop();

        cout<<vertex[v]<<" ";

        struct node *temp = adj[v];

        while(temp != NULL)
        {
            int x = temp->data;

            if(visited[x] == 0)
            {
                visited[x] = 1;
                q.push(x);
            }

            temp = temp->next;
        }
    }

    cout<<endl;
}

void dfs(int v)
{
    visited[v] = 1;
    cout<<vertex[v]<<" ";
    struct node *temp = adj[v];

    while(temp != NULL)
    {
        int x = temp->data;

        if(visited[x] == 0)
        {
            dfs(x);
        }

        temp = temp->next;
    }
}

void startDfs()
{
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }

    int start;

    cout<<"\n Enter The Starting Vertex : ";
    cin>>start;

    int index = findVertex(start);

    if(index == -1)
    {
        cout<<"\n Invalid Vertex";
        return;
    }

    cout<<"\n Dfs : \n";

    dfs(index);

    cout<<endl;
}

void display()
{
    for(int i=0;i<n;i++)
    {
        cout<<vertex[i]<<" -> ";

        struct node *temp = adj[i];

        while(temp != NULL)
        {
            cout<<vertex[temp->data]<<" -> ";
            temp = temp->next;
        }

        cout<<" NULL "<<endl;
    }
}