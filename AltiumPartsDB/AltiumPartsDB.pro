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


SOURCES += main.cpp\
    manufacturer_dlg.cpp \
    mfg_list_dlg.cpp \
    library_part.cpp \
    database_connection_dlg.cpp \
    parts_browser_dlg.cpp \
    part_params_dlg.cpp \
    mfg_list_model.cpp

HEADERS  += \
    manufacturer_dlg.h \
    mfg_list_dlg.h \
    library_part.h \
    database_connection_dlg.h \
    parts_browser_dlg.h \
    part_params_dlg.h \
    mfg_list_model.h

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
