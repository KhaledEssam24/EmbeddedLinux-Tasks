from tkinter import *

root = Tk()

root.geometry("500x500+450+250")
root.resizable(0,0)

def call_back():
    try:
        if(choice.get() == 1):
            label3.config(text=f"the sum is {int(Num_M.get()) + int(Num_N.get())}")
        elif(choice.get() == 2):
            label3.config(text=f"the sub is {int(Num_M.get()) - int(Num_N.get())}")
        elif(choice.get() == 3):
            label3.config(text=f"the mul is {int(Num_M.get()) * int(Num_N.get())}")
        elif(choice.get() == 4):
            label3.config(text=f"the div is {int(Num_M.get()) / int(Num_N.get())}")
    except:
        label3.config(text="Enter Valid numbers")

Num_M = StringVar() 
Num_N = StringVar() 
choice = IntVar()

label1 = Label(master=root,text="Enter the value of M")
label1.place(x=10,y=10)

entry1 = Entry(master=root , textvariable= Num_M) 
entry1.place(x=160,y=10)

label2 = Label(master=root,text="Enter the value of N")
label2.place(x=10,y=50)

entry2 = Entry(master=root , textvariable = Num_N) 
entry2.place(x=160,y=50)

radio_sum = Radiobutton(master=root, text='Sum' , variable=choice ,value=1, command= call_back)
radio_sum.place(x=200,y=100)

radio_sub = Radiobutton(master=root, text='Sub' , variable=choice ,value=2, command= call_back)
radio_sub.place(x=200,y=120)

radio_mul = Radiobutton(master=root, text='Mul' , variable=choice ,value=3, command= call_back)
radio_mul.place(x=200,y=140)

radio_div = Radiobutton(master=root, text='Div' , variable=choice ,value=4, command= call_back)
radio_div.place(x=200,y=160)

label3 = Label(master=root, text="")
label3.place(x=180,y=200)

root.mainloop()
