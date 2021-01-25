#include "BinaryTree.h"
#define cerr(msg) std::cerr << "[" << __FILE__ << ": at " << __LINE__ << " line: " << msg << "]"
#define EXPECT_EQ_BASE(equality, expect, actual, format)                                                           \
    do                                                                                                             \
    {                                                                                                              \
        test_count++;                                                                                              \
        if (equality)                                                                                              \
            test_pass++;                                                                                           \
        else                                                                                                       \
        {                                                                                                          \
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual); \
            main_ret = 1;                                                                                          \
        }                                                                                                          \
    } while (0)
#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")
static int test_pass = 0;
static int test_count = 0;
static int main_ret = 0;

int main()
{
    auto tree = new BinaryTree<int, int>();
    int nums[] = {1, 1, 2, 3, 3, 4, 4, 5,6, 7, 8, 9 , 10, 11, 11, 12, 12,321,235,35};
    tree->put(1, 10);
    EXPECT_EQ_INT(10, tree->get(1));
    tree->deletenode(1);
    EXPECT_EQ_INT(true, tree->isEmpty());
    for (size_t i = 0; i < 20; i++)
    {
        tree->put(nums[i], nums[i]);
    }
    EXPECT_EQ_INT(321, tree->max());
    tree->deleteMax();
    EXPECT_EQ_INT(235, tree->max());
    EXPECT_EQ_INT(14, tree->size());
    EXPECT_EQ_INT(35, tree->ceiling(20));
    EXPECT_EQ_INT(35, tree->floor(36));
    printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    return 0;
}
