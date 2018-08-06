#include<stdio.h>
#include"utils.h"

char* OPTIONS[] = {"OPTION_APPEND_NODE_SLL\0",
            "OPTION_INSERT_NODE_SLL\0",
            "OPTION_PRINT_SLL\0",
            "OPTION_DELETE_INDEX_NODE_SLL\0",
            "OPTION_SEARCH_NODE_SLL\0",
            "OPTION_FIND_MIDDLE_NODE_1\0",
            "OPTION_FIND_N_ELEMENT_FROM_END\0",
            "OPTION_SWAP_TWO_NODES\0",
            "OPTION_MERGE_SORTED_LL\0",
            "OPTION_DELETE_SLL\0",
            "OPTION_GET_LENGTH\0", 
            "OPTION_EXIT_PROGRAM\0",};

int getUserInput(){
    int result = OPTION_EXIT_PROGRAM; 
    int itr = 	OPTION_APPEND_NODE_SLL;
    printf("\n");
    for(itr = OPTION_APPEND_NODE_SLL; itr <= OPTION_EXIT_PROGRAM; itr++){
        printf("%d:%s\n",itr,OPTIONS[itr]);
    }
    scanf("%d",&result);
    return result;
}
