#pragma once

#include <iostream>
#include <ostream>

class INT{
    private:
        int number;

    public:
        INT()=delete;
        INT(int number):number(number){
            std::cout<<"param constructor"<<std::endl;
        }

        //copy constructor
        INT(const INT& obj):number(obj.number){
            std::cout<<"copy constructor"<<std::endl;
        }    

        //copy assignment
        INT& operator=(const INT& obj){   
            std::cout<<"copy assignment"<<std::endl;          
            if(this != &obj)
                number=obj.number;
            return *this;
        }

        //move constructor
        INT(INT&& obj):number(obj.number){ 
            std::cout<<"move constructor"<<std::endl;          
            obj.number=0;
        }

        //move assignment
        INT& operator=(INT&& obj){       
            std::cout<<"move assignment"<<std::endl;               
            if(this != &obj)
            {
                number=obj.number;
                obj.number=0;
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os ,INT& obj);

        // Addition operator
        INT operator+(const INT &obj) const {
            return INT(number + obj.number);
        }

        // Subtraction operator
        INT operator-(const INT &obj) const {
            return INT(number - obj.number);
        }

        // Multiplication operator
        INT operator*(const INT &obj) const {
            return INT(number * obj.number);
        }

        // Division operator
        INT operator/(const INT &obj) const {
            if (obj.number == 0) {
                throw std::runtime_error("Division by zero");
            }
            return INT(number / obj.number);
        }

        // Modulus operator
        INT operator%(const INT &obj) const {
            if (obj.number == 0) {
                throw std::runtime_error("Modulus by zero");
            }
            return INT(number % obj.number);
        }

        // Increment operators
        INT& operator++() { // Prefix
            ++number;
            return *this;
        }

        // Decrement operators
        INT& operator--() { // Prefix
            --number;
            return *this;
        } 

        // Equality operator
        bool operator==(const INT &obj) const {
            return number == obj.number;
        }

        // Inequality operator
        bool operator!=(const INT &obj) const {
            return number != obj.number;
        }

        // Less than operator
        bool operator<(const INT &obj) const {
            return number < obj.number;
        }

        // Greater than operator
        bool operator>(const INT &obj) const {
            return number > obj.number;
        }

        // Less than or equal to operator
        bool operator<=(const INT &obj) const {
            return number <= obj.number;
        }

        // Greater than or equal to operator
        bool operator>=(const INT &obj) const {
            return number >= obj.number;
        }
};
