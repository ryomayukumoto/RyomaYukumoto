#include <iostream>
#include <stdlib.h>
#include <vector>

//TaskBにキューとして扱う要素数5のInt型の配列を作成し、1・3・5・7・9をEnqueueし、2つ
//Dequeueするプログラムを書く(Enqueue・Dequeueするたびに配列の中身を出力すること)

#define SUCCESS     1
#define FAILURE     0
#define QUEUE_SIZE  5       

const int DEFAULT = 0;          // キュー内のデフォルト値

std::vector<int>Queue(QUEUE_SIZE, 0);     // キュー
int queue_num;                  // キュー内のデータ数

int Enqueue(int value);
int Dequeue(int* pop_data);
void PrintQueue();

// リングバッファー　インデックスを要素数で割る

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
    queue_num = 0;  // キュー内のデータの数初期化

}

// キューに値を入れる関数
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

// キューから値を出す関数
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

// キューの中身を表示する関数
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