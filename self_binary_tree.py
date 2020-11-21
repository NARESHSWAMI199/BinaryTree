# created a node
class newNode():
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None


def inorder(temp): 
    if not temp:
        return
    inorder(temp.left)
    print(temp.data ,end= ' ')
    inorder(temp.right)
 

def insert(temp,data):
    if not temp:
        root = newNode(data)
        print("working")
        return

    q = []
    q.append(temp)

    while len(q):
        temp = q[0]
        q.pop(0)

        if not temp.left:
            temp.left = newNode(data)
            break
        else:
            q.append(temp.left)

        if not temp.right:
            temp.right = newNode(data)
        else:
            q.append(temp.right)


# left
root = newNode(15)
root.left = newNode(21)
root.left.left = newNode(6)
# right
root.right= newNode(7)
root.right.right = newNode(10)
root.right.left = newNode(12)



# print("the inorder before inserting : " , end= ' ')
# inorder(root)

data =11

insert(root,data)

print()
print("the inorder after inserting : " , end= ' ')
inorder(root)

