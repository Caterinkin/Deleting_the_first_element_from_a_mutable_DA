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

    //���� ��� ����� �������� �������
    while (true) 
    {
        std::cout << "������� ����������� ������ �������: ";
        std::cin >> actual_size;

        std::cout << "������� ���������� ������ �������: ";
        std::cin >> logical_size;
               
        if (logical_size > actual_size)
        {
            std::cout << "������! ���������� ������ ������� �� ����� ��������� �����������!" << std::endl;
            std::cout << std::endl;
            continue; // ������� �� ��������� �������� �����
        }
        // ���� ������� ���������, ������� �� �����
        break;
    }

    // �������� ������������� �������
    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) 
    {
        std::cout << "������� arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "������������ ������: ";
    print_dynamic_array(arr, logical_size, actual_size);
   
    // ���� ��� �������� ���������
    while (true)
    {
        std::string answer;
        std::cout << "\n������� ������ �������? (��/���): ";
        std::cin >> answer;

        if (answer == "���") 
        {
            std::cout << "\n�������! ��� ������������ ������: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break; // ����� �� �����
        }
        else if (answer == "��") 
        {
            if (logical_size == 0) 
            {
                std::cout << "\n���������� ������� ������ �������, ��� ��� ������ ������. �� ��������!" << std::endl;
                break;
            }

            // �������� ������� ��������
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);

            // ����� ������� ����� ��������
            std::cout << "������������ ������: ";
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else 
        {
            std::cout << "�������� ����. ����������, ������� '��' ��� '���'." << std::endl;
        }
    }

    delete[] arr;

    return EXIT_SUCCESS ;
}