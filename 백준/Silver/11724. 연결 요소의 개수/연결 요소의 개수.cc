#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
	struct Node* next;
	int node_number;
}Node;
typedef struct Queue
{
	struct Node* front;
	struct Node* rear;
	int queue_size;
}Queue;
void init(Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->queue_size = 0;
}
int is_empty(Queue* queue)
{
	if (queue->queue_size == 0)
	{
		return 1;
	}
	return 0;
}
void enqueue(Queue* queue, int number)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->node_number = number;
	if (is_empty(queue))
	{
		queue->front = newnode;
		queue->rear = newnode;
		queue->queue_size++;
		return;
	}
	queue->rear->next = newnode;
	queue->rear = newnode;
	queue->queue_size++;
}
int dequeue(Queue* queue)
{
	int first = queue->front->node_number;
	queue->front = queue->front->next;
	queue->queue_size--;
	return first;
}
int matrix[1001][1001] = { 0 };
int visited[1001] = { 0 };
int main()
{
	int N, M, value1, value2;
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	init(queue);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &value1, &value2);
		matrix[value1][value2] = 1;
		matrix[value2][value1] = 1;
	}
	int count = 0;
	for (int j = 1; j <= N; j++)
	{
		if (visited[j] == 1)
		{
			continue;
		}
		if (visited[j] == 0)
		{
			enqueue(queue, j);
			visited[j] = 1;
		}
		while (!is_empty(queue))
		{
			int current = dequeue(queue);
			for (int i = 1; i <= N; i++)
			{
				if (matrix[current][i] == 1 && visited[i] == 0)
				{
					enqueue(queue, i);
					visited[i] = 1;
				}
			}
		}
		count++;
	}
	printf("%d", count);
}
