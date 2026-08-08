#include <stdio.h>
#include "list.h"

struct data_node
{
    struct list_head node;
    int data;
};
int main()
{
    // Declare list head and initialize it
    LIST_HEAD(head);

    // method 2
    // struct list_head head;
    // INIT_LIST_HEAD(&head);

    // init data node
    struct data_node data_node_a = {0};
    struct data_node data_node_b = {0};
    struct data_node data_node_c = {0};
    data_node_a.data = 100;
    data_node_b.data = 200;
    data_node_c.data = 300;

    // Add a list node to the end of the list
    list_add_tail(&data_node_a.node, &head);
    list_add_tail(&data_node_b.node, &head);
    list_add(&data_node_c.node, &head);

    // iterate over list entries (method 1)
    struct list_head *p_node;
    list_for_each(p_node, &head)
    {
        struct data_node *pEntry = list_entry(p_node, struct data_node, node);
        printf("data is %d \n", pEntry->data);
    }

    // iterate over list entries (method 2)
    struct data_node *p_data_node;
    list_for_each_entry(p_data_node, &head, node)
    {
        printf("value is %d \n", p_data_node->data);
    }

    return 0;
}