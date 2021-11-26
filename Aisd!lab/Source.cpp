#include <stdlib.h>
#include <iostream>

using namespace std;

struct Element                             
{
    int x;                             
    Element* Next, * Previous;                
};

class List                              //������� ��� ������ ������
{
    Element* Head, * Tail;               //��������� �� ������ ������ ������ � ��� �����
    
public:
    List() :Head(NULL), Tail(NULL) {};    //�������������� ������ ��� ������
    
    ~List()                           //����������
    {
        while (Head)                       //���� �� ������ �� ������ ������ ���-�� ����
        {
            Tail = Head->Next;             
            delete Head;                   
            Head = Tail;                   
        }
    }                         
    void Show();                       //�������� ������� ����������� ������ �� ������
    
    size_t get_size()
    {
        size_of_list = 0;
        Element* temp = Head;
        if (Head == NULL)
            return 0;
        else
        {
            while (temp != Tail)                 //���� �� ������ �� ������ ������ ���-�� ����
            {
                size_of_list += 1;
                temp = temp->Next;
            }
            size_of_list += 1;
            return size_of_list;
        }
        

    }
    void remove(size_t number)
    {
        Element* temp = Head, * save;
        for (int i = 0; i < number - 1; i++)
        {
            temp = temp->Next;  //���� � ������ ���������� ��������
        }
        save = temp;	                                //�������� ���������� ����� ���������� ��������
        save->Previous->Next = temp->Next;	            //���������� ������, ��� ��������� �� ����� ������ ��������� ��������� - ��� ��������� �� ����������
        save->Next->Previous = temp->Previous;               //� ���������� ��� ���������� - ��� ���������� ��� ����������
        delete temp;
    
    }
    void push_front(int x)
    {
        Element* temp = new Element;               //��������� ������ ��� ����� ������� ���������
        temp->Next = NULL;                //���������, ��� ���������� �� ���������� ������ �����
        temp->x = x;                         //���������� �������� � ���������

        if (Head != NULL)                    //���� ������ �� ����
        {
            temp->Next = Head;               //��������� ����� �� ���������� ������� � �����. ����
            Head->Previous = temp;               //��������� ����� ���������� �� ������� ��������
            Head = temp;                     //������ ����� ������
        }
        else //���� ������ ������
        {
            temp->Previous = NULL;               //���������� ������� ��������� � �������
            Head = Tail = temp;              //������=�����=��� �������, ��� ������ ��������
        }
    }

    void push_back(int x)
    {
        Element* temp = new Element;               //��������� ������ ��� ����� ������� ���������
        temp->Next = NULL;                   //���������, ��� ���������� �� ���������� ������ �����
        temp->x = x;                         //���������� �������� � ���������

        if (Head != NULL)                    //���� ������ �� ����
        {
            temp->Previous = Tail;               //��������� ����� �� ���������� ������� � �����. ����
            Tail->Next = temp;               //��������� ����� ���������� �� ������� ��������
            Tail = temp;                     //������ ����� ������
        }
        else //���� ������ ������
        {
            temp->Previous = NULL;               //���������� ������� ��������� � �������
            Head = Tail = temp;              //������=�����=��� �������, ��� ������ ��������
        }
    }

    void pop_back()
    {
        if (Head != NULL)
        {
            if (Head == Tail) //���� � ������ ������ 1 �������
            {
                Head->Next = NULL;	                        
                Head = NULL;
                delete Head;
            }
            else //���� � ������ ������ 1 ��������
            {
                Element* temp = Tail;
                Tail = Tail->Previous;	                              
                Tail->Next = NULL;	                                
                delete temp;
            }

        }
        else
            cout << "List is already empty" << endl;
    }

    void pop_front()
    {
        if (Head != NULL)
        {
            if (Head == Tail) //���� � ������ ������ 1 �������
            {
                Head->Next = NULL;
                Head = NULL;
                delete Head;
            }
            else //���� � ������ ������ 1 ��������
            {
                Element* temp = Head;
                Head = Head->Next;	                            
                Head->Previous = NULL;	                            
                delete temp;
                
            }

        }
        else
            cout << "List is already empty" << endl;
    }

    void clear()
    {
        while (Head)                       //���� �� ������ �� ������ ������ ���-�� ����
        {
            Tail = Head->Next;
            delete Head;
            Head = Tail;
        }
    }

    bool isEmpty()
    {
        if (Head == NULL)
            return true;
        else
            return false;
    }

    int at(size_t elem)
    {
        if (get_size()-1 <= elem)
        {
            Element* temp = Head;
            for (int i = 0; i < elem; i++)
            {
                temp = temp->Next;
            }
            return temp->x;
        }
        else
        {
            cout << "Invalid index" << endl;
            return 0;
        }

            
    }
 
    void set(size_t elem, int X)
    {
        Element* temp = Head;
        for (int i = 0; i < elem; i++)
        {
            temp = temp->Next;
        }
        temp->x = X;
    }

    void insert(int value, size_t elem)
    {
        if ((elem == 0) || elem >= get_size())
        {
            if (elem == 0)
                push_front(value);
            if (elem >= get_size())
                push_back(value);
        }
            
        
        else 
        {
            Element* temp = Head, *save;
            for (int i = 0; i < elem - 1; i++)
                temp = temp->Next;
            Element* newElement = new Element;
                              
            newElement->x = value;
            save = temp->Next;
            temp->Next;
            temp->Next = newElement;
            newElement->Next = save;
        }
        
        
    }
private:

    size_t size_of_list;
    
};




void List::Show()
{
    //������� ������ � �����
    Element* temp = Tail;                   //��������� ��������� �� ����� ���������� ��������

    
    //������� ������ � ������
    temp = Head;                       //�������� ��������� �� ����� ������� ��������
    while (temp != NULL)              //���� �� �������� ������ ��������
    {
        cout << temp->x << " ";        //������� ������ ��������� �������� �� �����
        temp = temp->Next;             //����� ������ �� ����� ���������� ��������
    }
    cout << "\n";
}

int main()
{
    system("CLS");
    List lst; //��������� ����������, ��� ������� ���� ������
    lst.push_back(1); //��������� � ������ ��������
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
        
    
    lst.Show();
    
    lst.insert(90,1);
    lst.Show();
    cout << lst.at(5) << endl;
    system("PAUSE");
    return 0;
}