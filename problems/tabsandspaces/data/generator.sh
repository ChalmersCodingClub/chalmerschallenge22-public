#!/usr/bin/env bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

use_solution victor_py3.py

compile gen.py
compile asdf.py
compile gen_rand.py

sample 1
sample 2

tc t01 gen
tc t02 gen
tc t03 gen
tc t04 gen
tc t05 gen
tc t06 gen_rand
tc t07 gen_rand
tc t08 gen_rand
tc t09 gen_rand
tc t10 asdf
tc_manual ../manual_tests/a1.in
tc_manual ../manual_tests/a2.in
tc_manual ../manual_tests/a3.in

