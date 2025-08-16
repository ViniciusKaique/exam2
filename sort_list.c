#include <stdio.h>

typedef struct s_list
{
    int data;
    struct s_list *next;

} t_list;

int ascending(int a, int b)
{
	return (a <= b);
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *head;
    head = lst;

    while(lst && lst->next)
    {
        if(cmp(lst->data, lst->next->data) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = head;
        }
        else
        lst = lst->next;
    }
    return (head);
}

int main(void)
{
    t_list node5 = {7, NULL};
    t_list node4 = {2, &node5};
    t_list node3 = {9, &node4};
    t_list node2 = {1, &node3};
    t_list node1 = {5, &node2};

    t_list *head = &node1;

    printf("Antes: ");
    for (t_list *cur = head; cur; cur = cur->next)
        printf("%d ", cur->data);
    printf("\n");

    head = sort_list(head, ascending);

    printf("Depois: ");
    for (t_list *cur = head; cur; cur = cur->next)
        printf("%d ", cur->data);
    printf("\n");

    return 0;
}