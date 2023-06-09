/*
    155. Min Stack
*/
#include "../utils/common.h"

typedef struct {
    int top;
    int* min;
    int* stack;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->top = -1;
    stack->stack = malloc(10000 * sizeof(int));
    stack->min = malloc(10000 * sizeof(int));
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++(obj->top)] = val;

    if(obj->top == 0){
        obj->min[obj->top] = val;
    } else {
        obj->min[obj->top] = (val < obj->min[obj->top-1]) ? val : obj->min[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    --(obj->top);
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);    
    free(obj->min);
}

/*
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/