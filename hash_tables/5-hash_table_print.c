#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 *
 * Description: Prints key/value pairs in the order they appear
 * in the array, and in the linked list for collisions
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int first = 1;
	hash_node_t *temp;

	if (!ht)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			first = 0;
			temp = temp->next;
		}
	}

	printf("}\n");
}
