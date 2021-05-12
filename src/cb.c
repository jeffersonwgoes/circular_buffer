#include "cb.h"

bool cb_init(cb_t *cb, uint8_t size)
{
	cb->start = 0;
	cb->end = 0;
	cb->size = size;
	cb->count = 0;
	return true;
}

bool cb_is_full(cb_t cb)
{
	return cb.count == cb.size;
}
	
bool cb_is_empty(cb_t cb) 
{
	return cb.count == 0;
}

void cb_add(cb_t * cb, uint8_t item)
{
	cb->values[cb->start++] = item;
	cb->start = cb->start == cb->size ? 0 : cb->start;
	cb->count++;
}
	
uint8_t cb_get(cb_t *cb)
{
	uint8_t item = cb->values[cb->end++];	
	cb->end = cb->end == cb->size ? 0 : cb->end;
	cb->count--;
	return item;
}