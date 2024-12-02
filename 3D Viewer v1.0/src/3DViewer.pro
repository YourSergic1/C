QT       += core gui widgets opengl openglwidgets
LIBS += -lcheck -lm

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    simple.c \
    parser.c \
    affine_transform.c \
    myopenglwidget.cpp \
    opengl_data_calc.cpp \
    opengl_settings.cpp

HEADERS += \
    mainwindow.h \
    parser.h \
    gif.h \
    myopenglwidget.h

FORMS += \
    mainwindow.ui

    DEFINES += _GNU_SOURCE

CLEAN_FILES += 3DViewer *.o

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix {
    # Добавьте здесь флаги для Unix-подобных систем
    FLAGSCH += -lm -pthread 
    !macx {
        # Добавьте здесь флаги для Linux, если это не macOS
        FLAGSCH += -lcheck_pic -lrt -lsubunit
        # какая ОС (для отключения изменения точек )
        DEFINES += OS_LINUX
    }
    macx {
        DEFINES += OS_MAC
    }
}

tests.target = tests
tests.commands = gcc -Wall -Werror -Wextra -std=c11 -lcheck --coverage affine_transform.c parser.c tests.c -o tests $${FLAGSCH} && \
rm -rf *.o *.gcda *.gcno  && \
./tests
CLEAN_FILES += tests

gcov_report.target = gcov_report
gcov_report.commands = gcc -Wall -Werror -Wextra -std=c11 -lcheck --coverage affine_transform.c parser.c tests.c -o tests $${FLAGSCH} && \
./tests && \
lcov -t "s21_BrickGame" -o game.info -c -d . && \
genhtml -o report game.info && \
rm -rf *.o *.gcda *.gcno
CLEAN_FILES += game.info *.gcda *.gcno

style.target = style
style.commands = clang-format -n *.c *.h *.cpp

clang.target = clang
clang.commands = clang-format -i *.c *.h *.cpp


QMAKE_CLEAN += rm -rf report

QMAKE_EXTRA_TARGETS += gcov_report tests style clang