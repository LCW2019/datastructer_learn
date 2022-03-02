#include<iostream>
#include"sourcedata.h"

using namespace std;

template<typename T>
void selectionSort(T array,int length)
{
    for (size_t i = 0; i < length; i++)
    {
        /* code */
        int minindex = i;
        for (size_t j = i; j < length; j++)
        {
            /* code */
            if (array[minindex]>array[j])
            {
                minindex = j;
                /* code */
            }
        }
        swap(array[i],array[minindex]);  
    } 
}

//插入排序
template<typename T>
void insertionSort(T array,int length)
{
    for (size_t i = 1; i < length; i++)
    {
          for (size_t j = i; j >0; j--)  //对比a[i]
        {
            if(array[j]<array[j-1])
            {
                swap(array[j],array[j-1]); 
            }
            else
            {
                break;
            }
        }
    }
}

//插入排序 优化版本
template<typename T>
void insertionSortOptimization(T* array,int length)
{
    for (size_t i = 1; i < length; i++)
    {   
        T e = array[i];
        int j =i;
        for (j; j >0&array[j]<array[j-1]; j--)  //对比a[i]
        {
            swap(array[j],array[j-1]);    
        }
    }
}

int  main()
{
    // int testIntarray[] ={1,2,333,4,5,6,8,7,10,9};
    // selectionSort(testIntarray,10);
    // TestData::my_print(testIntarray,10);
    // char testChararray[] ={'A','C','D','E','F','D'};
    // selectionSort(testChararray,6);
    // my_print(testChararray,6);
    int length=10000;
    int* arr = TestData::getRandomData(length,10,1000);
    int* arr_copy = TestData::copyData(arr,length);
    // TestData::my_print<int *>(arr,length);
    // selectionSort(arr,length);
    // TestData::my_print<int *>(arr,length);
    // delete[]arr;

    // TestData::testSort("selectionSort",selectionSort,arr,length,false);
    TestData::testSort("selectionSort",selectionSort,arr,length);
    TestData::testSort("insertionSort",insertionSort,arr_copy,length);
    delete[]arr;
    delete[]arr_copy;

    
    return 0;
}