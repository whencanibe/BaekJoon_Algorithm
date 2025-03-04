def solve():
    import sys
    input = sys.stdin.readline

    words = input().strip()

    leng = len(words)
    result = leng

    i = 0
    while i < leng:
        if i + 2 < leng and words[i:i+3] == "dz=":
            result -= 2
            i += 3
            continue
        if i + 1 < leng:
            if words[i:i+2] == "c=" or words[i:i+2] == "c-" or words[i:i+2] == "d-" or words[i:i+2] == "lj" or words[i:i+2] == "nj" or words[i:i+2] == "s=" or words[i:i+2] == "z=":
                result -= 1
        i += 1

    print(result)

if __name__ == "__main__":
    solve()