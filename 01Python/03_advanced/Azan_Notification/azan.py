import requests
import datetime
import json
from plyer import notification 
import schedule
import time

response = requests.get("https://api.ipify.org/?format=json")
ip = response.json()['ip']

latitude_longitude  = requests.get(f"https://ipinfo.io/{ip}/json").json()['loc']
latitude , longitude = map(float , latitude_longitude.split(',') )

url = f"https://api.aladhan.com/v1/calendar/{datetime.datetime.now().year}/{datetime.datetime.now().month}?latitude={latitude}&longitude={longitude}"
response = requests.get(url).json()

with open('output.json', 'w') as f:
    json.dump(response, f, indent=4)

day = datetime.datetime.now().day

data_base = response['data'][day-1]['timings']

for key in ['Sunrise','Sunset','Imsak','Midnight','Firstthird','Lastthird']:
    del data_base[key]

def notify(message):
    notification.notify(title='Prayer', message= message,  timeout=5)

for key,value in data_base.items():
    schedule.every().day.at(value[:-7]).do(notify,message=f"Azan El-{key}") 

while True:
    schedule.run_pending()
    time.sleep(10)
