HEADERS = tree/Bud.h tree/Node.h tree/Internode.h tree/Tree.h tree/ITreePart.h TreeGenerator.h TreeViewer.h
SOURCE = main.cpp tree/Bud.cpp tree/Node.cpp tree/Internode.cpp tree/Tree.cpp

FLAGS = -std=c++11 -g
LIBS = -L /usr/lib -lGLEW -lGL -lGLU -lglfw -lboost_system -lboost_thread -lfreeimage
INCLUDES = -I /usr/include

all: ../build/test
	#rm ../build/*.o

../build/:
	mkdir ../build/

../build/test: ../build/ $(HEADERS) $(SOURCE)
	g++ $(FLAGS) $(LIBS) $(INCLUDES) -o ../build/test $(SOURCE)

clean:
	rm -rf ../build/
