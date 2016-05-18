#include "table.h"
#include <gtest.h>

TEST(TableHash, can_create_table_hash) {
	ASSERT_NO_THROW(HashTable t);
}
TEST(TableHash, can_Insert_1) {
	HashTable t;
	Polinom p;
	p.InsertFirst(Monom(1, 1, 0, 0));
	t.Insert("a", &p);

	EXPECT_EQ(1, t.GetNode("a")->head->m.GetCoeff());
}
TEST(TableHash, can_Insert_whith_collision) {
	HashTable t;
	Polinom p,d;
	p.InsertFirst(Monom(1, 1, 0, 0));
	d.InsertFirst(Monom(2, 2, 0, 0));
	t.Insert("a", &p);
	t.Insert("k", &d);

	EXPECT_EQ(1, t.GetNode("a")->head->m.GetCoeff());
	EXPECT_EQ(2, t.GetNode("k")->head->m.GetCoeff());
}

TEST(TableHash, can_not_find) {
	HashTable t;
	EXPECT_EQ(NULL, t.GetNode("a"));
}

TEST(TableHash, can_delete) {
	HashTable t;
	Polinom p;
	p.InsertFirst(Monom(1, 1, 0, 0));
	t.Insert("w", &p);
	t.Delete("w");
	EXPECT_EQ(NULL, t.GetNode("w"));
}