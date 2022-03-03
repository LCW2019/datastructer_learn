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
          for (size_t j = i; j >0&array[j]<array[j-1]; j--)  //对比a[i] 与 a[0]~a[i]的元素 如果不符合升序就交换
        {
             swap(array[j],array[j-1]); 
        }
    }
}

//插入排序 优化版本
template<typename T>
void insertionSortOptimization(T* array,int length)
{
     for (size_t i = 1; i < length; i++)
    {
        T temp = array[i];
        int j;
        for (j=i;j>0&array[j-1]>temp; j--)  //对比a[i] 与 a[0]~a[i]的元素 如果不符合升序就交换
        {
             array[j]=array[j-1]; 
        }
        array[j] = temp;
    }
}

//冒泡排序
template<typename T>
void BubbleSort(T* array,int length)
{
  for (size_t i = length-1; i > 0; i--)
  {
      for (size_t j = 0; j < i; j++)
      {
          if (array[j]>array[j+1])
          {
              swap(array[j],array[j+1]);
          }
      }
      
  }
}

//冒泡排序改进版本
template<typename T>
void BubbleSortOptimization(T* array,int length)
{
for (size_t i = length-1; i > 0; i--)
  {
      int tempIndex = i;
      for (size_t j = 0; j < tempIndex; j++)
      {
          if (array[j]>array[j+1])
          {
              swap(array[j],array[j+1]);
              tempIndex = j;    //记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
          }
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
    int* arr_copy_1 = TestData::copyData(arr,length);
    int* arr_copy_2 = TestData::copyData(arr,length);
    // TestData::my_print<int *>(arr,length);
    // selectionSort(arr,length);
    // TestData::my_print<int *>(arr,length);
    // delete[]arr;

    TestData::testSort("selectionSort",selectionSort,arr,length);
    TestData::testSort("selectionSort",selectionSort,arr,length);
    TestData::testSort("insertionSort",insertionSort,arr_copy,length);
    TestData::testSort("insertionSortOptimization",insertionSortOptimization,arr_copy_1,length);
    TestData::testSort("BubbleSort",BubbleSort,arr_copy_2,length);
    TestData::testSort("BubbleSortOptimization",BubbleSortOptimization,arr_copy_2,length);
    delete[]arr;
    delete[]arr_copy;
    delete[]arr_copy_1;
    delete[]arr_copy_2;

    
    return 0;
}