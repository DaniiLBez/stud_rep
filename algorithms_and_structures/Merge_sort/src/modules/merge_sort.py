import itertools as it

class Matrix:
    _data_ = []
    _id_ = it.count()

    def __init__(self, data):
        self._data_ = data
        self._id_ = next(Matrix._id_)

    def get_dSum(self):
        res = 0
        for i in range(len(self._data_)):
            res+=self._data_[i][i]
        return res

    def getID(self):
        return self._id_

    def __str__(self):
        return f'{self.getID()}'

    def __lt__(self, other):
        return self.get_dSum() < other.get_dSum()


def merge_sort(x):

    if len(x) < 2: return x

    result,mid = [],int(len(x)/2)

    y = merge_sort(x[:mid])
    z = merge_sort(x[mid:])

    while (len(y) > 0) and (len(z) > 0):
            if y[0] > z[0]: result.append(z.pop(0))
            else: result.append(y.pop(0))

    result.extend(y+z)
    print(*result)
    return result
