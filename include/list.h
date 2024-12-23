#ifndef __CSDA_LIST_H__
#define __CSDA_LIST_H__

/* single, circular linked list*/

struct sc_list_node {
    int data;
    struct sc_list_node *next;
};

int sc_list_add_head(struct sc_list_node **list, int data);

int sc_list_add_tail(struct sc_list_node **list, int data);

int sc_list_delete(struct sc_list_node **list, int data);

void sc_list_traverse(struct sc_list_node **list);

void sc_list_destroy(struct sc_list_node **list);

/* double, circular linked list */

struct dc_list_node {
    int data;
    struct dc_list_node *prev, *next;
};

int dc_list_add_head(struct dc_list_node **list, int data);

int dc_list_add_tail(struct dc_list_node **list, int data);

int dc_list_delete(struct dc_list_node **list, int data);

void dc_list_traverse(struct dc_list_node **list);

void dc_list_destroy(struct dc_list_node **list);

#endif