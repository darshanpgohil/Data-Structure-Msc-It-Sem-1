#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/* EDGE_PTR Function */

struct edgelist *EDGE_PTR(int link)
{
    return ynd[link].listptr;
}

/* DFS Function */

void DFS(int index)
{
    int link;
    struct edgelist *linkptr;

    ynd[index].reach = true;

    printf("%c ", ynd[index].data);

    linkptr = EDGE_PTR(index);

    while (linkptr != NULL)
    {
        link = linkptr->destin;

        if (ynd[link].reach == false)
        {
            DFS(link);
        }

        linkptr = linkptr->edgeptr;
    }
}

/* MAIN Function */

int main()
{
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

    printf("\nDFS Traversal: ");

    DFS(index);

    printf("\n");

    return 0;
}
