#ifndef __CSDA_LIST_H__
#define __CSDA_LIST_H__

#define linked_list_prototype(type, prefix)         \
struct prefix##_list_node {                         \
    type data;                                      \
    struct prefix##_list_node *prev, *next;         \
};                                                  \
struct prefix##_list {                              \
    struct prefix##_list_node *head;                \
}

struct list_node {
    int data;
    struct list_node *prev, *next;
};

int list_add_head(struct list_node **list, int data);

int list_add_tail(struct list_node **list, int data);

int list_delete(struct list_node **list, int data);

int list_count(struct list_node **list);

#endif