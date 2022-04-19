## Столяров, стр. 144 pdf
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    def __repr__(self) -> str:
        return str(self.data)

def int_array_to_list(l)
    ## return pointer to the first element of the linked list ##
    if (len(l) == 0):
        return None
    last = Node(l[-1])
    last.next = int_array_to_list(l[:-1]) 
    return last

def sum_el_ll(first):
    if (first == None):
        return 0
    return first.data + sum_el_ll(first.next)


l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
first = int_array_to_list(l)
print(sum_el_ll(first))
