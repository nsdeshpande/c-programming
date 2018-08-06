#include<stdio.h>
#include"sll.h"
#include"utils.h"

int main(void){

    Node *head = NULL;
    int data = -1;
    int userOption = 1;
    int sll_node_search_index = -2;
    int index = -1;
    int length = 0;
	int swap1 = -1, swap2 = -1;
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
            case OPTION_FIND_MIDDLE_NODE_1:
                sll_find_middle_of_sll_1(head);
            break;
            case OPTION_FIND_N_ELEMENT_FROM_END:
                 printf("\nSLL_USER_INPUT: Enter nth index to find from end.");
                 scanf("%d",&index);
                 sll_find_n_node_from_end(head,index);
            break;
            case OPTION_SWAP_TWO_NODES:
                printf("\nSLL_USER_INPUT: Enter two unique nodes to swap");
                scanf("%d %d",&swap1, &swap2);
                sll_swap_two_nodes(head,swap1,swap2);
            break;
            case OPTION_MERGE_SORTED_LL:
                sll_merge_sorte_ll();
            break;
            case OPTION_DELETE_SLL:
                head = sll_delete_sll(head);
            break;
            case OPTION_GET_LENGTH:
                length = sll_get_length(head);
                printf("\nThe length of the SLL is %d",length);
            break;  
        }
    }while(userOption!=OPTION_EXIT_PROGRAM);


    return 0;
}
