#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int front = -1, rear = -1;

struct edgelist
{
    int destin;
    struct edgelist *edgeptr;
};

struct nodediv
{
    bool reach;
    int nodeno;
    char data;
    int dist;
    struct edgelist *listptr;
};

struct nodediv ynd[6];

/* QINSERT Function */

void QINSERT(int Q[], int index)
{
    if (rear == 5)
    {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear = rear + 1;
    Q[rear] = index;
}

/* QDELETE Function */

int QDELETE(int Q[])
{
    int index;

    if (front == -1 || front > rear)
    {
        return -1;
    }

    index = Q[front];
    front = front + 1;

    if (front > rear)
    {
        front = rear = -1;
    }

    return index;
}

/* EDGE_PTR Function */

struct edgelist *EDGE_PTR(int link)
{
    return ynd[link].listptr;
}

/* Insert Edge */

void INSERT_EDGE(int src, int dest)
{
    struct edgelist *newnode;

    newnode = (struct edgelist *)
              malloc(sizeof(struct edgelist));

    if (newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    newnode->destin = dest;
    newnode->edgeptr = ynd[src].listptr;
    ynd[src].listptr = newnode;
}

/* BFS Function */

void BFS(int Q[], int index)
{
    int link;
    struct edgelist *linkptr;

    ynd[index].reach = true;
    ynd[index].dist = 0;

    QINSERT(Q, index);

    while (front != -1)
    {
        index = QDELETE(Q);

        printf("%c ", ynd[index].data);

        linkptr = EDGE_PTR(index);

        while (linkptr != NULL)
        {
            link = linkptr->destin;

            if (ynd[link].reach == false)
            {
                ynd[link].dist = ynd[index].dist + 1;

                ynd[link].reach = true;

                QINSERT(Q, link);
            }

            linkptr = linkptr->edgeptr;
        }
    }
}

/* MAIN Function */

int main()
{
    int Q[6];
    int n, e;
    int src, dest;
    int index;

    printf("Enter Number Of Nodes (Maximum 6): ");
    scanf("%d", &n);

    if (n < 1 || n > 6)
    {
        printf("Invalid Number Of Nodes\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        ynd[i].nodeno = i;
        ynd[i].reach = false;
        ynd[i].dist = 0;
        ynd[i].listptr = NULL;

        printf("Enter Data For Node %d: ", i);
        scanf(" %c", &ynd[i].data);
    }

    printf("Enter Number Of Edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++)
    {
        printf("Enter Source And Destination: ");
        scanf("%d %d", &src, &dest);

        if (src < 0 || src >= n ||
            dest < 0 || dest >= n)
        {
            printf("Invalid Edge\n");
            i--;
            continue;
        }

        INSERT_EDGE(src, dest);
    }

    printf("Enter Starting Node Index: ");
    scanf("%d", &index);

    if (index < 0 || index >= n)
    {
        printf("Invalid Starting Node\n");
        return 0;
    }

    front = rear = -1;

    printf("\nBFS Traversal: ");

    BFS(Q, index);

    printf("\n");

    return 0;
}
