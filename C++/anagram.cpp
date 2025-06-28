/*
    An anagram is a word or phrase formed by rearranging the letters
    of a different word or phrase, typically using all the original letters exactly once.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool is_anagram_by_sorting(std::string str, std::string str2)
{
    int size_str1 = str.length();
    int size_str2 = str2.length();

    if (size_str1 != size_str2)
        return false;

    std::sort(str.begin(), str.end());
    std::sort(str2.begin(), str2.end());
    // std::cout << str.begin() << std::endl;
    for (int i = 0; i < size_str1; i++)
        if (str[i] != str2[i])
            return false;

    return true;
}

bool is_anagram_count_array(const std::string &str, const std::string &str2)
{
    int size_str1 = str.length();
    int size_str2 = str2.length();

    if (size_str1 != size_str2)
        return false;

    std::vector<int> ASCII(256, 0);

    for (int c : str)
        ASCII[c]++;

    for (int c : str2)
        ASCII[c]--;

    for (int i = 0; i < 256; i++)
        if (ASCII[i] != 0)
            return false;

    return true;
}

int main()
{
    std::vector<std::string> str1 = {"silent", "triangle", "abc"};
    std::vector<std::string> str2 = {"listen", "integral", "cdb"};

    for (int i = 0; i < str1.size(); i++)
    {
        // bool res = is_anagram_by_sorting(str1[i], str2[i]);
        bool res = is_anagram_count_array(str1[i], str2[i]);
        std::cout << (res ? "This is an anagram" : "This isn\'t an anagram") << std::endl;
    }

    return 0;
}