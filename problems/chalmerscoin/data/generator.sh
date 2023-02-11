#!/usr/bin/env bash

PPATH=$(realpath ..)
REQUIRE_SAMPLE_REUSE=0
. ../../../testdata_tools/gen.sh

use_solution cheater.cpp

compile gen.py

samplegroup
sample_manual 1

group g1 100
tc t01 gen
