#include <stdio.h>
#include <math.h>

int decSystem(const char*, int); //Прототип функції
char* secondSystem(int, int);
char checkNumber(char*, char*);
char checkSystem(char*, char*);

int main()
{
    //Об'явимо змінні

    char number[256]; //Перше число
    char f_system[256];//Система числа
    char s_system[256]; // Вихідна система


    //Вхід даних
    printf("Enter first number: ");
    scanf_s("%s", &number, 12);

    char negative = number[0] == '-';


    printf("Enter first system: ");
    scanf_s("%s", &f_system, 12);

    //Перевірка на коректність
    while(checkNumber(f_system, number) || checkSystem(f_system, number)){
        printf("System is incorrect, enter one more time :\n");
        scanf_s("%s", &f_system, 12);
    }

    printf("Enter second system: ");
    scanf_s("%s", &s_system, 12);

    while(checkNumber(s_system, number)){
        printf("It's not a number, enter one more time :\n");
        scanf_s("%s", &s_system, 12);
    }

     //Перевірка для від'ємних чисел
    if(negative == 1)
        printf("-");

    //Основна функція
    secondSystem(decSystem(number, atoi(f_system)), atoi(s_system));


    return 0;
}

    //Функція для переведення в 10-ну систему
int decSystem(const char* number, int inputSystem)
{
    char negative = number[0] == '-';

    int length = 0; //Кількість символів числа

    int k = 1; //Коефіцієнт

    while (number[++length]); //Визначимо кіл-ть символів циклом while

    int result = 0; //Результат переведення

    for (int i = length - 1; i >= negative; --i)
    {
        result += ((number[i] >= '0' && number[i] <= '9') ? (number[i] - '0') : (10 + number[i] - 'A')) * k;
        k *= inputSystem;
    }

    return result;
}
    //Функція для переведення в іншу систему
char* secondSystem(int number, int outputSystem)
{
    int size = 0;
    while (pow(outputSystem, ++size) <= number);

    do
    {
        --size;

        int n = 0;

        int p = pow(outputSystem, size);

        while (p <= number)
        {
          number -= p;
          ++n;
        }

        if (n < 10)
          printf("%i ", n);
        else
          printf("%c ", 'A' + n - 10);
    } while (size > 0);

    return 0;
}
    //Перевірка числа
char checkNumber(char* c_system, char* number){

    for(int i = 0; c_system[i]; ++i)
    {
        if(!(c_system[i] >= '0' && c_system[i] <= '9'))
        {
            return 1;
        }
    }

    return 0;
}
    //Перевірка системи
char checkSystem(char* c_system, char* number){

    int i_system = atoi(c_system);

    for(int i = 0; number[i]; ++i)
    {
        if (i_system == 1 && number[i] != '1')
          return 1;
        if (number[i] < 'A' ? number[i] - '0' >= i_system : number[i] - 'A' + 10 >= i_system)
        {
          return 1;
        }
    }

  return 0;
}
