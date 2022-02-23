#!/bin/sh
set -e
if [[ $(id -u) -ne 0 ]] ; then printf 'Please create ~/.local/bin if not exist, and add it to $PATH\n' ; exit 1 ; fi

cd ~/.local/bin/
curl -o ppfetch https://raw.githubusercontent.com/pedroportales/ppfetch/main/ppfetch
printf "\nppfetch has a successful installation, please consider run it now. :D\n"
