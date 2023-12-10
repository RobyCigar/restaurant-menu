CC = clang++
CFLAGS = -Wall -std=c++11
SRC = main.cpp menu.cpp operation.cpp utils.cpp auth.cpp
OUTPUT = output

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^
	./output

.PHONY: clean

clean:
	rm -f $(OUTPUT)
