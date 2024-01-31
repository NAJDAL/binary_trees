#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 * create_node - Creates a new node for level-order traversal queue.
 *
 * @node: Binary tree node for the new node to contain.
 *
 * Return: Pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * pint_push - Pushes children of a node into level-order traversal queue.
 *
 * @node: Binary tree node to push children from.
 * @head: Pointer to the head of the queue.
 * @tail: Double pointer to the tail of the queue.
 * @func: Pointer to the function to call on each node.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * free_queue - Frees memory allocated for level-order traversal queue.
 *
 * @head: Pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pop - Pops the head of the level-order traversal queue.
 *
 * @head: Double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
