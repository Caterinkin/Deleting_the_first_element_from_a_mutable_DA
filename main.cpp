#include <iostream>
#include <string>
#include <windows.h>
#include "dynamic_array.h"

int main() 
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int actual_size, logical_size;

    //цикл для ввода размеров массива
    while (true) 
    {
        std::cout << "Введите фактический размер массива: ";
        std::cin >> actual_size;

        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
               
        if (logical_size > actual_size)
        {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
            std::cout << std::endl;
            continue; // Переход на следующую итерацию цикла
        }
        // Если размеры корректны, выходим из цикла
        break;
    }

    // Создание динамического массива
    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) 
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
   
    // Цикл для удаления элементов
    while (true)
    {
        std::string answer;
        std::cout << "\nУдалить первый элемент? (да/нет): ";
        std::cin >> answer;

        if (answer == "нет") 
        {
            std::cout << "\nСпасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break; // Выход из цикла
        }
        else if (answer == "да") 
        {
            if (logical_size == 0) 
            {
                std::cout << "\nНевозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
                break;
            }

            // Удаление первого элемента
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);

            // Вывод массива после удаления
            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else 
        {
            std::cout << "Неверный ввод. Пожалуйста, введите 'да' или 'нет'." << std::endl;
        }
    }

    delete[] arr;

    return EXIT_SUCCESS ;
}
