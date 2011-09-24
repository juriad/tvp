#!/bin/sh

#[ -e X2C ] && rm -Rf X2C
git clone git://github.com/juriad/X2C.git X2C
cd X2C/src
qmake
make
cd ../..
[ -e model ] && rm -Rf model
mkdir model
X2C/src/X2C "xmltv/xmltv.xsd" "tns" "" "model"
rm -Rf X2C
