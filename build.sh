#!/usr/bin/env bash

set -euo pipefail

cd "$(dirname "$0")"

umount build/https: || :
rm -rf build

mkdir build
c++ -std=c++17 -O3 httpsfs.cpp -lfuse3 -lcurlpp -lcurl -o build/httpsfs

mkdir build/cache
mkdir build/https:

build/httpsfs build/https:
