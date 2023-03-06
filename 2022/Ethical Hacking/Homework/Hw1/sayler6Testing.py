import hashlib
#Jack Blackburn Q9 HW1 csci 4413
#node class and insert function backbones sourced from:
#https://aaronjwood.com/articles/binary-search-trees/
#I changed the the class a little to include a second node value 
#as well as added an if statement in the insert function to search for matches

class Node:
    def __init__(self, hashvalue, number, left, right):
        self.hashvalue = hashvalue
        self.number = number
        self.left = left
        self.right = right


def insert(root, v, number):
    if root is None:
        root = Node(v, number, None, None)
    elif v == root.hashvalue:
        print("match found between %i and %i" % root.number, number)
        exit(0)
    elif v < root.hashvalue:
        root.left = insert(root.left, v, number)
    else:
        root.right = insert(root.right, v, number)
    return root


if __name__ == "__main__":
    
    root = None
    
    hash1 = hashlib.md5(str(0).encode()).hexdigest()
    hash1 = hash1[0:6] + hash1[26:32]
    
    root = insert(root, hash1, 0)

    for i in range(1, 10000000):
        
        hash2 = hashlib.md5(str(i).encode()).hexdigest()
        hash2 = hash2[0:6] + hash2[26:32]
        
        root = insert(root,hash2, i) 
        
        if i % 1000000 == 0:
            print("looped a million entries currently at %i iterations" % i)

