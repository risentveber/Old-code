
struct tree_element
{
	tree_element * parent;
	data memory;
	tree_element * left;
	tree_element * right;
};

tree_element* create(data memory)
{
	tree_element* temp = (tree_element*)calloc(1, sizeof(tree_element));
	temp->memory = memory;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;

	return temp;
}

tree_element* find(tree_element* root, data item)//Функция поиска, аргументы: корень дерева, искомый элемент
{
	tree_element* finder = NULL;// Указатель на искомый элемент
	tree_element* temp = root;// Текущий элемент
	while ((finder == NULL)&&(temp != NULL)) // Если элемент не найден и дерево не закончилось
	{
		if (temp->memory == item)//Если найден элемент
		{
			finder = temp;
		}
		else //Если не найден
		{
			if (temp->memory > item)//Если элемент больше то идем вправо
			{
				temp = temp->left;
			}
			else                    //В противном случае влево
			{
				temp = temp->right;
			}
		}
	}
	return finder;

}

void insert(tree_element* root, data item)//Функция вставки элемента, аргументы корень и вставляемый элемент
{
	tree_element* temp = root;// Текущий элемент
	while (true) // Если дерево не закончилось
	{
		if (temp->memory <= item)//Если элемент больше либо равен то идем вправо
		{
			if (temp->right !=NULL)//если это не конец то идем дальше
			{
				temp = temp->right;
			}
			else                   //создаем новый лист
			{
				temp->right = create(item);
				temp->right->parent = temp;
				break;
			}
		}
		else                    //Меньше - влево
		{
			if (temp->left != NULL)//если это не конец то идем дальше
			{
				temp = temp->left;

			}
			else                   //создаем новый лист
			{
				temp->left = create(item);
				temp->left->parent = temp;
				break;
			}
		}
	}
	return;
}

void remove_item(tree_element* &root, data item)
{
	tree_element* temp = find(root, item);//Просматриваемый элемент
	tree_element* parent;//Родитель текущего элемента
	tree_element* right;//Правый сын текущего
	tree_element* left;//Левый сын текущего
	tree_element* helper;
	tree_element** par;//Адрес указателя на текущий элемент

	if (temp != NULL)//Если удаляемый элемент найден
	{
		right = temp->right;
		left = temp->left;

		if (temp != root)//Если это не корень дерева
		{
			if (temp->parent->left == temp)
			{
				par = &(temp->parent->left);
			}
			else
			{
				par = &(temp->parent->right);
			}//Находим адрес указателя на удаляемый элемент

			if (right != NULL)//Существует правый сын корня
			{
				*par = right;
				if (left != NULL)//У исходного корня было оба сына
				{
					right = *par;//Указатель на самый левый элемент дерева
					while (right->left != NULL)
					{
						right = right->left;
					}
					right->left = left;

				}
			}
			else//Правого сына у корня нет
			{
				if (left != NULL)//Существует только левый сын корня
				{
					*par = left;
				}
				else//Сыновей у корня нет
				{
					*par = NULL;
				}

			}
			free(temp);

		}
		else//Удаляемый элемент - корень
		{
			if (right != NULL)//Существует правый сын корня
			{
				root = right;
				root->parent=NULL;

				if (left != NULL)//У исходного корня было оба сына
				{
					right = root;//Указатель на самый левый элемент дерева
					while (right->left != NULL)
					{
						right = right->left;
					}
					right->left = left;

				}
			}
			else//Правого сына у корня нет
			{
				if (left != NULL)//Существует только левый сын корня
				{
					root = left;
					root->parent=NULL;
				}
				else//Сыновей у корня нет
				{
					root = NULL;
				}

			}

			free(temp);
		}
	}

}

void printer(tree_element* root)
{
	if (root->left != NULL)
		printer(root->left);
	printf("%i\n", root->memory);
	if (root->right != NULL)
		printer(root->right);
}


void clear(tree_element* root)
{
	if (root->left != NULL)
		clear(root->left);
	if (root->right != NULL)
		clear(root->right);
	free(root);
}
