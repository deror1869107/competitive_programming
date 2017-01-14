#!/usr/bin/env python3
import sys, os, time, signal
from subprocess import Popen, PIPE

bulb = None
holder = None
TIME_LIMIT = 6

def cmp(a, b):
    x = bulb[a - 1] - holder[b - 1]
    if x > 0:
        return 1
    elif x < 0:
        return -1
    return 0

# set the timeout handler
class TimeoutError(Exception):
    pass

def handler(signum, frame):
    raise TimeoutError()
signal.signal(signal.SIGALRM, handler)

try:
    testdata = open(sys.argv[1], 'rt')
    N = int(testdata.readline());
    bulb = [int(i) for i in testdata.readline().split(' ')]
    holder = [int(i) for i in testdata.readline().split(' ')]
    signal.alarm(TIME_LIMIT)
    start = time.time()
    with Popen([sys.argv[2]], stdin=PIPE, stdout=PIPE,
            universal_newlines=True, bufsize=0) as proc:
        proc.stdin.write("{}\n".format(N))
        output = proc.stdout.readline().strip().split(' ')
        query = 0
        while output[0] == 'C':
            query += 1
            input = cmp(int(output[1]), int(output[2]))
            proc.stdin.write("{}\n".format(input))
            output = proc.stdout.readline().strip().split(' ')

        if output[0] == 'A':
            output = [int(i) for i in proc.stdout.read().strip().split("\n")]

        end = time.time()
        signal.alarm(0)

    if bulb == output:
        print("AC 1.0")
        print("Query Times: {}".format(query))
        print("Total Time: {:.3f}s".format(end - start))
    else:
        print("WA 0.0")

except TimeoutError:
    print("TLE")

except:
    print("RE")
