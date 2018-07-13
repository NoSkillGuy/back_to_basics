class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		print('A node got initialized')

class LinkedList:
	def __init__(self):
		self.head = None
		print('A LL got initialized')

	def traverse_and_print(self):
		print('traverse and print got called')
		tmp = self.head 
		while(tmp):
			print(tmp.data)
			tmp = tmp.next
			print(tmp)

if __name__ == '__main__':
	llist = LinkedList()
	llist.head = Node(1)
	second = Node(2)
	print(second.data)
	third = Node(3)
	print(third.data)
	
	llist.next = second
	print(llist.next.data)
	second.next = third
	llist.traverse_and_print()
