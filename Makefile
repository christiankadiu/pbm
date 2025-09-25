# Nome del file eseguibile finale
TARGET = rubrica

# Nome del tuo file sorgente C
SRC = rubrica.c

# Compilatore da usare
CC = gcc

# Compila l'eseguibile a partire dal file sorgente
# La prima riga è il target, la seconda è il comando
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)
