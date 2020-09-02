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
        {//如果失配，那么不断回跳，直到可以继续匹配
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j])
        {
            j++;
        }
        if (j == n)
        {
            index_of_found_substring.push_back(i - n + 2);
            j = prefix[j - 1];
        }
    }
    
    return index_of_found_substring;
}

//"前缀"指除了最后一个字符以外，一个字符串的全部头部组合；"后缀"指除了第一个字符以外，一个字符串的全部尾部组合
////prefix_table存放的是最长公共前后缀的长度
void prefix_table(std::string &pattern, int prefix[], size_t size)
{
    prefix[0] = 0;
    int len = 0; //最长公共前后缀的长度
    for (int i = 1; i < size; i++)
    {
        //如果len为0，就不用回跳
        while (pattern[i] != pattern[len] && len != 0)
        {   //不匹配时，将pattern[len]指向前一个截断字符串的最长公共前缀的下一个字符
            //不匹配时，回看前一个截断字符串，它如果有公共前后缀。
            //它的最长公共后缀成为新的匹配字符串(原来的匹配字符串由于不匹配而失效了)的前缀，因为公共前缀等于公共后缀。
            //然后pattern[len]指向最长公共前缀的下一个字符(此时等同于加上了前缀)，继续匹配上一个匹配字符串没能匹配的字符。重复这个过程
            
            len = prefix[len - 1];
        }
        if (pattern[i] == pattern[len])
        {
            len++;
        }
        prefix[i] = len;
    }
}