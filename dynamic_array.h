#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// ������� ��� ������ ������������� �������
void print_dynamic_array(int* arr, int logical_size, int actual_size);

// ������� ��� �������� ������� �������� �� ������������� �������
int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size);

#endif // DYNAMIC_ARRAY_H