IDIR = .
ODIR = .
LDIR = .

CC     = gcc
CFLAGS = -I$(IDIR)
LIBS   = -lncurses

_DEPS = io.h bsod.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o bsod.o io.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TARGET_NAME = fake-bsod

$(TARGET_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o

.PHONY: clean-all
clean-all:
	rm -f $(ODIR)/*.o $(TARGET_NAME)

