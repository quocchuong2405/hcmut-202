# Lab 7

## Problem 1

<details><summary>Output</summary>

```text
Page table
00001 --> 52354
00002 --> afb29
00003 --> 4b0dc
00004 --> 52ca0
00005 --> a7cbd
17d42 --> 338a3
1238f --> 28471
da234 --> 2341b
f1234 --> 1bca2
129af --> 23133
Access pages
00003123 --> 4b0dc123
00001524 --> 52354524
00002534 --> afb29534
17d42e52 --> 338a3e52
121aabdd --> Illegal address
000012ac --> 523542ac
00004a71 --> 52ca0a71
TLB
0: 00001 --> 52354 :  2
1: 00004 --> 52ca0 :  1
2: 00003 --> 4b0dc :  1
3: 17d42 --> 338a3 :  1
```

</details>

## Problem 2

A system defines a page table with 12-bit virtual and physical address with 256-byte pages, i.e. 12-bit memory length including 4-bit index and 8-bit offset.

The page frame is as follows

| Page  | Data Frame | After Conversion |
| :---: | :--------: | :--------------: |
|   0   |     -      |        E         |
|   1   |     2      |        2         |
|   2   |     C      |        C         |
|   3   |     A      |        A         |
|   4   |     -      |        -         |
|   5   |     4      |        4         |
|   6   |     3      |        3         |
|   7   |     -      |        D         |
|   8   |     B      |        B         |
|   9   |     0      |        0         |

with frames D, E, F initially unassigned.

The following virtual addresses are in hexadecimal and are to be converted to their equivalent physical addresses.

- 9EF => 0EF
- 111 => 211
- 700 => D00
- 0FF => EFF

## Problem 3

Given a page reference string

```text
1, 2, 3, 2, 4, 5, 1, 6, 2, 1, 3, 2, 7, 6, 3, 2, 2, 1, 3, 2, 6
```

Calculate the number of page faults the the following replacement algorithms assuming using 1 ~ 7 frames.

- LRU replacement
- FIFO replacement
- Optimal replacement
- Clock replacement

|         |   1   |   2   |   3   |   4   |   5   |   6   |   7   |
| :-----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|   LRU   |  20   |  19   |  15   |  12   |   8   |   7   |   7   |
|  FIFO   |  20   |  19   |  15   |  12   |  10   |   9   |   7   |
| Optimal |  20   |  15   |  11   |   8   |   7   |   7   |   7   |
|  Clock  |  20   |  18   |  15   |  13   |   8   |   7   |   7   |

<img src="https://raw.githubusercontent.com/Smithienious/hcmut-202/master/CO2018/Lab7/1952255/graph.png">
