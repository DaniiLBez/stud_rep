import pytest
import rb_tree as rb
import hash_table as ht

def test_insert_rb():
    rb_tree = rb.RB_tree()
    rb_tree.insert(70)
    rb_tree.insert(60)
    rb_tree.insert(85)
    rb_tree.insert(80)
    rb_tree.insert(95)
    rb_tree.insert(65)
    assert rb_tree.search(70).color == rb.BLACK
    assert rb_tree.search(65).color == rb.RED

def test_delete_rb():
    rb_tree = rb.RB_tree()
    rb_tree.insert(70)
    rb_tree.insert(60)
    rb_tree.insert(85)
    rb_tree.insert(80)
    rb_tree.insert(95)
    rb_tree.insert(65)
    rb_tree.delete_elem(80)
    assert rb_tree.search(80) == None
    assert rb_tree.search(85).color == rb.BLACK

def test_search_rb():
    rb_tree = rb.RB_tree()
    rb_tree.insert(70)
    rb_tree.insert(60)
    rb_tree.insert(85)
    rb_tree.insert(80)
    rb_tree.insert(95)
    rb_tree.insert(65)
    assert rb_tree.search(80).parent == rb_tree.search(85)
    assert rb_tree.search(60).right == rb_tree.search(65)

def test_add_ht():
    hash_table = ht.Hash_table(30)
    for i in range(25):
        hash_table.add(i)
    assert hash_table.search(24) == 24

def test_delete_ht():
    hash_table = ht.Hash_table(30)
    for i in range(25):
        hash_table.add(i)
    hash_table.delete_elem(0)
    assert hash_table.list[0] == ht.DELETED

def test_search_ht():
    hash_table = ht.Hash_table(30)
    for i in range(25):
        hash_table.add(i)
    assert hash_table.search(0) == 0
    assert hash_table.search(1000) == None
