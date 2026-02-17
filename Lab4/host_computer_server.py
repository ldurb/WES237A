import socket
import time
import signal
import sys

def run_program():
    sock_1 = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    sock_1.bind(('0.0.0.0',12346))
    sock_1.listen()
    print('waiting for connection!')
    conn,addr = sock_1.accept()
    with conn:
        data = conn.recv(2048)
    print(data.decode())

if __name__ == '__main__':
    original_sigint = signal.getsignal(signal.SIGINT)
    signal.signal(signal.SIGINT,exit)
    run_program()

