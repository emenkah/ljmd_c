#! /bin/bash

rm -f examples/ljmd-serial.x 

cp bin/ljmd-serial.x examples

echo "                             "
echo "                             "
echo "----testing executable-------"
echo "                             "
echo "                             "

cd examples && ./ljmd-serial.x < argon_108.inp 

