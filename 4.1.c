#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf

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
void printArray(int* arr, const size_t size);

/**
 * @brief Вычисляет сумму чётных элементов массива
 * @param arr массив
 * @param size размер массива
 */
void sumEven(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 * @param start начало диапазона
 * @param end конец диапазона
 */
void fillRandom(int* arr, const size_t size, const int start, const int end);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет крайний отрицательный элемент массива на модуль первого элемента
 * @param copyArr копия массива
 * @param size размер массива
 * @return Возвращает 1, если функция выполнена корректно, 0 - если в массиве отсутствуют отрицательные элементы
 */
int replaceFirstAbsLastNegative(int* copyArr, const size_t size);

/**
 * @brief Считает количество двузначных элементов массива
 * @param arr массив
 * @param size размер массива
 */
void countTwoDigitNumbers(int* arr, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{
    size_t size = getSize("Input size of an array:\n");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }
    
    printf("Chose the method of filling the array:\n%d - by random\n%d - manually\n", RANDOM, MANUAL);
    int choice = Value();
    
    switch(choice)
    {
        case RANDOM:
            {
                printf("diapozon start:\n");
                const int start = Value();
                printf("diapozon end:\n");
                const int end = Value();
                if (start >= end) {
                    fprintf(stderr, "Error: end must be more than start\n");
                    free(arr);
                    exit(1);
                }
                fillRandom(arr, size, start, end);
                break;
            }
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            fprintf(stderr, "Error: invalid choice\n");
            free(arr);
            exit(1);
    }
    
    printArray(arr, size);
    printf("\n");
    sumEven(arr, size);
    printf("\n");
    countTwoDigitNumbers(arr, size);
    printf("\n");
    
    int* copyArr = copyArray(arr, size);
    if (copyArr != NULL) {
        replaceFirstAbsLastNegative(copyArr, size);
        free(copyArr);
    }
    
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1){
        fprintf(stderr, "Input error");
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
        fprintf(stderr, "Input error: size must be positive\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Error: null pointer in fillArray\n");
        exit(1);
    }
    
    for (size_t i = 0; i < size; i++)
    {
        printf("Input %zu element of array:", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Error: null pointer in printArray\n");
        return;
    }
    
    printf("Your array is:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sumEven(int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Error: null pointer in sumEven\n");
        return;
    }
    
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            result += arr[i];
        }
    }
    printf("Sum of even numbers is %d.\n", result);
}

void fillRandom(int* arr, const size_t size, const int start, const int end)
{
    if (arr == NULL) {
        fprintf(stderr, "Error: null pointer in fillRandom\n");
        exit(1);
    }
    
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Error: null pointer in copyArray\n");
        return NULL;
    }
    
    int* copyArr = malloc(sizeof(int) * size);
    if (copyArr == NULL) {
        fprintf(stderr, "Error: memory allocation failed in copyArray\n");
        return NULL;
    }
    
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

void countTwoDigitNumbers(int* arr, const size_t size) {
    if (arr == NULL) {
        fprintf(stderr, "Error: null pointer in countTwoDigitNumbers\n");
        return;
    }
    
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if ((arr[i] >= 10 && arr[i] <= 99) || (arr[i] <= -10 && arr[i] >= -99)) {
            count++;
        }
    }
    printf("Amount of 2-digit elements is %d.\n", count);
}

int replaceFirstAbsLastNegative(int* copyArr, const size_t size) {
    if (copyArr == NULL) {
        fprintf(stderr, "Error: null pointer in replaceFirstAbsLastNegative\n");
        return 0;
    }
    
    int firstAbs = abs(copyArr[0]);
    for (size_t i = size; i > 0; i--) {
        if (copyArr[i-1] < 0) {
            copyArr[i-1] = firstAbs;
            printf("Your new array is:\n");
            for (size_t j = 0; j < size; j++) {
                printf("%d ", copyArr[j]);
            }
            printf("\n");
            return 1;
        }
    }
    printf("Your array has not negative elements.");
    return 0;
}
