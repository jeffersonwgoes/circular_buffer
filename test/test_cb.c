#include "cb.h"
#include "tinytest.h"

cb_t cb;

void test_init(void)
{
	//On start, expected an empty and not full buffer.
	ASSERT_EQUALS(true, cb_init(&cb)); 
	ASSERT_EQUALS(true, cb_is_empty(cb));
	ASSERT_EQUALS(false, cb_is_full(cb));
}

void test_add_itens(void)
{
	
}

int main(void)
{
	RUN(test_init);
	RUN(test_add_itens);
	return TEST_REPORT();
}