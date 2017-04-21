TEMPLATE = subdirs

SUBDIRS += gsettings imports

imports.depends = gsettings
