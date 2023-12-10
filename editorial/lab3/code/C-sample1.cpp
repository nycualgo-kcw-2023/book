A(a, k) // a is set of node()
	S := a
	cost := 0
	while |S| ≠ 1 :
			Z := new node()
			Z.childs := ∅ // set of node()
			Z.val := 0
			while |Z.childs| < 2 or |S| % (k - 1) != 0 : // at least 2 in one battle
					minNode := node with smallest val in S
					Z.childs = Z.childs ∪ minNode
					Z.val += minNode.val
					S := S - minNode
			cost += Z.val
			S := S ∪ Z
	root := the remained node in S
	return root, cost