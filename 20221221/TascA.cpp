#include <iostream>
#include <stdlib.h>
#include <vector>


#define STACK_SIZE  5   // スタックサイズ
#define SUCCESS     1   // 成功したとき
#define FAILURE     0   // 失敗したとき

//typedef int data_t;   // スタックの中身のデータ型

std::vector<int>stack(STACK_SIZE);  // スタック
int stack_num = 0;      // スタック内のデータの数

int Push(int push_data);
int Pop(int* pop_data);
void stackPrint();

int main()
{
    stackPrint();
    int p;
    //int element;

    Push(1);
    stackPrint();
    Push(3);
    stackPrint();
    Push(5);
    stackPrint();
    Push(7);
    stackPrint();
    Push(9);
    stackPrint();

    for (int i = 0; i < 2; i++)
    {
        Pop(&p);
        stackPrint();
    }
}

int Push(int push_data)
{
    if (stack_num < STACK_SIZE)
    {
        stack.emplace_back(push_data);
        //stack[stack_num] = push_data;
        stack_num++;
        return SUCCESS;
    }
    else
        return FAILURE;
}

int Pop(int* pop_data)
{
    if (stack_num > 0)
    {

        *pop_data = stack.back();
        stack.pop_back();
        stack_num--;
        //*pop_data = stack[stack_num];
        return SUCCESS;
    }
    else
        return FAILURE;
}

void stackPrint()
{
    for (auto vec : stack)
    {
        std::cout << vec << " ";
    }
    std::cout << std::endl;
    /*printf("stack");
    for (int i = 0; i < stack_num; i++)
    {
        printf("%2d", stack[i]);
    }
    printf("\n");*/
}