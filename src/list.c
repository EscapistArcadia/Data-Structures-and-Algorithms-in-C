#include <list.h>
#include <stddef.h>
#include <stdlib.h>

int list_add_head(struct list_node **list, int data) {
    struct list_node *new_head, *head;

    if (list == NULL) {
        return -1;
    }

    new_head = (struct list_node *)malloc(sizeof(struct list_node));
    if (!new_head) {
        return -1;
    }

    head = *list;
    new_head->data = data;
    if (head) {
        new_head->next = head;
        new_head->prev = head->prev;
        head->prev->next = new_head;
        head->prev = new_head;
    } else {
        new_head->prev = new_head->next = new_head;
    }
    *list = new_head;

    return 0;
}

int list_add_tail(struct list_node **list, int data) {
    struct list_node *node, *head;

    if (list == NULL) {
        return -1;
    }

    node = (struct list_node *)malloc(sizeof(struct list_node));
    if (!node) {
        return -1;
    }

    head = *list;
    node->data = data;
    if (head) {
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;        /* the previous */
        head->prev = node;
    } else {
        *list = node->next = node->prev = node;
    }

    return 0;
}

int list_delete(struct list_node **list, int data) {
    struct list_node *head, *curr, *next;

    if (list == NULL || *list == NULL) {
        return -1;
    }

    head = *list;
    if (head->data == data) {
        if (head == head->next) {
            free(head);
            *list = NULL;
        } else {
            // someone asked me, so I wrote this
            // for (curr = head->next; curr->next != head; curr = curr->next);
            // curr->next = head->next;
            
            next = head->next;
            next->prev = head->prev;
            head->prev->next = next;
            *list = head->next;
            free(head);
        }
        return 0;
    } else {
        for (curr = head, next = curr->next; next != head; curr = next, next = next->next) {
            if (next->data == data) {
                curr->next = next->next;
                curr->next->prev = curr;
                free(next);
                return 0;
            }
        }
        return -1;
    }
}

int list_count(struct list_node **list) {
    int count;
    struct list_node *head, *curr;

    if (list == NULL || *list == NULL) {
        return 0;
    }

    count = 1;
    head = *list;
    for (curr = head->next; curr != head; curr = curr->next, ++count);
    return count;
}
