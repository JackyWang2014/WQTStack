//
//  main.c
//  WQTStack
//
//  Created by 王亓泰 on 16/4/14.
//  Copyright © 2016年 WangQitai. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data{
    int data;           // 数据
    struct data * next; // 指向下一节点的指针
}data_t;

typedef struct stack {
    data_t * top;
    data_t * bottom;
}stack_tt;

// 入栈
void push_stack(stack_tt * stack, int data);
// 出栈
int pop_stack(stack_tt * stack, int * x);

int main(int argc, const char * argv[]) {
    
    // 声明两个指针 一个指向栈顶, 一个指向栈底.
    stack_tt stack = {};
    // 创建栈顶, 相当于链表头结点
    push_stack(&stack, 4);
    push_stack(&stack, 5);
    push_stack(&stack, 6);
    
    int data;
    while (pop_stack(&stack, &data)) {
        printf("%d\n",data);
    }
    
    return 0;
}
// 入栈
void push_stack(stack_tt * stack, int data)
{
    // 首先 创建一个堆空间, 存储数据
    data_t * p = (data_t *)malloc(sizeof(data_t));
    if (!p) {
        perror("malloc");
        exit(-1);
    }
    p->data = data;
    
    // 入栈
    if (stack->top == NULL) {
        stack->top = stack->bottom = p;
    } else {
        p->next = stack->top;
        stack->top = p;
    }
    
}
// 出栈
int pop_stack(stack_tt * stack, int * x)
{
    if (stack->top == NULL) {
        return 0;
    }
    
    // 取出数据
    *x = stack->top->data;
    data_t * temp = stack->top->next;
    free(stack->top);
    stack->top = temp;
    return 1;
}

