def merge_sort(liste):
    if len(liste) <= 1:
        return liste
        
    left = []
    right = []
    for elem in range(len(liste)):
        if elem % 2:
            left.append(liste[elem])
        else:
            right.append(liste[elem])
    #return(left,right)
    left = merge_sort(left)
    right = merge_sort(right)
    
    return merge(left,right)
    
def merge(left,right):
    comb = []
    while left and right:
        if left[0] < right[0]:
            comb.append(left.pop(0))
        else:
            comb.append(right.pop(0))
            
    while left:
        comb.append(left.pop(0))
        
    while right:
        comb.append(right.pop(0))
        
    return comb
    
if __name__ == "__main__":
    print(merge_sort([23,15, 3, 94, 6, 88, 69, 2, 49, 1, 32]))



