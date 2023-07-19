#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @st: str field of node
 * @no: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *st, int no)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->no = no;
	if (st)
	{
		new_head->st = _strdup(st);
		if (!new_head->st)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @st: str field of node
 * @no: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *st, int no)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->no = no;
	if (st)
	{
		new_node->st = _strdup(st);
		if (!new_node->st)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->st);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->st);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->st);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

/**
* list_len - determines length of linked list
* @h: pointer to first node
*
* Return: size of list
*/
size_t list_len(const list_t *h)
{
	size_t i = 0;
	
	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
* list_to_strings - returns an array of strings of the list->str
* @head: pointer to first node
*
* Return: array of strings
*/
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **sts;
	char *st;
	
	if (!head || !i)
		return (NULL);
	sts = malloc(sizeof(char *) * (i + 1));
	if (!sts)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		st = malloc(_strlen(node->st) + 1);
		if (!st)
		{
			for (j = 0; j < i; j++)
				free(sts[j]);
			free(sts);
			return (NULL);
		}
		st = _strcpy(st, node->st);
		sts[i] = st;
	}
	sts[i] = NULL;
	return (sts);
}

/**
* print_list - prints all elements of a list_t linked list
* @h: pointer to first node
*
* Return: size of list
*/
size_t print_list(const list_t *h)
{
	size_t i = 0;
	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->st ? h->st : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
* node_starts_with - returns node whose string starts with prefix
* @node: pointer to list head
* @prefix: string to match
* @c: the next character after prefix to match
*
* Return: match node or null
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;
	
	while (node)
	{
		p = starts_with(node->st, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
* get_node_index - gets the index of a node
* @head: pointer to list head
* @node: pointer to the node
*
* Return: index of node or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;
	
	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
