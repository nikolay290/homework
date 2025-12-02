#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/**
 * @brief Считывает значение, введенное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int Value(void);

/**
 * @brief Получение размера массива
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(char* message);

/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Вывод массива на экран
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заполнение массива случайными числами
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Создаёт массив по указанным пользователем вводным данным
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return полученный массив
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождает память, выделенную под массив
 * @param arr массив
 * @param rows количество строк массива
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief Проверяет корректность диапазона случайных чисел
 * @param start Начало диапазона
 * @param end Конец диапазона
 */
void checkRange(const int start, const int end);

/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 * @return Полученный массив
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заменяет минимальный по модулю элемент каждого столбца на противоположный
 * @param copyArr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 */
void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns);

/**
 * @brief Находит максимальное значение в массиве
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 * @return максимальное значение в массиве
 */
int findMaxValue(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Определяет количество строк, которые не содержат максимальное значение
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @param max максимальное значение
 * @return количество строк для сохранения
 */
size_t rowsToKeepCount(int** arr, const size_t rows, const size_t columns, const int max);

/**
 * @brief Удаляет все строки массива с максимальным значением
 * @param copyArr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return новый массив после удаления строк
 */
int** delRowsWithMax(int** copyArr, size_t* rows, const size_t columns);

/**
 * @brief RANDOM - заполнение массива случайными числами
 * @brief MANUAL - заполнение массива вручную.
 */
enum { RANDOM = 1, MANUAL };

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main(void)
{
    char* locale = setlocale(LC_ALL, "");
    size_t rows = getSize("Введите количество строк массива: ");
    size_t columns = getSize("Введите количество столбцов массива: ");

    int** arr = getArray(rows, columns);

    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами\n"
        "%d - вручную\n"
        "Введите нужный номер заполнения: ",
        RANDOM, MANUAL);
    int choice = Value();

    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, rows, columns);
        break;
    case MANUAL:
        fillArray(arr, rows, columns);
        break;
    default:
        printf("Ошибка!\n");
        freeArray(arr, rows);
        return 1;
    }

    printf("Исходный массив:\n");
    printArray(arr, rows, columns);

    int** copyArr = copyArray(arr, rows, columns);
    printf("Замена минимального по модулю элемента в каждом столбце на противоположный:\n");
    replaceMinOpposite(copyArr, rows, columns);
    printArray(copyArr, rows, columns);

    printf("Удаление строк с максимальным элементом:\n");
    size_t newRows = rows;
    int** newArr = delRowsWithMax(copyArr, &newRows, columns);

    if (newRows == 0) {
        printf("Все строки были удалены.\n");
    }
    else {
        printArray(newArr, newRows, columns);
    }

    freeArray(arr, rows);
    freeArray(copyArr, rows);
    freeArray(newArr, newRows);

    return 0;
}

int Value(void)
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Ошибка!\n");
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
        printf("Ошибка!");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    printf("Введите минимальное значение: ");
    int start = Value();
    printf("Введите максимальное значение: ");
    int end = Value();
    checkRange(start, end);

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (end - start + 1)) + start;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        exit(1);
    }
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Ошибка выделения памяти.\n");
            for (size_t j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);
            exit(1);
        }
    }
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    if (arr != NULL) {
        for (size_t i = 0; i < rows; i++)
        {
            free(arr[i]);
        }
        free(arr);
    }
}

void checkRange(const int start, const int end)
{
    if (start > end)
    {
        printf("Ошибка, конец должен быть больше начала!\n");
        exit(1);
    }
}

int** copyArray(int** arr, const size_t rows, const size_t columns)
{
    int** copyArr = getArray(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}

void replaceMinOpposite(int** copyArr, const size_t rows, const size_t columns)
{
    for (size_t j = 0; j < columns; j++)
    {
        size_t minIndex = 0;
        int minAbs = abs(copyArr[0][j]);
        for (size_t i = 1; i < rows; i++)
        {
            int curAbs = abs(copyArr[i][j]);
            if (curAbs < minAbs)
            {
                minAbs = curAbs;
                minIndex = i;
            }
        }
        copyArr[minIndex][j] = -copyArr[minIndex][j];
    }
}

int findMaxValue(int** arr, const size_t rows, const size_t columns)
{
    int max = arr[0][0];
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

size_t rowsToKeepCount(int** arr, const size_t rows, const size_t columns, const int max)
{
    size_t count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        int containsMax = 0;
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] == max)
            {
                containsMax = 1;
                break;
            }
        }
        if (!containsMax)
        {
            count++;
        }
    }
    return count;
}

int** delRowsWithMax(int** copyArr, size_t* rows, const size_t columns)
{
    if (*rows == 0) return NULL;

    int max = findMaxValue(copyArr, *rows, columns);
    size_t countToKeep = rowsToKeepCount(copyArr, *rows, columns, max);

    if (countToKeep == 0)
    {
        *rows = 0;
        return NULL;
    }

    int** newArr = getArray(countToKeep, columns);
    size_t newIndex = 0;

    for (size_t i = 0; i < *rows; i++)
    {
        int containsMax = 0;
        for (size_t j = 0; j < columns; j++)
        {
            if (copyArr[i][j] == max)
            {
                containsMax = 1;
                break;
            }
        }

        if (!containsMax)
        {
            for (size_t j = 0; j < columns; j++)
            {
                newArr[newIndex][j] = copyArr[i][j];
            }
            newIndex++;
        }
    }

    *rows = countToKeep;
    return newArr;
}
