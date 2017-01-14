#!/usr/bin/env python3
import sys, os, re, math

try:
    ans = [line.strip().strip(':') for line in open(sys.argv[1],'rt')]
    out = [line.strip().strip(':') for line in open(sys.argv[2],'rt')]
    if len(ans) != len(out):
        raise
    pairs = zip(ans,out)
    for _ in pairs:
        if _[0] != _[1]:
            raise
    print('AC 1.0')
except:
    print('WA 0.0')
