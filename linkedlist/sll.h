#ifndef SLL_H
#define SLL_H
#include<stdio.h>
typedef struct Node{
    int    data;
    struct Node *nextNode;
}Node;

enum result{
    RESULT_SUCCESS = 0,
    RESULT_FAILURE = 1,
    RESULT_MEMORY_ALLOCATION_FAILURE = 2,
};

enum {
    SLL_APPEND_NODE = -1,
    SLL_HEAD_NODE   = 0,
    SLL_TAIL_NODE   = 1,
};

Node* sll_insert_node(int index, int data, Node* head);
int   sll_search_data(int data, Node *head);
Node* sll_delete_node(int index, Node * head);
void  sll_print_sll(Node *head);
void  sll_find_middle_of_sll_1(Node *head);
void  sll_find_n_node_from_end(Node *head, int n);
void  sll_swap_two_nodes(Node *head, int x, int y);
Node* sll_delete_sll(Node *head);
#define SLL_DEBUG_PRINTF(str) printf("SLL_DEBUG_PRINTF: %s",str);
#endif
