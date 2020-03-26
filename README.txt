waitalloc

Tiny utility to consume memory (and swap)

usage:
  waitalloc <bytes>


Simple command to find a good consume number

    awk '/MemFree|SwapFree/ {sum += $2*1024} END {print sum - 1024}' /proc/meminfo
