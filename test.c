#include <list.h>
#include <stdio.h>

linked_list_prototype(int, test);

#define traverse_linked_list(head)                      \
printf("%d, ", head->data);                             \
for (it = head->next; it != head; it = it->next) {      \
    printf("%d, ", it->data);                           \
}                                                       \
printf("\n")

void list_test() {
    struct list_node *head = NULL, *it;

    list_add_head(&head, 2);
    traverse_linked_list(head);

    list_add_head(&head, 6);
    traverse_linked_list(head);
    
    list_add_head(&head, 3);
    traverse_linked_list(head);
    
    list_add_head(&head, 4);
    traverse_linked_list(head);
    
    list_add_head(&head, 5);
    traverse_linked_list(head);
    
    list_delete(&head, 5);
    traverse_linked_list(head);
    
    list_delete(&head, 4);
    traverse_linked_list(head);
    
    list_delete(&head, 6);
    traverse_linked_list(head);
    
    list_delete(&head, 3);
    traverse_linked_list(head);
    
    list_delete(&head, 6);
    traverse_linked_list(head);

    list_delete(&head, 2);
}

int main() {
    list_test();
    return 0;
}