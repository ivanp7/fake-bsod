TARGET_NAME = fake-bsod

IDIR = .
ODIR = .
LDIR = .

CC     = gcc
CFLAGS = -I$(IDIR) -Wall `pkg-config --cflags ncurses`
LIBS   = `pkg-config --libs ncurses`

_DEPS = io.h bsod.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o bsod.o io.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean clean-all
clean:
	rm -f $(ODIR)/*.o

clean-all: clean
	rm -f $(TARGET_NAME)

