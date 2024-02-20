CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRC     = ft_kmp_strstr.c
TESTSRC = ft_kmp_strstrtest.c
PROGRAM = test.out
LIBPROGRAM = ft_kmp_strstr.so

all: $(PROGRAM)

$(PROGRAM): src/$(SRC) src/$(TESTSRC)
	$(CC) $(CFLAGS) src/$(SRC) src/$(TESTSRC) -o pkg/$(PROGRAM)

lib: src/$(SRC)
	$(CC) $(CFLAGS) -shared -o pkg/$(LIBPROGRAM) -fPIC src/$(SRC)

clean:
	rm -f pkg/*.o *~ pkg/$(PROGRAM) pkg/$(LIBPROGRAM)
