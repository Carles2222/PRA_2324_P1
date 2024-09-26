bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	c++ -o bin/testListArray testListArray.cpp ListArray.h

clean:
	rm -r *.o *.gch bin

