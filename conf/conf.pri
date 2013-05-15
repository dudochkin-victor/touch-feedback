### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

daemonconf.path = /etc/meegofeedbackd
daemonconf.files = ./conf/daemon.conf

INSTALLS += daemonconf
