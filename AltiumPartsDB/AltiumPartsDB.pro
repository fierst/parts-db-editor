#-------------------------------------------------
#
# Project created by QtCreator 2017-03-24T08:58:45
#
#-------------------------------------------------

QT       += core gui\
            sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AltiumPartsDB
TEMPLATE = app

INCLUDEPATH += C:\Users\ewilson\Desktop\Code\lib\boost
LIBS += "-LC:\Users\ewilson\Desktop\Code\lib\boost\stage\lib" -llibboost_filesystem-mgw53-mt-d-1_64 -llibboost_system-mgw53-mt-d-1_64

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
    manufacturer_dlg.cpp \
    mfg_list_dlg.cpp \
    library_part.cpp \
    database_connection_dlg.cpp \
    parts_browser_dlg.cpp \
    part_params_dlg.cpp \
    mfg_list_model.cpp \
    altium_lib.cpp \
    cfb_types.cpp \
    capacitor_dlg.cpp \
    transistor_dlg.cpp \
    transformer_dlg.cpp \
    resistor_dlg.cpp \
    power_dlg.cpp \
    oscillator_dlg.cpp \
    optoelectronic_dlg.cpp \
    mechanical_dlg.cpp \
    inductor_dlg.cpp \
    ic_dlg.cpp \
    fuse_dlg.cpp \
    filter_dlg.cpp \
    electromechanical_dlg.cpp \
    diode_dlg.cpp \
    connector_dlg.cpp

HEADERS  += \
    manufacturer_dlg.h \
    mfg_list_dlg.h \
    library_part.h \
    database_connection_dlg.h \
    parts_browser_dlg.h \
    part_params_dlg.h \
    mfg_list_model.h \
    altium_lib.hpp \
    cfb_types.hpp \
    transistor_dlg.h \
    transformer_dlg.h \
    resistor_dlg.h \
    power_dlg.h \
    oscillator_dlg.h \
    optoelectronic_dlg.h \
    mechanical_dlg.h \
    inductor_dlg.h \
    ic_dlg.h \
    fuse_dlg.h \
    filter_dlg.h \
    electromechanical_dlg.h \
    diode_dlg.h \
    capacitor_dlg.h \
    connector_dlg.h

FORMS    += \
    manufacturer_dlg.ui \
    mfg_list_dlg.ui \
    database_connection_dlg.ui \
    part_params_dlg.ui \
    parts_browser_dlg.ui \
    capacitor_dlg.ui \
    connector_dlg.ui \
    diode_dlg.ui \
    filter_dlg.ui \
    fuse_dlg.ui \
    inductor_dlg.ui \
    mechanical_dlg.ui \
    ic_dlg.ui \
    optoelectronic_dlg.ui \
    oscillator_dlg.ui \
    power_dlg.ui \
    resistor_dlg.ui \
    transformer_dlg.ui \
    transistor_dlg.ui \
    electromechanical_dlg.ui
