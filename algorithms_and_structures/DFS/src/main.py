from modules.tree import *


if __name__ == "__main__":
    n = int(input())
    data = list(map(int, input().split()))
    print(height(data, n))