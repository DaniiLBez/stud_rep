def check_tree(tree, n):
    if n < 0:
        raise ValueError('invalid value for length of the tree')
    for elem in tree:
        if elem >= n:
            raise ValueError('invalid value for child')
    if -1 not in tree:
        raise ValueError('there is no root!')


def height(tree, n):
    if n == 0:
        return 0

    check_tree(tree, n)

    list_of_lens = {}
    for i, root in enumerate(tree):
        cur_len = 1
        cur_elem = root
        while cur_elem != -1:
            if cur_elem in list_of_lens:
                cur_len+=list_of_lens[cur_elem]
                break
            else:
                cur_elem = tree[cur_elem]
                cur_len+=1
        list_of_lens[i] = cur_len
    return max(list_of_lens.values())
