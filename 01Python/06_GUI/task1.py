from tkinter import *

root = Tk()

root.geometry("500x500+450+250")
root.resizable(0,0)

reversed_text=''

def call_back():
    global reversed_text
    reversed_text = Name.get()[::-1]
    label2.config(text=reversed_text)

Name = StringVar() 

label = Label(master=root,text="Enter a word ")
label.place(x=10,y=10)

entry = Entry(master=root , textvariable= Name) 
entry.place(x=120,y=10)

button = Button(master=root , text= "reverse" , command = call_back) 
button.place(x=200,y=50)

label2 = Label (master=root , text = '',bg='grey') 
label2.place(x=200,y=90)

root.mainloop()
