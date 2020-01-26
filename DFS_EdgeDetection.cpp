#include<bits/stdc++.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define VERTEXCOUNT 100
#define EDGECOUNT 100

struct Edge{
    int from;
    int to;
    char type;
}edges[EDGECOUNT];

struct Vertex{
    int data;
    int disTime;
    int finTime;
    int color;
}verts[VERTEXCOUNT], graph[VERTEXCOUNT][VERTEXCOUNT], graphT[VERTEXCOUNT][VERTEXCOUNT];

static int timee = 0,itr = 0;


void DFS_visit(int u){
    timee++;
    verts[u].disTime = timee;
    verts[u].color = GRAY;

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
        if(graph[u][i].data == 1){
            if(verts[i].color == WHITE){
                edges[itr].from = u;
                edges[itr].to = i;
                edges[itr].type = 'T';
                itr++;
                DFS_visit(i);
            }
            else if(verts[i].color == GRAY){
                edges[itr].from = u;
                edges[itr].to = i;
                edges[itr].type = 'B';
                itr++;
            }
            else if(verts[i].color == BLACK){
                if(verts[u].disTime > verts[i].disTime){
                    edges[itr].from = u;
                    edges[itr].to = i;
                    edges[itr].type = 'C';
                    itr++;
                }
                else{
                    edges[itr].from = u;
                    edges[itr].to = i;
                    edges[itr].type = 'F';
                    itr++;
                }
            }
        }
    }

    timee++;
    verts[u].finTime = timee;
    verts[u].color = BLACK;
}

void DFS(){
    for(int i = 0 ; i < VERTEXCOUNT ; i++){
        verts[i].color = WHITE;
    }

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
        if(verts[i].color == WHITE)
            DFS_visit(i);
    }
}

int main(){

    int v, e,row,col;
    printf("Enter number of vertex: ");
    scanf("%d",&v);

    printf("Enter number of edges: ");
    scanf("%d",&e);

    #ifdef VERTEXCOUNT
        #define VERTEXCOUNT v
    #endif // VERTEXCOUNT
    #ifdef EDGECOUNT
        #define EDGECOUNT e
    #endif // EDGECOUNT

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
        for(int j = 0 ; j < VERTEXCOUNT ; j++){
            graph[i][j].data = 0;
        }
    }

    for( int i = 0 ; i < EDGECOUNT ; i++){
        printf("Enter from-to respectively: ");
        fflush(stdin);
        scanf("%d%d",&row,&col);
        graph[row][col].data = 1;
    }

    printf("\n\n\n");

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
        for(int j = 0 ; j < VERTEXCOUNT ; j++){
            printf("%-4d",graph[i][j].data);
        }
        printf("\n\n");
    }
    DFS();

    for(int i = 0 ; i < EDGECOUNT ; i++){
        printf("%d %d %c\t",edges[i].from,edges[i].to,edges[i].type);
    }
    return 0;
}
