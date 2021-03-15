#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

class SLlist
{
private:
    Node *head;

public:
    SLlist()
    {
        head = NULL;
    }

    void print()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->value << endl;
            tmp = tmp->next;
        }
    }

    void insert_at_head(int val)
    {
        Node *item = new Node;
        item->value = val;
        item->next = NULL;

        if (head == NULL)
        {
            head = item;
        }
        else
        {
            item->next = head;
            head = item;
        }
    }

    void insert(int val)
    {
        Node *item = new Node;
        item->value = val;
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

    void delete_from_head()
    {
        if (head == NULL)
        {
            cout << "the list is empty. Nothing deleted!" << endl;
        }
        else 
        {
            Node *tmp = head;
            head = head->next;
            cout << "Value: " << tmp->value << " has been deleted!" << endl;
            delete tmp;
        }
    }


    void delete_from_tail()
    {
        if( head == NULL)
        {
            cout << "the list is empty. Nothing deleted!" << endl;
        }
        else
        {
            Node *tmp = head;
            Node *del_item;
            while(tmp->next->next != NULL)
            {
                tmp = tmp->next;
            }
            del_item = tmp->next;
            tmp->next = NULL;
            cout << "Value: " << del_item->value << " has been deleted!" << endl;
            delete del_item;
        }
    }

    void delete_value(int val)
    {
        if (head == NULL)
        {
            cout << "the list is empty. Nothing deleted!" << endl;
        } 
        else
        {
            Node *tmp = head;
            Node *del_item;
            if (tmp->value == val)
            {
                head = tmp->next;
                delete tmp;
            }
            else 
            {
                while (tmp->next->value != val)
                {
                    tmp = tmp->next;
                }
                del_item = tmp->next;
                tmp->next = tmp->next->next;
                cout << "Value : " << del_item->value << " has been deleted!" << endl;
                delete del_item;
            }
        }
    }
};

int main()
{
    SLlist list;
    list.delete_value(7);
    list.delete_from_head();
    list.delete_from_tail();
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);
    list.insert(3);
    list.insert_at_head(500);
    list.insert(13);
    list.insert(245);

    list.print();

    list.delete_from_head();
    list.print();

    list.delete_from_tail();
    list.print();

    list.delete_value(6);
    list.print();

    list.delete_value(13);
    list.print();

    return 0;
}