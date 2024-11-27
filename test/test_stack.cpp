// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(TVectorStack, can_create_empty_stack)
{
	TVectorStack<int> st;
	EXPECT_TRUE(st.IsEmpty());
}
TEST(TVectorStack, can_get_size)
{
	TVectorStack<int> st;
	EXPECT_EQ(0,st.size());
}
TEST(TVectorStack, can_return_is_not_empty)
{
	TVectorStack<int> st;
	st.Push(10);
	EXPECT_FALSE(st.IsEmpty());
}
TEST(TVectorStack, can_return_is_empty)
{
	TVectorStack<int> st;
	st.Push(10);
	st.Pop();
	EXPECT_TRUE(st.IsEmpty());
}
TEST(TVectorStack, can_push_and_pop)
{
	TVectorStack<int> st;
	st.Push(10);
	int value = st.Pop();
	EXPECT_EQ(10,value);
}
TEST(TVectorStack, can_check_top_element)
{
	TVectorStack<int> st;
	st.Push(10);
	EXPECT_EQ(10, st.Top());
}
TEST(TVectorStack, throws_when_try_to_pop_element_from_empty_stack)
{
	TVectorStack<int> st;
	ASSERT_ANY_THROW(st.Pop());
}
TEST(TVectorStack, throws_when_try_to_check_top_element_from_empty_stack)
{
	TVectorStack<int> st;
	ASSERT_ANY_THROW(st.Top());
}