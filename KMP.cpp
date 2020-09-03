#include <iostream>
#include <string>
#include <vector>
/* String matching using KMP algorithm */
void prefix_table(std::string &pattern, int prefix[], size_t size);
std::vector<int> kmp_search(std::string &text, std::string &pattern);
int main()
{
    std::string pattern, text;
    std::vector<int> index_of_found_substring;
    std::cin >> text >> pattern;
    index_of_found_substring = kmp_search(text, pattern);
    
    for (auto &&value : index_of_found_substring)
    {
        std::cout << value << ' ';
    }
    
    return 0;
}

std::vector<int> kmp_search(std::string &text, std::string &pattern)
{
    size_t n = pattern.length();
    size_t m = text.length();
    int *prefix = new int[n];
    std::vector<int> index_of_found_substring;
    prefix_table(pattern, prefix, n);

    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j && pattern[j] != text[i])
        {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j])
        {
            j++;
        }
        if (j == n)
        {
            index_of_found_substring.push_back(i - n + 2);
            //等同于执行未匹配的操作
            j = prefix[j - 1];
        }
    }
    
    return index_of_found_substring;
}

void prefix_table(std::string &pattern, int prefix[], size_t size)
{
    prefix[0] = 0;
    int len = 0; //最长公共前后缀的长度
    for (int i = 1; i < size; i++)
    {
        //pattern[len]代表pattern的前缀中正在匹配的字符
        //也因此len为0，就不用回跳
        while (pattern[i] != pattern[len] && len != 0)        
        {   
            len = prefix[len - 1];
            //执行后，pattern[len]的指向改变
        }
        if (pattern[i] == pattern[len])
        {
            len++;
        }
        //prefix存放，字符pattern[0]到字符pattern[i]组成的字符串的最长公共前缀的index的下一位
        prefix[i] = len;
    }
}