#ifndef PROBLEMS_H
#define PROBLEMS_H
#include "doublylinkedlist.h"
#include<vector>
#include<tuple>

Node* delete_Key_InDLL(Node*,int);
vector<tuple<int,int>> find_pairs_with_sum_inDLL(Node*, int);
Node* remove_duplicates_from_DLL(Node*);
Node* remove_duplicates_from_DLL_Sol2(Node*);
#endif