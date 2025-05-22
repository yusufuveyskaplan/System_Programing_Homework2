CC = gcc
CFLAGS = -I/usr/include/gtk-4.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include $(pkg-config --cflags gtk4 glib-2.0) -Wall
LDFLAGS = -L/usr/lib/x86_64-linux-gnu $(pkg-config --libs gtk4 glib-2.0)
SRC = main.c model.c view.c controller.c
OBJ = $(SRC:.c=.o)
TARGET = msweeper

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
