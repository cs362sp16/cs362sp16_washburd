# Script
echo "--- Executing Tests ---"
echo "randomtestcard1"
rm dominion.gcda
random1 42 > out.tmp
gcov dominion.c -f > gcov.tmp
cat out.tmp gcov.tmp dominion.c.gcov > randomtestcard1.out
rm *.tmp
echo "randomtestcard2"
rm dominion.gcda
random2 42 > out.tmp
gcov dominion.c -f > gcov.tmp
cat out.tmp gcov.tmp dominion.c.gcov > randomtestcard2.out
rm *.tmp
echo "randomtestadventurer"
rm dominion.gcda
adventurerrandom 42 > out.tmp
gcov dominion.c -f > gcov.tmp
cat out.tmp gcov.tmp dominion.c.gcov > randomtestadventurer.out
rm *.tmp
