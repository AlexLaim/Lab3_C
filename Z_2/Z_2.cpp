#include "Auto.h"
#include "Minibus.h"
#include "PassengerCar.h"
#include "IFuelConsume.h"

int main()
{
    //Для русского языка
    setlocale(LC_ALL, "ru");
    //Для рандомных значений
    srand(time(NULL));
    Auto* cars[4];
    cars[0] = new PassengerCar(15);
    cars[0]->setCompany("Audi");
    cars[0]->setModel("A8");
    cars[0]->setNumber("BO4H5");
    cars[0]->setPrice(4626593);
    cars[0]->setYearOfProd(2015);
    cars[0]->setMileage();
    cars[1] = new PassengerCar(10);
    cars[1]->setCompany("Chevrolet");
    cars[1]->setModel("Corvette");
    cars[1]->setNumber("CO4H5");
    cars[1]->setPrice(2000000);
    cars[1]->setYearOfProd(2004);
    cars[1]->setMileage();
    cars[2] = new Minibus(7.5);
    cars[2]->setCompany("Ford");
    cars[2]->setModel("Transit");
    cars[2]->setNumber("DO4H5");
    cars[2]->setPrice(4950000);
    cars[2]->setYearOfProd(2022);
    cars[2]->setMileage();
    cars[3] = new Minibus(9.5);
    cars[3]->setCompany("GAZ");
    cars[3]->setModel("Next");
    cars[3]->setNumber("EO4H5");
    cars[3]->setPrice(3507500);
    cars[3]->setYearOfProd(2022);
    cars[3]->setMileage();
    for (size_t i = 0; i < 4; i++)
    {
        cars[i]->printInfo();
    }
    //Работа с пользователем
    bool flag = true;
    while (flag) {
        std::cout << "Выберите действие:\n 1: Сохранить в файл;\n 2: Вывести из файла;\n 3: Выйти" << std::endl;
        int act, count;
        std::string modelCar;
        std::string path;
        Auto newCar;
        std::cin >> act;
        switch (act)
        {
        case 1:
            //Сохранение информации об автомобиле в файл
            std::cout << "Введите модель автомобиля которую нужно сохранить" << std::endl;
            std::cin >> modelCar;
            path = modelCar + ".txt";
            count = 0;
            for (int i = 0;i < 4;i++) {
                if (cars[i]->GetModel() == modelCar) {
                    cars[i]->serialize(path);
                    count++;
                }
            }
            if (count == 0) {
                std::cout << "Данная модель не найдена!" << std::endl;
            }
            else {
                std::cout << "Сохранение в файл прошло успешно!" << std::endl;
            }
            break;
        case 2:
            //Вывод информации об автомобиле из файла
            std::cout << "Введите модель автомобиля информацию о котором нужно получить" << std::endl;
            std::cin >> modelCar;
            path = modelCar + ".txt";
            newCar.deserialize(path);
            std::cout << "Информация по вашему авто: " << std::endl;
            newCar.printInfo();
            std::cout << "Чтение из файла прошло успешно!" << std::endl;
            break;
        case 3:
            //Закрытие программы
            flag = false;
            break;
        default:
            //Дефолтное действие
            std::cout << "Неизвестное действие!" << std::endl;
            break;
        }
    }

}
