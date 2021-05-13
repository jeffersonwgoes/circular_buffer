#include "cb.h"
#include "tinytest.h"
#define BUFFER_SIZE 5

static uint8_t storage[BUFFER_SIZE];
void test_init(void)
{
	cb_t cb;
	ASSERT_EQUALS(true, cb_init(&cb, BUFFER_SIZE, storage)); 
	ASSERT_EQUALS(true, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
}

void test_add_item(void)
{
	cb_t cb;
	ASSERT_EQUALS(true, cb_init(&cb, BUFFER_SIZE, storage)); 
	
	cb_add(&cb, 10);
	ASSERT_EQUALS(false, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
	
	uint8_t item;
	ASSERT_EQUALS(true, cb_get(&cb, &item));
	ASSERT_EQUALS(10, item);
	ASSERT_EQUALS(true, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
}

void test_buffer(void)
{
	cb_t cb;
	ASSERT_EQUALS(true, cb_init(&cb, BUFFER_SIZE, storage)); 
	
	ASSERT_EQUALS(true,cb_add(&cb, 1));
	ASSERT_EQUALS(true,cb_add(&cb, 2));
	ASSERT_EQUALS(true,cb_add(&cb, 3));
	ASSERT_EQUALS(true,cb_add(&cb, 4));
	ASSERT_EQUALS(true,cb_add(&cb, 5));
	
	ASSERT_EQUALS(false, cb_is_empty(cb));
	ASSERT_EQUALS(true, cb_is_full(cb));
	
	uint8_t item;
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(1, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(2, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(3, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(4, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(5, item);		
	
	ASSERT_EQUALS(true, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
}

void test_fails(void)
{
	cb_t cb;
	ASSERT_EQUALS(false, cb_init(NULL, BUFFER_SIZE, storage));
	ASSERT_EQUALS(false, cb_init(&cb, BUFFER_SIZE, NULL));
	ASSERT_EQUALS(false, cb_init(&cb, 0, storage));
	
	uint8_t item;
	ASSERT_EQUALS(false, cb_add(NULL, 10));
	ASSERT_EQUALS(false, cb_get(NULL, &item));
	ASSERT_EQUALS(false, cb_get(&cb, NULL));
}

void test_extreme(void)
{
	cb_t cb;
	ASSERT_EQUALS(true, cb_init(&cb, BUFFER_SIZE, storage)); 
	ASSERT_EQUALS(true,cb_add(&cb, 1));
	ASSERT_EQUALS(true,cb_add(&cb, 2));
	ASSERT_EQUALS(true,cb_add(&cb, 3));
	ASSERT_EQUALS(true,cb_add(&cb, 4));
	ASSERT_EQUALS(true,cb_add(&cb, 5));
	ASSERT_EQUALS(false,cb_add(&cb, 6));
	
	ASSERT_EQUALS(false, cb_is_empty(cb));
	ASSERT_EQUALS(true, cb_is_full(cb));
	
	uint8_t item;
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(1, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(2, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(3, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(4, item);		
	
	ASSERT_EQUALS(true, cb_get(&cb, &item));		
	ASSERT_EQUALS(5, item);		
	
	ASSERT_EQUALS(false, cb_get(&cb, &item));	
}

int main(void)
{
	RUN(test_init);
	RUN(test_add_item);
	RUN(test_buffer);
	RUN(test_fails);
	RUN(test_extreme);
	return TEST_REPORT();
}