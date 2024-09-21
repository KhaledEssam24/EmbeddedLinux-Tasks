import pyfiglet as pf
import os


print(pf.figlet_format("Task 1"))
while True:
    try:
        given_data = input("Enter a list of integers separated by commas: ")
        given_num  = int(input("Enter a number you want to count: "))

        given_list = [int(i.strip()) for i in given_data.split(',')]

        print(f"Number {given_num} count is:", given_list.count(given_num))
        break
    except ValueError:
        print("Please enter valid data")
        continue
    except KeyboardInterrupt:
        print("\nProgram terminated by user")
        break


print(pf.figlet_format("Task 2"))
letter=input("Enter a letter : ")
print("Vowel") if letter in ['a','e','o','u','i'] else print("non Vowel") 


print(pf.figlet_format("Task 3"))
print("current work directory is ",os.getcwd())