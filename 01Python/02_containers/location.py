import requests

response = requests.get("https://api.ipify.org/?format=json")

ip = response.json()['ip']

response = requests.get(f"https://ipinfo.io/{ip}/geo")

print("Country : ",response.json()['country'])
print("Region : ",response.json()['region'])
print("City : ",response.json()['city'])
print("TimeZone : ",response.json()['timezone'])

