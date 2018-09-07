//#include "libloader.h"
#include <iostream>
#include <string>
#include <dlfcn.h>
using namespace std;
class libloader {
public:
    typedef int (*libc_abs)(int value); // псевдоним libc_abs указателя на функцию, принимающий int и возвращающий int
    typedef void* lib_ptr; // псевдоним lib_ptr, который является указателем на неопределенный тип
    int (*p)(int value); // указатель на функцию, которая принимает int и возвращает int с именем p
    //libc_abs p; // передача в метод, в качестве аргумента указателя на int
    libloader(string root_path, string m_libname) // конструктор, принимающий пусть к библиотеке и имя библиотеки
    {
        this->root_path = root_path; // присвоение пути к библиотеке
        this->m_libname = m_libname; // присвоение имени библиотеки
        m_libptr = dlopen(string(root_path + m_libname).c_str(), RTLD_NOW); // присваиваем указателю на библиотеку результат работы функции dlopen
        abs_ptr = (libc_abs)dlsym(m_libptr, "abs"); // присвоение указателю на функцию в библиотеке результата функции dlsym(указатель на библиотеку, "имя функции")
        //abs_ptr(-2);
    }
    ~libloader() // деструктор
    {
        dlclose(m_libptr); // присвоение нулевого указателя указателю на динамическую библиотеку и выгрузка библиотеки
    }
//    const string& libname() const // пока не понятно
//    {
//        return m_libname; // возвращает имя библиотеки
//    }
    int abs(int value) // функция abs принимающая int
    {
        return abs_ptr(value); //возвращает указатель на функцию abs в динамической библиотеке с числом value в качесте аргумента
    }
private:
    string root_path; // путь к директории с динамической библиотекой
    string m_libname; // имя динамической библиотеки
    lib_ptr m_libptr = nullptr; // указатель на библиотеку
    libc_abs abs_ptr = nullptr; // указатель на функцию в библиотеке
};
