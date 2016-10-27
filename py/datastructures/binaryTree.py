# Press COMMAND + ENTER to run a single line in the console

class BinaryTree():
    def __init__(self, root=None):
        self.root = root
        self.left = None
        self.right = None
    
    def insert(self, data):
        
        if self.root is None:
            self.root = data
        
        elif data <= self.root:
            
            # check if empty
            if self.left is None:
                self.left = data
            
            # if not empty
            else:
                temp = self.left
                
                # check whether leaf or subtree
                # if subtree, recursively 
                # traverse subtree
                if not isinstance(temp, int):
                    self.left.insert(data)
                    
                # else append a new subtree with current
                # leaf being the new root/parent node 
                else:
                    self.left = BinaryTree(temp)
                    self.left.insert(data)
        else:
            # check if empty
            if self.right is None:
                self.right = data
            
            # if not empty
            else:
                temp = self.right
                
                # check whether leaf or subtree
                # if subtree, recursively 
                # traverse subtree
                if not isinstance(temp, int):
                    self.left.insert(data)
                    
                # else append a new subtree with current
                # leaf being the new root/parent node 
                else:
                    self.right = BinaryTree(temp)
                    self.right.insert(data)
                
    def getLeftChild(self):
        if self.left:
            return self.left
    def getRightChild(self):
        if self.right:
            return self.right
    def setNodeValue(self,data):
        self.root = data
    def getNodeValue(self):
        return self.root
        
    
def printTree(tree):
    # check whether tree contains root node
    print('Traversing Tree...')
    if isinstance(tree, int):
        print("Leaf: ", tree)
    
    else:
        root = tree.getNodeValue()
        if root:
            print("Root found: ", root)
        # check whether there is left child
            left = tree.getLeftChild()
            right = tree.getRightChild()
            if not left and not right:
                print("No children")
            elif left and right:
                print("2 Children")
                printTree(left)
                printTree(right)
            elif left:
                print("Only left child.")
                # repeat recursively
                printTree(left)
                
            # else check whether there is right child
            elif right:
                print("Only right child.")
                # repeat recursively
                printTree(right)
        else:
            print("Empty Tree.")
            
    print("Done traversing")

x = BinaryTree()
printTree(x)
x.insert(35)
x.insert(40)
x.insert(32)
x.insert(45)
x.insert(2)
x.insert(1)
x.insert(18)
x.insert(39)
