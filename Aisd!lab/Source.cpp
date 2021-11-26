#include <stdlib.h>
#include <iostream>

using namespace std;

struct Element                             
{
    int x;                             
    Element* Next, * Previous;                
};

class List                              //Создаем тип данных Список
{
    Element* Head, * Tail;               //Указатели на адреса начала списка и его конца
    
public:
    List() :Head(NULL), Tail(NULL) {};    //Инициализируем адреса как пустые
    
    ~List()                           //Деструктор
    {
        while (Head)                       //Пока по адресу на начало списка что-то есть
        {
            Tail = Head->Next;             
            delete Head;                   
            Head = Tail;                   
        }
    }                         
    void Show();                       //Прототип функции отображения списка на экране
    
    size_t get_size()
    {
        size_of_list = 0;
        Element* temp = Head;
        if (Head == NULL)
            return 0;
        else
        {
            while (temp != Tail)                 //Пока по адресу на начало списка что-то есть
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
            temp = temp->Next;  //Идем к адресу удаляемого элемента
        }
        save = temp;	                                //Временно запоминаем адрес удаляемого элемента
        save->Previous->Next = temp->Next;	            //Записываем данные, что следующий за перед сейчас удаляемым элементом - это следующий от удаляемого
        save->Next->Previous = temp->Previous;               //а предыдущий для следующего - это предыдущий для удаляемого
        delete temp;
    
    }
    void push_front(int x)
    {
        Element* temp = new Element;               //Выделение памяти под новый элемент структуры
        temp->Next = NULL;                //Указываем, что изначально по следующему адресу пусто
        temp->x = x;                         //Записываем значение в структуру

        if (Head != NULL)                    //Если список не пуст
        {
            temp->Next = Head;               //Указываем адрес на предыдущий элемент в соотв. поле
            Head->Previous = temp;               //Указываем адрес следующего за хвостом элемента
            Head = temp;                     //Меняем адрес хвоста
        }
        else //Если список пустой
        {
            temp->Previous = NULL;               //Предыдущий элемент указывает в пустоту
            Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
        }
    }

    void push_back(int x)
    {
        Element* temp = new Element;               //Выделение памяти под новый элемент структуры
        temp->Next = NULL;                   //Указываем, что изначально по следующему адресу пусто
        temp->x = x;                         //Записываем значение в структуру

        if (Head != NULL)                    //Если список не пуст
        {
            temp->Previous = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
            Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
            Tail = temp;                     //Меняем адрес хвоста
        }
        else //Если список пустой
        {
            temp->Previous = NULL;               //Предыдущий элемент указывает в пустоту
            Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
        }
    }

    void pop_back()
    {
        if (Head != NULL)
        {
            if (Head == Tail) //Если в списке только 1 элемент
            {
                Head->Next = NULL;	                        
                Head = NULL;
                delete Head;
            }
            else //Если в списке больше 1 элемента
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
            if (Head == Tail) //Если в списке только 1 элемент
            {
                Head->Next = NULL;
                Head = NULL;
                delete Head;
            }
            else //Если в списке больше 1 элемента
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
        while (Head)                       //Пока по адресу на начало списка что-то есть
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
    //ВЫВОДИМ СПИСОК С КОНЦА
    Element* temp = Tail;                   //Временный указатель на адрес последнего элемента

    
    //ВЫВОДИМ СПИСОК С НАЧАЛА
    temp = Head;                       //Временно указываем на адрес первого элемента
    while (temp != NULL)              //Пока не встретим пустое значение
    {
        cout << temp->x << " ";        //Выводим каждое считанное значение на экран
        temp = temp->Next;             //Смена адреса на адрес следующего элемента
    }
    cout << "\n";
}

int main()
{
    system("CLS");
    List lst; //Объявляем переменную, тип которой есть список
    lst.push_back(1); //Добавляем в список элементы
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