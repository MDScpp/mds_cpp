cd trash
@echo off
for %%x in (
        example_1
        example_2
       ) do (
            cd %%x
            clang++ -E -P -nostdinc main.cpp -o output.cpp
            cd ..
)


cd example_2
clang++ -E -P -nostdinc main.cpp -o output_d.cpp -DFOO_IFS_H
cd ..



cd example_3
clang++ -c main.cpp -o main.o 
clang++ -c my_math.cpp -o my_math.o 
clang++ main.cpp my_math.cpp -o program.exe 
cd ..

cd example_3
clang++ -c main.cpp -o main.o -DMY_MATH_H
clang++ main.cpp my_math.cpp -o program.exe 
cd ..

cd example_3
clang++ main.cpp my_math.cpp -o program.exe 
cd ..


cd internal_linkage
clang++ main.cpp internal.cpp -o program.exe 

clang++ -S main.cpp -o main.ll -emit-llvm 
clang++ -S internal.cpp -o internal.ll -emit-llvm 

clang++ -S main.cpp -o main.s -masm=intel
clang++ -S internal.cpp -o internal.s -masm=intel
cd ..

cd conflict_linkage
clang++ main.cpp external.cpp -o program.exe 

cd ..


cd ..