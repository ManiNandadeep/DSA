from collections import defaultdict

class Graph :
    def __init__(self,vertices) :
        self.V = vertices
        self.graph = []

    def addedge(self,u,v,w) :
        self.graph.append([u,v,w])

    def find(self,parent,i) :
        if parent[i] == i :
            return i 
        return self.find(parent,parent[i])

    def union(self,parent,rank,x,y) :
        xroot = self.find(parent,x)
        yroot = self.find(parent,y)

        if rank[xroot] < rank[yroot] :
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot] :
            parent[yroot] = xroot
        else :
            parent[yroot] = xroot
            rank[xroot] += 1

    def kruskal(self) :
        result = []
        i = 0 
        e = 0 
        self.graph = sorted(self.graph,key=lambda  item: item[2])
        parent = []
        rank = []

        for node in range(self.V) :
            parent.append(node)
            rank.append(0)

        while e < self.V - 1 :
            u,v,w = self.graph[i]
            i += 1
            x = self.find(parent,u)
            y = self.find(parent,v)

            if x != y :
                e += 1
                result.append([u,v,w])
                self.union(parent,rank,x,y)

        print ("Following are the edges in the constructed MST")
        for u,v,weight  in result:  
            print ("{} -- {} == {}".format(u,v,weight))


if __name__ == "__main__":
    g = Graph(4)
    g.addedge(0, 1, 10) 
    g.addedge(0, 2, 6) 
    g.addedge(0, 3, 5) 
    g.addedge(1, 3, 15) 
    g.addedge(2, 3, 4) 
    g.kruskal()
