#!/usr/bin/env bash

cp FairTech-AIO-Updater.elf release-FairTech-AIO-Updater.elf

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd $DIR
rm -r switch/FairTech-AIO-Updater/
mkdir -p switch/FairTech-AIO-Updater/
cp FairTech-AIO-Updater.nro switch/FairTech-AIO-Updater/
#VERSION=$(grep "APP_VERSION :=" Makefile | cut -d' ' -f4)
#cp aiosu-forwarder/aiosu-forwarder.nro switch/FairTech-AIO-Updater/FairTech-AIO-Updater-v$VERSION.nro
zip -FSr FairTech-AIO-Updater.zip switch/