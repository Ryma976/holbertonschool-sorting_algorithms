#include "deck.h"
#include <string.h>

/**
 * get_value - Converts card value to number
 * @value: Card value
 *
 * Return: Card value index
 */
int get_value(const char *value)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
		"Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * compare_cards - Compares two cards
 * @a: First card node
 * @b: Second card node
 *
 * Return: Difference between cards
 */
int compare_cards(deck_node_t *a, deck_node_t *b)
{
	int val_a = get_value(a->card->value);
	int val_b = get_value(b->card->value);

	if (a->card->kind != b->card->kind)
		return (a->card->kind - b->card->kind);

	return (val_a - val_b);
}

/**
 * swap_nodes - Swaps two adjacent nodes
 * @deck: Pointer to deck head
 * @a: First node
 * @b: Second node
 */
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*deck = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to deck head
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	int swapped = 1;

	if (!deck || !*deck)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *deck;

		while (current && current->next)
		{
			if (compare_cards(current, current->next) > 0)
			{
				swap_nodes(deck, current, current->next);
				swapped = 1;
				if (current->prev)
					current = current->prev;
			}
			else
				current = current->next;
		}
	}
}
