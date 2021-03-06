#include "configTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(ConfigTest);

void ConfigTest::TestValuesRange(void) {
	CPPUNIT_ASSERT(SZ_BLOCKSIZE > 5);
	CPPUNIT_ASSERT(SZ_SCREENWIDTH < 16384 && SZ_SCREENWIDTH > 0);
	CPPUNIT_ASSERT(SZ_SCREENHEIGHT < 16384 && SZ_SCREENHEIGHT > 0);

	CPPUNIT_ASSERT(SZ_INFOSWIDTH + SZ_MAINWIDTH <= SZ_SCREENWIDTH);
}