#Uses python3
import sys
import math
import queue

def distance(x1, y1, x2, y2):
    return ((x1-x2)**2+(y1-y2)**2)**0.5

class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
        self.regions = n
    
    def find(self, i):
        while i != self.parent[i]:
            i = self.parent[i]
        return i
    
    def union(self, i, j):
        i_id = self.find(i)
        j_id = self.find(j)
        if i_id == j_id:
            return
        self.regions -= 1
        if self.rank[i_id] > self.rank[j_id]:
            self.parent[j_id] = i_id
        else:
            self.parent[i_id] = j_id
            if self.rank[i_id] == self.rank[j_id]:
                self.rank[j_id] += 1

def clustering(x, y, k):
    n = len(x)
    D = DisjointSet(n)
    Q = queue.PriorityQueue()
    for i in range(n):
        for j in range(i+1, n):
            Q.put((distance(x[i], y[i], x[j], y[j]), (i, j)))
    while not Q.empty():
        dist, (u, v) = Q.get()
        if D.find(u) != D.find(v):
            if D.regions == k:
                return dist
            D.union(u, v)

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    data = data[1:]
    x = data[0:2 * n:2]
    y = data[1:2 * n:2]
    data = data[2 * n:]
    k = data[0]
    print("{0:.9f}".format(clustering(x, y, k)))
