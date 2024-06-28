import socket 
import netifaces as ni
import threading

ip = ni.ifaddresses('wlp3s0')[ni.AF_INET][0]['addr']

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

sock.bind((ip ,5000))

sock.listen(5)

def handle_client():
    request = client.recv(1024)
    print(f'request from client {address} --> {request.decode()}')
    response = client.send(f'Done! you have sent {request.decode()}'.encode())
    client.close()

while True:
    client,address = sock.accept()
    thread = threading.Thread(target=handle_client)
    thread.start()
