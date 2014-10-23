



# Compilation Settings
CINC = -I ./include
CFLAGS = -Wall
COPT = ${CFLAGS} ${CINC}
CC = g++ ${COPT}



# Targets
DIR = ./build
HDR = ./include/c3d.h
OBJ = ${DIR}/Vector.o ${DIR}/Ray.o
TST = ${DIR}/VectorTest.exe ${DIR}/RayTest.exe



############### BUILD RULES ###############

all: ${DIR} ${OBJ}



${DIR}:
	mkdir -p ${DIR}



${DIR}/Vector.o: source/Vector.cpp ${HDR}
	${CC} -c -o $@ $<

${DIR}/Ray.o: source/Ray.cpp ${HDR}
	${CC} -c -o $@ $<

clean:
	@echo
	@echo "cleaning build directory"
	rm -rvf ./build/*.o ./build/*.exe
	@echo



############### TEST SUITE ###############

test: ${DIR} ${TST}
	${DIR}/VectorTest.exe
	${DIR}/RayTest.exe

${DIR}/VectorTest.o: ./tests/VectorTest.cpp ./source/Vector.cpp ${HDR}
	${CC} -c -o $@ $<

${DIR}/VectorTest.exe: ${DIR}/VectorTest.o ${DIR}/Vector.o
	${CC} -o $@ $^

${DIR}/RayTest.o: ./tests/RayTest.cpp ./source/Ray.cpp ${HDR}
	${CC} -c -o $@ $<

${DIR}/RayTest.exe: ${DIR}/RayTest.o ${DIR}/Ray.o ${DIR}/Vector.o
	${CC} -o $@ $^




	
