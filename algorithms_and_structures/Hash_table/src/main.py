def hashing(str, k):
    res = 0
    for i in range(len(str)):
        res+=ord(str[i])*k[len(str) - i - 1]
    return res % 1000000007

def substringRK(text, pattern, coefs):
    p = 1000000007
    res = []
    pat_len = len(pattern)
    substr = text[:pat_len]

    patt_hash = hashing(pattern, coefs)
    substr_hash = hashing(substr, coefs)

    for i in range(pat_len, len(text)+1):
        if patt_hash == substr_hash:
            res.append(i - pat_len)
        if i < len(text):
            substr += text[i]
            substr_hash = ((substr_hash - ord(substr[i - pat_len])*coefs[pat_len-1])*coefs[1] + ord(text[i])) % p
    return res

def main():
    pattern = input()
    str = input()
    m = len(set(str))
    coefs = [m**i for i in range(len(pattern))]
    res = substringRK(str, pattern, coefs)
    print(*res)

if __name__ == '__main__':
    main()