import pytest
from main import *

def test_screaming():
    alph = len(set('аааааа'))
    coefs = [alph ** i for i in range(len('aaa'))]
    res = substringRK('aaaaaa', 'aaa', coefs)
    assert res == [0, 1, 2, 3]

def test_common():
    alph = len(set('аbacaba'))
    coefs = [alph ** i for i in range(len('aba'))]
    res = substringRK('abacaba', 'aba', coefs)
    assert res == [0, 4]

def test_empty():
    alph = len(set('аbacaba'))
    coefs = [alph ** i for i in range(len('aaa'))]
    res = substringRK('abacaba', 'aaa', coefs)
    assert res == []

def test_equal():
    alph = len(set('аbacaba'))
    coefs = [alph ** i for i in range(len('аbacaba'))]
    res = substringRK('аbacaba', 'аbacaba', coefs)
    assert res == [0]