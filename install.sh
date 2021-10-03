#!/bin/sh
set -e
if [[ $(id -u) -ne 0 ]] ; then printf "Please run as root\n" ; exit 1 ; fi

cd /usr/bin
curl -o ppfetch https://raw.githubusercontent.com/pedroportales/ppfetch/main/ppfetch
printf "\nppfetch has a successful installation, please consider run it now. :D\n"
