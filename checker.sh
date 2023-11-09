set -e
g++ D_Sum_of_XOR_Functions.cpp -o wrong
echo "Compiled WA"
g++ gen.cpp -o gen
echo "Compiled gen"
g++ ac.cpp -o ac
echo "Compiled AC"
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./wrong < input_file > myAnswer
    ./ac < input_file > correctAnswer
    diff -Z myAnswer correctAnswer || break
    echo "Passed test: "  $i
done

echo "WA on test : "
cat input_file

echo "Your answer : "
cat myAnswer
echo "Correct Answer : "
cat correctAnswer
