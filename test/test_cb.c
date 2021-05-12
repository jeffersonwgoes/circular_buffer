#include "cb.h"
#include "tinytest.h"
#define BUFFER_SIZE 5

void test_init(void)
{
	cb_t cb;
	ASSERT_EQUALS(true, cb_init(&cb, BUFFER_SIZE)); 
	ASSERT_EQUALS(true, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
}

void test_add_item(void)
{
	cb_t cb;
	ASSERT_EQUALS(true, cb_init(&cb, BUFFER_SIZE)); 
	
	cb_add(&cb, 10);
	ASSERT_EQUALS(false, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
	
	ASSERT_EQUALS(10, cb_get(&cb));
	ASSERT_EQUALS(true, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
}

void test_buffer(void)
{
	cb_t cb;
	ASSERT_EQUALS(true, cb_init(&cb, BUFFER_SIZE)); 
	
	cb_add(&cb, 1);
	cb_add(&cb, 2);
	cb_add(&cb, 3);
	cb_add(&cb, 4);
	cb_add(&cb, 5);
	
	ASSERT_EQUALS(false, cb_is_empty(cb));
	ASSERT_EQUALS(true, cb_is_full(cb));
	
	ASSERT_EQUALS(1, cb_get(&cb));		
	ASSERT_EQUALS(2, cb_get(&cb));		
	ASSERT_EQUALS(3, cb_get(&cb));		
	ASSERT_EQUALS(4, cb_get(&cb));		
	ASSERT_EQUALS(5, cb_get(&cb));		
	
	ASSERT_EQUALS(true, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
}

int main(void)
{
	RUN(test_init);
	RUN(test_add_item);
	RUN(test_buffer);
	return TEST_REPORT();
}