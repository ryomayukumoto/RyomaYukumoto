#include <iostream>
#include <stdlib.h>
#include <vector>

//TaskB�ɃL���[�Ƃ��Ĉ����v�f��5��Int�^�̔z����쐬���A1�E3�E5�E7�E9��Enqueue���A2��
//Dequeue����v���O����������(Enqueue�EDequeue���邽�тɔz��̒��g���o�͂��邱��)

#define SUCCESS     1
#define FAILURE     0
#define QUEUE_SIZE  5       

const int DEFAULT = 0;          // �L���[���̃f�t�H���g�l

std::vector<int>Queue(QUEUE_SIZE, 0);     // �L���[
int queue_num;                  // �L���[���̃f�[�^��

int Enqueue(int value);
int Dequeue(int* pop_data);
void PrintQueue();

// �����O�o�b�t�@�[�@�C���f�b�N�X��v�f���Ŋ���

int main()
{
    int p;

    PrintQueue();

    Enqueue(1);
    PrintQueue();
    Enqueue(3);
    PrintQueue();
    Enqueue(5);
    PrintQueue();
    Enqueue(7);
    PrintQueue();
    Enqueue(9);
    PrintQueue();

    for (int i = 0; i < 2; i++)
    {
        Dequeue(&p);
        PrintQueue();
    }
    return 0;
}

void InitQueue(int* queue)
{
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        queue[i] = DEFAULT;
    }
    queue_num = 0;  // �L���[���̃f�[�^�̐�������

}

// �L���[�ɒl������֐�
int Enqueue(int value)
{
    if (queue_num < QUEUE_SIZE)
    {
        Queue.emplace_back(value);
        //Queue[queue_num] = value;
        queue_num++;
        return SUCCESS;
    }
    else
        return FAILURE;

}

// �L���[����l���o���֐�
int Dequeue(int* pop_data)
{
    if (queue_num > 0)
    {

        *pop_data = Queue.front();//= Queue[0];
        Queue.erase(Queue.begin());
        queue_num--;
        return SUCCESS;
    }
    else
        return FAILURE;


}

// �L���[�̒��g��\������֐�
void PrintQueue()
{
    //printf("Queue");
    std::cout << "Queue";
    for (auto vec : Queue)
    {
        std::cout << vec << " ";
    }

    std::cout << std::endl;
    /*for (int i = 0; i < queue_num; i++)
    {
        printf("%2d", Queue[i]);
        std::cout <<
    }
    printf("\n");*/
}