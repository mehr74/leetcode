class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1)
            return "";
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int i = 0; i < palindrome.size() / 2; i++) {
                if (palindrome[i] > ch) {
                    palindrome[i] = ch;
                    return palindrome;
                }
            }
            for (int i = palindrome.size() - 1; i >= palindrome.size() / 2; i--) {
                if (palindrome.size() % 2 == 1 && i == palindrome.size() / 2)
                    continue;
                if (palindrome[i] < ch) {
                    palindrome[i] = ch;
                    return palindrome;
                }
            }
        }
        return "";
    }
};
