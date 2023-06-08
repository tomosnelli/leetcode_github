/*
    20. Valid Parentheses
*/
#include "../utils/common.h"

#define O '('
#define C ')'
#define CURL_O '{'
#define CURL_C '}'
#define SQ_O '['
#define SQ_C ']'

bool isOpen(char* s)
{
    if(*s == O || *s == CURL_O || *s == SQ_O){
        return true;
    }

    return false;
}

bool validPair(char stack_pop, char s)
{
    if((stack_pop == O && s == C) ||
        (stack_pop == CURL_O && s == CURL_C) ||
        (stack_pop == SQ_O && s == SQ_C)){
        return true;
    }

    return false;
}

bool isValid(char* s)
{
    int length = strlen(s);    
    char* stack = malloc(length * sizeof(char));

    int stk_ptr = -1;

    while(*s != '\0'){
        if(isOpen(s)){
            stack[++stk_ptr] = *s;
        } else {
            if(stk_ptr >= 0 && !validPair(stack[stk_ptr], *s)){
                return false;
            } else if(stk_ptr < 0){
                return false;
            } else {
                --stk_ptr;
            }
        }
        ++s;
    }

    if(stk_ptr == -1) return true;
    return false;
}

void test_case1() {
    char* input = "()";
    bool expected = true;
    bool result = isValid(input);
    printf("Test Case 1: %s\n", expected == result ? "Passed" : "Failed");
}

void test_case2() {
    char* input = "()[]{}";
    bool expected = true;
    bool result = isValid(input);
    printf("Test Case 2: %s\n", expected == result ? "Passed" : "Failed");
}

void test_case3() {
    char* input = "(]";
    bool expected = false;
    bool result = isValid(input);
    printf("Test Case 3: %s\n", expected == result ? "Passed" : "Failed");
}

void test_case4() {
    char* input = "([)]";
    bool expected = false;
    bool result = isValid(input);
    printf("Test Case 4: %s\n", expected == result ? "Passed" : "Failed");
}

void test_case5() {
    char* input = "{[]}";
    bool expected = true;
    bool result = isValid(input);
    printf("Test Case 5: %s\n", expected == result ? "Passed" : "Failed");
}

int main() {
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    test_case5();
    
    return 0;
}
