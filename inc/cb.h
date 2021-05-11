#ifndef __CB_H__
#define __CB_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct cb {
	uint8_t start;
	uint8_t end;
	uint8_t count;
} cb_t;

bool cb_init(cb_t *cb);
bool cb_is_full(cb_t cb);
bool cb_is_empty(cb_t cb);

#endif /* __CB_H__ */