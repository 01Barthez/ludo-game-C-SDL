compile: src/*.c include/*.h
	gcc -o ludo_game src/*.c ./main.c include/*.h -lSDL2 -lSDL2_image
run:
	./ludo_game
clean:
	rm -f ludo_game