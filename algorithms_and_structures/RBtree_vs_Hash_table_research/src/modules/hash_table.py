import prettytable as pt

DELETED = -2
EMPTY = -1

class Hash_table:
    def __init__(self, size):
        self.size = size
        self.list = [EMPTY for _ in range(size)]
        self.count = 0

    def printTable(self):
        res = pt.PrettyTable()
        res.field_names = ['key', 'value']
        for k, v in enumerate(self.list):
            res.add_row([k,v])
        print(res)

    def __hash_1(self, key) -> int:
        return key % self.size

    def __hash_2(self, key) -> int:
        return self.__getPrime() - (key % self.__getPrime())

    def add(self, key):
        if self.count == self.size:
            raise Exception("Table is full")
        elif self.list[self.__hash_1(key)] == EMPTY or self.list[self.__hash_1(key)] == DELETED:
            self.list[self.__hash_1(key)] = key
            self.count += 1
        else:
            i = 1
            probe = self.__hash_1(key)
            offset = self.__hash_2(key)
            index = (probe + offset) % self.size
            while self.list[index] != EMPTY and self.list[index] != DELETED:
                i+=1
                if i > self.size:
                    print("No space")
                    return
                index = (probe + i*offset) % self.size
            self.list[index] = key
            return

    def search(self, key):
        if self.count == 0: return
        probe = self.__hash_1(key)

        if self.list[probe] == key: return probe
        else:
            i = 1
            offset = self.__hash_2(key)
            index = (probe + offset) % self.size
            while self.list[index] != key:
                i+=1
                if i > self.size:
                    return
                index = (probe + i*offset) % self.size
            return index

    def delete_elem(self, key):
        if self.search(key) is None:
            return

        probe = self.__hash_1(key)
        offset = self.__hash_2(key)

        while self.list[probe] != EMPTY:
            if self.list[probe] == key:
                self.list[probe] = DELETED
                self.count-=1
                return
            else:
                probe = (probe + offset) % self.size

    def __getPrime(self) -> int:
        maximum = self.size
        while True:
            if self.__isPrime(maximum):
                return maximum
            maximum-=1

    def __isPrime(self, value) -> bool:
        for i in [2] + list(range(3, int(value**0.5)+1, 2)):
            if not value % i:
                return False
        return True

def main():
    table_size = 30
    table = Hash_table(table_size)
    for i in range(25):
        table.add(i)
    elem = table.search(23)
    table.delete_elem(0)
    table.printTable()
    print(elem)


if __name__ == '__main__':
    main()