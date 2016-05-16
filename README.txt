HOW TO COMPILE:
$ g++ -c HugeInt.cpp
$ g++ -c main.cpp
$ g++ -o hugeint main.o HugeInt.o
$ ./hugeint


THE RUNNING SCRIPT:
Administrator@H64B /cygdrive/d/Jessie/程設/lab5
$ cat lab5.script
命令稿啟動於 2016年05月17日 上午 02:39:04

Administrator@H64B /cygdrive/d/Jessie/程設/lab5
$ make
g++ -c HugeInt.cpp
g++ -c main.cpp
g++ -o hugeint main.o HugeInt.o

Administrator@H64B /cygdrive/d/Jessie/程設/lab5
$ ./hugeint
1
1+28825252=28825253
314159265358979323845

Administrator@H64B /cygdrive/d/Jessie/程設/lab5
$ ./hugeint
314159265358979323846
314159265358979323846+28825252=314159265359008149098
0

Administrator@H64B /cygdrive/d/Jessie/程設/lab5
$ ./hugeint
201605170239
201605170239+28825252=201633995491
314159265157374153607

Administrator@H64B /cygdrive/d/Jessie/程設/lab5
$ exit

命令稿已於 2016年05月17日 上午 02:39:41
 完成