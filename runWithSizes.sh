cd cmake-build-debug
g++ -o piRandom ../main.cpp ../Ran2.cpp -pthread -std=c++17 -fopenmp
cd ..
{
    read
    while IFS=" " read -r ITERATIONS THREADS
    do
        echo "numero iteraciones: $ITERATIONS, Threads: $THREADS"
        cd cmake-build-debug
        export OMP_NUM_THREADS=$THREADS
        ./piRandom $ITERATIONS >> test.out
        cd ..
    done
} < sizes.txt