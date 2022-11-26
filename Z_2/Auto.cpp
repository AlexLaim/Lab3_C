#include "Auto.h"


Auto::Auto(){}
Auto::Auto(std::string company_, std::string model_, std::string number_, int price_, int yearOfProd_, unsigned int mileage_){
    company = company_;
    model = model_;
    number = number_;
    price = price_;
    yearOfProd = yearOfProd_;
    mileage = mileage_;
}
void Auto::setCompany(const std::string& company_){
    company = company_;
}
void Auto::setModel(const std::string& model_){ 
    model = model_; 
}
void Auto::setNumber(const std::string& number_){
    number = number_;
}
void Auto::setPrice(int price_){
    price = price_;
}
void Auto::setYearOfProd(int yearOfProd_){
    yearOfProd = yearOfProd_;
}
int Auto::setMileage() {
    for (int i = 0; i < 3; i++) {
        mileage += (1000 + rand() % (10000 - 1000 + 1));
    }
    return mileage;
}
int Auto::getMileage(Auto car) {
    return car.mileage;
}
void Auto::printInfo() {
    std::cout << "Фирма: " << this->company << std::endl;
    std::cout << "Модель: " << this->model << std::endl;
    std::cout << "Номер: " << this->number << std::endl;
    std::cout << "Цена: " << this->price << std::endl;
    std::cout << "Год выпуска: " << this->yearOfProd << std::endl;
    std::cout << "Пробег: " << this->mileage << " км." << std::endl;
    if (this->consumeAuto == 0) {
        std::cout << "Расход топлива: " << this->consume(this->mileage) << " л." << std::endl;
    }
    else
    {
        std::cout << "Расход топлива: " << this->consumeAuto << " л." << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------\n";
}
void Auto::deserialize(const std::string filename) {
    std::fstream fs;
    std::ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        exit(0);
    }
    else {
        fin >> company >> model >> number >> price >> yearOfProd >> mileage >> consumeAuto;

        fin.close();
    }
}
void Auto::serialize(const std::string filename) {
    std::ofstream fs;
    //SetConsoleCP(1251); //Для ввода русских букв в файл
    fs.open(filename);
    if (!fs.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        exit(0);
    }
    else {
        fs << company << "\n" << model << "\n" << number << "\n" << price << "\n" << yearOfProd << "\n" << this->mileage << "\n" << this->consume(this->mileage) << "\n";
        fs.close();
    }
    //SetConsoleCP(866); //Обязательно возвращаем значение
}
std::string Auto::GetModel() {
    return this->model;
}
int Auto::GetYearOfProd(Auto car) {
    return car.yearOfProd;
}
std::string Auto::GetNumber(Auto car) {
    return car.number;
}
double Auto::consume(int distance) {
    return 0;
}