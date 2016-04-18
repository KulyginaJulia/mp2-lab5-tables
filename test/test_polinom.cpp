#include <gtest.h>
#include "polinom.h"
#include "monom.h"
#include <iostream>
// тесты мономов и полиномов


TEST(Monom, Can_create_monom){
	ASSERT_NO_THROW(Monom m(0.5, 1, 1, 1));
}
TEST(Monom, Create_monom_with_negative_degree){
	ASSERT_ANY_THROW(Monom m(3.5, 1, -8, 1));
}
TEST(Monom, Can_copy_monom){
	Monom m1(3, 1, 1, 1);
	ASSERT_NO_THROW(Monom m2(m1));
}

TEST(Monom, can_set_and_get) {
 	int d[3];
	double c = 0;
	Monom m(c, d);
 	m.SetCoeff(10);
	d[0] = 1;
	d[1] = 0;
	d[2] = 1;
 	m.SetDegree(d);
 
 	EXPECT_EQ(10, m.GetCoeff());
 }
 TEST(Monom, can_check_equality)
 {
 	Monom a(1, 1, 2, 3);
 	Monom b(1, 1, 2, 3);
 	EXPECT_EQ(1, a == b);
 }
 TEST(Monom, can_check_noy_equality_degree) {
 	Monom a(1, 1, 0, 0);
 	Monom b(1, 1, 2, 3);
 	EXPECT_NE(1 , a == b);
 }
 
 TEST(Monom, can_compare_no_equality_monoms_by_degree) {
 	Monom a(1, 1, 0, 0);
 	Monom b(1, 1, 2, 3);
 	EXPECT_TRUE(a < b);
 	EXPECT_FALSE(a > b);
 }
 
 TEST(Monom, can_add_monoms) {
 	Monom a(1, 1, 0, 0);
 	Monom b(2, 1, 0, 0);
 	Monom c = a + b;
 	EXPECT_EQ(3, c.GetCoeff());
 }

TEST(Monom, can_multiply) {
	Monom a(3, 1, 0, 0);
	Monom b(2, 1, 0, 0);
	Monom c = a * b;
	EXPECT_EQ(6, c.GetCoeff());
}

TEST(Monom, can_not_multiply_whith_large_degrees) {
	Monom a(3, 9, 0, 1);
	Monom b(2, 1, 0, 9);
	Monom c;
	ASSERT_ANY_THROW(c = a * b);
}

TEST(Node, Can_create_node){
	ASSERT_NO_THROW(new Node);
}

TEST(Node, Can_create_node_with_monom){
	Monom m(1.5 , 0, 0 , 0 );

	ASSERT_NO_THROW(new Node(m));
}
TEST(Node, Can_copy_node){
	Monom m1(3, 1, 1, 1);
	Node n1(m1);

	ASSERT_NO_THROW(new Node(n1));
}

TEST(Polinom, Can_create_polinom){
	ASSERT_NO_THROW(Polinom p);
}
TEST(Polinom, Can_create_polinom_with_parametres){
	Node *head = 0;
	ASSERT_ANY_THROW(Polinom p(head));
}
TEST(Polinom, Can_copy_polinom){
	Polinom p;
	p.InsertFirst(Monom(2, 2, 0, 0));
	p.InsertFirst(Monom(1, 1, 0, 0));
	Polinom p1(p);
	EXPECT_EQ(p1.head->m, p.head->m);
	EXPECT_EQ(p1.head->next->m, p.head->next->m);
	EXPECT_EQ(p1.head->m.coeff, p.head->m.coeff);
	EXPECT_EQ(p1.head->next->m.coeff, p.head->next->m.coeff);
}
TEST(Polinom, Can_equal_polinom){
	Polinom p;
	p.InsertFirst(Monom(2, 3, 2, 1));
	p.InsertFirst(Monom(1, 1, 0, 0));
	Polinom p1;
	p1.InsertFirst(Monom(1, 0, 0, 0));
	p1 = p;

	EXPECT_EQ(p1.head->m, p.head->m);
	EXPECT_EQ(p1.head->next->m, p.head->next->m);
	EXPECT_EQ(p1.head->m.coeff, p.head->m.coeff);
	EXPECT_EQ(p1.head->next->m.coeff, p.head->next->m.coeff);
}
TEST(Polinom, Can_delete_list){
	Polinom p;
	ASSERT_NO_THROW(p.DeleteList());
}
TEST(Polinom, Can_not_insert_first_monom_as_last){
	Monom m1(3, 1, 1, 1);
	Monom m2(5.4, 2, 1, 1);
	Node n1(m1);
	Polinom p;

	ASSERT_ANY_THROW(p.InsertLast(p.head, m1));
}


TEST(Polinom, Can_insert_monom_first){
	Monom m1(3, 1, 1, 1);
	Node n1(m1);
	Polinom p;
	p.InsertFirst(m1);

	EXPECT_EQ(m1, p.head->m);
}
TEST(Polinom, Can_insert_monom_last){
	Monom m1(3, 1, 1, 1);
	Monom m2(5.4, 2, 1, 1);
	Polinom p;
	p.InsertFirst(m1);
	Node *curr = p.head;
	
	p.InsertLast(curr, m2);
	EXPECT_EQ(5.4, p.head->next->m.coeff);
}
TEST(Polinom, Can_insert_monom_middle){
	Monom m1(3, 1, 1, 1);
	Monom m2(5.4, 2, 1, 1);
	Monom m3(5.8, 2, 1, 1);
	Polinom p;
	p.InsertFirst(m3);
	p.InsertFirst(m1);

	p.InsertMiddle(p.head, m2);
	EXPECT_EQ(m2.coeff, p.head->next->m.coeff);
}

TEST(Polinom, can_plus) {
	Polinom a;
	a.InsertFirst(Monom(2, 2, 0, 0));
	a.InsertFirst(Monom(2, 1, 0, 0));
	Polinom b;
	b.InsertFirst(Monom(1, 2, 0, 0));
	b.InsertFirst(Monom(4, 1, 0, 0));
	Polinom c;
	
	c = a + b;

	EXPECT_EQ(6, c.head->m.coeff);
	EXPECT_EQ(3, c.head->next->m.coeff);
}

TEST(Polinom, can_minus) {
	Polinom a;
	a.InsertFirst(Monom(2, 2, 0, 0));
	a.InsertFirst(Monom(2, 1, 0, 0));
	Polinom b;
	b.InsertFirst(Monom(4, 2, 0, 0));
	b.InsertFirst(Monom(1, 1, 0, 0));
	Polinom c;

	c = a - b;

	EXPECT_EQ(1, c.head->m.coeff);
	EXPECT_EQ(-2, c.head->next->m.coeff);
}

TEST(Polinom, can_multiply_polinom_monom){
	Polinom a;
	a.InsertFirst(Monom(1.5, 1, 0, 0));
	a.InsertFirst(Monom(2.5, 2, 0, 0));
	Monom b(2.0, 1, 0, 0);
	Polinom c;

	c = a * b;

	EXPECT_EQ(5, c.head->m.coeff);
	EXPECT_EQ(3, c.head->next->m.coeff);
}
TEST(Polinom, can_multiply_polinom_with_polinom){
	Polinom a;
	a.InsertFirst(Monom(2, 3, 0, 0));
	a.InsertFirst(Monom(1, 1, 0, 0));
	Polinom b(a);
	Polinom c(a*b);


	EXPECT_EQ(1, c.head->m.coeff);
	EXPECT_EQ(4, c.head->next->m.coeff);
	EXPECT_EQ(4, c.head->next->next->m.coeff);

	EXPECT_EQ(2, c.head->m.deg[0]);
	EXPECT_EQ(4, c.head->next->m.deg[0]);
	EXPECT_EQ(6, c.head->next->next->m.deg[0]);
}
