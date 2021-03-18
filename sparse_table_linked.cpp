// linked list representation
#include <iostream>

using namespace std;

class Node
{
public:
    int row;
    int col;
    int val;
    Node *next;
};

class Sll
{
private:
    Node *head;

public:
    Sll()
    {
        head = NULL;
    }

    void insert(int row1, int column, int value)
    {
        Node *item = new Node;
        item->val = value;
        item->row = row1;
        item->col = column;
        item->next = NULL;

        if (head == NULL)
        {
            head = item;
        }
        else
        {
            Node *tmp = head;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = item;
        }
    }

    void print()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << "Row : " << tmp->row << endl;
            cout << "Column : " << tmp->col << endl;
            cout << "Value : " << tmp->val << endl;
            cout << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    Sll obj;
    int matrix[3][3] = {
        {0, 0, 3},
        {4, 2, 0},
        {0, 5, 7}};

    int size = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i][j] != 0)
            {
                obj.insert(i, j, matrix[i][j]);
            }

    obj.print();
    return 0;
}