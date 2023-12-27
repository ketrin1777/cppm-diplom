#include "paramdata.h"
#include <Windows.h>
#pragma execution_character_set("utf-8")

int main(int, char **)
{
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    std::cout << "Добро пожаловать в гоночный симулятор!\n";
    bool start = true;
    while (start)
    {

        ParamData param;
        while (param.GetSize() < 2)
        {
            int numb = 0;
            while (numb != 1)
            {
                std::cout << "\nДолжно быть зарегистрировано хотя бы 2 транспортных средства\n1. Зарегистрировать транспорт\nВыберите деиствие: ";
                std::cin >> numb;
            }

            param.Register();
            numb = 0;

            while (numb != 2)
            {
                std::cout << "\n1. Зарегистрировать транспорт\n2. Начать гонку\nВыберите деиствие: ";
                std::cin >> numb;
                if (numb == 1)
                {
                    param.Register();
                }
            }

            param.Result();
            numb = 0;
            while (!(numb == 2 || numb == 1))
            {
                std::cout << "\n1. Провести ещё одну гонку\n2. Выйти\nВыберите деиствие: ";
                std::cin >> numb;
                if (numb == 2)
                {
                    start = false;
                }
            }
            std::cout << "\n\n";
        }
    }
}
