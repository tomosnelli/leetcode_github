/*
    125. Valid Palindrome
*/
#include "../utils/common.h"

bool isAlphanumeric(char* s)
{
    if (('A' <= *s && *s <= 'Z') || ('a' <= *s && *s <= 'z') || ('0' <= *s && *s <= '9'))
        return true;
    return false;
}

bool isPalindrome(char * s)
{
    int length = strlen(s);
    if(length == 0) return true;

    int i = 0;
    int j = length - 1;

    while(i < j){
        while(i < j && !isalnum(s[i])){
            ++i;
        }

        while(i < j && !isalnum(s[j])){
            --j;
        }

        if(tolower(s[i]) != tolower(s[j])) return false;

        ++i;
        --j;
    }

    return true;

}