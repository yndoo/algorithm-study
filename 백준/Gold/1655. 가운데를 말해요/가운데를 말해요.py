import sys
import heapq
inputt = sys.stdin.readline
N = int(inputt())
small = []
large = []

for i in range(N):
    ni = int(inputt())
    if len(small)==len(large):
        heapq.heappush(small,(-ni,ni))
    else:
        heapq.heappush(large,ni)

    if large and small[0][1] > large[0]:
        tmp_s = heapq.heappop(small)[1]
        tmp_l = heapq.heappop(large)
        heapq.heappush(small,(-tmp_l,tmp_l))
        heapq.heappush(large,tmp_s)
    print(small[0][1])


