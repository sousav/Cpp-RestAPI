/**
 * @Author: Victor Sousa <vicostudio>
 * @Date:   21/04/2018 00:55:40
 * @Email:  victor.sousa@epitech.eu
 * @Last modified by:   vicostudio
 * @Last modified time: 12/05/2018 17:42:36
 */

#ifndef SHAREDLOADER_H_
#define SHAREDLOADER_H_

#include <string>
#include <dlfcn.h>
#include <iostream>

void def_sym();

#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>

std::string GetCurrentWorkingDir( void ) {
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    return current_working_dir;
}


template <class T>
class SharedLib {
public:
    SharedLib(std::string const &path) {
        this->load(GetCurrentWorkingDir() + "/" + path);
    }
    ~SharedLib() {
        this->_destroy(this->_library);
    }

    T &get() {
        return *this->_library;
    }

private:
    void load(std::string const &path) {
        void* handle = dlopen(path.c_str(), RTLD_LAZY);

        this->_create = (T* (*)())dlsym(handle, "create_object");
        this->_destroy = (void (*)(T*))dlsym(handle, "destroy_object");

        this->_library = this->_create();
    }

private:
    T* _library;
    T* (*_create)();
    void (*_destroy)(T*);
};

#endif //SHAREDLOADER_H_
