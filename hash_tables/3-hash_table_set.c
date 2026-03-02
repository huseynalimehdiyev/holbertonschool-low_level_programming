#include "hash_tables.h"

/**
 * create_node - Creates a new hash node
 * @key: The key
 * @value: The value
 *
 * Return: Pointer to the new node, or NULL on failure
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * update_node - Updates value of an existing node
 * @node: The node to update
 * @value: New value
 *
 * Return: 1 on success, 0 on failure
 */
int update_node(hash_node_t *node, const char *value)
{
	char *new_value;

	new_value = strdup(value);
	if (!new_value)
		return (0);

	free(node->value);
	node->value = new_value;
	return (1);
}

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key (cannot be empty)
 * @value: The value (must be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *temp, *new_node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (update_node(temp, value));
		temp = temp->next;
	}

	new_node = create_node(key, value);
	if (!new_node)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
