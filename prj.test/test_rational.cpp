#include<rational/rational.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


TEST_CASE("rational tests") {
	Rational r_def;
	CHECK(0 == r_def.c());
	CHECK(1 == r_def.z());

	Rational r(3,5);
	CHECK(3 == r.c());
	CHECK(5 == r.z());


	Rational r1(2, 5);
	Rational r2(3, 5);
	r = r1 + r2;
	CHECK(r.c() == 1);
	CHECK(r.z() == 1);
	r = r1 - r2;
	CHECK(r.c() == -1);
	CHECK(r.z() == 5);
	r = r1 * r2;
	CHECK(r.c() == 6);
	CHECK(r.z() == 25);
	r = r1 / r2;
	CHECK(r.c() == 2);
	CHECK(r.z() == 3);


	r1 -= r2;
	CHECK(r1.c() == -1);
	CHECK(r1.z() == 5);
	r1 += r2;
	CHECK(r1.c() == 2);
	CHECK(r1.z() == 5);
	r1 *= r2;
	CHECK(r1.c() == 6);
	CHECK(r1.z() == 25);
	r1 /= r2;
	CHECK(r1.c() == 2);
	CHECK(r1.z() == 5);

	CHECK((r1 < r2) == 1);
	CHECK((r1 <= r2) == 1);
	CHECK((r1 > r2) == 0);
	CHECK((r1 >= r2) == 0);
	CHECK((r1 == r2) == 0);
	CHECK((r1 != r2) == 1);
	
	r1 = r2;
	CHECK(r1.c() == 3);
	CHECK(r1.z() == 5);

	Rational r3(2, 5);
	Rational r4(4, 10);
	CHECK((r3 == r4) == 1);
	CHECK((r3 != r4) == 0);
}