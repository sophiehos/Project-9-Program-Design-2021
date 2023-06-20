summer_camp:summer_camp.o read_line.o request.o
	gcc -o summer_camp summer_camp.o read_line.o request.o
summer_camp.o:summer_camp.c read_line.h request.h
	gcc -c summer_camp.c
read_line.o:read_line.c read_line.h
	gcc -c read_line.c
request.o: request.c request.h
	gcc -c request.c
