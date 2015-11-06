struct queue 
{
	queue* previous;
	data memory;
	queue* next;
};
//начало  .... очередь .... конец
queue* queue_put_last(queue* previous_queue, data temp_memory) //принимает и выдает указатель на конец очереди
{
	queue* new_queue;
	new_queue = (queue*)malloc(sizeof(queue));
	new_queue->memory = temp_memory;
	new_queue->next = NULL;
	new_queue->previous = previous_queue;
	return new_queue;
};

queue* queue_put_first(queue* next_queue, data temp_memory) //принимает и выдает указатель на начало очереди
{
	queue* new_queue;
	new_queue = (queue*)malloc(sizeof(queue));
	new_queue->memory = temp_memory;
	new_queue->next = next_queue;
	new_queue->previous = NULL;
	return new_queue;
};

data queue_get_last(queue* &queue_first, queue* &queue_last)
{
	data result = queue_last->memory;
	if (queue_first == queue_last)
	{
		queue_last = NULL;
		free(queue_first);
		queue_first = NULL;

	}
	else
	{
		queue* temp = queue_last->previous;
		free(queue_last);
		queue_last = temp;
	}

	return result;
}

data queue_get_first(queue* &queue_first, queue* &queue_last)
{
	data result = queue_first->memory;
	if (queue_first == queue_last)
	{
		queue_last = NULL;
		free(queue_first);
		queue_first = NULL;

	}
	else
	{
		queue* temp = queue_first->next;
		free(queue_first);
		queue_first = temp;
	}

	return result;
}
