#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution loke.cpp

compile gen.py

samplegroup
sample 1
sample 2

group full 100
tc 1
tc 2
tc t01 gen MaxD=1
tc t02 gen MaxD=1
tc t03 gen MaxAB=10
tc t04 gen MaxAB=10
tc t05 gen MaxAB=1
tc t06 gen MaxD=1 MaxAB=1
tc t07 gen MaxD=1 MaxAB=1
tc t08 gen MaxAB=100000
tc t09 gen MaxAB=100000
tc t10 gen MaxAB=100000
tc t11 gen MaxAB=100000
tc t12 gen MaxAB=100000
tc t13 gen MaxAB=100000
tc t14 gen MaxAB=100000
tc t15 gen MaxAB=100000
tc t16 gen MaxAB=100000
tc t17 gen MaxAB=100000
tc t18 gen MaxAB=100000
tc t19 gen MaxAB=100000
tc t20 gen MaxAB=1000000
tc t21 gen MaxAB=10000000
tc t22 gen MaxAB=100000000
tc t23 gen MaxAB=1000000000
tc t24 gen MaxAB=10000000000
tc t25 gen MaxAB=1000000000000000
tc t26 gen MaxAB=1000000000000000
tc t27 gen MaxAB=1000000000000000
tc t28 gen MaxAB=1000000000000000
tc t29 gen
tc t30 gen
tc t31 gen
tc t32 gen
tc_manual ../manual_tests/a1.in
tc_manual ../manual_tests/a2.in
tc_manual ../manual_tests/a3.in
tc_manual ../manual_tests/a4.in
