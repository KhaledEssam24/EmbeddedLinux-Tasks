from bs4 import BeautifulSoup
import random
import pandas as pd

fd = open("doxygen-example/generated-docs/html/classDog.html")
content = fd.read()
fd.close()

functions_sign=list()
functions_paramtype=list()
functions_paramname=list()
functions_IDs=list()

parser = BeautifulSoup(content,'html.parser')

functions_soup = parser.find_all('div' , class_= 'memitem')

for function_soup in functions_soup:
    function_soup = function_soup.find('div' , class_= 'memproto').find('table' , class_= 'memname')

    try:
        paramtype = function_soup.find('td' , class_= 'paramtype').text.strip()
        functions_paramtype.append(paramtype)

        paramname = function_soup.find('td' , class_= 'paramname').text.strip()
        functions_paramname.append(paramname)

        sign = function_soup.find('td' , class_= 'memname').text.strip()
        functions_sign.append(sign)

        functions_IDs.append(random.randint(0,1000000))

    except:
        var = function_soup.find('td' , class_= 'memname').text.strip()
        print(f'{var} is public member not method')
   
data_base = []

for row in range(len(functions_IDs)):
    data_base.append( {
    "Signature":functions_sign[row],
    "Parameters Name":functions_paramname[row],
    "Parameters Type":functions_paramtype[row],
    "IDs":functions_IDs[row],
    })

df = pd.DataFrame.from_dict(data_base) 
df.to_csv ('output.csv', index=False, header=True)
