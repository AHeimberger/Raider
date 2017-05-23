LIB_NAME = core
LIB_PREFIX = lib
LIB_SUFFIX = .a

LIBS += -l$${LIB_NAME} \
        -L$${OUT_PWD}/../$${LIB_NAME}/$${DESTDIR}/

INCLUDEPATH += $${PWD}/includes
DEPENDPATH += $${PWD}/includes
PRE_TARGETDEPS += $${OUT_PWD}/../$${LIB_NAME}/$${DESTDIR}/$${LIB_PREFIX}$${LIB_NAME}$${LIB_SUFFIX}
