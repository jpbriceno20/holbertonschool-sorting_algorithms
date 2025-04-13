#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    curr = (*list)->next;
    while (curr)
    {
        temp = curr;
        while (temp->prev && temp->n < temp->prev->n)
        {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->prev->prev;

            if (temp->prev)
                temp->prev->next = temp;
            else
                *list = temp;

            temp->next->prev = temp;

            print_list(*list);
        }
        curr = curr->next;
    }
}

