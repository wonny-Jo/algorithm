import sys
sys.setrecursionlimit(10**6)
from functools import cmp_to_key

class Node:
    def __init__(self, x,y,pos):
        self.x=x
        self.y=y
        self.pos=pos
        self.left = None
        self.right = None

def compare(a,b):
    if a.y!=b.y:
        return -1 if a.y>b.y else 1
    if a.x!=b.x:
        return -1 if a.x<b.x else 1
    return -1

def add(preNode, nextNode):
    if preNode.x>nextNode.x:
        if preNode.left==None:
            preNode.left=nextNode
        else:
            add(preNode.left,nextNode)
    else:
        if preNode.right==None:
            preNode.right=nextNode
        else:
            add(preNode.right,nextNode)

pre=[]
post=[]

def preorder(node):
    if node==None:
        return
    pre.append(node.pos)
    preorder(node.left)
    preorder(node.right)
    
def postorder(node):
    if node==None:
        return
    postorder(node.left)
    postorder(node.right)
    post.append(node.pos)

def solution(nodeinfo):
    v=[[] for _ in range(len(nodeinfo))]
    for i in range(len(nodeinfo)):
        v[i]=Node(nodeinfo[i][0],nodeinfo[i][1],i+1)
    v.sort(key=cmp_to_key(compare))

    for i in range(len(v)-1):
        add(v[0],v[i+1])

    preorder(v[0])
    postorder(v[0])

    answer = []
    answer.append(pre)
    answer.append(post)
    return answer

print(solution([[5,3],[11,5],[13,3],[3,5],[6,1],
                [1,3],[8,6],[7,2],[2,2]]))