# All variables and this file are optional, if they are not present the PG and the
# makefiles will try to parse the correct values from the file system.
#
# Variables that specify exclusions can use % as a wildcard to specify that anything in
# that position will match. A partial path can also be specified to, for example, exclude
# a whole folder from the parsed paths from the file system
#
# Variables can be specified using = or +=
# = will clear the contents of that variable both specified from the file or the ones parsed
# from the file system
# += will add the values to the previous ones in the file or the ones parsed from the file
# system
#
# The PG can be used to detect errors in this file, just create a new project with this addon
# and the PG will write to the console the kind of error and in which line it is

meta:
	ADDON_NAME = ofxMongo
	ADDON_DESCRIPTION =
	ADDON_AUTHOR =
	ADDON_TAGS = 
	ADDON_URL = 

common:

	ADDON_INCLUDES = src 

linux64:
    ADDON_PKG_CONFIG_LIBRARIES = libbson-1.0 libbsoncxx libbsoncxx-static libbson-static-1.0 libmongoc-1.0 libmongoc-ssl-1.0 libmongoc-static-1.0 libmongocxx libmongocxx-static

osx:
	ADDON_INCLUDES += include
	ADDON_LIBS = lib/osx/libbson-static-1.0.a
	ADDON_LIBS += lib/osx/libbsoncxx-static.a
	ADDON_LIBS += lib/osx/libmongoc-static-1.0.a
	ADDON_LIBS += lib/osx/libmongocxx-static.a
	ADDON_LIBS += lib/osx/libmongocxx-static.a
	ADDON_LIBS += lib/osx/libcrypto.a
	ADDON_LIBS += lib/osx/libssl.a
	