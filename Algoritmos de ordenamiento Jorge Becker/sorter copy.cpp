//
//  sorter.cpp
//  sort
//
//  Created by Jorge Becker on 8/31/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "myTimer.h" //liberira de cronometro
#include "sorter.hpp"//desarrollo de cada metodo de sort


using namespace std;


template <typename T>
void print_vector(vector<T> arr, int N)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    // generate a random vector array of float que va a ser usado para el selection sort
    vector<int> arr_f;
    int tamaño1 = 100000;
    for (size_t i = 0; i < tamaño1; i++)
    {
        arr_f.push_back((int)rand() % 256);
    }

    cout << "Unsorted:" << endl;
    print_vector(arr_f, 10);

    // create instance of SelectionSort
    DECLARE_TIMING(t);
    START_TIMING(t);
    SelectionSort<int> selsort;
    selsort.sort(arr_f);

    cout <<"Sorted With Selection Sort:" << endl;
    print_vector(arr_f, 20);
    STOP_TIMING(t);
    SHOW_TIMING(t, " selection sort");

    // generate a random vector array of float que va a ser usado para bubble sort
    vector<int> arr_a;
    int tamaño2 = 100000;
    for (size_t i = 0; i < tamaño2; i++)
    {
        arr_a.push_back((int)rand() % 256);
        // arr_f.push_back((double)rand() / RAND_MAX);
    }

    cout << "Unsorted:" << endl;
    print_vector(arr_a, 10);

    // create instance of BubbleSort
    DECLARE_TIMING(a);
    START_TIMING(a);
    BubbleSort<int> bubbsort;
    bubbsort.sort(arr_a);

    cout << endl << "Sorted With Bubble Sort:" << endl;
    print_vector(arr_a, 20);
    STOP_TIMING(a);
    SHOW_TIMING(a, " Bubble sort");

    // generate a random vector array of float que va a ser usado para insertion sort
    vector<int> arr_b;
    int tamaño3 = 100000;
    for (size_t i = 0; i < tamaño3; i++)
    {
        arr_b.push_back((int)rand() % 256);
        // arr_f.push_back((double)rand() / RAND_MAX);
    }

    cout << "Unsorted:" << endl;
    print_vector(arr_b, 10);

    // create instance of Insertion sort
    DECLARE_TIMING(b);
    START_TIMING(b);
    InsertionSort<int> inssort;
    inssort.sort(arr_b);

    cout << endl << "Sorted With Insertion Sort:" << endl;
    print_vector(arr_b, 20);
    STOP_TIMING(b);
    SHOW_TIMING(b, " insertion sort");

    // generate a random vector array of float que va a ser usado para merge sort
    vector<int> arr_c;
    int tamaño4 = 100000;
    for (size_t i = 0; i < tamaño4; i++)
    {
        arr_c.push_back((int)rand() % 250);
        // arr_f.push_back((double)rand() / RAND_MAX);
    }

    cout << "Unsorted:" << endl;
    print_vector(arr_c, 5);

    // create instance of merge sort
    DECLARE_TIMING(c);
    START_TIMING(c);
    MergeSort<int> mersort;
    mersort.sort(arr_c);

    cout << endl << "Sorted With merge Sort:" << endl;
    print_vector(arr_c, 25);
    STOP_TIMING(c);
    SHOW_TIMING(c, " merge sort");



    return 0;
}
