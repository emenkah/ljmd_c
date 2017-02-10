#! /bin/bash

rm -f examples/ljmd-serial.x 
rm -f examples/gmon.out

cp bin/ljmd-serial.x examples

echo "                             "
echo "                             "
echo "----testing executable-------"
echo "                             "
echo "                             "

cd examples && ./ljmd-serial.x < argon_108.inp && gprof ljmd-serial.x gmon.out > analysis2_opt.txt && head analysis2_opt.txt

