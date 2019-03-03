#include "TestMd5GuidGenerator.h"
#include "Md5GuidGenerator.h"

void TestMd5GuidGenerator::SetUp()
{
}

void TestMd5GuidGenerator::TearDown()
{
}

TEST_F(TestMd5GuidGenerator, testGuidFormat)
{
  Md5GuidGenerator gen;
  gen.setProtoFilename("foo.proto");
  gen.setPackage("bar");
  gen.setComponentName("mycomponent");
  gen.setOutputFilename("test");

  //ie: 8ea124e7-bd1a-453d-86b7-6df845e519f7
  std::string guid = gen.newGuid();
  ASSERT_EQ(36, guid.size());
  ASSERT_EQ('-', guid[8]);
  ASSERT_EQ('-', guid[13]);
  ASSERT_EQ('4', guid[14]);
  ASSERT_EQ('-', guid[18]);
  ASSERT_EQ('-', guid[23]);
}

TEST_F(TestMd5GuidGenerator, testRepetition)
{
  Md5GuidGenerator gen;
  gen.setProtoFilename("foo.proto");
  gen.setPackage("bar");
  gen.setComponentName("mycomponent");
  gen.setOutputFilename("test");

  std::string guidBase = gen.newGuid();
  for(int i=0; i<100; i++)
  {
    std::string tmpGuid = gen.newGuid();
    ASSERT_EQ(guidBase, tmpGuid);
  }
}
