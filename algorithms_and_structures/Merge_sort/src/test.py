from main import *
import pytest

def test_one_matrix():
    res = merge_sort([Matrix([1])])
    res = ' '.join(str(elem) for elem in res)
    assert res == '0'

def test_empty_matrix():
    res = merge_sort([Matrix([])])
    res = ' '.join(str(elem) for elem in res)
    assert res == '1'

def test_normal():
    a = Matrix([[1,1,1],[1,1,1],[1,1,1]])
    b = Matrix([[0, 1, 1], [1, 0, 1], [1, 1, 0]])
    c = Matrix([[2, 1, 1], [1, 2, 1], [1, 1, 2]])
    res = merge_sort([a,b,c])
    res = ' '.join(str(elem) for elem in res)
    assert res == '3 2 4'