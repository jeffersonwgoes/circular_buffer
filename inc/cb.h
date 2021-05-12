#ifndef __CB_H__
#define __CB_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct cb {
	uint8_t start;
	uint8_t end;
	uint8_t size;
	uint8_t count;
	uint8_t values[5];
} cb_t;

bool cb_init(cb_t *cb, uint8_t size);
bool cb_is_full(cb_t cb);
bool cb_is_empty(cb_t cb);
void cb_add(cb_t *cb, uint8_t item);
uint8_t cb_get(cb_t *cb);

#endif /* __CB_H__ */