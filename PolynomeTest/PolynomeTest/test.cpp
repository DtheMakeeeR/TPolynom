#include "pch.h"
#include "../../TPolynom/Polynome.h"
#include "../../TPolynom/Polynome.cpp"
#include "../../TPolynom/Monome.h"
#include "../../TPolynom/Monome.cpp"
TEST(TPolynome, AddMonome_back_del) {
	Monome m1[3] = { Monome(1, 2, 1, 1), Monome(-3, 1, 0, 0), Monome(4, 0, 2, 1) };
	Monome m2[3] = { Monome(1, 2, 1, 1), Monome(-3, 1, 0, 0) };
	Monome m3[3] = { Monome(-1, 2, 1, 1), Monome(-3, 1, 0, 0), Monome(4, 0, 3, 1) };
	Polynome p1(m1, 3), res(m2, 2);
	Monome monome(-4, 0, 2, 1);
	p1.AddMonome(monome);
	EXPECT_EQ(p1, res);
}
TEST(TPolynome, AddPolynomeToMid) {
	Monome m1[2] = { Monome(1, 3, 1, 1), Monome(-3, 2, 3, 0) };
	Monome m2[2] = { Monome(1, 3, 0, 0), Monome(-3, 0, 1, 1) };
	Monome m3[4] = { Monome(1, 3, 1, 1), Monome(1, 3, 0, 0), 
					 Monome(-3, 2, 3, 0),Monome(-3, 0, 1, 1) };
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 4);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, AddPolynomeWithDelInMid) {
	Monome m1[2] = { Monome(1, 3, 1, 1), Monome(-3, 2, 3, 0) };
	Monome m2[2] = { Monome(3, 2, 3, 0), Monome(-3, 0, 1, 1) };
	Monome m3[2] = { Monome(1, 3, 1, 1), Monome(-3, 0, 1, 1) };
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 2);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, AddPolynomeWithDelInFront) {
	Monome m1[2] = { Monome(1, 3, 1, 1),  Monome(-3, 2, 3, 0)};
	Monome m2[2] = { Monome(-1, 3, 1, 1), Monome(-3, 0, 1, 1)};
	Monome m3[2] = { Monome(-3, 2, 3, 0), Monome(-3, 0, 1, 1)};
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 2);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, AddPolynomeWithDelInBack) {
	Monome m1[2] = { Monome(1, 3, 1, 1), Monome(-3, 2, 3, 0) };
	Monome m2[2] = { Monome(3, 2, 3, 0), Monome(1, 2, 1, 1) };
	Monome m3[2] = { Monome(1, 3, 1, 1), Monome(1, 2, 1, 1), };
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 2);
	res = p1 + p2 ;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, AddPolynomeWithMergeInMid) {
	Monome m1[2] = { Monome(1, 3, 1, 1), Monome(3, 2, 3, 0) };
	Monome m2[2] = { Monome(3, 2, 3, 0), Monome(1, 2, 1, 1) };
	Monome m3[3] = { Monome(1, 3, 1, 1), Monome(6, 2, 3, 0), Monome(1, 2, 1, 1)};
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, AddPolynomeWithMergeInFront) {
	Monome m1[2] = { Monome(1, 3, 1, 1), Monome(3, 2, 3, 0) };
	Monome m2[2] = { Monome(-2, 3, 1, 1), Monome(1, 2, 1, 1) };
	Monome m3[3] = { Monome(-1, 3, 1, 1), Monome(3, 2, 3, 0), Monome(1, 2, 1, 1) };
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, AddPolynomeWithMergeInBack) {
	Monome m1[2] = { Monome(1, 3, 1, 1), Monome(3, 2, 3, 0) };
	Monome m2[2] = { Monome(-2, 3, 1, 0), Monome(1, 2, 3, 0) };
	Monome m3[3] = { Monome(1, 3, 1, 1), Monome(-2, 3, 1, 0), Monome(4, 2, 3, 0) };
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, AddPolynome) {//1 del  2 merge 3 ne peresek
	Monome m1[3] = { Monome(1, 3, 1, 1),  Monome(-3, 2, 3, 0), Monome(4, 1, 2, 1) };
	Monome m2[3] = { Monome(-1, 3, 1, 1), Monome(-3, 2, 3, 0), Monome(4, 0, 0, 1) };
	Monome m3[3] = { Monome(-6, 2, 3, 0), Monome(4, 1, 2, 1),  Monome(4, 0, 0, 1) };
	Polynome p1(m1, 3), p2(m2, 3), res, expect(m3, 3);
	res = p1 + p2;
	EXPECT_EQ(res, expect);
	res = p2 + p1;
	EXPECT_EQ(res, expect);
}
//6*x^5*y^5*z^3 +3*x^4*y^4*z^4 +4*x^2*y^2 +2*x^1*y^1*z^1 p6 * p7
TEST(TPolynome, MultPolynome) {
	Monome m1[2] = { Monome(2, 2, 2, 0), Monome(1, 1, 1, 1) };
	Monome m2[2] = { Monome(3, 3, 3, 3), Monome(2) };
	Monome m3[4] = { Monome(6, 5, 5, 3), Monome(3, 4, 4, 4),
					 Monome(4, 2, 2, 0), Monome(2, 1, 1, 1) };
	Polynome p1(m1, 2), p2(m2, 2), res, expect(m3, 4);
	res = p1 * p2;
	EXPECT_EQ(res, expect);
	res = p2 * p1;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, MultOnInt) {
	Monome m1[2] = { Monome(3, 3, 3, 3), Monome(2) };
	Monome m2[2] = { Monome(6, 3, 3, 3), Monome(4) };
	Polynome p1(m1, 2), res, expect(m2, 2);
	res = p1 * 2;
	EXPECT_EQ(res, expect);
}
TEST(TPolynome, MultOnZero) {
	Monome m1[2] = { Monome(3, 3, 3, 3), Monome(2) };
	Polynome p1(m1, 2), res, expect;
	res = p1 * 0;
	EXPECT_EQ(res, expect);
}
//TEST(TPolynome, TestName) {
//	EXPECT_EQ(1, 1);
//	EXPECT_TRUE(true);
//}
//TEST(TPolynome, TestName) {
//	EXPECT_EQ(1, 1);
//	EXPECT_TRUE(true);
//}
//TEST(TPolynome, TestName) {
//	EXPECT_EQ(1, 1);
//	EXPECT_TRUE(true);
//}
//TEST(TPolynome, TestName) {
//	EXPECT_EQ(1, 1);
//	EXPECT_TRUE(true);
//}
//TEST(TPolynome, TestName) {
//	EXPECT_EQ(1, 1);
//	EXPECT_TRUE(true);
//}