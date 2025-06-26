/*
    A pangram is a string that contains every letter of the English alphabet at least once.
*/

#include <iostream>
#include <vector>
#include <string>

std::string is_pangram(const std::string &str) {
    std::vector<bool> visited(26, false);
    
    for(char c: str) {
        if( c >= 'a' && c <= 'z'){
            visited[c - 'a'] = true;
        }else if(c >= 'A' && c <= 'Z') {
            visited[c - 'A'] = true;
        }
    }

    for(int i = 0; i < 26; i++)
        if(visited[i] != true) return "No, It isn\'t a pangram";
    
    return "Yes, It\'s a pangram";
}

int main() {
    std::vector<std::string> phrases = {"The quick brown fox jumps over the lazy dog", "Hello World"};
    for(int i = 0; i < phrases.size(); i++) {
        std::cout << (is_pangram(phrases[i])) << std::endl;
    }

    return 0;
}