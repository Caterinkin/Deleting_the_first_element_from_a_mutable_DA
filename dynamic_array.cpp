#include <iostream>
#include "dynamic_array.h"

// ������� ��� ������ ������������� �������
void print_dynamic_array(int* arr, int logical_size, int actual_size) 
{
    for (int i = 0; i < actual_size; ++i) 
    {
        if (i < logical_size) 
        {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

// ������� ��� �������� ������� �������� �� ������������� �������
int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size)
{
    if (logical_size == 0)
    {
        std::cout << "���������� ������� ������ �������, ��� ��� ������ ������." << std::endl;
        return arr; // ���������� ������ ������, ��� ��� ������� ������
    }

    // ��������� ���������� ������
    logical_size--;

    // ���������, ����� �� ��������� ����������� ������
    if (logical_size <= actual_size / 3) 
    {
        int new_actual_size = actual_size / 3;
        if (new_actual_size < 1) new_actual_size = 1; // ����������� ������ ������� � 1

        int* new_arr = new int[new_actual_size];

        // �������� ��������, ������� �� �������
        for (int i = 0; i < logical_size; ++i) 
        {
            new_arr[i] = arr[i + 1];
        }

        // ������� ������ ������
        delete[] arr;

        // ��������� ����������� ������
        actual_size = new_actual_size;

        // ���������� ����� ������
        return new_arr;
    }
    else
    {
        // �������� �������� �����
        for (int i = 0; i < logical_size; ++i)
        {
            arr[i] = arr[i + 1];
        }

        // ���������� ������ ������
        return arr;
    }
}