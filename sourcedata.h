#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;

namespace TestData{
    int* getRandomData(int length,int randomL,int randomR)
    {
        int* array = new int[length];
        srand(time(NULL));
        for (size_t i = 0; i < length; i++)
        {
            /* code */
            array[i] = rand()%randomR-randomL+1;
            // cout<<array[i] <<" ";
        }
        return array;
    }

    template<typename T>
    void my_print(T array,int length)
    {
        for (size_t i = 0; i < length; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<"  "<<endl;
    }

    template<typename T>
    bool checkResult(T array,int length)
    {
        for (size_t i = 0; i < length-1; i++)
        {
           if (array[i]>array[i+1])  //Ä¬ÈÏÉýÐò
           {
               /* code */
               return false;
           }
        }
        return true;
    }


    template<typename T>
    void testSort(string sortname,void(*sort)(T* array,int length),T* array,int length,bool print=false)
    {
        if (print)
        {
            /* code */
            my_print(array,length);
        }
        clock_t starttime = clock();
        sort(array,length);
        clock_t endtime = clock();
         if (print)
        {
            /* code */
            my_print(array,length);
        }
        assert(checkResult(array,length));
        cout<<"function name::"<<sortname<<" used "<<double(endtime-starttime)/CLOCKS_PER_SEC<<" s"<<endl;
    }

    int *copyData(int* array,int length)
    {
        int* array_copy = new int[length];
        std::copy(array,array+length,array_copy);
        return array_copy;
    }

   



}