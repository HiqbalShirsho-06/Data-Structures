#include<bits/stdc++.h>
#include<queue>
#include<stack>

#define VERTEXCOUNT 10
using namespace std;

int graph[VERTEXCOUNT][VERTEXCOUNT],indegrees[VERTEXCOUNT];
queue<int> Q[VERTEXCOUNT];
queue<int> S;
stack<int> temp;

int main(){

    int nodeCount,edges,row,col,weight;
    printf("Enter vertex count: ");
    scanf("%d",&nodeCount);
    printf("\n\nEnter Edges count: ");
    scanf("%d",&edges);

    #ifdef VERTEXCOUNT
        #define VERTEXCOUNT nodeCount
    #endif

    for(int i = 0 ; i < edges ; i++){
        printf("\nFrom and To respectively: ");
        scanf("%d%d",&row,&col);
        graph[row][col] = 1;
        Q[col].push(row);
    }

    int graphT[VERTEXCOUNT][VERTEXCOUNT];

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
            for(int k = 0 ; k < VERTEXCOUNT ; k++){
                    graphT[k][i] = graph[i][k];
            }
    }

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
            for(int k = 0 ; k < VERTEXCOUNT ; k++){
                indegrees[i] += graphT[i][k];
            }
            printf("\n");
    }

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
            printf("\n\t");
            for(int k = 0 ; k < VERTEXCOUNT ; k++){
                printf("%-4d",graph[i][k]);
            }
            printf("\n");
    }
    printf("\n\n");

    for(int i = 0 ; i < VERTEXCOUNT ; i++){
        printf("%d ",indegrees[i]);
    }
    printf("\n");
    for(int i = 0 ; i < VERTEXCOUNT ; i++){
        while(!Q[i].empty()){
            printf("%d ",Q[i].front());
            temp.push(Q[i].front());
            Q[i].pop();
        }
        printf("\n");
        while(!temp.empty()){
            Q[i].push(temp.top());
            temp.pop();
        }
    }


    printf("\n\n\n");

    for(int i = 0 ; i< VERTEXCOUNT ; i++){
        if(indegrees[i] == 0){
            indegrees[i] = -1;
            S.push(i);
            for(int j = 0 ; j < VERTEXCOUNT ; j++){
                while(!Q[j].empty()){
                    if(i == Q[j].front())
                        indegrees[j]--;
                    temp.push(Q[j].front());
                    Q[j].pop();
                }
                while(!temp.empty()){
                    Q[j].push(temp.top());
                    temp.pop();
                }
            }
            i = 0;
        }
        for(int i = 0 ; i < VERTEXCOUNT ; i++){
            printf("%d ",indegrees[i]);
        }
    }
    printf("\n\n\n");

    while(!S.empty()){
        printf("%d\t",S.front());
        S.pop();
    }
	return 0;
}
