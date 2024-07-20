#include "list.h"
#include "gtest/gtest.h"


TEST(StringListInit, Test1) {
    char** list;
    StringListInit(list);
    ASSERT_EQ(list[0], (char*) NULL);

    StringListDestroy(list);
}

TEST(StringListDestroy, Test1) {
    char** list;
    StringListInit(list);

    StringListAdd(list, "Hello");
    StringListAdd(list, "World");
    StringListAdd(list, "!");

    StringListDestroy(list);
    ASSERT_EQ(list, (char**) NULL);
}

TEST(StringListAdd, Test1) {
    char** list;
    StringListInit(list);

    StringListAdd(list, "Hello");
    StringListAdd(list, "World");
    StringListAdd(list, "!");

    ASSERT_EQ(strcmp(list[0], "Hello"), 0);
    ASSERT_EQ(strcmp(list[1], "World"), 0);
    ASSERT_EQ(strcmp(list[2], "!"), 0);

    StringListDestroy(list);
}

TEST(StringListRemove, Test1) {
    char** list;
    StringListInit(list);

    StringListAdd(list, "Hello");
    StringListAdd(list, "World");
    StringListAdd(list, "!");
    StringListAdd(list, "Hello");

    StringListRemove(list, "Hello");

    ASSERT_EQ(strcmp(list[0], "World"), 0);
    ASSERT_EQ(strcmp(list[1], "!"), 0);
    ASSERT_EQ(list[2], (char*) NULL);

    StringListDestroy(list);
}

TEST(StringListSize, Test1) {
    char** list;
    StringListInit(list);

    ASSERT_EQ(StringListSize(list), 0);

    StringListAdd(list, "Hello");
    StringListAdd(list, "World");

    ASSERT_EQ(StringListSize(list), 2);

    StringListAdd(list, "!");
    
    ASSERT_EQ(StringListSize(list), 3);

    StringListDestroy(list);
}

TEST(StringListIndexOf, Test1) {
    char** list;
    StringListInit(list);

    StringListAdd(list, "Hello");
    StringListAdd(list, "World");
    StringListAdd(list, "!");
    StringListAdd(list, "World");

    ASSERT_EQ(StringListIndexOf(list, "Hello"), 0);
    ASSERT_EQ(StringListIndexOf(list, "World"), 1);
    ASSERT_EQ(StringListIndexOf(list, "!"), 2);

    StringListDestroy(list);
}

TEST(StringListRemoveDuplicates, Test1) {
    char** list;
    StringListInit(list);

    StringListAdd(list, "Hello");
    StringListAdd(list, "World");
    StringListAdd(list, "!");
    StringListAdd(list, "World");
    StringListAdd(list, "World");
    StringListAdd(list, "Hello");
    StringListAdd(list, "World");
    StringListAdd(list, "Hello");
    StringListAdd(list, "Hello");
    StringListAdd(list, "Goodbye");

    StringListRemoveDuplicates(list);

    ASSERT_EQ(strcmp(list[0], "Hello"), 0);
    ASSERT_EQ(strcmp(list[1], "World"), 0);
    ASSERT_EQ(strcmp(list[2], "!"), 0);
    ASSERT_EQ(strcmp(list[3], "Goodbye"), 0);

    StringListDestroy(list);
}

TEST(StringListReplaceInStrings, Test1) {
    char** list;
    StringListInit(list);

    StringListAdd(list, "Hello Worllod!");
    StringListAdd(list, "World Hello!");
    StringListAdd(list, "Hello!");

    StringListReplaceInStrings(list, "llo", "OK");

    ASSERT_EQ(strcmp(list[0], "HeOK WorOKd!"), 0);
    ASSERT_EQ(strcmp(list[1], "World HeOK!"), 0);
    ASSERT_EQ(strcmp(list[2], "HeOK!"), 0);

    StringListDestroy(list);
}

TEST(StringListSort, Test1) {
    char** list;
    StringListInit(list);

    StringListAdd(list, "Hello");
    StringListAdd(list, "World");
    StringListAdd(list, "Lviv");
    StringListAdd(list, "Kyiv");
    StringListAdd(list, "Kharkiv");
    StringListAdd(list, "Vinnytsia");
    StringListAdd(list, "Alaska");

    StringListSort(list);

    ASSERT_EQ(strcmp(list[0], "Alaska"), 0);
    ASSERT_EQ(strcmp(list[1], "Hello"), 0);
    ASSERT_EQ(strcmp(list[2], "Kharkiv"), 0);
    ASSERT_EQ(strcmp(list[3], "Kyiv"), 0);
    ASSERT_EQ(strcmp(list[4], "Lviv"), 0);
    ASSERT_EQ(strcmp(list[5], "Vinnytsia"), 0);
    ASSERT_EQ(strcmp(list[6], "World"), 0);

    StringListDestroy(list);
}

//pause the system
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
