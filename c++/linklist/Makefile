CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_link: build/test_link.o build/linklist.o 
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test all clean

test_link: build/test_link
	./build/test_link

test: test_link

clean:
	rm -rf build
