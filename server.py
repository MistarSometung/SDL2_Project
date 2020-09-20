from socket import *
import time
import _thread


def ball_position():
    
    pass


def send_data(con, addr):
    con.send(b'Bem-vindo ao servidor do PONG.')
    ball_pos = 0

    while True:
        data = con.recv(1)
        print(data)
        if data == b'0':
            con.send(str(ball_pos).encode('UTF-8').zfill(3))
            ball_pos += 1    

        elif data == b'1':
            con.send(str(ball_pos).encode('UTF-8').zfill(3))
            ball_pos -= 1

    _thread.exit()

    pass

myhost = '192.168.15.6'
port = 5001

objsock = socket(AF_INET, SOCK_STREAM)

objsock.bind((myhost, port))
objsock.listen(2)

print('Aguardando conexão...')

while True:

    con, addr = objsock.accept()

    if con != 0:
        _thread.start_new_thread(send_data, tuple([con, addr]))
        print('Conectado por: ', addr)

    


