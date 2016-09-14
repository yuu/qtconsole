TEMPLATE = app
TARGET = qtconsole
INCLUDEPATH += include

# By default, QT contains core and gui (redefine)
QT = core gui

CONFIG += c++14

MOC_DIR = .moc
OBJECTS_DIR = .obj

target.path = /usr/local/bin
documentation.path = /usr/local/share/qtconsole
documentation.files = README.md
INSTALLS += target documentation

# Input
SOURCES += \
    src/main.cpp
