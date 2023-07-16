
#include "push_swap.h"

Node	*create_node(int value)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	return (newNode);
}

Node	*pop(t_stack* stack)
{
	Node*	tmp;

	if (!stack || stack->head == NULL)
		return NULL;
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = NULL;
	stack->size--;
	return (tmp);
}

void	insert_node_head(t_stack* stack, Node* node)
{
	Node*	tmp;

	if (!stack || !node)
		return;
	tmp = stack->head;
	stack->head = node;
	stack->head->next = tmp;
	stack->size++;
}

void	insert_node_tail(t_stack* stack, Node* node)
{
	Node*	current;

	if (!stack || !node)
		return;
	current = stack->head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = node;
	node->next = NULL;
	stack->size++;
}

void	destroy_node(Node* node)
{
	free(node);
}
