#include <iostream>
using namespace std;

// Convert a character to lowercase
char toLowercase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        // converting to lowercase by adjusting the ASCII value and return it
        return c + ('a' - 'A');
    }
    // returns the character unchanged
    return c;
}

// Check if a character is letter or a number
bool isAlphanumeric(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

// Function to check if a string is a palindrome
bool isPalindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // skip if not alphanumeric frin left
        while (left < right && !isAlphanumeric(s[left]))
        {
            left++;
        }
        // skip if not alphanumeric from right
        while (left < right && !isAlphanumeric(s[right]))
        {
            right--;
        }

        // Compare characters case insensitively
        // check the character are different if they are return false
        if (toLowercase(s[left]) != toLowercase(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // Use getline to handle spaces and punctuation

    if (isPalindrome(str))
        cout << "\"" << str << "\"  is a palindrome." << endl;
    else
        cout << "\"" << str << "\"  is not a palindrome." << endl;

    return 0;
}
