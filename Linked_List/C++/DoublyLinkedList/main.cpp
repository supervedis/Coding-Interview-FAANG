#include"doublylinkedlist.h"
#include "problems.h"

int main(){
    DoublyLinkedList dlist;
    /*for (size_t i = 1; i < 6; i++)
    {
        dlist.append(i);
    }*/
    
    /*dlist.append(3);
    dlist.append(2);
    dlist.append(3);
    dlist.append(3);
    dlist.append(4);
    dlist.append(3);
    dlist.append(5);
    dlist.append(3);
    dlist.append(6);*/
    dlist.append(1);
    dlist.append(1);
    dlist.append(1);
    dlist.append(2);
    dlist.append(3);
    dlist.append(3);
    dlist.append(4);
    dlist.print();
    //dlist.delete_head();
    //dlist.delete_tail();
    //dlist.delete_element_at(1);
    //dlist.delete_value(4);
    //dlist.insert_before_head(1);
    //dlist.insert_before_tail(7);
    //dlist.insert_before_index(1,9);
    Node* head = dlist.get_head();
    //dlist.head = delete_Key_InDLL(head, 3);
    /*vector<tuple<int, int>> pairs = find_pairs_with_sum_inDLL(head, 5);
    for (size_t i = 0; i < pairs.size(); i++)
    {
        tuple<int, int> pair = pairs[i];
        cout<<"("<<get<0>(pair)<<","<<get<1>(pair)<<")"<<endl;
    }*/
    remove_duplicates_from_DLL_Sol2(head);
    dlist.print();
    //dlist.reverse_list();
    //dlist.print();
    return 0;
}