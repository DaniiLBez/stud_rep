from modules.tree import *
import pytest

def test_empty_tree():
    len = 0
    data = []
    assert height(data, len) == 0

def test_list_tree():
    len = 5
    data = [-1, 0, 1, 2, 3]
    assert height(data, len) == 5

def test_common_tree():
    len = 5
    data = [4, -1, 4, 1, 1]
    assert height(data, len) == 3

def test_error_negative_len():
    len = -1
    data = [0, 1, 2, 3]
    with pytest.raises(ValueError):
        height(data, len)

def test_error_incorrect_data():
    len = 5
    data = [-1, 0, 1, 2, 5]
    with pytest.raises(ValueError):
        height(data, len)

def test_error_no_root():
    len = 3
    data = [0, 1, 2]
    with pytest.raises(ValueError):
        height(data, len)
