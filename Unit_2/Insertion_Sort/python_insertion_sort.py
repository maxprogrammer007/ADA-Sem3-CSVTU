def insertionSort(lst):
    for i in range(1, len(lst)):
        key = lst[i]
        j = i - 1
        while j >= 0 and key < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = key
    return lst

if __name__ == '__main__':
    lst = [64, 88, 51, 65, 90, 75, 34, 79, 46, 36]
    print(insertionSort(lst))

# 'if __name__ == "__main__":' ka use isliye karte hain taaki yeh code sirf tabhi chale jab script directly run ki jaye.
# Agar hum is script ko kisi dusre Python file mein import karte hain, toh yeh code automatically execute nahi hoga.
# Yeh practice useful hai jab hum code ko reuse karna chahte hain, bina kisi unwanted execution ke.
# Isse script ko modular aur maintainable banaya ja sakta hai, jahan testing ya specific code sirf direct execution pe hi chalega.
