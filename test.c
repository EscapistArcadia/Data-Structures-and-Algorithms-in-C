#include <list.h>
#include <stdio.h>

void sc_list_test() {
    struct sc_list_node *head = NULL;

    sc_list_traverse(&head);
    sc_list_add_tail(&head, 2);
    sc_list_traverse(&head);
    sc_list_add_tail(&head, 4);
    sc_list_traverse(&head);
    sc_list_add_tail(&head, 6);
    sc_list_traverse(&head);
    sc_list_add_tail(&head, 7);
    sc_list_traverse(&head);
    sc_list_add_tail(&head, 8);
    sc_list_traverse(&head);
    sc_list_delete(&head, 6);
    sc_list_traverse(&head);
    sc_list_delete(&head, 2);
    sc_list_traverse(&head);
    sc_list_destroy(&head);
}

void dc_list_test() {
    struct dc_list_node *head = NULL;

    dc_list_traverse(&head);
    dc_list_add_tail(&head, 2);
    dc_list_traverse(&head);
    dc_list_add_tail(&head, 4);
    dc_list_traverse(&head);
    dc_list_add_tail(&head, 6);
    dc_list_traverse(&head);
    dc_list_add_tail(&head, 7);
    dc_list_traverse(&head);
    dc_list_add_tail(&head, 8);
    dc_list_traverse(&head);
    dc_list_delete(&head, 6);
    dc_list_traverse(&head);
    dc_list_delete(&head, 2);
    dc_list_traverse(&head);
    dc_list_destroy(&head);
}

int main() {
    sc_list_test();
    dc_list_test();
    return 0;
}