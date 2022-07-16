#!/usr/bin/python3

import json

n, base = 64, '0'
for m in range(n, 10000):
  if len({ (2**i) % m for i in range(n) }) == n:
    M = { j: chr(ord(base) + i)
      for j in range(0, m)
        for i in range(0, n)
          if (2**i) % m == j }
    break

magic = json.dumps(''.join(
  [ M.get(j, '-') for j in range(0, m) ]
  )).strip('"')

print(f'#define LOG2(x) ("{magic}"[(x) % {m}] - \'{base}\')')

