#include <iostream>
#include <string>
#include <vector>
/* std::string matching using KMP algorithm */
void prefix_table(std::string &pattern, int prefix[], size_t size);
std::vector<int> kmp_search(std::string &text, std::string &pattern);
int main()
{
    std::string pattern, text;
    std::vector<int> index_found; //找到的子字串索引
    std::cin >> text >> pattern;
    index_found = kmp_search(text, pattern);

    for (auto &&value : index_found)
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
    std::vector<int> index_found;
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
            index_found.push_back(i - n + 2);
            //等同于执行未匹配的操作
            j = prefix[j - 1];
        }
    }

    return index_found;
}

void prefix_table(std::string &pattern, int prefix[], size_t size)
{
    prefix[0] = 0;
    int len = 0; //最长公共前后缀的长度
    for (int i = 1; i < size; i++)
    {
        //pattern[len]代表pattern的前缀中正在匹配的字符
        while (pattern[i] != pattern[len] && len != 0)
        {
            len = prefix[len - 1];
            //执行后，pattern[len]的指向改变
        }
        if (pattern[i] == pattern[len])
        {
            len++;
        }
        //prefix[i]存放，字符pattern[0]到字符pattern[i]组成的字符串,的最长公共前缀,的index的下一位
        prefix[i] = len;
    }
}
/*
int **dfa(std::string pat)
{
    int R = 256;
    int m = pat.length();

    // build DFA from pattern
    int **dfa = new int *[R];
    for (int i = 0; i < R; ++i)
        dfa[i] = new int[m];
    dfa[pat[0]][0] = 1;
    for (int x = 0, j = 1; j < m; j++)
    {
        for (int c = 0; c < R; c++)
            dfa[c][j] = dfa[c][x]; // Copy mismatch cases.
        dfa[pat[j]][j] = j + 1;    // Set match case.
        x = dfa[pat[j]][x];        // Update restart state.
    }
    return dfa;
}


std::vector<int> KMP(std::string txt, std::string pat)
{
    std::vector<int> index_found;
    // simulate operation of DFA on text
    int n = txt.length();
    int m = pat.length();
    int **DFA = dfa(pat);
    int i, j;
    for (i = 0, j = 0; i < n && j < m; i++)
    {
        j = DFA[txt[i]][j];
    }
    if (j == m)
        return i - m; // found
    return n;         // not found
}



int main(char *argv[], int argc)
{

    std::string pat = argv[0];
    std::string txt = argv[1];
    std::string pattern = pat.toCharArray();
    std::string text = txt.toCharArray();

    KMP kmp1 = new KMP(pat);
    int offset1 = kmp1.search(txt);

    KMP kmp2 = new KMP(pattern, 256);
    int offset2 = kmp2.search(text);

    // print results
    StdOut.println("text:    " + txt);

    StdOut.print("pattern: ");
    for (int i = 0; i < offset1; i++)
        StdOut.print(" ");
    StdOut.println(pat);

    StdOut.print("pattern: ");
    for (int i = 0; i < offset2; i++)
        StdOut.print(" ");
    StdOut.println(pat);
}
}*/