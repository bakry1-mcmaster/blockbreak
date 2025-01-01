all:
	g++ -Isrc/include -Lsrc/lib -Lsrc/lib -o blockbreaker blockbreaker.cpp player.cpp ball.cpp brick.cpp -lSDL2_image -lmingw32 -lSDL2main -lSDL2


clean:
	rm -f blockbreaker.exe