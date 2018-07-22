#include<stdio.h>
#include"utils.h"

char* OPTIONS[6] = {"OPTION_APPEND_NODE_SLL\0",
            "OPTION_INSERT_NODE_SLL\0",
            "OPTION_PRINT_SLL\0",
            "OPTION_DELETE_INDEX_NODE_SLL\0",
            "OPTION_SEARCH_NODE_SLL\0",
            "OPTION_EXIT_PROGRAM\0"};

int getUserInput(){
    int result = OPTION_EXIT_PROGRAM; 
    int itr = 	OPTION_APPEND_NODE_SLL;
    for(itr = OPTION_APPEND_NODE_SLL; itr <= OPTION_EXIT_PROGRAM; itr++){
        printf("\n%d:%s\n",itr,OPTIONS[itr]);
    }
    scanf("%d",&result);
    return result;
}
