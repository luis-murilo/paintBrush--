@echo off

cd biblioteca

gcc -c console_v1.5.3.c
gcc -c graphics.c
gcc -c conio_v3.2.3.c
gcc -c paint.c  -Wall -pedantic
gcc -c window.c -Wall -pedantic
gcc -c interface.c -Wall -pedantic
gcc -c info_lower_bar.c -Wall -pedantic
gcc -c pencil.c -Wall -pedantic
gcc -c draw.c -Wall -pedantic

ar rvs libpaint.a console_v1.5.3.o graphics.o conio_v3.2.3.o paint.o window.o interface.o info_lower_bar.o pencil.o draw.o

cd ..

gcc -o pbrush++ pbrush++.c -I.\biblioteca -L.\biblioteca -lpaint -lgdi32 -Wall -pedantic

@echo on