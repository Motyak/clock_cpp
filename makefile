CC=g++
CFLAGS=#-O3
LDFLAGS=-lpthread
OBJ=obj/Clock.o obj/main.o
EXEC=bin/clock
DIRS=bin obj

all: prep release

release: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

obj/Clock.o: src/Clock.cpp src/Clock.h
	$(CC) -c $< -o $@ $(CFLAGS)

obj/main.o: src/main.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

debug: CFLAGS += -g
debug: clean all

prep:
	@mkdir -p $(DIRS)

remake: clean all

clean:
	rm -f $(OBJ)

mrproper:
	rm -rf $(DIRS)
