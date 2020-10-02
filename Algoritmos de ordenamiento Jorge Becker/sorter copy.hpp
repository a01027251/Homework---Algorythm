//
//  sorter.hpp
//  sort
//
//  Created by Jorge Becker on 8/31/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

//#ifndef sorter_hpp
#define sorter_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace::std;


template <typename T>// clase papa para intercambiar resultados
class Sorter
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};
};


template <typename T>
class SelectionSort : public Sorter<T>//clase para la implementacion de selection sort
{
    public:
    SelectionSort() {};
    ~SelectionSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i+1; j < arr.size(); j++)
            {
                if (arr[j] < arr[min])
                    min = j;
            }
            Sorter<T>::swap(i, min, arr);
        }
    };
};

template <typename T>
class BubbleSort : public Sorter<T>// clase para la implementacion de bubble sort
{
    public:
    BubbleSort() {};
    ~BubbleSort() {};
    bool no_swap;
    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            no_swap = true;
            for (size_t j = 0; j < arr.size() - i-1; j++)
            {
                if (arr[j] > arr[j+1]) {
                    Sorter<T>::swap(j, j+1, arr);
                    no_swap = false;
                }
            }
            if (no_swap)
                break;
        }
    };
};


    
    template<typename T>
    class InsertionSort : public Sorter<T> //clase para la implementacion de insertion sort
    {
        public:
        InsertionSort(){};
        ~InsertionSort(){};
        
        void sort(std::vector<T> &arr)
        {
            T key;
            for (size_t i = 1; i < arr.size(); i++)
            {
                key = arr[i];
                int j = i-1;
                while (j >=0 && arr[j]>key)
                {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1];
            }
        };
    };



template <typename T>

class MergeSort : public Sorter<T>//clase para la implementacion de merge sort
{
public:
    MergeSort(){};
    ~MergeSort(){};
    void sort(std::vector<T> &arr) { mergeSort(arr, 0, arr.size() - 1); };
    
    void mergeSort(std::vector<T> &arr, long int l,long int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        };
    };


    void merge(std::vector<T> &arr, int l, int m, int r)
    {

        int i = l;
        int j = m + 1;
        vector<T>resultado(arr.size(),0);

        for (size_t k = l; k <= r; k++)
        {

            if ((arr[i] <= arr[j] || j>r) && (i<= m))
            {
               resultado[k] = arr[i];

               i++;
            }

           else if (arr[i] > arr[j] || i > m)
            {
                resultado[k] = arr[j];
                j++;
            }
            
            else
                cout<<"No se pudieron unir las comparaciones";
          
        }
        for (size_t a = l; a <= r; a++)
        {
            arr[a] = resultado[a];

        }
        
    };


};



