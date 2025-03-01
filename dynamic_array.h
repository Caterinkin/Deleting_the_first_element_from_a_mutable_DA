#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// Функция для вывода динамического массива
void print_dynamic_array(int* arr, int logical_size, int actual_size);

// Функция для удаления первого элемента из динамического массива
int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size);

#endif // DYNAMIC_ARRAY_H