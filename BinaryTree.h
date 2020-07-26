#ifndef _BinaryTree_h_
#define _BinaryTree_h_
#include <iostream>
#include <queue>
#include <string>

template <typename Key, typename Value>
struct BinaryTreeNode
{
public:
    Key key;
    Value val;
    BinaryTreeNode *left, *right;
    int N;

    BinaryTreeNode(Key key, Value val, int N);
    BinaryTreeNode();
};

template <typename Key, typename Value>
BinaryTreeNode<Key, Value>::BinaryTreeNode(Key key, Value val, int N)
{
    this->key = key;
    this->val = val;
    this->N = N;
    this->left = NULL;
    this->right = NULL;
}

template <typename Key, typename Value>
BinaryTreeNode<Key, Value>::BinaryTreeNode()
{
    this->left = NULL;
    this->right = NULL;
}

template <typename Key, typename Value>
class BinaryTree
{
    typedef struct BinaryTreeNode<Key, Value> Node;

private:
    Node * root;

    int size(Node * x)
    {
        if (x == NULL)
        {
            return 0;
        }
        else
        {
            return x->N;
        }
    }
    //如果有key对应的Node则覆盖它的值，无则在树的底部创建。
    Node * put(Node * x, Key key, Value val)
    {
        if (x == NULL)
        {
            return new Node(key, val, 1);
        }
        Key cmp = key - x->key;
        if (cmp < 0)
        {
            x->left = put(x->left, key, val);
        }
        else if (cmp > 0)
        {
            x->right = put(x->right, key, val);
        }
        else
        {
            x->val = val;
        }
        //有的Node只有左右子树中的一个，要判断指针的validity
        //创建了新节点，或是没有，size(left) + size(right) + 1都适用
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Value get(Node * x, Key key)
    {
        if (x == NULL)
        {
            return NULL;
        }

        Key cmp = key - x->key;
        if (cmp < 0)
        {
            return get(x->left, key);
        }
        else if (cmp > 0)
        {
            return get(x->right, key);
        }
        else
        {
            return x->val;
        }
    }

    Node * min(Node * x)
    {
        if (x->left == NULL)
        {
            return x;
        }
        return min(x->left);
    }

    Node * max(Node * x)
    {
        if (x->right == NULL)
        {
            return x;
        }
        return max(x->right);
    }

    //比较大小进入对应的子树
    Node * floor(Node * x, Key key)
    {
        //二叉树的性质: 一个父节点的值是左(右)子树的最大(小)值。
        //只要子树不为NULL，查找过程中就不需要考虑上方节点。
        if (x == NULL)
        {
            //子树无法向下后会结束。
            //返回值由递归中的Node t决定(保存的小于键值的最大键值的节点)
            return NULL;
        }
        Key cmp = key - x->key;
        if (cmp == 0)
        {
            //找到完全对应的节点的情况
            return x;
        }
        else if (cmp < 0)
        {
            //进入左子树查找
            return floor(x->left, key);
        }
        //进入右子树查找
        Node * t = floor(x->right, key);

            if (t != NULL)
        {
            //直接找到了对应节点
            return t;
        }
        else
        {
            //返回保存的小于键值的最大键值的节点
            return x;
        }
    }
    Node * ceiling(Node * x, Key key)
    {
        //二叉树的性质: 一个父节点的值是左(右)子树的最大(小)值。
        //只要子树不为NULL，查找过程中就不需要考虑上方节点。
        if (x == NULL)
        {
            //子树无法向下后会结束。
            //返回值由递归中的Node t决定(保存的大于键值的最小键值的节点)
            return NULL;
        }
        Key cmp = key - x->key;
        if (cmp == 0)
        {
            //找到完全对应的节点的情况
            return x;
        }
        else if (cmp > 0)
        {
            //进入左子树查找
            return ceiling(x->right, key);
        }
        //进入右子树查找
        Node * t = ceiling(x->left, key);

            if (t != NULL)
        {
            //直接找到了对应节点
            return t;
        }
        else
        {
            //返回保存的大于键值的最小键值的节点
            return x;
        }
    }

    Node * select(Node * x, int k)
    {
        //返回排名为k的结点
        if (x == NULL)
        {
            return NULL;
        }
        int t = size(x->left);
        if (t > k)
        {
            return select(x->left, k);
        }
        else if (t < k)
        {
            return select(x->right, k - t - 1);
        }
        else
        {
            return x;
        }
    }

    int rank(Key key, Node * x)
    {
        //返回以x为根节点的子树中小于x.key的键的数量
        if (x == NULL)
        {
            return 0;
        }
        Key cmp = key - x->key;
        if (cmp < 0)
        {
            return rank(key, x->left);
        }
        else if (cmp > 0)
        {
            return 1 + size(x->left) + rank(key, x->right);
        }
        else
        {
            return size(x->left);
        }
    }

    Node * deleteMin(Node * x)
    {
        if (x->left == NULL)
        {
            Node * temp = x->right;
            delete x;
            return temp;
        }
        x->left = deleteMin(x->left);
        //这条路径上的节点N全部更新
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node * deleteMax(Node * x)
    {
        if (x->right == NULL)
        {
            Node * temp = x->left;
            delete x;
            return temp;
        }
        x->right = deleteMax(x->right);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }

    Node * deletenode(Node * x, Key key)
    {
        if (x == NULL)
            return NULL;
        int cmp = key - x->key;
        if (cmp < 0)
            x->left = deletenode(x->left, key);
        else if (cmp > 0)
            x->right = deletenode(x->right, key);
        else
        {
            Node * t;
            if (x->right == NULL)
            {
                t = x->left;
                delete x;
                return t;
            }
            if (x->left == NULL)
            {
                t = x->right;
                delete x;
                return t;
            }
            t = x;
            x = min(t.right);
            x->right = deleteMin(t.right);
            x->left = t.left;
        }
        x->size = size(x->left) + size(x->right) + 1;
        return x;
    }

    void keys(Node * x, std::queue<Key> queue, Key lo, Key hi)
    {

        if (x == NULL)
            return;
        int cmplo = lo - x->key;
        int cmphi = hi - x->key;
        //二叉树查找找到遍历起始节点，遍历lo和hi取值范围内的节点，并储存了每一个节点，和判断是否在范围内
        if (cmplo < 0)
            keys(x->left, queue, lo, hi);
        if (cmplo <= 0 && cmphi >= 0)
            queue.enqueue(x->key);
        if (cmphi > 0)
            keys(x->right, queue, lo, hi);
    }

public:
    Key min() { return min(root).key; }
    Key max() { return max(root).key; }
    int size() { return size(this->root); }
    Value get(Key key) { return get(root, key); }
    void put(Key key, Value val) { root = put(root, key, val); }
    Key select(int k) { return select(root, k).key; }
    int rank(Key key) { return rank(key, root); }
    void deleteMin() { root = deleteMin(root); }
    void deleteMax() { root = deleteMax(root); }
    void deletenode(Key key) { root = delete (root, key); }
    bool isEmpty() { return root == NULL; }

    std::queue<Key> keys()
    {
        if (isEmpty())
            return new std::queue<Key>();
        return keys(min(), max());
    }

    std::queue<Key> keys(Key lo, Key hi)
    {
        try
        {
            if (lo == NULL)
                throw new std::string("first argument to keys() is NULL");
            if (hi == NULL)
                throw new std::string("second argument to keys() is NULL");
        }
        catch (const std::string msg)
        {
            std::cerr << msg << '\n';
        }

        auto queue = new std::queue<Key>();
        keys(root, queue, lo, hi);
        return queue;
    }

    BinaryTree(){this->root = NULL;}
    ~BinaryTree(){}

    Key floor(Key key)
    {
        Node * x = floor(root, key);
        if (x == NULL)
        {
            return NULL;
        }
        return x->key;
    }
    Key ceiling(Key key)
    {
        Node * x = ceiling(root, key);
        if (x == NULL)
        {
            return NULL;
        }
        return x->key;
    }
};

/**
     * Removes the smallest key and associated value from the symbol table.
     *
     * @throws NoSuchElementException if the symbol table is empty
     */

/**
     * Removes the largest key and associated value from the symbol table.
     *
     * @throws NoSuchElementException if the symbol table is empty
     */

/**
     * Removes the specified key and its associated value from this symbol table     
     * (if the key is in this symbol table).    
     *
     * @param  key the key
     * @throws IllegalArgumentException if {@code key} is {@code NULL}
     */

/**
     * Returns all keys in the symbol table as an {@code Iterable}.
     * To iterate over all of the keys in the symbol table named {@code st},
     * use the foreach notation: {@code for (Key key : st.keys())}.
     *
     * @return all keys in the symbol table
     */

/**
     * Returns all keys in the symbol table in the given range,
     * as an {@code Iterable}.
     *
     * @param  lo minimum endpoint
     * @param  hi maximum endpoint
     * @return all keys in the symbol table between {@code lo} 
     *         (inclusive) and {@code hi} (inclusive)
     * @throws IllegalArgumentException if either {@code lo} or {@code hi}
     *         is {@code NULL}
     */
#endif