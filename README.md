## Laboratory work III

Данная лабораторная работа посвещена изучению систем автоматизации сборки проекта на примере **CMake**

```ShellSession
$ open https://cmake.org/
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab03** на сервисе **GitHub**
- [x] 2. Ознакомиться со ссылками учебного материала
- [ ] 3. Выполнить инструкцию учебного материала
- [ ] 4. Составить отчет и отправить ссылку личным сообщением в **Slack**

## Tutorial

```ShellSession
$ export GITHUB_USERNAME=<имя_пользователя> #устанавливаем переменную окружения
```

```ShellSession
$ cd ${GITHUB_USERNAME}/workspace # переходим в рабочую директорию
$ pushd .                         # закидываем в стак
$ source scripts/activate         # активируем скрипт
```

```ShellSession
$ git clone https://github.com/${GITHUB_USERNAME}/lab02.git projects/lab03 # клоним репозиторий и создаем новый
$ cd projects/lab03                                                        # переходим в него
$ git remote remove origin                                                 # удаляем удаленный репо
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab03.git    # добавляем удаленный репо
```

```ShellSession
$ g++ -std=c++11 -I./include -c sources/print.cpp #запускаем компилятор в стандарте С++11 и
                                                  #подключаем директорию и выходной файл с расширением .o
$ ls print.o                                      #выводим "содержимое" созданного объекта
$ nm print.o | grep print                         #смотрим информацию бинарника, передаем в grep
                                                  #ищем выводы содержащие "print"
$ ar rvs print.a print.o                          #архивируем с замещением, подробностями, индексом
$ file print.a                                    #смотрим информацию о файле (ar архив)
$ g++ -std=c++11 -I./include -c examples/example1.cpp #по той же схеме компилируем example1.cpp
$ ls example1.o                                   #смотрим содержимое
$ g++ example1.o print.a -o example1              #компилим в файл example1
$ ./example1 && echo                              #выполняем скрипт и выводим результат
```

```ShellSession
$ g++ -std=c++11 -I./include -c examples/example2.cpp #компилируем example2.cpp
$ nm example2.o                      #смотрим информацию
$ g++ example2.o print.a -o example2 #компилируем example2.o и print.a в example2
$ ./example2                         #выполняем
$ cat log.txt && echo                #выводим лог и выводим результат
```

```ShellSession
$ rm -rf example1.o example2.o print.o #ТУТ
$ rm -rf print.a                       #УДАЛЯЕМ
$ rm -rf example1 example2             #ВСЕ
$ rm -rf log.txt                       #СОЗДАННОЕ
```

```ShellSession
$ cat > CMakeLists.txt <<EOF        #создаем файл cmake
cmake_minimum_required(VERSION 3.4) #минимальная требуемая версия
project(print)                      #название проекта
EOF                                 #
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF #пишем в тот же файл
set(CMAKE_CXX_STANDARD 11)    #устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD_REQUIRED ON) # в качестве обязательного
EOF                      
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF #добавляем статичную библиотеку с именем print, 
add_library(print STATIC \${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF #директории в которых компилятор будет искать файлы include
include_directories(\${CMAKE_CURRENT_SOURCE_DIR}/include)
EOF
```

```ShellSession
$ cmake -H. -B_build #собираем в директорию _build (-H. уточнить)
$ cmake --build _build #уточнить эти две команды
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF #добавляем исполняемые файлы

add_executable(example1 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 \${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)
EOF
```

```ShellSession
$ cat >> CMakeLists.txt <<EOF #связываем исполняемые файлы с библиотекой

target_link_libraries(example1 print)
target_link_libraries(example2 print)
EOF
```

```ShellSession
$ cmake --build _build #строим бинарное дерево проекта
$ cmake --build _build --target print    #добавляем туда "таргет"
$ cmake --build _build --target example1 #добавляем туда "таргет"
$ cmake --build _build --target example2 #добавляем туда "таргет"
```

```ShellSession
$ ls -la _build/libprint.a #смотрим содержимое
$ _build/example1 && echo  #исполняем пример1 и выводим
hello
$ _build/example2          #исполняем пример2
$ cat log.txt && echo      #выводим
hello
$ rm -rf log.txt      #удаляем лог
```

```ShellSession
$ git clone https://github.com/tp-labs/lab03 tmp #копируем репо в tmp
$ mv -f tmp/CMakeLists.txt . #перемещаем и выполняем?
$ rm -rf tmp      #удаляем
```

```ShellSession
$ cat CMakeLists.txt         #выводим содержимое
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install #указываем директорию установки
$ cmake --build _build --target install #создаем в таргет
$ tree _install #смотрим структуру
```

```ShellSession
$ git add CMakeLists.txt              #добавляем
$ git commit -m"added CMakeLists.txt" #коммитим
$ git push origin master              #пушим
```

## Report

```ShellSession
$ popd
$ export LAB_NUMBER=03
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER} tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gistup -m "lab${LAB_NUMBER}"
```

## Homework

Представьте, что вы стажер в компании "Formatter Inc.".
### Задание 1
1. Копируем директорию [formatter_lib](formatter_lib)
2. Пишем в CMakeList.txt:
   ```
   #достаточно
   ADD_LIBRARY(formatter STATIC formatter.cpp formatter.h)
   #хотя правильнее прописывать и другие параметры
   ```
В этой директории находятся файлы для статической библиотеки *formatter*.
Создайте `CMakeList.txt` в директории [formatter_lib](formatter_lib),
с помощью которого можно будет собирать статическую библиотеку *formatter*.

### Задание 2
    ```
    #аналогично
    ADD_LIBRARY(formatter STATIC libformatter.a formatter_ex.cpp formatter_ex.h)
    #но нужно чтобы все файлы были в одной директории, чтобы не линковать их
    ```
У компании "Formatter Inc." есть перспективная библиотека,
которая является расширением предыдущей библиотеки. Т.к. вы уже овладели
навыком созданием `CMakeList.txt` для статической библиотеки *formatter*, ваш 
руководитель поручает заняться созданием `CMakeList.txt` для библиотеки 
*formatter_ex*, которая в свою очередь использует библиотеку *formatter*.

### Задание 3
Конечно же ваша компания предоставляет примеры использования своих библиотек.
Чтобы продемонстрировать как работать с библиотекой *formatter_ex*,
вам необходимо создать два `CMakeList.txt` для двух простых приложений:
* *hello_world*, которое использует библиотеку *formatter_ex*;
* *solver*, приложение которое испольует статические библиотеки *formatter_ex* и *solver_lib*.

**Удачной стажировки!**

## Links
- [Основы сборки проектов на С/C++ при помощи CMake](https://eax.me/cmake/)
- [CMake Tutorial](http://neerc.ifmo.ru/wiki/index.php?title=CMake_Tutorial)
- [C++ Tutorial - make & CMake](https://www.bogotobogo.com/cplusplus/make.php)
- [Autotools](http://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html)
- [CMake](https://cgold.readthedocs.io/en/latest/index.html)

```
Copyright (c) 2015-2019 The ISC Authors
```
