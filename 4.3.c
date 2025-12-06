#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Выводит массив на экран
 * @param arr массив
 * @param rows количесство строк массива
 * @param columns количество столбцов массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заполняет массив случайными числами в выбранном пользователе диапазоне
 * @param arr массив
 * @param rows количество строк
 * @param columns количество столбцов
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Создаёт массив по указанным пользователем вводным данным
 * @param rows количество строк
 * @param columns количество столбцов
 * @return полученный массив
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождает память, выделенную под массив
 * @param arr массив
 * @param rows количество строк
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief Заменяет минимальный по модулю элемент каждого столбца на противоположный
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количство столбцов массива
 */
void replaceMinOpposite(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Подсчитывает количество строк, которые нужно сохранить (без максимального элемента)
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return количество строк без максимального элемента
 */
size_t getCountRowsWithoutMax(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Удаляет все строки массива с максимальным значением
 * @param arr массив
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return новый массив после удаления строк
 */
int** delRowsWithMax(int** arr, const size_t rows, const size_t columns, size_t newRows);

/**
 * @brief Проверяет, что минимальное значенье меньше максимального
 * @param min минимальное значение
 * @param max максимальное значение
 */
void checkRange(const int min, const int max);

/**
 * @brief Создаёт копию массива для дальнейшей работы с ней
 * @param arr изначальный массив
 * @param rows количество строк
 * @param columns количество столбцов
 * @return копию массива
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);
/**
* @param RANDOM - Заполнение массива случайными числами
* @param MANUAL - Заполнение массива вручную
*/
enum { RANDOM = 1, MANUAL };

int main(void)
{
    srand(time(NULL));

    size_t rows = getSize("Введите количество строк массива:  ");
    size_t columns = getSize("Введите количество столбцов массива:  ");

    int** arr = getArray(rows, columns);

    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
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
        printf("Ошибка выбора\n");
        freeArray(arr, rows);
        return 1;
    }

    printf("\nИсходный массив:\n");
    printArray(arr, rows, columns);

    // 1. Замена минимальных по модулю элементов
    int** copyArr = copyArray(arr, rows, columns);
    replaceMinOpposite(copyArr, rows, columns);
    printf("После замены минимальных по модулю элементов в каждом столбце:\n");
    printArray(copyArr, rows, columns);

    // 2. Удаление строк с максимальными элементами
    size_t newRows = getCountRowsWithoutMax(arr, rows, columns);
    printf("Удаление строк с максимальными элементами:\n");

    if (newRows > 0)
    {
        int** newArr = delRowsWithMax(arr, rows, columns, newRows);
        printArray(newArr, newRows, columns);
        freeArray(newArr, newRows);
    }
    else
    {
        printf("Все строки были удалены (все содержали максимальный элемент)\n");
    }

    freeArray(arr, rows);
    freeArray(copyArr, rows);

    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Ошибка ввода\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("Ошибка: размер должен быть положительным\n");
        abort();
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
    int min = Value();
    printf("Введите максимальное значение: ");
    int max = Value();
    checkRange(min, max);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (max - min + 1)) + min;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Ошибка выделения памяти\n");
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
    for (size_t i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        printf("Ошибка: минимальное значение больше максимального\n");
        exit(1);
    }
}

void replaceMinOpposite(int** arr, const size_t rows, const size_t columns)
{
    for (size_t j = 0; j < columns; j++)
    {
        // 1. Находим минимальное значение по модулю
        int minAbs = abs(arr[0][j]);
        for (size_t i = 1; i < rows; i++)
        {
            int currentAbs = abs(arr[i][j]);
            if (currentAbs < minAbs)
            {
                minAbs = currentAbs;
            }
        }

        // 2. Меняем ВСЕ элементы с таким модулем
        for (size_t i = 0; i < rows; i++)
        {
            if (abs(arr[i][j]) == minAbs)
            {
                arr[i][j] = -arr[i][j];
            }
        }
    }
}
size_t getCountRowsWithoutMax(int** arr, const size_t rows, const size_t columns)
{
    // Находим максимальное значение
    int maxValue = arr[0][0];
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] > maxValue)
            {
                maxValue = arr[i][j];
            }
        }
    }

    // Считаем строки без максимального значения
    size_t count = 0;
    for (size_t i = 0; i < rows; i++)
    {
        bool hasMax = false;
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] == maxValue)
            {
                hasMax = true;
                break;
            }
        }
        if (!hasMax)
        {
            count++;
        }
    }

    return count;
}

int** delRowsWithMax(int** arr, const size_t rows, const size_t columns, size_t newRows)
{
    // Находим максимальное значение
    int maxValue = arr[0][0];
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] > maxValue)
            {
                maxValue = arr[i][j];
            }
        }
    }

    // Создаем новый массив
    int** newArr = getArray(newRows, columns);

    // Копируем строки без максимального значения
    size_t newIndex = 0;
    for (size_t i = 0; i < rows; i++)
    {
        bool hasMax = false;
        for (size_t j = 0; j < columns; j++)
        {
            if (arr[i][j] == maxValue)
            {
                hasMax = true;
                break;
            }
        }

        if (!hasMax)
        {
            for (size_t j = 0; j < columns; j++)
            {
                newArr[newIndex][j] = arr[i][j];
            }
            newIndex++;
        }
    }

    return newArr;
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
