cc = gcc
flags = -Wall -pedantic -std=c99

res 	: server client ;
server 	: server.c 		; $(cc) $(flags) server.c -o server
client 	: client.c 		; $(cc) $(flags) client.c -o client
clean 	: 				; rm server client
ip 		: 				; ifconfig | grep "inet "
