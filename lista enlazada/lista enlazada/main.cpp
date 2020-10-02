//
//  main.cpp
//  lista enlazada
//
//  Created by Jorge Becker on 9/21/20.
//

#include <iostream>

#include "lista.h"

using namespace std;

int main()
{
    try
    {
        LinkedList<int> list;
        list.push(4);
        list.push(42);
        list.push(92);
        list.push(56);
        list.push(48);
        list.print();

        list.append(92);
        list.append(92);
        list.print();

        list.insert_item(66, 1);
        list.print();
        cout<<"La lista en orden inverso es: "<<endl;
        list.Reverse();
        list.print();

        list.delete_item(1);

        list.print();

        cout<<"La cantidad de veces que aparece el numero deseado es: "<<list.count(92)<<endl;;
        
        list.DeleteList();
        
        list.push(4);
        list.push(9);
        list.push(10);
        list.push(10);
        list.push(15);
        list.push(15);
        list.push(15);
        list.RemoveDuplicates();
        



        


        for (size_t i = 0; i < list.length(); i++)
        {
            int item;
            list.get_nth(i, item);
            cout << item << ", ";
        }
        cout << endl;
    }
    catch(const char* e)
    {
        std::cerr << "ERROR caught: " << e << std::endl;
    }

    return 0;
}
