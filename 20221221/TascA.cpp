#include <iostream>
#include <stdlib.h>
#include <vector>


#define STACK_SIZE  5   // �X�^�b�N�T�C�Y
#define SUCCESS     1   // ���������Ƃ�
#define FAILURE     0   // ���s�����Ƃ�

//typedef int data_t;   // �X�^�b�N�̒��g�̃f�[�^�^

std::vector<int>stack(STACK_SIZE);  // �X�^�b�N
int stack_num = 0;      // �X�^�b�N���̃f�[�^�̐�

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