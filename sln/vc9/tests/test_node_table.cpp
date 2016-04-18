#include <gtest.h>

#include "table.h"


TEST(TableNode, can_create_table_node) {
	string s = "a";
	Monom m(1,1, 0, 0);
	Polinom a;
	a.InsertFirst(m);
	NodeTable n(s, &a);

	EXPECT_EQ("a", n.GetKey());
	EXPECT_EQ(m.GetCoeff(), n.GetElement()->head->m.GetCoeff());
}

TEST(TableNode, test_1) {
	NodeTable a("a", NULL);
	NodeTable b("b", NULL);

	ASSERT_NO_THROW(b=a);
	EXPECT_EQ("a", b.GetKey());
}

TEST(TableSort, can_create_table) {
	ASSERT_NO_THROW(SortedTable table);
}