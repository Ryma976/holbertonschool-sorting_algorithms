#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Card kinds
 * @SPADE: Spade card
 * @HEART: Heart card
 * @CLUB: Club card
 * @DIAMOND: Diamond card
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of card
 * @kind: Kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck node
 * @card: Pointer to card
 * @prev: Previous node
 * @next: Next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
