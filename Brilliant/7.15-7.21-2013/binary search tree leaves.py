class Node:
	def __init__(self, val):
		self.left_child = None
		self.right_child = None
		self.data = val

def binary_insert(tree, val):
	# insert val at root if tree is empty
	if tree is None:
		tree = Node(val)
	else:
		# if val is less than current node, 
		# insert val into left subtree
		if (tree.data > val):
			tree.left_child = binary_insert(tree.left_child, val)
		# else, insert val into right subtree
		else:
			tree.right_child = binary_insert(tree.right_child, val)
	return tree

def leafSum(tree):
	if tree is None:
		return 0
	elif tree.left_child is None and tree.right_child is None:
		return tree.data
	else:
		return leafSum(tree.left_child) + leafSum(tree.right_child)


vals = [4, 2, 1, 5, 6, 3, 7, 9, 8, 12, 10, 11, 13, 15, 14]
tree = None

for x in vals:
	tree = binary_insert(tree, x)

print leafSum(tree)
