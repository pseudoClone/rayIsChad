COMP= gcc

CFLAGS= -lraylib -lm

all:
	$(COMP) $(CFLAGS) rayDVD.c -o ray

clean:
	rm -rf ray
