#include "binary_trees.h"
#include <assert.h>


void QueuePush(Queue *q, binary_tree_t *data);
void QueuePop(Queue *q);
binary_tree_t *QueueFront(Queue *q);
int QueueEmpty(Queue *q);

/**
 * QueuePush - Push node to queue
 * @q: A pointer to queue
 * @data:ready to pushed data
 */
void QueuePush(Queue *q, binary_tree_t *data)
{
	QNode *newnode;

	assert(q);
	newnode = (QNode *)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail:");
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
	if (q->rear == NULL)
	{
		assert(q->front == NULL);
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}
/**
 * QueueEmpty - QueueEmpty
 * @q: A pointer to queue.
 * Return: return result.
 */
int QueueEmpty(Queue *q)
{
	assert(q);
	if (q->size == 0)
		return (1);
	else
		return (0);
}

/**
 * QueueFront - get the front .
 * @q: A pointer to queue.
 * Return: return data pointer.
 */
binary_tree_t *QueueFront(Queue *q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return (q->front->data);
}

/**
 * QueuePop - pop destroy data from queue .
 * @q: A pointer to queue.
 */
void QueuePop(Queue *q)
{
	QNode *next;

	assert(q);
	assert(!QueueEmpty(q));

	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		next = q->front->next;
		free(q->front);
		q->front = next;
	}
	q->size--;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	Queue q;
	QNode *cur, *next;
	binary_tree_t *front;

	if (tree != NULL && func != NULL)
	{
		q.front = NULL;
		q.rear = NULL;
		q.size = 0;
		if (tree != NULL)
			QueuePush(&q, (binary_tree_t *)tree);
		while (!QueueEmpty(&q))
		{
			front = QueueFront(&q);
			func(front->n);
			if (front->left != NULL)
				QueuePush(&q, front->left);
			if (front->right != NULL)
				QueuePush(&q, front->right);
			QueuePop(&q);
		}
		cur = q.front;
		while (cur)
		{
			next = cur->next;
			free(cur);
			cur = next;
		}
		q.front = q.rear = NULL;
		q.size = 0;
	}
}

