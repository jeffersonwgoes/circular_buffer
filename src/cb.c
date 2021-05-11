#include "cb.h"

bool cb_init(cb_t *cb)
{
	cb->start = 0;
	cb->end = 0;
	cb->count = 0;
	return true;
}

bool cb_is_full(cb_t cb)
{
	return cb.start == cb.end && cb.count > 0;
}


bool cb_is_empty(cb_t cb) 
{
	return cb.count == 0;
}