### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

include(../shared.pri)
DOXYGEN_BIN=$$findFile(doxygen)

QMAKE_EXTRA_TARGETS += doc
doc.target = doc
isEmpty(DOXYGEN_BIN) {
    doc.commands = @echo "Unable to detect doxygen in PATH"
} else {
    system( mkdir -p $${OUT_PWD}/doc/html )

    doc.commands = ( sed -e \"s:@MEEGOFEEDBACK_SRC_DIR@:$${IN_PWD}:g\" \
                         $${IN_PWD}/mdoxy.cfg.in > doc/mdoxy.cfg );

    doc.commands+= ( $${DOXYGEN_BIN} doc/mdoxy.cfg );
    doc.commands+= ( cd doc ; $${IN_PWD}/xmlize.pl );

    # Install rules
    htmldocs.files = $${OUT_PWD}/doc/html/

    htmldocs.path = /usr/share/doc/meegofeedbackd-doc
    htmldocs.CONFIG += no_check_exist
    INSTALLS += htmldocs
}

doc.depends = FORCE

