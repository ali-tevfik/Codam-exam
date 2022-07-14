#include <stdlib.h>
#include <stdio.h>


typedef struct s_list
{
	struct s_list *next;
	void *data;
}	t_list;

/*
	add new node to the end of the list, with data as content
*/
void add_to_list_end(t_list **head, void *data)
{
	t_list *ptr = *head;
	t_list *current;
	
	current = (t_list *)malloc(sizeof(t_list));
	current->data = data;
	while (ptr->next != 0) // get last element
		ptr = ptr->next;
	ptr->next = current;
	current->next = NULL;
}

/*
	compare first char of data to first char of data_ref
	(just for testing)
*/
int cmp(void *data, void *data_ref)
{
	if (*(char *)data == *(char *)data_ref)
		return 0;
	return 1;
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current, *temp, *old;
	current = *begin_list; // I would not call this variable head, call it 'current' or something like that. You change this pointer during the program so it does not always point to the head of the list. Confusing!!
	old = NULL; // maybe call this variable 'previous' since it should always point to the previous node
	while (current)
	{
		// add line temp = head;
		if (!(cmp(data_ref, current->data))) // cmp returns 0 if the args are the same. Now you use it as if 1 would be the same. and: what is env->data? You just set env to head->data in the previous line. Does env->data even exist?
		{
			temp = current; // what is env?? change this to env = head, not head->data
			if (!old)
				*begin_list = (*begin_list)->next; // use *begin_list instead of begin_list. You can not change the ** pointer. I already changed it to how it should be now
			else
				old->next = current->next; // Shouldnt you change old->next instead of head here? So old->next = head->next
			// free(env->data); // you dont have to free the data, only the pointer to the node. So this line can be removed
			// free(env);  // remove
			current = current->next; //  <-- move to the next node
			free(temp); //   <-- free the current node
		}
		// add:
		else
		{
			old = current;//   <-- change previous node to current node
			current = current->next;//   <-- move to the next node
		}
	}
}


int main(void)
{

	t_list *head = (t_list *)malloc(sizeof(t_list));

	head->data = "XXX";
	head->next = NULL;

	add_to_list_end(&head, "tweede");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "derde");
	add_to_list_end(&head, "vierde");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "vijfde");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "XXX");
	add_to_list_end(&head, "XXX");

	ft_list_remove_if(&head, "tweede", cmp);
	ft_list_remove_if(&head, "XXX", cmp);
	ft_list_remove_if(&head, "vijfde", cmp);

	t_list *ptr = head;

	while (ptr) // loop through all elements
	{
		printf("%s\n", ptr->data);
		ptr = ptr->next;
	}
	// while(1) // to test for leaks
	// {
	// 	;
	// }
}
