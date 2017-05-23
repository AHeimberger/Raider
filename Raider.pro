TEMPLATE = subdirs

SUBDIRS = \
    core \
    tests \
    app

OTHER_FILES += \
    LICENSE.md \
    README.md \
    scripts/entrypoint.sh \
    scripts/build.sh \
    scripts/cppcheck.sh

core.subdir = core

tests.subdir = tests
tests.depends = core

app.subdir = app
app.depends = core
