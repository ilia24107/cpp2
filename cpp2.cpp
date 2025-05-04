#include <iostream>
#include <vector>
using namespace std;

// ANSI цветовые коды
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
    virtual void printInfo() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    void printInfo() const override {
        cout << BOLD << CYAN << "○ Круг:" << RESET << " радиус = " << GREEN << radius 
             << RESET << ", площадь = " << GREEN << area() << RESET << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    void printInfo() const override {
        cout << BOLD << CYAN << "□ Прямоугольник:" << RESET << " ширина = " << GREEN << width 
             << RESET << ", высота = " << GREEN << height << RESET << ", площадь = " 
             << GREEN << area() << RESET << endl;
    }
};

void shapeDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация фигур ===" << RESET << endl;
    vector<Shape*> shapes = {
        new Circle(5),
        new Rectangle(4, 6)
    };
    
    for (auto shape : shapes) {
        shape->printInfo();
        delete shape;
    }
};

class Animal {
public:
    virtual void sound() const = 0;
    virtual ~Animal() {}
    virtual void printInfo() const = 0;
};

class Dog : public Animal {
public:
    void sound() const override { cout << BOLD << "Гав!" << RESET; }
    void printInfo() const override {
        cout << BLUE << "🐶 Собака: " << RESET;
        sound();
        cout << endl;
    }
};

class Cat : public Animal {
public:
    void sound() const override { cout << BOLD << "Мяу!" << RESET; }
    void printInfo() const override {
        cout << MAGENTA << "🐱 Кошка: " << RESET;
        sound();
        cout << endl;
    }
};

void animalDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация животных ===" << RESET << endl;
    vector<Animal*> animals = {
        new Dog(),
        new Cat()
    };
    
    for (auto animal : animals) {
        animal->printInfo();
        delete animal;
    }
};

class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
    virtual void printInfo() const = 0;
};

class FullTimeEmployee : public Employee {
    double monthlySalary;
public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {}
    double calculateSalary() const override { return monthlySalary; }
    void printInfo() const override {
        cout << GREEN << "🧑‍💼 Полный рабочий день: " << RESET << "зарплата = " 
             << BOLD << GREEN << calculateSalary() << RESET << endl;
    }
};

class PartTimeEmployee : public Employee {
    double hourlyRate;
    int hours;
public:
    PartTimeEmployee(double rate, int h) : hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
    void printInfo() const override {
        cout << CYAN << "👨‍💼 Частичная занятость: " << RESET << "ставка = " << hourlyRate 
             << ", часы = " << hours << ", зарплата = " << BOLD << GREEN 
             << calculateSalary() << RESET << endl;
    }
};

void employeeDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация сотрудников ===" << RESET << endl;
    vector<Employee*> employees = {
        new FullTimeEmployee(5000),
        new PartTimeEmployee(20, 80)
    };
    
    for (auto emp : employees) {
        emp->printInfo();
        delete emp;
    }
};

class Vehicle {
public:
    virtual void move() const = 0;
    virtual ~Vehicle() {}
    virtual void printInfo() const = 0;
};

class Car : public Vehicle {
public:
    void move() const override { cout << "Машина едет" << RESET; }
    void printInfo() const override {
        cout << RED << "🚗 Машина: " << RESET;
        move();
        cout << endl;
    }
};

class Bike : public Vehicle {
public:
    void move() const override { cout << "Велосипед крутит педали" << RESET; }
    void printInfo() const override {
        cout << BLUE << "🚲 Велосипед: " << RESET;
        move();
        cout << endl;
    }
};

void vehicleDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация транспорта ===" << RESET << endl;
    vector<Vehicle*> vehicles = {
        new Car(),
        new Bike()
    };
    
    for (auto v : vehicles) {
        v->printInfo();
        delete v;
    }
};

class Account {
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual void withdraw(double amount) = 0;
    virtual ~Account() {}
    virtual void printInfo() const = 0;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        if (balance - amount >= 0) balance -= amount;
    }
    void printInfo() const override {
        cout << GREEN << "💰 Сберегательный счет: " << RESET << "баланс = " 
             << BOLD << GREEN << balance << RESET << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        balance -= amount;
    }
    void printInfo() const override {
        cout << CYAN << "💳 Текущий счет: " << RESET << "баланс = " 
             << BOLD << GREEN << balance << RESET << endl;
    }
};

void accountDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация банковских счетов ===" << RESET << endl;
    vector<Account*> accounts = {
        new SavingsAccount(1000),
        new CheckingAccount(1000)
    };
    
    for (auto acc : accounts) {
        acc->withdraw(200);
        acc->printInfo();
        delete acc;
    }
};

class Media {
public:
    virtual void play() const = 0;
    virtual ~Media() {}
    virtual void printInfo() const = 0;
};

class Audio : public Media {
public:
    void play() const override { cout << "Воспроизводится аудио..." << RESET; }
    void printInfo() const override {
        cout << MAGENTA << "🔊 Аудио: " << RESET;
        play();
        cout << endl;
    }
};

class Video : public Media {
public:
    void play() const override { cout << "Воспроизводится видео..." << RESET; }
    void printInfo() const override {
        cout << BLUE << "📹 Видео: " << RESET;
        play();
        cout << endl;
    }
};

void mediaDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация медиа ===" << RESET << endl;
    vector<Media*> media = {
        new Audio(),
        new Video()
    };
    
    for (auto m : media) {
        m->printInfo();
        delete m;
    }
};

class Person {
public:
    virtual void introduce() const = 0;
    virtual ~Person() {}
    virtual void printInfo() const = 0;
};

class Student : public Person {
public:
    void introduce() const override { cout << "Я студент" << RESET; }
    void printInfo() const override {
        cout << YELLOW << "🎓 Студент: " << RESET;
        introduce();
        cout << endl;
    }
};

class Teacher : public Person {
public:
    void introduce() const override { cout << "Я учитель" << RESET; }
    void printInfo() const override {
        cout << RED << "👨‍🏫 Учитель: " << RESET;
        introduce();
        cout << endl;
    }
};

void personDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация людей ===" << RESET << endl;
    vector<Person*> people = {
        new Student(),
        new Teacher()
    };
    
    for (auto p : people) {
        p->printInfo();
        delete p;
    }
};

class Book {
public:
    virtual void getInfo() const = 0;
    virtual ~Book() {}
    virtual void printInfo() const = 0;
};

class EBook : public Book {
public:
    void getInfo() const override { cout << "Электронная книга" << RESET; }
    void printInfo() const override {
        cout << CYAN << "📱 ";
        getInfo();
        cout << endl;
    }
};

class PrintedBook : public Book {
public:
    void getInfo() const override { cout << "Печатная книга" << RESET; }
    void printInfo() const override {
        cout << GREEN << "📖 ";
        getInfo();
        cout << endl;
    }
};

void bookDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация книг ===" << RESET << endl;
    vector<Book*> books = {
        new EBook(),
        new PrintedBook()
    };
    
    for (auto b : books) {
        b->printInfo();
        delete b;
    }
};

class Appliance {
public:
    virtual void turnOn() const = 0;
    virtual ~Appliance() {}
    virtual void printInfo() const = 0;
};

class WashingMachine : public Appliance {
public:
    void turnOn() const override { cout << "Стиральная машина запущена" << RESET; }
    void printInfo() const override {
        cout << BLUE << "🧺 Стиральная машина: " << RESET;
        turnOn();
        cout << endl;
    }
};

class Refrigerator : public Appliance {
public:
    void turnOn() const override { cout << "Холодильник охлаждает" << RESET; }
    void printInfo() const override {
        cout << WHITE << "❄️ Холодильник: " << RESET;
        turnOn();
        cout << endl;
    }
};

void applianceDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация бытовой техники ===" << RESET << endl;
    vector<Appliance*> appliances = {
        new WashingMachine(),
        new Refrigerator()
    };
    
    for (auto a : appliances) {
        a->printInfo();
        delete a;
    }
};

class Game {
public:
    virtual void play() const = 0;
    virtual ~Game() {}
    virtual void printInfo() const = 0;
};

class BoardGame : public Game {
public:
    void play() const override { cout << "Играем в настольную игру" << RESET; }
    void printInfo() const override {
        cout << GREEN << "🎲 Настольная игра: " << RESET;
        play();
        cout << endl;
    }
};

class VideoGame : public Game {
public:
    void play() const override { cout << "Играем в видеоигру" << RESET; }
    void printInfo() const override {
        cout << MAGENTA << "🎮 Видеоигра: " << RESET;
        play();
        cout << endl;
    }
};

void gameDemo() {
    cout << BOLD << YELLOW << "\n=== Демонстрация игр ===" << RESET << endl;
    vector<Game*> games = {
        new BoardGame(),
        new VideoGame()
    };
    
    for (auto g : games) {
        g->printInfo();
        delete g;
    }
};

int main() {
    shapeDemo();
    animalDemo();
    employeeDemo();
    vehicleDemo();
    accountDemo();
    mediaDemo();
    personDemo();
    bookDemo();
    applianceDemo();
    gameDemo();
    
    return 0;
}