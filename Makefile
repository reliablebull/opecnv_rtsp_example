CFLAGS = -Wall -std=c++11

ALL = Sender Receiver

all: $(ALL)

Sender: 
	g++ sender.cpp -o sender -pthread `pkg-config --libs --cflags opencv4` -lopencv_tracking

Sender.o: ./sender.cpp
	g++ $(CFLAGS) -c ./sender.cpp -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui

send: Sender
	./Sender

Receiver: Receiver.o
	g++ -o Receiver Receiver.o -L/usr/local/lib \
          -lopencv_core -lopencv_imgproc -lopencv_videoio -lopencv_highgui

Receiver.o: ../Source/Receiver.cpp
	g++ $(CFLAGS) -c ../Source/Receiver.cpp

receive:
	g++ reciever.cpp -o receiver -pthread `pkg-config --libs --cflags opencv4` -lopencv_tracking



clean:
	rm -rf $(ALL) *.o *~