#!/usr/bin/env python3
import sys
import re

integer = "(0|-?[1-9]\d*)"

files = sys.stdin.readline()
assert re.match(integer + "\n", files), "file count not an integer!!"
files = int(files)
assert 1 <= files <= 10, "file count not between 1 and 10!!"

for f in range(files):
    lines = sys.stdin.readline()
    assert re.match(integer + "\n", lines), "line count not an integer!!"
    lines = int(lines)
    assert 1 <= lines <= 20, "line count not between 1 and 20!!"
    for l in range(lines):
        a = sys.stdin.readline()
        assert re.match(integer + "\n", a), "line length not an integer!!"
        a = int(a)
        assert 0 <= a <= 79, "line length not between 0 and 79!!"

assert sys.stdin.readline() == "", "junk at end of file!!"

# Nothing to report
sys.exit(42)
