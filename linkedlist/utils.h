#ifndef UTILS_H
#define UTILS_H

enum options{
    OPTION_APPEND_NODE_SLL       = 0,
    OPTION_INSERT_NODE_SLL       = 1,
    OPTION_PRINT_SLL             = 2,
    OPTION_DELETE_INDEX_NODE_SLL = 3,
    OPTION_SEARCH_NODE_SLL       = 4,
    OPTION_FIND_MIDDLE_NODE_1    = 5,
    OPTION_FIND_N_ELEMENT_FROM_END = 6, 
    OPTION_SWAP_TWO_NODES         = 7,
    OPTION_MERGE_SORTED_LL        = 8,
    OPTION_DELETE_SLL             = 9,
    OPTION_GET_LENGTH             = 10,
    OPTION_EXIT_PROGRAM,
};


int getUserInput();

#endif
