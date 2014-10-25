
############### Notes ###############
# $@ - The rule target
# $< - The left-most dependency
# $^ - All the dependencies



# Compilation Settings
CINC = -I ./include # So we can use <> notation when including headers
CFLAGS = -Wall # Turn on all compiler warnings. Turn this off if too verbose
COPT = ${CFLAGS} ${CINC} # compiler options, flags and include directory
CC = g++ ${COPT} # the c compiler we'll be using



# Targets
HDR = ./include/c3d.h # headers go here
C3D = ./source/c3d
OBJ = ./build/Vector.o ./build/Ray.o ./build/Surface.o ./build/Plane.o
TST = ./build/VectorTest.exe ./build/RayTest.exe # test executables



############### BUILD RULES ###############

all: ${OBJ}

./build/Vector.o: ${C3D}/Vector.cpp ${HDR}
	${CC} -c -o $@ $<

./build/Ray.o: ${C3D}/Ray.cpp ${HDR}
	${CC} -c -o $@ $<

./build/Surface.o: ${C3D}/Surface.cpp ${HDR}
	${CC} -c -o $@ $<

./build/Plane.o: ${C3D}/Plane.cpp ${C3D}/Surface.cpp ${HDR}
	${CC} -c -o $@ $<

clean:
	@echo
	@echo "cleaning build directory"
	rm -rvf ./build/*.o ./build/*.exe
	@echo



############### TEST SUITE ###############

test: ${TST}
	./build/VectorTest.exe
	./build/RayTest.exe

./build/VectorTest.o: ./tests/VectorTest.cpp ${C3D}/Vector.cpp ${HDR}
	${CC} -c -o $@ $<

./build/VectorTest.exe: ./build/VectorTest.o ./build/Vector.o
	${CC} -o $@ $^

./build/RayTest.o: ./tests/RayTest.cpp ${C3D}/Ray.cpp ${HDR}
	${CC} -c -o $@ $<

./build/RayTest.exe: ./build/RayTest.o ./build/Ray.o ./build/Vector.o
	${CC} -o $@ $^




	
