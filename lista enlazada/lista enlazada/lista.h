//
//  lista.h
//  lista enlazada
//
//  Created by Jorge Becker on 9/21/20.
//

#ifndef lista_h
#define lista_h
#include <stddef.h>
#include <iostream>

template <class T>
class Node
{
private:
    T val;


public:
    
    Node<T> *next;
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext)
    {
        val = pVal;
        next = pNext;
    };

    T get_val() {return val;};
    void set_val(T pVal) {val = pVal;};
    Node<T> *get_next() {return next;};
    void set_next(Node<T> *pNext) {next = pNext;};
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;

public:

    ~LinkedList()
    {
        // to be implemented
    };
    LinkedList()
    {
        head = NULL;
    };

    int length()
    {
        int length = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->get_next();
        }
        return length;
    };

    void print()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            std::cout << ptr->get_val() << ", ";
            ptr = ptr->get_next();
        }
        std::cout << std::endl;
    }

    void push(T pVal)
    {
        Node<T> *node = new Node<T>(pVal, head);
        head = node;
    };

    void append(T pVal)
    {
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL)
        {
            ptr = ptr->get_next();
        }
        Node<T> *node = new Node<T>(pVal, NULL);
        ptr->set_next(node);
    };

    int insert_item(T pVal, int index)
    {
        if (index > length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            push(pVal);
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        Node<T> *node = new Node<T>(pVal, ptr);
        pre->set_next(node);
        return 1;
    };

    bool is_empty()
    {
        return head == NULL;
    };

    int delete_item(int index)
    {
        if (is_empty())
            return -1;
        if (index >= length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->get_next();
            delete temp;
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr->get_next() != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        pre->set_next(ptr->get_next());
        delete ptr;
        return 1;
    };

    int get_nth(int index, T &item)
    {
        if (index < 0)
            return -1;
        if (index >= length())
            return -2;
            
        int i = 0;
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL && index > i)
        {
            ptr = ptr->get_next();
            i++;
        }
        item = ptr->get_val();
        return 1;
    };
    int count (T searchFor){ // Complejidad O(n)
        Node<T>* current = head;
        int count = 0;
        while (current != NULL) {
            if(current -> get_val() == searchFor)
                count++;
            current = current -> next;
        }
        return count;
    };
    
    void DeleteList(){ //Complejidad O(N)
        Node<T>* current = head;
        Node<T>* next2;
        
        while (current != NULL) {
            next2= current->get_next();
            free(current);
            current = current -> get_next();
            
        }
        head=NULL;
    };
    
    void SortedInsert (Node<T> *newNode){ //Complejidad O(n)
        int pVal = newNode->get_val();
        Node<T> *ptr = head;

        while (ptr->get_next()->get_val() < pVal)
        {
            ptr = ptr->get_next();
        }
        newNode->set_next(ptr->get_next());
        ptr->set_next(newNode);
        

    };
    
    void RemoveDuplicates(){//complejidad O(n^2)
        Node<T>* current = head;
        Node<T>* next2;
        if (current == NULL)
            throw -1;
        while (current->next != NULL)
           {
           if (current->get_val() == current->next->get_val())
           {
               next2 = current->next->next;
               free(current->next);
               current->next = next2;
           }
           else
           {
               current = current->next;
           }
           }
        
        
    };
    
    void Reverse(){ // Complejidad O(n)
        Node<T>* next = NULL;
        Node<T>* prev = NULL;
        Node<T>* current = head;
        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
        
        
        
};


#endif /* lista_h */
