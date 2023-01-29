import  rb_tree as rb
import hash_table as ht
import time


def main():

    rb_tree = rb.RB_tree()
    hash_table = ht.Hash_table(3000)

    for elem in range(1750):
        rb_tree.insert(elem)
        hash_table.add(elem)

    start_time = time.perf_counter()
    rb_tree.insert(10000)
    time_t = (time.perf_counter() - start_time)
    print(time_t)

    start_time = time.perf_counter()
    hash_table.add(10000)
    time_t = (time.perf_counter() - start_time)
    print(time_t)

    start_time = time.perf_counter()
    rb_tree.search(10000)
    time_t = (time.perf_counter() - start_time)
    print(time_t)

    start_time = time.perf_counter()
    hash_table.search(10000)
    time_t = (time.perf_counter() - start_time)
    print(time_t)

    start_time = time.perf_counter()
    rb_tree.delete_elem(10000)
    time_t = (time.perf_counter() - start_time)
    print(time_t)

    start_time = time.perf_counter()
    hash_table.delete_elem(10000)
    time_t = (time.perf_counter() - start_time)
    print(time_t)

if __name__ == '__main__':
    main()