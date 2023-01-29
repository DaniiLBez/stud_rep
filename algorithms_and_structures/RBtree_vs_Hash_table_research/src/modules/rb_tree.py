import sys

BLACK = 'black'
RED = 'red'

class Node:
    def __init__(self, key, color, parent = None):
        self.key = key
        self.left = None
        self.right = None
        self.color = color
        self.parent = parent

    def __str__(self):
        left = self.left.key if self.left else None
        right = self.right.key if self.right else None
        parent = self.parent.key if self.parent else None
        return 'key: {}, left: {}, right: {}, color: {}, parent: {}'.format(self.key, left, right, self.color, parent)

class RB_tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if not self.root:
            self.root = Node(key, BLACK)
        else:
            current = self.root
            while current:
                if key < current.key:
                    if not current.left:
                        new_node = Node(key, RED, parent=current)
                        current.left = new_node
                        break
                    current = current.left
                else:
                    if not current.right:
                        new_node = Node(key, RED, parent=current)
                        current.right = new_node
                        break
                    current = current.right
            self.fix_insert(new_node)

    def fix_insert(self, node):
        while node.parent and node.parent.color == RED:
            grandparent = node.parent.parent

            if grandparent is None:
                return

            if node.parent == grandparent.left:
                uncle = grandparent.right

                if not uncle or uncle.color == BLACK:  # дядя отсутствует или черный
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    self.right_rotate(grandparent)
                    node.parent.color = BLACK
                    grandparent.color = RED

                else:  # дядя красный
                    uncle.color = BLACK
                    node.parent.color = BLACK
                    grandparent.color = RED
                    node = grandparent
            else:  # если родитель нового узла правый сын
                uncle = grandparent.left

                if not uncle or uncle.color == BLACK:  # дядя отсутствует или черный
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    self.left_rotate(grandparent)
                    node.parent.color = BLACK
                    grandparent.color = RED

                else:  # дядя красный
                    uncle.color = BLACK
                    node.parent.color = BLACK
                    grandparent.color = RED
                    node = grandparent
        if self.root.color == RED:
            self.root.color = BLACK

    def search(self, key) -> Node:
        root = self.root
        while root and root.key != key:
            if key > root.key:
                root = root.right
            else:
                root = root.left
        return root

    def delete_elem(self, key):
        node = self.search(key)

        if not node:
            return

        y = node
        y_original_color = y.color
        if not node.left:
            x = node.right
            self.transplant(node, node.right)
        elif not node.right:
            x = node.left
            self.transplant(node, node.left)
        else:
            y = self.minimum(node.right)
            y_original_color = y.color
            x = y.right
            if y.parent == node:
                x.parent = y
            else:
                self.transplant(y, y.right)
                y.right = node.right
                y.right.parent = y

            self.transplant(node, y)
            y.left = node.left
            y.left.parent = y
            y.color = node.color
        if y_original_color == 0:
            self.fix_delete(x)

    def fix_delete(self, x):
        while x != self.root and x.color == BLACK:
            if x == x.parent.left:
                s = x.parent.right
                if s.color == RED:
                    s.color = BLACK
                    x.parent.color = RED
                    self.left_rotate(x.parent)
                    s = x.parent.right

                if s.left.color == BLACK and s.right.color == BLACK:
                    s.color = RED
                    x = x.parent
                else:
                    if s.right.color == BLACK:
                        s.left.color = BLACK
                        s.color = RED
                        self.right_rotate(s)
                        s = x.parent.right

                    s.color = x.parent.color
                    x.parent.color = BLACK
                    s.right.color = BLACK
                    self.left_rotate(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.color == RED:
                    s.color = BLACK
                    x.parent.color = RED
                    self.right_rotate(x.parent)
                    s = x.parent.left

                if s.right.color == BLACK and s.right.color == BLACK:
                    s.color = RED
                    x = x.parent
                else:
                    if s.left.color == BLACK:
                        s.right.color = BLACK
                        s.color = RED
                        self.left_rotate(s)
                        s = x.parent.left

                    s.color = x.parent.color
                    x.parent.color = BLACK
                    s.left.color = BLACK
                    self.right_rotate(x.parent)
                    x = self.root
        x.color = BLACK

        # if self.root.parent:
        #     self.root.parent = None

    def left_rotate(self, node): # node - отец нового элемента
        new_node = node.right
        parent = node.parent

        node.right = new_node.left # Lb
        if node.right:
            node.right.parent = node

        new_node.left = node
        node.parent = new_node

        if not parent:
            self.root = new_node

        else:
            if parent.left == node:
                parent.left = new_node
            else:
                parent.right = new_node


    def right_rotate(self, node):
        new_node = node.left
        parent = node.parent

        node.left = new_node.right
        if node.left:
            node.left.parent = node

        new_node.right = node
        node.parent = new_node

        if not parent:
            self.root = new_node

        else:
            if parent.left == node:
                parent.left = new_node
            else:
                parent.right = new_node

    def transplant(self, node, new_node):
        if node.parent == None:
            self.root = new_node
        elif node == node.parent.left:
            node.parent.left = new_node
        else:
            node.parent.right = new_node
            if not new_node:
                node.parent = None
            else:
                new_node.parent = node.parent

    def minimum(self, node) -> Node:
        while node.left:
            node = node.left
        return node

    def maximum(self, node) -> Node:
        while node.right:
            node = node.right
        return node

    def print_tree(self):
        self.__print_helper(self.root, "", True)

    def __print_helper(self, node, indent, last):
        if node != None:
            sys.stdout.write(indent)
            if last:
                sys.stdout.write("R----")
                indent += "     "
            else:
                sys.stdout.write("L----")
                indent += "|    "

            s_color = "RED" if node.color == RED else "BLACK"
            print(str(node.key) + "(" + s_color + ")")
            self.__print_helper(node.left, indent, False)
            self.__print_helper(node.right, indent, True)

def main():
    rb = RB_tree()

    rb.insert(70)
    rb.insert(60)
    rb.insert(85)
    rb.insert(80)
    rb.insert(95)
    rb.insert(65)

    rb.print_tree()
    print()
    rb.delete_elem(80)
    rb.print_tree()

    rb.print_tree()
if __name__ == '__main__':
    main()