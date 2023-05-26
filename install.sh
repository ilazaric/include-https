#!/usr/bin/env bash

cd "$(dirname "$0")"

sudo ln -s "$(realpath build/https:)" "/usr/include/https:"
