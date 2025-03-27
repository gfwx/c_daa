#include <stdio.h>
#include <stdlib.h>

struct Node {
        struct Node * next;
        int data;
};

struct Stack {
        struct Node *tos;
};

struct Node * create_node(int data) {
        struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
}

void push(struct Stack * st, int data) {
        struct Node * tmp = st->tos;
        struct Node *res = create_node(data);
        if (st->tos == NULL) {
                st->tos = res;
                return;
        }

        st->tos = res;
        res->next = tmp;
}

int isEmpty(struct Stack *st) {
        if (st->tos == NULL) return 1;
        return 0;
}

struct Stack * create_stack() {
        struct Stack * st = (struct Stack * ) malloc(sizeof(struct Stack));
        st->tos = NULL;
        return st;
}


int pop(struct Stack * st) {
        if (st->tos == NULL) {
                printf("Empty Stack!\n");
                return -1;
        }

        struct Node *tmp = st->tos;
        int data = tmp->data;
        st->tos = st->tos->next;
        free(tmp);

        return data;
}

void traverse(struct Stack *st) {
        struct Node *tmp = st->tos;
        while (tmp != NULL) {
                printf("%d ", tmp->data);
                tmp = tmp->next;
        }
        printf("\n");
}

void display_arr(int arr[], int n) {
        for (int i = 0; i < n; ++i) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

void dfs(int n, int initialState, int mat[n][n]) {
        if (initialState < 0 || initialState >= n) {
                printf("Initial State out of bounds!\n");
                return;
        }
        struct Stack * st = create_stack();
        int visited[n];
        for (int i = 0; i < n; ++i) {
                visited[i] = 0;
        }

        push(st, initialState);

        while (!isEmpty(st)) {
                int tmp = pop(st);
                if (visited[tmp] == 0) {
                        visited[tmp] = 1;
                        for (int i = 0; i < n; ++i) {
                                if (mat[tmp][i] == 1 && visited[i] == 0) {
                                        push(st, i);
                                }
                        }
                        printf("%d ", tmp);
                }
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
        printf("DFS Traversal: \n");
        dfs(n, 0, mat);
}