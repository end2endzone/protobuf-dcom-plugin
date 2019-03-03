#include "TestDcomFunctions.h"
#include "dcom.h"
#include "stringfunc.h"

void TestDcomFunctions::SetUp()
{
}

void TestDcomFunctions::TearDown()
{
}

TEST_F(TestDcomFunctions, testNewGuid)
{
  //ie: 8ea124e7-bd1a-453d-86b7-6df845e519f7
  std::string guid = newGuid();

  ASSERT_EQ(36, guid.size());
  ASSERT_EQ('-', guid[ 8]);
  ASSERT_EQ('-', guid[13]);
  ASSERT_EQ('-', guid[18]);
  ASSERT_EQ('-', guid[23]);
  ASSERT_EQ('4', guid[14]);

  //assert all lowercase
  ASSERT_TRUE(lowercase(guid) == guid);
}
