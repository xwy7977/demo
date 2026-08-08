CC = gcc
CFLAGS = -Wall -g
SRCDIR = src
OBJS = $(SRCDIR)/main.o $(SRCDIR)/var1.o $(SRCDIR)/var2.o $(SRCDIR)/var3.o

all: extern_demo

extern_demo: $(OBJS)
	$(CC) $(CFLAGS) -o extern_demo $(OBJS)

$(SRCDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/globals.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCDIR)/var1.o: $(SRCDIR)/var1.c $(SRCDIR)/globals.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCDIR)/var2.o: $(SRCDIR)/var2.c $(SRCDIR)/globals.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCDIR)/var3.o: $(SRCDIR)/var3.c $(SRCDIR)/globals.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o extern_demo