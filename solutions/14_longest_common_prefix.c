/*
    14. Longest Common Prefix
*/
#include "../utils/common.h"

char * longestCommonPrefix(char ** strs, int strsSize)
{
    int count = strlen(strs[0]);

    for(int i = 1; i < strsSize; ++i){
        int temp = 0;
        char* prev_str = strs[i-1];
        char* str = strs[i];

        if(prev_str[0] != str[0]) return "";

        while((*str != '\0' || *prev_str != '\0') && (*str == *prev_str)){
            ++temp;
            str += 1;
            prev_str += 1;
        }

        count = count > temp ? temp : count;
    }

    char* result = malloc((count + 1) * sizeof(char)); // account for NULL

    strncpy(result, strs[0], count);
    result[count] = '\0';

    return result;
}