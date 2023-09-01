# nombre del programa
TARGET = tarea2

#compilador y opciones de compilacion
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS = -lm

#archivos fuente
SOURCES = zero.c zero.h main.c

#regla por defecto
all: $(TARGET)

#para construir el programa
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $(TARGET) $(LDLIBS)
	
#regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

#regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)
