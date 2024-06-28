import os

user_choice_list = ["Init" , "Write" ,"Read"]

user_choices = input(f"Select from this List what you need seperated by commas if you need more than choice {user_choice_list} : ")

port = input(f"Select Port from A-F : ").upper().strip()

try:
    user_choices = user_choices.split(',')
except:
    user_choices = user_choices.split()


if port in ['A','B','C','D','E','F']:
        
    with open("gpio.c", 'w') as fd:

        fd.write("// This file is generated using python script\n\n\n")

        for user_choice in user_choices:

            if user_choice.capitalize().strip() in user_choice_list:

                if(user_choice.startswith("In")) :
                    pin_modes = [input(f"please enter Bit {pin} mode : ") for pin in range(8)]  
                    fd.write(f"void Init_Gpio(){{\n     DDR{port} = {''.join(pin_modes)};\n}}\n\n")

                elif(user_choice.startswith("Wr")) :
                    pin_status = [input(f"please enter Bit {pin} status : ") for pin in range(8)]
                    fd.write(f"void Write_Gpio(){{\n     PIN{port} = {''.join(pin_status)};\n}}\n\n")

                elif(user_choice.startswith("Re")) :
                    fd.write(f"gpio_port Read_Gpio(){{\n     return PORT{port};\n}}\n\n")

else :
    print("enter valid port !!")
        
