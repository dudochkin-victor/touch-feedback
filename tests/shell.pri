### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

shell_scripts.commands += $$system(touch tests.xml)
shell_scripts.files += runtests.sh tests.xml

# fixed path required by TATAM
shell_scripts.path += /usr/share/libmeegofeedback-tests
shell_scripts.depends = FORCE

INSTALLS    += \
              shell_scripts
