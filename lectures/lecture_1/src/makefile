
CC=clang++
EXE_S=.exe

dir=example_1
${dir}/output.cpp:  ${dir}/main.cpp
	${CC} -E -P -nostdinc ${dir}/main.cpp -o ${dir}/output.cpp


dir=example_2
${dir}/output.cpp ${dir}/output_d.cpp:  ${dir}/main.cpp
	${CC} -E -P -nostdinc ${dir}/main.cpp -o ${dir}/output.cpp
	${CC} -E -P -nostdinc ${dir}/main.cpp -o ${dir}/output_d.cpp -DFOO_IFS_H



######################################################################

dir=example_3
${dir}/my_math.o : ${dir}/my_math.cpp
	clang++ -c ${dir}/main.cpp -o ${dir}/main.o 

${dir}/main.o :  ${dir}/main.cpp
	clang++ -c ${dir}/my_math.cpp -o ${dir}/my_math.o 


${dir}/main.o :  ${dir}/main.cpp
	clang++ ${dir}/main.o ${dir}/my_math.o -o ${dir}/program${EXE_S} 


######################################################################

dir=internal_linkage


${dir}/program.exe ${dir}/main.ll ${dir}/internal.ll: ${dir}/main.cpp ${dir}/internal.cpp
	clang++ ${dir}/main.cpp ${dir}/internal.cpp -o ${dir}/program.exe 

	clang++ -S ${dir}/main.cpp -o ${dir}/main.ll -emit-llvm 
	clang++ -S ${dir}/internal.cpp -o ${dir}/internal.ll -emit-llvm 

	clang++ -S ${dir}/main.cpp -o ${dir}/main.s -masm=intel
	clang++ -S ${dir}/internal.cpp -o ${dir}/internal.s -masm=intel

######################################################################

#clang++ main.cpp external.cpp -o program.exe 