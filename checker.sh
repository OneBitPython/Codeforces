set -e
g++ C_Count_Binary_Strings.cpp -o wrong
echo "Compiled WA"
g++ gen.cpp -o generator
echo "Compiled gen"
g++ ac.cpp -o ac
echo "Compiled AC"
for((i = 1; ; ++i)); do
    ./generator $i > input_file
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
