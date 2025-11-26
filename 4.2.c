#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет первый отрицательный элемент массива на первый положительный
 * @param arr массив
 * @param size размер массива
 * @return 0, если положительный или отрицательный элементы отсутствуют, 1 - если замена выполнена успешно
 */
int replaceFirstNegativeFirstPositive(int* arr, const size_t size);

/**
 * @brief Удаляет элементы массива, кратные семи и лежащие в диапазоне [min; max]
 * @param arr массив
 * @param size размер массива
 * @param newSize новый размер массива после удаления
 * @return 0 - если неверно задан диапазон/отсутствуют подходящие элементы, 1 - если функция выполнена успешно
 */
int deleteMultiplesOf7InRange(int* arr, const size_t size, size_t* newSize);

/**
 * @brief Преобразует элементы массива по определённым правилам
 * @param arr массив
 * @param size размер массива
 * @return 0 - если в массиве отсутствуют элементы, 1 - если функция выполнена успешно
 */
int transformArray(int* arr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

int main(void)
{
    size_t size = getSize("Input size of an array:\n");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    printf("Choose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            fprintf(stderr, "Invalid choice\n");
            free(arr);
            exit(1);
    }

    printf("Original array:\n");
    printArray(arr, size);

    // Создаем копию для работы
    int* copyArr = copyArray(arr, size);
    if (copyArr == NULL)
    {
        fprintf(stderr, "Memory allocation error for copy\n");
        free(arr);
        exit(1);
    }

    // Задание 1: Замена первого отрицательного на первый положительный
    printf("\n1. Replace first negative with first positive:\n");
    if (replaceFirstNegativeFirstPositive(copyArr, size))
    {
        printArray(copyArr, size);
    }

    // Задание 2: Удаление элементов, кратных 7 в диапазоне
    printf("\n2. Delete multiples of 7 in range:\n");
    size_t newSize = size;
    if (deleteMultiplesOf7InRange(copyArr, size, &newSize))
    {
        printf("New size: %zu\n", newSize);
        printArray(copyArr, newSize);
    }

    // Задание 3: Преобразование массива
    printf("\n3. Transform array:\n");
    if (transformArray(copyArr, newSize))
    {
        printArray(copyArr, newSize);
    }

    free(copyArr);
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1)
    {
        fprintf(stderr, "Input error\n");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr, "Size must be positive\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Null pointer in fillArray\n");
        exit(1);
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("Input %zu element of array: ", i + 1);
        arr[i] = Value();
    }
}

void printArray(const int* arr, const size_t size)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Null pointer in printArray\n");
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Null pointer in fillRandom\n");
        exit(1);
    }

    printf("Enter range start: ");
    int start = Value();
    printf("Enter range end: ");
    int end = Value();
    
    if (start > end)
    {
        fprintf(stderr, "Start cannot be greater than end\n");
        exit(1);
    }

    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Null pointer in copyArray\n");
        return NULL;
    }

    int* copyArr = malloc(size * sizeof(int));
    if (copyArr == NULL)
    {
        fprintf(stderr, "Memory allocation error in copyArray\n");
        return NULL;
    }

    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int replaceFirstNegativeFirstPositive(int* arr, const size_t size)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Null pointer in replaceFirstNegativeFirstPositive\n");
        return 0;
    }

    int firstPositive = 0;
    int firstNegative = 0;
    size_t negativeIndex = 0;
    bool foundPositive = false;
    bool foundNegative = false;

    // Ищем первый положительный и первый отрицательный элементы
    for (size_t i = 0; i < size; i++)
    {
        if (!foundPositive && arr[i] > 0)
        {
            firstPositive = arr[i];
            foundPositive = true;
        }
        if (!foundNegative && arr[i] < 0)
        {
            firstNegative = arr[i];
            negativeIndex = i;
            foundNegative = true;
        }
        if (foundPositive && foundNegative)
        {
            break;
        }
    }

    if (!foundPositive)
    {
        printf("No positive elements found\n");
        return 0;
    }
    if (!foundNegative)
    {
        printf("No negative elements found\n");
        return 0;
    }

    // Заменяем первый отрицательный на первый положительный
    arr[negativeIndex] = firstPositive;
    return 1;
}

int deleteMultiplesOf7InRange(int* arr, const size_t size, size_t* newSize)
{
    if (arr == NULL || newSize == NULL)
    {
        fprintf(stderr, "Null pointer in deleteMultiplesOf7InRange\n");
        return 0;
    }

    printf("Enter min value: ");
    int min = Value();
    printf("Enter max value: ");
    int max = Value();
    
    if (min > max)
    {
        printf("Max must be greater than min\n");
        return 0;
    }

    // Сдвигаем элементы, не удовлетворяющие условию удаления
    size_t writeIndex = 0;
    int countDeleted = 0;

    for (size_t readIndex = 0; readIndex < size; readIndex++)
    {
        if (arr[readIndex] % 7 == 0 && arr[readIndex] >= min && arr[readIndex] <= max)
        {
            countDeleted++;
        }
        else
        {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    *newSize = writeIndex;

    if (countDeleted == 0)
    {
        printf("No elements to delete\n");
        return 0;
    }

    printf("Deleted %d elements\n", countDeleted);
    return 1;
}

int transformArray(int* arr, const size_t size)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Null pointer in transformArray\n");
        return 0;
    }

    if (size == 0)
    {
        printf("Array is empty\n");
        return 0;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 0)  // Четные индексы (0, 2, 4, ...)
        {
            arr[i] = arr[i] * arr[i] + (int)i;
        }
        else  // Нечетные индексы (1, 3, 5, ...)
        {
            arr[i] = arr[i] * (int)i;
        }
    }
    return 1;
}
