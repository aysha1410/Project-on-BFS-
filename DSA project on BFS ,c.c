#include <stdio.h>
#include <string.h>

#define MAX_FRIENDS 100
#define MAX_NAME_LENGTH 50

int visited[MAX_FRIENDS];
int distance[MAX_FRIENDS];
int total;

void BFS(int start, int graph[][MAX_FRIENDS], char names[][MAX_NAME_LENGTH]) {
    int queue[MAX_FRIENDS];
    int front = 0, rear = 0;

    queue[rear] = start;
    rear=rear + 1;
    visited[start] = 1;
    distance[start] = 0;

    printf("Friend\t\tDistance\n");

    while (front != rear) {
        int vertex;
        vertex = queue[front];
        front=front+1;

        printf("%s\t\t%d\n", names[vertex], distance[vertex]);

        for (int j = 0; j < total; j++) {
            if (!visited[j] && graph[vertex][j] == 1) {
                queue[rear] = j;
                rear=rear+1;
                visited[j] = 1;
                distance[j] = distance[vertex] + 1;
            }
        }
    }
}

int main() {
    printf("Enter the total number of friends: ");
    scanf("%d", &total);

    char names[MAX_FRIENDS][MAX_NAME_LENGTH];
    int graph[MAX_FRIENDS][MAX_FRIENDS];

    for (int i = 0; i <total; i++) {
        printf("Enter name of friend %d: ", i+1);
        scanf("%s",&names[i]);
    }

    printf("Enter connections as adjacency matrix:\n");
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < total; i++) {
        visited[i] = 0;
        distance[i] = -1;
    }

    printf("\nDistance from the Source :\n");
    BFS(0, graph, names);

    return 0;
}
