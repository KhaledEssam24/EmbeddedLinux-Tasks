import socket 
import netifaces as ni
from time import sleep

while True:

    client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    ip = ni.ifaddresses('wlp3s0')[ni.AF_INET][0]['addr']

    client.connect((ip ,5000))

    client.send(f'[Client1] this is request for server'.encode())

    response = client.recv(1024).decode()

    print(response)

    client.close()

    sleep(1)
