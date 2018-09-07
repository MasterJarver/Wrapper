#include <iostream>
#include <string>
#include <dlfcn.h>
#include "libloader.cpp"
using namespace std;
/*
    root_path = "/lib/x86_64-linux-gnu/";
    m_libname("libc-2.27.so")
*/
int main()
{
    libloader libc("/lib/x86_64-linux-gnu/", "libc-2.27.so");
    cout << "Result:" <<  libc.abs(-23) << endl;
    return 0;
}
