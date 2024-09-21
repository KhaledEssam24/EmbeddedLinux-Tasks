#pragma once

#include <cstring>
#include <iostream>
#include <ostream>


class STRING{
    private:
        char* str;
        int size;
    public:
        /*param constructor*/
        STRING(const char* l_str,int size):size(size){
            str = new char[size];
            strcpy(str, l_str);
            std::cout << "param constructor" << std::endl;
        }

        /*copy constructor*/
        STRING(const STRING & obj):size(obj.size){
            str = new char[size];
            strcpy(str, obj.str);
            std::cout << "copy constructor" << std::endl;
        }

        /*copy assignment*/
        STRING& operator=(const STRING & obj){
            if (this != &obj) {
                size=obj.size;
                delete [] str;
                str = new char[size];
                strcpy(str, obj.str);
                std::cout << "copy assignment" << std::endl;
            }
            return *this;
        }

        /*move constructor*/
        STRING(STRING && obj):size(obj.size),str(obj.str){  //it's acceptable here str(obj.str) but in copy it's not as in move it's OK temporarly
                                                            //that 2 objects have the same pointers to sth as one of them should be deleted            
            obj.str = nullptr;
            obj.size = 0;
            std::cout << "move constructor" << std::endl;
        }

        /*move assignment*/
        STRING& operator=(STRING&& obj){
            if (this != &obj) {
                size=obj.size;
                delete [] str;
                str = obj.str;

                obj.size=0;
                obj.str = nullptr;

            }
            std::cout << "move assignment" << std::endl;
            return *this;
        }

       ~STRING(){
            delete [] str;
       } 

        friend std::ostream& operator<<(std::ostream& os ,STRING& obj);
};