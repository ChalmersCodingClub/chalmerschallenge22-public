#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution julia.py

compile gen.py

samplegroup
sample 1
sample 2
sample 3
sample 4

group full 100
tc 1
tc 2
tc 3
tc 4
tc t01 gen A2Max=0 B2Max=0
tc t02 gen A2Max=0 B2Max=0
tc t03 gen A2Max=0 B2Max=0
tc t04 gen A2Max=0
tc t05 gen A2Max=0
tc t06 gen A2Max=0
tc t07 gen A1Max=10
tc t08 gen A1Max=10
tc t09 gen A1Max=10
tc t10 gen B1Max=10
tc t11 gen B1Max=10
tc t12 gen B1Max=10
tc t13 gen A1Max=10 B1Max=10
tc t14 gen
tc t15 gen
tc t16 gen
tc t17 gen
tc t18 gen A1Max=0 B1Max=0
tc t19 gen B2Max=0
tc t20 gen A1Max=0 B1Max=0 A2Max=0 B2Max=0
tc t21 gen A1Max=0 B1Max=0 A2Max=0
tc t22 gen A1Max=0 A2Max=0 B2Max=0
tc t23 gen B1Max=0 A2Max=0 B2Max=0
