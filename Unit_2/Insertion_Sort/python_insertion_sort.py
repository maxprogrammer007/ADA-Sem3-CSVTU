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
