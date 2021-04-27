# Lab 5

## Problem 1

`deposit()` could be implemented as

```c
register0 = balance;
register0 = register0 + value;
balance = register0;
```

`withdraw()` could be implemented as

```c
register1 = balance;
register1 = register1 - value;
balance = register1;
```

Each function has its write back section, where `balance` is written. Thus the latter to write will hold the value.

With an initial value `balance = 5` and `value = 1`, we can see that `register0 = 6` and `register1 = 4`. If the program runs correctly, the final result should be 5. If for some reason `balance = register0` is executed later, `balance = 6`. And `balance = 4` vice versa.

### Workaround

We implement a queue with control initialized to 1. For any process that leaves the queue, control will be decreased, then increased when the process finishes. No process can leave the queue if control is non positive.

## Problem 2

<details><summary> cond_usg </summary>

```bash
main: begin
Starting watch_count(): thread 1
watch_count(): thread 1, count = 10, waiting...
inc_count(): thread 2, count = 11, unlocking mutex
inc_count(): thread 3, count = 12, unlocking mutex
inc_count(): thread 2, count = 13, unlocking mutex
inc_count(): thread 3, count = 14, unlocking mutex
inc_count(): thread 2, count = 15, unlocking mutex
inc_count(): thread 3, count = 16, unlocking mutex
inc_count(): thread 3, count = 17, unlocking mutex
inc_count(): thread 2, count = 18, unlocking mutex
inc_count(): thread 3, count = 19, unlocking mutex
inc_count(): thread 2, count = 20, threshold reached.
Just sent signal
inc_count(): thread 2, count = 20, unlocking mutex
watch_count(): thread 1. Condition sinal received. Count = 20
watch_count(): thread 1. Updating the count value...
watch_count(): thread 1 count now = 100
watch_count(): thread 1. Unlocking mutex.
inc_count(): thread 3, count = 101, unlocking mutex
inc_count(): thread 2, count = 102, unlocking mutex
inc_count(): thread 3, count = 103, unlocking mutex
inc_count(): thread 2, count = 104, unlocking mutex
inc_count(): thread 3, count = 105, unlocking mutex
inc_count(): thread 2, count = 106, unlocking mutex
inc_count(): thread 3, count = 107, unlocking mutex
inc_count(): thread 2, count = 108, unlocking mutex
inc_count(): thread 3, count = 109, unlocking mutex
inc_count(): thread 2, count = 110, unlocking mutex
inc_count(): thread 3, count = 111, unlocking mutex
inc_count(): thread 2, count = 112, unlocking mutex
inc_count(): thread 3, count = 113, unlocking mutex
inc_count(): thread 2, count = 114, unlocking mutex
inc_count(): thread 3, count = 115, unlocking mutex
inc_count(): thread 2, count = 116, unlocking mutex
inc_count(): thread 3, count = 117, unlocking mutex
inc_count(): thread 2, count = 118, unlocking mutex
inc_count(): thread 3, count = 119, unlocking mutex
inc_count(): thread 2, count = 120, unlocking mutex
inc_count(): thread 3, count = 121, unlocking mutex
inc_count(): thread 2, count = 122, unlocking mutex
inc_count(): thread 3, count = 123, unlocking mutex
inc_count(): thread 2, count = 124, unlocking mutex
inc_count(): thread 3, count = 125, unlocking mutex
inc_count(): thread 2, count = 126, unlocking mutex
inc_count(): thread 3, count = 127, unlocking mutex
inc_count(): thread 2, count = 128, unlocking mutex
inc_count(): thread 3, count = 129, unlocking mutex
inc_count(): thread 2, count = 130, unlocking mutex
inc_count(): thread 3, count = 131, unlocking mutex
inc_count(): thread 2, count = 132, unlocking mutex
inc_count(): thread 3, count = 133, unlocking mutex
inc_count(): thread 2, count = 134, unlocking mutex
inc_count(): thread 3, count = 135, unlocking mutex
inc_count(): thread 2, count = 136, unlocking mutex
inc_count(): thread 3, count = 137, unlocking mutex
inc_count(): thread 2, count = 138, unlocking mutex
inc_count(): thread 3, count = 139, unlocking mutex
inc_count(): thread 2, count = 140, unlocking mutex
inc_count(): thread 3, count = 141, unlocking mutex
inc_count(): thread 2, count = 142, unlocking mutex
inc_count(): thread 3, count = 143, unlocking mutex
inc_count(): thread 2, count = 144, unlocking mutex
inc_count(): thread 3, count = 145, unlocking mutex
inc_count(): thread 2, count = 146, unlocking mutex
inc_count(): thread 3, count = 147, unlocking mutex
inc_count(): thread 2, count = 148, unlocking mutex
inc_count(): thread 3, count = 149, unlocking mutex
inc_count(): thread 2, count = 150, unlocking mutex
inc_count(): thread 3, count = 151, unlocking mutex
inc_count(): thread 2, count = 152, unlocking mutex
inc_count(): thread 3, count = 153, unlocking mutex
inc_count(): thread 2, count = 154, unlocking mutex
inc_count(): thread 3, count = 155, unlocking mutex
inc_count(): thread 2, count = 156, unlocking mutex
inc_count(): thread 3, count = 157, unlocking mutex
inc_count(): thread 2, count = 158, unlocking mutex
inc_count(): thread 3, count = 159, unlocking mutex
inc_count(): thread 2, count = 160, unlocking mutex
inc_count(): thread 3, count = 161, unlocking mutex
inc_count(): thread 2, count = 162, unlocking mutex
inc_count(): thread 3, count = 163, unlocking mutex
inc_count(): thread 2, count = 164, unlocking mutex
inc_count(): thread 3, count = 165, unlocking mutex
inc_count(): thread 2, count = 166, unlocking mutex
inc_count(): thread 3, count = 167, unlocking mutex
inc_count(): thread 2, count = 168, unlocking mutex
inc_count(): thread 3, count = 169, unlocking mutex
inc_count(): thread 2, count = 170, unlocking mutex
inc_count(): thread 2, count = 171, unlocking mutex
inc_count(): thread 3, count = 172, unlocking mutex
inc_count(): thread 2, count = 173, unlocking mutex
inc_count(): thread 3, count = 174, unlocking mutex
inc_count(): thread 2, count = 175, unlocking mutex
inc_count(): thread 3, count = 176, unlocking mutex
inc_count(): thread 2, count = 177, unlocking mutex
inc_count(): thread 3, count = 178, unlocking mutex
inc_count(): thread 3, count = 179, unlocking mutex
inc_count(): thread 2, count = 180, unlocking mutex
inc_count(): thread 2, count = 181, unlocking mutex
inc_count(): thread 3, count = 182, unlocking mutex
inc_count(): thread 3, count = 183, unlocking mutex
inc_count(): thread 2, count = 184, unlocking mutex
inc_count(): thread 3, count = 185, unlocking mutex
inc_count(): thread 2, count = 186, unlocking mutex
inc_count(): thread 3, count = 187, unlocking mutex
inc_count(): thread 2, count = 188, unlocking mutex
inc_count(): thread 3, count = 189, unlocking mutex
inc_count(): thread 2, count = 190, unlocking mutex
inc_count(): thread 3, count = 191, unlocking mutex
inc_count(): thread 2, count = 192, unlocking mutex
inc_count(): thread 2, count = 193, unlocking mutex
inc_count(): thread 3, count = 194, unlocking mutex
inc_count(): thread 2, count = 195, unlocking mutex
inc_count(): thread 3, count = 196, unlocking mutex
inc_count(): thread 2, count = 197, unlocking mutex
inc_count(): thread 3, count = 198, unlocking mutex
inc_count(): thread 3, count = 199, unlocking mutex
inc_count(): thread 2, count = 200, unlocking mutex
inc_count(): thread 2, count = 201, unlocking mutex
inc_count(): thread 3, count = 202, unlocking mutex
inc_count(): thread 2, count = 203, unlocking mutex
inc_count(): thread 3, count = 204, unlocking mutex
inc_count(): thread 2, count = 205, unlocking mutex
inc_count(): thread 3, count = 206, unlocking mutex
inc_count(): thread 3, count = 207, unlocking mutex
inc_count(): thread 2, count = 208, unlocking mutex
inc_count(): thread 3, count = 209, unlocking mutex
inc_count(): thread 2, count = 210, unlocking mutex
inc_count(): thread 2, count = 211, unlocking mutex
inc_count(): thread 3, count = 212, unlocking mutex
inc_count(): thread 2, count = 213, unlocking mutex
inc_count(): thread 3, count = 214, unlocking mutex
inc_count(): thread 3, count = 215, unlocking mutex
inc_count(): thread 2, count = 216, unlocking mutex
inc_count(): thread 3, count = 217, unlocking mutex
inc_count(): thread 2, count = 218, unlocking mutex
inc_count(): thread 2, count = 219, unlocking mutex
inc_count(): thread 3, count = 220, unlocking mutex
inc_count(): thread 2, count = 221, unlocking mutex
inc_count(): thread 3, count = 222, unlocking mutex
inc_count(): thread 3, count = 223, unlocking mutex
inc_count(): thread 2, count = 224, unlocking mutex
inc_count(): thread 3, count = 225, unlocking mutex
inc_count(): thread 2, count = 226, unlocking mutex
inc_count(): thread 3, count = 227, unlocking mutex
inc_count(): thread 2, count = 228, unlocking mutex
inc_count(): thread 2, count = 229, unlocking mutex
inc_count(): thread 3, count = 230, unlocking mutex
inc_count(): thread 2, count = 231, unlocking mutex
inc_count(): thread 3, count = 232, unlocking mutex
inc_count(): thread 2, count = 233, unlocking mutex
inc_count(): thread 3, count = 234, unlocking mutex
inc_count(): thread 2, count = 235, unlocking mutex
inc_count(): thread 3, count = 236, unlocking mutex
inc_count(): thread 3, count = 237, unlocking mutex
inc_count(): thread 2, count = 238, unlocking mutex
inc_count(): thread 2, count = 239, unlocking mutex
inc_count(): thread 3, count = 240, unlocking mutex
inc_count(): thread 3, count = 241, unlocking mutex
inc_count(): thread 2, count = 242, unlocking mutex
inc_count(): thread 3, count = 243, unlocking mutex
inc_count(): thread 2, count = 244, unlocking mutex
inc_count(): thread 3, count = 245, unlocking mutex
inc_count(): thread 2, count = 246, unlocking mutex
inc_count(): thread 2, count = 247, unlocking mutex
inc_count(): thread 3, count = 248, unlocking mutex
inc_count(): thread 3, count = 249, unlocking mutex
inc_count(): thread 2, count = 250, unlocking mutex
inc_count(): thread 2, count = 251, unlocking mutex
inc_count(): thread 3, count = 252, unlocking mutex
inc_count(): thread 2, count = 253, unlocking mutex
inc_count(): thread 3, count = 254, unlocking mutex
inc_count(): thread 2, count = 255, unlocking mutex
inc_count(): thread 3, count = 256, unlocking mutex
inc_count(): thread 3, count = 257, unlocking mutex
inc_count(): thread 2, count = 258, unlocking mutex
inc_count(): thread 3, count = 259, unlocking mutex
inc_count(): thread 2, count = 260, unlocking mutex
inc_count(): thread 3, count = 261, unlocking mutex
inc_count(): thread 2, count = 262, unlocking mutex
inc_count(): thread 3, count = 263, unlocking mutex
inc_count(): thread 2, count = 264, unlocking mutex
inc_count(): thread 2, count = 265, unlocking mutex
inc_count(): thread 3, count = 266, unlocking mutex
inc_count(): thread 2, count = 267, unlocking mutex
inc_count(): thread 3, count = 268, unlocking mutex
inc_count(): thread 2, count = 269, unlocking mutex
inc_count(): thread 3, count = 270, unlocking mutex
inc_count(): thread 3, count = 271, unlocking mutex
inc_count(): thread 2, count = 272, unlocking mutex
inc_count(): thread 2, count = 273, unlocking mutex
inc_count(): thread 3, count = 274, unlocking mutex
inc_count(): thread 3, count = 275, unlocking mutex
inc_count(): thread 2, count = 276, unlocking mutex
inc_count(): thread 2, count = 277, unlocking mutex
inc_count(): thread 3, count = 278, unlocking mutex
inc_count(): thread 2, count = 279, unlocking mutex
inc_count(): thread 3, count = 280, unlocking mutex
inc_count(): thread 3, count = 281, unlocking mutex
inc_count(): thread 2, count = 282, unlocking mutex
inc_count(): thread 3, count = 283, unlocking mutex
inc_count(): thread 2, count = 284, unlocking mutex
inc_count(): thread 3, count = 285, unlocking mutex
inc_count(): thread 2, count = 286, unlocking mutex
inc_count(): thread 3, count = 287, unlocking mutex
inc_count(): thread 2, count = 288, unlocking mutex
inc_count(): thread 2, count = 289, unlocking mutex
inc_count(): thread 3, count = 290, unlocking mutex
main: finish, final count = 290
```

</details>

<details><summary> nosynch </summary>

```bash
main: begin
inc_count(): thread 3, count = 11, unlocking mutex
Starting watch_count(): thread 1
watch_count(): thread 1, count = 12, waiting...
watch_count(): thread 1. Condition signal received. Count = 12
watch_count(): thread 1. Updating the count value...
watch_count(): thread 1 count now = 92
watch_count(): thread 1. Unlocking mutex.
inc_count(): thread 2, count = 12, unlocking mutex
inc_count(): thread 3, count = 93, unlocking mutex
inc_count(): thread 2, count = 94, unlocking mutex
inc_count(): thread 3, count = 95, unlocking mutex
inc_count(): thread 2, count = 96, unlocking mutex
inc_count(): thread 3, count = 97, unlocking mutex
inc_count(): thread 2, count = 98, unlocking mutex
inc_count(): thread 3, count = 99, unlocking mutex
inc_count(): thread 2, count = 100, unlocking mutex
inc_count(): thread 3, count = 101, unlocking mutex
inc_count(): thread 2, count = 102, unlocking mutex
inc_count(): thread 3, count = 103, unlocking mutex
inc_count(): thread 2, count = 104, unlocking mutex
inc_count(): thread 3, count = 105, unlocking mutex
inc_count(): thread 2, count = 106, unlocking mutex
inc_count(): thread 3, count = 107, unlocking mutex
inc_count(): thread 2, count = 108, unlocking mutex
inc_count(): thread 3, count = 109, unlocking mutex
inc_count(): thread 2, count = 109, unlocking mutex
inc_count(): thread 2, count = 110, unlocking mutex
inc_count(): thread 3, count = 111, unlocking mutex
inc_count(): thread 2, count = 112, unlocking mutex
inc_count(): thread 3, count = 112, unlocking mutex
inc_count(): thread 3, count = 113, unlocking mutex
inc_count(): thread 2, count = 114, unlocking mutex
inc_count(): thread 3, count = 115, unlocking mutex
inc_count(): thread 2, count = 115, unlocking mutex
inc_count(): thread 2, count = 116, unlocking mutex
inc_count(): thread 3, count = 116, unlocking mutex
inc_count(): thread 3, count = 117, unlocking mutex
inc_count(): thread 2, count = 117, unlocking mutex
inc_count(): thread 3, count = 118, unlocking mutex
inc_count(): thread 2, count = 119, unlocking mutex
inc_count(): thread 3, count = 120, unlocking mutex
inc_count(): thread 2, count = 121, unlocking mutex
inc_count(): thread 3, count = 122, unlocking mutex
inc_count(): thread 2, count = 123, unlocking mutex
inc_count(): thread 3, count = 124, unlocking mutex
inc_count(): thread 2, count = 125, unlocking mutex
inc_count(): thread 3, count = 126, unlocking mutex
inc_count(): thread 2, count = 127, unlocking mutex
inc_count(): thread 3, count = 128, unlocking mutex
inc_count(): thread 2, count = 129, unlocking mutex
inc_count(): thread 3, count = 130, unlocking mutex
inc_count(): thread 2, count = 131, unlocking mutex
inc_count(): thread 2, count = 133, unlocking mutex
inc_count(): thread 3, count = 132, unlocking mutex
inc_count(): thread 2, count = 134, unlocking mutex
inc_count(): thread 3, count = 134, unlocking mutex
inc_count(): thread 3, count = 135, unlocking mutex
inc_count(): thread 2, count = 135, unlocking mutex
inc_count(): thread 3, count = 136, unlocking mutex
inc_count(): thread 2, count = 137, unlocking mutex
inc_count(): thread 2, count = 138, unlocking mutex
inc_count(): thread 3, count = 138, unlocking mutex
inc_count(): thread 2, count = 139, unlocking mutex
inc_count(): thread 3, count = 139, unlocking mutex
inc_count(): thread 3, count = 140, unlocking mutex
inc_count(): thread 2, count = 141, unlocking mutex
inc_count(): thread 2, count = 142, unlocking mutex
inc_count(): thread 3, count = 143, unlocking mutex
inc_count(): thread 2, count = 144, unlocking mutex
inc_count(): thread 3, count = 145, unlocking mutex
inc_count(): thread 3, count = 146, unlocking mutex
inc_count(): thread 2, count = 146, unlocking mutex
inc_count(): thread 3, count = 147, unlocking mutex
inc_count(): thread 2, count = 147, unlocking mutex
inc_count(): thread 3, count = 148, unlocking mutex
inc_count(): thread 2, count = 149, unlocking mutex
inc_count(): thread 3, count = 150, unlocking mutex
inc_count(): thread 2, count = 151, unlocking mutex
inc_count(): thread 3, count = 152, unlocking mutex
inc_count(): thread 2, count = 153, unlocking mutex
inc_count(): thread 3, count = 154, unlocking mutex
inc_count(): thread 2, count = 155, unlocking mutex
inc_count(): thread 3, count = 156, unlocking mutex
inc_count(): thread 2, count = 157, unlocking mutex
inc_count(): thread 2, count = 158, unlocking mutex
inc_count(): thread 3, count = 158, unlocking mutex
inc_count(): thread 2, count = 159, unlocking mutex
inc_count(): thread 3, count = 159, unlocking mutex
inc_count(): thread 2, count = 160, unlocking mutex
inc_count(): thread 3, count = 161, unlocking mutex
inc_count(): thread 2, count = 162, unlocking mutex
inc_count(): thread 3, count = 163, unlocking mutex
inc_count(): thread 2, count = 164, unlocking mutex
inc_count(): thread 3, count = 165, unlocking mutex
inc_count(): thread 2, count = 166, unlocking mutex
inc_count(): thread 3, count = 166, unlocking mutex
inc_count(): thread 3, count = 167, unlocking mutex
inc_count(): thread 2, count = 167, unlocking mutex
inc_count(): thread 3, count = 168, unlocking mutex
inc_count(): thread 2, count = 169, unlocking mutex
inc_count(): thread 3, count = 170, unlocking mutex
inc_count(): thread 2, count = 171, unlocking mutex
inc_count(): thread 3, count = 172, unlocking mutex
inc_count(): thread 2, count = 173, unlocking mutex
inc_count(): thread 3, count = 174, unlocking mutex
inc_count(): thread 2, count = 175, unlocking mutex
inc_count(): thread 2, count = 176, unlocking mutex
inc_count(): thread 3, count = 176, unlocking mutex
inc_count(): thread 2, count = 177, unlocking mutex
inc_count(): thread 3, count = 178, unlocking mutex
inc_count(): thread 3, count = 179, unlocking mutex
inc_count(): thread 2, count = 180, unlocking mutex
inc_count(): thread 3, count = 181, unlocking mutex
inc_count(): thread 2, count = 182, unlocking mutex
inc_count(): thread 3, count = 183, unlocking mutex
inc_count(): thread 2, count = 184, unlocking mutex
inc_count(): thread 3, count = 185, unlocking mutex
inc_count(): thread 2, count = 186, unlocking mutex
inc_count(): thread 3, count = 187, unlocking mutex
inc_count(): thread 2, count = 188, unlocking mutex
inc_count(): thread 3, count = 189, unlocking mutex
inc_count(): thread 2, count = 190, unlocking mutex
inc_count(): thread 3, count = 191, unlocking mutex
inc_count(): thread 2, count = 192, unlocking mutex
inc_count(): thread 3, count = 193, unlocking mutex
inc_count(): thread 2, count = 194, unlocking mutex
inc_count(): thread 3, count = 195, unlocking mutex
inc_count(): thread 2, count = 196, unlocking mutex
inc_count(): thread 3, count = 197, unlocking mutex
inc_count(): thread 2, count = 198, unlocking mutex
inc_count(): thread 3, count = 199, unlocking mutex
inc_count(): thread 2, count = 200, unlocking mutex
inc_count(): thread 3, count = 201, unlocking mutex
inc_count(): thread 2, count = 202, unlocking mutex
inc_count(): thread 3, count = 203, unlocking mutex
inc_count(): thread 2, count = 204, unlocking mutex
inc_count(): thread 3, count = 205, unlocking mutex
inc_count(): thread 2, count = 206, unlocking mutex
inc_count(): thread 3, count = 207, unlocking mutex
inc_count(): thread 2, count = 208, unlocking mutex
inc_count(): thread 3, count = 209, unlocking mutex
inc_count(): thread 2, count = 210, unlocking mutex
inc_count(): thread 3, count = 211, unlocking mutex
inc_count(): thread 2, count = 212, unlocking mutex
inc_count(): thread 3, count = 213, unlocking mutex
inc_count(): thread 2, count = 214, unlocking mutex
inc_count(): thread 3, count = 215, unlocking mutex
inc_count(): thread 2, count = 216, unlocking mutex
inc_count(): thread 3, count = 217, unlocking mutex
inc_count(): thread 2, count = 218, unlocking mutex
inc_count(): thread 3, count = 219, unlocking mutex
inc_count(): thread 2, count = 220, unlocking mutex
inc_count(): thread 3, count = 221, unlocking mutex
inc_count(): thread 2, count = 222, unlocking mutex
inc_count(): thread 2, count = 223, unlocking mutex
inc_count(): thread 3, count = 223, unlocking mutex
inc_count(): thread 3, count = 224, unlocking mutex
inc_count(): thread 2, count = 225, unlocking mutex
inc_count(): thread 3, count = 226, unlocking mutex
inc_count(): thread 2, count = 227, unlocking mutex
inc_count(): thread 3, count = 228, unlocking mutex
inc_count(): thread 2, count = 229, unlocking mutex
inc_count(): thread 2, count = 230, unlocking mutex
inc_count(): thread 3, count = 230, unlocking mutex
inc_count(): thread 2, count = 231, unlocking mutex
inc_count(): thread 3, count = 231, unlocking mutex
inc_count(): thread 2, count = 232, unlocking mutex
inc_count(): thread 3, count = 233, unlocking mutex
inc_count(): thread 3, count = 234, unlocking mutex
inc_count(): thread 2, count = 234, unlocking mutex
inc_count(): thread 3, count = 235, unlocking mutex
inc_count(): thread 2, count = 236, unlocking mutex
inc_count(): thread 2, count = 237, unlocking mutex
inc_count(): thread 3, count = 237, unlocking mutex
inc_count(): thread 2, count = 238, unlocking mutex
inc_count(): thread 3, count = 238, unlocking mutex
inc_count(): thread 2, count = 239, unlocking mutex
inc_count(): thread 3, count = 239, unlocking mutex
inc_count(): thread 2, count = 240, unlocking mutex
inc_count(): thread 3, count = 241, unlocking mutex
inc_count(): thread 3, count = 242, unlocking mutex
inc_count(): thread 2, count = 243, unlocking mutex
inc_count(): thread 2, count = 244, unlocking mutex
inc_count(): thread 3, count = 244, unlocking mutex
inc_count(): thread 3, count = 245, unlocking mutex
inc_count(): thread 2, count = 245, unlocking mutex
inc_count(): thread 3, count = 246, unlocking mutex
inc_count(): thread 2, count = 247, unlocking mutex
inc_count(): thread 3, count = 248, unlocking mutex
inc_count(): thread 2, count = 249, unlocking mutex
inc_count(): thread 3, count = 250, unlocking mutex
inc_count(): thread 2, count = 251, unlocking mutex
inc_count(): thread 3, count = 252, unlocking mutex
inc_count(): thread 2, count = 253, unlocking mutex
inc_count(): thread 3, count = 254, unlocking mutex
inc_count(): thread 2, count = 255, unlocking mutex
inc_count(): thread 2, count = 256, unlocking mutex
inc_count(): thread 3, count = 256, unlocking mutex
inc_count(): thread 2, count = 257, unlocking mutex
inc_count(): thread 3, count = 258, unlocking mutex
inc_count(): thread 2, count = 259, unlocking mutex
inc_count(): thread 3, count = 260, unlocking mutex
inc_count(): thread 2, count = 261, unlocking mutex
inc_count(): thread 3, count = 261, unlocking mutex
inc_count(): thread 3, count = 262, unlocking mutex
inc_count(): thread 2, count = 262, unlocking mutex
main: finish, final count = 262
```

</details>

With synchronization, `p1` runs first but then hits cond signal and gives mutex permission to count threshold.
`p2` runs with permission from cond signal, thus increasing `count` by `TCOUNT` or until `count == 20`.
After reaching `count == 20`, cond signal is released so that `p1` can continue running, where `count += 80` then `count == 100`.
`p1` releases mutex, letting `p2` and `p3` run, where `p2` runs the remaining (TCOUNT - (COUNT_LIMIT - 10)) iterations and `p3` runs all TCOUNT iterations.

Without synchronization, `p1`, `p2`, `p3` all try to write to `count` simultaneously, leading to inconsistent results in each execution.
In the case two `inc_count` read and return `count` at the same time, `count` is increased by 1 unit where it should be increased by 2, hence the difference in final count.

## Problem 3

For some reason `clock()` is not behaving properly. Regardless, using mutex on a global scope yields longer runtime as more mutex switch are needed, hence more instructions and more cycles for overhead.
