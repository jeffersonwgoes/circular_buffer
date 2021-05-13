#include "cb.h"
#include <stddef.h>

bool cb_init(cb_t *cb, uint8_t size, uint8_t *storage)
{
	if(cb == NULL) return false;
	if(storage == NULL) return false;
	if(size < 1) return false;
	cb->start = 0;
	cb->end = 0;
	cb->size = size;
	cb->count = 0;
	cb->values = storage;
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

bool cb_add(cb_t * cb, uint8_t item)
{
	if(cb == NULL) return false;
	if(cb_is_full(*cb)) return false;
	
	cb->values[cb->start++] = item;
	cb->start = cb->start == cb->size ? 0 : cb->start;
	cb->count++;
	return true;
}
	
bool cb_get(cb_t *cb, uint8_t* item)
{
	if(cb == NULL) return false;
	if(item == NULL) return false;
	if(cb_is_empty(*cb)) return false;
	
	*item = cb->values[cb->end++];	
	cb->end = cb->end == cb->size ? 0 : cb->end;
	cb->count--;
	return true;
}