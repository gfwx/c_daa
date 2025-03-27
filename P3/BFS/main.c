#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
        struct Node * next;
        int data;
};

struct Queue {
        struct Node * front;
        struct Node * rear;
        int size;
};

struct Node * create_node(int data) {
        struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
}

struct Queue *init_q() {
        struct Queue * res = (struct Queue *) malloc(sizeof(struct Queue));
        res->front = NULL;
        res->rear = res->front;
        res->size = 0;
        return res;
}

void enq(struct Queue * q, int data) {
        struct Node *tmp = q->rear;
        struct Node * new_node = create_node(data);

        if (q->front == NULL) {
                q->front = new_node;
                q->rear = new_node;
        }
        else {
                tmp->next = new_node;
                q->rear = new_node;
        }
        q->size++;
}

int deq(struct Queue *q) {
        if (q->front == NULL) {
                return -1;
        }

        struct Node *tmp = q->front;
        int data = tmp->data;

        q->size--;
        q->front = q->front->next;
        free(tmp);
        return data;
}

bool isEmpty(struct Queue *q) {
        return (q->size == 0);
}

void bfs(int n, int initialState, int mat[n][n]) {
        if (initialState < 0 || initialState >= n) {
                printf("Initial State out of bounds!\n");
                return;
        }
        struct Queue * q = init_q();
        int visited[n];
        for (int i = 0; i < n; ++i) {
                visited[i] = 0;
        }

        enq(q, initialState);

        while (!isEmpty(q)) {
                int tmp = deq(q);
                if (visited[tmp] == 1) continue;

                visited[tmp] = 1;
                for (int i = 0; i < n; ++i) {
                        if (mat[tmp][i] == 1 && visited[i] == 0) {
                                enq(q, i);
                        }
                }
                printf("%d ", tmp);
        }

        printf("\n");
}

int main() {
        int n;
        printf("Total number of vertices:\n");
        scanf("%d", &n);
        int mat[n][n];

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        mat[i][j] = 0;
                }
        }

        for (int i = 0; i < n; ++i) {
                int tmp;
                printf("Enter number of adjacent vertices for vertex %d:\n", i);
                scanf("%d", &tmp);

                printf("Enter vertices: \n");
                while (tmp--) {
                        int v;
                        scanf("%d", &v);
                        if (v < 0 || v >= n) {
                                printf("Out of range!\n");
                                ++tmp;
                        } else {
                                mat[i][v] = 1;
                                mat[v][i] = 1;
                        }
                }
        }

        printf("BFS Traversal: \n");
        bfs(n, 0, mat);
}