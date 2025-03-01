#include <iostream>
#include "dynamic_array.h"

// Функция для вывода динамического массива
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

// Функция для удаления первого элемента из динамического массива
int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size)
{
    if (logical_size == 0)
    {
        std::cout << "Невозможно удалить первый элемент, так как массив пустой." << std::endl;
        return arr; // Возвращаем старый массив, так как удалять нечего
    }

    // Уменьшаем логический размер
    logical_size--;

    // Проверяем, нужно ли уменьшать фактический размер
    if (logical_size <= actual_size / 3) 
    {
        int new_actual_size = actual_size / 3;
        if (new_actual_size < 1) new_actual_size = 1; // Минимальный размер массива — 1

        int* new_arr = new int[new_actual_size];

        // Копируем элементы, начиная со второго
        for (int i = 0; i < logical_size; ++i) 
        {
            new_arr[i] = arr[i + 1];
        }

        // Удаляем старый массив
        delete[] arr;

        // Обновляем фактический размер
        actual_size = new_actual_size;

        // Возвращаем новый массив
        return new_arr;
    }
    else
    {
        // Сдвигаем элементы влево
        for (int i = 0; i < logical_size; ++i)
        {
            arr[i] = arr[i + 1];
        }

        // Возвращаем старый массив
        return arr;
    }
}
