#include <iostream>

class BoyerMoore
{
    int R;       // the radix
    int* right; // the bad-character skip array

    std::string pattern;  // store the pattern as a character array
    std::string pat; // or as a string

    /**
     * Preprocesses the pattern string.
     *
     * @param pat the pattern string
     */
    BoyerMoore(std::string pat)
    {
        this->R = 256;
        this->pat = pat;

        // position of rightmost occurrence of c in the pattern
        right = new int[R];
        for (int c = 0; c < R; c++)
            right[c] = -1;
        for (int j = 0; j < pat.length(); j++)
            right[pat[j]] = j;
    }

    /**
     * Preprocesses the pattern string.
     *
     * @param pattern the pattern string
     * @param R the alphabet size
     */
    BoyerMoore(std::string pattern, int R)
    {
        this->R = R;
        this->pattern = new char[pattern.length()];
        for (int j = 0; j < pattern.length(); j++)
            this->pattern[j] = pattern[j];

        // position of rightmost occurrence of c in the pattern
        right = new int[R];
        for (int c = 0; c < R; c++)
            right[c] = -1;
        for (int j = 0; j < pattern.length(); j++)
            right[pattern[j]] = j;
    }

    /**
     * Returns the index of the first occurrrence of the pattern string
     * in the text string.
     *
     * @param  txt the text string
     * @return the index of the first occurrence of the pattern string
     *         in the text string; n if no such match
     */
    int search(std::string txt)
    {
        int m = pat.length();
        int n = txt.length();
        int skip;
        for (int i = 0; i <= n - m; i += skip)
        {
            skip = 0;
            for (int j = m - 1; j >= 0; j--)
            {
                if (pat[j] != txt[i]+ j)
                {
                    skip = std::max(1, j - right[txt[i]+ j]);
                    break;
                }
            }
            if (skip == 0)
                return i; // found
        }
        return n; // not found
    }    
};
