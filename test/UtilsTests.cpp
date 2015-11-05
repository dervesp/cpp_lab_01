#include "stdafx.h"
#include "Utils.h"

/*
��� ����������,
    ���� �� ������� �� 4
    ���� ��� ���� �� �� ������� �� 100
	�� ������� �� 400
*/

BOOST_AUTO_TEST_SUITE(Leap_year)
	BOOST_AUTO_TEST_CASE(Leap_year_is_divisible_by_4)
	{
		BOOST_CHECK(IsLeapYear(2004));
		BOOST_CHECK(!IsLeapYear(2005));
		BOOST_CHECK(!IsLeapYear(2006));
		BOOST_CHECK(!IsLeapYear(2007));
	}
	BOOST_AUTO_TEST_CASE(if_is_not_divisible_by_100)
	{
		BOOST_CHECK(!IsLeapYear(1900));
	}
	BOOST_AUTO_TEST_CASE(is_divisible_by_400)
	{
		BOOST_CHECK(IsLeapYear(2000));
	}
BOOST_AUTO_TEST_SUITE_END();