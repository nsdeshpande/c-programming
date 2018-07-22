#include<stdio.h>
#include"sll.h"
#include"utils.h"

int main(void){

    Node *head = NULL;
    int data = -1;
    int userOption = 1;
    int sll_node_search_index = -2;
    int index = -1;
    do{
        userOption = getUserInput();
        switch(userOption){
            case OPTION_APPEND_NODE_SLL:
                printf("\nSLL_USER_INPUT: Enter node data.");
                scanf("%d",&data);
                head = sll_insert_node(SLL_APPEND_NODE, data,head);
            break;
            case OPTION_PRINT_SLL:
                sll_print_sll(head);
            break;
            case OPTION_SEARCH_NODE_SLL:
                printf("\nSLL_USER_INPUT: Enter data to search.");
                scanf("%d",&data);
                sll_node_search_index = sll_search_data(data,head);
                printf("\nSLL_USER_OUTPUT: element foudn at index(%d)",sll_node_search_index);
            break;
            case OPTION_INSERT_NODE_SLL:
                printf("\nSLL_USER_INPUT: Enter node data and index.");
                scanf("%d %d",&data,&index);
                head = sll_insert_node(index, data,head);
            break;
            case OPTION_DELETE_INDEX_NODE_SLL:
                printf("\nSLL_USER_INPUT: Enter index to delete.");
                scanf("%d",&index);
                head = sll_delete_node(index,head);
            break;
        }
    }while(userOption!=OPTION_EXIT_PROGRAM);


    return 0;
}
