G 		= g++
flags 	= -std=c++14 -o
dll 	= -lzmq

main 	: Src/main.cpp Src/Worker.hpp Src/Package.hpp node 	; $(G) $(flags) main Src/main.cpp $(dll)
node 	: Src/work.cpp Src/Worker.hpp Src/Package.hpp 		; $(G) $(flags) node Src/work.cpp $(dll)
clean 	: ; rm main node
log		: ; rm Logs/*.txt
