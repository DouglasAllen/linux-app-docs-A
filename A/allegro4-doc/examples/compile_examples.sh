#!/bin/sh
set -e
echo Creating $HOME/allegro4-examples
cd ~
mkdir -p allegro4-examples
cd allegro4-examples
#cp /usr/share/doc/allegro4-doc/examples/* .
echo "Uncompressing example source from " /usr/share/doc/allegro4-doc/examples/*.tar.gz
tar zxf /usr/share/doc/allegro4-doc/examples/*tar.gz
#gunzip -v *.gz
echo "Compiling examples..."
for src in *.c; do
  gcc -g -O2 -o ${src%.c} $src `allegro-config --libs`
#  strip ${src%.c}
done
echo "Compiled example programs are now in ~/allegro4-examples"
