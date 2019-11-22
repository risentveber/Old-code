
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

tree_element* find(tree_element* root, data item)//������� ������, ���������: ������ ������, ������� �������
{
	tree_element* finder = NULL;// ��������� �� ������� �������
	tree_element* temp = root;// ������� �������
	while ((finder == NULL)&&(temp != NULL)) // ���� ������� �� ������ � ������ �� �����������
	{
		if (temp->memory == item)//���� ������ �������
		{
			finder = temp;
		}
		else //���� �� ������
		{
			if (temp->memory > item)//���� ������� ������ �� ���� ������
			{
				temp = temp->left;
			}
			else                    //� ��������� ������ �����
			{
				temp = temp->right;
			}
		}
	}
	return finder;

}

void insert(tree_element* root, data item)//������� ������� ��������, ��������� ������ � ����������� �������
{
	tree_element* temp = root;// ������� �������
	while (true) // ���� ������ �� �����������
	{		
		if (temp->memory <= item)//���� ������� ������ ���� ����� �� ���� ������
		{
			if (temp->right !=NULL)//���� ��� �� ����� �� ���� ������
			{
				temp = temp->right;
			}
			else                   //������� ����� ����
			{
				temp->right = create(item);
				temp->right->parent = temp;
				break;
			}
		}
		else                    //������ - �����
		{
			if (temp->left != NULL)//���� ��� �� ����� �� ���� ������
			{
				temp = temp->left;
				
			}
			else                   //������� ����� ����
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
	tree_element* temp = find(root, item);//��������������� �������
	tree_element* parent;//�������� �������� ��������
	tree_element* right;//������ ��� ��������
	tree_element* left;//����� ��� ��������
	tree_element* helper;
	tree_element** par;//����� ��������� �� ������� �������

	if (temp != NULL)//���� ��������� ������� ������
	{
		right = temp->right;
		left = temp->left;

		if (temp != root)//���� ��� �� ������ ������
		{
			if (temp->parent->left == temp)
			{
				par = &(temp->parent->left);
			}
			else
			{
				par = &(temp->parent->right);
			}//������� ����� ��������� �� ��������� �������
			
			if (right != NULL)//���������� ������ ��� �����
			{
				*par = right;
				if (left != NULL)//� ��������� ����� ���� ��� ����
				{
					right = *par;//��������� �� ����� ����� ������� ������
					while (right->left != NULL)
					{
						right = right->left;
					}
					right->left = left;

				}
			}
			else//������� ���� � ����� ���
			{
				if (left != NULL)//���������� ������ ����� ��� �����
				{
					*par = left;					
				}
				else//������� � ����� ���
				{
					*par = NULL;
				}
				
			}
			free(temp);

		}
		else//��������� ������� - ������
		{
			if (right != NULL)//���������� ������ ��� �����
			{
				root = right;
				root->parent=NULL;

				if (left != NULL)//� ��������� ����� ���� ��� ����
				{
					right = root;//��������� �� ����� ����� ������� ������
					while (right->left != NULL)
					{
						right = right->left;
					}
					right->left = left;

				}
			}
			else//������� ���� � ����� ���
			{
				if (left != NULL)//���������� ������ ����� ��� �����
				{
					root = left;					
					root->parent=NULL;
				}
				else//������� � ����� ���
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
