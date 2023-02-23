from copy import deepcopy

class Square:

    def __init__(self, size, x, y, color=1):
        self.size = size
        self.x_coord = x
        self.y_coord = y
        self.color = color

    def __str__(self):
        return f"{self.x_coord}{self.y_coord}{self.size}"


class Desk:

    def __init__(self, n):
        self.side_len = n
        self.map = [[0]*n for _ in range(n)]
        self.list_of_squares = []
        self.count_squares = 0

        if n % 2 != 0 and n % 3 != 0:
            self.set_default()

    def set_default(self):
        buff = add_square(self, Square(0, 0, n // 2 + 1, 1))
        buff = add_square(buff, Square(0, n // 2 + 1, n // 2, 2))
        buff = add_square(buff, Square(n // 2 + 1, 0, n // 2, 3))
        self = deepcopy(buff)


    def __str__(self):
        res = ''
        for elem in self.map:
            res += (''.join(map(str, elem)) + '\n')
        return res

    def __deepcopy__(self, memo):
        cls = self.__class__
        result = cls.__new__(cls)
        memo[id(self)] = result
        for k, v in self.__dict__.items():
            setattr(result, k, deepcopy(v))
        return result


def add_square(map, square):
    desk = deepcopy(map)
    desk.list_of_squares.append(square)
    for i in range(square.size):
        for j in range(square.size):
            desk.map[square.y_coord+i][square.x_coord+j] = square.color
    desk.count_squares+=1
    return desk


def is_answer(desk) -> bool:
    for elem in desk.map:
        if 0 in elem:
            return False
    return True


def can_add(desk, x, y, square) -> bool:
    if y+square.size > desk.side_len or x + square.size > desk.side_len:
        return False
    for i in range(square.size):
        for j in range(square.size):
            if desk.map[y+i][x+j] != 0:
                return False
    return True


def empty_cell(map) -> list:
    for i in range(len(map.map)):
        for j in range(len(map.map[i])):
            if map.map[j][i] == 0:
                return [i, j]
    return [-1, -1]


def backtracking(desk, sizes):

    queue = [desk]

    while not is_answer(queue[0]):
        s = queue.pop(0)
        x, y = empty_cell(s)[0], empty_cell(s)[1]
        for elem in sizes:
            if can_add(s, x, y, Square(elem, x, y, s.count_squares+1)):
                cur_desk = add_square(s, Square(elem, x, y, s.count_squares+1))
                queue.append(cur_desk)

    return queue[0]



n = int(input())
desk = Desk(n)

sizes = [i for i in range(n-1, 0, -1)]
answer = backtracking(desk, sizes)
print(answer.count_squares)
for elem in answer.list_of_squares:
    print(elem)

print(answer)