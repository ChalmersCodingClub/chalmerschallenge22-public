#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution gustav.cpp

compile gen_random.py
compile gen_bigsum.py
compile gen_bigans.py

samplegroup
limits nMax=10 aMax=10
sample 1
sample 2
sample 3

group group1 25
limits nMax=20 aMax=20
tc 1
tc 2
tc 3
tc g1_1 gen_random n=1 aMax=1
tc g1_2 gen_random n=5 aMax=1
tc g1_3 gen_random n=5 aMax=5
tc g1_4 gen_random n=10 aMax=10
tc g1_5 gen_random n=10 aMax=10
tc g1_6 gen_random n=10 aMax=10
tc g1_7 gen_random n=20 aMax=10
tc g1_8 gen_random n=10 aMax=20
tc g1_9 gen_random n=20 aMax=20
tc g1_10 gen_random n=20 aMax=20 sortType=sort
tc g1_11 gen_random n=20 aMax=20 sortType=almostrev
tc g1_12 gen_bigsum n=20 aMax=20
tc g1_13 gen_bigans n=20 aMax=20

group group2 20
limits nMax=75 aMax=75
include_group group1
tc g2_1 gen_random n=20 aMax=75
tc g2_2 gen_random n=30 aMax=75
tc g2_3 gen_random n=31 aMax=75
tc g2_4 gen_random n=50 aMax=75
tc g2_5 gen_random n=75 aMax=20
tc g2_6 gen_random n=75 aMax=75
tc g2_7 gen_random n=75 aMax=75 sortType=almostsort
tc g2_8 gen_random n=75 aMax=75 sortType=rev
tc g2_9 gen_random n=75 aMax=1
tc g2_10 gen_bigsum n=75 aMax=75
tc g2_11 gen_bigans n=75 aMax=75

group group3 15
limits nMax=250 aMax=1000000000
include_group group2
tc g3_1 gen_random n=250 aMax=5
tc g3_2 gen_random n=5 aMax=250
tc g3_3 gen_random n=250 aMax=75
tc g3_4 gen_random n=75 aMax=250
tc g3_5 gen_random n=250 aMax=1000000000
tc g3_6 gen_random n=250 aMax=1000000000 sortType=sort
tc g3_7 gen_random n=250 aMax=1000000000 sortType=rev
tc g3_8 gen_random n=250 aMax=1000000000 sortType=almostsort
tc g3_9 gen_random n=250 aMax=1000000000 sortType=almostrev
tc g3_10 gen_bigsum n=250 aMax=1000000000
tc g3_11 gen_bigans n=250 aMax=1000000000

group group4 40
limits nMax=5000 aMax=1000000000
include_group group3
tc g4_1 gen_random n=5000 aMax=5
tc g4_2 gen_random n=5000 aMax=5 sortType=sort
tc g4_3 gen_random n=5 aMax=1500
tc g4_4 gen_random n=5000 aMax=75
tc g4_5 gen_random n=75 aMax=1500
tc g4_6 gen_random n=5000 aMax=250
tc g4_7 gen_random n=1500 aMax=250
tc g4_8 gen_random n=250 aMax=1500
tc g4_9 gen_random n=5000 aMax=1000000000
tc g4_10 gen_random n=5000 aMax=1000000000
tc g4_11 gen_random n=5000 aMax=1000000000 sortType=sort
tc g4_12 gen_random n=5000 aMax=1000000000 sortType=rev
tc g4_13 gen_random n=5000 aMax=1000000000 sortType=almostsort
tc g4_14 gen_random n=5000 aMax=1000000000 sortType=almostrev
tc g4_15 gen_random n=5000 aMax=1
tc g4_16 gen_bigsum n=5000 aMax=1000000000
tc g4_17 gen_bigans n=5000 aMax=1000000000
