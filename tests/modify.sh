# BASH script to modify the formatting of .txt files from http://en.top-sudoku.com/hexadoku/choose-hexadoku-grid.php 

# Modifying the formatting will make it easier to parse the input files in C++
# usage: ./modify.sh file_to_modify.txt
head -n 19 $1 > tmp.txt
mv tmp.txt $1
sed -i 's/ //g' $1
sed -i '/^$/d' $1
sed -i 's/\.//g' $1