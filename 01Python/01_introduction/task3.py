import calendar

while True:
    try:
        year = int(input("Enter the year : "))
        if(year<0) : 
            print("Year is negative!!")
            continue
        break
    except ValueError:
        print("Enter a valid year")
    except KeyboardInterrupt:
        print("\nterminated by user")
        break

while True:
    try:
        month = int(input("Enter the month : "))
        if(month<0) : 
            print("month is negative!!")
            continue
        elif(month>12) : 
            print("which month is this!!")
            continue
        break
    except ValueError:
        print("Enter a valid month")
    except KeyboardInterrupt:
        print("\nterminated by user")
        break

print(calendar.month(year,month,w=0,l=0))
