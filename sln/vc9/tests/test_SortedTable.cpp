#include "table.h"
#include <gtest.h>

TEST(TableSort, can_create_table_sort) {
	ASSERT_NO_THROW(SortedTable t);
}
TEST(TableSort, can_find_in_empty) {
	SortedTable t;
	EXPECT_EQ(NULL, t.GetNode("a"));
}
TEST(TableSort, can_insert) {
	SortedTable t;
	Polinom p;
	p.InsertFirst(Monom(1, 1, 0, 0));
	t.Insert("a", &p);
	EXPECT_EQ(1, t.GetNode("a")->head->m.GetCoeff());
}
TEST(TableSort, can_insert_2) {
	SortedTable t;
	Polinom p,d;
	p.InsertFirst(Monom(1, 1, 0, 0));
	d.InsertFirst(Monom(2, 2, 0, 0));
	t.Insert("a", &p);
	t.Insert("b", &d);
	EXPECT_EQ(1, t.GetNode("a")->head->m.GetCoeff());
	EXPECT_EQ(2, t.GetNode("b")->head->m.GetCoeff());
}
TEST(TableSort, can_insert_3) {
	SortedTable t;
	Polinom p, d, g;
	p.InsertFirst(Monom(1, 1, 0, 0));
	d.InsertFirst(Monom(2, 2, 0, 0));
	g.InsertFirst(Monom(3, 3, 0, 0));
	t.Insert("aaa", &g);
	t.Insert("a", &p);
	t.Insert("aa", &d);
	
	EXPECT_EQ(1, t.GetNode("a")->head->m.GetCoeff());
	EXPECT_EQ(2, t.GetNode("aa")->head->m.GetCoeff());
	EXPECT_EQ(3, t.GetNode("aaa")->head->m.GetCoeff());
}

TEST(TableSort, can_delete) {
	SortedTable t;
	Polinom p, d, g;
	p.InsertFirst(Monom(1, 1, 0, 0));
	d.InsertFirst(Monom(2, 2, 0, 0));
	g.InsertFirst(Monom(3, 3, 0, 0));
	t.Insert("aaa", &g);
	t.Insert("a", &p);
	t.Insert("aa", &d);
	t.Delete("aa");

	EXPECT_EQ(1, t.GetNode("a")->head->m.GetCoeff());
	EXPECT_EQ(3, t.GetNode("aaa")->head->m.GetCoeff());
}

TEST(TableSort, can_get_mem) {
	SortedTable t;
	Polinom p, d, g;
	p.InsertFirst(Monom(1, 1, 0, 0));
	string s= "a";
	for (int i = 0; i < 11; i++)
	{
		t.Insert(s, &p);
		s += "a";
	}
	EXPECT_EQ(11, t.GetCountData());
}

TEST(TableSort, can_insert_orderly) {
	SortedTable t;
	Polinom p, d;
	p.InsertFirst(Monom(1, 1, 0, 0));
	d.InsertFirst(Monom(3, 3, 0, 0));
	t.Insert("aaa", &p);
	t.Insert("a",&d);

	EXPECT_EQ(3, t.GetNode("a")->head->m.GetCoeff());
	EXPECT_EQ(1, t.GetNode("aaa")->head->m.GetCoeff());
}

TEST(TableSort, can_insert_orderly_2) {
	SortedTable t;
	Polinom p, d, r;
	p.InsertFirst(Monom(1, 1, 0, 0));
	d.InsertFirst(Monom(2, 3, 0, 0));
	r.InsertFirst(Monom(3, 4, 0, 0));
	t.Insert("aaa", &r);
	t.Insert("a", &p);
	t.Insert("aa", &d);

	EXPECT_EQ(1, t.GetNode("a")->head->m.GetCoeff());
	EXPECT_EQ(2, t.GetNode("aa")->head->m.GetCoeff());
	EXPECT_EQ(3, t.GetNode("aaa")->head->m.GetCoeff()); 
}