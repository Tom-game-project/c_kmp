CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRC     = kmp_strstr.c
TESTSRC = kmp_strstrtest.c
PROGRAM = test.out
LIBPROGRAM = kmp_strstr.so

all: $(PROGRAM)

$(PROGRAM): src/$(SRC) src/$(TESTSRC)
	$(CC) $(CFLAGS) src/$(SRC) src/$(TESTSRC) -o pkg/$(PROGRAM)

lib: src/$(SRC)
	$(CC) $(CFLAGS) -shared -o pkg/$(LIBPROGRAM) -fPIC src/$(SRC)

clean:
	rm -f pkg/*.o *~ pkg/$(PROGRAM) pkg/$(LIBPROGRAM)

