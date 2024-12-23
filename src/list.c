#include <list.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int sc_list_add_head(struct sc_list_node **list, int data) {
    struct sc_list_node *head, *node, *curr;

    if (list == NULL) {
        return -1;
    }

    head = *list;
    if (head) {
        node = (struct sc_list_node *)malloc(sizeof(struct sc_list_node));          /* assignment */
        node->data = data;
        node->next = head;
        for (curr = head; curr->next != head; curr = curr->next);                   /* reassign the tail's next to the new head */
        curr->next = node;
        *list = node;
    } else {
        head = *list = (struct sc_list_node *)malloc(sizeof(struct sc_list_node));
        head->data = data;
        head->next = head;
    }
    return 0;
}

int sc_list_add_tail(struct sc_list_node **list, int data) {
    struct sc_list_node *head, *curr, *node;

    if (list == NULL) {
        return -1;
    }

    head = *list;
    if (head) {
        node = (struct sc_list_node *)malloc(sizeof(struct sc_list_node));          /* assignment */
        node->data = data;
        node->next = head;
        for (curr = head; curr->next != head; curr = curr->next);
        curr->next = node;
    } else {
        head = *list = (struct sc_list_node *)malloc(sizeof(struct sc_list_node));
        head->data = data;
        head->next = head;
    }
    return 0;
}

int sc_list_delete(struct sc_list_node **list, int data) {
    struct sc_list_node *head, *curr, *next;

    if (list == NULL || *list == NULL) {
        return -1;
    }

    head = *list;
    if (head->data == data) {
        if (head->next == head) {
            free(head);
            *list = NULL;
        } else {
            for (next = head->next; next->next != head; next = next->next);
            next->next = head->next;
            *list = head->next;
            free(head);
        }
    } else {
        for (curr = head, next = curr->next; next != head; curr = next, next = next->next) {
            if (next->data == data) {
                curr->next = next->next;
                free(next);
                break;
            }
        }
    }
    return 0;
}

inline void sc_list_traverse(struct sc_list_node **list) {
    struct sc_list_node *head, *node;

    if (list == NULL || *list == NULL) {
        printf("{}\n");
    } else {
        head = *list;
        putc('{', stdout);
        printf("%d", head->data);
        for (node = head->next; node != head; node = node->next) {
            printf(", %d", node->data);
        }
        printf("}\n");
    }
}

inline void sc_list_destroy(struct sc_list_node **list) {
    struct sc_list_node *head, *curr, *next;

    if (list == NULL || *list == NULL) {
        return;
    }

    head = *list;
    for (curr = head->next, next = curr->next; curr != *list; curr = next, next = next->next) {
        free(curr);
    }
    free(head);
}

int dc_list_add_head(struct dc_list_node **list, int data) {
    struct dc_list_node *new_head, *head;

    if (list == NULL) {
        return -1;
    }

    new_head = (struct dc_list_node *)malloc(sizeof(struct dc_list_node));
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

int dc_list_add_tail(struct dc_list_node **list, int data) {
    struct dc_list_node *node, *head;

    if (list == NULL) {
        return -1;
    }

    node = (struct dc_list_node *)malloc(sizeof(struct dc_list_node));
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

int dc_list_delete(struct dc_list_node **list, int data) {
    struct dc_list_node *head, *curr, *next;

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

void dc_list_traverse(struct dc_list_node **list) {
    struct dc_list_node *head, *node;

    if (list == NULL || *list == NULL) {
        printf("{}\n");
    } else {
        head = *list;
        putc('{', stdout);
        printf("%d", head->data);
        for (node = head->next; node != head; node = node->next) {
            printf(", %d", node->data);
        }
        printf("}\n");
    }
}

void dc_list_destroy(struct dc_list_node **list) {
    struct dc_list_node *head, *curr, *next;

    if (list == NULL || *list == NULL) {
        return;
    }

    head = *list;
    for (curr = head->next, next = curr->next; curr != *list; curr = next, next = next->next) {
        free(curr);
    }
    free(head);
}
