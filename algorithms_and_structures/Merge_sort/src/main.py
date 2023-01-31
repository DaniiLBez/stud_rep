from merge_sort import *

if __name__ == '__main__':
    count = int(input())
    matrix_array = []
    for i in range(count):
        n = int(input())
        matrix_array.append(Matrix([list(map(int, input().split())) for elem in range(n)]))
    print(*merge_sort(matrix_array))