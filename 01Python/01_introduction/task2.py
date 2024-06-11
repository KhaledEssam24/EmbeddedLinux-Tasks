import math

while(True):
    try:
        radius = float(input("Enter the radius of circle : "))
        print("Area of the circle : ",round(math.pi * math.pow(radius,2),2))
        break
    except ValueError:
        print("Enter valid radius")
        continue
    except KeyboardInterrupt:
        print("\nProgram terminated by user")
        break

