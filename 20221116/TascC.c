//TaskCにキューとして扱う要素数5のInt型の配列を作成し、1・3・5・7・9をEnqueueし、2つ
//Dequeueしたあと、更に2・4をEnqueueするプログラムを書く(Enqueue・Dequeueするたびに配
//列の中身を出力すること)

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS     1
#define FAILURE     0
#define DEFAULT     0
#define QUEUE_SIZE  5

int queue_data[QUEUE_SIZE];     // キュー配列
int queue_head;         // キューの先頭
int queue_end;          // キューの末尾
int queue_num;

void InitQueue();
int Enqueue(int value);
int Dequeue(int* pop_data);
void queuePrint();

int main()
{
    int p;
    InitQueue();    // Queue初期化

    // Enqueue
    Enqueue(1);
    queuePrint();
    Enqueue(3);
    queuePrint();
    Enqueue(5);
    queuePrint();
    Enqueue(7);
    queuePrint();
    Enqueue(9);
    queuePrint();

    // Dequeue
    for (int i = 0; i < 2; i++)
    {
        Dequeue(&p);
        queuePrint();
    }

    // Enqueue
    Enqueue(2);
    queuePrint();
    Enqueue(4);
    queuePrint();




    return 0;
}

// queue初期化関数
void InitQueue()
{
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        queue_data[i] = DEFAULT;    // キュー内初期化
    }
    queue_head = 0;     // キューの先頭 0
    queue_end = 0;      // キューの末尾 0
    queue_num = 0;
}

// queueにデータ入れる関数
int Enqueue(int value)
{
    
    if (queue_num < QUEUE_SIZE) {
        queue_data[(queue_head + queue_num) % QUEUE_SIZE] = value;
        queue_num++;
        return SUCCESS;
    }
    else {
        return FAILURE;
    }
    
}

int Dequeue(int* pop_data)
{
    if (queue_num > 0) {
        *pop_data = queue_data[queue_head];
        queue_head = (queue_head + 1) % QUEUE_SIZE;
        queue_num--;
        return SUCCESS;
    }
    else {
        return FAILURE;
    }
}

void queuePrint()
{
   
    int i;

    printf("queue [");
    for (i = 0; i < QUEUE_SIZE; i++) {
        if ((queue_head + queue_num <= QUEUE_SIZE && queue_head <= i && i < queue_head + queue_num)
            || (queue_head + queue_num > QUEUE_SIZE && (queue_head <= i || i < (queue_head + queue_num) % QUEUE_SIZE))) {
            printf("%3d", queue_data[i]);
        }
        else {
            printf("%3c", '.');       /* queue に入っていないデータは表示しない */
        }
    }
    printf("]\n");
    
}